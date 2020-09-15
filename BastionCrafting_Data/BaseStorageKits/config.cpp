class CfgPatches
{
	class Base_Storage_Base_Kit
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
	class Container_Base;
	class WoodenCrate: Container_Base
	{
	};
	class Base_Almara_Kit: WoodenCrate
	{
		scope=2;
		displayName="Armoire Kit";
		descriptionShort="Can be deployed into an Armoire in your base.  Dismantle with pliers or a screwdriver  Created by Diesel & Axobi";
		model="\DZ\structures\furniture\decoration\box_c\box_c.p3d";
		itemSize[]={8,6};
		carveNavmesh=1;
		canBeDigged=0;
		simulation="inventoryItem";
		physLayer="item_small";
		SingleUseActions[]={527};
		ContinuousActions[]={231};
		rotationFlags=2;
		InteractActions[]={};
		weight=300;
		itemBehaviour=2;
		class Cargo
		{
		};
	};
	class Base_BMetalCrate_Kit: WoodenCrate
	{
		scope=2;
		displayName="Blue Metal Crate Kit";
		descriptionShort="Can be deployed into a blue metal crate in your base.  Dismantle with pliers or a screwdriver  Created by Diesel & Axobi";
		model="\DZ\structures\furniture\decoration\box_c\box_c.p3d";
		itemSize[]={6,6};
		carveNavmesh=1;
		canBeDigged=0;
		simulation="inventoryItem";
		physLayer="item_small";
		SingleUseActions[]={527};
		ContinuousActions[]={231};
		rotationFlags=2;
		InteractActions[]={};
		weight=300;
		itemBehaviour=2;
		class Cargo
		{
		};
	};
	class Base_GMetalCrate_Kit: WoodenCrate
	{
		scope=2;
		displayName="Green Metal Crate Kit";
		descriptionShort="Can be deployed into a green metal crate in your base.  Dismantle with pliers or a screwdriver  Created by Diesel & Axobi";
		model="\DZ\structures\furniture\decoration\box_c\box_c.p3d";
		itemSize[]={6,6};
		carveNavmesh=1;
		canBeDigged=0;
		simulation="inventoryItem";
		physLayer="item_small";
		SingleUseActions[]={527};
		ContinuousActions[]={231};
		rotationFlags=2;
		InteractActions[]={};
		weight=300;
		itemBehaviour=2;
		class Cargo
		{
		};
	};
	class Base_Cot_Kit: WoodenCrate
	{
		scope=2;
		displayName="Comfy Cot Kit";
		descriptionShort="Can be deployed into a comfy cot to decorate your base.  Dismantle with pliers or a screwdriver  Created by Diesel & Axobi";
		model="\DZ\structures\furniture\decoration\box_c\box_c.p3d";
		itemSize[]={4,4};
		carveNavmesh=1;
		canBeDigged=0;
		simulation="inventoryItem";
		physLayer="item_small";
		SingleUseActions[]={527};
		ContinuousActions[]={231};
		rotationFlags=2;
		InteractActions[]={};
		weight=300;
		itemBehaviour=2;
		class Cargo
		{
		};
	};
	class Base_Almara_Large_Kit: WoodenCrate
	{
		scope=2;
		displayName="Large Armoire Kit";
		descriptionShort="Can be deployed into a Large Armoire in your base.  Dismantle with pliers or a screwdriver  Created by Diesel & Axobi";
		model="\DZ\structures\furniture\decoration\box_c\box_c.p3d";
		itemSize[]={9,9};
		carveNavmesh=1;
		canBeDigged=0;
		simulation="inventoryItem";
		physLayer="item_small";
		SingleUseActions[]={527};
		ContinuousActions[]={231};
		rotationFlags=2;
		InteractActions[]={};
		weight=300;
		itemBehaviour=2;
		class Cargo
		{
		};
	};
	class Base_Nightstand_Kit: WoodenCrate
	{
		scope=2;
		displayName="Nightstand Kit";
		descriptionShort="Can be deployed into a Nightstand in your base.  Dismantle with pliers or a screwdriver  Created by Diesel & Axobi";
		model="\DZ\structures\furniture\decoration\box_c\box_c.p3d";
		itemSize[]={4,4};
		carveNavmesh=1;
		canBeDigged=0;
		simulation="inventoryItem";
		physLayer="item_small";
		SingleUseActions[]={527};
		ContinuousActions[]={231};
		rotationFlags=2;
		InteractActions[]={};
		weight=300;
		itemBehaviour=2;
		class Cargo
		{
		};
	};
	class Base_Chernarus_Flag_Kit: WoodenCrate
	{
		scope=2;
		displayName="Chernarus Flag Kit";
		descriptionShort="Can be deployed into a Chernarus Flag on your base walls.  Dismantle with pliers or a screwdriver  Created by Diesel & Axobi";
		model="\DZ\structures\furniture\decoration\box_c\box_c.p3d";
		itemSize[]={4,4};
		carveNavmesh=1;
		canBeDigged=0;
		simulation="inventoryItem";
		physLayer="item_small";
		SingleUseActions[]={527};
		ContinuousActions[]={231};
		rotationFlags=2;
		InteractActions[]={};
		weight=300;
		itemBehaviour=2;
		class Cargo
		{
		};
	};
	class Base_CornerSofa_Kit: WoodenCrate
	{
		scope=2;
		displayName="Corner Sofa Kit";
		descriptionShort="Can be deployed into a Corner Sofa to decorate your base.  Dismantle with pliers or a screwdriver  Created by Diesel & Axobi";
		model="\DZ\structures\furniture\decoration\box_c\box_c.p3d";
		itemSize[]={4,4};
		carveNavmesh=1;
		canBeDigged=0;
		simulation="inventoryItem";
		physLayer="item_small";
		SingleUseActions[]={527};
		ContinuousActions[]={231};
		rotationFlags=2;
		InteractActions[]={};
		weight=300;
		itemBehaviour=2;
		class Cargo
		{
		};
	};
	class Base_LeatherSofa_Kit: WoodenCrate
	{
		scope=2;
		displayName="Leather Sofa Kit";
		descriptionShort="Can be deployed into a Leather Sofa to decorate your base.  Dismantle with pliers or a screwdriver  Created by Diesel & Axobi";
		model="\DZ\structures\furniture\decoration\box_c\box_c.p3d";
		itemSize[]={4,4};
		carveNavmesh=1;
		canBeDigged=0;
		simulation="inventoryItem";
		physLayer="item_small";
		SingleUseActions[]={527};
		ContinuousActions[]={231};
		rotationFlags=2;
		InteractActions[]={};
		weight=300;
		itemBehaviour=2;
		class Cargo
		{
		};
	};
	class Base_WoodStorage_Kit: WoodenCrate
	{
		scope=2;
		displayName="Wood Storage Kit";
		descriptionShort="Can be deployed into a wood storage container for your base.  Dismantle with pliers or a screwdriver  Created by Diesel & Axobi";
		model="\DZ\structures\furniture\decoration\box_c\box_c.p3d";
		itemSize[]={9,9};
		carveNavmesh=1;
		canBeDigged=0;
		simulation="inventoryItem";
		physLayer="item_small";
		SingleUseActions[]={527};
		ContinuousActions[]={231};
		rotationFlags=2;
		InteractActions[]={};
		weight=300;
		itemBehaviour=2;
		class Cargo
		{
		};
	};
	class Base_SingleBed_Kit: WoodenCrate
	{
		scope=2;
		displayName="Single Bed Kit";
		descriptionShort="Can be deployed into a Single Bed for your base.  Dismantle with pliers or a screwdriver  Created by Diesel & Axobi";
		model="\DZ\structures\furniture\decoration\box_c\box_c.p3d";
		itemSize[]={6,6};
		carveNavmesh=1;
		canBeDigged=0;
		simulation="inventoryItem";
		physLayer="item_large";
		SingleUseActions[]={527};
		ContinuousActions[]={231};
		rotationFlags=2;
		InteractActions[]={};
		weight=10000;
		itemBehaviour=2;
		class Cargo
		{
		};
	};
	class Base_CoffeeTable_Kit: WoodenCrate
	{
		scope=2;
		displayName="Coffee Table Kit";
		descriptionShort="Can be deployed into a Coffee Table for your base.  Dismantle with pliers or a screwdriver  Created by Diesel & Axobi";
		model="\DZ\structures\furniture\decoration\box_c\box_c.p3d";
		itemSize[]={4,4};
		carveNavmesh=1;
		canBeDigged=0;
		simulation="inventoryItem";
		physLayer="item_small";
		SingleUseActions[]={527};
		ContinuousActions[]={231};
		rotationFlags=2;
		InteractActions[]={};
		weight=300;
		itemBehaviour=2;
		class Cargo
		{
		};
	};
};
