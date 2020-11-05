class CfgPatches
{
	class DisableMenuButtons
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgMods
{
	class DisableMenuButtons
	{
		dir = "DisableMenuButtons";
		picture = "";
		action = "";
		hideName = 0;
		hidePicture = 0;
		name = "";
		credits = "";
		author = "Kactet";
		authorID = "0";
		version = "0.1";
		extra = 0;
		type = "mod";
		dependencies[] = {"Mission"};
		class defs
		{
			class missionScriptModule
			{
				value = "";
				files[] = {"BastionMod/BastionMisc/DisableMenuButtons/scripts/5_Mission"};
			};
		};
	};
};
