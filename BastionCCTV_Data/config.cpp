////////////////////////////////////////////////////////////////////
//DeRap: P:\BastionMod\BastionCCTV_Data\config.bin
//Produced from mikero's Dos Tools Dll version 7.60
//https://mikero.bytex.digital/Downloads
//'now' is Tue Apr 28 21:12:30 2020 : 'file' last modified on Tue Apr 28 21:12:30 2020
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class BastionCCTV_Data
	{
		units[] = {"BRP_CCTV","BRP_DOME_CCTV"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class HouseNoDestruct;
	class BRP_CCTV: Inventory_Base
	{
		scope = 2;
		displayName = "CCTV Monitor";
		descriptionShort = "CCTV Monitor";
		model = "\DZ\structures\furniture\Eletrical_appliances\pc\PC.p3d";
		weight = 5000;
		itemBehaviour = 0;
		itemSize[] = {5,5};
		carveNavmesh = 1;
		rotationFlags = 2;
	};
	class BRP_DOME_CCTV: HouseNoDestruct
	{
		scope = 2;
		displayName = "CCTV Dome Camera";
		descriptionShort = "CCTV Dome Camera";
		model = "BastionMod\BastionCCTV_Data\cctv_dome.p3d";
	};
};
