class CfgPatches
{
	class VerticalGrip_Base
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
	class VerticalGrip_Base: Inventory_base
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
	class VerticalGrip_Black: VerticalGrip_Base
	{
		scope = 2;
		displayName = "Vertical Grip (Black)";
		inventorySlot = "grip1";
		hiddenSelectionsTextures[] = {"BastionMod\BastionGuns\Grips\Data\VGRIP_Base_co.paa"};
	};
	class Bipod_Base: Inventory_base
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
	class Bipod_Black: Bipod_Base
	{
		scope = 2;
		displayName = "Bipod (Black)";
		inventorySlot = "grip2";
		hiddenSelectionsTextures[] = {"BastionMod\BastionGuns\Grips\Data\BIPOD_Base_co.paa"};
	};
};
