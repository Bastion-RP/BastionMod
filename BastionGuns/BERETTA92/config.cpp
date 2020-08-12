class CfgPatches
{
	class BRP_BerettaM9
	{
		units[] = {};
		weapons[] = {"BRP_BerettaM9"};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Pistols"};
		magazines[] = {"BRP_Mag_BerettaM9_15rnd"};
	};
};

class Mode_Safe;
class Mode_SemiAuto;
class cfgWeapons
{
	class CZ75;
	class BRP_BerettaM9: CZ75
	{
		scope = 2;
		displayName = "Beretta M9";
		descriptionShort = "The Beretta M9 is the designation for the Beretta 92F semi-automatic pistol used by the United States Armed Forces. The M9 was adopted by the United States military as their service pistol in 1985. Chambered in 9x19mm Rounds.";
		model = "BastionMod\BastionGuns\BERETTA92\Beretta92.p3d";
		attachments[] = {"pistolMuzzle", "pistolFlashlight"};
		magazines[] = {"BRP_Mag_BerettaM9_15rnd"};
		itemSize[] = {3,2};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\pistols\cz75\data\cz75.rvmat"}},{0.7,{"DZ\weapons\pistols\cz75\data\cz75.rvmat"}},{0.5,{"DZ\weapons\pistols\cz75\data\cz75_damage.rvmat"}},{0.3,{"DZ\weapons\pistols\cz75\data\cz75_damage.rvmat"}},{0.0,{"DZ\weapons\pistols\cz75\data\cz75_destruct.rvmat"}}};
				};
			};
		};
	};
};

class CfgMagazines
{
	class Mag_CZ75_15Rnd;
	class BRP_Mag_BerettaM9_15rnd: Mag_CZ75_15Rnd
	{
		scope = 2;
		displayName = "15rnd Beretta M9 Magazine";
		descriptionShort = "15 round Magazine for the Beretta M9, loaded with 9x19mm rounds.";
		model = "BastionMod\BastionGuns\BERETTA92\mag_Beretta92_15rnd.p3d";
		weight = 40;
		itemSize[] = {1,2};
		count = 15;
		ammoItems[] = {"Ammo_9x19"};
	};
};
