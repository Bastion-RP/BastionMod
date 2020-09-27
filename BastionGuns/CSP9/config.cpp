class CfgPatches
{
	class BastionRP_Pistols_CSP9
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Pistols_CZ75"};
		magazines[] = {};
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
	class CSP9_Base: CZ75
	{
		scope = 0;
		model = "BastionMod\BastionGuns\CSP9\CSP9.p3d";
		attachments[] = {"pistolMuzzle","pistolFlashlight"};
		itemSize[] = {3,2};		
		weight = 950;
		absorbency = 0;
		repairableWithKits[] = {5,1};
		repairCosts[] = {30,25};
		PPDOFProperties[] = {1,0.5,10,250,4,10};
		ironsightsExcludingOptics[] = {"FNP45_MRDSOptic"};
		WeaponLength = 0.634148;
		chamberSize = 1;
		chamberedRound = "";
		magazines[] = {"BRP_Mag_CSP9_17Rnd"};
		chamberableFrom[] = {"Ammo_9x19"};
		ejectType = 1;
		recoilModifier[] = {1,1,1};
		modes[] = {"SemiAuto"};
		class SemiAuto: Mode_SemiAuto
		{
			soundSetShot[] = {"FNX45_Shot_SoundSet","FNX45_Tail_SoundSet","FNX45_InteriorTail_SoundSet"};
			soundSetShotExt[] = {{"FNX45_silencerPro_SoundSet","FNX45_silencerTail_SoundSet","FNX45_silencerInteriorTail_SoundSet"}};
			reloadTime = 0.125;
			recoil = "recoil_fnx";
			recoilProne = "recoil_fnx_prone";
			dispersion = 0.006;
			magazineSlot = "magazine";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = 
					{
						{1.0,{"BastionMod\BastionGuns\CSP9\data\csp9.rvmat"}},
						{0.7,{"BastionMod\BastionGuns\CSP9\data\csp9.rvmat"}},
						{0.5,{"BastionMod\BastionGuns\CSP9\data\csp9_damage.rvmat"}},
						{0.3,{"BastionMod\BastionGuns\CSP9\data\csp9_damage.rvmat"}},
						{0.0,{"BastionMod\BastionGuns\CSP9\data\csp9_destruct.rvmat"}}
					};
				};
			};
		};		
		class Particles
		{
			class OnFire
			{
				class MuzzleFlashForward
				{
					ignoreIfSuppressed = 1;
					illuminateWorld = 1;
					overrideParticle = "weapon_shot_fnx_01";
				};
				class SmokeCloud
				{
					overrideParticle = "weapon_shot_winded_smoke_small";
				};
			};
			class OnOverheating
			{
				shotsToStartOverheating = 1;
				maxOverheatingValue = 7;
				overheatingDecayInterval = 1;
				class OpenChamberSmoke
				{
					onlyIfBoltIsOpen = 1;
					overrideParticle = "smoking_barrel_small";
					overridePoint = "Nabojnicestart";
				};
			};
			class OnBulletCasingEject
			{
				class ChamberSmokeRaise
				{
					overrideParticle = "weapon_shot_chamber_smoke_raise";
					overridePoint = "Nabojnicestart";
				};
			};
		};		
	};
	class BRP_CSP9: CSP9_Base
	{
		scope = 2;
		displayName = "CSP-9";
		descriptionShort = "Russian-made, NCC co-opted 9x19mm handgun.";
	};
	class BRP_CSP45: CSP9_Base
	{
		scope = 2;
		displayName = "CSP-45";
		descriptionShort = "Russian-made, NCC co-opted .45 ACP handgun.";
		magazines[] = {"BRP_Mag_CSP45_15Rnd"};
		chamberableFrom[] = {"Ammo_45ACP"};
		recoilModifier[] = {1.05,1.05,1.05};		
	};	
};
class CfgMagazines
{
	class Magazine_Base;
	class BRP_Mag_CSP9_17Rnd: Magazine_Base
	{
		scope = 2;
		displayName = "17 round CSP9 Grach Mag";
		descriptionShort = "CSP9 Grach Mag is a 17 round mag for the CSP9 pistol, loaded in 9x19mm rounds.";
		model = "BastionMod\BastionGuns\CSP9\CSP9mag.p3d";
		weight = 230;
		itemSize[] = {1,2};
		count = 17;
		ammo = "Bullet_9x19";
		ammoItems[] = {"Ammo_9x19"};
		isMeleeWeapon = 0;
		tracersEvery = 1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = 
					{
						{1.0,{"BastionMod\BastionGuns\CSP9\data\csp9.rvmat"}},
						{0.7,{"BastionMod\BastionGuns\CSP9\data\csp9.rvmat"}},
						{0.5,{"BastionMod\BastionGuns\CSP9\data\csp9_damage.rvmat"}},
						{0.3,{"BastionMod\BastionGuns\CSP9\data\csp9_damage.rvmat"}},
						{0.0,{"BastionMod\BastionGuns\CSP9\data\csp9_destruct.rvmat"}}
					};
				};
			};
		};	
		class AnimEvents
		{
			class SoundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet = "MagRifle_fill_in_SoundSet";
					id = 1;
				};
				class MagRifle_fill_loop
				{
					soundSet = "MagRifle_fill_loop_SoundSet";
					id = 2;
				};
				class MagRifle_fill_out
				{
					soundSet = "MagRifle_fill_out_SoundSet";
					id = 3;
				};
				class MagRifle_empty_in
				{
					soundSet = "MagRifle_empty_in_SoundSet";
					id = 4;
				};
				class MagRifle_empty_loop
				{
					soundSet = "MagRifle_empty_loop_SoundSet";
					id = 5;
				};
				class MagRifle_empty_out
				{
					soundSet = "MagRifle_empty_out_SoundSet";
					id = 6;
				};
				class MagPistol_fill_in
				{
					soundSet = "MagPistol_fill_in_SoundSet";
					id = 7;
				};
				class MagPistol_fill_loop
				{
					soundSet = "MagPistol_fill_loop_SoundSet";
					id = 8;
				};
				class MagPistol_fill_out
				{
					soundSet = "MagPistol_fill_out_SoundSet";
					id = 9;
				};
				class MagPistol_empty_in
				{
					soundSet = "MagPistol_empty_in_SoundSet";
					id = 10;
				};
				class MagPistol_empty_loop
				{
					soundSet = "MagPistol_empty_loop_SoundSet";
					id = 11;
				};
				class MagPistol_empty_out
				{
					soundSet = "MagPistol_empty_out_SoundSet";
					id = 12;
				};
			};
		};
	};
	class BRP_Mag_CSP45_15Rnd: Magazine_Base
	{
		scope = 2;
		displayName = "15 round CSP9 Grach Mag";
		descriptionShort = "CSP9 Grach Mag is a 15 round mag for the CSP9 pistol, loaded in .45 ACP rounds.";
		model = "BastionMod\BastionGuns\CSP9\CSP9mag.p3d";
		weight = 230;
		itemSize[] = {1,2};
		count = 15;
		ammo = "Bullet_45ACP";
		ammoItems[] = {"Ammo_45ACP"};
		isMeleeWeapon = 0;
		tracersEvery = 1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = 
					{
						{1.0,{"BastionMod\BastionGuns\CSP9\data\csp9.rvmat"}},
						{0.7,{"BastionMod\BastionGuns\CSP9\data\csp9.rvmat"}},
						{0.5,{"BastionMod\BastionGuns\CSP9\data\csp9_damage.rvmat"}},
						{0.3,{"BastionMod\BastionGuns\CSP9\data\csp9_damage.rvmat"}},
						{0.0,{"BastionMod\BastionGuns\CSP9\data\csp9_destruct.rvmat"}}
					};
				};
			};
		};	
		class AnimEvents
		{
			class SoundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet = "MagRifle_fill_in_SoundSet";
					id = 1;
				};
				class MagRifle_fill_loop
				{
					soundSet = "MagRifle_fill_loop_SoundSet";
					id = 2;
				};
				class MagRifle_fill_out
				{
					soundSet = "MagRifle_fill_out_SoundSet";
					id = 3;
				};
				class MagRifle_empty_in
				{
					soundSet = "MagRifle_empty_in_SoundSet";
					id = 4;
				};
				class MagRifle_empty_loop
				{
					soundSet = "MagRifle_empty_loop_SoundSet";
					id = 5;
				};
				class MagRifle_empty_out
				{
					soundSet = "MagRifle_empty_out_SoundSet";
					id = 6;
				};
				class MagPistol_fill_in
				{
					soundSet = "MagPistol_fill_in_SoundSet";
					id = 7;
				};
				class MagPistol_fill_loop
				{
					soundSet = "MagPistol_fill_loop_SoundSet";
					id = 8;
				};
				class MagPistol_fill_out
				{
					soundSet = "MagPistol_fill_out_SoundSet";
					id = 9;
				};
				class MagPistol_empty_in
				{
					soundSet = "MagPistol_empty_in_SoundSet";
					id = 10;
				};
				class MagPistol_empty_loop
				{
					soundSet = "MagPistol_empty_loop_SoundSet";
					id = 11;
				};
				class MagPistol_empty_out
				{
					soundSet = "MagPistol_empty_out_SoundSet";
					id = 12;
				};
			};
		};		
	};	
};