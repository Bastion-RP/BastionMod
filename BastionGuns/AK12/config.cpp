class CfgPatches
{
	class BRP_AK15
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Weapons_Firearms"};
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
	class BRP_AK15_Base: Rifle_Base
	{
		scope = 0;
		displayName = "AK-15";
		descriptionShort = "Selective-fire assault rifle fed from a detachable magazine. Modernized version of classic AKM. Uses 7.62x39mm rounds.";
		model = "BastionMod\BastionGuns\AK12\ak12.p3d";
		attachments[] = {"weaponWrap","weaponMuzzleAK","weaponOptics","weaponFlashlight"};		
		itemSize[] = {8,3};
		weight = 3500;
		absorbency = 0.0;
		repairableWithKits[] = {5,1};
		repairCosts[] = {30.0,50.0};
		barrelArmor = 4.444;		
		PPDOFProperties[] = {};
		WeaponLength = 0.929067;
		chamberSize = 1;
		chamberedRound = "";
		chamberableFrom[] = {"Ammo_762x39","Ammo_762x39Tracer"};
		magazines[] = {"Mag_AKM_30Rnd","Mag_AKM_Palm30Rnd","Mag_AKM_Palm30Rnd_Black","Mag_AKM_Palm30Rnd_Green","Mag_AKM_Drum75Rnd","Mag_AKM_Drum75Rnd_Green","Mag_AKM_Drum75Rnd_Black","Mag_AKM_Drum_TEST"};
		ejectType = 1;
		recoilModifier[] = {0.6,0.6,0.6};
		swayModifier[] = {1.8,1.8,1.05};
		simpleHiddenSelections[] = {"hide_barrel","hide_ironsights"};
		modes[] = {"FullAuto"};
		class SemiAuto: Mode_SemiAuto
		{
			soundSetShot[] = {"AK_Shot_SoundSet","AK_Tail_SoundSet","AK_InteriorTail_SoundSet"};
			soundSetShotExt[] = {{"AK_silencer_SoundSet","AK_silencerTail_SoundSet","AK_silencerInteriorTail_SoundSet"},{"AK_silencerHomeMade_SoundSet","AK_silencerHomeMadeTail_SoundSet","AK_silencerInteriorHomeMadeTail_SoundSet"}};
			reloadTime = 0.125;
			recoil = "recoil_AKM";
			recoilProne = "recoil_AKM_prone";
			dispersion = 0.0013;
			magazineSlot = "magazine";
		};
		class FullAuto: Mode_FullAuto
		{
			soundSetShot[] = {"AK_Shot_SoundSet","AK_Tail_SoundSet","AK_InteriorTail_SoundSet"};
			soundSetShotExt[] = {{"AK_silencer_SoundSet","AK_silencerTail_SoundSet","AK_silencerInteriorTail_SoundSet"},{"AK_silencerHomeMade_SoundSet","AK_silencerHomeMadeTail_SoundSet","AK_silencerInteriorHomeMadeTail_SoundSet"}};
			reloadTime = 0.095;
			recoil = "recoil_AKM";
			recoilProne = "recoil_AKM_prone";
			dispersion = 0.0013;
			magazineSlot = "magazine";
		};
		class OpticsInfo: OpticsInfoRifle
		{
			memoryPointCamera = "eye";
			discreteDistance[] = {100,200,300,400,500,600,700,800,900,1000};
			discreteDistanceInitIndex = 0;
			modelOptics = "-";
			distanceZoomMin = 100;
			distanceZoomMax = 1000;
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 220;
					healthLevels[] = 
					{
						{1.0,{"BastionMod\BastionGuns\AK12\data\ak12.rvmat","BastionMod\BastionGuns\AK12\data\stock.rvmat"}},
						{0.7,{"BastionMod\BastionGuns\AK12\data\ak12.rvmat","BastionMod\BastionGuns\AK12\data\stock.rvmat"}},
						{0.5,{"BastionMod\BastionGuns\AK12\data\ak12_damage.rvmat","BastionMod\BastionGuns\AK12\data\stock_damage.rvmat"}},
						{0.3,{"BastionMod\BastionGuns\AK12\data\ak12_damage.rvmat","BastionMod\BastionGuns\AK12\data\stock_damage.rvmat"}},
						{0.0,{"BastionMod\BastionGuns\AK12\data\ak12_destruct.rvmat","BastionMod\BastionGuns\AK12\data\stock_destruct.rvmat"}}
					};
				};
			};
		};		
		class Particles
		{
			class OnFire
			{
				class SmokeCloud
				{
					overrideParticle = "weapon_shot_winded_smoke";
				};
				class MuzzleFlash
				{
					overrideParticle = "weapon_shot_akm_01";
					ignoreIfSuppressed = 1;
					illuminateWorld = 1;
					positionOffset[] = {-0.05,0,0};
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
				maxOverheatingValue = 100;
				shotsToStartOverheating = 5;
				overheatingDecayInterval = 1;
				class SmokingBarrel1
				{
					overrideParticle = "smoking_barrel_small";
					onlyWithinOverheatLimits[] = {0.0,0.5};
					positionOffset[] = {0.1,0,0};
					onlyWithinRainLimits[] = {0,0.2};
				};
				class SmokingBarrelHot1
				{
					overrideParticle = "smoking_barrel";
					onlyWithinOverheatLimits[] = {0.5,0.8};
					positionOffset[] = {0.1,0,0};
					onlyWithinRainLimits[] = {0,0.2};
				};
				class SmokingBarrelHot3
				{
					overrideParticle = "smoking_barrel_heavy";
					onlyWithinOverheatLimits[] = {0.8,1};
					positionOffset[] = {0.1,0,0};
					onlyWithinRainLimits[] = {0,0.2};
				};
				class SmokingBarrelHotSteamSmall
				{
					overrideParticle = "smoking_barrel_steam_small";
					positionOffset[] = {0.3,0,0};
					onlyWithinRainLimits[] = {0.2,0.5};
				};
				class SmokingBarrelHotSteam
				{
					overrideParticle = "smoking_barrel_steam";
					positionOffset[] = {0.3,0,0};
					onlyWithinRainLimits[] = {0.5,1};
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
	};
	class BRP_AK15: BRP_AK15_Base
	{
		scope = 2;		
	};		
};