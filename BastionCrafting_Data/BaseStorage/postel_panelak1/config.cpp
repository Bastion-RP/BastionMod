class CfgPatches
{
	class DZ_Base_SingleBed
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Scripts"
		};
	};
};
class CfgVehicles
{
	class Container_Base;
	class Base_SingleBed: Container_Base
	{
		scope=2;
		displayName="Single Bed";
		descriptionShort="A single Bed to rest on, with a pistol slot and a bit of storage.   Dismantle with pliers or a screwdriver  Created by Axobi";
		model="DZ\structures\furniture\chairs\postel_panelak1\postel_panelak1.p3d";
		itemSize[]={10,8};
		carveNavmesh=1;
		canBeDigged=0;
		bounding="BSphere";
		overrideDrawArea="3.0";
		placement="ForceSlopeOnTerrain";
		physLayer="item_large";
		SingleUseActions[]={527};
		ContinuousActions[]={231};
		rotationFlags=2;
		InteractActions[]={};
		weight=50000;
		itemBehaviour=0;
		class Cargo
		{
			itemsCargoSize[]={6,3};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
		attachments[]=
		{
			"Pistol",
			"Knife"
		};
	};
	class Base_SingleBed_Kit_Holo: Container_Base
	{
		scope = 0;
		displayName = "Single Bed HOLO";
		model="DZ\structures\furniture\chairs\postel_panelak1\postel_panelak1.p3d";
	};
};