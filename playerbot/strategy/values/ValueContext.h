#pragma once

#include "ActiveSpellValue.h"
#include "NearestGameObjects.h"
#include "LogLevelValue.h"
#include "NearestNpcsValue.h"
#include "PossibleTargetsValue.h"
#include "NearestAdsValue.h"
#include "NearestCorpsesValue.h"
#include "PartyMemberWithoutAuraValue.h"
#include "PartyMemberToHeal.h"
#include "PartyMemberToResurrect.h"
#include "CurrentTargetValue.h"
#include "SelfTargetValue.h"
#include "MasterTargetValue.h"
#include "LineTargetValue.h"
#include "TankTargetValue.h"
#include "DpsTargetValue.h"
#include "CcTargetValue.h"
#include "CurrentCcTargetValue.h"
#include "PetTargetValue.h"
#include "GrindTargetValue.h"
#include "RtiTargetValue.h"
#include "PartyMemberToDispel.h"
#include "StatsValues.h"
#include "AttackerCountValues.h"
#include "AttackersValue.h"
#include "AvailableLootValue.h"
#include "AlwaysLootListValue.h"
#include "LootStrategyValue.h"
#include "HasAvailableLootValue.h"
#include "LastMovementValue.h"
#include "DistanceValue.h"
#include "IsMovingValue.h"
#include "IsBehindValue.h"
#include "IsFacingValue.h"
#include "ItemCountValue.h"
#include "SpellIdValue.h"
#include "ItemForSpellValue.h"
#include "SpellCastUsefulValue.h"
#include "LastSpellCastValue.h"
#include "ChatValue.h"
#include "HasTotemValue.h"
#include "LeastHpTargetValue.h"
#include "AoeHealValues.h"
#include "AoeValues.h"
#include "RtiValue.h"
#include "PositionValue.h"
#include "ThreatValues.h"
#include "DuelTargetValue.h"
#include "InvalidTargetValue.h"
#include "EnemyPlayerValue.h"
#include "AttackerWithoutAuraTargetValue.h"
#include "CollisionValue.h"
#include "CraftValue.h"
#include "LastSpellCastTimeValue.h"
#include "ManaSaveLevelValue.h"
#include "LfgValues.h"
#include "PvpValues.h"
#include "EnemyHealerTargetValue.h"
#include "Formations.h"
#include "ItemUsageValue.h"
#include "LastSaidValue.h"
#include "NearestFriendlyPlayersValue.h"
#include "NearestNonBotPlayersValue.h"
#include "NewPlayerNearbyValue.h"
#include "OutfitListValue.h"
#include "PartyMemberWithoutItemValue.h"
#include "PossibleRpgTargetsValue.h"
#include "RandomBotUpdateValue.h"
#include "RangeValues.h"
#include "SkipSpellsListValue.h"
#include "SnareTargetValue.h"
#include "Stances.h"
#include "MoveTargetValue.h"
#include "QuestValues.h"

