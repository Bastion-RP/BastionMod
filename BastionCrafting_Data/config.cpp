class CfgPatches
{
	class BastionCrafting_Data
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] =
		{
			"DZ_Gear_Containers",
			"DZ_Gear_Crafting",
			"DZ_Gear_Tools",
			"DZ_Data"
		};
	};
};
class CfgMods
{
	class BastionCrafting_Data
	{
		dir = "BastionCrafting_Data";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "BastionCrafting_Data";
		credits = "RoomService";
		author = "RoomService";
		authorID = "0";
		version = "1.0";
		extra = 0;
		type = "mod";
		dependencies[] = {"World"};
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = {"BastionMod/BastionCrafting_Data/scripts/4_World"};
			};
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class Container_Base;
	class Barrel_ColorBase;
	class BarrelHoles_ColorBase;
	class FireplaceBase;
	class HouseNoDestruct;

	class BRP_Item: Container_Base
	{
		scope=0;
		destroyOnEmpty=0;
		varQuantityDestroyOnMin=0;
		descriptionShort="This can be dismantled with a screwdriver, pliers or hammer.";
		quantityBar=1;
		carveNavmesh=1;
		bounding="BSphere";
		overrideDrawArea="3.0";
		visibilityModifier=0.94999999;
		canBeDigged=0;
		alignHologramToTerain=0;
		heavyItem=1;
		weight=10;
		itemSize[]={10,10};
		itemBehaviour=1;
		physLayer="item_large";
		simulation="inventoryItem";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage=0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage=0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0;
					};
				};
			};
		};
	};

	class BRP_Item_HND: HouseNoDestruct
	{
		scope=0;
		descriptionShort="This can be dismantled with a screwdriver, pliers or hammer.";
		storageCategory=1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage=0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage=0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0;
					};
				};
			};
		};
	};
	class BRP_Kit: Container_Base
	{
		scope=0;
		displayName="Box Kit";
		descriptionShort="A cardboard box used to transport small items. Place to deploy item inside. The items can be dismantled with a screwdriver or pliers after deployment.";
		model="\BastionMod\BastionCrafting_Data\kitbox\kitbox.p3d";
		itemsCargoSize[]={0,0};
		itemSize[]={6,4};
		carveNavmesh=1;
		canBeDigged=0;
		simulation="inventoryItem";
		physLayer="item_small";
		rotationFlags=2;
		heavyItem=1;
		weight=3000;
		itemBehaviour=2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage=0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage=0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0;
					};
				};
			};
		};
	};

	class BRP_CraftingBenchBase : BRP_Item
	{
		scope = 2;
		descriptionShort="A table to store your tools and craft items. Attachments: 1x Hammer, 1x Hatchet, 3x Saws, 1x Screwdriver, 1x Pliers, 1x Wrench";
		attachments[]=
		{
			"Hammer1",
			"Hatchet1",
			"Pliers1",
			"Saw1",
			"Saw2",
			"Saw3",
			"Screwdriver1",
			"Wrench1"
		};
		class GUIInventoryAttachmentsProps
		{
			class MediumTools
			{
				name="Medium Tools";
				description="3x Saws, 1x Hatchet, 1x Hammer";
				attachmentSlots[]=
				{
					"Hatchet1",
					"Hammer1",
					"Saw1",
					"Saw2",
					"Saw3"
				};
				icon="cat_common_cargo";
			};
			class SmallTools
			{
				name="Small Tools";
				description="1x Screwdrivers, 1x Pliers, 1x Wrench";
				attachmentSlots[]=
				{
					"Pliers1",
					"Screwdriver1",
					"Wrench1"
				};
				icon="cat_common_cargo";
			};
		};
		class Cargo
		{
			itemsCargoSize[]={10,15};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
	};
	class BRP_CraftingTable_Kit: BRP_Kit
	{
		scope = 2;
		displayName = "Crafting Table Kit";
	};
	class BRP_CraftingTable: BRP_CraftingBenchBase
	{
		displayName="Crafting Table";
		descriptionShort="Table used for crafting";
		model = "\BastionMod\BastionCrafting_Data\craftingtable\craftingtable.p3d";
	};
	class BRP_CraftingTable_Static: BRP_CraftingBenchBase
	{
		displayName="Crafting Table";
		descriptionShort="Table used for crafting";
		model = "\BastionMod\BastionCrafting_Data\craftingtable\craftingtable.p3d";
	};	
	class BRP_CraftingTableStatic_Kit: BRP_Kit
	{
		scope = 2;
		displayName = "STATIC Crafting Table Kit";
	};	

	class BRP_Workbench1_Kit: BRP_Kit
	{
		scope = 2;
		displayName = "Workbench 1 Kit";
	};
	class BRP_Workbench1: BRP_CraftingBenchBase
	{
		displayName="Workbench";
		descriptionShort="Table used for crafting";
		model = "\BastionMod\BastionCrafting_Data\workbench\workbench1.p3d";
	};
	class BRP_Workbench1_Static: BRP_CraftingBenchBase
	{
		displayName="Workbench";
		descriptionShort="Table used for crafting";
		model = "\BastionMod\BastionCrafting_Data\workbench\workbench1.p3d";
	};	
	class BRP_Workbench1Static_Kit: BRP_Kit
	{
		scope = 2;
		displayName = "STATIC Workbench 1 Kit";
	};		
	class BRP_Workbench2_Kit: BRP_Kit
	{
		scope = 2;
		displayName = "Workbench 2 Kit";
	};
	class BRP_Workbench2: BRP_CraftingBenchBase
	{
		displayName="Workbench";
		descriptionShort="Table used for crafting";
		model = "\BastionMod\BastionCrafting_Data\workbench\workbench2.p3d";
	};
	class BRP_Workbench2_Static: BRP_CraftingBenchBase
	{
		displayName="Workbench";
		descriptionShort="Table used for crafting";
		model = "\BastionMod\BastionCrafting_Data\workbench\workbench2.p3d";
	};	
	class BRP_Workbench2Static_Kit: BRP_Kit
	{
		scope = 2;
		displayName = "STATIC Workbench 2 Kit";
	};			
	class BRP_Toolsbench_Base: BRP_CraftingBenchBase
	{
		displayName="Toolbench";
		descriptionShort="A bench to store your tools and craft items. Attachments: Axe, Pickaxe, Shovel, 3x Hammers, 5x Hatchets, 3x Saws, 2x Screwdrivers, 1x Pliers, 3x Metal Wire";
		scope = 0;
		model = "\BastionMod\BastionCrafting_Data\toolsbench\toolsbench.p3d";
		attachments[]=
		{
			"Axe1",
			"Hammer1",
			"Hammer2",
			"Hammer3",
			"Hatchet",
			"Hatchet1",
			"Hatchet2",
			"Hatchet3",
			"Hatchet4",
			"Pickaxe1",
			"Pliers1",
			"Saw1",
			"Saw2",
			"Saw3",
			"Screwdriver1",
			"Screwdriver2",
			"Shovel1",
			"Wire1",
			"Wire2",
			"Wire3"
		};
		class GUIInventoryAttachmentsProps
		{
			class Top
			{
				name="Top";
				description="3x Hammers, 5x Hatchets, 3x Saws";
				attachmentSlots[]=
				{
					"Saw1",
					"Saw2",
					"Saw3",
					"Hatchet2",
					"Hatchet3",
					"Hatchet4",
					"Hatchet",
					"Hatchet1",
					"Hammer1",
					"Hammer2",
					"Hammer3"
				};
				icon="cat_common_cargo";
			};
			class Side
			{
				name="Side";
				description="Axe, Pickaxe, Shovel";
				attachmentSlots[]=
				{
					"Shovel1",
					"Pickaxe1",
					"Axe1"
				};
				icon="cat_common_cargo";
			};
			class SmallTools
			{
				name="Small Tools";
				description="2x Screwdrivers, 1x Pliers";
				attachmentSlots[]=
				{
					"Pliers1",
					"Screwdriver1",
					"Screwdriver2"
				};
				icon="cat_common_cargo";
			};
			class Wires
			{
				name="Wires";
				description="3x Metal Wire";
				attachmentSlots[]=
				{
					"Wire1",
					"Wire2",
					"Wire3"
				};
				icon="cat_common_cargo";
			};
		};
		hiddenSelections[]=
		{
			"metalparts",
			"woodparts"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionCrafting_Data\toolsbench\data\toolsbench_blue_co.paa",
			"BastionMod\BastionCrafting_Data\toolsbench\data\toolsbench_wood_co.paa"
		};
	};

	class BRP_Toolsbench_Blue_Kit: BRP_Kit
	{
		scope = 2;
		displayName = "Toolsbench Blue Kit";
	};
	class BRP_Toolsbench_Blue: BRP_Toolsbench_Base
	{
		scope = 2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionCrafting_Data\toolsbench\data\toolsbench_blue_co.paa",
			"BastionMod\BastionCrafting_Data\toolsbench\data\toolsbench_wood_co.paa"
		};
	};
	class BRP_Toolsbench_Red_Kit: BRP_Kit
	{
		scope = 2;
		displayName = "Toolsbench Red Kit";
	};
	class BRP_Toolsbench_Red: BRP_Toolsbench_Base
	{
		scope = 2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionCrafting_Data\toolsbench\data\toolsbench_red_co.paa",
			"BastionMod\BastionCrafting_Data\toolsbench\data\toolsbench_wood_co.paa"
		};
	};
	class BRP_Toolsbench_Grey_Kit: BRP_Kit
	{
		scope = 2;
		displayName = "Toolsbench Grey Kit";
	};
	class BRP_Toolsbench_Grey: BRP_Toolsbench_Base
	{
		scope = 2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionCrafting_Data\toolsbench\data\toolsbench_grey_co.paa",
			"BastionMod\BastionCrafting_Data\toolsbench\data\toolsbench_wood_co.paa"
		};
	};

	//==============================================Barrel Furniture================================================>

	class BRP_BarrelChair_Avgas_Kit: BRP_Kit
	{
		scope = 2;
		displayName = "Barrel Chair Avgas Kit";
	};
	class BRP_BarrelChair_Avgas: BRP_Item
	{
		scope = 2;
		color = "Avgas";
		displayName = "Barrel Chair";
		descriptionShort = "A comfy seat crafted from an oil barrel.";
		model = "BastionMod\BastionCrafting_Data\barrelfurniture\BRP_BarrelChair.p3d";
		itemsCargoSize[] = {10,8};
		hiddenSelections[] =
		{
			"OilDrumCushion",
			"OilDrumSeat"
		};
		hiddenSelectionsTextures[] =
		{
			"bastionmod\bastioncrafting_data\barrelfurniture\data\brp_barrelchaircushions_co.paa",
			"BastionMod\BastionCrafting_Data\barrelfurniture\data\BRP_BarrelChair_Avgas_co.paa"
		};
	};
	class BRP_BarrelChair_Green_Kit: BRP_Kit
	{
		scope = 2;
		displayName = "Barrel Chair Green Kit";
	};
	class BRP_BarrelChair_Green: BRP_BarrelChair_Avgas
	{
		scope = 2;
		color = "Green";
		hiddenSelectionsTextures[] =
		{
			"bastionmod\bastioncrafting_data\barrelfurniture\data\brp_barrelchaircushions_co.paa",
			"BastionMod\BastionCrafting_Data\barrelfurniture\data\BRP_BarrelChair_Green_co.paa"
		};
	};
	class BRP_BarrelChair_Blue_Kit: BRP_Kit
	{
		scope = 2;
		displayName = "Barrel Chair Blue Kit";
	};
	class BRP_BarrelChair_Blue: BRP_BarrelChair_Avgas
	{
		scope = 2;
		color = "Blue";
		hiddenSelectionsTextures[] =
		{
			"bastionmod\bastioncrafting_data\barrelfurniture\data\brp_barrelchaircushions_co.paa",
			"BastionMod\BastionCrafting_Data\barrelfurniture\data\BRP_BarrelChair_Blue_co.paa"
		};
	};
	class BRP_BarrelChair_Red_Kit: BRP_Kit
	{
		scope = 2;
		displayName = "Barrel Chair Red Kit";
	};
	class BRP_BarrelChair_Red: BRP_BarrelChair_Avgas
	{
		scope = 2;
		color = "Red";
		hiddenSelectionsTextures[] =
		{
			"bastionmod\bastioncrafting_data\barrelfurniture\data\brp_barrelchaircushions_co.paa",
			"BastionMod\BastionCrafting_Data\barrelfurniture\data\BRP_BarrelChair_Red_co.paa"
		};
	};
	class BRP_BarrelChair_Yellow_Kit: BRP_Kit
	{
		scope = 2;
		displayName = "Barrel Chair Yellow Kit";
	};
	class BRP_BarrelChair_Yellow: BRP_BarrelChair_Avgas
	{
		scope = 2;
		color = "Yellow";
		hiddenSelectionsTextures[] =
		{
			"bastionmod\bastioncrafting_data\barrelfurniture\data\brp_barrelchaircushions_co.paa",
			"BastionMod\BastionCrafting_Data\barrelfurniture\data\BRP_BarrelChair_Yellow_co.paa"
		};
	};
	class BRP_BarrelChair_Danmak_Kit: BRP_Kit
	{
		scope = 2;
		displayName = "Barrel Chair Danmak Kit";
	};
	class BRP_BarrelChair_Danmak: BRP_BarrelChair_Avgas
	{
		scope = 2;
		color = "Danmak";
		hiddenSelectionsTextures[] =
		{
			"bastionmod\bastioncrafting_data\barrelfurniture\data\brp_barrelchaircushions_co.paa",
			"BastionMod\BastionCrafting_Data\barrelfurniture\data\BRP_BarrelChair_Danmak_co.paa"
		};
	};
	class BRP_BarrelTable_Danmak_Kit: BRP_Kit
	{
		scope = 2;
		displayName = "Barrel Table Danmak Kit";
	};
	class BRP_BarrelTable_Danmak: BRP_Item
	{
		scope = 2;
		color = "Danmak";
		displayName = "Barrel Table";
		descriptionShort = "A table crafted from an oil barrel.";
		model = "BastionMod\BastionCrafting_Data\barrelfurniture\BRP_BarrelTable.p3d";
		itemsCargoSize[] = {10,8};
		hiddenSelections[] = {"OilDrumTable"};
		hiddenSelectionsTextures[] = {"BastionMod\BastionCrafting_Data\barrelfurniture\data\BRP_BarrelTable_Danmak_ca.paa"};
	};
	class BRP_BarrelTable_Green_Kit: BRP_Kit
	{
		scope = 2;
		displayName = "Barrel Table Green Kit";
	};
	class BRP_BarrelTable_Green: BRP_BarrelTable_Danmak
	{
		scope = 2;
		color = "Green";
		hiddenSelectionsTextures[] = {"BastionMod\BastionCrafting_Data\barrelfurniture\data\BRP_BarrelTable_Green_ca.paa"};
	};
	class BRP_BarrelTable_Blue_Kit: BRP_Kit
	{
		scope = 2;
		displayName = "Barrel Table Blue Kit";
	};
	class BRP_BarrelTable_Blue: BRP_BarrelTable_Danmak
	{
		scope = 2;
		color = "Blue";
		hiddenSelectionsTextures[] = {"BastionMod\BastionCrafting_Data\barrelfurniture\data\BRP_BarrelTable_Blue_ca.paa"};
	};
	class BRP_BarrelTable_Red_Kit: BRP_Kit
	{
		scope = 2;
		displayName = "Barrel Table Red Kit";
	};
	class BRP_BarrelTable_Red: BRP_BarrelTable_Danmak
	{
		scope = 2;
		color = "Red";
		hiddenSelectionsTextures[] = {"BastionMod\BastionCrafting_Data\barrelfurniture\data\BRP_BarrelTable_Red_ca.paa"};
	};
	class BRP_BarrelTable_Yellow_Kit: BRP_Kit
	{
		scope = 2;
		displayName = "Barrel Table Yellow Kit";
	};
	class BRP_BarrelTable_Yellow: BRP_BarrelTable_Danmak
	{
		scope = 2;
		color = "Yellow";
		hiddenSelectionsTextures[] = {"BastionMod\BastionCrafting_Data\barrelfurniture\data\BRP_BarrelTable_Yellow_ca.paa"};
	};
	class BRP_BarrelTable_Avgas_Kit: BRP_Kit
	{
		scope = 2;
		displayName = "Barrel Table Avgas Kit";
	};
	class BRP_BarrelTable_Avgas: BRP_BarrelTable_Danmak
	{
		scope = 2;
		color = "Avgas";
		hiddenSelectionsTextures[] = {"BastionMod\BastionCrafting_Data\barrelfurniture\data\BRP_BarrelTable_Avgas_ca.paa"};
	};

	//small item
	class BRP_BarrelTableCactus: Inventory_Base
	{
		scope = 2;
		displayName = "Cactus";
		descriptionShort = "A decorative table cactus.";
		model = "BastionMod\BastionCrafting_Data\barrelfurniture\BRP_BarrelTableCactus.p3d";
		weight = 100;
		itemSize[] = {2,2};
		itemsCargoSize[] = {1,1};
		itemBehaviour = 2;
	};

	//retextures
	class BRP_Barrel_Danmak: Barrel_ColorBase
	{
		scope = 2;
		color = "Danmak";
		hiddenSelectionsTextures[] = {"BastionMod\BastionCrafting_Data\barrelfurniture\data\BRP_Barrel_Danmak_co.paa"};
		hologramMaterial = "barrel";
		hologramMaterialPath = "";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1,{"DZ\gear\containers\data\Barrel_yellow.rvmat"}},{0.7,{"DZ\gear\containers\data\Barrel_yellow.rvmat"}},{0.5,{"DZ\gear\containers\data\Barrel_yellow_damage.rvmat"}},{0.3,{"DZ\gear\containers\data\Barrel_yellow_damage.rvmat"}},{0,{"DZ\gear\containers\data\Barrel_yellow_destruct.rvmat"}}};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
			};
		};
	};
	class BarrelHoles_Danmak: BarrelHoles_ColorBase
	{
		scope = 2;
		color = "Danmak";
		hiddenSelectionsTextures[] = {"\dz\gear\cooking\data\stoneground_co.paa","BastionMod\BastionCrafting_Data\barrelfurniture\data\BRP_Barrel_Danmak_co.paa","BastionMod\BastionCrafting_Data\barrelfurniture\data\BRP_Barrel_Danmak_co.paa"};
		hologramMaterial = "Barrel";
		hologramMaterialPath = "";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1,{"DZ\gear\cooking\data\Barrel_yellow_holes.rvmat"}},{0.7,{"DZ\gear\cooking\data\Barrel_yellow_holes.rvmat"}},{0.5,{"DZ\gear\cooking\data\Barrel_yellow_holes_damage.rvmat"}},{0.3,{"DZ\gear\cooking\data\Barrel_yellow_holes_damage.rvmat"}},{0,{"DZ\gear\cooking\data\Barrel_yellow_holes_destruct.rvmat"}}};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
			};
		};
	};
	class BRP_Barrel_Avgas: Barrel_ColorBase
	{
		scope = 2;
		color = "Avgas";
		hiddenSelectionsTextures[] = {"BastionMod\BastionCrafting_Data\barrelfurniture\data\BRP_Barrel_Avgas_co.paa"};
		hologramMaterial = "barrel";
		hologramMaterialPath = "";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1,{"DZ\gear\containers\data\Barrel_red.rvmat"}},{0.7,{"DZ\gear\containers\data\Barrel_red.rvmat"}},{0.5,{"DZ\gear\containers\data\Barrel_red_damage.rvmat"}},{0.3,{"DZ\gear\containers\data\Barrel_red_damage.rvmat"}},{0,{"DZ\gear\containers\data\Barrel_red_destruct.rvmat"}}};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
			};
		};
	};
	class BarrelHoles_Avgas: BarrelHoles_ColorBase
	{
		scope = 2;
		color = "Avgas";
		hiddenSelectionsTextures[] = {"\dz\gear\cooking\data\stoneground_co.paa","BastionMod\BastionCrafting_Data\barrelfurniture\data\BRP_Barrel_Avgas_co.paa","BastionMod\BastionCrafting_Data\barrelfurniture\data\BRP_Barrel_Avgas_co.paa"};
		hologramMaterial = "Barrel";
		hologramMaterialPath = "";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1,{"DZ\gear\cooking\data\Barrel_red_holes.rvmat"}},{0.7,{"DZ\gear\cooking\data\Barrel_red_holes.rvmat"}},{0.5,{"DZ\gear\cooking\data\Barrel_red_holes_damage.rvmat"}},{0.3,{"DZ\gear\cooking\data\Barrel_red_holes_damage.rvmat"}},{0,{"DZ\gear\cooking\data\Barrel_red_holes_destruct.rvmat"}}};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
			};
		};
	};

	class BRP_Safe_Kit: BRP_Kit
	{
		scope = 2;
		displayName = "Safe Kit";
	};
	class BRP_Safe: BRP_Item
	{
		scope = 2;
		displayName = "Safe";
		model = "\BastionMod\BastionCrafting_Data\safe\safe.p3d";
		itemsCargoSize[] = {10,8};
	};

	class BRP_BoxingRing_Kit: BRP_Kit
	{
		scope = 2;
		weight = 10000;
		displayName = "Boxing Ring Kit";
	};
    class BRP_BoxingRing: BRP_Item_HND
    {
        scope = 2;
        model = "\BastionMod\BastionCrafting_Data\boxingring\boxing_ring.p3d";
    };
		//=================================================Fences===================================================>

	class BRP_Fence01_Kit: BRP_Kit
	{
		scope = 2;
		displayName = "Fence01 Kit";
	};
	class BRP_Fence01: BRP_Item
	{
		scope = 2;
		displayName = "Fence";
		descriptionShort = "A hand crafted fence.";
		model = "BastionMod\BastionCrafting_Data\fences\BRP_Fence01.p3d";
		hiddenSelections[] = {"FenceTexture01","FenceTexture02"};
		hiddenSelectionsTextures[] = {"BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture01_ca.paa","BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture02_ca.paa"};
		reversed=1;
	};
	class BRP_Fence02_Kit: BRP_Kit
	{
		scope = 2;
		displayName = "Fence02 Kit";
	};
	class BRP_Fence02: BRP_Item
	{
		scope = 2;
		displayName = "Fence";
		descriptionShort = "A hand crafted fence.";
		model = "BastionMod\BastionCrafting_Data\fences\BRP_Fence02.p3d";
		hiddenSelections[] = {"FenceTexture01","FenceTexture02"};
		hiddenSelectionsTextures[] = {"BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture01_ca.paa","BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture02_ca.paa"};
		reversed=1;
	};
	class BRP_Fence03_Kit: BRP_Kit
	{
		scope = 2;
		displayName = "Fence03 Kit";
	};
	class BRP_Fence03: BRP_Item
	{
		scope = 2;
		displayName = "Fence";
		descriptionShort = "A hand crafted fence.";
		model = "BastionMod\BastionCrafting_Data\fences\BRP_Fence03.p3d";
		hiddenSelections[] = {"FenceTexture01","FenceTexture02"};
		hiddenSelectionsTextures[] = {"BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture01_ca.paa","BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture02_ca.paa"};
		reversed=1;
	};
	class BRP_Fence04_Kit: BRP_Kit
	{
		scope = 2;
		displayName = "Fence04 Kit";
	};
	class BRP_Fence04: BRP_Item
	{
		scope = 2;
		displayName = "Fence";
		descriptionShort = "A hand crafted fence.";
		model = "BastionMod\BastionCrafting_Data\fences\BRP_Fence04.p3d";
		hiddenSelections[] = {"FenceTexture01","FenceTexture02"};
		hiddenSelectionsTextures[] = {"BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture01_ca.paa","BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture02_ca.paa"};
		reversed=1;
	};
	class BRP_Fence05_Kit: BRP_Kit
	{
		scope = 2;
		displayName = "Fence05 Kit";
	};
	class BRP_Fence05: BRP_Item
	{
		scope = 2;
		displayName = "Fence";
		descriptionShort = "A hand crafted fence.";
		model = "BastionMod\BastionCrafting_Data\fences\BRP_Fence05.p3d";
		hiddenSelections[] = {"FenceTexture01","FenceTexture02"};
		hiddenSelectionsTextures[] = {"BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture01_ca.paa","BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture02_ca.paa"};
		reversed=1;
	};
	class BRP_Fence06_Kit: BRP_Kit
	{
		scope = 2;
		displayName = "Fence06 Kit";
	};
	class BRP_Fence06: BRP_Item
	{
		scope = 2;
		displayName = "Fence";
		descriptionShort = "A hand crafted fence.";
		model = "BastionMod\BastionCrafting_Data\fences\BRP_Fence06.p3d";
		hiddenSelections[] = {"FenceTexture01","FenceTexture02"};
		hiddenSelectionsTextures[] = {"BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture01_ca.paa","BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture02_ca.paa"};
		reversed=1;
	};
	class BRP_Fence07_Kit: BRP_Kit
	{
		scope = 2;
		displayName = "Fence07 Kit";
	};
	class BRP_Fence07: BRP_Item
	{
		scope = 2;
		displayName = "Fence";
		descriptionShort = "A hand crafted fence.";
		model = "BastionMod\BastionCrafting_Data\fences\BRP_Fence07.p3d";
		hiddenSelections[] = {"FenceTexture01","FenceTexture02"};
		hiddenSelectionsTextures[] = {"BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture01_ca.paa","BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture02_ca.paa"};
		reversed=1;
	};
	class BRP_Fence11_Kit: BRP_Kit
	{
		scope = 2;
		displayName = "Fence11 Kit";
	};
	class BRP_Fence11: BRP_Item
	{
		scope = 2;
		displayName = "Fence";
		descriptionShort = "A hand crafted fence.";
		model = "BastionMod\BastionCrafting_Data\fences\BRP_Fence11.p3d";
		hiddenSelections[] = {"FenceTexture01","FenceTexture02"};
		hiddenSelectionsTextures[] = {"BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture01_ca.paa","BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture02_ca.paa"};
		reversed=1;
	};
	class BRP_Fence12_Kit: BRP_Kit
	{
		scope = 2;
		displayName = "Fence12 Kit";
	};
	class BRP_Fence12: BRP_Item
	{
		scope = 2;
		displayName = "Fence";
		descriptionShort = "A hand crafted fence.";
		model = "BastionMod\BastionCrafting_Data\fences\BRP_Fence12.p3d";
		hiddenSelections[] = {"FenceTexture01","FenceTexture02"};
		hiddenSelectionsTextures[] = {"BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture01_ca.paa","BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture02_ca.paa"};
		reversed=1;
	};
	class BRP_Fence13_Kit: BRP_Kit
	{
		scope = 2;
		displayName = "Fence13 Kit";
	};
	class BRP_Fence13: BRP_Item
	{
		scope = 2;
		displayName = "Fence";
		descriptionShort = "A hand crafted fence.";
		model = "BastionMod\BastionCrafting_Data\fences\BRP_Fence13.p3d";
		hiddenSelections[] = {"FenceTexture01","FenceTexture02"};
		hiddenSelectionsTextures[] = {"BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture01_ca.paa","BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture02_ca.paa"};
		reversed=1;
	};
	class BRP_Fence14_Kit: BRP_Kit
	{
		scope = 2;
		displayName = "Fence14 Kit";
	};
	class BRP_Fence14: BRP_Item
	{
		scope = 2;
		displayName = "Fence";
		descriptionShort = "A hand crafted fence.";
		model = "BastionMod\BastionCrafting_Data\fences\BRP_Fence14.p3d";
		hiddenSelections[] = {"FenceTexture01","FenceTexture02"};
		hiddenSelectionsTextures[] = {"BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture01_ca.paa","BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture02_ca.paa"};
		reversed=1;
	};
	class BRP_Fence15_Kit: BRP_Kit
	{
		scope = 2;
		displayName = "Fence15 Kit";
	};
	class BRP_Fence15: BRP_Item
	{
		scope = 2;
		displayName = "Fence";
		descriptionShort = "A hand crafted fence.";
		model = "BastionMod\BastionCrafting_Data\fences\BRP_Fence15.p3d";
		hiddenSelections[] = {"FenceTexture01","FenceTexture02"};
		hiddenSelectionsTextures[] = {"BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture01_ca.paa","BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture02_ca.paa"};
		reversed=1;
	};
	class BRP_Fence16_Kit: BRP_Kit
	{
		scope = 2;
		displayName = "Fence16 Kit";
	};
	class BRP_Fence16: BRP_Item
	{
		scope = 2;
		displayName = "Fence";
		descriptionShort = "A hand crafted fence.";
		model = "BastionMod\BastionCrafting_Data\fences\BRP_Fence16.p3d";
		hiddenSelections[] = {"FenceTexture01","FenceTexture02"};
		hiddenSelectionsTextures[] = {"BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture01_ca.paa","BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture02_ca.paa"};
		reversed=1;
	};
	class BRP_Fence17_Kit: BRP_Kit
	{
		scope = 2;
		displayName = "Fence17 Kit";
	};
	class BRP_Fence17: BRP_Item
	{
		scope = 2;
		displayName = "Fence";
		descriptionShort = "A hand crafted fence.";
		model = "BastionMod\BastionCrafting_Data\fences\BRP_Fence17.p3d";
		hiddenSelections[] = {"FenceTexture01","FenceTexture02"};
		hiddenSelectionsTextures[] = {"BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture01_ca.paa","BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture02_ca.paa"};
		reversed=1;
	};
	class BRP_Fence18_Kit: BRP_Kit
	{
		scope = 2;
		displayName = "Fence18 Kit";
	};
	class BRP_Fence18: BRP_Item
	{
		scope = 2;
		displayName = "Fence";
		descriptionShort = "A hand crafted fence.";
		model = "BastionMod\BastionCrafting_Data\fences\BRP_Fence18.p3d";
		hiddenSelections[] = {"FenceTexture01","FenceTexture02"};
		hiddenSelectionsTextures[] = {"BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture01_ca.paa","BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture02_ca.paa"};
		reversed=1;
	};
	class BRP_Fence19_Kit: BRP_Kit
	{
		scope = 2;
		displayName = "Fence19 Kit";
	};
	class BRP_Fence19: BRP_Item
	{
		scope = 2;
		displayName = "Fence";
		descriptionShort = "A hand crafted fence.";
		model = "BastionMod\BastionCrafting_Data\fences\BRP_Fence19.p3d";
		hiddenSelections[] = {"FenceTexture01","FenceTexture02"};
		hiddenSelectionsTextures[] = {"BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture01_ca.paa","BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture02_ca.paa"};
		reversed=1;
	};
	class BRP_Fence20_Kit: BRP_Kit
	{
		scope = 2;
		displayName = "Fence20 Kit";
	};
	class BRP_Fence20: BRP_Item
	{
		scope = 2;
		displayName = "Fence";
		descriptionShort = "A hand crafted fence.";
		model = "BastionMod\BastionCrafting_Data\fences\BRP_Fence20.p3d";
		hiddenSelections[] = {"FenceTexture01","FenceTexture02"};
		hiddenSelectionsTextures[] = {"BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture01_ca.paa","BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture02_ca.paa"};
		reversed=1;
	};
	class BRP_Fence21_Kit: BRP_Kit
	{
		scope = 2;
		displayName = "Fence21 Kit";
	};
	class BRP_Fence21: BRP_Item
	{
		scope = 2;
		displayName = "Fence";
		descriptionShort = "A hand crafted fence.";
		model = "BastionMod\BastionCrafting_Data\fences\BRP_Fence21.p3d";
		hiddenSelections[] = {"FenceTexture01","FenceTexture02"};
		hiddenSelectionsTextures[] = {"BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture01_ca.paa","BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture02_ca.paa"};
		reversed=1;
	};
	class BRP_Fence22_Kit: BRP_Kit
	{
		scope = 2;
		displayName = "Fence22 Kit";
	};
	class BRP_Fence22: BRP_Item
	{
		scope = 2;
		displayName = "Fence";
		descriptionShort = "A hand crafted fence.";
		model = "BastionMod\BastionCrafting_Data\fences\BRP_Fence22.p3d";
		hiddenSelections[] = {"FenceTexture01","FenceTexture02"};
		hiddenSelectionsTextures[] = {"BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture01_ca.paa","BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture02_ca.paa"};
		reversed=1;
	};
	class BRP_Fence23_Kit: BRP_Kit
	{
		scope = 2;
		displayName = "Fence23 Kit";
	};
	class BRP_Fence23: BRP_Item
	{
		scope = 2;
		displayName = "Fence";
		descriptionShort = "A hand crafted fence.";
		model = "BastionMod\BastionCrafting_Data\fences\BRP_Fence23.p3d";
		hiddenSelections[] = {"FenceTexture01","FenceTexture02"};
		hiddenSelectionsTextures[] = {"BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture01_ca.paa","BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture02_ca.paa"};
		reversed=1;
	};
	class BRP_Fence24_Kit: BRP_Kit
	{
		scope = 2;
		displayName = "Fence24 Kit";
	};
	class BRP_Fence24: BRP_Item
	{
		scope = 2;
		displayName = "Fence";
		descriptionShort = "A hand crafted fence.";
		model = "BastionMod\BastionCrafting_Data\fences\BRP_Fence24.p3d";
		hiddenSelections[] = {"FenceTexture01","FenceTexture02"};
		hiddenSelectionsTextures[] = {"BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture01_ca.paa","BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture02_ca.paa"};
		reversed=1;
	};
	class BRP_Fence25_Kit: BRP_Kit
	{
		scope = 2;
		displayName = "Fence25 Kit";
	};
	class BRP_Fence25: BRP_Item
	{
		scope = 2;
		displayName = "Fence";
		descriptionShort = "A hand crafted fence.";
		model = "BastionMod\BastionCrafting_Data\fences\BRP_Fence25.p3d";
		hiddenSelections[] = {"FenceTexture01","FenceTexture02"};
		hiddenSelectionsTextures[] = {"BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture01_ca.paa","BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture02_ca.paa"};
		reversed=1;
	};
	class BRP_Fence26_Kit: BRP_Kit
	{
		scope = 2;
		displayName = "Fence26 Kit";
	};
	class BRP_Fence26: BRP_Item
	{
		scope = 2;
		displayName = "Fence";
		descriptionShort = "A hand crafted fence.";
		model = "BastionMod\BastionCrafting_Data\fences\BRP_Fence26.p3d";
		hiddenSelections[] = {"FenceTexture01","FenceTexture02"};
		hiddenSelectionsTextures[] = {"BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture01_ca.paa","BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture02_ca.paa"};
		reversed=1;
	};
	class BRP_Fence27_Kit: BRP_Kit
	{
		scope = 2;
		displayName = "Fence27 Kit";
	};
	class BRP_Fence27: BRP_Item
	{
		scope = 2;
		displayName = "Fence";
		descriptionShort = "A hand crafted fence.";
		model = "BastionMod\BastionCrafting_Data\fences\BRP_Fence27.p3d";
		hiddenSelections[] = {"FenceTexture01","FenceTexture02"};
		hiddenSelectionsTextures[] = {"BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture01_ca.paa","BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture02_ca.paa"};
		reversed=1;
	};
	class BRP_Fence28_Kit: BRP_Kit
	{
		scope = 2;
		displayName = "Fence28 Kit";
	};
	class BRP_Fence28: BRP_Item
	{
		scope = 2;
		displayName = "Fence";
		descriptionShort = "A hand crafted fence.";
		model = "BastionMod\BastionCrafting_Data\fences\BRP_Fence28.p3d";
		hiddenSelections[] = {"FenceTexture01","FenceTexture02"};
		hiddenSelectionsTextures[] = {"BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture01_ca.paa","BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture02_ca.paa"};
		reversed=1;
	};
	class BRP_Fence29_Kit: BRP_Kit
	{
		scope = 2;
		displayName = "Fence29 Kit";
	};
	class BRP_Fence29: BRP_Item
	{
		scope = 2;
		displayName = "Fence";
		descriptionShort = "A hand crafted fence.";
		model = "BastionMod\BastionCrafting_Data\fences\BRP_Fence29.p3d";
		hiddenSelections[] = {"FenceTexture01","FenceTexture02"};
		hiddenSelectionsTextures[] = {"BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture01_ca.paa","BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture02_ca.paa"};
		reversed=1;
	};
	class BRP_Fence30_Kit: BRP_Kit
	{
		scope = 2;
		displayName = "Fence30 Kit";
	};
	class BRP_Fence30: BRP_Item
	{
		scope = 2;
		displayName = "Fence";
		descriptionShort = "A hand crafted fence.";
		model = "BastionMod\BastionCrafting_Data\fences\BRP_Fence30.p3d";
		hiddenSelections[] = {"FenceTexture01","FenceTexture02"};
		hiddenSelectionsTextures[] = {"BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture01_ca.paa","BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture02_ca.paa"};
		reversed=1;
	};
	class BRP_Fence31_Kit: BRP_Kit
	{
		scope = 2;
		displayName = "Fence31 Kit";
	};
	class BRP_Fence31: BRP_Item
	{
		scope = 2;
		displayName = "Fence";
		descriptionShort = "A hand crafted fence.";
		model = "BastionMod\BastionCrafting_Data\fences\BRP_Fence31.p3d";
		hiddenSelections[] = {"FenceTexture01","FenceTexture02"};
		hiddenSelectionsTextures[] = {"BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture01_ca.paa","BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture02_ca.paa"};
		reversed=1;
	};
	class BRP_Fence32_Kit: BRP_Kit
	{
		scope = 2;
		displayName = "Fence32 Kit";
	};
	class BRP_Fence32: BRP_Item
	{
		scope = 2;
		displayName = "Fence";
		descriptionShort = "A hand crafted fence.";
		model = "BastionMod\BastionCrafting_Data\fences\BRP_Fence32.p3d";
		hiddenSelections[] = {"FenceTexture01","FenceTexture02"};
		hiddenSelectionsTextures[] = {"BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture01_ca.paa","BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture02_ca.paa"};
		reversed=1;
	};
	class BRP_Fence33_Kit: BRP_Kit
	{
		scope = 2;
		displayName = "Fence33 Kit";
	};
	class BRP_Fence33: BRP_Item
	{
		scope = 2;
		displayName = "Fence";
		descriptionShort = "A hand crafted fence.";
		model = "BastionMod\BastionCrafting_Data\fences\BRP_Fence33.p3d";
		hiddenSelections[] = {"FenceTexture01","FenceTexture02"};
		hiddenSelectionsTextures[] = {"BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture01_ca.paa","BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture02_ca.paa"};
		reversed=1;
	};
	class BRP_Fence34_Kit: BRP_Kit
	{
		scope = 2;
		displayName = "Fence34 Kit";
	};
	class BRP_Fence34: BRP_Item
	{
		scope = 2;
		displayName = "Fence";
		descriptionShort = "A hand crafted fence.";
		model = "BastionMod\BastionCrafting_Data\fences\BRP_Fence34.p3d";
		hiddenSelections[] = {"FenceTexture01","FenceTexture02"};
		hiddenSelectionsTextures[] = {"BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture01_ca.paa","BastionMod\BastionCrafting_Data\fences\data\BRP_FenceTexture02_ca.paa"};
		reversed=1;
	};

	class BRP_SewingMachine: Inventory_Base
	{
		scope = 2;
		displayName = "Sewing Machine";
		descriptionShort = "A sewing machine.";
		model = "BastionMod\BastionCrafting_Data\sewingmachine\BRP_SewingMachine.p3d";
		weight = 500;
		itemSize[] = {4,2};
		itemBehaviour = 2;
	};

	//==============================================Furnace================================================>

	class BRP_Furnace_Kit: BRP_Kit
	{
		scope = 2;
		displayName = "Furnace Kit";
		descriptionShort = "A hand made furnace kit. Place to begin construction.";
	};
	class BRP_Furnace_Hologram: Inventory_Base
	{
		scope = 2;
		displayName = "Furnace Hologram";
		descriptionShort = "xD";
		model = "\BastionMod\BastionCrafting_Data\furnace\BRP_Furnace_Hologram.p3d";
		overrideDrawArea = "8.0";
		itemBehaviour = 2;
		attachments[] = {};
		carveNavmesh = 1;
		lootCategory = "Tents";
		placement = "ForceSlopeOnTerrain";
		physLayer = "item_large";
		rotationFlags = 2;
		class GUIInventoryAttachmentsProps{};
	};
	class BRP_Furnace_Fireplace: FireplaceBase
	{
		scope = 2;
		displayName = "Furnace";
		descriptionShort = "A hand made furnace.";
		model = "\BastionMod\BastionCrafting_Data\furnace\BRP_FurnaceFireplace.p3d";
		overrideDrawArea = "8.0";
		slopeTolerance = 0.3;
		physLayer = "item_large";
		lootCategory = "Crafted";
		itemSize[] = {10,20};
		itemsCargoSize[]={10,10};
		openable=0;
		allowOwnedCargoManipulation=1;
		useEntityHierarchy = "true";
		hiddenSelections[] =
		{
			"zbytek"
		};
		hiddenSelectionsTextures[] =
		{
			"bastionmod\bastioncrafting_data\furnace\data\brp_furnace_co.paa"
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class movement
				{
					soundSet = "barrel_movement_SoundSet";
					id = 1;
				};
				class pickUpItem_Light
				{
					soundSet = "pickUpBarrelLight_SoundSet";
					id = 796;
				};
				class pickUpItem
				{
					soundSet = "pickUpBarrel_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "barrel_drop_SoundSet";
					id = 898;
				};
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1,{"DZ\gear\cooking\data\Barrel_red_holes.rvmat"}},{0.7,{"DZ\gear\cooking\data\Barrel_red_holes.rvmat"}},{0.5,{"DZ\gear\cooking\data\Barrel_red_holes_damage.rvmat"}},{0.3,{"DZ\gear\cooking\data\Barrel_red_holes_damage.rvmat"}},{0,{"DZ\gear\cooking\data\Barrel_red_holes_destruct.rvmat"}}};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
			};
		};
	};

	//crafting materials
	class BRP_Coal: Inventory_Base
	{
		scope = 2;
		displayName = "Charcoal";
		descriptionShort = "A briquette of charcoal. Useful for smelting in the furnace.";
		model = "BastionMod\BastionCrafting_Data\coal\coal.p3d";
		isMeleeWeapon = 0;
		rotationFlags=16;
		weight = 300;
		absorbency = 0;
		itemSize[] = {2,2};
		itemBehaviour = 1;
	};
	class BRP_MetalScrap: Inventory_Base
	{
		scope = 2;
		displayName = "Metal Scrap";
		descriptionShort = "Small sheets of scrap metal. Useful for crafting.";
		model = "BastionMod\BastionCrafting_Data\metalsheets\metalscrap_small1.p3d";
		isMeleeWeapon = 0;
		rotationFlags=16;
		weight = 250;
		absorbency = 0;
		itemSize[] = {2,2};
		itemBehaviour = 1;
		canBeSplit = 1;		
		varQuantityInit = 1.0;
		varQuantityMin = 0.0;
		varQuantityMax = 6.0;
		varQuantityDestroyOnMin = 1;
		varStackMax = 6.0;			
	};
	class BRP_MetalSheet_Small2: Inventory_Base
	{
		scope = 2;
		displayName = "Metal Scrap";
		descriptionShort = "Small sheets of scrap metal. Useful for crafting.";
		model = "BastionMod\BastionCrafting_Data\metalsheets\metalscrap_small2.p3d";
		isMeleeWeapon = 0;
		rotationFlags=16;
		weight = 300;
		absorbency = 0;
		itemSize[] = {3,3};
		itemBehaviour = 1;
	};
	class BRP_ComputerComponent: Inventory_Base
	{
		scope = 2;
		displayName = "Computer Component";
		descriptionShort = "A computer component. Useful for crafting.";
		model = "BastionMod\BastionCrafting_Data\raspberry\pi.p3d";
		isMeleeWeapon = 0;
		rotationFlags=16;
		weight = 50;
		absorbency = 0;
		itemSize[] = {1,1};
		itemBehaviour = 1;
	};
	class BRP_WoodScrap: Inventory_Base
	{
		scope = 2;
		displayName = "Wood Scrap";
		descriptionShort = "Pieces of wooden scrap. Useful for crafting.";
		model = "BastionMod\BastionCrafting_Data\woodscrap\woodscrap.p3d";
		isMeleeWeapon = 0;
		rotationFlags=16;
		weight = 500;
		absorbency = 0;
		itemSize[] = {2,3};
		itemBehaviour = 1;
		canBeSplit = 1;				
		varQuantityInit = 1.0;
		varQuantityMin = 0.0;
		varQuantityMax = 2.0;
		varQuantityDestroyOnMin = 1;
		varStackMax = 2.0;			
	};
	class BRP_Woodscrap2: Inventory_Base
	{
		scope = 2;
		displayName = "Wood Scrap";
		descriptionShort = "Pieces of wooden scrap. Useful for crafting.";
		model = "BastionMod\BastionCrafting_Data\woodscrap\woodscrap2.p3d";
		isMeleeWeapon = 0;
		rotationFlags=16;
		weight = 500;
		absorbency = 0;
		itemSize[] = {2,3};
		itemBehaviour = 1;
		canBeSplit = 1;				
		varQuantityInit = 1.0;
		varQuantityMin = 0.0;
		varQuantityMax = 2.0;
		varQuantityDestroyOnMin = 1;
		varStackMax = 2.0;			
	};
	class BRP_PlasticScrap: Inventory_Base
	{
		scope = 2;
		displayName = "Plastic Scrap";
		descriptionShort = "Pieces of melted plastic. Useful for crafting.";
		model = "BastionMod\BastionCrafting_Data\plasticpieces\plastic.p3d";
		isMeleeWeapon = 0;
		rotationFlags=16;
		weight = 50;
		absorbency = 0;
		itemSize[] = {2,2};
		itemBehaviour = 1;
		canBeSplit = 1;				
		varQuantityInit = 1.0;
		varQuantityMin = 0.0;
		varQuantityMax = 15.0;
		varQuantityDestroyOnMin = 1;
		varStackMax = 15.0;		
	};
	class BRP_FirearmPart: Inventory_Base
	{
		scope = 2;
		displayName = "Firearm Parts";
		descriptionShort = "Parts of various weapons, some in not very good condition. Can be useful anyway.";
		model = "BastionMod\BastionCrafting_Data\weaponparts\weaponparts.p3d";
		rotationFlags = 2;
		isMeleeWeapon=0;
		weight = 250;
		absorbency = 0.0;
		itemBehaviour = 1;
		heavyItem = 1;
		itemSize[] = {4,2};
		canBeSplit = 1;				
		varQuantityInit = 1.0;
		varQuantityMin = 0.0;
		varQuantityMax = 4.0;
		varQuantityDestroyOnMin = 1;
		varStackMax = 4.0;		
		hiddenSelections[]=
		{
			"all"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionCrafting_Data\weaponparts\data\weaponparts_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 60;
					healthLevels[] =
					{
						{1.0,{"BastionMod\BastionCrafting_Data\weaponparts\data\weaponparts.rvmat"}},
						{0.7,{"BastionMod\BastionCrafting_Data\weaponparts\data\weaponparts.rvmat"}},
						{0.5,{"BastionMod\BastionCrafting_Data\weaponparts\data\weaponparts_damage.rvmat"}},
						{0.3,{"BastionMod\BastionCrafting_Data\weaponparts\data\weaponparts_damage.rvmat"}},
						{0.0,{"BastionMod\BastionCrafting_Data\weaponparts\data\weaponparts_destruct.rvmat"}}
					};
				};
			};
		};
	};

	//slots
	class Wrench: Inventory_Base
	{
		inventorySlot[]=
		{
			"Wrench1"
		};
	};
	class WoodAxe: Inventory_Base
	{
		inventorySlot[]=
		{
			"Shoulder",
			"Melee",
			"Axe1"
		};
	};
	class FirefighterAxe: Inventory_Base
	{
		inventorySlot[]=
		{
			"Shoulder",
			"Melee",
			"Axe1"
		};
	};
	class Pickaxe: Inventory_Base
	{
		inventorySlot[]=
		{
			"Shoulder",
			"Melee",
			"Pickaxe1"
		};
	};
	class Hatchet: Inventory_Base
	{
		inventorySlot[]=
		{
			"MassTool",
			"Hatchet",
			"Hatchet1",
			"Hatchet2",
			"Hatchet3",
			"Hatchet4"
		};
	};
	class Hammer: Inventory_Base
	{
		inventorySlot[]=
		{
			"Hammer",
			"MassHammer",
			"Hammer1",
			"Hammer2",
			"Hammer3"
		};
	};
	class Shovel: Inventory_Base
	{
		inventorySlot[]=
		{
			"Shoulder",
			"Melee",
			"Shovel1"
		};
	};
	class Pliers: Inventory_Base
	{
		inventorySlot[]=
		{
			"Pliers",
			"Pliers1"
		};
	};
	class HandSaw: Inventory_Base
	{
		inventorySlot[]=
		{
			"HandSaw",
			"Saw",
			"Saw1",
			"Saw2",
			"Saw3"
		};
	};
	class Hacksaw: Inventory_Base
	{
		inventorySlot[]=
		{
			"Hacksaw",
			"Saw",
			"Saw1",
			"Saw2",
			"Saw3"
		};
	};
	class Screwdriver: Inventory_Base
	{
		inventorySlot[]=
		{
			"Screwdriver",
			"MassScrewDriver",
			"Screwdriver1",
			"Screwdriver2"
		};
	};
	class MetalWire: Inventory_Base
	{
		inventorySlot[]=
		{
			"MetalWire",
			"Material_MetalWire",
			"Wire1",
			"Wire2",
			"Wire3"
		};
	};
};

