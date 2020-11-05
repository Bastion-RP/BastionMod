class CfgPatches
{
	class BastionDangerousZone_Data
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] =
		{
			"DZ_Data"
		};
	};
};

class CfgMods
{
	class BastionDangerousZone_Data
	{
		dir = "BastionDangerousZone_Data";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "BastionDangerousZone_Data";
		credits = "";
		author = "";
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
				files[] = {"BastionMod/BastionDangerousZone_Data/scripts/4_World"};
			};
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class BRP_Dosimeter: Inventory_Base
	{
		scope = 2;
		displayName = "Dosimeter";
		descriptionShort = "A radiation dosimeter is a device that measures dose uptake of external ionizing radiation. It is worn by the person being monitored when used as a personal dosimeter, and is a record of the radiation dose received.";
		model = "BastionMod\BastionDangerousZone_Data\dosimeter\geiger.p3d";
		rotationFlags = 2;
		weight = 500;
		absorbency = 0.0;
		itemSize[] = {3,2};
		attachments[]=
		{
			"BatteryD"
		};
		hiddenSelections[]=
		{
			"all"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionDangerousZone_Data\dosimeter\data\geiger_ca.paa"
		};
		batteryTexturePaths[]=
		{
			"BastionMod\BastionDangerousZone_Data\detectors\battery\battery1bars.paa",
			"BastionMod\BastionDangerousZone_Data\detectors\battery\battery2bars.paa",
			"BastionMod\BastionDangerousZone_Data\detectors\battery\battery3bars.paa",
			"BastionMod\BastionDangerousZone_Data\detectors\battery\battery4bars.paa"
		};
		class EnergyManager
		{
			hasIcon=1;
			autoSwitchOff=1;
			energyUsagePerSecond=0.01;
			plugType=1;
			attachmentAction=1;
			updateInterval=30;
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 60;
					healthLevels[] =
					{
						{1.0,{"BastionMod\BastionDangerousZone_Data\dosimeter\data\geiger.rvmat"}},
						{0.7,{"BastionMod\BastionDangerousZone_Data\dosimeter\data\geiger.rvmat"}},
						{0.5,{"BastionMod\BastionDangerousZone_Data\dosimeter\data\geiger_damage.rvmat"}},
						{0.3,{"BastionMod\BastionDangerousZone_Data\dosimeter\data\geiger_damage.rvmat"}},
						{0.0,{"BastionMod\BastionDangerousZone_Data\dosimeter\data\geiger_destruct.rvmat"}}
					};
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeLightBlunt";
				range = 1.0;
			};
			class Heavy
			{
				ammo = "MeleeLightBlunt_Heavy";
				range = 1.0;
			};
			class Sprint
			{
				ammo = "MeleeLightBlunt_Heavy";
				range = 2.8;
			};
		};
	};
	
	class BRP_Dosimeter_TBC3S : BRP_Dosimeter
	{
		scope = 2;
		displayName = "Dosimeter TBC-3S";
		itemSize[] = {2,3};
		model = "BastionMod\BastionDangerousZone_Data\dosimeter\sovietdosimeter.p3d";
		hiddenSelections[]=
		{
			"all"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionDangerousZone_Data\dosimeter\data\sovietdosimeter_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 60;
					healthLevels[] =
					{
						{1.0,{"BastionMod\BastionDangerousZone_Data\dosimeter\data\sovietdosimeter.rvmat"}},
						{0.7,{"BastionMod\BastionDangerousZone_Data\dosimeter\data\sovietdosimeter.rvmat"}},
						{0.5,{"BastionMod\BastionDangerousZone_Data\dosimeter\data\sovietdosimeter_damage.rvmat"}},
						{0.3,{"BastionMod\BastionDangerousZone_Data\dosimeter\data\sovietdosimeter_damage.rvmat"}},
						{0.0,{"BastionMod\BastionDangerousZone_Data\dosimeter\data\sovietdosimeter_destruct.rvmat"}}
					};
				};
			};
		};
	};	

	class BRP_Dosimeter_Opal : BRP_Dosimeter
	{
		scope = 2;
		displayName = "Dosimeter Opal";
		itemSize[] = {2,3};
		model = "BastionMod\BastionDangerousZone_Data\detectors\detector_opal.p3d";
		hiddenSelections[]=
		{
			"base",
			"screen",
			"dig0",
			"dig1",
			"dig2",
			"cmpDig0",
			"cmpDig1",
			"cmpDig2",
			"battery",
			"time0",
			"time1",
			"time2",
			"time3"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionDangerousZone_Data\detectors\data\detectors_co.paa",
			"BastionMod\BastionDangerousZone_Data\detectors\data\detectors_screen_co.paa"
		};
		digitTexturePaths[]=
		{
			"BastionMod\BastionDangerousZone_Data\detectors\tier2\0.paa",
			"BastionMod\BastionDangerousZone_Data\detectors\tier2\1.paa",
			"BastionMod\BastionDangerousZone_Data\detectors\tier2\2.paa",
			"BastionMod\BastionDangerousZone_Data\detectors\tier2\3.paa",
			"BastionMod\BastionDangerousZone_Data\detectors\tier2\4.paa",
			"BastionMod\BastionDangerousZone_Data\detectors\tier2\5.paa",
			"BastionMod\BastionDangerousZone_Data\detectors\tier2\6.paa",
			"BastionMod\BastionDangerousZone_Data\detectors\tier2\7.paa",
			"BastionMod\BastionDangerousZone_Data\detectors\tier2\8.paa",
			"BastionMod\BastionDangerousZone_Data\detectors\tier2\9.paa"
		};
		workScreenPath = "BastionMod\BastionDangerousZone_Data\detectors\tier2\screen_t2_co.paa";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 60;
					healthLevels[] =
					{
						{1.0,{"BastionMod\BastionDangerousZone_Data\detectors\data\detectors.rvmat"}},
						{0.7,{"BastionMod\BastionDangerousZone_Data\detectors\data\detectors.rvmat"}},
						{0.5,{"BastionMod\BastionDangerousZone_Data\detectors\data\detectors_damage.rvmat"}},
						{0.3,{"BastionMod\BastionDangerousZone_Data\detectors\data\detectors_damage.rvmat"}},
						{0.0,{"BastionMod\BastionDangerousZone_Data\detectors\data\detectors_destruct.rvmat"}}
					};
				};
			};
		};
	};
	class BRP_Dosimeter_Osa : BRP_Dosimeter
	{
		scope = 2;
		displayName = "Dosimeter Osa";
		model = "BastionMod\BastionDangerousZone_Data\detectors\detector_osa.p3d";

		hiddenSelections[]=
		{
			"base",
			"screen",
			"dig0",
			"dig1",
			"dig2",
			"cmpDig0",
			"cmpDig1",
			"cmpDig2",
			"battery",
			"time0",
			"time1",
			"time2",
			"time3"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionDangerousZone_Data\detectors\data\detectors_co.paa",
			"BastionMod\BastionDangerousZone_Data\detectors\data\detectors_screen_co.paa"
		};
		digitTexturePaths[]=
		{
			"BastionMod\BastionDangerousZone_Data\detectors\tier5\0.paa",
			"BastionMod\BastionDangerousZone_Data\detectors\tier5\1.paa",
			"BastionMod\BastionDangerousZone_Data\detectors\tier5\2.paa",
			"BastionMod\BastionDangerousZone_Data\detectors\tier5\3.paa",
			"BastionMod\BastionDangerousZone_Data\detectors\tier5\4.paa",
			"BastionMod\BastionDangerousZone_Data\detectors\tier5\5.paa",
			"BastionMod\BastionDangerousZone_Data\detectors\tier5\6.paa",
			"BastionMod\BastionDangerousZone_Data\detectors\tier5\7.paa",
			"BastionMod\BastionDangerousZone_Data\detectors\tier5\8.paa",
			"BastionMod\BastionDangerousZone_Data\detectors\tier5\9.paa"
		};
		workScreenPath = "BastionMod\BastionDangerousZone_Data\detectors\tier5\screen_t5_co.paa";
	};
	class BRP_Dosimeter_Sova : BRP_Dosimeter
	{
		scope = 2;
		displayName = "Dosimeter Sova";
		model = "BastionMod\BastionDangerousZone_Data\detectors\detector_sova.p3d";
	};
	class BRP_Dosimeter_Zov : BRP_Dosimeter
	{
		scope = 2;
		displayName = "Dosimeter Zov";
		model = "BastionMod\BastionDangerousZone_Data\detectors\detector_zov.p3d";

		hiddenSelections[]=
		{
			"base",
			"screen",
			"dig0",
			"dig1",
			"dig2",
			"cmpDig0",
			"cmpDig1",
			"cmpDig2",
			"battery",
			"time0",
			"time1",
			"time2",
			"time3"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionDangerousZone_Data\detectors\data\detectors_co.paa",
			"BastionMod\BastionDangerousZone_Data\detectors\data\detectors_screen_co.paa"
		};
		digitTexturePaths[]=
		{
			"BastionMod\BastionDangerousZone_Data\detectors\tier4\0.paa",
			"BastionMod\BastionDangerousZone_Data\detectors\tier4\1.paa",
			"BastionMod\BastionDangerousZone_Data\detectors\tier4\2.paa",
			"BastionMod\BastionDangerousZone_Data\detectors\tier4\3.paa",
			"BastionMod\BastionDangerousZone_Data\detectors\tier4\4.paa",
			"BastionMod\BastionDangerousZone_Data\detectors\tier4\5.paa",
			"BastionMod\BastionDangerousZone_Data\detectors\tier4\6.paa",
			"BastionMod\BastionDangerousZone_Data\detectors\tier4\7.paa",
			"BastionMod\BastionDangerousZone_Data\detectors\tier4\8.paa",
			"BastionMod\BastionDangerousZone_Data\detectors\tier4\9.paa"
		};
		workScreenPath = "BastionMod\BastionDangerousZone_Data\detectors\tier4\screen_t4_co.paa";
	};
	class Container_Base;
	class BRP_RadiationCase: Container_Base
	{
		scope = 2;
		displayName = "Radiation Case";
		descriptionShort = "A Case Found in the Radiation Zone";
		model = "BastionMod\BastionDangerousZone_Data\RadiationCase\RadiationCase.p3d";
		weight=10000;
		heavyItem=2;
		itemSize[]={50,50};
		carveNavmesh=1;
		rotationFlags=2;
		class Cargo
		{
			itemsCargoSize[]={10,30};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "smallprotectorcase_pickup_SoundSet";
					id = 797;
				};
			class drop
				{
					soundset = "smallprotectorcase_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class BRP_ShowerKit: Inventory_Base
	{
		scope=2;
		displayName="shower kit";
		descriptionShort="Shower Kit";
		model="BastionMod\BastionDangerousZone_Data\Box\ToxicBox.p3d";
		itemSize[]={5,10};
		carveNavmesh=1;
		canBeDigged=0;
		simulation="inventoryItem";
		physLayer="item_small";
		rotationFlags=2;
		weight=20000;
		itemBehaviour=2;
	};
	class BRP_DecontaminationShower: Inventory_Base
	{
		scope=2;
		displayName="Decontamination shower";
		descriptionShort="This Decontamination shower needs a gasoline tank full of water to work. Use it do decontaminate the clothe that you wear and reduce the radiation effect to the state 1";
		model="BastionMod\BastionDangerousZone_Data\Shower\ToxicShower.p3d";
		attachments[]=
		{
			"ShowerTank"
		};
		bounding="BSphere";
		overrideDrawArea="3.0";
		forceFarBubble="true";
		handheld="true";
		carveNavmesh=1;
		canBeDigged=0;
		weight=40000;
		itemSize[]={10,10};
		itemBehaviour=2;
		rotationFlags=2;
		hologramMaterial="BRP_DecontaminationShower";
		hologramMaterialPath="BastionMod\BastionDangerousZone_Data\Box\data";
		class EnergyManager
		{
			hasIcon=1;
			autoSwitchOff=1;
			energyAtSpawn=10;
			energyStorageMax=100;
			energyUsagePerSecond=1;
			updateInterval=30;
		};
	};
	class Edible_Base;
	class BRP_AntiRadPills: Edible_Base
	{
		scope=2;
		displayName="Radiation blocking tablets";
		descriptionShort="The tablets helps you to get rid of high radiation dose and offers some minor radiation protection too.";
		model="\dz\gear\medical\VitaminBottle.p3d";
		varQuantityInit=10;
		varQuantityMin=0;
		varQuantityMax=10;
		varQuantityDestroyOnMin=1;
		itemSize[]={1,2};
		weight=20;
		stackedUnit="pills";
		quantityBar=0;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionDangerousZone_Data\Treatment\BRP_TabletBottle_radiation_blockers.paa",
			"BastionMod\BastionDangerousZone_Data\Treatment\BRP_TabletBottle_radiation_blockers.paa",
			"BastionMod\BastionDangerousZone_Data\Treatment\BRP_TabletBottle_radiation_blockers.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{"DZ\gear\medical\data\vitamin_bottle.rvmat"}},{0.7,{"DZ\gear\medical\data\vitamin_bottle.rvmat"}},{0.5,{"DZ\gear\medical\data\vitamin_bottle_damage.rvmat"}},{0.3,{"DZ\gear\medical\data\vitamin_bottle_damage.rvmat"}},{0.0,{"DZ\gear\medical\data\vitamin_bottle_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class VitaminBottle_open
				{
					soundSet="VitaminBottle_open_SoundSet";
					id=201;
				};
				class VitaminBottle_shake
				{
					soundSet="VitaminBottle_shake_SoundSet";
					id=202;
				};
				class VitaminBottle_close
				{
					soundSet="VitaminBottle_close_SoundSet";
					id=203;
				};
				class pickUpItem
				{
					soundSet="vitaminbottle_pickup_SoundSet";
					id=797;
				};
			};
		};
	};
	class BRP_RadPillsTreament: Edible_Base
	{
		scope=2;
		displayName="Radiation treatment tablets";
		descriptionShort="The tablets helps you to recover after having being in contact with an high level of radiation.";
		model="\dz\gear\medical\painkillers2.p3d";
		varQuantityInit=5;
		varQuantityMin=0;
		varQuantityMax=5;
		varQuantityDestroyOnMin=1;
		itemSize[]={1,2};
		weight=20;
		stackedUnit="pills";
		quantityBar=0;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionDangerousZone_Data\Treatment\BRP_Tablets_anti_radiation.paa",
			"BastionMod\BastionDangerousZone_Data\Treatment\BRP_Tablets_anti_radiation.paa",
			"BastionMod\BastionDangerousZone_Data\Treatment\BRP_Tablets_anti_radiation.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 30;
					healthLevels[] = {{1.0,{"DZ\gear\medical\data\painkiller2.rvmat"}},{0.7,{"DZ\gear\medical\data\painkiller2.rvmat"}},{0.5,{"DZ\gear\medical\data\painkiller2_damage.rvmat"}},{0.3,{"DZ\gear\medical\data\painkiller2_damage.rvmat"}},{0.0,{"DZ\gear\medical\data\painkiller2_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class Tablets_open
				{
					soundSet="Tablets_open_SoundSet";
					id=201;
				};
				class Tablets_catch
				{
					soundSet="Tablets_catch_SoundSet";
					id=202;
				};
				class Tablets_close
				{
					soundSet="Tablets_close_SoundSet";
					id=203;
				};
				class pickup
				{
					soundSet="purificationtablets_pickup_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="purificationtablets_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	class Morphine;
	class BRP_InternalDosimeter: Morphine
	{
		scope = 2;
		displayName = "Internal Dosimeter";
		descriptionShort = "Tracks internal exposure to radiation. Measured in microsieverts. Developed by TharmaCorp.";
		model = "BastionMod\BastionDangerousZone_Data\dosimeter\injector.p3d";
		rotationFlags = 17;
		itemSize[] = {1,2};
		weight = 200;
		class EnergyManager
		{
			hasIcon=1;
			autoSwitchOff=1;
			energyUsagePerSecond=0.01;
			plugType=1;
			attachmentAction=1;
			updateInterval=30;
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{"BastionMod\BastionDangerousZone_Data\dosimeter\data\injector.rvmat"}},{0.7,{"BastionMod\BastionDangerousZone_Data\dosimeter\data\injector.rvmat"}},{0.5,{"BastionMod\BastionDangerousZone_Data\dosimeter\data\injector_damage.rvmat"}},{0.3,{"BastionMod\BastionDangerousZone_Data\dosimeter\data\injector_damage.rvmat"}},{0.0,{"BastionMod\BastionDangerousZone_Data\dosimeter\data\injector_destruct.rvmat"}}};
				};
			};
		};
	};	
};