namespace ai
{
    class ValueContext : public NamedObjectContext<UntypedValue>
    {
    public:
        ValueContext()
        {
            creators["active spell"] = &ValueContext::active_spell;
            creators["craft"] = &ValueContext::craft;
            creators["collision"] = &ValueContext::collision;
            creators["skip spells list"] = &ValueContext::skip_spells_list_value;
            creators["nearest game objects"] = &ValueContext::nearest_game_objects;
            creators["nearest game objects no los"] = &ValueContext::nearest_game_objects_no_los;
            creators["closest game objects"] = &ValueContext::closest_game_objects;
            creators["nearest npcs"] = &ValueContext::nearest_npcs;
            creators["nearest friendly players"] = &ValueContext::nearest_friendly_players;
            creators["closest friendly players"] = &ValueContext::closest_friendly_players;
            creators["nearest enemy players"] = &ValueContext::nearest_enemy_players;
            creators["possible targets"] = &ValueContext::possible_targets;
            creators["possible targets no los"] = &ValueContext::possible_targets_no_los;
            creators["possible adds"] = &ValueContext::possible_adds;
            creators["all targets"] = &ValueContext::all_targets;
            creators["possible rpg targets"] = &ValueContext::possible_rpg_targets;
            creators["nearest adds"] = &ValueContext::nearest_adds;
            creators["nearest corpses"] = &ValueContext::nearest_corpses;
            creators["log level"] = &ValueContext::log_level;
            creators["party member without aura"] = &ValueContext::party_member_without_aura;
            creators["attacker without aura"] = &ValueContext::attacker_without_aura;
            creators["party member to heal"] = &ValueContext::party_member_to_heal;
            creators["party member to resurrect"] = &ValueContext::party_member_to_resurrect;
            creators["current target"] = &ValueContext::current_target;
            creators["self target"] = &ValueContext::self_target;
            creators["master target"] = &ValueContext::master;
            creators["line target"] = &ValueContext::line_target;
            creators["tank target"] = &ValueContext::tank_target;
            creators["dps target"] = &ValueContext::dps_target;
            creators["dps aoe target"] = &ValueContext::dps_aoe_target;
            creators["least hp target"] = &ValueContext::least_hp_target;
            creators["enemy player target"] = &ValueContext::enemy_player_target;
            creators["cc target"] = &ValueContext::cc_target;
            creators["current cc target"] = &ValueContext::current_cc_target;
            creators["pet target"] = &ValueContext::pet_target;
            creators["old target"] = &ValueContext::old_target;
            creators["grind target"] = &ValueContext::grind_target;
            creators["rti target"] = &ValueContext::rti_target;
            creators["rti cc target"] = &ValueContext::rti_cc_target;
            creators["duel target"] = &ValueContext::duel_target;
            creators["party member to dispel"] = &ValueContext::party_member_to_dispel;
            creators["health"] = &ValueContext::health;
            creators["rage"] = &ValueContext::rage;
            creators["energy"] = &ValueContext::energy;
            creators["mana"] = &ValueContext::mana;
            creators["combo"] = &ValueContext::combo;
            creators["dead"] = &ValueContext::dead;
            creators["pet dead"] = &ValueContext::pet_dead;
            creators["pet happy"] = &ValueContext::pet_happy;
            creators["has mana"] = &ValueContext::has_mana;
            creators["attacker count"] = &ValueContext::attacker_count;
            creators["my attacker count"] = &ValueContext::my_attacker_count;
            creators["has aggro"] = &ValueContext::has_aggro;
            creators["mounted"] = &ValueContext::mounted;

            creators["can loot"] = &ValueContext::can_loot;
            creators["loot target"] = &ValueContext::loot_target;
            creators["available loot"] = &ValueContext::available_loot;
            creators["has available loot"] = &ValueContext::has_available_loot;
            creators["always loot list"] = &ValueContext::always_loot_list;
            creators["loot strategy"] = &ValueContext::loot_strategy;
            creators["last movement"] = &ValueContext::last_movement;
            creators["stay time"] = &ValueContext::stay_time;
            creators["last taxi"] = &ValueContext::last_movement;
            creators["last area trigger"] = &ValueContext::last_movement;
            creators["distance"] = &ValueContext::distance;
            creators["moving"] = &ValueContext::moving;
            creators["swimming"] = &ValueContext::swimming;
            creators["behind"] = &ValueContext::behind;
            creators["facing"] = &ValueContext::facing;

            creators["item count"] = &ValueContext::item_count;
            creators["inventory items"] = &ValueContext::inventory_item;

            creators["spell id"] = &ValueContext::spell_id;
            creators["item for spell"] = &ValueContext::item_for_spell;
            creators["spell cast useful"] = &ValueContext::spell_cast_useful;
            creators["last spell cast"] = &ValueContext::last_spell_cast;
            creators["last spell cast time"] = &ValueContext::last_spell_cast_time;
            creators["chat"] = &ValueContext::chat;
            creators["has totem"] = &ValueContext::has_totem;

            creators["aoe heal"] = &ValueContext::aoe_heal;

            creators["rti cc"] = &ValueContext::rti_cc;
            creators["rti"] = &ValueContext::rti;
            creators["position"] = &ValueContext::position;
            creators["threat"] = &ValueContext::threat;

            creators["balance"] = &ValueContext::balance;
            creators["attackers"] = &ValueContext::attackers;
            creators["invalid target"] = &ValueContext::invalid_target;
            creators["mana save level"] = &ValueContext::mana_save_level;
            creators["combat"] = &ValueContext::combat;
            creators["lfg proposal"] = &ValueContext::lfg_proposal;
            creators["bag space"] = &ValueContext::bag_space;
            creators["durability"] = &ValueContext::durability;
            creators["repair cost"] = &ValueContext::repair_cost;
            creators["enemy healer target"] = &ValueContext::enemy_healer_target;
            creators["snare target"] = &ValueContext::snare_target;
            creators["formation"] = &ValueContext::formation;
            creators["stance"] = &ValueContext::stance;
            creators["item usage"] = &ValueContext::item_usage;
            creators["speed"] = &ValueContext::speed;
            creators["last said"] = &ValueContext::last_said;
            creators["last emote"] = &ValueContext::last_emote;

            creators["aoe count"] = &ValueContext::aoe_count;
            creators["aoe position"] = &ValueContext::aoe_position;
            creators["outfit list"] = &ValueContext::outfit_list_value;

            creators["random bot update"] = &ValueContext::random_bot_update_value;
            creators["nearest non bot players"] = &ValueContext::nearest_non_bot_players;
            creators["new player nearby"] = &ValueContext::new_player_nearby;
            creators["already seen players"] = &ValueContext::already_seen_players;
            creators["rpg target"] = &ValueContext::rpg_target;
            creators["ignore rpg target"] = &ValueContext::ignore_rpg_target;
            creators["travel target"] = &ValueContext::travel_target;			
            creators["talk target"] = &ValueContext::talk_target;
            creators["pull target"] = &ValueContext::pull_target;
            creators["group"] = &ValueContext::group;
            creators["range"] = &ValueContext::range;
            creators["inside target"] = &ValueContext::inside_target;
            creators["party member without item"] = &ValueContext::party_member_without_item;
            creators["party member without food"] = &ValueContext::party_member_without_food;
            creators["party member without water"] = &ValueContext::party_member_without_water;
            creators["death count"] = &ValueContext::death_count;

            creators["bg type"] = &ValueContext::bg_type;
            creators["arena type"] = &ValueContext::arena_type;
            creators["bg role"] = &ValueContext::bg_role;
            creators["bg master"] = &ValueContext::bg_master;
            creators["enemy flag carrier"] = &ValueContext::enemy_fc;
            creators["team flag carrier"] = &ValueContext::team_fc;

            creators["move target"] = &ValueContext::move_target;

            creators["active quest givers"] = &ValueContext::active_quest_givers;
            creators["active quest takers"] = &ValueContext::active_quest_takers;
            creators["active quest objectives"] = &ValueContext::active_quest_objectives;
            creators["free quest log slots"] = &ValueContext::free_quest_log_slots;
        }

