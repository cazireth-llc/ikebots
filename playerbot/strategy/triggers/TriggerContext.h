#pragma once

#include "HealthTriggers.h"
#include "GenericTriggers.h"
#include "LootTriggers.h"
#include "../triggers/GenericTriggers.h"
#include "LfgTriggers.h"
#include "PvpTriggers.h"
#include "RpgTriggers.h"
#include "TravelTriggers.h"
#include "RtiTriggers.h"
#include "CureTriggers.h"
#include "ActiveQuestTriggers.h"

namespace ai
{

    class TriggerContext : public NamedObjectContext<Trigger>
    {
    public:
        TriggerContext()
        {
            creators["return"] = &TriggerContext::_return;
            creators["sit"] = &TriggerContext::sit;
            creators["collision"] = &TriggerContext::collision;

            creators["timer"] = &TriggerContext::Timer;
            creators["random"] = &TriggerContext::Random;
            creators["seldom"] = &TriggerContext::seldom;
            creators["often"] = &TriggerContext::often;

            creators["target critical health"] = &TriggerContext::TargetCriticalHealth;

            creators["critical health"] = &TriggerContext::CriticalHealth;
            creators["low health"] = &TriggerContext::LowHealth;
            creators["medium health"] = &TriggerContext::MediumHealth;
            creators["almost full health"] = &TriggerContext::AlmostFullHealth;

            creators["low mana"] = &TriggerContext::LowMana;
            creators["medium mana"] = &TriggerContext::MediumMana;

            creators["party member critical health"] = &TriggerContext::PartyMemberCriticalHealth;
            creators["party member low health"] = &TriggerContext::PartyMemberLowHealth;
            creators["party member medium health"] = &TriggerContext::PartyMemberMediumHealth;
            creators["party member almost full health"] = &TriggerContext::PartyMemberAlmostFullHealth;

            creators["light rage available"] = &TriggerContext::LightRageAvailable;
            creators["medium rage available"] = &TriggerContext::MediumRageAvailable;
            creators["high rage available"] = &TriggerContext::HighRageAvailable;

            creators["light energy available"] = &TriggerContext::LightEnergyAvailable;
            creators["medium energy available"] = &TriggerContext::MediumEnergyAvailable;
            creators["high energy available"] = &TriggerContext::HighEnergyAvailable;

            creators["loot available"] = &TriggerContext::LootAvailable;
            creators["no attackers"] = &TriggerContext::NoAttackers;
            creators["no target"] = &TriggerContext::NoTarget;
            creators["target in sight"] = &TriggerContext::TargetInSight;
            creators["not dps target active"] = &TriggerContext::not_dps_target_active;
            creators["not dps aoe target active"] = &TriggerContext::not_dps_aoe_target_active;
            creators["has nearest adds"] = &TriggerContext::has_nearest_adds;
            creators["enemy player near"] = &TriggerContext::enemy_player_near;

            creators["tank aoe"] = &TriggerContext::TankAoe;
            creators["lose aggro"] = &TriggerContext::LoseAggro;
            creators["has aggro"] = &TriggerContext::HasAggro;

            creators["light aoe"] = &TriggerContext::LightAoe;
            creators["medium aoe"] = &TriggerContext::MediumAoe;
            creators["high aoe"] = &TriggerContext::HighAoe;

            creators["enemy out of melee"] = &TriggerContext::EnemyOutOfMelee;
            creators["enemy out of spell"] = &TriggerContext::EnemyOutOfSpell;
            creators["enemy too close for spell"] = &TriggerContext::enemy_too_close_for_spell;
            creators["enemy too close for shoot"] = &TriggerContext::enemy_too_close_for_shoot;
            creators["enemy too close for melee"] = &TriggerContext::enemy_too_close_for_melee;
            creators["enemy is close"] = &TriggerContext::enemy_is_close;
            creators["party member to heal out of spell range"] = &TriggerContext::party_member_to_heal_out_of_spell_range;

            creators["combo points available"] = &TriggerContext::ComboPointsAvailable;

            creators["medium threat"] = &TriggerContext::MediumThreat;

            creators["dead"] = &TriggerContext::Dead;
            creators["corpse near"] = &TriggerContext::corpse_near;
            creators["party member dead"] = &TriggerContext::PartyMemberDead;
            creators["no pet"] = &TriggerContext::no_pet;
            creators["has attackers"] = &TriggerContext::has_attackers;
            creators["no possible targets"] = &TriggerContext::no_possible_targets;
            creators["possible adds"] = &TriggerContext::possible_adds;

            creators["no drink"] = &TriggerContext::no_drink;
            creators["no food"] = &TriggerContext::no_food;

            creators["panic"] = &TriggerContext::panic;
            creators["outnumbered"] = &TriggerContext::outnumbered;
            creators["behind target"] = &TriggerContext::behind_target;
            creators["not behind target"] = &TriggerContext::not_behind_target;
            creators["not facing target"] = &TriggerContext::not_facing_target;
            creators["far from master"] = &TriggerContext::far_from_master;
            creators["far from loot target"] = &TriggerContext::far_from_loot_target;
            creators["can loot"] = &TriggerContext::can_loot;
            creators["swimming"] = &TriggerContext::swimming;
            creators["target changed"] = &TriggerContext::target_changed;

            creators["critical aoe heal"] = &TriggerContext::critical_aoe_heal;
            creators["low aoe heal"] = &TriggerContext::low_aoe_heal;
            creators["medium aoe heal"] = &TriggerContext::medium_aoe_heal;
            creators["invalid target"] = &TriggerContext::invalid_target;
            creators["lfg proposal active"] = &TriggerContext::lfg_proposal_active;

            creators["random bot update"] = &TriggerContext::random_bot_update_trigger;
            creators["no non bot players around"] = &TriggerContext::no_non_bot_players_around;
            creators["new player nearby"] = &TriggerContext::new_player_nearby;
            creators["no rpg target"] = &TriggerContext::no_rpg_target;
            creators["far from rpg target"] = &TriggerContext::far_from_rpg_target;
            creators["no travel target"] = &TriggerContext::no_travel_target;
            creators["far from travel target"] = &TriggerContext::far_from_travel_target;			
            creators["no rti target"] = &TriggerContext::no_rti;

            creators["give food"] = &TriggerContext::give_food;
            creators["give water"] = &TriggerContext::give_water;

            creators["bg waiting"] = &TriggerContext::bg_waiting;
            creators["bg active"] = &TriggerContext::bg_active;
            creators["player has no flag"] = &TriggerContext::player_has_no_flag;
            creators["player has flag"] = &TriggerContext::player_has_flag;
            creators["team has flag"] = &TriggerContext::team_has_flag;
            creators["enemy team has flag"] = &TriggerContext::enemy_team_has_flag;
            creators["enemy flagcarrier near"] = &TriggerContext::enemy_flagcarrier_near;
            creators["in battleground"] = &TriggerContext::player_is_in_battleground;
            creators["in battleground without flag"] = &TriggerContext::player_is_in_battleground_no_flag;
            creators["wants in bg"] = &TriggerContext::player_wants_in_bg;

            creators["mounted"] = &TriggerContext::mounted;

            // move to/enter dark portal if near
            creators["near dark portal"] = &TriggerContext::near_dark_portal;
            creators["at dark portal azeroth"] = &TriggerContext::at_dark_portal_azeroth;
            creators["at dark portal outland"] = &TriggerContext::at_dark_portal_outland;

            creators["need world buff"] = &TriggerContext::need_world_buff;
            creators["falling"] = &TriggerContext::falling;
            creators["falling far"] = &TriggerContext::falling_far;

            creators["has continue target"] = &TriggerContext::has_continue_action;

            creators["free quest log slots"] = &TriggerContext::free_quest_log_slots;
            creators["active objectives"] = &TriggerContext::active_objectives;
            creators["completed quests"] = &TriggerContext::completed_quests;
        }

