#pragma once
#include "../Trigger.h"
#include "../../PlayerbotAIConfig.h"
#include "../../ServerFacade.h"
#include "../values/MoveTargetValue.h"

namespace ai
{
    class EnemyTooCloseForSpellTrigger : public Trigger {
    public:
        EnemyTooCloseForSpellTrigger(PlayerbotAI* ai) : Trigger(ai, "enemy too close for spell") {}
        virtual bool IsActive()
		{
			Unit* target = AI_VALUE(Unit*, "current target");
            return target &&
                sServerFacade.IsDistanceLessOrEqualThan(AI_VALUE2(float, "distance", "current target"), (ai->GetRange("spell") / 2));
        }
    };

    class EnemyTooCloseForShootTrigger : public Trigger {
    public:
        EnemyTooCloseForShootTrigger(PlayerbotAI* ai) : Trigger(ai, "enemy too close for shoot") {}
        virtual bool IsActive()
		{
			Unit* target = AI_VALUE(Unit*, "current target");
            return target &&
                sServerFacade.IsDistanceLessOrEqualThan(AI_VALUE2(float, "distance", "current target"), (ai->GetRange("shoot") / 2));
        }
    };

    class EnemyTooCloseForMeleeTrigger : public Trigger {
    public:
        EnemyTooCloseForMeleeTrigger(PlayerbotAI* ai) : Trigger(ai, "enemy too close for melee") {}
        virtual bool IsActive()
		{
			Unit* target = AI_VALUE(Unit*, "current target");
            return target && AI_VALUE2(bool, "inside target", "current target");
        }
    };

    class EnemyIsCloseTrigger : public Trigger {
    public:
        EnemyIsCloseTrigger(PlayerbotAI* ai) : Trigger(ai, "enemy is close") {}
        virtual bool IsActive()
		{
			Unit* target = AI_VALUE(Unit*, "current target");
            return target &&
                    sServerFacade.IsDistanceLessOrEqualThan(AI_VALUE2(float, "distance", "current target"), sPlayerbotAIConfig.tooCloseDistance);
        }
    };

    class OutOfRangeTrigger : public Trigger {
    public:
        OutOfRangeTrigger(PlayerbotAI* ai, string name, float distance) : Trigger(ai, name)
		{
            this->distance = distance;
        }
        virtual bool IsActive()
		{
			Unit* target = AI_VALUE(Unit*, GetTargetName());
			return target &&
			        sServerFacade.IsDistanceGreaterThan(AI_VALUE2(float, "distance", GetTargetName()), distance);
        }
        virtual string GetTargetName() { return "current target"; }

    protected:
        float distance;
    };

    class EnemyOutOfMeleeTrigger : public OutOfRangeTrigger
	{
    public:
        EnemyOutOfMeleeTrigger(PlayerbotAI* ai) : OutOfRangeTrigger(ai, "enemy out of melee range", sPlayerbotAIConfig.meleeDistance) {}
    };

    class EnemyOutOfSpellRangeTrigger : public OutOfRangeTrigger
	{
    public:
        EnemyOutOfSpellRangeTrigger(PlayerbotAI* ai) : OutOfRangeTrigger(ai, "enemy out of spell range", ai->GetRange("spell")) {}
    };

    class PartyMemberToHealOutOfSpellRangeTrigger : public OutOfRangeTrigger
	{
    public:
        PartyMemberToHealOutOfSpellRangeTrigger(PlayerbotAI* ai) : OutOfRangeTrigger(ai, "party member to heal out of spell range", ai->GetRange("heal")) {}
        virtual string GetTargetName() { return "party member to heal"; }
    };

    class FarFromMasterTrigger : public Trigger {
    public:
        FarFromMasterTrigger(PlayerbotAI* ai, string name = "far from master", float distance = 12.0f, int checkInterval = 50) : Trigger(ai, name, checkInterval), distance(distance) {}

        virtual bool IsActive()
        {
            return sServerFacade.IsDistanceGreaterThan(AI_VALUE2(float, "distance", "master target"), distance);
        }

    private:
        float distance;
    };

    class OutOfReactRangeTrigger : public FarFromMasterTrigger
    {
    public:
        OutOfReactRangeTrigger(PlayerbotAI* ai) : FarFromMasterTrigger(ai, "out of react range", 40.0f, 5) {}
    };

    class HasContinueActionTrigger : public Trigger
    {
    public:
        HasContinueActionTrigger(PlayerbotAI* ai) : Trigger(ai, "has continue action") {}

        virtual bool IsActive()
        {
            return AI_VALUE(MoveTarget*, "move target")->getRelevance();
        }
    };

    class ArrivedAtMoveTargetTrigger : public Trigger
    {
    public:
        ArrivedAtMoveTargetTrigger(PlayerbotAI* ai) : Trigger(ai, "arrived at move target") {}

        virtual bool IsActive()
        {
            return AI_VALUE(MoveTarget*, "move target")->getRelevance() && AI_VALUE(MoveTarget*, "move target")->isInRange(bot);
        }
    };
}