    private:
        static UntypedValue* team_fc(PlayerbotAI* ai) { return new FlagCarrierValue(ai, true, true); }
        static UntypedValue* enemy_fc(PlayerbotAI* ai) { return new FlagCarrierValue(ai, false, true); }
        static UntypedValue* bg_master(PlayerbotAI* ai) { return new BgMasterValue(ai); }
        static UntypedValue* bg_role(PlayerbotAI* ai) { return new BgRoleValue(ai); }
        static UntypedValue* arena_type(PlayerbotAI* ai) { return new ArenaTypeValue(ai); }
        static UntypedValue* bg_type(PlayerbotAI* ai) { return new BgTypeValue(ai); }
        static UntypedValue* party_member_without_water(PlayerbotAI* ai) { return new PartyMemberWithoutWaterValue(ai); }
        static UntypedValue* party_member_without_food(PlayerbotAI* ai) { return new PartyMemberWithoutFoodValue(ai); }
        static UntypedValue* party_member_without_item(PlayerbotAI* ai) { return new PartyMemberWithoutItemValue(ai); }
        static UntypedValue* inside_target(PlayerbotAI* ai) { return new InsideTargetValue(ai); }
        static UntypedValue* range(PlayerbotAI* ai) { return new RangeValue(ai); }
        static UntypedValue* active_spell(PlayerbotAI* ai) { return new ActiveSpellValue(ai); }
        static UntypedValue* group(PlayerbotAI* ai) { return new IsInGroupValue(ai); }
        static UntypedValue* craft(PlayerbotAI* ai) { return new CraftValue(ai); }
        static UntypedValue* collision(PlayerbotAI* ai) { return new CollisionValue(ai); }
        static UntypedValue* already_seen_players(PlayerbotAI* ai) { return new AlreadySeenPlayersValue(ai); }
        static UntypedValue* new_player_nearby(PlayerbotAI* ai) { return new NewPlayerNearbyValue(ai); }
        static UntypedValue* item_usage(PlayerbotAI* ai) { return new ItemUsageValue(ai); }
        static UntypedValue* formation(PlayerbotAI* ai) { return new FormationValue(ai); }
        static UntypedValue* stance(PlayerbotAI* ai) { return new StanceValue(ai); }
        static UntypedValue* mana_save_level(PlayerbotAI* ai) { return new ManaSaveLevelValue(ai); }
        static UntypedValue* invalid_target(PlayerbotAI* ai) { return new InvalidTargetValue(ai); }
        static UntypedValue* balance(PlayerbotAI* ai) { return new BalancePercentValue(ai); }
        static UntypedValue* attackers(PlayerbotAI* ai) { return new AttackersValue(ai); }

