class CfgPatches
{
	class BastionBodyBag
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = 
		{
			"DZ_Data",
			"BastionBodyBagItems"
		};
	};
};
class CfgMods
{
	class BastionBodyBag
	{
		dir = "BastionBodyBag";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "BastionBodyBag";
		credits = "Kerkkoh";
		author = "Kerkkoh";
		authorID = "0";
		version = "1.0";
		extra = 0;
		type = "mod";
		dependencies[] = {"Game", "World", "Mission"};
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {"BastionBodyBag/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"BastionBodyBag/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"BastionBodyBag/scripts/5_Mission"};
			};
		};
	};
};
