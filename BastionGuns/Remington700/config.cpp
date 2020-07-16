class CfgPatches
{
	class BRP_R700
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Weapons_Firearms"};
		magazines[] = {};
		ammo[] = {};
	};
};
class Mode_Safe;
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class OpticsInfoRifle;
class cfgWeapons
{
	class BoltActionRifle_InnerMagazine_Base;
	class BRP_R700_Base: BoltActionRifle_InnerMagazine_Base
	{
		scope = 0;
		displayName = "Remington 700";
		descriptionShort = "Remington 700 is a bolt-action rifle manufactured by Remington Arms since 1962. The M24 and M40 military sniper rifles, used by the US Army and USMC, respectively, are both based on the Model 700 design. Chambered in 7.62×51mm (.308) NATO.";
		animName = "Winchester70";
		weight = 4080;
		absorbency = 0.0;
		repairableWithKits[] = {5,1};
		repairCosts[] = {30.0,25.0};
		PPDOFProperties[] = {1,0.5,20,170,4,10};
		WeaponLength = 0.931718;
		winchesterTypeOpticsMount = 1;		
		chamberSize = 5;
		chamberedRound = "";
		chamberableFrom[] = {"Ammo_308Win","Ammo_308WinTracer"};
		magazines[] = {};
		DisplayMagazine = 0;
		ejectType = 0;
		recoilModifier[] = {0.9,0.9,0.9};
		swayModifier[] = {2.0,2.0,1.0};
		simpleHiddenSelections[] = {"hide_barrel"};
		drySound[] = {"dz\sounds\weapons\firearms\mosin9130\mosin_dry",0.5,1,20};
		reloadAction = "ReloadWinchester70";
		shotAction = "ReloadWinchester70_shot";
		hiddenSelections[] = {"color"};
		modes[] = {"Single"};
		class Single: Mode_SemiAuto
		{
			soundSetShot[] = {"Magnum_Shot_SoundSet","Magnum_Tail_SoundSet","Magnum_InteriorTail_SoundSet"};
			soundSetShotExt[] = {{"Win_silencerHomeMade_SoundSet","Win_silencerHomeMadeTail_SoundSet","Win_silencerInteriorHomeMadeTail_SoundSet"}};
			reloadTime = 1.3;
			recoil = "recoil_Winchester";
			recoilProne = "recoil_Winchester_prone";
			dispersion = 0.0006;
			magazineSlot = "magazine";
		};
		class OpticsInfo: OpticsInfoRifle
		{
			memoryPointCamera = "eye";
			discreteDistance[] = {200};
			discreteDistanceInitIndex = 0;
			modelOptics = "-";
			distanceZoomMin = 200;
			distanceZoomMax = 200;
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
						{1.0,{"BastionMod\BastionGuns\Remington700\data\rem700.rvmat"}},
						{0.7,{"BastionMod\BastionGuns\Remington700\data\rem700.rvmat"}},
						{0.5,{"BastionMod\BastionGuns\Remington700\data\rem700_damage.rvmat"}},
						{0.3,{"BastionMod\BastionGuns\Remington700\data\rem700_damage.rvmat"}},
						{0.0,{"BastionMod\BastionGuns\Remington700\data\rem700_destruct.rvmat"}}
					};
				};
			};
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
					overrideParticle = "weapon_shot_winch70_01";
					ignoreIfSuppressed = 1;
					illuminateWorld = 1;
					positionOffset[] = {0.1,0,0};
				};
			};
			class OnOverheating
			{
				shotsToStartOverheating = 1;
				maxOverheatingValue = 3;
				overheatingDecayInterval = 4;
				class BarrelSmoke
				{
					overrideParticle = "smoking_barrel_small";
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
	class BRP_R700: BRP_R700_Base
	{
		scope = 2;
		model = "BastionMod\BastionGuns\Remington700\r700.p3d";
		attachments[] = {"weaponWrap","weaponOpticsHunting","suppressorImpro"};
		itemSize[] = {10,3};
	};
};