class CfgSlots
{
	class Slot_Wrench1
	{
		name="Wrench1";
		displayName="Wrench1";
		ghostIcon="shoulderleft";
	};
	class Slot_Axe1
	{
		name="Axe1";
		displayName="Axe1";
		ghostIcon="shoulderleft";
	};
	class Slot_Hatchet
	{
		name="Hatchet";
		displayName="Hatchet";
		ghostIcon="shoulderleft";
	};
	class Slot_Hatchet1
	{
		name="Hatchet1";
		displayName="Hatchet1";
		ghostIcon="shoulderleft";
	};
	class Slot_Hatchet2
	{
		name="Hatchet2";
		displayName="Hatchet2";
		ghostIcon="shoulderleft";
	};
	class Slot_Hatchet3
	{
		name="Hatchet3";
		displayName="Hatchet3";
		ghostIcon="shoulderleft";
	};
	class Slot_Hatchet4
	{
		name="Hatchet4";
		displayName="Hatchet4";
		ghostIcon="shoulderleft";
	};
	class Slot_Pickaxe1
	{
		name="Pickaxe1";
		displayName="Pickaxe1";
		ghostIcon="shoulderleft";
	};
	class Slot_Pliers1
	{
		name="Pliers1";
		displayName="Pliers1";
		ghostIcon="";
	};
	class Slot_Screwdriver1
	{
		name="Screwdriver1";
		displayName="Screwdriver1";
		ghostIcon="";
	};
	class Slot_Screwdriver2
	{
		name="Screwdriver2";
		displayName="Screwdriver2";
		ghostIcon="";
	};
	class Slot_Shovel1
	{
		name="Shovel1";
		displayName="Shovel1";
		ghostIcon="shoulderleft";
	};
	class Slot_Hammer1
	{
		name="Hammer1";
		displayName="Hammer1";
		ghostIcon="";
	};
	class Slot_Hammer2
	{
		name="Hammer2";
		displayName="Hammer2";
		ghostIcon="";
	};
	class Slot_Hammer3
	{
		name="Hammer3";
		displayName="Hammer3";
		ghostIcon="";
	};
	class Slot_Saw1
	{
		name="Saw1";
		displayName="Saw1";
		ghostIcon="";
	};
	class Slot_Saw2
	{
		name="Saw2";
		displayName="Saw2";
		ghostIcon="";
	};
	class Slot_Saw3
	{
		name="Saw3";
		displayName="Saw3";
		ghostIcon="";
	};
	class Slot_Wire1
	{
		name="Wire1";
		displayName="Wire1";
		ghostIcon="metalwire";
	};
	class Slot_Wire2
	{
		name="Wire2";
		displayName="Wire2";
		ghostIcon="metalwire";
	};
	class Slot_Wire3
	{
		name="Wire3";
		displayName="Wire3";
		ghostIcon="metalwire";
	};
};

