class CfgPatches
{
	class BastionCCTV
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Structures"};
	};
};
class CfgMods
{
	class BastionCCTV
	{
		dir = "BastionCCTV";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "BastionCCTV";
		credits = "Kerkkoh";
		author = "Kerkkoh";
		authorID = "0";
		version = "1.0";
		extra = 0;
		type = "mod";
		dependencies[] = {"Game", "World", "Mission"};
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {"BastionCCTV/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"BastionCCTV/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"BastionCCTV/scripts/5_Mission"};
			};
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class BST_CCTV: Inventory_Base
	{
		scope = 2;
		displayName = "CCTV Monitor";
		descriptionShort = "CCTV Monitor";
		model = "\DZ\structures\furniture\Eletrical_appliances\pc\PC.p3d";
		weight = 5000;
		itemBehaviour = 0;
		itemSize[] = {5,5};
		carveNavmesh = 1;
		canBeDigged = 1;
		rotationFlags = 2;
	};
	class DOME_CCTV: Inventory_Base
	{
		scope = 2;
		displayName = "CCTV Dome Camera";
		descriptionShort = "CCTV Dome Camera";
		model = "\BastionMod\BastionCCTV\cctv_dome.p3d";
		weight = 1000;
	};
};