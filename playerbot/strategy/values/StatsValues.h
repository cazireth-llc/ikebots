#pragma once
#include "../Value.h"

class Unit;

namespace ai
{
    class HealthValue : public Uint8CalculatedValue, public Qualified
    {
    public:
        HealthValue(PlayerbotAI* ai) : Uint8CalculatedValue(ai) {}

        Unit* GetTarget()
        {
            AiObjectContext* ctx = AiObject::context;
            return ctx->GetValue<Unit*>(qualifier)->Get();
        }
        virtual uint8 Calculate();
    };

    class IsDeadValue : public BoolCalculatedValue, public Qualified
    {
    public:
        IsDeadValue(PlayerbotAI* ai) : BoolCalculatedValue(ai) {}

        Unit* GetTarget()
        {
            AiObjectContext* ctx = AiObject::context;
            return ctx->GetValue<Unit*>(qualifier)->Get();
        }
        virtual bool Calculate();
    };

    class PetIsDeadValue : public BoolCalculatedValue
    {
    public:
        PetIsDeadValue(PlayerbotAI* ai) : BoolCalculatedValue(ai) {}
        virtual bool Calculate();
    };

    class PetIsHappyValue : public BoolCalculatedValue
    {
    public:
        PetIsHappyValue(PlayerbotAI* ai) : BoolCalculatedValue(ai) {}
        virtual bool Calculate();
    };

    class RageValue : public Uint8CalculatedValue, public Qualified
    {
    public:
        RageValue(PlayerbotAI* ai) : Uint8CalculatedValue(ai) {}

        Unit* GetTarget()
        {
            AiObjectContext* ctx = AiObject::context;
            return ctx->GetValue<Unit*>(qualifier)->Get();
        }
        virtual uint8 Calculate();
    };

    class EnergyValue : public Uint8CalculatedValue, public Qualified
    {
    public:
        EnergyValue(PlayerbotAI* ai) : Uint8CalculatedValue(ai) {}

        Unit* GetTarget()
        {
            AiObjectContext* ctx = AiObject::context;
            return ctx->GetValue<Unit*>(qualifier)->Get();
        }
        virtual uint8 Calculate();
    };

    class ManaValue : public Uint8CalculatedValue, public Qualified
    {
    public:
        ManaValue(PlayerbotAI* ai) : Uint8CalculatedValue(ai) {}

        Unit* GetTarget()
        {
            AiObjectContext* ctx = AiObject::context;
            return ctx->GetValue<Unit*>(qualifier)->Get();
        }
        virtual uint8 Calculate();
    };

    class HasManaValue : public BoolCalculatedValue, public Qualified
    {
    public:
        HasManaValue(PlayerbotAI* ai) : BoolCalculatedValue(ai) {}

        Unit* GetTarget()
        {
            AiObjectContext* ctx = AiObject::context;
            return ctx->GetValue<Unit*>(qualifier)->Get();
        }
        virtual bool Calculate();
    };

    class ComboPointsValue : public Uint8CalculatedValue, public Qualified
    {
    public:
        ComboPointsValue(PlayerbotAI* ai) : Uint8CalculatedValue(ai) {}

        Unit* GetTarget()
        {
            AiObjectContext* ctx = AiObject::context;
            return ctx->GetValue<Unit*>(qualifier)->Get();
        }
        virtual uint8 Calculate();
    };

    class IsMountedValue : public BoolCalculatedValue, public Qualified
    {
    public:
        IsMountedValue(PlayerbotAI* ai) : BoolCalculatedValue(ai) {}

        Unit* GetTarget()
        {
            AiObjectContext* ctx = AiObject::context;
            return ctx->GetValue<Unit*>(qualifier)->Get();
        }
        virtual bool Calculate();
    };

    class IsInCombatValue : public BoolCalculatedValue, public Qualified
    {
    public:
        IsInCombatValue(PlayerbotAI* ai) : BoolCalculatedValue(ai) {}

        Unit* GetTarget()
        {
            AiObjectContext* ctx = AiObject::context;
            return ctx->GetValue<Unit*>(qualifier)->Get();
        }
        virtual bool Calculate() ;
    };

    class BagSpaceValue : public Uint8CalculatedValue
    {
    public:
        BagSpaceValue(PlayerbotAI* ai) : Uint8CalculatedValue(ai) {}

        virtual uint8 Calculate();
    };

    class DurabilityValue : public Uint8CalculatedValue
    {
    public:
        DurabilityValue(PlayerbotAI* ai) : Uint8CalculatedValue(ai) {}

        virtual uint8 Calculate();
    };

    class RepairCostValue : public Uint32CalculatedValue
    {
    public:
        RepairCostValue(PlayerbotAI* ai) : Uint32CalculatedValue(ai) {}

        virtual uint32 Calculate();
    };

    class SpeedValue : public Uint8CalculatedValue, public Qualified
    {
    public:
        SpeedValue(PlayerbotAI* ai) : Uint8CalculatedValue(ai) {}

        Unit* GetTarget()
        {
            AiObjectContext* ctx = AiObject::context;
            return ctx->GetValue<Unit*>(qualifier)->Get();
        }
        virtual uint8 Calculate();
    };

    class IsInGroupValue : public BoolCalculatedValue
    {
    public:
        IsInGroupValue(PlayerbotAI* ai) : BoolCalculatedValue(ai) {}

        virtual bool Calculate() { return bot->GetGroup(); }
    };

    class DeathCountValue : public ManualSetValue<uint32>
    {
    public:
        DeathCountValue(PlayerbotAI* ai) : ManualSetValue<uint32>(ai, 0, "death_count") {}
    };
}
