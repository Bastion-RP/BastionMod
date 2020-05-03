class CfgPatches
{
	class BastionVendor
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"JM_CF_Scripts",
			"DZ_Data",
			"DZ_Gear_Navigation"
		};
	};
};

class CfgMods
{
	class BastionVendor
	{
		dir = "BastionVendor";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "BastionVendor";
		credits = "CAMINOonPC";
		author = "CAMINOonPC";
		authorID = "0";
		version = "1.0";
		extra = 0;
		type = "mod";
		dependencies[] = {"Game","World","Mission"};
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {"BastionMod/BastionVendor/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"BastionMod/BastionVendor/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"BastionMod/BastionVendor/scripts/5_Mission"};
			};
		};
	};
};