class CfgPatches
{
	class BastionRemoteIED
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data"
		};
	};
};
class CfgMods
{
	class RemoteIED
	{
		dir = "BastionRemoteIED";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "BastionRemoteIED";
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
				files[] = {"BastionMod/BastionRemoteIED/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"BastionMod/BastionRemoteIED/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"BastionMod/BastionRemoteIED/scripts/5_Mission"};
			};
		};
	};
};