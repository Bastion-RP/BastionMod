class CfgPatches
{
	class BRP_M9A3
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Pistols"};
		magazines[] = {};
		ammo[] = {};
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
	class BRP_M9A3_Base: Pistol_Base
	{
		scope = 0;
		weight = 994;
		absorbency = 0.0;
		repairableWithKits[] = {5,1};
		repairCosts[] = {30.0,25.0};
		PPDOFProperties[] = {};
		WeaponLength = 0.6;
		chamberSize = 1;
		chamberedRound = "";
		magazines[] = {"BRP_Mag_M9A3_17rnd"};
		chamberableFrom[] = {"Ammo_9x19"};
		ejectType = 1;
		recoilModifier[] = {1,1,1};
		swayModifier[] = {1.1,1.1,0.6};
		modes[] = {"SemiAuto"};
		class SemiAuto: Mode_SemiAuto
		{
			soundSetShot[] = {"PM73_Shot_SoundSet","PM73_Tail_SoundSet","PM73_InteriorTail_SoundSet"};
			soundSetShotExt[] = {{"Red9_silencerHomeMade_SoundSet","Red9_silencerHomeMadeTail_SoundSet","Red9_silencerInteriorHomeMadeTail_SoundSet"}};
			reloadTime = 0.1;
			recoil = "recoil_cz75";
			recoilProne = "recoil_cz75_prone";
			dispersion = 0.004;
			magazineSlot = "magazine";
		};
		class Particles
		{
			class OnFire
			{
				class MuzzleFlashForward
				{
					ignoreIfSuppressed = 1;
					illuminateWorld = 1;
					overrideParticle = "weapon_shot_cz75_01";
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
		class OpticsInfo: OpticsInfoPistol
		{
			memoryPointCamera = "eye";
			discreteDistance[] = {25};
			discreteDistanceInitIndex = 0;
			modelOptics = "-";
			distanceZoomMin = 25;
			distanceZoomMax = 25;
		};
	};
	class BRP_M9A3: BRP_M9A3_Base
	{
		scope = 2;
		displayName = "M9A3";
		descriptionShort = "M9A3 is a semiautomatic pistol, an updated version of well-known M9. Fed from detachable magazines, 9x19 caliber.";
		model = "BastionMod\BastionGuns\M9A3\m9a3.p3d";
		attachments[] = {"pistolFlashlight","pistolMuzzle"};
		itemSize[] = {3,2};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = 	
					{					
						{1.0,{"BastionMod\BastionGuns\M9A3\data\m9a3.rvmat"}},
						{0.7,{"BastionMod\BastionGuns\M9A3\data\m9a3.rvmat"}},
						{0.5,{"BastionMod\BastionGuns\M9A3\data\m9a3_damage.rvmat"}},
						{0.3,{"BastionMod\BastionGuns\M9A3\data\m9a3_damage.rvmat"}},
						{0.0,{"BastionMod\BastionGuns\M9A3\data\m9a3_destruct.rvmat"}}
					};
				};
			};
		};
	};
};

class cfgMagazines
{
	class Magazine_Base;
	class BRP_Mag_M9A3_17rnd: Magazine_Base
	{
		scope = 2;
		displayName = "17rd M9A3 Mag";
		descriptionShort = "Detachable box magazine for the M9A3. Holds up to 17 rounds of 9x19mm.";
		model = "BastionMod\BastionGuns\M9A3\m9a3_mag.p3d";
		weight = 151;
		itemSize[] = {1,2};
		count = 17;
		ammo = "Bullet_9x19";
		ammoItems[] = {"Ammo_9x19"};
		tracersEvery = 0;
		mass = 10;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = 
					{
						{1.0,{"BastionMod\BastionGuns\M9A3\data\m9a3.rvmat"}},
						{0.7,{"BastionMod\BastionGuns\M9A3\data\m9a3.rvmat"}},
						{0.5,{"BastionMod\BastionGuns\M9A3\data\m9a3_damage.rvmat"}},
						{0.3,{"BastionMod\BastionGuns\M9A3\data\m9a3_damage.rvmat"}},
						{0.0,{"BastionMod\BastionGuns\M9A3\data\m9a3_destruct.rvmat"}}
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