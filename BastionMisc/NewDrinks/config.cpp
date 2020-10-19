//Custom juice/cider in tandem with recipes
//Liquidvars are defined here for the script that it pulls from for full functionality
class CfgPatches
{
	class BRP_CiderDrinks
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_data\",
			"DZ_Gear_Optics",
			"DZ_Weapons_Melee",
			"DZ_Gear_Tools",
			"DZ_Gear_Crafting"
		};
	};
};
class cfgVehicles
{
	class Bottle_Base;
	class BRP_waterbottle_juice: Bottle_Base
	{
		scope=0;
		model="\dz\gear\drinks\WaterBottle.p3d";
		displayName="Fruit Juice";
		descriptionShort="A waterbottle filled with fruit juice";
		varLiquidTypeInit=778;
		weight=25;
		itemSize[]={1,3};
		destroyOnEmpty=0;
		varQuantityDestroyOnMin=0;
		liquidContainerType="1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256 + 333 + 334 + 512 + 1024 + 2048 + 4096 + 8192 + 16384 + 32768 + 65536  - (1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256)";
		varQuantityInit=1000;
		varQuantityMin=0;
		varQuantityMax=1000;
		isMeleeWeapon=1;
		hiddenSelections[]=
		{
			"zbytek",
			"zbytek",
			"zbytek"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=50;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\drinks\data\\Loot_WaterBottle.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\drinks\data\\Loot_WaterBottle.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\drinks\data\\Loot_WaterBottle_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\drinks\data\\Loot_WaterBottle_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\drinks\data\\Loot_WaterBottle_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class WaterBottle_in_B
				{
					soundSet="WaterBottle_in_B_SoundSet";
					id=202;
				};
				class WaterBottle_in_C
				{
					soundSet="WaterBottle_in_C_SoundSet";
					id=203;
				};
				class WaterBottle_in_C1
				{
					soundSet="WaterBottle_in_C1_SoundSet";
					id=204;
				};
				class WaterBottle_out_A
				{
					soundSet="WaterBottle_out_A_SoundSet";
					id=205;
				};
				class WaterBottle_out_B
				{
					soundSet="WaterBottle_out_B_SoundSet";
					id=206;
				};
				class WellPond_loop
				{
					soundSet="WellPond_loop_SoundSet";
					id=209;
				};
				class WellBottle_loop
				{
					soundSet="WellBottle_loop_SoundSet";
					id=210;
				};
				class pickup
				{
					soundSet="WaterBottle_pickup_SoundSet";
					id=797;
				};
			};
		};
	};
	class BRP_waterbottle_sweetjuice: BRP_waterbottle_juice
	{
		scope=0;
		displayName="Sweetened Fruit Juice";
		descriptionShort="A waterbottle filled with fruit juice. It's been sweetened with sugar";
		varLiquidTypeInit=779;
	};
	class BRP_waterbottle_cider: BRP_waterbottle_juice
	{
		scope=0;
		displayName="Fruit Cider";
		descriptionShort="Don't let appearances fool you. Sweet and simple homemade cider.";
		varLiquidTypeInit=780;
	};
	class BRP_waterbottle_apple: BRP_waterbottle_juice
	{
		scope=2;
		displayName="Apple Fruit Juice";
		//descriptionShort="A waterbottle filled with apple fruit juice";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_apple.paa",
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_apple.paa",
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_apple.paa"
		};
	};
	class BRP_waterbottle_banana: BRP_waterbottle_juice
	{
		scope=2;
		displayName="Banana Fruit Juice";
		//descriptionShort="A waterbottle filled with banana fruit juice";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_banana.paa",
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_banana.paa",
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_banana.paa"
		};
	};
	class BRP_waterbottle_elderberry: BRP_waterbottle_juice
	{
		scope=2;
		displayName="Elderberry Fruit Juice";
		//descriptionShort="A waterbottle filled with elderberry fruit juice";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_elderberry.paa",
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_elderberry.paa",
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_elderberry.paa"
		};
	};
	class BRP_waterbottle_kiwi: BRP_waterbottle_juice
	{
		scope=2;
		displayName="Kiwi Fruit Juice";
		//descriptionShort="A waterbottle filled with kiwi fruit juice";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_kiwi.paa",
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_kiwi.paa",
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_kiwi.paa"
		};
	};
	class BRP_waterbottle_orange: BRP_waterbottle_juice
	{
		scope=2;
		displayName="Orange Fruit Juice";
		//descriptionShort="A waterbottle filled with orange fruit juice";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_orange.paa",
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_orange.paa",
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_orange.paa"
		};
	};
	class BRP_waterbottle_pear: BRP_waterbottle_juice
	{
		scope=2;
		displayName="Pear Fruit Juice";
		//descriptionShort="A waterbottle filled with pear fruit juice";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_pear.paa",
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_pear.paa",
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_pear.paa"
		};
	};
	class BRP_waterbottle_plum: BRP_waterbottle_juice
	{
		scope=2;
		displayName="Plum Fruit Juice";
		//descriptionShort="A waterbottle filled with plum fruit juice";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_plum.paa",
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_plum.paa",
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_plum.paa"
		};
	};
	class BRP_waterbottle_rosehip: BRP_waterbottle_juice
	{
		scope=2;
		displayName="Rosehip Fruit Juice";
		//descriptionShort="A waterbottle filled with rosehip fruit juice";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_rosehip.paa",
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_rosehip.paa",
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_rosehip.paa"
		};
	};
	class BRP_waterbottle_sweetapple: BRP_waterbottle_sweetjuice
	{
		scope=2;
		displayName="Sweetened Apple Fruit Juice";
		//descriptionShort="A waterbottle filled with apple fruit juice. It's been sweetened with sugar";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_apple.paa",
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_apple.paa",
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_apple.paa"
		};
	};
	class BRP_waterbottle_sweetbanana: BRP_waterbottle_sweetjuice
	{
		scope=2;
		displayName="Sweetened Banana Fruit Juice";
		//descriptionShort="A waterbottle filled with banana fruit juice. It's been sweetened with sugar";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_banana.paa",
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_banana.paa",
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_banana.paa"
		};
	};
	class BRP_waterbottle_sweetelderberry: BRP_waterbottle_sweetjuice
	{
		scope=2;
		displayName="Sweetened Elderberry Fruit Juice";
		//descriptionShort="A waterbottle filled with elderberry fruit juice. It's been sweetened with sugar";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_elderberry.paa",
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_elderberry.paa",
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_elderberry.paa"
		};
	};
	class BRP_waterbottle_sweetkiwi: BRP_waterbottle_sweetjuice
	{
		scope=2;
		displayName="Sweetened Kiwi Fruit Juice";
		//descriptionShort="A waterbottle filled with kiwi fruit juice. It's been sweetened with sugar";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_kiwi.paa",
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_kiwi.paa",
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_kiwi.paa"
		};
	};
	class BRP_waterbottle_sweetorange: BRP_waterbottle_sweetjuice
	{
		scope=2;
		displayName="Sweetened Orange Fruit Juice";
		//descriptionShort="A waterbottle filled with orange fruit juice. It's been sweetened with sugar";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_orange.paa",
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_orange.paa",
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_orange.paa"
		};
	};
	class BRP_waterbottle_sweetpear: BRP_waterbottle_sweetjuice
	{
		scope=2;
		displayName="Sweetened Pear Fruit Juice";
		//descriptionShort="A waterbottle filled with pear fruit juice. It's been sweetened with sugar";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_pear.paa",
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_pear.paa",
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_pear.paa"
		};
	};
	class BRP_waterbottle_sweetplum: BRP_waterbottle_sweetjuice
	{
		scope=2;
		displayName="Sweetened Plum Fruit Juice";
		//descriptionShort="A waterbottle filled with plum fruit juice. It's been sweetened with sugar";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_plum.paa",
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_plum.paa",
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_plum.paa"
		};
	};
	class BRP_waterbottle_sweetrosehip: BRP_waterbottle_sweetjuice
	{
		scope=2;
		displayName="Sweetened Rosehip Fruit Juice";
		//descriptionShort="A waterbottle filled with rosehip fruit juice. It's been sweetened with sugar";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_rosehip.paa",
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_rosehip.paa",
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_rosehip.paa"
		};
	};
	class BRP_waterbottle_applecider: BRP_waterbottle_cider
	{
		scope=2;
		displayName="Apple Fruit Cider";
		//descriptionShort="A waterbottle filled with apple fruit cider";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_apple.paa",
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_apple.paa",
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_apple.paa"
		};
	};
	class BRP_waterbottle_bananacider: BRP_waterbottle_cider
	{
		scope=2;
		displayName="Banana Fruit Cider";
		//descriptionShort="A waterbottle filled with banana fruit cider";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_banana.paa",
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_banana.paa",
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_banana.paa"
		};
	};
	class BRP_waterbottle_elderberrycider: BRP_waterbottle_cider
	{
		scope=2;
		displayName="Elderberry Fruit Cider";
		//descriptionShort="A waterbottle filled with elderberry fruit cider";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_elderberry.paa",
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_elderberry.paa",
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_elderberry.paa"
		};
	};
	class BRP_waterbottle_kiwicider: BRP_waterbottle_cider
	{
		scope=2;
		displayName="Kiwi Fruit Cider";
		//descriptionShort="A waterbottle filled with kiwi fruit cider";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_kiwi.paa",
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_kiwi.paa",
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_kiwi.paa"
		};
	};
	class BRP_waterbottle_orangecider: BRP_waterbottle_cider
	{
		scope=2;
		displayName="Orange Fruit Cider";
		//descriptionShort="A waterbottle filled with orange fruit cider";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_orange.paa",
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_orange.paa",
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_orange.paa"
		};
	};
	class BRP_waterbottle_pearcider: BRP_waterbottle_cider
	{
		scope=2;
		displayName="Pear Fruit Cider";
		//descriptionShort="A waterbottle filled with pear fruit cider";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_pear.paa",
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_pear.paa",
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_pear.paa"
		};
	};
	class BRP_waterbottle_plumcider: BRP_waterbottle_cider
	{
		scope=2;
		displayName="Plum Fruit Cider";
		//descriptionShort="A waterbottle filled with plum fruit cider";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_plum.paa",
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_plum.paa",
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_plum.paa"
		};
	};
	class BRP_waterbottle_rosehipcider: BRP_waterbottle_cider
	{
		scope=2;
		displayName="Rosehip Fruit Cider";
		//descriptionShort="A waterbottle filled with rosehip fruit cider";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_rosehip.paa",
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_rosehip.paa",
			"BastionMod\BastionMisc\NewDrinks\data\coda_waterbottle_rosehip.paa"
		};
	};
};
class cfgLiquidDefinitions
{
	class Beer//Does not work for whatever reason. Attempted to add agent=512 to beers to no avail
	{
		class Nutrition
		{
			fullnessIndex=1;
			energy=43;
			water=100;
			nutritionalIndex=75;
			toxicity=0.0099999998;
			digestibility=2;
			agents=512;
		};
	};
	class FruitJuice
	{
		type=778;
		displayName="Fruit Juice";
		flammability=-10;
		class Nutrition
		{
			fullnessIndex=1;
			energy=25;
			water=100;
			nutritionalIndex=75;
			toxicity=-0;
			digestibility=2;
		};
	};
	class SweetFruitJuice
	{
		type=779;
		displayName="Sweetened Fruit Juice";
		flammability=-10;
		class Nutrition
		{
			fullnessIndex=1;
			energy=50;
			water=100;
			nutritionalIndex=75;
			toxicity=-0;
			digestibility=2;
		};
	};
	class Cider
	{
		type=780;
		displayName="Moonshine";
		flammability=-10;
		class Nutrition
		{
			fullnessIndex=1;
			energy=20;
			water=100;
			nutritionalIndex=75;
			toxicity=-0;
			digestibility=2;
		};
	};
	class Spirits
	{
		type=781;
		displayName="Spirits";
		flammability=-10;
		class Nutrition
		{
			fullnessIndex=1;
			energy=10;
			water=100;
			nutritionalIndex=75;
			toxicity=-0;
			digestibility=2;
		};
	};
};