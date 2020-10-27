class CfgPatches
{
	class BRP_CodaScripts
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Gear_Optics",
			"DZ_Weapons_Melee",
			"DZ_Gear_Tools",
			"DZ_Gear_Crafting"
		};
	};
};
class CfgMods
{
	class BRP_CodaScripts
	{
		dir="BastionMod";
		picture="";
		action="";
		hideName=1;
		hidePicture=1;
		name="coda_gear";
		credits="CodaRP";
		author="CodaRP";
		authorID="0";
		version="1.0";
		extra=0;
		type="mod";
		dependencies[]=
		{
			"World",
			"Game"
		};
		class defs
		{
			class gameScriptModule
			{
				value="";
				files[]=
				{
					"BastionMod/BastionMisc/CodaScripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"BastionMod/BastionMisc/CodaScripts/4_World"
				};
			};
		};
	};
};