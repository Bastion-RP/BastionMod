class CfgPatches
{
	class BastionGuns
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data"
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
				files[] = {"BastionMod/BastionGuns/scripts/4_World"};
			};
		};
	};
};