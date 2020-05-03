////////////////////////////////////////////////////////////////////
//DeRap: P:\BastionMod\BastionRemoteIED_Data\config.bin
//Produced from mikero's Dos Tools Dll version 7.60
//https://mikero.bytex.digital/Downloads
//'now' is Tue Apr 28 20:52:45 2020 : 'file' last modified on Tue Apr 28 20:52:45 2020
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class BastionRemoteIED_Data
	{
		units[] = {"BRP_RemoteIED"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgVehicles
{
	class LandMineTrap;
	class Lockpick;
	class BRP_RemoteDetonator: Lockpick
	{
		displayName = "Remote Detonator";
		descriptionShort = "Remote detonator used to touch off placed IEDs";
		model = "\BastionMod\BastionRemoteIED_Data\m57_remote.p3d";
	};
	class BRP_RemoteIED: LandMineTrap
	{
		scope = 2;
		displayName = "Remote IED";
		descriptionShort = "Placeable IED that can be detonated using a remote trigger.";
		model = "\BastionMod\BastionRemoteIED_Data\c4.p3d";
	};
};
