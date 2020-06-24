class CfgPatches
{
	class DeadlyWater
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};

class CfgMods
{
	class DeadlyWater
	{
		dir = "DeadlyWater";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "DeadlyWater";
		credits = "Kactet";
		author = "Kactet";
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
				files[] = {"BastionMod/BastionMisc/DeadlyWater/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"BastionMod/BastionMisc/DeadlyWater/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"BastionMod/BastionMisc/DeadlyWater/scripts/5_Mission"};
			};
		};
	};
};