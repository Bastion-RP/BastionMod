class CfgPatches 
{
	class BRP_CasinoGamblingMachine 
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
	class BRP_CasinoGamblingMachine : HouseNoDestruct 
	{
		scope=1;
		model="BastionMod\BastionMisc_Data\CasinoGambling\gamblingmachine.p3d";		
	};
};
