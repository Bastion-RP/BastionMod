class CfgPatches
{
	class DZ_Base_CoffeeTable
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
	class Base_CoffeeTable: Container_Base
	{
		scope=2;
		displayName="Coffee Table";
		descriptionShort="A Coffee Table to decorate your base.   Dismantle with pliers or a screwdriver  Created by Axobi";
		model="DZ\structures\furniture\tables\lobby_table\lobby_table.p3d";
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
			itemsCargoSize[]={8,5};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
		
	};
	class Base_CoffeeTable_Kit_Holo: Container_Base
	{
		scope = 0;
		displayName = "Coffee Table HOLO";
		model="DZ\structures\furniture\tables\lobby_table\lobby_table.p3d";
	};
};