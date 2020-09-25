class CfgPatches
{
	class BastionCentralMenu
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"BastionMultiCharacters"};
	};
};
class CfgMods
{
	class BastionCentralMenu
	{
		dir = "BastionCentralMenu";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "BastionCentralMenu";
		credits = "RoomService";
		author = "RoomService";
		inputs="BastionMod/BastionCentralMenu/modded_Inputs.xml";
		authorID = "0";
		version = "1.0";
		extra = 0;
		type = "mod";
		dependencies[] = {"World","Mission"};
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = {"BastionMod/BastionCentralMenu/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"BastionMod/BastionCentralMenu/scripts/5_Mission"};
			};
		};
	};
};