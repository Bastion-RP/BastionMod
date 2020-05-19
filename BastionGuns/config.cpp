class CfgPatches
{
	class BastionGuns
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Weapons_Projectiles"
		};
	};
};


class CfgMods
{
	class BastionGuns
	{
		dir = "BastionGuns";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "BastionGuns";
		credits = "";
		author = "Helkhiana & Jordan";
		authorID = "0";
		version = "1.0";
		extra = 0;
		type = "mod";
		dependencies[] = {"World"};
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = {"BastionMod/BastionGuns/scripts/4_World"};
			};
		};
	};
};


class CfgAmmo
{
	class Bullet_12GaugeSlug;
	class Bullet_12GaugeRubberSlug: Bullet_12GaugeSlug
	{
		class DamageApplied
		{
			type="Projectile";
			dispersion=0.050000001;
			bleedThreshold=0;
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
				damage=80;
				damageOverride[]=
				{
					{0.60000002,1}
				};
			};
		};
	};
};