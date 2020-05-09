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
	class BRP_AION_Empty: BRP_AION
	{
		displayName="AION Bottle";
		descriptionShort="Fill this with water then mix in AION Powder to make AION.";		
		varQuantityInit=0;
		varLiquidTypeInit=512;
		destroyOnEmpty=0;		
		liquidContainerType="512";
	};

	class PowderedMilk;
	class BRP_AIONPowder: PowderedMilk
	{
		scope=2;
		displayName="AION Powder";
		descriptionShort="AION Powder used to make AION. Mix this with AION Bottle with water inside. Do not eat the powder.";
		absorbency=0.89999998;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\food\data\powdered_milk.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\food\data\powdered_milk.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\food\data\powdered_milk_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\food\data\powdered_milk_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\food\data\powdered_milk_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class Nutrition
		{
			fullnessIndex=2.5;
			energy=196;
			water=-200;
			nutritionalIndex=1;
			toxicity=1;
			agents=16;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet="openTunaCan_SoundSet";
					id=204;
				};
				class pickUpItem
				{
					soundSet="pickUpBloodBag_SoundSet";
					id=797;
				};
				class Eating_TakeFood
				{
					soundSet="Eating_TakeFood_Soundset";
					id=889;
				};
				class Eating_BoxOpen
				{
					soundSet="Eating_BoxOpen_Soundset";
					id=893;
				};
				class Eating_BoxShake
				{
					soundSet="Eating_BoxShake_Soundset";
					id=894;
				};
				class Eating_BoxEnd
				{
					soundSet="Eating_BoxEnd_Soundset";
					id=895;
				};
				class drop
				{
					soundset="bloodbag_drop_SoundSet";
					id=898;
				};
			};
		};
	};
};
