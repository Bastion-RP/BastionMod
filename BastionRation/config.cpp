class CfgPatches
{
	class BastionRation
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"BastionRP_Items"};
	};
};

class CfgMods
{
	class BastionRation
	{
		dir = "BastionRation";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "BastionRation";
		credits = "CAMINOonPC";
		author = "CAMINOonPC";
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
				files[] = {"BastionRation/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"BastionRation/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"BastionRation/scripts/5_Mission"};
			};
		};
	};
};

class CfgVehicles
{
	class Inventory_Base;
	class NCC_AionVendor: Inventory_Base
	{
		scope = 2;
		displayName = "Vending Machine";
		descriptionShort = "Vending Machine";
		weight = 5000;
		itemBehaviour = 0;
		itemSize[] = { 5, 5 };
		carveNavmesh = 1;
		bounding="BSphere";
		physLayer="item_large";
		// model = "\DZ\structures\furniture\Eletrical_appliances\vending_machine\vending_machine.p3d"; 
	};
};