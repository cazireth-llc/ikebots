#include "botpch.h"
#include "../../playerbot.h"
#include "PossibleRpgTargetsValue.h"

#include "../../ServerFacade.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "CellImpl.h"
#include "NearestUnitsValue.h"
#include "../../Travelmgr.h"

using namespace ai;
using namespace MaNGOS;

vector<uint32> PossibleRpgTargetsValue::allowedNpcFlags;

PossibleRpgTargetsValue::PossibleRpgTargetsValue(PlayerbotAI* ai, float range) :
        NearestUnitsValue(ai, "possible rpg targets", range, true)
{
    if (!allowedNpcFlags.size())
    {
        allowedNpcFlags.push_back(UNIT_NPC_FLAG_INNKEEPER);
        allowedNpcFlags.push_back(UNIT_NPC_FLAG_GOSSIP);
        allowedNpcFlags.push_back(UNIT_NPC_FLAG_QUESTGIVER);
        allowedNpcFlags.push_back(UNIT_NPC_FLAG_FLIGHTMASTER);
        allowedNpcFlags.push_back(UNIT_NPC_FLAG_BANKER);
#ifndef MANGOSBOT_ZERO
        allowedNpcFlags.push_back(UNIT_NPC_FLAG_GUILD_BANKER);
        allowedNpcFlags.push_back(UNIT_NPC_FLAG_TRAINER_CLASS);
        allowedNpcFlags.push_back(UNIT_NPC_FLAG_TRAINER_PROFESSION);
        allowedNpcFlags.push_back(UNIT_NPC_FLAG_VENDOR_AMMO);
        allowedNpcFlags.push_back(UNIT_NPC_FLAG_VENDOR_FOOD);
        allowedNpcFlags.push_back(UNIT_NPC_FLAG_VENDOR_POISON);
        allowedNpcFlags.push_back(UNIT_NPC_FLAG_VENDOR_REAGENT);
#endif
        allowedNpcFlags.push_back(UNIT_NPC_FLAG_AUCTIONEER);
        allowedNpcFlags.push_back(UNIT_NPC_FLAG_STABLEMASTER);
        allowedNpcFlags.push_back(UNIT_NPC_FLAG_PETITIONER);
        allowedNpcFlags.push_back(UNIT_NPC_FLAG_TABARDDESIGNER);

        allowedNpcFlags.push_back(UNIT_NPC_FLAG_TRAINER);
        allowedNpcFlags.push_back(UNIT_NPC_FLAG_VENDOR);
        allowedNpcFlags.push_back(UNIT_NPC_FLAG_REPAIR);
    }
}

void PossibleRpgTargetsValue::FindUnits(list<Unit*> &targets)
{
    AnyUnitInObjectRangeCheck u_check(bot, range);
    UnitListSearcher<AnyUnitInObjectRangeCheck> searcher(targets, u_check);
    Cell::VisitAllObjects(bot, searcher, range);
}

bool PossibleRpgTargetsValue::AcceptUnit(Unit* unit)
{
    if (sServerFacade.IsHostileTo(unit, bot) || dynamic_cast<Player*>(unit))
        return false;

    if (sServerFacade.GetDistance2d(bot, unit) <= sPlayerbotAIConfig.tooCloseDistance)
        return false;

	if (unit->HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPIRITHEALER))
		return false;

    for (vector<uint32>::iterator i = allowedNpcFlags.begin(); i != allowedNpcFlags.end(); ++i)
    {
		if (unit->HasFlag(UNIT_NPC_FLAGS, *i)) return true;
    }

    TravelTarget* travelTarget = context->GetValue<TravelTarget*>("travel target")->Get();

    if (travelTarget->getDestination() && travelTarget->getDestination()->getEntry() == unit->GetEntry())
        return true;

    if (urand(1, 100) < 25 && sServerFacade.IsFriendlyTo(unit, bot))
        return true;

    if (urand(1, 100) < 5)
        return true;

    return false;
}