        static UntypedValue* position(PlayerbotAI* ai) { return new PositionValue(ai); }
        static UntypedValue* rti(PlayerbotAI* ai) { return new RtiValue(ai); }
        static UntypedValue* rti_cc(PlayerbotAI* ai) { return new RtiCcValue(ai); }

        static UntypedValue* aoe_heal(PlayerbotAI* ai) { return new AoeHealValue(ai); }

        static UntypedValue* chat(PlayerbotAI* ai) { return new ChatValue(ai); }
        static UntypedValue* last_spell_cast(PlayerbotAI* ai) { return new LastSpellCastValue(ai); }
        static UntypedValue* last_spell_cast_time(PlayerbotAI* ai) { return new LastSpellCastTimeValue(ai); }
        static UntypedValue* spell_cast_useful(PlayerbotAI* ai) { return new SpellCastUsefulValue(ai); }
        static UntypedValue* item_for_spell(PlayerbotAI* ai) { return new ItemForSpellValue(ai); }
        static UntypedValue* spell_id(PlayerbotAI* ai) { return new SpellIdValue(ai); }
        static UntypedValue* inventory_item(PlayerbotAI* ai) { return new InventoryItemValue(ai); }
        static UntypedValue* item_count(PlayerbotAI* ai) { return new ItemCountValue(ai); }
        static UntypedValue* behind(PlayerbotAI* ai) { return new IsBehindValue(ai); }
        static UntypedValue* facing(PlayerbotAI* ai) { return new IsFacingValue(ai); }
        static UntypedValue* moving(PlayerbotAI* ai) { return new IsMovingValue(ai); }
        static UntypedValue* swimming(PlayerbotAI* ai) { return new IsSwimmingValue(ai); }
        static UntypedValue* distance(PlayerbotAI* ai) { return new DistanceValue(ai); }
        static UntypedValue* last_movement(PlayerbotAI* ai) { return new LastMovementValue(ai); }
        static UntypedValue* stay_time(PlayerbotAI* ai) { return new StayTimeValue(ai); }

        static UntypedValue* can_loot(PlayerbotAI* ai) { return new CanLootValue(ai); }
        static UntypedValue* available_loot(PlayerbotAI* ai) { return new AvailableLootValue(ai); }
        static UntypedValue* loot_target(PlayerbotAI* ai) { return new LootTargetValue(ai); }
        static UntypedValue* has_available_loot(PlayerbotAI* ai) { return new HasAvailableLootValue(ai); }
        static UntypedValue* always_loot_list(PlayerbotAI* ai) { return new AlwaysLootListValue(ai); }
        static UntypedValue* loot_strategy(PlayerbotAI* ai) { return new LootStrategyValue(ai); }

