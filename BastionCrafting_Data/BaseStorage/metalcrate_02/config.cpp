class CfgPatches
{
	class DZ_Base_BMetalCrate
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
	class Base_BMetalCrate: Container_Base
	{
		scope=2;
		displayName="Blue Metal Crate";
		descriptionShort="A blue metal storage container for your base.   Dismantle with pliers or a screwdriver  Created by Axobi";
		model="DZ\structures\furniture\cases\metalcrate_02\metalcrate_02.p3d";
		itemSize[]={6,6};		
		canBeDigged=0;
		bounding="BSphere";
		overrideDrawArea="3.0";
		placement="ForceSlopeOnTerrain";
		physLayer="item_small";
		carveNavmesh=1;
		SingleUseActions[]={527};
		ContinuousActions[]={231};
		rotationFlags=2;
		InteractActions[]={};
		weight=50000;
		itemBehaviour=0;
		class Cargo
		{
			itemsCargoSize[]={10,25};
			openable=0;
			allowOwnedCargoManipulation=1;
		};		
	};
	class Base_BMetalCrate_Kit_Holo: Container_Base
	{
		scope = 0;
		displayName = "Wardrobe Storage HOLO";
		model="DZ\structures\furniture\cases\case_a\case_a.p3d";
	};
};