////////////////////////////////////////////////////////////////////
//DeRap: P:\BastionMod\BastionGuns\BERETTA92\config.bin
//Produced from mikero's Dos Tools Dll version 7.60
//https://mikero.bytex.digital/Downloads
//'now' is Tue Apr 28 20:41:45 2020 : 'file' last modified on Tue Apr 28 20:41:45 2020
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class Beretta92
	{
		units[] = {};
		weapons[] = {"BastionRPGuns_BerettaM9"};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Pistols"};
		magazines[] = {"Mag_BerettaM9_15rnd"};
	};
};
class Mode_Safe;
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class OpticsInfoPistol;
class cfgWeapons
{
	class CZ75;
	class BastionRPGuns_BerettaM9: CZ75
	{
		scope = 2;
		displayName = "Beretta M9";
		descriptionShort = "The Beretta M9——officially the Pistol, Semiautomatic, 9mm, M9——is the designation for the Beretta 92F semi-automatic pistol used by the United States Armed Forces. The M9 was adopted by the United States military as their service pistol in 1985. Chambered in 9x19mm Rounds.";
		model = "BastionMod\BastionGuns\BERETTA92\Beretta92.p3d";
		attachments[] = {};
		magazines[] = {"Mag_BerettaM9_15Rnd"};
		itemSize[] = {4,2};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1,{"DZ\weapons\pistols\cz75\data\cz75.rvmat"}},{0.7,{"DZ\weapons\pistols\cz75\data\cz75.rvmat"}},{0.5,{"DZ\weapons\pistols\cz75\data\cz75_damage.rvmat"}},{0.3,{"DZ\weapons\pistols\cz75\data\cz75_damage.rvmat"}},{0,{"DZ\weapons\pistols\cz75\data\cz75_destruct.rvmat"}}};
				};
			};
		};
	};
};
class CfgMagazines
{
	class Mag_CZ75_15Rnd;
	class Mag_BerettaM9_15rnd: Mag_CZ75_15Rnd
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
