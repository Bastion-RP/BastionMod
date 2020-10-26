class CfgPatches
{
    class LaborRetex
    {
        units[]={};
        weapons[]={};
        requiredVersion=0.1;
        requiredAddons[]=
        {
            "DZ_Characters",
            "DZ_Characters_Backpacks",
            "DZ_Characters_Pants",
            "DZ_Characters_Tops",
            "DZ_Gear_Containers",
            "DZ_Characters_Headgear",
            "DZ_Data"
        };
    };
};
class CfgVehicles
{
	class Clothing;
    class PressVest_ColorBase: Clothing
    {
        hiddenSelections[] = {
            "camoGround",
            "camoMale",
            "camoFemale"
        };
    };
    class BRP_PressVest_Labor: PressVest_ColorBase
    {
		scope=2;
		visibilityModifier=0.94999999;
        displayName="Labor Division Vest";
        descriptionShort="Labor Gang";
        hiddenSelectionsTextures[]=
        {
            "LaborRetex\Data\LaborVest_co.paa",
            "LaborRetex\Data\LaborVest_co.paa",
            "LaborRetex\Data\LaborVest_co.paa",
        };
		hiddenSelectionsMaterials[]=
        {
            "LaborRetex\Data\LaborVest.rvmat",
            "LaborRetex\Data\LaborVest.rvmat",
            "LaborRetex\Data\LaborVest.rvmat",
        };
    };
};