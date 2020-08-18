class CfgPatches
{
	class BRP_Taser_Base
	{
		units[] = {};
		weapons[] = {"BRP_PX4"};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Pistols"};
		magazines[] = {"BRP_Taser_Cartridge"};
	};
};

class Mode_Safe;
class Mode_SemiAuto;
class cfgWeapons
{
	class CZ75;
	class BRP_Taser_Base: CZ75
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
		recoilModifier[] = {1,1,1};
		modes[] = {"SemiAuto"};
		class SemiAuto: Mode_SemiAuto
		{
			soundSetShot[] = {"Shockpistol_Shot_SoundSet","Shockpistol_Tail_SoundSet","Shockpistol_InteriorTail_SoundSet"};
			begin1[] = {"dz\sounds\weapons\firearms\FNX45\FNX45_single_1",1,1,600};
			begin2[] = {"dz\sounds\weapons\firearms\FNX45\FNX45_single_2",1,1,600};
			soundBegin[] = {"begin1",0.33333,"begin2",0.33333,"begin2",0.33333};
			reloadTime = 0.125;
			recoil = "recoil_fnx";
			recoilProne = "recoil_fnx_prone";
			dispersion = 0.006;
			magazineSlot = "magazine";
			beginSilenced_Pro[] = {"",1,1,60};
			beginSilenced_HomeMade[] = {"",1,1,100};
			soundBeginExt[] = {{"beginSilenced_Pro",1},{"beginSilenced_HomeMade",1}};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class walkErc_L
				{
					soundSet = "Weapon_Movement_Pistol_walkErc_L_SoundSet";
					id = 1;
				};
				class walkErc_R
				{
					soundSet = "Weapon_Movement_Pistol_walkErc_R_SoundSet";
					id = 2;
				};
				class runErc_L
				{
					soundSet = "Weapon_Movement_Pistol_runErc_L_SoundSet";
					id = 3;
				};
				class runErc_R
				{
					soundSet = "Weapon_Movement_Pistol_runErc_R_SoundSet";
					id = 4;
				};
				class sprintErc_L
				{
					soundSet = "Weapon_Movement_Pistol_sprintErc_SoundSet";
					id = 5;
				};
				class sprintErc_R
				{
					soundSet = "Weapon_Movement_Pistol_sprintErc_SoundSet";
					id = 6;
				};
				class walkCro_L
				{
					soundSet = "Weapon_Movement_Pistol_walkCro_SoundSet";
					id = 21;
				};
				class walkCro_R
				{
					soundSet = "Weapon_Movement_Pistol_walkCro_SoundSet";
					id = 22;
				};
				class runCro_L
				{
					soundSet = "Weapon_Movement_Pistol_runCro_SoundSet";
					id = 23;
				};
				class runCro_R
				{
					soundSet = "Weapon_Movement_Pistol_runCro_SoundSet";
					id = 24;
				};
				class walkProne_L
				{
					soundSet = "Weapon_Movement_Pistol_walkCro_SoundSet";
					id = 31;
				};
				class walkProne_R
				{
					soundSet = "Weapon_Movement_Pistol_walkCro_SoundSet";
					id = 32;
				};
				class runProne_L
				{
					soundSet = "Weapon_Movement_Pistol_runCro_SoundSet";
					id = 33;
				};
				class runProne_R
				{
					soundSet = "Weapon_Movement_Pistol_runCro_SoundSet";
					id = 34;
				};
				class jumpErc_L
				{
					soundSet = "Weapon_Movement_Pistol_runErc_L_SoundSet";
					id = 35;
				};
				class jumpErc_R
				{
					soundSet = "Weapon_Movement_Pistol_runErc_L_SoundSet";
					id = 36;
				};
				class landFootErc_L
				{
					soundSet = "Weapon_Movement_Pistol_landFootErc_SoundSet";
					id = 37;
				};
				class landFootErc_R
				{
					soundSet = "Weapon_Movement_Pistol_landFootErc_SoundSet";
					id = 38;
				};
				class walkRasErc_L
				{
					soundSet = "Weapon_Movement_Pistol_walkRasErc_SoundSet";
					id = 51;
				};
				class walkRasErc_R
				{
					soundSet = "Weapon_Movement_Pistol_walkRasErc_SoundSet";
					id = 52;
				};
				class runRasErc_L
				{
					soundSet = "Weapon_Movement_Pistol_runRasErc_SoundSet";
					id = 53;
				};
				class runRasErc_R
				{
					soundSet = "Weapon_Movement_Pistol_runRasErc_SoundSet";
					id = 54;
				};
				class HandStep_L
				{
					soundSet = "Weapon_Movement_Pistol_walkErc_L_SoundSet";
					id = 61;
				};
				class HandStep_R
				{
					soundSet = "Weapon_Movement_Pistol_walkErc_L_SoundSet";
					id = 62;
				};
				class HandStep_Hard_L
				{
					soundSet = "Weapon_Movement_Pistol_runErc_L_SoundSet";
					id = 63;
				};
				class HandStep_Hard_R
				{
					soundSet = "Weapon_Movement_Pistol_runErc_L_SoundSet";
					id = 64;
				};
				class landFeetErc
				{
					soundSet = "Weapon_Movement_Pistol_landFeetErc_SoundSet";
					id = 100;
				};
				class Weapon_Movement_Pistol_Walk
				{
					soundSet = "Weapon_Movement_Pistol_walkErc_L_SoundSet";
					id = 101;
				};
				class Weapon_Movement_Pistol_Run
				{
					soundSet = "Weapon_Movement_Pistol_runErc_L_SoundSet";
					id = 102;
				};
				class Weapon_Movement_Pistol_Sprint
				{
					soundSet = "Weapon_Movement_Pistol_sprintErc_SoundSet";
					id = 103;
				};
				class Weapon_Movement_Pistol_Land
				{
					soundSet = "Weapon_Movement_Pistol_landFeetErc_SoundSet";
					id = 104;
				};
				class pickup
				{
					soundSet = "pickUpPistol_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "pistol_drop_SoundSet";
					id = 898;
				};
				class bodyfall_pistol
				{
					soundSet = "pickUpPistol_SoundSet";
					id = 13400;
				};
			};
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
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\pistols\fnx45\data\herstal45.rvmat"}},{0.7,{"DZ\weapons\pistols\fnx45\data\herstal45.rvmat"}},{0.5,{"DZ\weapons\pistols\fnx45\data\herstal45_damage.rvmat"}},{0.3,{"DZ\weapons\pistols\fnx45\data\herstal45_damage.rvmat"}},{0.0,{"DZ\weapons\pistols\fnx45\data\herstal45_destruct.rvmat"}}};
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
		isMeleeWeapon = 0;
		tracersEvery = 1;
	};
	class Ammunition_Base;
	class Ammo_Taser: Ammunition_Base
	{
		scope=2;
		displayName="Taser Prongs";
		descriptionShort="Taser Prongs to go into a taser cartridge.";
		model="\dz\weapons\ammunition\556_LooseRounds.p3d";
		rotationFlags=34;
		weight=0;
		count=4;
		ammo = "Bullet_Taser";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\weapons\ammunition\data\308_loose.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\weapons\ammunition\data\308_loose.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\weapons\ammunition\data\308_loose_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\weapons\ammunition\data\308_loose_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\weapons\ammunition\data\308_loose_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
};

class cfgAmmoTypes
	{
		class Bullet_Taser
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
		lootCategory="Crafted";
		cartridge="FxCartridge_9mm";
		spawnPileType="Ammo_Taser";
		hit=11;
		indirectHit=0;
		indirectHitRange=0;
		tracerScale=1;
		caliber=0.65000004;
		deflecting=45;
		visibleFire=5;
		audibleFire=9;
		typicalSpeed=850;
		airFriction=-0.00119;
		supersonicCrackNear[]={};
		supersonicCrackFar[]={};
		initSpeed=830;
		weight=0.0149;
		
		class DamageApplied {
			type = "Projectile";
			dispersion = 0;
			bleedThreshold = 0.600000;
			class Health
			{
				damage = 0;
			};
			class Blood
			{
				damage = 1;
			};
			class Shock
			{
				damage = 1000;
			};
		};
    };
};