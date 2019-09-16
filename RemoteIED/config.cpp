class CfgPatches
{
	class RemoteIED
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {};
	};
};
class CfgMods
{
	class RemoteIED
	{
		dir = "RemoteIED";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "RemoteIED";
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
				files[] = {"RemoteIED/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"RemoteIED/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"RemoteIED/scripts/5_Mission"};
			};
		};
	};
};