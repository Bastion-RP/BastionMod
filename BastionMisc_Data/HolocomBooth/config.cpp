class CfgPatches 
{
	class BRP_HolocomBooth
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};

class CfgVehicles 
{
    class Inventory_Base;	
	class BRP_HolocomBooth : Inventory_Base 
	{
		scope = 2;
		displayName = "OIM Automated Booth";		
		model="BastionMod\BastionMisc_Data\HolocomBooth\booth.p3d";		
		physLayer = "item_large";
		class Cargo
		{
			itemsCargoSize[] = {};
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};		
	};
};