class CfgNonAIVehicles
{
	class ProxyAttachment;
	class Proxywrench1: ProxyAttachment
	{
		scope=2;
		inventorySlot[] = { "Wrench1" };
		model="\BastionMod\BastionCrafting_Data\proxies\tools\wrench1.p3d";
	};
	class Proxyaxe1: ProxyAttachment
	{
		scope=2;
		inventorySlot[] = { "Axe1" };
		model="\BastionMod\BastionCrafting_Data\proxies\tools\axe1.p3d";
	};
	class Proxypickaxe1: ProxyAttachment
	{
		scope=2;
		inventorySlot[] = { "Pickaxe1" };
		model="\BastionMod\BastionCrafting_Data\proxies\tools\pickaxe1.p3d";
	};
	class Proxypliers1: ProxyAttachment
	{
		scope=2;
		inventorySlot[] = { "Pliers1" };
		model="\BastionMod\BastionCrafting_Data\proxies\tools\pliers1.p3d";
	};
	class Proxyhatchet1: ProxyAttachment
	{
		scope=2;
		inventorySlot[] = { "Hatchet1" };
		model="\BastionMod\BastionCrafting_Data\proxies\tools\hatchet1.p3d";
	};
	class Proxyhatchet2: ProxyAttachment
	{
		scope=2;
		inventorySlot[] = { "Hatchet2" };
		model="\BastionMod\BastionCrafting_Data\proxies\tools\hatchet2.p3d";
	};
	class Proxyhatchet3: ProxyAttachment
	{
		scope=2;
		inventorySlot[] = { "Hatchet3" };
		model="\BastionMod\BastionCrafting_Data\proxies\tools\hatchet3.p3d";
	};
	class Proxyhatchet4: ProxyAttachment
	{
		scope=2;
		inventorySlot[] = { "Hatchet4" };
		model="\BastionMod\BastionCrafting_Data\proxies\tools\hatchet4.p3d";
	};
	class Proxyhatchet5: ProxyAttachment
	{
		scope=2;
		inventorySlot[] = { "Hatchet" };
		model="\BastionMod\BastionCrafting_Data\proxies\tools\hatchet5.p3d";
	};
	class Proxyscrewdriver1: ProxyAttachment
	{
		scope=2;
		inventorySlot[] = { "Screwdriver1" };
		model="\BastionMod\BastionCrafting_Data\proxies\tools\screwdriver1.p3d";
	};
	class Proxyscrewdriver2: ProxyAttachment
	{
		scope=2;
		inventorySlot[] = { "Screwdriver2" };
		model="\BastionMod\BastionCrafting_Data\proxies\tools\screwdriver2.p3d";
	};
	class Proxyshovel1: ProxyAttachment
	{
		scope=2;
		inventorySlot[] = { "Shovel1" };
		model="\BastionMod\BastionCrafting_Data\proxies\tools\shovel1.p3d";
	};

