class CfgPatches
{
	class BastionRation
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {};
	};
};
class CfgMods
{
	class BastionRation
	{
		dir = "BastionRation";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "BastionRation";
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
				files[] = {"BastionRation/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"BastionRation/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"BastionRation/scripts/5_Mission"};
			};
		};
	};
};