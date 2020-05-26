class CfgPatches
{
	class AK12
	{
		units[] = {};
		weapons[] = {"BRP__AK12"};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Weapons_Firearms","DZ_Characters"};
		magazines[] = {"BRP_Mag_AK12_30rnd"};
	};
};
class Mode_Safe;
class Mode_SemiAuto;
class Mode_FullAuto;
class cfgWeapons
{
	class AKM;
	class BRP_AK12: AKM
	{
		scope = 2;
		displayName = "AK-12";
		descriptionShort = "The AK-12 is a Russian assault rifle chambered in 5.45×39mm. It is designed and manufactured by Kalashnikov Concern. It is currently the latest of the Russian AK-Pattern series of assault rifles.";
		model = "BastionMod\BastionGuns\AK12\AK12.p3d";
		spawnDamageRange[] = {0,0};
		attachments[] = {"weaponFlashlight","weaponOptics","weaponWrap","suppressorImpro","weaponMuzzleAK"};
		chamberableFrom[] = {"Ammo_545x39","Ammo_545x39Tracer"};
		magazines[] = {"BRP_Mag_AK12_30Rnd"};
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
	class BRP_Mag_AK12_30rnd: Mag_AKM_30Rnd
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
