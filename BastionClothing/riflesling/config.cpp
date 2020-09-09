class CfgPatches
{
	class BRP_riflesling
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
	class BRP_riflesling_colorbase: Clothing
	{
		scope = 2 ;
		displayName="Riflesling leather";
		descriptionShort="";
		model="\BastionMod\BastionClothing\riflesling\riflesling_g.p3d";
		inventorySlot="shoulder";
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
			"shoulder"
		};
		simpleHiddenSelections[]=
        {
            "rolled",
            "deployed"
        };
		hiddenSelections[]=
		{
			"rolled",
			"deployed",
			"sling"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\riflesling\data\ground\rifle_sling_g_CO.paa",
			"BastionMod\BastionClothing\riflesling\data\rifle_sling_CO.paa",
			"BastionMod\BastionClothing\riflesling\data\rifle_sling_CO.paa"
		};
		class ClothingTypes
		{
			male="\BastionMod\BastionClothing\riflesling\riflesling.p3d";
			female="\BastionMod\BastionClothing\riflesling\riflesling.p3d";
		};
	};
	class BRP_riflesling_black : BRP_riflesling_colorbase
	{
	scope = 2;
	displayName="Riflesling black";
	hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\riflesling\data\ground\rifle_sling_g_black_co.paa",
			"\BastionMod\BastionClothing\riflesling\data\rifle_sling_black_co.paa",
			"\BastionMod\BastionClothing\riflesling\data\rifle_sling_black_co.paa"
		};
	};
};