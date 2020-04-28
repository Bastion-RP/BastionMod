////////////////////////////////////////////////////////////////////
//DeRap: P:\BastionMod\BastionPending_Data\Keylock\config.bin
//Produced from mikero's Dos Tools Dll version 7.60
//https://mikero.bytex.digital/Downloads
//'now' is Tue Apr 28 21:15:56 2020 : 'file' last modified on Tue Apr 28 21:15:56 2020
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class BastionRP_Keylock
	{
		units[] = {"BastionRP_Keylock"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgVehicles
{
	class HouseNoDestruct;
	class BastionRP_Keylock: HouseNoDestruct
	{
		scope = 2;
		displayName = "KeyLock";
		descriptionShort = "Keylock";
		model = "\BastionMod\BastionPending_Data\Keylock\Bastion_Keylock.p3d";
	};
};
