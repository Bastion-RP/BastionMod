class CfgPatches
{
	class StunGrenade_Script
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data"
		};
	};
};
class CfgMods
{
	class StunGrenade
	{
		dir="StunGrenade";
		picture="";
		action="";
		hideName=1;
		hidePicture=1;
		name="StunGrenade";
		credits="TheDmitri";
		author="TheDmitri";
		authorID="0";
		version="1.1";
		extra=0;
		type="mod";
		dependencies[]=
		{
			"Game",
			"World"
		};
		class defs
		{
			class gameScriptModule
			{
				value="";
				files[]=
				{
					"BastionMod/BastionMisc/StunGrenade/scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"BastionMod/BastionMisc/StunGrenade/scripts/4_World"
				};
			};
			class missionScriptModule
			{
				value="";
				files[]=
				{
					"BastionMod/BastionMisc/StunGrenade/scripts/5_Mission"
				};
			};
		};
	};
};
class CfgVehicles
{
	class Grenade_Base;
	class StunM18SmokeGrenade_ColorBase: Grenade_Base
	{
		displayName="$STR_CfgVehicles_M18SmokeGrenade_ColorBase0";
		descriptionShort="$STR_CfgVehicles_M18SmokeGrenade_ColorBase1";
		model="\dz\weapons\explosives\smokegrenade.p3d";
		rotationFlags=17;
		lootTag[]=
		{
			"Military_west"
		};
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\weapons\explosives\data\smokegrenade.rvmat"
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
								"DZ\weapons\explosives\data\smokegrenade.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\weapons\explosives\data\smokegrenade.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\weapons\explosives\data\smokegrenade_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\weapons\explosives\data\smokegrenade_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\weapons\explosives\data\smokegrenade_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class EnergyManager
		{
			energyAtSpawn=60;
			energyUsagePerSecond=1;
			wetnessExposure=0.1;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class Unpin
				{
					soundSet="SmokegGrenades_M18_oneshot_ignite_SoundSet";
					id=201;
				};
			};
		};
	};
	class BRP_Kolokol2: StunM18SmokeGrenade_ColorBase
	{
		scope=2;
		displayName="K2";
		model = "BastionMod\BastionMisc_Data\TearGasGrenade\gasgrenade.p3d";
		descriptionShort="Experimental gas grenade. It might say CS gas on the front, but CS gas doesn't knock people unconscious...";
		rotationFlags = 17;
		weight = 500;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 20;
					healthLevels[] = 
					{
						{1.0,{"BastionMod\BastionMisc_Data\TearGasGrenade\data\gasgrenade.rvmat"}},
						{0.7,{"BastionMod\BastionMisc_Data\TearGasGrenade\data\gasgrenade.rvmat"}},
						{0.5,{"BastionMod\BastionMisc_Data\TearGasGrenade\data\gasgrenade_damage.rvmat"}},
						{0.3,{"BastionMod\BastionMisc_Data\TearGasGrenade\data\gasgrenade_damage.rvmat"}},
						{0.0,{"BastionMod\BastionMisc_Data\TearGasGrenade\data\gasgrenade_destruct.rvmat"}}
					};
				};
			};
		};
	};
};
