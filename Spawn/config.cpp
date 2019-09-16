class CfgPatches
{
	class Spawn
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {};
	};
};
class CfgMods
{
	class Spawn
	{
		dir = "Spawn";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "Spawn";
		credits = "RoomService";
		author = "RoomService";
		authorID = "0";
		version = "1.0";
		extra = 0;
		type = "mod";
		dependencies[] = {"Game","World","Mission","gui"};
		class defs
		{
			class WidgetStyles
			{
				files[] = {"Spawn/scripts/layouts/test.styles"};
			}
			class imageSets
			{
				files[] = {"Spawn/scripts/layouts/bastionmulticharacters.imageset"};
			};
			class gameScriptModule
			{
				value = "";
				files[] = {"Spawn/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"Spawn/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"Spawn/scripts/5_Mission"};
			};
		};
	};
};