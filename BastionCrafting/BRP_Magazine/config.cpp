class CfgPatches
{
	class Lugge_Krone
	{
		units[]=
		{
			"Lugge_Krone"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Characters",
			"DZ_Characters_Pants",
			"DZ_Characters_Tops",
			"DZ_Characters_Headgear",
			"DZ_Data"
		};
	};
	
};

class CfgVehicles
{		
	class Inventory_Base;
	class Book_Base: Inventory_Base
	{
		simulation="ItemBook";
		model="\BastionMod\BastionCrafting\BRP_Magazine\magazine.p3d";
		inventorySlot[]=
		{
			"Book"
		};
		itemSize[]={2,2};
		absorbency=0.89999998;
		hiddenSelections[]=
		{
			"all"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionCrafting\BRP_Magazine\textures\brp_magazine_co.paa"
		};
	
	};
};