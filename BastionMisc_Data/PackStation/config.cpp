class CfgPatches 
{
	class BRP_PackStation 
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
	class BRP_PackStation : HouseNoDestruct 
	{
		scope=2;
		model="BastionMod\BastionMisc_Data\PackStation\packstation.p3d";	
		hiddenSelections[] = {"all"};		
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionMisc_Data\PackStation\data\packstation_co.paa"
		};		
	};
};
