﻿class CfgPatches
{
	class P99
	{
		units[] = {};
		weapons[] = {"BastionRPGuns_P99"};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Pistols"};
		magazines[] = {"Mag_P99_15rnd"};
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
	class BastionRPGuns_P99: CZ75
	{
		scope = 2;
		displayName = "Walther P99";
		descriptionShort = "The Walther P99 is a semi-automatic pistol developed by the German company Carl Walther GmbH Sportwaffen of Ulm for law enforcement, security forces and the civilian shooting market as a replacement for the Walther P5 and the P88. The P99 and its variants are also made under licence by Fabryka Broni Radom. Chambered in 9x19mm Rounds.";
		model = "BastionMod\Guns\P99\P99.p3d";
		attachments[] = {};
		magazines[] = {"Mag_P99_15Rnd"};
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
	class Mag_P99_15rnd: Mag_CZ75_15Rnd
	{
		scope = 2;
		displayName = "15rnd P99 Magazine";
		descriptionShort = "15 round Magazine for the P99, loaded with 9x19mm rounds.";
		model = "BastionMod\Guns\P99\mag_P99_10rnd.p3d";
		weight = 40;
		itemSize[] = {1,2};
		count = 15;
		ammoItems[] = {"Ammo_9x19"};
	};
};
