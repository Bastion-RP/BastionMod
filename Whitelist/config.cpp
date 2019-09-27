class CfgPatches
{
	class BSTWhitelist
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {};
	};
};
class CfgMods
{
	class BSTWhitelist
	{
		dir = "BSTWhitelist";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "BSTWhitelist";
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
				files[] = {"BSTWhitelist/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"BSTWhitelist/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"BSTWhitelist/scripts/5_Mission"};
			};
		};
	};
};