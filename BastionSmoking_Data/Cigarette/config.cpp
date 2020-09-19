class CfgPatches
{
	class BRP_Cigarette
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
	class BRP_Cigarette: Clothing
	{
		scope=2;
		displayName="Cigarette";
		descriptionShort="A cigarette is a cylindrical roll of shredded or ground tobacco that is wrapped in paper or another substance that does not contain tobacco.";
		model="BastionMod\BastionSmoking_Data\Cigarette\cigarette_g.p3d";
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
			male="BastionMod\BastionSmoking_Data\Cigarette\cigarette_m";
			female="BastionMod\BastionSmoking_Data\Cigarette\cigarette_f";
		};
        hiddenSelectionsTextures[]=
        {
            "BastionMod\BastionSmoking_Data\Cigarette\data\cigarette_co.paa"
		}; 
        hiddenSelectionsMaterials[]=
        {
            "BastionMod\BastionSmoking_Data\Cigarette\data\cigarette.rvmat"
		}; 
		weight=50;
		itemSize[]={1,1};
	};
	class BRP_Cigarette_Lit : BRP_Cigarette
	{
		scope=2;
		hiddenSelectionsTextures[]=
        {
            "BastionMod\BastionSmoking_Data\Cigarette\data\cigarette_lit_co.paa"
        }; 
		hiddenSelectionsMaterials[]=
        {
            "BastionMod\BastionSmoking_Data\Cigarette\data\cigarette_lit.rvmat"
        }; 
	};
};