class CfgSoundShaders
{
	class GeiGer_Tick_0_SoundShader
	{
		samples[]={{"BastionMod\BastionDangerousZone_Data\detectors\sounds\Geiger_Counter_0",1}};
		range=5;
		volume=15;
	};
	class GeiGer_Tick_1_SoundShader
	{
		samples[]={{"BastionMod\BastionDangerousZone_Data\detectors\sounds\Geiger_Counter_1",1}};
		range=5;
		volume=15;
	};
	class GeiGer_Tick_2_SoundShader
	{
		samples[]={{"BastionMod\BastionDangerousZone_Data\detectors\sounds\Geiger_Counter_2",1}};
		range=5;
		volume=15;
	};
	class GeiGer_Tick_3_SoundShader
	{
		samples[]={{"BastionMod\BastionDangerousZone_Data\detectors\sounds\Geiger_Counter_3",1}};
		range=5;
		volume=15;
	};
	class GeiGer_Tick_4_SoundShader
	{
		samples[]={{"BastionMod\BastionDangerousZone_Data\detectors\sounds\Geiger_Counter_4",1}};
		range=5;
		volume=15;
	};
	class GeiGer_Tick_5_SoundShader
	{
		samples[]={{"BastionMod\BastionDangerousZone_Data\detectors\sounds\Geiger_Counter_5",1}};
		range=5;
		volume=15;
	};
	class GeiGer_Tick_6_SoundShader
	{
		samples[]={{"BastionMod\BastionDangerousZone_Data\detectors\sounds\Geiger_Counter_6",1}};
		range=5;
		volume=15;
	};
	class GeiGer_Tick_7_SoundShader
	{
		samples[]={{"BastionMod\BastionDangerousZone_Data\detectors\sounds\Geiger_Counter_7",1}};
		range=5;
		volume=15;
	};
	class GeiGer_Tick_8_SoundShader
	{
		samples[]={{"BastionMod\BastionDangerousZone_Data\detectors\sounds\Geiger_Counter_8",1}};
		range=5;
		volume=15;
	};
	class GeiGer_Tick_9_SoundShader
	{
		samples[]={{"BastionMod\BastionDangerousZone_Data\detectors\sounds\Geiger_Counter_9",1}};
		range=5;
		volume=15;
	};

