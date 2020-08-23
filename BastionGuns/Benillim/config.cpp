class CfgPatches
{
	class BRP_CS12G
	{
		units[] = {};
		weapons[] = {"BRP_CS12G"};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Weapons_Firearms","DZ_Weapons_Ammunition","DZ_Weapons_Magazines"};
		magazines[] = {};
		ammo[] = {};
	};
};
class Mode_Safe;
class Mode_Single;
class cfgWeapons
{
	class Mp133Shotgun;
	class BRP_CS12G: Mp133Shotgun
	{
		scope = 2;
		displayName = "CS-12G";
		descriptionShort = "Italian engineered, NCC reproduced semi-automatic shotgun.";
		weight = 2500;
		model = "\BastionMod\BastionGuns\Benillim\Ben4.p3d";
		magazines[] = {};
		itemSize[] = {8,3};
		PPDOFProperties[] = {1,0.6,200000,0.3,3,0.1};
		dexterity = 2.7;
		repairableWithKits[] = {5,1};
		repairCosts[] = {30.0,25.0};
		discreteDistance[] = {25,50,100};
		reloadAction = "ReloadMP133";
		shotAction = "ReloadMP133Shot";
		chamberSize = 6;
		chamberableFrom[] = {"Ammo_12gaPellets","Ammo_12gaSlug","Ammo_12gaRubberSlug","Ammo_12gaBeanbag"};
		attachments[] = {"weaponOptics"};
		modes[] = {"Single"};
		class Single: Mode_Single
		{
			soundSetShot[] = {"Mp133_Shot_SoundSet","Mp133_Tail_SoundSet","Mp133_InteriorTail_SoundSet"};
			reloadTime = 1;
			recoil = "recoil_Mp133";
			recoilProne = "recoil_Mp133_prone";
			dispersion = 0.0015;
			magazineSlot = "magazine";
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
	};
};
