////////////////////////////////////////////////////////////////////
//DeRap: P:\BastionMod\BastionGuns\BROWNINGHP\config.bin
//Produced from mikero's Dos Tools Dll version 7.60
//https://mikero.bytex.digital/Downloads
//'now' is Tue Apr 28 20:42:04 2020 : 'file' last modified on Tue Apr 28 20:42:04 2020
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class BrowningHP
	{
		units[] = {};
		weapons[] = {"BastionRPGuns_BrowningHP"};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Pistols"};
		magazines[] = {"Mag_BrowningHP_13rnd"};
	};
};
class Mode_Safe;
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class OpticsInfoPistol;
class cfgWeapons
{
	class FNX45;
	class BastionRPGuns_BrowningHP: FNX45
	{
		scope = 2;
		displayName = "Browning Hi-Power";
		descriptionShort = "The Browning Hi Power is a single-action, semi-automatic handgun available in the 9mm and .40 S&W calibers. The Hi-Power is one of the most widely used military pistols in history, having been used by the armed forces of over 50 countries. Chambered in 9x19mm rounds.";
		model = "BastionMod\BastionGuns\BROWNINGHP\BrowningHP.p3d";
		attachments[] = {};
		magazines[] = {"Mag_BrowningHP_13Rnd"};
		chamberableFrom[] = {"Ammo_9x19"};
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
	class Mag_BrowningHP_13rnd: Mag_CZ75_15Rnd
	{
		scope = 2;
		displayName = "13rnd Browning Hi-Power Magazine";
		descriptionShort = "13 round Magazine for the Browning Hi-Power, loaded with 9x19mm rounds.";
		model = "BastionMod\BastionGuns\BROWNINGHP\mag_BrowningHP_13rnd.p3d";
		weight = 40;
		itemSize[] = {1,2};
		count = 13;
		ammoItems[] = {"Ammo_9x19"};
	};
};
