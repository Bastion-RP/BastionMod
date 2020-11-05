class CfgPatches
{
	class BastionMeleeNerf
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={
			"DZ_Data",
			"DZ_Characters",
			"MSP_Weapons_Data"
		};
	};
};
class CfgMods
{
	class BastionMeleeNerf
	{
	    type = "mod";
	    dependencies[] = {"Game","World","Mission"};
	    class defs
	    {
			class gameScriptModule
            {
                value = "";
                files[] = {"BastionMod/BastionMisc/MeleeNerf/scripts/3_Game"};
            };
			class worldScriptModule
            {
                value = "";
                files[] = {"BastionMod/BastionMisc/MeleeNerf/scripts/4_World"};
            };
			class missionScriptModule
            {
                value = "";
                files[] = {"BastionMod/BastionMisc/MeleeNerf/scripts/5_Mission"};
            };
        };
    };
};

class CfgVehicles
{
	class Msp_BlunderBat;
	class BRP_Msp_BlunderBat: Msp_BlunderBat
	{
		class MeleeModes
		{
			class Default
			{
				ammo = "BRP_MeleeBlunderBat";
				range = 1.6;
			};
			class Heavy
			{
				ammo = "BRP_MeleeBlunderBat_Heavy";
				range = 1.6;
			};
			class Sprint
			{
				ammo = "BRP_MeleeBlunderBat_Heavy";
				range = 4.0;
			};
		};
	};	
};

// Nerf melee:
// - Reduce shock damage for hits by fists.
class CfgAmmo {
	class Bullet_Base;
	class MeleeDamage;
	class MeleeFist: MeleeDamage {
		class DamageApplied {
			type = "Melee";
			class Health {
				damage = 7;
				armorDamage = 0.1;
			};
			class Blood {
				damage = 0;
			};
			class Shock {
				damage = 5;
			};
		};
    };
    class MeleeFist_Heavy: MeleeFist {
		hitAnimation = 1;
		class DamageApplied {
			type = "Melee";
			class Health {
				damage = 14;
				armorDamage = 0.1;
			};
			class Blood {
				damage = 0;
			};
			class Shock {
				damage = 9;
			};
		};
	};
	
// -- MSP NERF
	class MeleeMachete;
	class MeleeMachete_Heavy;
	class BRP_MeleeBlunderBat: MeleeMachete
	{
		affectSkeleton = 0.2;
		class DamageApplied
		{
			type = "Melee";
			bleedThreshold = 1;
			class Health
			{
				damage = 20;
			};
			class Blood
			{
				damage = 60;
			};
			class Shock
			{
				damage = 15;
			};
			additionAnimalMeleeMultiplier = 3;
		};
	};
	class BRP_MeleeBlunderBat_Heavy: MeleeMachete_Heavy
	{
		class DamageApplied
		{
			type = "Melee";
			bleedThreshold = 1;
			class Health
			{
				damage = 25;
			};
			class Blood
			{
				damage = 100;
			};
			class Shock
			{
				damage = 20;
			};
			additionAnimalMeleeMultiplier = 3;
		};
		hitAnimation = 1;
	};
		
};

