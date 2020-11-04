class CfgPatches
{
	class BRP_P99
	{
		units[] = {};
		weapons[] = {"BRP_P99"};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Pistols"};
		magazines[] = {"BRP_Mag_P99_15rnd"};
	};
};
class Mode_Safe;
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class OpticsInfoPistol;
class cfgWeapons
{
	class Pistol_Base;
	class BRP_P99: Pistol_Base
	{
		scope = 2;
		displayName = "Walther P99";
		descriptionShort = "The Walther P99 is a semi-automatic pistol, chambered in 9x19mm, developed by the German company Carl Walther GmbH Sportwaffen of Ulm for law enforcement, security forces and the civilian shooting market as a replacement for the Walther P5 and the P88. The P99 and its variants are also made under licence by Fabryka Broni Radom.";
		model = "BastionMod\BastionGuns\P99\P99.p3d";
		attachments[] = {};
		magazines[] = {"BRP_Mag_P99_15rnd"};
		itemSize[] = {3,2};
		chamberableFrom[] = {"Ammo_9x19"};		
		weight = 950;
		absorbency = 0;	
		repairableWithKits[] = {1};
		repairCosts[] = {30,25};
		PPDOFProperties[] = {1,0.5,10,250,4,10};
		WeaponLength = 0.634148;
		barrelArmor = 2.018;		
		chamberSize = 1;
		chamberedRound = "";	
		ejectType = 1;
		recoilModifier[] = {0.95,0.95,0.95};
		swayModifier[] = {1.15,1.15,0.76};		
		modes[] = {"SemiAuto"};				
		class SemiAuto: Mode_SemiAuto
		{
			soundSetShot[] = {"CZ75_Shot_SoundSet","CZ75_Tail_SoundSet","CZ75_InteriorTail_SoundSet"};
			soundSetShotExt[] = {{"CZ75_silencerPro_SoundSet","CZ75_silencerTail_SoundSet","CZ75_silencerInteriorTail_SoundSet"}};
			reloadTime = 0.1;
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
						{1.0,{"BastionMod\BastionGuns\P99\data\p99.rvmat"}},
						{0.7,{"BastionMod\BastionGuns\P99\data\p99.rvmat"}},
						{0.5,{"BastionMod\BastionGuns\P99\data\p99_damage.rvmat"}},
						{0.3,{"BastionMod\BastionGuns\P99\data\p99_damage.rvmat"}},
						{0.0,{"BastionMod\BastionGuns\P99\data\p99_destruct.rvmat"}}
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
};
class CfgMagazines
{
	class Magazine_Base;
	class BRP_Mag_P99_15rnd: Magazine_Base
	{
		scope = 2;
		displayName = "15rnd P99 Magazine";
		descriptionShort = "15 round Magazine for the P99, loaded with 9x19mm rounds.";
		model = "BastionMod\BastionGuns\P99\mag_P99_10rnd.p3d";
		weight = 100;
		itemSize[] = {1,2};
		count = 15;
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
						{1.0,{"BastionMod\BastionGuns\P99\data\p99.rvmat"}},
						{0.7,{"BastionMod\BastionGuns\P99\data\p99.rvmat"}},
						{0.5,{"BastionMod\BastionGuns\P99\data\p99_damage.rvmat"}},
						{0.3,{"BastionMod\BastionGuns\P99\data\p99_damage.rvmat"}},
						{0.0,{"BastionMod\BastionGuns\P99\data\p99_destruct.rvmat"}}
					};
				};
			};
		};				
	};	
};
