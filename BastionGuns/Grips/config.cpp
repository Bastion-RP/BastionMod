class CfgPatches
{
	class BRP_VerticalGrip_Base
	{
		units[] = {"VerticalGrip_Black","Bipod_Black"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgVehicles
{
	class Inventory_base;
	class BRP_VerticalGrip_Base: Inventory_base
	{
		scope = 0;
		displayName = "Vertical Grip";
		descriptionShort = "";
		inventorySlot = "grip1";
		model = "BastionMod\BastionGuns\Grips\grip1.p3d";
		itemSize[] = {1,2};
		weight = 10;
		hiddenSelections[] = {"camo"};
		recoilModifier[] = {0.5,0.5,0.5};
	};
	class BRP_VerticalGrip_Black: BRP_VerticalGrip_Base
	{
		scope = 2;
		displayName = "Vertical Grip (Black)";
		inventorySlot = "grip1";
		hiddenSelectionsTextures[] = {"BastionMod\BastionGuns\Grips\Data\VGRIP_Base_co.paa"};
	};
	class BRP_Bipod_Base: Inventory_base
	{
		scope = 0;
		displayName = "Bipod";
		descriptionShort = "";
		inventorySlot = "grip2";
		model = "BastionMod\BastionGuns\Grips\grip2.p3d";
		itemSize[] = {1,2};
		weight = 10;
		hiddenSelections[] = {"camo"};
		recoilModifier[] = {0.3,0.3,0.3};
	};
	class BRP_Bipod_Black: BRP_Bipod_Base
	{
		scope = 2;
		displayName = "Bipod (Black)";
		inventorySlot = "grip2";
		hiddenSelectionsTextures[] = {"BastionMod\BastionGuns\Grips\Data\BIPOD_Base_co.paa"};
	};
};
