class CfgPatches
{
	class BastionMeleeNerf
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={
			"DZ_Data",
			"DZ_Characters"
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
};