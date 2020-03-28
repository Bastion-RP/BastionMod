class CfgPatches
{
	class BastionRP_AION
	{
		units[] = {"BastionRP_AION"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgMods
{
	class BastionRP_AION
	{
		dir = "BastionRP_AION";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "BastionRP_AION";
		credits = "BastionRP";
		author = "BastionRP";
		authorID = "0";
		version = "1.0";
		extra = 0;
		type = "mod";
		dependencies[] = {"World"};
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = {"BastionMod/NCC_Rations/AION/scripts/4_World"};
			};
		};
	};
};
class CfgVehicles
{
	class WaterBottle;
	class BastionRP_AION: WaterBottle
	{
		scope = 2;
		displayName = "AION";
		descriptionShort = "Aion | All-In-One NutritionAion. Developed by the NATO-CSTO Coalition.  Is an affordable, sustainable, all-in-one solution to the food crisis that we face every day. In order to regrow a population in a world wracked with disaster, it is imperative that our citizens have access to nutrition that is easy to consume and easy to sustain, so no one in any Bastion goes hungry.Each serving contains 25% daily value of protein and fats, slow-burning carbohydrates, and 28 essential vitamins and minerals that are then mixed with purified water and bottled to ensure that every citizen remains happy and, most importantly, healthy.";
		model = "BastionMod\NCC_Rations\AION\aion.p3d";
		weight = 25;
		itemSize[] = {1,3};
		varQuantityInit = 500;
		varQuantityMin = 0;
		varQuantityMax = 500;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1,{"DZ\gear\drinks\data\Loot_WaterBottle.rvmat"}},{0.7,{"DZ\gear\drinks\data\Loot_WaterBottle.rvmat"}},{0.5,{"DZ\gear\drinks\data\Loot_WaterBottle_damage.rvmat"}},{0.3,{"DZ\gear\drinks\data\Loot_WaterBottle_damage.rvmat"}},{0,{"DZ\gear\drinks\data\Loot_WaterBottle_destruct.rvmat"}}};
				};
			};
		};
		class Nutrition
		{
			fullnessIndex = 1.5;
			energy = 80;
			water = 0; // Don't put any water here, it will be added via a script
			nutritionalIndex = 1;
			toxicity = 0;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class WaterBottle_in_B
				{
					soundSet = "WaterBottle_in_B_SoundSet";
					id = 202;
				};
				class WaterBottle_in_C
				{
					soundSet = "WaterBottle_in_C_SoundSet";
					id = 203;
				};
				class WaterBottle_in_C1
				{
					soundSet = "WaterBottle_in_C1_SoundSet";
					id = 204;
				};
				class WaterBottle_out_A
				{
					soundSet = "WaterBottle_out_A_SoundSet";
					id = 205;
				};
				class WaterBottle_out_B
				{
					soundSet = "WaterBottle_out_B_SoundSet";
					id = 206;
				};
				class WellPond_loop
				{
					soundSet = "WellPond_loop_SoundSet";
					id = 209;
				};
				class WellBottle_loop
				{
					soundSet = "WellBottle_loop_SoundSet";
					id = 210;
				};
				class pickup
				{
					soundSet = "WaterBottle_pickup_SoundSet";
					id = 797;
				};
			};
		};
	};
};
