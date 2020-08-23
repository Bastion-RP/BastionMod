class CfgPatches
{
	class BRP_ACR
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Weapons_Firearms"};
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
	class BRP_ACR_Base: Rifle_Base
	{
		scope = 0;
		weight = 3600;
		absorbency = 0.0;
		repairableWithKits[] = {5,1};
		repairCosts[] = {30.0,25.0};
		PPDOFProperties[] = {1,0.5,20,170,4,10};
		WeaponLength = 0.829067;
		chamberSize = 1;
		chamberedRound = "";
		chamberableFrom[] = {"Ammo_556x45","Ammo_556x45Tracer"};
		magazines[] = {"Mag_STANAG_30Rnd","Mag_STANAGCoupled_30Rnd","Mag_CMAG_10Rnd","Mag_CMAG_20Rnd","Mag_CMAG_30Rnd","Mag_CMAG_40Rnd","Mag_CMAG_10Rnd_Green","Mag_CMAG_20Rnd_Green","Mag_CMAG_30Rnd_Green","Mag_CMAG_40Rnd_Green","Mag_CMAG_10Rnd_Black","Mag_CMAG_20Rnd_Black","Mag_CMAG_30Rnd_Black","Mag_CMAG_40Rnd_Black","Doc_Mag_100rndQuadStanag","Mag_Expansion_G36_30Rnd"};
		magazineSwitchTime = 0.7;
		ejectType = 1;
		recoilModifier[] = {0.5,0.5,0.5};
		swayModifier[] = {1.5,1.5,0.9};
		simpleHiddenSelections[] = {"hide_barrel","folding_raised","folding_lowered"};	
		modes[] = {"FullAuto","SemiAuto"};
		class SemiAuto: Mode_SemiAuto
		{
			soundSetShot[] = {"AUG_Shot_SoundSet","AUG_Tail_SoundSet","AUG_InteriorTail_SoundSet"};
			soundSetShotExt[] = {{"AUG_silencer_SoundSet","AUG_silencerTail_SoundSet","AUG_silencerInteriorTail_SoundSet"},{"AUG_silencerHomeMade_SoundSet","AUG_silencerHomeMadeTail_SoundSet","AUG_silencerInteriorHomeMadeTail_SoundSet"}};
			reloadTime = 0.1;
			recoil = "recoil_m4";
			recoilProne = "recoil_m4_prone";
			dispersion = 0.0015;
			magazineSlot = "magazine";
		};
		class FullAuto: Mode_FullAuto
		{
			soundSetShot[] = {"AUG_Shot_SoundSet","AUG_Tail_SoundSet","AUG_InteriorTail_SoundSet"};
			soundSetShotExt[] = {{"AUG_silencer_SoundSet","AUG_silencerTail_SoundSet","AUG_silencerInteriorTail_SoundSet"},{"AUG_silencerHomeMade_SoundSet","AUG_silencerHomeMadeTail_SoundSet","AUG_silencerInteriorHomeMadeTail_SoundSet"}};
			reloadTime = 0.06;
			recoil = "recoil_m4";
			recoilProne = "recoil_m4_prone";
			dispersion = 0.0015;
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
				maxOverheatingValue = 60;
				shotsToStartOverheating = 7;
				overheatingDecayInterval = 1;
				class SmokingBarrel1
				{
					positionOffset[] = {0.2,0,0};
					overrideParticle = "smoking_barrel_small";
					onlyWithinOverheatLimits[] = {0.0,0.2};
					onlyWithinRainLimits[] = {0,0.2};
				};
				class SmokingBarrelHot1
				{
					positionOffset[] = {0.2,0,0};
					overrideParticle = "smoking_barrel";
					onlyWithinOverheatLimits[] = {0.2,0.6};
					onlyWithinRainLimits[] = {0,0.2};
				};
				class SmokingBarrelHot3
				{
					positionOffset[] = {0.2,0,0};
					overrideParticle = "smoking_barrel_heavy";
					onlyWithinOverheatLimits[] = {0.6,1};
					onlyWithinRainLimits[] = {0,0.2};
				};
				class SmokingBarrelHotSteam
				{
					overrideParticle = "smoking_barrel_steam";
					positionOffset[] = {0.35,0,0};
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
					hitpoints = 220;
					healthLevels[] = 
					{
						{1.0,{"BastionMod\BastionGuns\ACR\data\acr_01.rvmat","BastionMod\BastionGuns\ACR\data\acr_02.rvmat"}},
						{0.7,{"BastionMod\BastionGuns\ACR\data\acr_01.rvmat","BastionMod\BastionGuns\ACR\data\acr_02.rvmat"}},
						{0.5,{"BastionMod\BastionGuns\ACR\data\acr_01_damage.rvmat","BastionMod\BastionGuns\ACR\data\acr_02_damage.rvmat"}},
						{0.3,{"BastionMod\BastionGuns\ACR\data\acr_01_damage.rvmat","BastionMod\BastionGuns\ACR\data\acr_02_damage.rvmat"}},
						{0.0,{"BastionMod\BastionGuns\ACR\data\acr_01_destruct.rvmat","BastionMod\BastionGuns\ACR\data\acr_02_destruct.rvmat"}}
					};
				};
			};
		};	
	};
	class BRP_ACR_Tan: BRP_ACR_Base
	{
		scope = 2;
		displayName = "ACR";
		descriptionShort = "The Adaptive Combat Rifle is a modular assault rifle designed by Magpul Industries of Austin, Texas, and known initially as the Masada. Uses STANAG magazines with 5.56x45 rounds.";
		model = "BastionMod\BastionGuns\ACR\acr.p3d";
		attachments[] = {"weaponWrap","weaponOptics","suppressorImpro","weaponOpticsHunting","weaponMuzzleM4"};
		itemSize[] = {8,3};
	};
};