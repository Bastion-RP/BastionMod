class CfgPatches
{
	class DZ_Base_Nightstand
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
	class Base_Nightstand: Container_Base
	{
		scope=2;
		displayName="Nightstand";
		descriptionShort="A Nightstand, with some storage to decorate your base.   Dismantle with pliers or a screwdriver  Created by Axobi";
		model="DZ\structures\furniture\cases\case_bedroom_b\case_bedroom_b.p3d";
		itemSize[]={10,8};
		weight=50000;
		canBeDigged=0;
		bounding="BSphere";
		overrideDrawArea="3.0";
		placement="ForceSlopeOnTerrain";
		carveNavmesh=1;
		physLayer="item_large";
		class Cargo
		{
			itemsCargoSize[]={6,6};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
	};
	class Base_Nightstand_Kit_Holo: Container_Base
	{
		scope = 0;
		displayName = "Nightstand HOLO";
		model="DZ\structures\furniture\cases\case_bedroom_b\case_bedroom_b.p3d";
	};
};