class CfgPatches
{
	class BRP_MP5SD
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
	class BRP_MP5SD_Base: Rifle_Base
	{
		scope = 0;
		weight = 3400;
		absorbency = 0.0;
		repairableWithKits[] = {5,1};
		repairCosts[] = {30.0,25.0};
		PPDOFProperties[] = {1,0.75,40,180,4,10};
		WeaponLength = 0.683269;
		chamberSize = 1;
		chamberedRound = "";
		chamberableFrom[] = {"Ammo_9x19"};
		magazines[] = {"Mag_MP5_15Rnd","Mag_MP5_30Rnd"};
		magazineSwitchTime = 0.5;
		ejectType = 1;
		recoilModifier[] = {0.7,0.7,0.7};
		swayModifier[] = {1.2,1.2,1};
		modes[] = {"FullAuto","SemiAuto"};
		class SemiAuto: Mode_SemiAuto
		{
			soundSetShot[] = {"PB6P9_silencerPro_SoundSet","PB6P9_silencerTail_SoundSet","PB6P9_silencerInteriorTail_SoundSet"};
			reloadTime = 0.125;
			recoil = "recoil_mp5";
			recoilProne = "recoil_mp5_prone";
			dispersion = 0.0025;
			magazineSlot = "magazine";
		};
		class FullAuto: Mode_FullAuto
		{
			soundSetShot[] = {"PB6P9_silencerPro_SoundSet","PB6P9_silencerTail_SoundSet","PB6P9_silencerInteriorTail_SoundSet"};
			reloadTime = 0.06;
			recoil = "recoil_mp5";
			recoilProne = "recoil_mp5_prone";
			dispersion = 0.0025;
			magazineSlot = "magazine";
		};	
		class NoiseShoot
		{
			strength = 3.0;
			type = "shot";
		};		
		class OpticsInfo: OpticsInfoRifle
		{
			memoryPointCamera = "eye";
			modelOptics = "-";
			distanceZoomMin = 25;
			distanceZoomMax = 150;
			discreteDistance[] = {25,50,100,150};
			discreteDistanceInitIndex = 0;
		};
		class Particles
		{
			class OnFire
			{
				class MuzzleFlash
				{
					overrideParticle = "weapon_shot_fnx_02";
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
						{1.0,{"BastionMod\BastionGuns\MP5SD\data\body.rvmat","BastionMod\BastionGuns\MP5SD\data\hndgrd_a2.rvmat","BastionMod\BastionGuns\MP5SD\data\stck_a1.rvmat"}},
						{0.7,{"BastionMod\BastionGuns\MP5SD\data\body.rvmat","BastionMod\BastionGuns\MP5SD\data\hndgrd_a2.rvmat","BastionMod\BastionGuns\MP5SD\data\stck_a1.rvmat"}},
						{0.5,{"BastionMod\BastionGuns\MP5SD\data\body_damage.rvmat","BastionMod\BastionGuns\MP5SD\data\hndgrd_a2_damage.rvmat","BastionMod\BastionGuns\MP5SD\data\stck_a1_damage.rvmat"}},
						{0.3,{"BastionMod\BastionGuns\MP5SD\data\body_damage.rvmat","BastionMod\BastionGuns\MP5SD\data\hndgrd_a2_damage.rvmat","BastionMod\BastionGuns\MP5SD\data\stck_a1_damage.rvmat"}},
						{0.0,{"BastionMod\BastionGuns\MP5SD\data\body_destruct.rvmat","BastionMod\BastionGuns\MP5SD\data\hndgrd_a2_destruct.rvmat","BastionMod\BastionGuns\MP5SD\data\stck_a1_destruct.rvmat"}}
					};
				};
			};
		};	
	};
	class BRP_MP5SD: BRP_MP5SD_Base
	{
		scope = 2;
		displayName = "MP5SD";
		descriptionShort = "Despite its integrated silencer element, MP5SD  has the same length and shape as an unsilenced submachine gun. Unlike most conventional silenced submachine guns, it fires standard 9x19 ammunition types with the same effect. The use of special subsonic ammunition is not necessary.";
		model = "BastionMod\BastionGuns\MP5SD\mp5sd.p3d";
		attachments[] = {"weaponWrap"};
		itemSize[] = {6,3};
	};
};