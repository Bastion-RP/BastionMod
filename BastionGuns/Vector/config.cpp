class CfgPatches
{
	class BRP_Vector
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Weapons_Firearms","DZ_Weapons_Magazines","DZ_Weapons_Muzzles"};
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
	class BRP_Vector_Base: Rifle_Base
	{
		scope = 0;
		model = "BastionMod\BastionGuns\Vector\vector.p3d";
		attachments[] = {"weaponOptics","suppressorKrissVector","weaponWrap"};
		itemSize[] = {6,3};		
		weight = 2500;
		absorbency = 0.0;
		repairableWithKits[] = {1};
		repairCosts[] = {30.0,25.0};
		PPDOFProperties[] = {};
		WeaponLength = 0.583269;
		barrelArmor = 2.667;
		chamberSize = 1;
		chamberedRound = "";
		chamberableFrom[] = {"Ammo_45ACP"};
		magazines[] = {"BRP_Mag_Vector_33rnd"};
		ejectType = 1;
		recoilModifier[] = {0.6,0.6,0.6};
		swayModifier[] = {0.9,0.9,1};
		simpleHiddenSelections[] = {"folding_raised","folding_lowered"};	
		hiddenSelections[] = {"color"};			
		modes[] = {"FullAuto","SemiAuto"};
		class SemiAuto: Mode_SemiAuto
		{
			soundSetShot[] = {"UMP45_Shot_SoundSet","UMP45_Tail_SoundSet","UMP45_InteriorTail_SoundSet"};
			soundSetShotExt[] = {{"UMP45_silencerPro_SoundSet","UMP45_silencerTail_SoundSet","UMP45_silencerInteriorTail_SoundSet"},{"UMP45_silencerHomeMade_SoundSet","UMP45_silencerHomeMadeTail_SoundSet","UMP45_silencerInteriorHomeMadeTail_SoundSet"}};	
			reloadTime = 0.1;
			recoil = "recoil_auto_primary_7outof10";
			recoilProne = "recoil_auto_primary_prone_7outof10";
			dispersion = 0.0035;
			magazineSlot = "magazine";
		};
		class FullAuto: Mode_FullAuto
		{
			soundSetShot[] = {"UMP45_Shot_SoundSet","UMP45_Tail_SoundSet","UMP45_InteriorTail_SoundSet"};
			soundSetShotExt[] = {{"UMP45_silencerPro_SoundSet","UMP45_silencerTail_SoundSet","UMP45_silencerInteriorTail_SoundSet"},{"UMP45_silencerHomeMade_SoundSet","UMP45_silencerHomeMadeTail_SoundSet","UMP45_silencerInteriorHomeMadeTail_SoundSet"}};	
			reloadTime = 0.055;
			recoil = "recoil_auto_primary_7outof10";
			recoilProne = "recoil_auto_primary_prone_7outof10";
			dispersion = 0.0035;
			magazineSlot = "magazine";
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
				shotsToStartOverheating = 10;
				maxOverheatingValue = 30;
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
		class OpticsInfo: OpticsInfoRifle
		{
			memoryPointCamera = "eye";
			modelOptics = "-";
			distanceZoomMin = 25;
			distanceZoomMax = 150;
			discreteDistance[] = {25,50,100,150};
			discreteDistanceInitIndex = 0;
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
						{1.0,{"BastionMod\BastionGuns\Vector\data\vector.rvmat"}},
						{0.7,{"BastionMod\BastionGuns\Vector\data\vector.rvmat"}},
						{0.5,{"BastionMod\BastionGuns\Vector\data\vector_damage.rvmat"}},
						{0.3,{"BastionMod\BastionGuns\Vector\data\vector_damage.rvmat"}},
						{0.0,{"BastionMod\BastionGuns\Vector\data\vector_destruct.rvmat"}}
					};
				};
			};
		};		
	};
	class BRP_Vector: BRP_Vector_Base
	{
		scope = 2;
		displayName = "KRISS Vector";
		descriptionShort = "The KRISS Vector is a series of weapons based upon the parent submachine gun design developed by the American company KRISS USA, formerly Transformational Defense Industries (TDI). Uses .45 ACP rounds.";
		hiddenSelectionsTextures[] = {"BastionMod\BastionGuns\Vector\data\vector_co.paa"};		
	};
};
class cfgMagazines
{
	class Magazine_Base;
	class BRP_Mag_Vector_33rnd : Magazine_Base
	{
		scope = 2;
		displayName = "33rd KRISS Vector Mag";
		descriptionShort = "Detachable box magazine for the KRISS Vector. Holds up to 33 rounds of .45 ACP.";
		model = "BastionMod\BastionGuns\Vector\vector_33rndmag.p3d";
		weight = 50;
		itemSize[] = {1,3};
		count = 33;
		ammo = "Bullet_45ACP";
		ammoItems[] = {"Ammo_45ACP"};
		tracersEvery = 0;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 220;
					healthLevels[] = 
					{
						{1.0,{"BastionMod\BastionGuns\Vector\data\vector.rvmat"}},
						{0.7,{"BastionMod\BastionGuns\Vector\data\vector.rvmat"}},
						{0.5,{"BastionMod\BastionGuns\Vector\data\vector_damage.rvmat"}},
						{0.3,{"BastionMod\BastionGuns\Vector\data\vector_damage.rvmat"}},
						{0.0,{"BastionMod\BastionGuns\Vector\data\vector_destruct.rvmat"}}
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

class cfgVehicles
{
	class ItemSuppressor;
	class BRP_Vector_Suppressor: ItemSuppressor
	{
		scope = 2;
		displayName = "KRISS Vector Suppressor";
		descriptionShort = "KRISS Vector Suppressor.";
		model = "BastionMod\BastionGuns\Vector\vector_suppressor.p3d";
		rotationFlags = 17;
		reversed = 0;
		weight = 200;
		itemSize[] = {3,1};
		itemModelLength = 0.25;
		inventorySlot[] = {"suppressorKrissVector"};
		simulation = "ItemSuppressor";
		dispersionModifier = -0.0001;
		noiseShootModifier = -0.95;
		dispersionCondition = "true";
		barrelArmor = 2500.0;
		recoilModifier[] = {0.95,0.95,0.95};
		swayModifier[] = {1.05,1.05,1};
		soundIndex = 1;
		muzzlePos = "usti hlavne";	
		class Particles
		{
			class OnFire
			{
				class MuzzleFlashAssault
				{
					overrideParticle = "weapon_shot_akm_02";
					onlyWithinHealthLabel[] = {0,3};
				};
				class Ruined
				{
					onlyWithinHealthLabel[] = {4,4};
					illuminateWorld = 1;
				};
			};
			class OnOverheating
			{
				shotsToStartOverheating = 1;
				maxOverheatingValue = 60;
				overheatingDecayInterval = 1;
				class SmokingBarrel
				{
					overrideParticle = "smoking_barrel_small";
					onlyWithinRainLimits[] = {0,0.2};
				};
				class SmokingBarrelHotSteamSmall
				{
					overrideParticle = "smoking_barrel_steam_small";
					positionOffset[] = {0.0,0.1,0};
					onlyWithinRainLimits[] = {0.2,1};
				};
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 4;
					healthLevels[] = 
					{
						{1.0,{"BastionMod\BastionGuns\Vector\data\vector.rvmat"}},
						{0.7,{"BastionMod\BastionGuns\Vector\data\vector.rvmat"}},
						{0.5,{"BastionMod\BastionGuns\Vector\data\vector_damage.rvmat"}},
						{0.3,{"BastionMod\BastionGuns\Vector\data\vector_damage.rvmat"}},
						{0.0,{"BastionMod\BastionGuns\Vector\data\vector_destruct.rvmat"}}
					};
				};
			};
		};
	};	
};

class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxyVector_suppressor: ProxyAttachment
	{
		scope = 0;
		inventorySlot = "suppressorKrissVector";
		model = "BastionMod\BastionGuns\Vector\vector_suppressor.p3d";
	};
};

class CfgSlots
{
	class Slot_suppressorKrissVector
	{
		name = "suppressorKrissVector";
		displayName = "Suppressor";
		ghostIcon = "supressor";
	};
};	