        static UntypedValue* attacker_count(PlayerbotAI* ai) { return new AttackerCountValue(ai); }
        static UntypedValue* my_attacker_count(PlayerbotAI* ai) { return new MyAttackerCountValue(ai); }
        static UntypedValue* has_aggro(PlayerbotAI* ai) { return new HasAggroValue(ai); }
        static UntypedValue* mounted(PlayerbotAI* ai) { return new IsMountedValue(ai); }
        static UntypedValue* health(PlayerbotAI* ai) { return new HealthValue(ai); }
        static UntypedValue* rage(PlayerbotAI* ai) { return new RageValue(ai); }
        static UntypedValue* energy(PlayerbotAI* ai) { return new EnergyValue(ai); }
        static UntypedValue* mana(PlayerbotAI* ai) { return new ManaValue(ai); }
        static UntypedValue* combo(PlayerbotAI* ai) { return new ComboPointsValue(ai); }
        static UntypedValue* dead(PlayerbotAI* ai) { return new IsDeadValue(ai); }
        static UntypedValue* pet_happy(PlayerbotAI* ai) { return new PetIsHappyValue(ai); }
        static UntypedValue* pet_dead(PlayerbotAI* ai) { return new PetIsDeadValue(ai); }
        static UntypedValue* has_mana(PlayerbotAI* ai) { return new HasManaValue(ai); }
        static UntypedValue* nearest_game_objects(PlayerbotAI* ai) { return new NearestGameObjects(ai); }
        static UntypedValue* nearest_game_objects_no_los(PlayerbotAI* ai) { return new NearestGameObjects(ai, sPlayerbotAIConfig.sightDistance, true); }
        static UntypedValue* closest_game_objects(PlayerbotAI* ai) { return new NearestGameObjects(ai, INTERACTION_DISTANCE); }
        static UntypedValue* log_level(PlayerbotAI* ai) { return new LogLevelValue(ai); }
        static UntypedValue* nearest_npcs(PlayerbotAI* ai) { return new NearestNpcsValue(ai); }
        static UntypedValue* nearest_friendly_players(PlayerbotAI* ai) { return new NearestFriendlyPlayersValue(ai); }
        static UntypedValue* closest_friendly_players(PlayerbotAI* ai) { return new NearestFriendlyPlayersValue(ai, INTERACTION_DISTANCE); }
        static UntypedValue* nearest_enemy_players(PlayerbotAI* ai) { return new NearestEnemyPlayersValue(ai); }
        static UntypedValue* nearest_corpses(PlayerbotAI* ai) { return new NearestCorpsesValue(ai); }
        static UntypedValue* possible_rpg_targets(PlayerbotAI* ai) { return new PossibleRpgTargetsValue(ai); }
        static UntypedValue* possible_targets(PlayerbotAI* ai) { return new PossibleTargetsValue(ai); }
        static UntypedValue* possible_targets_no_los(PlayerbotAI* ai) { return new PossibleTargetsValue(ai, "possible targets", 50.0f, true); }
        static UntypedValue* possible_adds(PlayerbotAI* ai) { return new PossibleAddsValue(ai); }
        static UntypedValue* all_targets(PlayerbotAI* ai) { return new AllTargetsValue(ai); }
        static UntypedValue* nearest_adds(PlayerbotAI* ai) { return new NearestAddsValue(ai); }
        static UntypedValue* party_member_without_aura(PlayerbotAI* ai) { return new PartyMemberWithoutAuraValue(ai); }
        static UntypedValue* attacker_without_aura(PlayerbotAI* ai) { return new AttackerWithoutAuraTargetValue(ai); }
        static UntypedValue* party_member_to_heal(PlayerbotAI* ai) { return new PartyMemberToHeal(ai); }
        static UntypedValue* party_member_to_resurrect(PlayerbotAI* ai) { return new PartyMemberToResurrect(ai); }
        static UntypedValue* party_member_to_dispel(PlayerbotAI* ai) { return new PartyMemberToDispel(ai); }
        static UntypedValue* current_target(PlayerbotAI* ai) { return new CurrentTargetValue(ai); }
        static UntypedValue* old_target(PlayerbotAI* ai) { return new CurrentTargetValue(ai); }
        static UntypedValue* self_target(PlayerbotAI* ai) { return new SelfTargetValue(ai); }
        static UntypedValue* master(PlayerbotAI* ai) { return new MasterTargetValue(ai); }
        static UntypedValue* line_target(PlayerbotAI* ai) { return new LineTargetValue(ai); }
        static UntypedValue* tank_target(PlayerbotAI* ai) { return new TankTargetValue(ai); }
        static UntypedValue* dps_target(PlayerbotAI* ai) { return new DpsTargetValue(ai); }
        static UntypedValue* dps_aoe_target(PlayerbotAI* ai) { return new DpsAoeTargetValue(ai); }
        static UntypedValue* least_hp_target(PlayerbotAI* ai) { return new LeastHpTargetValue(ai); }
        static UntypedValue* enemy_player_target(PlayerbotAI* ai) { return new EnemyPlayerValue(ai); }
        static UntypedValue* cc_target(PlayerbotAI* ai) { return new CcTargetValue(ai); }
        static UntypedValue* current_cc_target(PlayerbotAI* ai) { return new CurrentCcTargetValue(ai); }
        static UntypedValue* pet_target(PlayerbotAI* ai) { return new PetTargetValue(ai); }
        static UntypedValue* grind_target(PlayerbotAI* ai) { return new GrindTargetValue(ai); }
        static UntypedValue* rti_target(PlayerbotAI* ai) { return new RtiTargetValue(ai); }
        static UntypedValue* rti_cc_target(PlayerbotAI* ai) { return new RtiCcTargetValue(ai); }
        static UntypedValue* duel_target(PlayerbotAI* ai) { return new DuelTargetValue(ai); }
        static UntypedValue* has_totem(PlayerbotAI* ai) { return new HasTotemValue(ai); }
        static UntypedValue* threat(PlayerbotAI* ai) { return new ThreatValue(ai); }
        static UntypedValue* combat(PlayerbotAI* ai) { return new IsInCombatValue(ai); }
        static UntypedValue* lfg_proposal(PlayerbotAI* ai) { return new LfgProposalValue(ai); }
        static UntypedValue* bag_space(PlayerbotAI* ai) { return new BagSpaceValue(ai); }
        static UntypedValue* durability(PlayerbotAI* ai) { return new DurabilityValue(ai); }
        static UntypedValue* repair_cost(PlayerbotAI* ai) { return new RepairCostValue(ai); }
        static UntypedValue* enemy_healer_target(PlayerbotAI* ai) { return new EnemyHealerTargetValue(ai); }
        static UntypedValue* snare_target(PlayerbotAI* ai) { return new SnareTargetValue(ai); }
        static UntypedValue* speed(PlayerbotAI* ai) { return new SpeedValue(ai); }
        static UntypedValue* last_said(PlayerbotAI* ai) { return new LastSaidValue(ai); }
        static UntypedValue* last_emote(PlayerbotAI* ai) { return new LastEmoteValue(ai); }
        static UntypedValue* aoe_count(PlayerbotAI* ai) { return new AoeCountValue(ai); }
        static UntypedValue* aoe_position(PlayerbotAI* ai) { return new AoePositionValue(ai); }
        static UntypedValue* outfit_list_value(PlayerbotAI* ai) { return new OutfitListValue(ai); }
        static UntypedValue* random_bot_update_value(PlayerbotAI* ai) { return new RandomBotUpdateValue(ai); }
        static UntypedValue* nearest_non_bot_players(PlayerbotAI* ai) { return new NearestNonBotPlayersValue(ai); }
        static UntypedValue* skip_spells_list_value(PlayerbotAI* ai) { return new SkipSpellsListValue(ai); }
        static UntypedValue* rpg_target(PlayerbotAI* ai) { return new RpgTargetValue(ai); }
        static UntypedValue* travel_target(PlayerbotAI* ai) { return new TravelTargetValue(ai); }
        static UntypedValue* ignore_rpg_target(PlayerbotAI* ai) { return new IgnoreRpgTargetValue(ai); }
        static UntypedValue* talk_target(PlayerbotAI* ai) { return new TalkTargetValue(ai); }
        static UntypedValue* pull_target(PlayerbotAI* ai) { return new PullTargetValue(ai); }
        static UntypedValue* death_count(PlayerbotAI* ai) { return new DeathCountValue(ai); }

        static UntypedValue* move_target(PlayerbotAI* ai) { return new MoveTargetValue(ai); }

        static UntypedValue* active_quest_givers(PlayerbotAI* ai) { return new ActiveQuestGiversValue(ai); }
        static UntypedValue* active_quest_takers(PlayerbotAI* ai) { return new ActiveQuestTakersValue(ai); }
        static UntypedValue* active_quest_objectives(PlayerbotAI* ai) { return new ActiveQuestObjectivesValue(ai); }
        static UntypedValue* free_quest_log_slots(PlayerbotAI* ai) { return new FreeQuestLogSlotValue(ai); }
};
};
