class CfgPatches
{
	class DZ_Base_CornerSofa
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
	class Base_CornerSofa: Inventory_Base
	{
		scope=2;
		displayName="Corner Sofa";
		descriptionShort="A corner Sofa to decorate your base.   Dismantle with pliers or a screwdriver  Created by Axobi";
		model="DZ\structures\furniture\chairs\sofacorner\sofacorner.p3d";
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
	class Base_CornerSofa_Kit_Holo: Inventory_Base
	{
		scope = 0;
		displayName = "Corner Sofa HOLO";
		model="DZ\structures\furniture\chairs\sofacorner\sofacorner.p3d";
	};
};