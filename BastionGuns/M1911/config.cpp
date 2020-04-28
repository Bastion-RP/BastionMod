////////////////////////////////////////////////////////////////////
//DeRap: P:\BastionMod\BastionGuns\M1911\config.bin
//Produced from mikero's Dos Tools Dll version 7.60
//https://mikero.bytex.digital/Downloads
//'now' is Tue Apr 28 20:43:35 2020 : 'file' last modified on Tue Apr 28 20:43:35 2020
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class BRP_M1911
	{
		units[] = {};
		weapons[] = {"BRP_M1911"};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Weapons_Firearms","DZ_Weapons_Ammunition","DZ_Weapons_Magazines"};
		magazines[] = {"BRP_M1911_Magazine"};
		ammo[] = {};
	};
};
class Mode_Safe;
class Mode_SemiAuto;
class cfgWeapons
{
	class Colt1911;
	class BRP_M1911: Colt1911
	{
		scope = 2;
		displayName = "Makeshift Colt 1911";
		descriptionShort = "This is a makeshift Colt 1911.";
		weight = 1000;
		model = "\BastionMod\BastionGuns\M1911\M1911.p3d";
		magazines[] = {"BRP_M1911_Magazine","Mag_1911_7Rnd"};
		itemSize[] = {6,3};
		PPDOFProperties[] = {0,0,0,0,0,0};
		dexterity = 3.0;
		discreteDistance[] = {25,50,100};
		chamberSize = 1;
		chamberableFrom[] = {"Ammo_45ACP"};
		attachments[] = {};
		modes[] = {"SemiAuto"};
		class SemiAuto: Mode_SemiAuto
		{
			soundSetShot[] = {"Colt1911_Shot_SoundSet","Colt1911_Tail_SoundSet","Colt1911_InteriorTail_SoundSet"};
			soundSetShotExt[] = {{"Colt1911_silencerPro_SoundSet","Colt1911_silencerTail_SoundSet","Colt1911_silencerInteriorTail_SoundSet"}};
			reloadTime = 0.065;
			recoil = "recoil_1911";
			recoilProne = "recoil_1911_prone";
			dispersion = 0.0015;
			magazineSlot = "magazine";
		};
	};
};
class CfgMagazines
{
	class Magazine_Base;
	class BRP_M1911_Magazine: Magazine_Base
	{
		scope = 2;
		displayName = "Colt 1911 Magazine";
		descriptionShort = "";
		model = "\BastionMod\BastionGuns\M1911\M1911_Magazine.p3d";
		weight = 90;
		itemSize[] = {1,2};
		count = 7;
		ammo = "Bullet_45ACP";
		ammoItems[] = {"Ammo_45ACP"};
		isMeleeWeapon = 0;
		tracersEvery = 1;
	};
};
