class CfgPatches
{
	class BRP_BrowningHP
	{
		units[] = {};
		weapons[] = {"BRP_BrowningHP"};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Pistols"};
		magazines[] = {"BRP_Mag_BrowningHP_13rnd"};
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
	class BRP_BrowningHP_Base: Pistol_Base
	{
		scope = 0;
		displayName = "Browning Hi-Power";
		descriptionShort = "The Browning Hi Power is a single-action, semi-automatic handgun available in the 9mm and .40 S&W calibers. The Hi-Power is one of the most widely used military pistols in history, having been used by the armed forces of over 50 countries. Chambered in 9x19mm rounds.";		
		model = "BastionMod\BastionGuns\BROWNINGHP\BrowningHP.p3d";
		attachments[] = {"pistolMuzzle"};
		itemSize[] = {3,2};
		weight = 950;
		absorbency = 0.0;
		repairableWithKits[] = {1};
		repairCosts[] = {30.0,25.0};
		PPDOFProperties[] = {1,0.5,10,250,4,10};
		WeaponLength = 0.634148;
		barrelArmor = 3.125;
		chamberSize = 1;
		chamberedRound = "";
		magazines[] = {"BRP_Mag_BrowningHP_13rnd"};
		chamberableFrom[] = {"Ammo_9x19"};
		ejectType = 1;
		recoilModifier[] = {0.9,0.9,0.9};
		swayModifier[] = {1.15,1.15,0.7};
		modes[] = {"SemiAuto"};
		class SemiAuto: Mode_SemiAuto
		{
			soundSetShot[] = {"FNX45_Shot_SoundSet","FNX45_Tail_SoundSet","FNX45_InteriorTail_SoundSet"};
			soundSetShotExt[] = {{"FNX45_silencerPro_SoundSet","FNX45_silencerTail_SoundSet","FNX45_silencerInteriorTail_SoundSet"}};
			reloadTime = 0.125;
			recoil = "recoil_fnx";
			recoilProne = "recoil_fnx_prone";
			dispersion = 0.0045;
			magazineSlot = "magazine";
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
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 150;
					healthLevels[] = 
					{
						{1.0,{"BastionMod\BastionGuns\BROWNINGHP\data\browning.rvmat"}},
						{0.7,{"BastionMod\BastionGuns\BROWNINGHP\data\browning.rvmat"}},
						{0.5,{"BastionMod\BastionGuns\BROWNINGHP\data\browning_damage.rvmat"}},
						{0.3,{"BastionMod\BastionGuns\BROWNINGHP\data\browning_damage.rvmat"}},
						{0.0,{"BastionMod\BastionGuns\BROWNINGHP\data\browning_destruct.rvmat"}}
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
	class BRP_BrowningHP: BRP_BrowningHP_Base
	{
		scope = 2;
	};
};
class CfgMagazines
{
	class Magazine_Base;
	class BRP_Mag_BrowningHP_13rnd: Magazine_Base
	{
		scope = 2;
		displayName = "13rnd Browning Hi-Power Magazine";
		descriptionShort = "13 round Magazine for the Browning Hi-Power, loaded with 9x19mm rounds.";
		model = "BastionMod\BastionGuns\BROWNINGHP\mag_BrowningHP_13rnd.p3d";
		weight = 120;
		itemSize[] = {1,2};
		count = 13;
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
						{1.0,{"BastionMod\BastionGuns\BROWNINGHP\data\browning.rvmat"}},
						{0.7,{"BastionMod\BastionGuns\BROWNINGHP\data\browning.rvmat"}},
						{0.5,{"BastionMod\BastionGuns\BROWNINGHP\data\browning_damage.rvmat"}},
						{0.3,{"BastionMod\BastionGuns\BROWNINGHP\data\browning_damage.rvmat"}},
						{0.0,{"BastionMod\BastionGuns\BROWNINGHP\data\browning_destruct.rvmat"}}
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
