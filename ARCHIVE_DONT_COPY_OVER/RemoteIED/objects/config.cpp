class CfgPatches
{
	class DZ_Gear_Traps
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data"
		};
	};
};
class CfgVehicles
{
	class LandMineTrap;
	class Lockpick;
	class RemoteDetonator : Lockpick
	{
		displayName="Remote Detonator";
		descriptionShort="Remote detonator used to touch off placed IEDs";
		model="\RemoteIED\objects\m57\m57_remote.p3d";
	};
	class RemoteIED : LandMineTrap
	{
		scope = 2;
		displayName="Remote IED";
		descriptionShort="Placeable IED that can be detonated using a remote trigger.";
		model="\RemoteIED\objects\c4\c4.p3d";
	};
};