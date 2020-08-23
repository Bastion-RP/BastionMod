class CfgPatches
{
	class BRP_AR15Hunting
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
	class BRP_AR15Hunting_Base: Rifle_Base
	{
		scope = 0;
		weight = 3000;
		absorbency = 0.0;
		repairableWithKits[] = {5,1};
		repairCosts[] = {30.0,25.0};
		PPDOFProperties[] = {1,0.5,50,160,4,10};
		WeaponLength = 1.2;
		initSpeedMultiplier = 1.05;
		winchesterTypeOpticsMount = 0;
		chamberSize = 1;
		chamberedRound = "";
		chamberableFrom[] = {"Ammo_556x45","Ammo_556x45Tracer"};
		magazines[] = {"Mag_STANAG_30Rnd","Mag_STANAGCoupled_30Rnd","Mag_CMAG_10Rnd","Mag_CMAG_20Rnd","Mag_CMAG_30Rnd","Mag_CMAG_40Rnd","Mag_CMAG_10Rnd_Green","Mag_CMAG_20Rnd_Green","Mag_CMAG_30Rnd_Green","Mag_CMAG_40Rnd_Green","Mag_CMAG_10Rnd_Black","Mag_CMAG_20Rnd_Black","Mag_CMAG_30Rnd_Black","Mag_CMAG_40Rnd_Black","Doc_Mag_100rndQuadStanag","Mag_Expansion_G36_30Rnd"};
		ejectType = 1;
		recoilModifier[] = {0.8,0.8,0.9};
		swayModifier[] = {2,2,1.1};
		simpleHiddenSelections[] = {"hide_barrel","folding_raised","folding_lowered"};	
		modes[] = {"Single"};
		class Single: Mode_SemiAuto
		{
			soundSetShot[] = {"M4_Shot_SoundSet","M4_Tail_SoundSet","M4_InteriorTail_SoundSet"};
			soundSetShotExt[] = {{"M4_silencer_SoundSet","M4_silencerTail_SoundSet","M4_silencerInteriorTail_SoundSet"},{"M4_silencerHomeMade_SoundSet","M4_silencerHomeMadeTail_SoundSet","M4_silencerInteriorHomeMadeTail_SoundSet"}};
			reloadTime = 0.065;
			recoil = "recoil_m4";
			recoilProne = "recoil_m4_prone";			
			dispersion = 0.0025;
			magazineSlot = "magazine";
		};
		class OpticsInfo: OpticsInfoRifle
		{
			memoryPointCamera = "eye";
			discreteDistance[] = {25};
			discreteDistanceInitIndex = 0;
			modelOptics = "-";
			distanceZoomMin = 25;
			distanceZoomMax = 25;
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
	};
	class BRP_AR15Hunting: BRP_AR15Hunting_Base
	{
		scope = 2;
		displayName = "AR-15 Hunting Carbine";
		descriptionShort = "Aftermarket civilian hunting carbine based on AR-15, fed from a detachable magazine. Uses 5.56x45 rounds.";
		model = "BastionMod\BastionGuns\M4Hunting\m4hunt.p3d";
		itemSize[] = {9,3};
		attachments[] = {"weaponWrap","weaponOptics","suppressorImpro","weaponOpticsHunting","weaponMuzzleM4"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
					healthLevels[] = 
					{
						{1.0,{"BastionMod\BastionGuns\M4Hunting\data\m4huntcarbine.rvmat","BastionMod\BastionGuns\M4Hunting\data\frontscope.rvmat"}},
						{0.7,{"BastionMod\BastionGuns\M4Hunting\data\m4huntcarbine.rvmat","BastionMod\BastionGuns\M4Hunting\data\frontscope.rvmat"}},
						{0.5,{"BastionMod\BastionGuns\M4Hunting\data\m4huntcarbine_damage.rvmat","BastionMod\BastionGuns\M4Hunting\data\frontscope_damage.rvmat"}},
						{0.3,{"BastionMod\BastionGuns\M4Hunting\data\m4huntcarbine_damage.rvmat","BastionMod\BastionGuns\M4Hunting\data\frontscope_damage.rvmat"}},
						{0.0,{"BastionMod\BastionGuns\M4Hunting\data\m4huntcarbine_destruct.rvmat","BastionMod\BastionGuns\M4Hunting\data\frontscope_destruct.rvmat"}}
					};
				};
			};
		};
	};
};
