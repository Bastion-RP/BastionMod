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
    class BRP_BoxRing: HouseNoDestruct
    {
        scope = 1;
        model = "\BastionMod\BastionCrafting_Data\BoxRing\BoxRing.p3d";  
    };	
};