    private:
        static Trigger* at_dark_portal_outland(PlayerbotAI* ai) { return new AtDarkPortalOutlandTrigger(ai); }
        static Trigger* at_dark_portal_azeroth(PlayerbotAI* ai) { return new AtDarkPortalAzerothTrigger(ai); }
        static Trigger* near_dark_portal(PlayerbotAI* ai) { return new NearDarkPortalTrigger(ai); }
        static Trigger* mounted(PlayerbotAI* ai) { return new IsMountedTrigger(ai); }
        static Trigger* enemy_flagcarrier_near(PlayerbotAI* ai) { return new EnemyFlagCarrierNear(ai); }
        static Trigger* player_has_no_flag(PlayerbotAI* ai) { return new PlayerHasNoFlag(ai); }
        static Trigger* bg_waiting(PlayerbotAI* ai) { return new BgWaitingTrigger(ai); }
        static Trigger* bg_active(PlayerbotAI* ai) { return new BgActiveTrigger(ai); }
        static Trigger* player_has_flag(PlayerbotAI* ai) { return new PlayerHasFlag(ai); }
        static Trigger* team_has_flag(PlayerbotAI* ai) { return new TeamHasFlag(ai); }
        static Trigger* enemy_team_has_flag(PlayerbotAI* ai) { return new EnemyTeamHasFlag(ai); }
        static Trigger* player_is_in_battleground(PlayerbotAI *ai) { return new PlayerIsInBattleground(ai); }
        static Trigger* player_is_in_battleground_no_flag(PlayerbotAI *ai) { return new PlayerIsInBattlegroundWithoutFlag(ai); }
        static Trigger* give_food(PlayerbotAI* ai) { return new GiveFoodTrigger(ai); }
        static Trigger* give_water(PlayerbotAI* ai) { return new GiveWaterTrigger(ai); }
        static Trigger* no_rti(PlayerbotAI* ai) { return new NoRtiTrigger(ai); }
        static Trigger* _return(PlayerbotAI* ai) { return new ReturnTrigger(ai); }
        static Trigger* sit(PlayerbotAI* ai) { return new SitTrigger(ai); }
        static Trigger* far_from_rpg_target(PlayerbotAI* ai) { return new FarFromRpgTargetTrigger(ai); }
        static Trigger* no_rpg_target(PlayerbotAI* ai) { return new NoRpgTargetTrigger(ai); }
        static Trigger* far_from_travel_target(PlayerbotAI* ai) { return new FarFromTravelTargetTrigger(ai); }
        static Trigger* no_travel_target(PlayerbotAI* ai) { return new NoTravelTargetTrigger(ai); }		
        static Trigger* collision(PlayerbotAI* ai) { return new CollisionTrigger(ai); }
        static Trigger* lfg_proposal_active(PlayerbotAI* ai) { return new LfgProposalActiveTrigger(ai); }
        static Trigger* invalid_target(PlayerbotAI* ai) { return new InvalidTargetTrigger(ai); }
        static Trigger* critical_aoe_heal(PlayerbotAI* ai) { return new AoeHealTrigger(ai, "critical aoe heal", "critical", 2); }
        static Trigger* low_aoe_heal(PlayerbotAI* ai) { return new AoeHealTrigger(ai, "low aoe heal", "low", 2); }
        static Trigger* medium_aoe_heal(PlayerbotAI* ai) { return new AoeHealTrigger(ai, "medium aoe heal", "medium", 2); }
        static Trigger* target_changed(PlayerbotAI* ai) { return new TargetChangedTrigger(ai); }
        static Trigger* swimming(PlayerbotAI* ai) { return new IsSwimmingTrigger(ai); }
        static Trigger* no_possible_targets(PlayerbotAI* ai) { return new NoPossibleTargetsTrigger(ai); }
        static Trigger* possible_adds(PlayerbotAI* ai) { return new PossibleAddsTrigger(ai); }
        static Trigger* can_loot(PlayerbotAI* ai) { return new CanLootTrigger(ai); }
        static Trigger* far_from_loot_target(PlayerbotAI* ai) { return new FarFromCurrentLootTrigger(ai); }
        static Trigger* far_from_master(PlayerbotAI* ai) { return new FarFromMasterTrigger(ai); }
        static Trigger* behind_target(PlayerbotAI* ai) { return new IsBehindTargetTrigger(ai); }
        static Trigger* not_behind_target(PlayerbotAI* ai) { return new IsNotBehindTargetTrigger(ai); }
        static Trigger* not_facing_target(PlayerbotAI* ai) { return new IsNotFacingTargetTrigger(ai); }
        static Trigger* panic(PlayerbotAI* ai) { return new PanicTrigger(ai); }
        static Trigger* outnumbered(PlayerbotAI* ai) { return new OutNumberedTrigger(ai); }
        static Trigger* no_drink(PlayerbotAI* ai) { return new NoDrinkTrigger(ai); }
        static Trigger* no_food(PlayerbotAI* ai) { return new NoFoodTrigger(ai); }
        static Trigger* LightAoe(PlayerbotAI* ai) { return new LightAoeTrigger(ai); }
        static Trigger* MediumAoe(PlayerbotAI* ai) { return new MediumAoeTrigger(ai); }
        static Trigger* HighAoe(PlayerbotAI* ai) { return new HighAoeTrigger(ai); }
        static Trigger* LoseAggro(PlayerbotAI* ai) { return new LoseAggroTrigger(ai); }
        static Trigger* HasAggro(PlayerbotAI* ai) { return new HasAggroTrigger(ai); }
        static Trigger* LowHealth(PlayerbotAI* ai) { return new LowHealthTrigger(ai); }
        static Trigger* MediumHealth(PlayerbotAI* ai) { return new MediumHealthTrigger(ai); }
        static Trigger* AlmostFullHealth(PlayerbotAI* ai) { return new AlmostFullHealthTrigger(ai); }
        static Trigger* CriticalHealth(PlayerbotAI* ai) { return new CriticalHealthTrigger(ai); }
        static Trigger* TargetCriticalHealth(PlayerbotAI* ai) { return new TargetCriticalHealthTrigger(ai); }
        static Trigger* LowMana(PlayerbotAI* ai) { return new LowManaTrigger(ai); }
        static Trigger* MediumMana(PlayerbotAI* ai) { return new MediumManaTrigger(ai); }
        static Trigger* LightRageAvailable(PlayerbotAI* ai) { return new LightRageAvailableTrigger(ai); }
        static Trigger* MediumRageAvailable(PlayerbotAI* ai) { return new MediumRageAvailableTrigger(ai); }
        static Trigger* HighRageAvailable(PlayerbotAI* ai) { return new HighRageAvailableTrigger(ai); }
        static Trigger* LightEnergyAvailable(PlayerbotAI* ai) { return new LightEnergyAvailableTrigger(ai); }
        static Trigger* MediumEnergyAvailable(PlayerbotAI* ai) { return new MediumEnergyAvailableTrigger(ai); }
        static Trigger* HighEnergyAvailable(PlayerbotAI* ai) { return new HighEnergyAvailableTrigger(ai); }
        static Trigger* LootAvailable(PlayerbotAI* ai) { return new LootAvailableTrigger(ai); }
        static Trigger* NoAttackers(PlayerbotAI* ai) { return new NoAttackersTrigger(ai); }
        static Trigger* TankAoe(PlayerbotAI* ai) { return new TankAoeTrigger(ai); }
        static Trigger* Timer(PlayerbotAI* ai) { return new TimerTrigger(ai); }
        static Trigger* NoTarget(PlayerbotAI* ai) { return new NoTargetTrigger(ai); }
        static Trigger* TargetInSight(PlayerbotAI* ai) { return new TargetInSightTrigger(ai); }
        static Trigger* not_dps_target_active(PlayerbotAI* ai) { return new NotDpsTargetActiveTrigger(ai); }
        static Trigger* not_dps_aoe_target_active(PlayerbotAI* ai) { return new NotDpsAoeTargetActiveTrigger(ai); }
        static Trigger* has_nearest_adds(PlayerbotAI* ai) { return new HasNearestAddsTrigger(ai); }
        static Trigger* enemy_player_near(PlayerbotAI* ai) { return new EnemyPlayerNear(ai); }
        static Trigger* Random(PlayerbotAI* ai) { return new RandomTrigger(ai, "random", 20); }
        static Trigger* seldom(PlayerbotAI* ai) { return new RandomTrigger(ai, "seldom", 300); }
        static Trigger* often(PlayerbotAI* ai) { return new RandomTrigger(ai, "often", 5); }
        static Trigger* EnemyOutOfMelee(PlayerbotAI* ai) { return new EnemyOutOfMeleeTrigger(ai); }
        static Trigger* EnemyOutOfSpell(PlayerbotAI* ai) { return new EnemyOutOfSpellRangeTrigger(ai); }
        static Trigger* enemy_too_close_for_spell(PlayerbotAI* ai) { return new EnemyTooCloseForSpellTrigger(ai); }
        static Trigger* enemy_too_close_for_shoot(PlayerbotAI* ai) { return new EnemyTooCloseForShootTrigger(ai); }
        static Trigger* enemy_too_close_for_melee(PlayerbotAI* ai) { return new EnemyTooCloseForMeleeTrigger(ai); }
        static Trigger* enemy_is_close(PlayerbotAI* ai) { return new EnemyIsCloseTrigger(ai); }
        static Trigger* party_member_to_heal_out_of_spell_range(PlayerbotAI* ai) { return new PartyMemberToHealOutOfSpellRangeTrigger(ai); }
        static Trigger* ComboPointsAvailable(PlayerbotAI* ai) { return new ComboPointsAvailableTrigger(ai); }
        static Trigger* MediumThreat(PlayerbotAI* ai) { return new MediumThreatTrigger(ai); }
        static Trigger* Dead(PlayerbotAI* ai) { return new DeadTrigger(ai); }
        static Trigger* corpse_near(PlayerbotAI* ai) { return new CorpseNearTrigger(ai); }
        static Trigger* PartyMemberDead(PlayerbotAI* ai) { return new PartyMemberDeadTrigger(ai); }
        static Trigger* PartyMemberLowHealth(PlayerbotAI* ai) { return new PartyMemberLowHealthTrigger(ai); }
        static Trigger* PartyMemberMediumHealth(PlayerbotAI* ai) { return new PartyMemberMediumHealthTrigger(ai); }
        static Trigger* PartyMemberAlmostFullHealth(PlayerbotAI* ai) { return new PartyMemberAlmostFullHealthTrigger(ai); }
        static Trigger* PartyMemberCriticalHealth(PlayerbotAI* ai) { return new PartyMemberCriticalHealthTrigger(ai); }
        static Trigger* no_pet(PlayerbotAI* ai) { return new NoPetTrigger(ai); }
        static Trigger* has_attackers(PlayerbotAI* ai) { return new HasAttackersTrigger(ai); }
        static Trigger* random_bot_update_trigger(PlayerbotAI* ai) { return new RandomBotUpdateTrigger(ai); }
        static Trigger* no_non_bot_players_around(PlayerbotAI* ai) { return new NoNonBotPlayersAroundTrigger(ai); }
        static Trigger* new_player_nearby(PlayerbotAI* ai) { return new NewPlayerNearbyTrigger(ai); }
        static Trigger* need_world_buff(PlayerbotAI* ai) { return new NeedWorldBuffTrigger(ai); }
        static Trigger* falling(PlayerbotAI* ai) { return new IsFallingTrigger(ai); }
        static Trigger* falling_far(PlayerbotAI* ai) { return new IsFallingFarTrigger(ai); }
        static Trigger* has_continue_action(PlayerbotAI* ai) { return new HasContinueActionTrigger(ai); }
        static Trigger* player_wants_in_bg(PlayerbotAI* ai) { return new PlayerWantsInBattlegroundTrigger(ai); }
        static Trigger* free_quest_log_slots(PlayerbotAI* ai) { return new FreeQuestLogSlotTrigger(ai); }
        static Trigger* active_objectives(PlayerbotAI* ai) { return new ActiveObjectivesTrigger(ai); }
        static Trigger* completed_quests(PlayerbotAI* ai) { return new CompletedQuestsTrigger(ai); }        
    };
};
