class CfgPatches
{
	class BRP_Taser_Base
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Pistols","DZ_Weapons_Ammunition","DZ_Weapons_Projectiles"};
		magazines[] = {};
	};
};

class Mode_SemiAuto;
class OpticsInfoPistol;
class cfgWeapons
{
	class Pistol_Base;
	class BRP_Taser_Base: Pistol_Base
	{
		scope = 0;
		weight = 350;
		absorbency = 0;
		repairableWithKits[] = {5,1};
		repairCosts[] = {30,25};
		PPDOFProperties[] = {0,0,0,0,0,0};
		WeaponLength = 0.634148;
		chamberSize = 1;
		chamberedRound = "";
		magazines[] = {"BRP_Taser_Cartridge"};
		chamberableFrom[] = {"Ammo_Taser"};
		ejectType = 1;
		recoilModifier[] = {0.1,0.1,0.1};
		swayModifier[] = {1.2,1.2,0.8};		
		modes[] = {"SemiAuto"};
		class SemiAuto: Mode_SemiAuto
		{
			soundSetShot[] = {"Shockpistol_Shot_SoundSet","Shockpistol_Tail_SoundSet","Shockpistol_InteriorTail_SoundSet"};
			reloadTime = 0.125;
			recoil = "recoil_cz75";
			recoilProne = "recoil_cz75_prone";
			dispersion = 0.006;
			magazineSlot = "magazine";
		};
		class Particles
		{
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
		};
		class OpticsInfo: OpticsInfoPistol
		{
			memoryPointCamera = "eye";
			discreteDistance[] = {20};
			discreteDistanceInitIndex = 0;
			modelOptics = "-";
			distanceZoomMin = 20;
			distanceZoomMax = 20;
		};		
	};
	class BRP_Taser: BRP_Taser_Base
	{
		scope = 2;
		displayName = "Taser";
		descriptionShort = "Its a Taser.";
		model = "\BastionMod\BastionGuns\Taser\BRP_Taser.p3d";
		itemSize[] = {3,2};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = 
					{
						{1.0,{"BastionMod\BastionGuns\Taser\Data\Taser.rvmat"}},
						{0.7,{"BastionMod\BastionGuns\Taser\Data\Taser.rvmat"}},
						{0.5,{"BastionMod\BastionGuns\Taser\Data\Taser_damage.rvmat"}},
						{0.3,{"BastionMod\BastionGuns\Taser\Data\Taser_damage.rvmat"}},
						{0.0,{"BastionMod\BastionGuns\Taser\Data\Taser_destruct.rvmat"}}
					};
				};
			};
		};
	};
};

class CfgMagazines
{
	class Magazine_Base;
	class BRP_Taser_Cartridge: Magazine_Base
	{
		scope = 2;
		displayName = "Taser cartridge";
		descriptionShort = "Taser Cartridge with 4 uses (4 prongs).";
		model = "BastionMod\BastionGuns\Taser\BRP_Taser_Cartridge.p3d";
		weight = 230;
		itemSize[] = {1,2};
		count = 4;
		ammo = "Bullet_Taser";
		ammoItems[] = {"Ammo_Taser"};
		tracersEvery = 0;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 30;
					healthLevels[] = 
					{
						{1.0,{"BastionMod\BastionGuns\Taser\Data\Taser.rvmat"}},
						{0.7,{"BastionMod\BastionGuns\Taser\Data\Taser.rvmat"}},
						{0.5,{"BastionMod\BastionGuns\Taser\Data\Taser_damage.rvmat"}},
						{0.3,{"BastionMod\BastionGuns\Taser\Data\Taser_damage.rvmat"}},
						{0.0,{"BastionMod\BastionGuns\Taser\Data\Taser_destruct.rvmat"}}
					};
				};
			};
		};		
	};
	class Ammunition_Base;
	class Ammo_Taser: Ammunition_Base
	{
		scope=2;
		displayName="Taser Prongs";
		descriptionShort="Taser Prongs to go into a taser cartridge.";
		model = "\dz\weapons\ammunition\22_LooseRounds.p3d";
		iconCartridge = 1;		
		rotationFlags=34;
		weight=6;
		count=4;
		ammo = "Bullet_Taser";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\ammunition\data\22lr.rvmat"}},{0.7,{"DZ\weapons\ammunition\data\22lr.rvmat"}},{0.5,{"DZ\weapons\ammunition\data\22lr_damage.rvmat"}},{0.3,{"DZ\weapons\ammunition\data\22lr_damage.rvmat"}},{0.0,{"DZ\weapons\ammunition\data\22lr_destruct.rvmat"}}};
				};
			};
		};
	};
};

class cfgAmmoTypes
{
	class AType_Bullet_Taser
	{
		name="Bullet_Taser";
	};	
};
	
class cfgAmmo
	{
	class Bullet_Base;
	class Bullet_Taser: Bullet_Base
	{
		scope=2;
		timeToLive = 0.3;		
		casing = "FxCartridge_22";
		round = "FxRound_22";
		spawnPileType="Ammo_Taser";
		hit=4.5;
		indirectHit=0;
		indirectHitRange=0;
		tracerScale=0.6;
		caliber=0.7;
		deflecting=30;
		typicalSpeed=200;
		airFriction=-0.1;
		supersonicCrackNear[]={};
		supersonicCrackFar[]={};
		initSpeed=500;
		weight=0.0025;
		class DamageApplied 
		{
			type = "Projectile";
			dispersion = 0.05;
			bleedThreshold = 0.0;
			class Health
			{
				damage = 0;
			};
			class Blood
			{
				damage = 0;
			};
			class Shock
			{
				damage = 1000;
			};
		};
		class NoiseHit
		{
			strength = 1;
			type = "shot";
		};		
    };
};
