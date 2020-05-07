class CfgPatches
{
	class BRP_AION
	{
		units[] = {"BRP_AION"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};

class cfgLiquidDefinitions
{
	class AION
	{
		type=131072;
		displayName="AION";
		class Nutrition
		{
			fullnessIndex=1.75;
			energy=1500;
			water=500;
			nutritionalIndex=1;
			toxicity=0;
			digestibility=2;
		};
	};
};
class CfgVehicles
{
	class Bottle_Base;
	class BRP_AION: Bottle_Base
	{
		scope=2;
		displayName="AION";
		descriptionShort="Aion | All-In-One NutritionAion. Developed by the NATO-CSTO Coalition.  Is an affordable, sustainable, all-in-one solution to the food crisis that we face every day. In order to regrow a population in a world wracked with disaster, it is imperative that our citizens have access to nutrition that is easy to consume and easy to sustain, so no one in any Bastion goes hungry.Each serving contains 25% daily value of protein and fats, slow-burning carbohydrates, and 28 essential vitamins and minerals that are then mixed with purified water and bottled to ensure that every citizen remains happy and, most importantly, healthy.";
		model="BastionMod\BastionVendor_Data\AION\aion.p3d";
		weight=25;
		itemSize[]={1,3};
		stackedRandom=0;
		stackedUnit="";
		varLiquidTypeInit=131072;
		//destroyOnEmpty=0;
		//varQuantityDestroyOnMin=0;
		varQuantityInit=500;
		varQuantityMin=0;
		varQuantityMax=500;
		liquidContainerType="131072";
		isMeleeWeapon=1;
		hiddenSelections[] = 
		{
			"cap",
			"body"
		};
		hiddenSelectionsTextures[] = 
		{
			"BastionMod\BastionVendor_Data\aion\data\cap_co.paa",			
			"BastionMod\BastionVendor_Data\aion\data\label_co.paa"
		};
		hiddenSelectionsMaterials[] = 
		{
			"BastionMod\BastionVendor_Data\aion\data\aion.rvmat",			
			"BastionMod\BastionVendor_Data\aion\data\aion.rvmat"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = 
					{
						{
							1.0,
							{"BastionMod\BastionVendor_Data\AION\data\aion.rvmat","BastionMod\BastionVendor_Data\AION\data\aion.rvmat"}
						},
						{
							0.7,
							{"BastionMod\BastionVendor_Data\AION\data\aion.rvmat","BastionMod\BastionVendor_Data\AION\data\aion.rvmat"}
						},
						{
							0.5,
							{"BastionMod\BastionVendor_Data\AION\data\aion_damage.rvmat","BastionMod\BastionVendor_Data\AION\data\aion_damage.rvmat"}
						},
						{
							0.3,
							{"BastionMod\BastionVendor_Data\AION\data\aion_damage.rvmat","BastionMod\BastionVendor_Data\AION\data\aion_damage.rvmat"}
						},
						{
							0.0,
							{"BastionMod\BastionVendor_Data\AION\data\aion_destruct.rvmat","BastionMod\BastionVendor_Data\AION\data\aion_destruct.rvmat"}
						}
					};
				};
			};
		};
		class Nutrition
		{
			totalVolume=1;
			fullnessIndex=1.75;
			energy=1500;
			water=500;
			nutritionalIndex=1;
			toxicity=0;
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
