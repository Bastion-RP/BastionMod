class CfgPatches
{
	class BRP_CSSMG9
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Weapons_Firearms","DZ_Weapons_Magazines"};
	};
};
class Mode_Safe;
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class OpticsInfoRifle;
class cfgWeapons
{
	class Rifle_Base;
	class BRP_CSSMG9_Base: Rifle_Base
	{
		scope = 0;
		weight = 2700;
		absorbency = 0.0;
		repairableWithKits[] = {5,1};
		repairCosts[] = {30.0,25.0};
		PPDOFProperties[] = {1,0.75,40,180,4,10};
		WeaponLength = 0.583269;
		chamberSize = 1;
		chamberedRound = "";
		chamberableFrom[] = {"Ammo_9x19"};
		magazines[] = {"BRP_Mag_CSSMG9_30Rnd"};
		magazineSwitchTime = 0.5;
		ejectType = 1;
		recoilModifier[] = {0.7,0.7,0.7};
		swayModifier[] = {1.2,1.2,1};
		reloadAction = "ReloadM4";
		modes[] = {"FullAuto","SemiAuto"};
		class SemiAuto: Mode_SemiAuto
		{
			soundSetShot[] = {"Red9_Shot_SoundSet","Red9_Tail_SoundSet","Red9_InteriorTail_SoundSet"};
			soundSetShotExt[] = {{"Red9_silencerHomeMade_SoundSet","Red9_silencerHomeMadeTail_SoundSet","Red9_silencerInteriorHomeMadeTail_SoundSet"}};
			reloadTime = 0.125;
			recoil = "recoil_mp5";
			recoilProne = "recoil_mp5_prone";
			dispersion = 0.0025;
			magazineSlot = "magazine";
		};
		class FullAuto: Mode_FullAuto
		{
			soundSetShot[] = {"Red9_Shot_SoundSet","Red9_Tail_SoundSet","Red9_InteriorTail_SoundSet"};
			soundSetShotExt[] = {{"Red9_silencerHomeMade_SoundSet","Red9_silencerHomeMadeTail_SoundSet","Red9_silencerInteriorHomeMadeTail_SoundSet"}};
			reloadTime = 0.065;
			recoil = "recoil_mp5";
			recoilProne = "recoil_mp5_prone";
			dispersion = 0.0025;
			magazineSlot = "magazine";
		};	
		class OpticsInfo: OpticsInfoRifle
		{
			memoryPointCamera = "eye";
			modelOptics = "-";
			distanceZoomMin = 50;
			distanceZoomMax = 50;
			discreteDistance[] = {50};
			discreteDistanceInitIndex = 0;
		};
		class Particles
		{
			class OnFire
			{
				class MuzzleFlash
				{
					overrideParticle = "weapon_shot_mp5k_01";
					ignoreIfSuppressed = 1;
					illuminateWorld = 1;					
				};
				class SmokeCloud
				{
					overrideParticle = "weapon_shot_winded_smoke_small";
				};
				class ChamberSmokeBurst
				{
					overrideParticle = "weapon_shot_chamber_smoke";
					overridePoint = "Nabojnicestart";
					overrideDirectionPoint = "Nabojniceend";
				};
			};
			class OnOverheating
			{
				shotsToStartOverheating = 3;
				maxOverheatingValue = 10;
				overheatingDecayInterval = 1;
				class SmokingBarrel
				{
					overrideParticle = "smoking_barrel_small";
					onlyWithinOverheatLimits[] = {0,0.8};
					onlyWithinRainLimits[] = {0.0,0.2};
				};
				class SmokingBarrelHotSteam
				{
					overrideParticle = "smoking_barrel_steam_small";
					positionOffset[] = {0.1,0.02,0};
					onlyWithinOverheatLimits[] = {0,1};
					onlyWithinRainLimits[] = {0.2,1};
				};
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
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
					healthLevels[] = 
					{
						{1.0,{"BastionMod\BastionGuns\MPX\data\mpx.rvmat","BastionMod\BastionGuns\MPX\data\mpx_acc.rvmat"}},
						{0.7,{"BastionMod\BastionGuns\MPX\data\mpx.rvmat","BastionMod\BastionGuns\MPX\data\mpx_acc.rvmat"}},
						{0.5,{"BastionMod\BastionGuns\MPX\data\mpx_damage.rvmat","BastionMod\BastionGuns\MPX\data\mpx_acc_damage.rvmat"}},
						{0.3,{"BastionMod\BastionGuns\MPX\data\mpx_damage.rvmat","BastionMod\BastionGuns\MPX\data\mpx_acc_damage.rvmat"}},
						{0.0,{"BastionMod\BastionGuns\MPX\data\mpx_destruct.rvmat","BastionMod\BastionGuns\MPX\data\mpx_acc_destruct.rvmat"}}
					};
				};
			};
		};	
	};
	class BRP_CSSMG9: BRP_CSSMG9_Base
	{
		scope = 2;
		displayName = "CSSMG-9";
		descriptionShort = "CSSMG-9 is a gas-operated submachine gun, primarily chambered in 9x19mm Parabellum cartridge and takes 30 round mags. It is a gas-operated firearm featuring a closed, rotating bolt. ";
		model = "BastionMod\BastionGuns\MPX\MPX.p3d";
		attachments[] = {"weaponWrap","weaponOptics","suppressorImpro","pistolMuzzle"};
		itemSize[] = {6,3};
	};
};
class cfgMagazines
{
	class Magazine_Base;
	class BRP_Mag_CSSMG9_30Rnd: Magazine_Base
	{
		scope = 2;
		displayName = "30rd CSSMG-9 Mag";
		descriptionShort = "Detachable box magazine for CSSMG-9 submachine gun. Holds up to 30 rounds of 9x19mm.";
		model = "BastionMod\BastionGuns\MPX\MPX_mag.p3d";
		weight = 150;
		itemSize[] = {1,3};
		count = 30;
		ammo = "Bullet_9x19";
		ammoItems[] = {"Ammo_9x19"};
		tracersEvery = 0;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = 
					{
						{1.0,{"BastionMod\BastionGuns\MPX\data\mpx.rvmat"}},
						{0.7,{"BastionMod\BastionGuns\MPX\data\mpx.rvmat"}},
						{0.5,{"BastionMod\BastionGuns\MPX\data\mpx_damage.rvmat"}},
						{0.3,{"BastionMod\BastionGuns\MPX\data\mpx_damage.rvmat"}},
						{0.0,{"BastionMod\BastionGuns\MPX\data\mpx_destruct.rvmat"}}
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