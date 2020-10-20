//Weapon retextures along with a nonlethal version on .22 Paintball rounds which only deliver shock damage
class CfgPatches
{
	class BRP_WeaponRetextures
	{
		units[]=
		{
			"Ruger1022";
			"Ruger1022_Base"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Gear_Optics",
			"DZ_Weapons_Melee",
			"DZ_Gear_Tools",
			"DZ_Weapons_Firearms",
			"DZ_Gear_Crafting";
			"DZ_Weapons_Firearms_Ruger1022"
		};
		magazines[]=
		{
			"Mag_Ruger1022_30Rnd"
		};
		ammo[]=
		{
			"Bullet_22PB"
		};
	};
};
class Mode_Safe;
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class OpticsInfoRifle;
class cfgAmmoTypes
{
	class Atype_Bullet_22PB
	{
		name="Bullet_22PB"
	};
};
class CfgAmmo
{
	class Bullet_Base;
	class Bullet_22PB: Bullet_Base
	{
		scope=2;
		casing="FxCartridge_22";
		round="FxRound_22";
		spawnPileType="Ammo_22PB";
		hit=4.5;
		indirectHit=0;
		indirectHitRange=0;
		tracerScale=0.60000002;
		tracerStartTime=-1;
		tracerEndTime=1;
		deflecting=30;
		caliber=0.69999999;
		airFriction=-0.00076899998;
		typicalSpeed=380;
		initSpeed=3300;
		weight=0.0024999999;
		soundFly[]={};
		supersonicCrackNear[]={};
		supersonicCrackFar[]={};
		class DamageApplied
		{
			type="Projectile";
			dispersion=0;
			bleedThreshold=1;
			defaultDamageOverride[]=
			{
				{0.8000000,1}
			};
			class Health
			{
				damage=0;
			};
			class Blood
			{
				damage=0;
			};
			class Shock
			{
				damage=30;
			};
		};
		class NoiseHit
		{
			strength=1;
			type="shot";
		};
	};
};
class CfgMagazines
{
	class Ammunition_Base;
	class Magazine_Base;
	class Ammo_22PB: Ammunition_Base
	{
		scope=2;
		displayName="Paintball Rounds";
		descriptionShort="Small nonlethal rounds with paintball capsules loaded at the end.";
		model="\dz\weapons\ammunition\22_LooseRounds.p3d";
		itemSize[]={1,1};
		iconCartridge=3;
		weight=15;
		count=50;
		ammo="Bullet_22PB";
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
								"DZ\weapons\ammunition\data\22lr.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\weapons\ammunition\data\22lr.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\weapons\ammunition\data\22lr_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\weapons\ammunition\data\22lr_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\weapons\ammunition\data\22lr_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		hiddenSelections[]=
		{
			"camoGround",
			"zbytek",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionGuns\WeaponRetextures\data\coda_22round_red.paa",
			"BastionMod\BastionGuns\WeaponRetextures\data\coda_22round_red.paa",
			"BastionMod\BastionGuns\WeaponRetextures\data\coda_22round_red.paa"
		};
	};
	class Mag_Ruger1022_30Rnd: Magazine_Base
	{
		ammo="Bullet_22";
		ammoItems[]=
		{
			"Ammo_22",
			"Ammo_22PB"
		};
	};
	class BRP_mag_sporter_pb: Mag_Ruger1022_30Rnd
	{
		displayName="30rd Paintball Magazine";
		descriptionShort="Detachable box magazine for the paintball gun. Holds up to 30 paintball rounds.";
		ammo="Bullet_22";
		ammoItems[]=
		{
			"Ammo_22PB"
		};
	};
};
class cfgWeapons
{
	class Repeater_Base;
	class Winchester70;
	class Ruger1022;
	class Mosin9130;
	class BRP_repeater_black: Repeater_Base
	{
		scope=2;
		displayName="$STR_cfgWeapons_Repeater0";
		descriptionShort="$STR_cfgWeapons_Repeater1";
		model="\dz\weapons\firearms\repeater\repeater.p3d";
		attachments[]=
		{
			"weaponWrap",
			"suppressorImpro"
		};
		itemSize[]={9,3};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionGuns\WeaponRetextures\data\coda_repeater_black.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\weapons\firearms\repeater\data\repeater.rvmat"
		};
	};
	class BRP_repeater_black_amelia: Repeater_Base
	{
		scope=2;
		displayName="'Amelia'";
		descriptionShort="Seven-shot lever-action carbine, fed from an internal magazine. Proven and reliable, with a dash of the Old West style. Uses .357 rounds. This one has been engraved with care. 'Amelia' is engraved into the side. Floral designs decorate various parts of the rifle.";
		model="\dz\weapons\firearms\repeater\repeater.p3d";
		attachments[]=
		{
			"weaponWrap",
			"suppressorImpro"
		};
		itemSize[]={9,3};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionGuns\WeaponRetextures\data\coda_repeater_black_amelia.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\weapons\firearms\repeater\data\repeater.rvmat"
		};
	};
	class BRP_repeater_hardened: Repeater_Base
	{
		scope=2;
		displayName="$STR_cfgWeapons_Repeater0";
		descriptionShort="$STR_cfgWeapons_Repeater1";
		model="\dz\weapons\firearms\repeater\repeater.p3d";
		attachments[]=
		{
			"weaponWrap",
			"suppressorImpro"
		};
		itemSize[]={9,3};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionGuns\WeaponRetextures\data\coda_repeater_hardened.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\weapons\firearms\repeater\data\repeater.rvmat"
		};
	};
	class BRP_winchester_black: Winchester70
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionGuns\WeaponRetextures\data\coda_winchester_black.paa"
		};
	};
	class BRP_sporter_red: Ruger1022
	{
		scope=2;
		displayName="Paintball Gun";
		descriptionShort="Paintball gun designed to look and feel like the real thing!";
		attachments[]=
		{
			"weaponOpticsHunting"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionGuns\WeaponRetextures\data\coda_sporter_red.paa"
		};
		chamberableFrom[]=
		{
			"Ammo_22PB"
		};
		magazines[]=
		{
			"brp_mag_sporter_pb"
		};
	};
	class BRP_sporter_blue: Ruger1022
	{
		scope=2;
		displayName="Paintball Gun";
		descriptionShort="Paintball gun designed to look and feel like the real thing!";
		attachments[]=
		{
			"weaponOpticsHunting"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionGuns\WeaponRetextures\data\coda_sporter_blue.paa"
		};
		chamberableFrom[]=
		{
			"Ammo_22PB"
		};
		magazines[]=
		{
			"brp_mag_sporter_pb"
		};
	};
	class BRP_mosin_black: Mosin9130
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionGuns\WeaponRetextures\data\coda_mosin_black.paa"
		};
	};
	class Colt1911;
	class BRP_1911_hiswill: Colt1911
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionGuns\WeaponRetextures\data\coda_1911_hiswill.paa"
		};
	};
};

