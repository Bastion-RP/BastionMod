class CfgPatches
{
	class BRP_CSM762_Suppressor
	{
		units[] = {"BRP_CSM762_Suppressor"};
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
	class BRP_CSM762_Suppressor: M4_Suppressor
	{
		scope = 2;
		displayName = "CSM-762 Suppressor";
		inventorySlot = "BRP_CSM762_Suppressor";
		itemSize[] = {1,3};
		descriptionShort = "Suppressor made for the SR25.";
		model = "BastionMod\BastionGuns\SR-25\SR25Silencer\BRP_CSM762_Suppressor.p3d";
	};
};
