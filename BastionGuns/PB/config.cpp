class CfgPatches
{
	class BRP_PB
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Pistols","DZ_Weapons_Magazines"};
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
	class BRP_PB_Base: Pistol_Base
	{
		scope = 0;
		weight = 900;
		absorbency = 0.0;
		repairableWithKits[] = {5,1};
		repairCosts[] = {30.0,25.0};
		PPDOFProperties[] = {1,0.5,10,280,4,10};
		WeaponLength = 0.560518;
		chamberSize = 1;
		chamberedRound = "";
		magazines[] = {"BRP_Mag_PB_8Rnd"};
		chamberableFrom[] = {"Ammo_380"};
		ejectType = 1;
		recoilModifier[] = {1,1,1};
		swayModifier[] = {1,1,0.7};
		modes[] = {"SemiAuto"};
		hiddenSelections[] = {"zasleh"};		
		class SemiAuto: Mode_SemiAuto
		{
			soundSetShot[] = {"PB6P9_silencerPro_SoundSet","PB6P9_silencerTail_SoundSet","PB6P9_silencerInteriorTail_SoundSet"};
			reloadTime = 0.125;
			recoil = "recoil_ij70";
			recoilProne = "recoil_if70_prone";
			dispersion = 0.006;
			magazineSlot = "magazine";
		};
		class NoiseShoot
		{
			strength = 3.5;
			type = "shot";
		};		
		class Particles
		{
			class OnFire
			{
				class MuzzleFlash
				{
					illuminateWorld = 0;
					overrideParticle = "weapon_shot_vss_01";
				};
				class SmokeCloud
				{
					overrideParticle = "weapon_shot_winded_smoke_small";
				};
			};
			class OnOverheating
			{
				shotsToStartOverheating = 3;
				maxOverheatingValue = 7;
				overheatingDecayInterval = 1;
				class OpenChamberSmoke
				{
					onlyIfBoltIsOpen = 1;
					overrideParticle = "smoking_barrel_small";
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
			distanceZoomMin = 100;
			distanceZoomMax = 100;
		};
	};
	class BRP_PB: BRP_PB_Base
	{
		scope = 2;
		displayName = "6P9 Makarov PB";
		descriptionShort = "A compact, easy to operate, and highly accurate, suppressed pistol which was based on the Makarov pistol design.";
		model = "\DZ\weapons\pistols\pb6p9\pb6p9.p3d";
//		attachments[] = {"pistolMuzzle"};
		itemSize[] = {4,2};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = 
					{
						{1.0,{"DZ\weapons\pistols\pb6p9\data\pb6p9.rvmat"}},
						{0.7,{"DZ\weapons\pistols\pb6p9\data\pb6p9.rvmat"}},
						{0.5,{"DZ\weapons\pistols\pb6p9\data\pb6p9_damage.rvmat"}},
						{0.3,{"DZ\weapons\pistols\pb6p9\data\pb6p9_damage.rvmat"}},
						{0.0,{"DZ\weapons\pistols\pb6p9\data\pb6p9_destruct.rvmat"}}
					};
				};
			};
		};
	};
};
class CfgMagazines
{
	class Magazine_Base;
	class BRP_Mag_PB_8Rnd: Magazine_Base
	{
		scope = 2;
		displayName = "Makarov PB6P9 magazine";
		descriptionShort = "A magazine for the Makarov PB6P9 pistol which holds 8 rounds of .380 Auto.";
		model = "\DZ\weapons\attachments\magazine\magazine_pb6p9.p3d";
		weight = 131;
		itemSize[] = {1,2};
		count = 8;
		ammo = "Bullet_380";
		ammoItems[] = {"Ammo_380"};
		tracersEvery = 0;
		mass = 10;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\attachments\magazine\data\magazine_pb6p9.rvmat"}},{0.7,{"DZ\weapons\attachments\magazine\data\magazine_pb6p9.rvmat"}},{0.5,{"DZ\weapons\attachments\magazine\data\magazine_pb6p9_damage.rvmat"}},{0.3,{"DZ\weapons\attachments\magazine\data\magazine_pb6p9_damage.rvmat"}},{0.0,{"DZ\weapons\attachments\magazine\data\magazine_pb6p9_destruct.rvmat"}}};
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
	class Proxymagazine_pb6p9: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "magazine";
		model = "\DZ\weapons\attachments\magazine\magazine_pb6p9.p3d";
	};
};