	class Radiation_MR_0_SoundShader
	{
		samples[]={{"BastionMod\BastionDangerousZone_Data\detectors\sounds\radLevelSound\dig_0",1}};
		range=5;
		volume=15;
	};
	class Radiation_MR_1_SoundShader
	{
		samples[]={{"BastionMod\BastionDangerousZone_Data\detectors\sounds\radLevelSound\dig_1",1}};
		range=5;
		volume=15;
	};
	class Radiation_MR_2_SoundShader
	{
		samples[]={{"BastionMod\BastionDangerousZone_Data\detectors\sounds\radLevelSound\dig_2",1}};
		range=5;
		volume=15;
	};
	class Radiation_MR_3_SoundShader
	{
		samples[]={{"BastionMod\BastionDangerousZone_Data\detectors\sounds\radLevelSound\dig_3",1}};
		range=5;
		volume=15;
	};
	class Radiation_MR_4_SoundShader
	{
		samples[]={{"BastionMod\BastionDangerousZone_Data\detectors\sounds\radLevelSound\dig_4",1}};
		range=5;
		volume=15;
	};
	class Radiation_MR_5_SoundShader
	{
		samples[]={{"BastionMod\BastionDangerousZone_Data\detectors\sounds\radLevelSound\dig_5",1}};
		range=5;
		volume=15;
	};
	class Radiation_MR_6_SoundShader
	{
		samples[]={{"BastionMod\BastionDangerousZone_Data\detectors\sounds\radLevelSound\dig_6",1}};
		range=5;
		volume=15;
	};
	class Radiation_MR_7_SoundShader
	{
		samples[]={{"BastionMod\BastionDangerousZone_Data\detectors\sounds\radLevelSound\dig_7",1}};
		range=5;
		volume=15;
	};
	class Radiation_MR_8_SoundShader
	{
		samples[]={{"BastionMod\BastionDangerousZone_Data\detectors\sounds\radLevelSound\dig_8",1}};
		range=5;
		volume=15;
	};
	class Radiation_MR_9_SoundShader
	{
		samples[]={{"BastionMod\BastionDangerousZone_Data\detectors\sounds\radLevelSound\dig_9",1}};
		range=5;
		volume=15;
	};
	class Radiation_INIT_PHRASE_SoundShader
	{
		samples[]={{"BastionMod\BastionDangerousZone_Data\detectors\sounds\radLevelSound\initPhrase",1}};
		range=5;
		volume=15;
	};
};
class CfgSoundSets
{
	class GeiGer_Tick_0_SoundSet {soundShaders[]={"GeiGer_Tick_0_SoundShader"};};
	class GeiGer_Tick_1_SoundSet {soundShaders[]={"GeiGer_Tick_1_SoundShader"};};
	class GeiGer_Tick_2_SoundSet {soundShaders[]={"GeiGer_Tick_2_SoundShader"};};
	class GeiGer_Tick_3_SoundSet {soundShaders[]={"GeiGer_Tick_3_SoundShader"};};
	class GeiGer_Tick_4_SoundSet {soundShaders[]={"GeiGer_Tick_4_SoundShader"};};
	class GeiGer_Tick_5_SoundSet {soundShaders[]={"GeiGer_Tick_5_SoundShader"};};
	class GeiGer_Tick_6_SoundSet {soundShaders[]={"GeiGer_Tick_6_SoundShader"};};
	class GeiGer_Tick_7_SoundSet {soundShaders[]={"GeiGer_Tick_7_SoundShader"};};
	class GeiGer_Tick_8_SoundSet {soundShaders[]={"GeiGer_Tick_8_SoundShader"};};
	class GeiGer_Tick_9_SoundSet {soundShaders[]={"GeiGer_Tick_9_SoundShader"};};

	class Radiation_MR_0_SoundSet {soundShaders[]={"Radiation_MR_0_SoundShader"};};
	class Radiation_MR_1_SoundSet {soundShaders[]={"Radiation_MR_1_SoundShader"};};
	class Radiation_MR_2_SoundSet {soundShaders[]={"Radiation_MR_2_SoundShader"};};
	class Radiation_MR_3_SoundSet {soundShaders[]={"Radiation_MR_3_SoundShader"};};
	class Radiation_MR_4_SoundSet {soundShaders[]={"Radiation_MR_4_SoundShader"};};
	class Radiation_MR_5_SoundSet {soundShaders[]={"Radiation_MR_5_SoundShader"};};
	class Radiation_MR_6_SoundSet {soundShaders[]={"Radiation_MR_6_SoundShader"};};
	class Radiation_MR_7_SoundSet {soundShaders[]={"Radiation_MR_7_SoundShader"};};
	class Radiation_MR_8_SoundSet {soundShaders[]={"Radiation_MR_8_SoundShader"};};
	class Radiation_MR_9_SoundSet {soundShaders[]={"Radiation_MR_9_SoundShader"};};
	class Radiation_INIT_SoundSet {soundShaders[]={"Radiation_INIT_PHRASE_SoundShader"};};
};