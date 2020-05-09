class CfgPatches
{
	class BRP_CSC45
	{
		units[] = {};
		weapons[] = {"BRP_CSC45"};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Weapons_Firearms","DZ_Characters"};
		magazines[] = {"BRP_Mag_CSC45_30Rnd"};
	};
};
class Mode_Safe;
class Mode_SemiAuto;
class Mode_FullAuto;
class cfgWeapons
{
	class AKS74U;
	class BRP_CSC45: AKS74U
	{
		scope = 2;
		displayName = "CSC-45";
		descriptionShort = "CSC-45 is a full-automatic SMG chambered in .45 ACP.";
		model = "BastionMod\BastionGuns\CSC45\csc45.p3d";
		attachments[] = {"weaponOptics","pistolMuzzle","pistolFlashlight"};
		magazines[] = {"BRP_Mag_CSC45_30Rnd"};
		itemSize[] = {4,2};
		modes[] = {"FullAuto","SemiAuto"};
		class SemiAuto: Mode_SemiAuto
		{
			soundSetShot[] = {"UMP45_Shot_SoundSet","UMP45_Tail_SoundSet","UMP45_InteriorTail_SoundSet"};
			soundSetShotExt[] = {{"UMP45_silencerPro_SoundSet","UMP45_silencerTail_SoundSet","UMP45_silencerInteriorTail_SoundSet"},{"UMP45_silencerHomeMade_SoundSet","UMP45_silencerHomeMadeTail_SoundSet","UMP45_silencerInteriorHomeMadeTail_SoundSet"}};
			reloadTime = 0.125;
			recoil = "recoil_m4";
			recoilProne = "recoil_m4_prone";
			dispersion = 0.002;
			magazineSlot = "magazine";
		};
		class FullAuto: Mode_FullAuto
		{
			soundSetShot[] = {"UMP45_Shot_SoundSet","UMP45_Tail_SoundSet","UMP45_InteriorTail_SoundSet"};
			soundSetShotExt[] = {{"UMP45_silencerPro_SoundSet","UMP45_silencerTail_SoundSet","UMP45_silencerInteriorTail_SoundSet"},{"UMP45_silencerHomeMade_SoundSet","UMP45_silencerHomeMadeTail_SoundSet","UMP45_silencerInteriorHomeMadeTail_SoundSet"}};
			reloadTime = 0.08;
			recoil = "recoil_m4";
			recoilProne = "recoil_m4_prone";
			dispersion = 0.002;
			magazineSlot = "magazine";
		};
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
	class Magazine_Base;
	class BRP_Mag_CSC45_30Rnd: Magazine_Base
	{
		scope = 2;
		displayName = "30round CSC-45 Magazine";
		descriptionShort = "30-round CSC-45 Magazine loaded in .45 ACP rounds.";
		model = "BastionMod\BastionGuns\CSC45\csc45mag.p3d";
		weight = 230;
		itemSize[] = {1,3};
		count = 30;
		ammo = "Bullet_45ACP";
		ammoItems[] = {"Ammo_45ACP"};
		isMeleeWeapon = 0;
		tracersEvery = 1;
	};
};

class CfgNonAIVehicles
{
	class ProxyAttachment;
	class Proxycsc45mag: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "magazine";
		model = "BastionMod\BastionGuns\CSC45\csc45mag.p3d";
	};
};