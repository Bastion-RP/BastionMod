class CfgPatches
{
	class DZ_Weapons_Muzzles
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};

class cfgVehicles
{
	class ItemSuppressor;
	class ImprovisedSuppressor: ItemSuppressor
	{
		noiseShootModifier= -0.8;
		class DamageSystem { class GlobalHealth { class Health { hitpoints= 5; }; }; };
	};

	class M4_Suppressor: ItemSuppressor
	{
		noiseShootModifier= -2.2;
		class DamageSystem { class GlobalHealth { class Health { hitpoints= 100; }; }; };
	};
	class AK_Suppressor: ItemSuppressor
	{
		noiseShootModifier= -2.2;
		class DamageSystem { class GlobalHealth { class Health { hitpoints= 100; }; }; };
	};
	class PistolSuppressor: ItemSuppressor
	{
		noiseShootModifier= -3.2;
		class DamageSystem { class GlobalHealth { class Health { hitpoints= 100; }; }; };
	};
}