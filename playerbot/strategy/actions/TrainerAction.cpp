#include "botpch.h"
#include "../../playerbot.h"
#include "TrainerAction.h"
#include "../../ServerFacade.h"

using namespace ai;

void TrainerAction::Learn(uint32 cost, TrainerSpell const* tSpell, ostringstream& msg)
{
    if (sPlayerbotAIConfig.autoTrainSpells != "free")
    {
        if (bot->GetMoney() < cost)
        {
            msg << " - too expensive";
            return;
        }

        bot->ModifyMoney(-int32(cost));
    }

    SpellEntry const* proto = sServerFacade.LookupSpellInfo(tSpell->spell);
    if (!proto)
        return;

#ifdef CMANGOS
    if (tSpell->learnedSpell)
        bot->learnSpell(tSpell->learnedSpell, false);
    else
        ai->CastSpell(tSpell->spell, bot);
#endif

#ifdef MANGOS
    bool learned = false;
    for (int j = 0; j < 3; ++j)
    {
        if (proto->Effect[j] == SPELL_EFFECT_LEARN_SPELL)
        {
            uint32 learnedSpell = proto->EffectTriggerSpell[j];
            bot->learnSpell(learnedSpell, false);
            learned = true;
        }
    }
    if (!learned) bot->learnSpell(tSpell->spell, false);
#endif

    msg << " - learned";
}

void TrainerAction::Iterate(Creature* creature, TrainerSpellAction action, SpellIds& spells)
{
    TellHeader(creature);

    TrainerSpellData const* cSpells = creature->GetTrainerSpells();
    TrainerSpellData const* tSpells = creature->GetTrainerTemplateSpells();
    float fDiscountMod =  bot->GetReputationPriceDiscount(creature);
    uint32 totalCost = 0;

    TrainerSpellData const* trainer_spells = cSpells;
    if (!trainer_spells)
        trainer_spells = tSpells;

    for (TrainerSpellMap::const_iterator itr =  trainer_spells->spellList.begin(); itr !=  trainer_spells->spellList.end(); ++itr)
    {
        TrainerSpell const* tSpell = &itr->second;

        if (!tSpell)
            continue;

        uint32 reqLevel = 0;

        reqLevel = tSpell->isProvidedReqLevel ? tSpell->reqLevel : std::max(reqLevel, tSpell->reqLevel);
        TrainerSpellState state = bot->GetTrainerSpellState(tSpell, reqLevel);
        if (state != TRAINER_SPELL_GREEN)
            continue;

        uint32 spellId = tSpell->spell;
        const SpellEntry *const pSpellInfo =  sServerFacade.LookupSpellInfo(spellId);
        if (!pSpellInfo)
            continue;

        if (!spells.empty() && spells.find(tSpell->spell) == spells.end())
            continue;

        uint32 cost = uint32(floor(tSpell->spellCost *  fDiscountMod));
        totalCost += cost;

        ostringstream out;
        out << chat->formatSpell(pSpellInfo) << chat->formatMoney(cost);

        if (action)
            (this->*action)(cost, tSpell, out);

        ai->TellMaster(out);
    }

    TellFooter(totalCost);
}

bool TrainerAction::Execute(Event event)
{
    string text = event.getParam();

    Player* master = GetMaster();

    Creature* creature = ai->GetCreature(bot->GetSelectionGuid());
    if (AI_VALUE(ObjectGuid, "rpg target") != bot->GetSelectionGuid())
        if (master)
            creature = ai->GetCreature(master->GetSelectionGuid());
        else
            return false;

#ifdef MANGOS
    if (!creature || !creature->IsTrainer())
#endif
#ifdef CMANGOS
    if (!creature || !creature->isTrainer())
#endif
        return false;

            
    if (!creature->IsTrainerOf(bot, false))
    {
        ai->TellError("This trainer cannot teach me");
        return false;
    }

    // check present spell in trainer spell list
    TrainerSpellData const* cSpells = creature->GetTrainerSpells();
    TrainerSpellData const* tSpells = creature->GetTrainerTemplateSpells();
    if (!cSpells && !tSpells)
    {
        ai->TellError("No spells can be learned from this trainer");
        return false;
    }

    uint32 spell = chat->parseSpell(text);
    SpellIds spells;
    if (spell)
        spells.insert(spell);

    if (text.find("learn") != string::npos || sRandomPlayerbotMgr.IsRandomBot(bot) || (sPlayerbotAIConfig.autoTrainSpells != "no" && (creature->GetCreatureInfo()->TrainerType != TRAINER_TYPE_TRADESKILLS || ai->isRealPlayer()))) //Todo rewrite to only exclude start primary profession skills and make config dependent.
        Iterate(creature, &TrainerAction::Learn, spells);
    else
        Iterate(creature, NULL, spells);

    return true;
}

void TrainerAction::TellHeader(Creature* creature)
{
    ostringstream out; out << "--- Can learn from " << creature->GetName() << " ---";
    ai->TellMaster(out);
}

void TrainerAction::TellFooter(uint32 totalCost)
{
    if (totalCost)
    {
        ostringstream out; out << "Total cost: " << chat->formatMoney(totalCost);
        ai->TellMaster(out);
    }
}
