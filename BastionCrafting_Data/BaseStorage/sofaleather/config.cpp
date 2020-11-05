class CfgPatches
{
	class DZ_Base_LeatherSofa
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
	class Inventory_Base;
	class Base_LeatherSofa: Inventory_Base
	{
		scope=2;
		displayName="Leather Sofa";
		descriptionShort="A Leather Sofa to decorate your base.   Dismantle with pliers or a screwdriver  Created by Axobi";
		model="DZ\structures\furniture\chairs\sofa_leather\sofa_leather_new.p3d";
		itemSize[]={10,8};
		carveNavmesh=1;
		canBeDigged=0;
		bounding="BSphere";
		overrideDrawArea="3.0";
		placement="ForceSlopeOnTerrain";
		physLayer="item_large";
		SingleUseActions[]={527};
		ContinuousActions[]={231};
		InteractActions[]={};
		weight=50000;
		itemBehaviour=0;
		
	};
	class Base_LeatherSofa_Kit_Holo: Inventory_Base
	{
		scope = 0;
		displayName = "Leather Sofa HOLO";
		model="DZ\structures\furniture\chairs\sofa_leather\sofa_leather_new.p3d";
	};
};