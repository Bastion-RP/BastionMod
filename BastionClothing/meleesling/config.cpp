class CfgPatches
{
	class BRP_meleesling
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Characters_Backpacks"
		};
	};	
};
class CfgVehicles
{
	class Clothing;
	class BRP_meleesling_colorbase: Clothing
	{
		scope = 2 ;
		displayName="Meleesling leather";
		descriptionShort="";
		model="\BastionMod\BastionClothing\meleesling\meleesling_g.p3d";
		inventorySlot[]=
		{
			"Melee"
		};
		simulation="clothing";
		vehicleClass="Clothing";
		itemInfo[]=
		{
			"Clothing",
			"Back"
		};
		rotationFlags=0;
		itemSize[]={7,3};
		itemsCargoSize[]={0,0};
		weight=500;
		absorbency=0.2;
		heatIsolation=0.13;
		repairableWithKits[]={5,3};
		repairCosts[]={30,25};
		canBeDigged=1;
		soundAttType="Outdoor";
		attachments[]=
		{
			"Melee"
		};
		simpleHiddenSelections[]=
        {
            "rolled",
            "deployed",
            "sword",
            "axe"
        };
		hiddenSelections[]=
		{
			"rolled",
			"deployed",
			"sling",
			"sword",
            "axe"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\meleesling\data\ground\rifle_sling_g_CO.paa",
			"BastionMod\BastionClothing\meleesling\data\rifle_sling_CO.paa",
			"BastionMod\BastionClothing\meleesling\data\rifle_sling_CO.paa"
		};
		class ClothingTypes
		{
			male="\BastionMod\BastionClothing\meleesling\meleesling.p3d";
			female="\BastionMod\BastionClothing\meleesling\meleesling.p3d";
		};
	};
	class BRP_meleesling_black : BRP_meleesling_colorbase
	{
	scope = 2;
	displayName="Meleesling black";
	hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\meleesling\data\ground\rifle_sling_g_black_co.paa",
			"\BastionMod\BastionClothing\meleesling\data\rifle_sling_black_co.paa",
			"\BastionMod\BastionClothing\meleesling\data\rifle_sling_black_co.paa"
		};
	};
};
