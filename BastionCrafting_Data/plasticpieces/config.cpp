class CfgPatches
{
	class BastionCrafting_Plastic
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = 
		{
			"DZ_Data"
		};
	};
};
class CfgVehicles
{
	// Config is just for ingame testing purpoces
	class Inventory_Base;
	class BRP_MeltedPlastic: Inventory_Base
	{
		scope = 2;
		displayName = "Melted plastic";
		descriptionShort = "REPLACE ME";
		model = "BastionMod\BastionCrafting_Data\plasticpieces\plastic.p3d";
		isMeleeWeapon = 0;
		weight = 50;
		absorbency = 0;
		itemSize[] = {1,1};
		itemBehaviour = 0;
	};
};