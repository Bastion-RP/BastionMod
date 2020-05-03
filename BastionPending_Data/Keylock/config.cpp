class CfgPatches
{
	class BastionRP_Keylock
	{
		units[] = {"BRP_Keylock"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgVehicles
{
	class HouseNoDestruct;
	class BRP_Keylock: HouseNoDestruct
	{
		scope = 2;
		displayName = "KeyLock";
		descriptionShort = "Keylock";
		model = "\BastionMod\BastionPending_Data\Keylock\Bastion_Keylock.p3d";
	};
};
