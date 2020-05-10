class CfgPatches
{
	class BWAF_Weapons
	{
		units[] = {"SR25_Suppressor"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Weapons_Muzzles"};
	};
};
class cfgVehicles
{
	class Inventory_Base;
	class ItemBarrel: Inventory_Base{};
	class ItemSuppressor: Inventory_Base{};
	class M4_Suppressor: ItemSuppressor{};
	class SR25_Suppressor: M4_Suppressor
	{
		scope = 2;
		displayName = "SR-25 Suppressor";
		inventorySlot = "SR25_Suppressor";
		itemSize[] = {1,3};
		descriptionShort = "Suppressor made for the SR25.";
		model = "BastionMod\BastionGuns\SR-25\SR25Silencer\SR25_Suppressor.p3d";
	};
};
