class CfgPatches
{
	class BRP_G18
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
	class BRP_G18_Base: Pistol_Base
	{
		scope = 0;
		weight = 580;
		absorbency = 0.0;
		repairableWithKits[] = {5,1};
		repairCosts[] = {30.0,25.0};
		PPDOFProperties[] = {};
		WeaponLength = 0.583269;
		chamberSize = 1;
		chamberedRound = "";
		magazines[] = {"BRP_Mag_G18_17rnd","MassG18Mag"};
		chamberableFrom[] = {"Ammo_9x19"};
		ejectType = 1;
		recoilModifier[] = {1.2,1.1,1.05};
		swayModifier[] = {1.1,1.0,0.9};
		modes[] = {"FullAuto","SemiAuto"};
		class SemiAuto: Mode_SemiAuto
		{
			soundSetShot[] = {"Glock19_Shot_SoundSet","Glock19_Tail_SoundSet","Glock19_InteriorTail_SoundSet"};
			soundSetShotExt[] = {{"Glock19_silencerPro_SoundSet","Glock19_silencerTail_SoundSet","Glock19_silencerInteriorTail_SoundSet"}};
			reloadTime = 0.11;
			recoil = "recoil_Glock";
			recoilProne = "recoil_Glock_prone";
			dispersion = 0.006;
			magazineSlot = "magazine";
		};
		class FullAuto: Mode_FullAuto
		{
			soundSetShot[] = {"Glock19_Shot_SoundSet","Glock19_Tail_SoundSet","Glock19_InteriorTail_SoundSet"};
			soundSetShotExt[] = {{"Glock19_silencerPro_SoundSet","Glock19_silencerTail_SoundSet","Glock19_silencerInteriorTail_SoundSet"}};
			reloadTime = 0.05;
			recoil = "recoil_Glock";
			recoilProne = "recoil_Glock_prone";
			dispersion = 0.006;
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
	class BRP_G18: BRP_G18_Base
	{
		scope = 2;
		displayName = "Glock 18";
		descriptionShort = "Austrian 9x19 mm Parabellum automatic pistol. It is intended for arming special units of army and police.";
		model = "BastionMod\BastionGuns\G18\g18.p3d";
		attachments[] = {"pistolMuzzle"};
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
						{1.0,{"BastionMod\BastionGuns\G18\data\g18.rvmat"}},
						{0.7,{"BastionMod\BastionGuns\G18\data\g18.rvmat"}},
						{0.5,{"BastionMod\BastionGuns\G18\data\g18_damage.rvmat"}},
						{0.3,{"BastionMod\BastionGuns\G18\data\g18_damage.rvmat"}},
						{0.0,{"BastionMod\BastionGuns\G18\data\g18_destruct.rvmat"}}
					};
				};
			};
		};
	};
};

class cfgMagazines
{
	class Magazine_Base;
	class BRP_Mag_G18_17rnd: Magazine_Base
	{
		scope = 2;
		displayName = "17rd Glock 18 Mag";
		descriptionShort = "Detachable box magazine for the Glock 18. Holds up to 17 rounds of 9x19mm.";
		model = "BastionMod\BastionGuns\G18\g18_mag.p3d";
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
						{1.0,{"BastionMod\BastionGuns\G18\data\g18.rvmat"}},
						{0.7,{"BastionMod\BastionGuns\G18\data\g18.rvmat"}},
						{0.5,{"BastionMod\BastionGuns\G18\data\g18_damage.rvmat"}},
						{0.3,{"BastionMod\BastionGuns\G18\data\g18_damage.rvmat"}},
						{0.0,{"BastionMod\BastionGuns\G18\data\g18_destruct.rvmat"}}
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
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class Proxyg18_mag: ProxyAttachment
	{
		scope = 0;
		inventorySlot = "magazine";
		model = "BastionMod\BastionGuns\G18\g18_mag.p3d";
	};
};
