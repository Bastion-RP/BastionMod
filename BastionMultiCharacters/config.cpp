class CfgPatches
{
	class BastionMultiCharacters
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {};
	};
};
class CfgMods
{
	class BastionMultiCharacters
	{
		dir = "BastionMultiCharacters";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "BastionMultiCharacters";
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
				files[] = {"BastionMod/BastionMultiCharacters/scripts/layouts/test.styles"};
			};
			class imageSets
			{
				files[] = {"BastionMod/BastionMultiCharacters/scripts/layouts/bastionmulticharacters.imageset"};
			};
			class gameScriptModule
			{
				value = "";
				files[] = {"BastionMod/BastionMultiCharacters/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"BastionMod/BastionMultiCharacters/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"BastionMod/BastionMultiCharacters/scripts/5_Mission"};
			};
		};
	};
};