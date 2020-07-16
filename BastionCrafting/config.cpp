class CfgPatches
{
	class BastionCrafting
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"BastionCrafting_Data"};
	};
};
class CfgMods
{
	class BastionCrafting
	{
		dir = "BastionCrafting";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "BastionCrafting";
		credits = "RoomService";
		author = "RoomService";
		inputs="BastionMod/BastionCrafting/modded_Inputs.xml";
		authorID = "0";
		version = "1.0";
		extra = 0;
		type = "mod";
		dependencies[] = {"Game","World","Mission", "gui"};
		class defs
		{
			class imageSets
			{
				value = "";
				files[] = {"BastionMod/BastionCrafting/gui/img/IngredientStatusImage.imageset"};
			};
			class gameScriptModule
			{
				value = "";
				files[] = {"BastionMod/BastionCrafting/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"BastionMod/BastionCrafting/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"BastionMod/BastionCrafting/scripts/5_Mission"};
			};
		};
	};
};