	class Proxyhammer1: ProxyAttachment
	{
		scope=2;
		inventorySlot[] = { "Hammer1" };
		model="\BastionMod\BastionCrafting_Data\proxies\tools\hammer1.p3d";
	};
	class Proxyhammer2: ProxyAttachment
	{
		scope=2;
		inventorySlot[] = { "Hammer2" };
		model="\BastionMod\BastionCrafting_Data\proxies\tools\hammer2.p3d";
	};
	class Proxyhammer3: ProxyAttachment
	{
		scope=2;
		inventorySlot[] = { "Hammer3" };
		model="\BastionMod\BastionCrafting_Data\proxies\tools\hammer3.p3d";
	};
	class Proxysaw1: ProxyAttachment
	{
		scope=2;
		inventorySlot[] = { "Saw1" };
		model="\BastionMod\BastionCrafting_Data\proxies\tools\saw1.p3d";
	};
	class Proxysaw2: ProxyAttachment
	{
		scope=2;
		inventorySlot[] = { "Saw2" };
		model="\BastionMod\BastionCrafting_Data\proxies\tools\saw2.p3d";
	};
	class Proxysaw3: ProxyAttachment
	{
		scope=2;
		inventorySlot[] = { "Saw3" };
		model="\BastionMod\BastionCrafting_Data\proxies\tools\saw3.p3d";
	};
	class Proxywire1: ProxyAttachment
	{
		scope=2;
		inventorySlot[] = { "Wire1" };
		model="\BastionMod\BastionCrafting_Data\proxies\tools\wire1.p3d";
	};
	class Proxywire2: ProxyAttachment
	{
		scope=2;
		inventorySlot[] = { "Wire2" };
		model="\BastionMod\BastionCrafting_Data\proxies\tools\wire2.p3d";
	};
	class Proxywire3: ProxyAttachment
	{
		scope=2;
		inventorySlot[] = { "Wire3" };
		model="\BastionMod\BastionCrafting_Data\proxies\tools\wire3.p3d";
	};
	
	class BRP_CraftingBook_INTERPOL: ItemBook
    {
        scope = 2;
        title = "INTERPOL Armorer's Guide, Volume 2"; //name
        author = "Mack Nelson"; //author
        file = "dz\gear\books\non-fiction\Bible.html"; //seems like it's path for text
        lootTag[] = {"Religious"}; //obsolete, not needed anymore
        displayName = "INTERPOL Armorer's Guide, Volume 2"; //item name
        descriptionShort = "Armorer's Guide, distributed to INTERPOL member states."; //item description
        rotationFlags = 1; //rotation of object after item was dropped/spawned
        hiddenSelectionsTextures[] = {"\BastionMod\BastionCrafting_Data\Retextures\data\"}; // texture of book
    };
};

