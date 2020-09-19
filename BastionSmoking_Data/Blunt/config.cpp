class CfgPatches
{
	class BRP_Blunt
	{
		units[]=
		{};		
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data"
		};
	};
};
class CfgVehicles
{		
	class Clothing;
	class BRP_Blunt: Clothing
	{
		scope=2;
		displayName="Blunt";
		descriptionShort="Marijuana rolled up in brown tobacco paper.";
		model="BastionMod\BastionSmoking_Data\Blunt\blunt_g.p3d";
		inventorySlot="Mask";
		rotationFlags=16;
		itemInfo[]=
		{
			"Clothing",
			"Mask"
		};
		simulation="clothing";
		vehicleClass="Clothing";
        hiddenSelections[]=
        {
			"zbytek"
        };
		class ClothingTypes
		{
			male="BastionMod\BastionSmoking_Data\Blunt\blunt_m";
			female="BastionMod\BastionSmoking_Data\Blunt\blunt_f";
		};
        hiddenSelectionsTextures[]=
        {
            "BastionMod\BastionSmoking_Data\Blunt\data\blunt_co.paa"
		}; 
        hiddenSelectionsMaterials[]=
        {
            "BastionMod\BastionSmoking_Data\Blunt\data\blunt.rvmat"
		}; 
		weight=50;
		itemSize[]={1, 2};
		quantityBar=1;
		varQuantityInit=100;
		varQuantityMin=0;
		varQuantityMax=100;
		varQuantityDestroyOnMin=0;
		class EnergyManager
		{
			energyAtSpawn=5400;
			energyUsagePerSecond=1;
			updateInterval=50;
			convertEnergyToQuantity=1;
		};
	};
	class BRP_Blunt_Lit : BRP_Blunt
	{
		scope=2;
		hiddenSelectionsTextures[]=
        {
            "BastionMod\BastionSmoking_Data\Blunt\data\blunt_lit_co.paa"
        }; 
		hiddenSelectionsMaterials[]=
        {
            "BastionMod\BastionSmoking_Data\Blunt\data\blunt_lit.rvmat"
        }; 
	};
};