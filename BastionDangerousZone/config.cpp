class CfgPatches
{
	class BastionDangerousZone_Script
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Gear_Medical",
			"DZ_Characters_Headgear",
			"DZ_Data"
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
		version="1.0";
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
class CfgVehicles
{
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
		weight=200;
		itemSize[]={2,2};
		absorbency=0;
		heatIsolation=0.60000002;
		visibilityModifier=0.94999999;
		quantityBar=1;
		varQuantityInit=2700;
		varQuantityMin=0;
		varQuantityMax=2700;
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
			energyAtSpawn=15;
			energyStorageMax=100;
			energyUsagePerSecond=1;
			updateInterval=59;
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
	class dz_Geiger_SoundShader
	{
		samples[]=
		{
			
			{
				"BastionMod\BastionDangerousZone\data\Sounds\Geiger_Counter_Sound",
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
				"BastionMod\DangerousZone\data\Sounds\Geiger_Counter_Sound_Switch",
				1
			}
		};
		range=5;
		volume=0.5;
	};
};
class CfgSoundSets
{
	class dz_Geiger_SoundSet
	{
		soundShaders[]=
		{
			"dz_Geiger_SoundShader"
		};
	};
	class dz_Geiger_SoundSet_Switch
	{
		soundShaders[]=
		{
			"dz_Geiger_SoundShader_Switch"
		};
	};
};
