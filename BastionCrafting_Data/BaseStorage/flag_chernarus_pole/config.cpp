class CfgPatches
{
	class DZ_Base_Chernarus_Flag
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
	class Base_Chernarus_Flag: Inventory_Base
	{
		scope=2;
		displayName="Chernarus Flag";
		descriptionShort="A Chernarus flag, mounted on a small pole, useful for sticking on the side of buildings and fences.  Made by Axobi";
		model="DZ\structures\furniture\school_equipment\flag_chernarus_pole.p3d";
		itemSize[]={10,8};
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
		weight=280;
		itemBehaviour=0;
		class Cargo{};
	};
	class Base_Cot_Kit_Holo: Inventory_Base
	{
		scope = 0;
		displayName = "Chernarus Flag HOLO";
		model="DZ\structures\furniture\school_equipment\flag_chernarus_pole.p3d";
	};
};