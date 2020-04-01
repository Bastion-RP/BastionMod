class CfgPatches
{
	class BastionBanking
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"MultiCharacters", "BastionRP_Items"};
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
				files[] = {"BastionBanking/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"BastionBanking/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"BastionBanking/scripts/5_Mission"};
			};
		};
	};
};

class CfgVehicles
{
	class Inventory_Base;
	class NCC_ATM: Inventory_Base
	{
	};
}