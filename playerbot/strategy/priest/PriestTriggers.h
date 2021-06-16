#pragma once

#include "../triggers/GenericTriggers.h"

namespace ai
{
    class PowerWordFortitudeOnPartyTrigger : public BuffOnPartyTrigger {
    public:
        PowerWordFortitudeOnPartyTrigger(PlayerbotAI* ai) : BuffOnPartyTrigger(ai, "power word: fortitude", 2) {}

        virtual bool IsActive() { return BuffOnPartyTrigger::IsActive() && !ai->HasAura("power word: fortitude", GetTarget()) && !ai->HasAura("prayer of fortitude", GetTarget()); }
    };

    class PowerWordFortitudeTrigger : public BuffTrigger {
    public:
        PowerWordFortitudeTrigger(PlayerbotAI* ai) : BuffTrigger(ai, "power word: fortitude", 2) {}

        virtual bool IsActive() { return BuffTrigger::IsActive() && !ai->HasAura("power word: fortitude", GetTarget()) && !ai->HasAura("prayer of fortitude", GetTarget()); }
    };

    class DivineSpiritOnPartyTrigger : public BuffOnPartyTrigger {
    public:
        DivineSpiritOnPartyTrigger(PlayerbotAI* ai) : BuffOnPartyTrigger(ai, "divine spirit", 2) {}

        virtual bool IsActive() { return BuffOnPartyTrigger::IsActive() && !ai->HasAura("divine spirit", GetTarget()) && !ai->HasAura("prayer of spirit", GetTarget()); }
    };

    class DivineSpiritTrigger : public BuffTrigger {
    public:
        DivineSpiritTrigger(PlayerbotAI* ai) : BuffTrigger(ai, "divine spirit", 2) {}

        virtual bool IsActive() { return BuffTrigger::IsActive() && !ai->HasAura("divine spirit", GetTarget()) && !ai->HasAura("prayer of spirit", GetTarget()); }
    };

    class PrayerOfFortitudeTrigger : public BuffOnPartyTrigger {
    public:
        PrayerOfFortitudeTrigger(PlayerbotAI* ai) : BuffOnPartyTrigger(ai, "prayer of fortitude", 2) {}

        virtual bool IsActive() { return BuffOnPartyTrigger::IsActive() &&
            !ai->HasAura("prayer of fortitude", GetTarget()) &&
#ifdef MANGOS
            (ai->GetBot()->IsInSameGroupWith((Player*)GetTarget()) || ai->GetBot()->IsInSameRaidWith((Player*)GetTarget())) &&
#endif
#ifdef CMANGOS
            (ai->GetBot()->IsInGroup((Player*)GetTarget(), true) || ai->GetBot()->IsInGroup((Player*)GetTarget())) &&
#endif
            ai->GetBuffedCount((Player*)GetTarget(), "prayer of fortitude") < 5 &&
            ai->GetBuffedCount((Player*)GetTarget(), "power word: fortitude") < 5
            ; }
    };

    class PrayerOfSpiritTrigger : public BuffOnPartyTrigger {
    public:
        PrayerOfSpiritTrigger(PlayerbotAI* ai) : BuffOnPartyTrigger(ai, "prayer of spirit", 2) {}

        virtual bool IsActive() { return BuffOnPartyTrigger::IsActive() &&
            !ai->HasAura("prayer of spirit", GetTarget()) &&
            //!ai->HasAura("divine spirit", GetTarget()) &&
#ifdef MANGOS
            (ai->GetBot()->IsInSameGroupWith((Player*)GetTarget()) || ai->GetBot()->IsInSameRaidWith((Player*)GetTarget())) &&
#endif
#ifdef CMANGOS
            (ai->GetBot()->IsInGroup((Player*)GetTarget(), true) || ai->GetBot()->IsInGroup((Player*)GetTarget())) &&
#endif
            //ai->GetManaPercent() > 50 &&
            ai->GetBuffedCount((Player*)GetTarget(), "prayer of spirit") < 5 &&
            ai->GetBuffedCount((Player*)GetTarget(), "divine spirit") < 5
            ; }
    };


    class InnerFireTrigger : public BuffTrigger
    {
    public:
        InnerFireTrigger(PlayerbotAI* ai) : BuffTrigger(ai, "inner fire", 2) {}
        virtual bool IsActive();
    };
    BUFF_TRIGGER(VampiricEmbraceTrigger, "vampiric embrace", "vampiric embrace")

    class PowerWordPainOnAttackerTrigger : public DebuffOnAttackerTrigger
    {
    public:
        PowerWordPainOnAttackerTrigger(PlayerbotAI* ai) : DebuffOnAttackerTrigger(ai, "shadow word: pain") {}
    };

    DEBUFF_TRIGGER(PowerWordPainTrigger, "shadow word: pain", "shadow word: pain")
    DEBUFF_TRIGGER(DevouringPlagueTrigger, "devouring plague", "devouring plague")
    DEBUFF_TRIGGER(VampiricTouchTrigger, "vampiric touch", "vampiric touch")

    class DispelMagicTrigger : public NeedCureTrigger
    {
    public:
        DispelMagicTrigger(PlayerbotAI* ai) : NeedCureTrigger(ai, "dispel magic", DISPEL_MAGIC) {}
    };

    class DispelMagicPartyMemberTrigger : public PartyMemberNeedCureTrigger
    {
    public:
        DispelMagicPartyMemberTrigger(PlayerbotAI* ai) : PartyMemberNeedCureTrigger(ai, "dispel magic", DISPEL_MAGIC) {}
    };

    class CureDiseaseTrigger : public NeedCureTrigger
    {
    public:
        CureDiseaseTrigger(PlayerbotAI* ai) : NeedCureTrigger(ai, "cure disease", DISPEL_DISEASE) {}
    };

    class PartyMemberCureDiseaseTrigger : public PartyMemberNeedCureTrigger
    {
    public:
        PartyMemberCureDiseaseTrigger(PlayerbotAI* ai) : PartyMemberNeedCureTrigger(ai, "cure disease", DISPEL_DISEASE) {}
    };

    class ShadowformTrigger : public BuffTrigger {
    public:
        ShadowformTrigger(PlayerbotAI* ai) : BuffTrigger(ai, "shadowform") {}
        virtual bool IsActive() { return !ai->HasAura("shadowform", bot); }
    };

    class PowerInfusionTrigger : public BuffTrigger
    {
    public:
        PowerInfusionTrigger(PlayerbotAI* ai) : BuffTrigger(ai, "power infusion") {}
    };

    class InnerFocusTrigger : public BuffTrigger
    {
    public:
        InnerFocusTrigger(PlayerbotAI* ai) : BuffTrigger(ai, "inner focus") {}
    };

    class ShadowProtectionOnPartyTrigger : public BuffOnPartyTrigger
    {
    public:
        ShadowProtectionOnPartyTrigger(PlayerbotAI* ai) : BuffOnPartyTrigger(ai, "shadow protection", 2) {}
    };

    class ShadowProtectionTrigger : public BuffTrigger
    {
    public:
        ShadowProtectionTrigger(PlayerbotAI* ai) : BuffTrigger(ai, "shadow protection", 2) {}
    };

    class ShackleUndeadTrigger : public HasCcTargetTrigger
    {
    public:
        ShackleUndeadTrigger(PlayerbotAI* ai) : HasCcTargetTrigger(ai, "shackle undead") {}
    };
}
