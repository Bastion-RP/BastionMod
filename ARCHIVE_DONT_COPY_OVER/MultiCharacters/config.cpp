class CfgPatches
{
	class MultiCharacters
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {};
	};
};
class CfgMods
{
	class MultiCharacters
	{
		dir = "MultiCharacters";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "MultiCharacters";
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
				files[] = {"MultiCharacters/scripts/layouts/test.styles"};
			}
			class imageSets
			{
				files[] = {"MultiCharacters/scripts/layouts/bastionmulticharacters.imageset"};
			};
			class gameScriptModule
			{
				value = "";
				files[] = {"MultiCharacters/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"MultiCharacters/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"MultiCharacters/scripts/5_Mission"};
			};
		};
	};
};