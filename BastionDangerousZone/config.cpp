class CfgPatches
{
	class BastionDangerousZone_Script
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Gear_Medical",
			"DZ_Characters_Headgear",
			"DZ_vehicles_parts"
		};
	};
};
class CfgMods
{
	class BastionDangerousZone
	{
		dir="BastionDangerousZone";
		picture="";
		action="";
		hideName=1;
		hidePicture=1;
		name="DangerousZone";
		credits="TheDmitri";
		author="TheDmitri";
		authorID="0";
		version="1.1";
		extra=0;
		type="mod";
		dependencies[]=
		{
			"Game",
			"World",
			"Mission"
		};
		class defs
		{
			class gameScriptModule
			{
				value="";
				files[]=
				{
					"BastionMod/BastionDangerousZone/scripts/Common","BastionMod/BastionDangerousZone/scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"BastionMod/BastionDangerousZone/scripts/Common","BastionMod/BastionDangerousZone/scripts/4_World"
				};
			};
			class missionScriptModule
			{
				value="";
				files[]=
				{
					"BastionMod/BastionDangerousZone/scripts/Common","BastionMod/BastionDangerousZone/scripts/5_Mission"
				};
			};
		};
	};
};
class CfgSlots
{
	class Slot_ShowerTank
	{
		name="ShowerTank";
		displayName="ShowerTank";
		ghostIcon="";
		show="false";
	};
};
class CfgVehicles
{
	class Bottle_Base;
	class CanisterGasoline: Bottle_Base
	{
		inventorySlot[]=
		{
			"ShowerTank"
		};
	};
	class Inventory_Base;
	class GP5GasMask_Filter: Inventory_Base
	{
		scope=2;
		displayName="GP5GasMask Filter";
		descriptionShort="Mask filter that can be attach to a GP5GasMask. A full filter provide 45 min of use";
		model="\DZ\characters\masks\GP5GasMask_filter.p3d";
		inventorySlot[]=
		{
			"GasMaskFilter"
		};
		rotationFlags=2;
		weight=5;
		itemSize[]={2,2};
		absorbency=0;
		heatIsolation=0.60000002;
		visibilityModifier=0.94999999;
		quantityBar=1;
		varQuantityInit=45;
		varQuantityMin=0;
		varQuantityMax=45;
		hiddenSelections[]=
		{
			"camoGround"
		};
		hiddenSelectionsTextures[]=
		{
			"\dz\characters\masks\data\GP5GasMask_white_co.paa"
		};
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
								"DZ\characters\masks\data\GP5GasMask.rvmat"
							}
						},

						{
							0.69999999,

							{
								"DZ\characters\masks\data\GP5GasMask.rvmat"
							}
						},

						{
							0.5,

							{
								"DZ\characters\masks\data\GP5GasMask_damage.rvmat"
							}
						},

						{
							0.30000001,

							{
								"DZ\characters\masks\data\GP5GasMask_damage.rvmat"
							}
						},

						{
							0,

							{
								"DZ\characters\masks\data\GP5GasMask_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class Clothing;
	class GP5GasMask: Clothing
	{
		scope=2;
		displayName="$STR_CfgVehicles_GP5GasMask0";
		descriptionShort="A GasMask green to protect from radiation and Dangerous gas. Attach a filter to make it work. It provide 45 min of use.";
		model="\DZ\characters\masks\GP5GasMask_g.p3d";
		itemInfo[]=
		{
			"Clothing",
			"Mask"
		};
		rotationFlags=1;
		weight=1090;
		itemSize[]={3,3};
		absorbency=0;
		heatIsolation=0.60000002;
		visibilityModifier=0.94999999;
		noHelmet=0;
		attachments[]=
		{
			"GasMaskFilter"
		};
		class EnergyManager
		{
			autoSwitchOff=0;
			energyAtSpawn=10;
			energyStorageMax=100;
			energyUsagePerSecond=1;
			updateInterval=60;
		};
		headSelectionsToHide[]=
		{
			"Clipping_GP5GasMask"
		};
		hiddenSelections[]=
		{
			"camoGround",
			"camoMale",
			"camoFemale"
		};
		hiddenSelectionsTextures[]=
		{
			"\dz\characters\masks\data\GP5GasMask_white_co.paa",
			"\dz\characters\masks\data\GP5GasMask_white_co.paa",
			"\dz\characters\masks\data\GP5GasMask_white_co.paa"
		};
		class ClothingTypes
		{
			male="\DZ\characters\masks\GP5GasMask_m.p3d";
			female="\DZ\characters\masks\GP5GasMask_f.p3d";
		};
		class Protection
		{
			biological=1;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet="DarkMotoHelmet_pickup_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="DarkMotoHelmet_drop_SoundSet";
					id=898;
				};
			};
		};
		soundVoiceType="gasmask";
		soundVoicePriority=5;
	};
	class DecontaminationSpray: Inventory_Base
	{
		scope=2;
		displayName="DecontaminationSpray";
		descriptionShort="Use the spray on clothes or weapons to remove radiation";
		model="\dz\gear\medical\DisinfectantSpray.p3d";
		quantityBar=1;
		weight=50;
		stackedUnit="ml";
		itemSize[]={1,3};
		varLiquidTypeInit=32768;
		varQuantityInit=500;
		varQuantityMin=0;
		varQuantityMax=500;
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
								"DZ\gear\medical\data\Loot_DisinfectantSpray.rvmat"
							}
						},

						{
							0.69999999,

							{
								"DZ\gear\medical\data\Loot_DisinfectantSpray.rvmat"
							}
						},

						{
							0.5,

							{
								"DZ\gear\medical\data\Loot_DisinfectantSpray_damage.rvmat"
							}
						},

						{
							0.30000001,

							{
								"DZ\gear\medical\data\Loot_DisinfectantSpray_damage.rvmat"
							}
						},

						{
							0,

							{
								"DZ\gear\medical\data\Loot_DisinfectantSpray_destruct.rvmat"
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
				class disinfectant_loop
				{
					soundSet="disinfectant_loop_SoundSet";
					id=212;
				};
				class disinfectant_loop2
				{
					soundSet="disinfectant_loop_SoundSet";
					id=213;
				};
				class pickUpItem
				{
					soundSet="pickUpWatterBottle_SoundSet";
					id=797;
				};
			};
		};
	};
	class ShowerKit: Inventory_Base
	{
		scope=2;
		displayName="shower kit";
		descriptionShort="Shower Kit";
		model="BastionMod\BastionDangerousZone\data\Box\ToxicBox.p3d";
		itemSize[]={5,5};
		carveNavmesh=1;
		canBeDigged=0;
		simulation="inventoryItem";
		physLayer="item_small";
		rotationFlags=2;
		weight=5000;
		itemBehaviour=2;
	};
	class DecontaminationShower: Inventory_Base
	{
		scope=2;
		displayName="Decontamination shower";
		descriptionShort="This Decontamination shower needs a gasoline tank full of water to work. Use it do decontaminate the clothe that you wear and reduce the radiation effect to the state 1";
		model="BastionMod\BastionDangerousZone\data\Shower\ToxicShower.p3d";
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
		hologramMaterial="DecontaminationShower";
		hologramMaterialPath="BastionMod\BastionDangerousZone\data\Box\data";
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
	class PillsBottle: Edible_Base
	{
		scope=2;
		model="\dz\gear\medical\VitaminBottle.p3d";
		varQuantityInit=5;
		varQuantityMin=0;
		varQuantityMax=10;
		varQuantityDestroyOnMin=1;
		itemSize[]={1,2};
		weight=20;
		stackedUnit="pills";
		quantityBar=0;
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
								"DZ\gear\medical\data\vitamin_bottle.rvmat"
							}
						},

						{
							0.69999999,

							{
								"DZ\gear\medical\data\vitamin_bottle.rvmat"
							}
						},

						{
							0.5,

							{
								"DZ\gear\medical\data\vitamin_bottle_damage.rvmat"
							}
						},

						{
							0.30000001,

							{
								"DZ\gear\medical\data\vitamin_bottle_damage.rvmat"
							}
						},

						{
							0,

							{
								"DZ\gear\medical\data\vitamin_bottle_destruct.rvmat"
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
	class dz_AntiRadPills: PillsBottle
	{
		scope=2;
		displayName="Radiation blocking tablets";
		descriptionShort="The tablets helps you to get rid received radiation dose and offers some minor radiation protection too.";
		model="\dz\gear\medical\VitaminBottle.p3d";
		varQuantityInit=20;
		varQuantityMin=0;
		varQuantityMax=20;
		hiddenSelections[]=
		{
			"zbytek"
		};
	};
	class dz_RadPillsTreament: PillsBottle
	{
		scope=2;
		displayName="Radiation treatment tablets";
		descriptionShort="The tablets helps you to recover after having being in contact with an high level of radiation.";
		model="\dz\gear\medical\VitaminBottle.p3d";
		varQuantityInit=5;
		varQuantityMin=0;
		varQuantityMax=5;
		hiddenSelections[]=
		{
			"zbytek"
		};
	};
	class HouseNoDestruct;
	class GreenSpore: HouseNoDestruct
	{
		scope=2;
		displayName="Spore";
		forceFarBubble="true";
		carveNavmesh=1;
		rotationFlags=2;
		itemSize[]={1,1};
		weight=1000000;
	};
	class WeirdGreenSpore: HouseNoDestruct
	{
		scope=2;
		displayName="Spore";
		forceFarBubble="true";
		carveNavmesh=1;
		rotationFlags=2;
		itemSize[]={1,1};
		weight=1000000;
	};
	class WeirdGreenSpore2: HouseNoDestruct
	{
		scope=2;
		displayName="Spore";
		forceFarBubble="true";
		carveNavmesh=1;
		rotationFlags=2;
		itemSize[]={1,1};
		weight=1000000;
	};
	class BlueSpore: HouseNoDestruct
	{
		scope=2;
		displayName="Spore";
		forceFarBubble="true";
		carveNavmesh=1;
		rotationFlags=2;
		itemSize[]={1,1};
		weight=1000000;
	};
	class RedSpore: HouseNoDestruct
	{
		scope=2;
		displayName="Spore";
		forceFarBubble="true";
		carveNavmesh=1;
		rotationFlags=2;
		itemSize[]={1,1};
		weight=1000000;
	};
	class PurpleSpore: HouseNoDestruct
	{
		scope=2;
		displayName="Spore";
		forceFarBubble="true";
		carveNavmesh=1;
		rotationFlags=2;
		itemSize[]={1,1};
		weight=1000000;
	};
	class WhiteSpore: HouseNoDestruct
	{
		scope=2;
		displayName="Spore";
		forceFarBubble="true";
		carveNavmesh=1;
		rotationFlags=2;
		itemSize[]={1,1};
		weight=1000000;
	};
};
class CfgSoundShaders
{
	class dz_Geiger_Intermediate_SoundShader
	{
		samples[]=
		{

			{
				"BastionMod\BastionDangerousZone\data\Sounds\Geiger_Counter_Sound_Intermediate",
				1
			}
		};
		range=15;
		volume=1.2;
	};
	class dz_Geiger_Low_SoundShader
	{
		samples[]=
		{

			{
				"BastionMod\BastionDangerousZone\data\Sounds\Geiger_Counter_Sound_Low",
				1
			}
		};
		range=15;
		volume=1.2;
	};
	class dz_Geiger_High_SoundShader
	{
		samples[]=
		{

			{
				"BastionMod\BastionDangerousZone\data\Sounds\Geiger_Counter_Sound_VeryHigh",
				1
			}
		};
		range=15;
		volume=1.2;
	};
	class dz_Geiger_VeryIntermediate_SoundShader
	{
		samples[]=
		{

			{
				"BastionMod\BastionDangerousZone\data\Sounds\Geiger_Counter_Sound_VeryIntermediate",
				1
			}
		};
		range=15;
		volume=1.2;
	};
	class dz_Geiger_VeryLow_SoundShader
	{
		samples[]=
		{

			{
				"BastionMod\BastionDangerousZone\data\Sounds\Geiger_Counter_Sound_VeryLow",
				1
			}
		};
		range=15;
		volume=1.2;
	};
	class dz_Geiger_VeryHigh_SoundShader
	{
		samples[]=
		{

			{
				"BastionMod\BastionDangerousZone\data\Sounds\Geiger_Counter_Sound_VeryHigh",
				1
			}
		};
		range=15;
		volume=1.2;
	};
	class dz_Geiger_SoundShader_Switch
	{
		samples[]=
		{
			{
				"BastionMod\BastionDangerousZone\data\Sounds\Geiger_Counter_Sound_Switch",
				1
			}
		};
		range=5;
		volume=0.5;
	};
	class dz_Shower_SoundShader
	{
		samples[]=
		{
			{
				"BastionMod\BastionDangerousZone\data\Sounds\Shower",
				1
			}
		};
		range=15;
		volume=1.2;
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class Proxyjerrycan: ProxyAttachment
	{
		scope=2;
		inventorySlot[]=
		{
			"ShowerTank"
		};
		model="\DZ\vehicles\parts\jerrycan.p3d";
	};
};
class CfgSoundSets
{
	class dz_Geiger_Intermediate_SoundSet
	{
		soundShaders[]=
		{
			"dz_Geiger_Intermediate_SoundShader"
		};
	};
	class dz_Geiger_Low_SoundSet
	{
		soundShaders[]=
		{
			"dz_Geiger_Low_SoundShader"
		};
	};
	class dz_Geiger_High_SoundSet
	{
		soundShaders[]=
		{
			"dz_Geiger_High_SoundShader"
		};
	};
	class dz_Geiger_VeryIntermediate_SoundSet
	{
		soundShaders[]=
		{
			"dz_Geiger_VeryIntermediate_SoundShader"
		};
	};
	class dz_Geiger_VeryLow_SoundSet
	{
		soundShaders[]=
		{
			"dz_Geiger_VeryLow_SoundShader"
		};
	};
	class dz_Geiger_VeryHigh_SoundSet
	{
		soundShaders[]=
		{
			"dz_Geiger_VeryHigh_SoundShader"
		};
	};
	class dz_Geiger_SoundSet_Switch
	{
		soundShaders[]=
		{
			"dz_Geiger_SoundShader_Switch"
		};
	};
	class dz_Shower_SoundSet
	{
		soundShaders[]=
		{
			"dz_Shower_SoundShader"
		};
	};
};
