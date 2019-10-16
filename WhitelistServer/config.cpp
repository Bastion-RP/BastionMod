class CfgPatches
{
	class BSTWhitelistServer
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"BSTWhitelist"};
	};
};
class CfgMods
{
	class BSTWhitelistServer
	{
		dir = "BSTWhitelistServer";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "BSTWhitelistServer";
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
				files[] = {"BSTWhitelistServer/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"BSTWhitelistServer/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"BSTWhitelistServer/scripts/5_Mission"};
			};
		};
	};
};