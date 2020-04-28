////////////////////////////////////////////////////////////////////
//DeRap: P:\BastionMod\BastionGuns\AK12\config.bin
//Produced from mikero's Dos Tools Dll version 7.60
//https://mikero.bytex.digital/Downloads
//'now' is Tue Apr 28 20:38:30 2020 : 'file' last modified on Tue Apr 28 20:38:30 2020
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class AK12
	{
		units[] = {};
		weapons[] = {"BastionRPGuns_AK12"};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Weapons_Firearms","DZ_Characters"};
		magazines[] = {"Mag_AK12_30rnd"};
	};
};
class Mode_Safe;
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class cfgWeapons
{
	class AKM;
	class BastionRPGuns_AK12: AKM
	{
		scope = 2;
		displayName = "AK-12";
		descriptionShort = "The AK-12 is a Russian assault rifle chambered in 5.45×39mm. It is designed and manufactured by Kalashnikov Concern. It is currently the latest of the Russian AK-Pattern series of assault rifles.";
		model = "BastionMod\BastionGuns\AK12\AK12.p3d";
		spawnDamageRange[] = {0,0};
		attachments[] = {"weaponFlashlight","weaponButtstockAK","weaponBipod","weaponOptics","weaponWrap","suppressorImpro","weaponMuzzleAK"};
		ironsightsExcludingOptics[] = {"M4_CarryHandleOptic","BUISOptic","M68Optic","M4_T3NRDSOptic","ReflexOptic","ACOGOptic"};
		chamberableFrom[] = {"Ammo_545x39","Ammo_545x39Tracer"};
		magazines[] = {"Mag_AK12_30Rnd"};
		class SemiAuto: Mode_SemiAuto
		{
			soundSetShot[] = {"AK_Shot_SoundSet","AK_Tail_SoundSet","AK_InteriorTail_SoundSet"};
			soundSetShotExt[] = {{"AK_silencer_SoundSet","AK_silencerTail_SoundSet","AK_silencerInteriorTail_SoundSet"},{"AK_silencerHomeMade_SoundSet","AK_silencerHomeMadeTail_SoundSet","AK_silencerInteriorHomeMadeTail_SoundSet"}};
			soundBegin[] = {"begin1",0.33333,"begin2",0.33333,"begin2",0.33333};
			reloadTime = 0.125;
			recoil = "recoil_AKM";
			recoilProne = "recoil_AKM_prone";
			dispersion = 0.0015;
			magazineSlot = "magazine";
		};
		class FullAuto: Mode_FullAuto
		{
			soundSetShot[] = {"AK_Shot_SoundSet","AK_Tail_SoundSet","AK_InteriorTail_SoundSet"};
			soundSetShotExt[] = {{"AK_silencer_SoundSet","AK_silencerTail_SoundSet","AK_silencerInteriorTail_SoundSet"},{"AK_silencerHomeMade_SoundSet","AK_silencerHomeMadeTail_SoundSet","AK_silencerInteriorHomeMadeTail_SoundSet"}};
			soundBegin[] = {"begin1",0.33333,"begin2",0.33333,"begin2",0.33333};
			reloadTime = 0.092;
			recoil = "recoil_AKM";
			recoilProne = "recoil_AKM_prone";
			dispersion = 0.0015;
			magazineSlot = "magazine";
		};
	};
};
class CfgMagazines
{
	class Mag_AKM_30Rnd;
	class Mag_AK12_30rnd: Mag_AKM_30Rnd
	{
		scope = 2;
		displayName = "30rnd AK-12 Magazine";
		descriptionShort = "30rnd magazine for the AK-12, loaded with 5.45x39mm rounds.";
		model = "BastionMod\BastionGuns\AK12\mag_AK12_30rnd.p3d";
		weight = 120;
		itemSize[] = {1,3};
		count = 30;
		ammo = "Bullet_545x39";
		ammoItems[] = {"Ammo_545x39","Ammo_545x39Tracer"};
	};
};
