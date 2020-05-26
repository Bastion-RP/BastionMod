class CfgPatches
{
	class CSM762_Base
	{
		units[] = {};
		weapons[] = {"SR25_Black","SR25_Green","SR25_Tan"};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Weapons_Firearms","DZ_Weapons_Ammunition","DZ_Weapons_Magazines"};
		magazines[] = {"SR25_Magazine","SR25_Magazine_Extendo","Mass308STANAG"};
		ammo[] = {};
	};
};

class Mode_Safe;
class Mode_SemiAuto;
class cfgWeapons
{
	class M4A1;
	class CSM762_Base: M4A1
	{
		scope = 0;
		absorbency = 0.1;
		displayName = "SR25";
		descriptionShort = "The SR-25 is a designated marksman rifle/semi-automatic sniper rifle designed by Eugene Stoner and manufactured by Knight's Armament Company. The SR-25 uses a rotating bolt and a direct impingement gas system. It is loosely based on Stoner's AR-10, rebuilt in its original 7.62×51mm NATO caliber.(.308win)";
		model = "BastionMod\BastionGuns\SR-25\SR25.p3d";
		magazines[] = {"SR25_Magazine","Mass308STANAG","SR25_Magazine_Extendo"};
		itemSize[] = {8,3};
		repairableWithKits[] = {5,1};
		repairCosts[] = {30,25};
		PPDOFProperties[] = {1,0.75,40,180,4,10};
		dexterity = 3.0;
		discreteDistance[] = {25,50,100,200,300,1000};
		chamberSize = 1;
		hiddenSelections[] = {"camo"};
		hiddenSelectionsMaterials[] = {"BastionMod\BastionGuns\SR-25\data\SR-25.rvmat"};
		chamberableFrom[] = {"Ammo_308Win","Ammo_308WinTracer"};
		attachments[] = {"weaponOptics","weaponOpticsHunting","weaponWrap","SR25_Suppressor","weaponFlashlight","grip1","grip2"};
		modes[] = {"SemiAuto"};
		class SemiAuto: Mode_SemiAuto
		{
			soundSetShot[] = {"SR25_Shot_SoundSet","SR25_Shot_SoundSet","SR25_Shot_SoundSet"};
			soundSetShotExt[] = {{"SR25_Suppressed_Shot_SoundSet","SR25_Suppressed_Shot_SoundSet","SR25_Suppressed_Shot_SoundSet"},{"SR25_Suppressed_Shot_SoundSet","SR25_Suppressed_Shot_SoundSet","SR25_Suppressed_Shot_SoundSet"}};
			soundBegin[] = {"begin1",0.03,"begin2",0.03,"begin2",0.03};
			reloadTime = 0.125;
			recoil = "recoil_m4";
			recoilProne = "recoil_m4_prone";
			dispersion = 0.0015;
			magazineSlot = "magazine";
			soundBeginExt[] = {{"beginSilenced_Pro1",0.5,"beginSilenced_Pro2",0.5},{"beginSilenced_HomeMade",1}};
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
					overrideParticle = "weapon_shot_ump45_01";
					ignoreIfSuppressed = 1;
					illuminateWorld = 1;
				};
				class ChamberSmoke
				{
					overrideParticle = "weapon_shot_chamber_smoke";
					overridePoint = "Nabojnicestart";
					overrideDirectionPoint = "Nabojniceend";
				};
				class ChamberSmokeRaise
				{
					overrideParticle = "weapon_shot_chamber_smoke_raise";
					overridePoint = "Nabojnicestart";
				};
			};
			class OnOverheating
			{
				maxOverheatingValue = 30;
				shotsToStartOverheating = 10;
				overheatingDecayInterval = 1;
				class SmokingBarrel
				{
					overrideParticle = "smoking_barrel_small";
					positionOffset[] = {0.1,0,0};
					onlyWithinHealthLabel[] = {0,1};
				};
				class SmokingBarrelDamaged
				{
					overrideParticle = "smoking_barrel";
					positionOffset[] = {0.1,0,0};
					onlyWithinHealthLabel[] = {2,4};
				};
				class SmokingBarrelBadlyDamaged
				{
					overridePoint = "Nabojnicestart";
					overrideParticle = "smoking_barrel_small";
					onlyWithinHealthLabel[] = {3,4};
				};
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0,{}}};
				};
			};
		};
	};
	class CSM762_Black: CSM762_Base
	{
		scope = 2;
		displayName = "SR-25 Black";
		hiddenSelectionsTextures[] = {"BastionMod\BastionGuns\SR-25\data\SR-25_Base_Co.paa"};
	};
	class CSM762_Green: CSM762_Base
	{
		scope = 2;
		displayName = "SR-25 Green(Muddy)";
		hiddenSelectionsTextures[] = {"BastionMod\BastionGuns\SR-25\data\SR-25_GreenMud.paa"};
	};
	class CSM762_Tan: CSM762_Base
	{
		scope = 2;
		displayName = "SR-25 Tan";
		hiddenSelectionsTextures[] = {"BastionMod\BastionGuns\SR-25\data\SR-25_Tan.paa"};
	};
};

