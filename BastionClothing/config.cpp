class CfgPatches
{
	class BastionClothing
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Characters",
			"DZ_Characters_Pants",
			"DZ_Characters_Tops",
			"DZ_Characters_Vests",
			"DZ_Data"
		};
	};
};


class CfgMods
{
	class BastionClothing
	{
		dir = "NCC_Clothing";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "BastionClothing";
		credits = "";
		author = "Helkhiana";
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
				files[] = {"BastionMod/BastionClothing/scripts/4_World"};
			};
		};
	};
};