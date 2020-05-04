class CfgPatches
{
	class CustomLiquid
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data", "DZ_Weapons_Melee"};
	};
};

class CfgMods
{
	class CustomLiquid
	{
		dir = "CustomLiquid";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "CustomLiquid";
		credits = "Helkhiana";
		author = "Helkhiana";
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
				files[] = {"BastionMod/BastionMisc/CustomLiquid/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"BastionMod/BastionMisc/CustomLiquid/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"BastionMod/BastionMisc/CustomLiquid/scripts/5_Mission"};
			};
		};
	};
};