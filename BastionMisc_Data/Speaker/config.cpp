class CfgPatches
{
    class BastionMisc_Data
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = 1;
        requiredAddons[] = {"DZ_Data"};
    };
};
class CfgVehicles
{
    class HouseNoDestruct;
    class BRP_Speaker_single: HouseNoDestruct
    {
        scope = 1;
        model = "\BastionMod\BastionMisc_Data\Speaker\Speaker_single.p3d";  
    };
	class BRP_Speaker_multi: HouseNoDestruct
    {
        scope = 1;
        model = "\BastionMod\BastionMisc_Data\Speaker\Speaker_multi.p3d";  
    };
	
};