class CfgPatches
{
	class BRP_BerettaM9
	{
		units[] = {};
		weapons[] = {"BRP_BerettaM9"};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Pistols"};
		magazines[] = {"BRP_Mag_BerettaM9_15rnd"};
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
	class BRP_BerettaM9: Pistol_Base
	{
		scope = 2;
		displayName = "Beretta M9";
		descriptionShort = "The Beretta M9 is the designation for the Beretta 92F semi-automatic pistol used by the United States Armed Forces. The M9 was adopted by the United States military as their service pistol in 1985. Chambered in 9x19mm Rounds.";
		model = "BastionMod\BastionGuns\BERETTA92\Beretta92.p3d";
		attachments[] = {"pistolMuzzle", "pistolFlashlight"};
		magazines[] = {"BRP_Mag_BerettaM9_15rnd","BRP_Mag_M9A3_17rnd"};
		chamberableFrom[] = {"Ammo_9x19"};		
		itemSize[] = {3,2};
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
						{1.0,{"BastionMod\BastionGuns\CSP9\data\csp9.rvmat"}},
						{0.7,{"BastionMod\BastionGuns\CSP9\data\csp9.rvmat"}},
						{0.5,{"BastionMod\BastionGuns\CSP9\data\csp9_damage.rvmat"}},
						{0.3,{"BastionMod\BastionGuns\CSP9\data\csp9_damage.rvmat"}},
						{0.0,{"BastionMod\BastionGuns\CSP9\data\csp9_destruct.rvmat"}}
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
	class BRP_Mag_BerettaM9_15rnd: Magazine_Base
	{
		scope = 2;
		displayName = "15rnd Beretta M9 Magazine";
		descriptionShort = "15 round Magazine for the Beretta M9, loaded with 9x19mm rounds.";
		model = "BastionMod\BastionGuns\BERETTA92\mag_Beretta92_15rnd.p3d";
		weight = 150;
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
						{1.0,{"BastionMod\BastionGuns\CSP9\data\csp9.rvmat"}},
						{0.7,{"BastionMod\BastionGuns\CSP9\data\csp9.rvmat"}},
						{0.5,{"BastionMod\BastionGuns\CSP9\data\csp9_damage.rvmat"}},
						{0.3,{"BastionMod\BastionGuns\CSP9\data\csp9_damage.rvmat"}},
						{0.0,{"BastionMod\BastionGuns\CSP9\data\csp9_destruct.rvmat"}}
					};
				};
			};
		};				
	};
};
