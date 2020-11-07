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
    class HouseNoDestruct;	
	class BRP_HolocomBooth : HouseNoDestruct 
	{
		scope=1;
		model="BastionMod\BastionMisc_Data\HolocomBooth\booth.p3d";		
	};
};
