////////////////////////////////////////////////////////////////////
//DeRap: P:\BastionMod\BastionGuns\MKIIA\config.bin
//Produced from mikero's Dos Tools Dll version 7.60
//https://mikero.bytex.digital/Downloads
//'now' is Tue Apr 28 20:43:56 2020 : 'file' last modified on Tue Apr 28 20:43:56 2020
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class MKIIA
	{
		units[] = {};
		weapons[] = {"BRP_MKIIA"};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Pistols"};
		magazines[] = {"BRP_Mag_MKIIA_6rnd"};
	};
};
class Mode_Safe;
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class OpticsInfoPistol;
class cfgWeapons
{
	class MKII;
	class MKIIA_Base: MKII
	{
		scope = 0;
		weight = 1300;
		absorbency = 0;
		repairableWithKits[] = {5,1};
		repairCosts[] = {30,25};
		modelOptics = "-";
		distanceZoomMin = 100;
		distanceZoomMax = 100;
		value = 0;
		chamberSize = 1;
		chamberedRound = "";
		magazines[] = {"BRP_Mag_MKIIA_6rnd"};
		chamberableFrom[] = {"Ammo_9x19"};
		ejectType = 1;
		recoilModifier[] = {1,1,1};
		reloadAction = "ReloadRugerMK2";
		modes[] = {"Single"};
		class Single: Mode_SemiAuto
		{
			soundSetShot[] = {"AmphibianS_Shot_SoundSet","AmphibianS_Tail_SoundSet","AmphibianS_InteriorTail_SoundSet"};
			soundSetShotExt[] = {{"AmphibianS_silencerHomeMade_SoundSet","AmphibianS_silencerHomeMadeTail_SoundSet","AmphibianS_InteriorTail_SoundSet"}};
			begin1[] = {"",0.8,1,80};
			begin2[] = {"",0.8,1,80};
			begin3[] = {"",0.8,1,80};
			soundBegin[] = {"begin1",0.33333,"begin2",0.33333,"begin3",0.33333};
			beginSilenced_HomeMade[] = {"",0.02,1,20};
			soundBeginExt[] = {{"beginSilenced_HomeMade",1}};
			reloadTime = 0.08;
			recoil = "recoil_mkii";
			recoilProne = "recoil_mkii_prone";
			dispersion = 0.006;
			magazineSlot = "magazine";
		};
		class NoiseShoot
		{
			strength = 10;
			type = "shot";
		};
	};
	class BRP_MKIIA: MKIIA_Base
	{
		scope = 2;
		displayName = "Welrod MKIIA";
		descriptionShort = "The Welrod is a British bolt action, magazine fed, suppressed pistol devised during World War II by Major Hugh Reeves at the Inter-Services Research Bureau. Chambered in 9x19mm rounds.";
		model = "BastionMod\BastionGuns\MKIIA\MKIIA.p3d";
		attachments[] = {};
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
		class SemiAuto: Mode_SemiAuto
		{
			soundSetShot[] = {"FNX45_silencerPro_SoundSet","FNX45_silencerTail_SoundSet","FNX45_silencerInteriorTail_SoundSet"};
			soundSetShotExt[] = {{"FNX45_silencerPro_SoundSet","FNX45_silencerTail_SoundSet","FNX45_silencerInteriorTail_SoundSet"}};
			soundBegin[] = {"begin1",0.33333,"begin2",0.33333,"begin2",0.33333};
			reloadTime = 1.25;
			recoil = "recoil_mkii";
			recoilProne = "recoil_mkii_prone";
			dispersion = 0.006;
			magazineSlot = "magazine";
		};
	};
};
class CfgMagazines
{
	class Mag_CZ75_15Rnd;
	class BRP_Mag_MKIIA_6rnd: Mag_CZ75_15Rnd
	{
		scope = 2;
		displayName = "6rnd MKIIA Magazine";
		descriptionShort = "6 round Magazine for the MKIIA, loaded with 9x19mm rounds.";
		model = "BastionMod\BastionGuns\MKIIA\mag_MKIIA_6rnd.p3d";
		weight = 40;
		itemSize[] = {1,2};
		count = 6;
		ammoItems[] = {"Ammo_9x19"};
	};
};
