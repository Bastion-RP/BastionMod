////////////////////////////////////////////////////////////////////
//DeRap: BastionRPitems\config.bin
//Produced from mikero's Dos Tools Dll version 7.26
//https://bytex.market/products/item/weodpphdknnzm70o0h8q/Mikero%27s%20Dos%20Tools
//'now' is Fri Jul 19 01:04:59 2019 : 'file' last modified on Sun Jul 14 06:31:11 2019
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class BastionRP_Keylock
	{
		units[] = {};
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
		model = "\BastionMod\Keylock\Bastion_Keylock.p3d";
	};
};

