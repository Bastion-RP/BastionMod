class CfgPatches
{
	class BastionCCTV
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgMods
{
	class BastionCCTV
	{
		dir = "BastionCCTV";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "BastionCCTV";
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
				files[] = {"BastionMod/BastionCCTV/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"BastionMod/BastionCCTV/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"BastionMod/BastionCCTV/scripts/5_Mission"};
			};
		};
	};
};
