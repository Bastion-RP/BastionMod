class CfgPatches
{
	class BastionBanking
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"BastionMultiCharacters"};
	};
};
class CfgMods
{
	class BastionBanking
	{
		dir = "BastionBanking";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "BastionBanking";
		credits = "RoomService";
		author = "RoomService";
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
				files[] = {"BastionMod/BastionBanking/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"BastionMod/BastionBanking/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"BastionMod/BastionBanking/scripts/5_Mission"};
			};
		};
	};
};