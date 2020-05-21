class CfgPatches
{
	class BastionGasGrenade
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Weapons_Explosives"};
	};
};

class CfgMods
{
    class TearGasGrenade
    {
        dir = "TearGasGrenade";
        picture = "";
        action = "";
        hideName = 1;
        hidePicture = 1;
        name = "TearGasGrenade";
        credits = "";
        author = "BastionRP Team";
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
                files[] = {"BastionMod/BastionMisc/TearGasGrenade/scripts/4_World"};
			};
		};
    };
};

class CfgVehicles
{
	class Grenade_Base;
	class BRP_GasGrenade: Grenade_Base
	{
		scope = 2;
		displayName = "Tear Gas Grenade";
		descriptionShort = "Description of gas grenade (:";
		model = "BastionMod\BastionMisc_Data\TearGasGrenade\gasgrenade.p3d";
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
		class EnergyManager
		{
			energyAtSpawn = 90;
			energyUsagePerSecond = 1;
			wetnessExposure = 0.1;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class Unpin
				{
					soundSet = "SmokegGrenades_M18_oneshot_ignite_SoundSet";
					id = 201;
				};
			};
		};
	};
};
