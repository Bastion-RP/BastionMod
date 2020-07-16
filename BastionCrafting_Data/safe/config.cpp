class CfgPatches
{
	class BRP_Safe
	{
		units[]=
		{
			"BRP_safe"
		};
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
	class Inventory_Base;
	
	class Book_Base;
	class ItemBook: Book_Base{};
	class BRP_safe: ItemBook
	{
		scope=2;
		model="\BastionMod\BastionCrafting_Data\safe\BRP_Safe.p3d";
		displayName="safe";
		descriptionShort="safe";
		itemSize[]={2,2};
		weight = 500;
		rotationFlags=1;

		
		
	};
};