class CfgMagazines
{
	class Mag_AKM_30Rnd;
	class CM25_Magazine: Mag_AKM_30Rnd
	{
		scope = 2;
		displayName = "SR-25 Magazine";
		descriptionShort = "Magazine for the SR-25.";
		model = "BastionMod\BastionGuns\SR-25\SR25_Magazine.p3d";
		weight = 230;
		itemSize[] = {1,2};
		count = 20;
		ammo = "Bullet_308Win";
		ammoItems[] = {"Ammo_308Win","Ammo_308WinTracer"};
		isMeleeWeapon = 0;
		tracersEvery = 1;
	};
	class CM25_Magazine_Extendo: Mag_AKM_30Rnd
	{
		scope = 2;
		displayName = "SR-25 Extended Magazine";
		descriptionShort = "Extended Magazine for the SR-25.";
		model = "BastionMod\BastionGuns\SR-25\SR25_Magazine_Extendo.p3d";
		weight = 230;
		itemSize[] = {1,3};
		count = 30;
		ammo = "Bullet_308Win";
		ammoItems[] = {"Ammo_308Win","Ammo_308WinTracer"};
		isMeleeWeapon = 0;
		tracersEvery = 1;
	};
};

class CfgSoundShaders
{
	class baseCharacter_SoundShader;
	class base_closeShot_SoundShader;
	class base_midShot_SoundShader;
	class base_distShot_SoundShader;
	class SR25_Shot_SoundShader: base_closeShot_SoundShader
	{
		samples[] = {{"BastionMod\BastionGuns\SR-25\SR25_1",1},{"BastionMod\BastionGuns\SR-25\SR25_2",1},{"BastionMod\BastionGuns\SR-25\SR25_3",1}};
		volume = 1;
	};
	class SR25_midshot_SoundShader: base_midShot_SoundShader
	{
		samples[] = {{"BastionMod\BastionGuns\SR-25\SR25_1",1},{"BastionMod\BastionGuns\SR-25\SR25_2",1},{"BastionMod\BastionGuns\SR-25\SR25_3",1}};
		volume = 0.56234133;
	};
	class SR25_distShot_SoundShader: base_distShot_SoundShader
	{
		samples[] = {{"BastionMod\BastionGuns\SR-25\SR25_1",1},{"BastionMod\BastionGuns\SR-25\SR25_2",1},{"BastionMod\BastionGuns\SR-25\SR25_3",1}};
	};
	class SR25_Suppressed_Shot_SoundShader: base_closeShot_SoundShader
	{
		samples[] = {{"BastionMod\BastionGuns\SR-25\SR25Suppressed",1},{"BastionMod\BastionGuns\SR-25\SR25Suppressed",1},{"BastionMod\BastionGuns\SR-25\SR25Suppressed",1}};
		volume = 0.5;
		range = 50;
		rangeCurve = "closeShotCurve";
	};
	class SR25_Suppressed_midshot_SoundShader: base_midShot_SoundShader
	{
		samples[] = {{"BastionMod\BastionGuns\SR-25\SR25Suppressed",1},{"BastionMod\BastionGuns\SR-25\SR25Suppressed",1},{"BastionMod\BastionGuns\SR-25\SR25Suppressed",1}};
		volume = 0.56234133;
		range = 100;
		rangeCurve[] = {{0,0.2},{50,1},{100,0},{200,0}};
	};
	class SR25_Suppressed_distShot_SoundShader: base_distShot_SoundShader
	{
		samples[] = {{"BastionMod\BastionGuns\SR-25\SR25Suppressed",1},{"BastionMod\BastionGuns\SR-25\SR25Suppressed",1},{"BastionMod\BastionGuns\SR-25\SR25Suppressed",1}};
		range = 200;
		rangeCurve[] = {{0,0.2},{50,1},{100,0},{200,0}};
	};
};
class CfgSoundSets
{
	class Rifle_Shot_Base_SoundSet;
	class rifle_tail_Base_soundset;
	class Rifle_InteriorTail_Base_SoundSet;
	class Rifle_silencerHomemade_Base_SoundSet;
	class Rifle_silencerHomemadeTail_Base_SoundSet;
	class Rifle_silencerInteriorHomeMadeTail_Base_SoundSet;
	class baseCharacter_SoundSet;
	class SR25_Shot_SoundSet: Rifle_Shot_Base_SoundSet
	{
		soundShaders[] = {"SR25_Shot_SoundShader","SR25_midShot_SoundShader","SR25_distShot_SoundShader"};
	};
	class SR25_Suppressed_Shot_SoundSet: Rifle_silencerHomemade_Base_SoundSet
	{
		soundShaders[] = {"SR25_Suppressed_Shot_SoundShader","SR25_Suppressed_midshot_SoundShader","SR25_Suppressed_distShot_SoundShader"};
	};
};


class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxySR25_Suppressor: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "SR25_Suppressor";
		model = "BastionMod\BastionGuns\SR-25\SR25Silencer\SR25_Suppressor.p3d";
	};
	class Proxysr25magazine: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "magazine";
		model = "BastionMod\BastionGuns\SR-25\data\magazine\sr25magazine.p3d";
	};
	class Proxygrip1: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "grip1";
		model = "BastionMod\BastionGuns\Grips\grip1.p3d";
	};
	class Proxygrip2: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "grip2";
		model = "BastionMod\BastionGuns\Grips\grip2.p3d";
	};
};


class CfgSlots
{
	class Slot_SR25_Suppressor
	{
		name = "SR25_Suppressor";
		displayName = "SR25_Suppressor";
		ghostIcon = "supressor";
	};
	class Slot_grip1
	{
		name = "grip1";
		displayName = "grip1";
		ghostIcon = "";
	};
	class Slot_grip2
	{
		name = "grip2";
		displayName = "grip2";
		ghostIcon = "";
	};
};