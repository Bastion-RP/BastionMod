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
			"DZ_Data"
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class Container_Base;
	class Barrel_ColorBase;
	class BarrelHoles_ColorBase;
	class BRP_CraftingBenchBase : Container_Base
	{
		scope = 1;
		itemSize[]={10,15};
		overrideDrawArea="8.0";
		forceFarBubble="true";
		slopeTolerance=0.30000001;
		destroyOnEmpty=0;
		varQuantityDestroyOnMin=0;
		quantityBar=1;
		carveNavmesh=1;
		canBeDigged=0;
		heavyItem=1;
		weight=10000;
		itemBehaviour=0;
		stackedUnit="ml";
		randomQuantity=2;
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=200000;
		absorbency=0.1;
		physLayer="item_large";
		allowOwnedCargoManipulation=1;
		class Cargo
		{
			itemsCargoSize[]={10,15};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
	};
	class BRP_CraftingTable: BRP_CraftingBenchBase
	{
		displayName="Crafting Table";
		descriptionShort="Table used for crafting";
		model = "\BastionMod\BastionCrafting_Data\craftingtable\craftingtable.p3d";
	};
	class BRP_Workbench_Base : BRP_CraftingBenchBase
	{
		displayName="Workbench";
		descriptionShort="Table used for crafting";
	};
	class BRP_Workbench1: BRP_Workbench_Base
	{
		model = "\BastionMod\BastionCrafting_Data\workbench\workbench1.p3d";
	};
	class BRP_Workbench2: BRP_Workbench_Base
	{
		model = "\BastionMod\BastionCrafting_Data\workbench\workbench2.p3d";
	};
	class BRP_Toolsbench_Base: BRP_CraftingBenchBase
	{
		displayName="Toolbench";
		descriptionShort="Table used for crafting";
		scope = 0;
		model = "\BastionMod\BastionCrafting_Data\toolsbench\toolsbench.p3d";
		hiddenSelections[]=
		{
			"",
			"metalparts",
			"woodparts"
		};
		hiddenSelectionsTextures[]=
		{
			"",
			"BastionMod\BastionCrafting_Data\toolsbench\data\toolsbench_blue_co.paa",
			"BastionMod\BastionCrafting_Data\toolsbench\data\toolsbench_wood_co.paa"
		};
	};
	class BRP_Toolsbench_Blue: BRP_Toolsbench_Base
	{
		scope = 1;
		hiddenSelectionsTextures[]=
		{
			"",
			"BastionMod\BastionCrafting_Data\toolsbench\data\toolsbench_blue_co.paa",
			"BastionMod\BastionCrafting_Data\toolsbench\data\toolsbench_wood_co.paa"
		};
	};
	class BRP_Toolsbench_Red: BRP_Toolsbench_Base
	{
		scope = 1;
		hiddenSelectionsTextures[]=
		{
			"",
			"BastionMod\BastionCrafting_Data\toolsbench\data\toolsbench_red_co.paa",
			"BastionMod\BastionCrafting_Data\toolsbench\data\toolsbench_wood_co.paa"
		};
	};
	class BRP_Toolsbench_Grey: BRP_Toolsbench_Base
	{
		scope = 1;
		hiddenSelectionsTextures[]=
		{
			"",
			"BastionMod\BastionCrafting_Data\toolsbench\data\toolsbench_grey_co.paa",
			"BastionMod\BastionCrafting_Data\toolsbench\data\toolsbench_wood_co.paa"
		};
	};
	class BRP_BarrelChair_Avgas: Container_Base
	{
		scope = 2;
		color = "Avgas";
		displayName = "Barrel Chair";
		descriptionShort = "A comfy seat crafted from an oil barrel.";
		model = "BastionMod\BastionCrafting_Data\barrelfurniture\BRP_BarrelChair.p3d";
		heavyItem = 1;
		weight = 10000;
		itemSize[] = {10,15};
		itemsCargoSize[] = {10,8};
		physLayer = "item_large";
		reversed = 2;
		itemBehaviour = 2;
		hiddenSelections[] = {"OilDrumSeat"};
		hiddenSelectionsTextures[] = {"BastionMod\BastionCrafting_Data\barrelfurniture\data\BRP_BarrelChair_Avgas_co.paa"};
	};
	class BRP_BarrelChair_Green: BRP_BarrelChair_Avgas
	{
		scope = 2;
		color = "Green";
		hiddenSelectionsTextures[] = {"BastionMod\BastionCrafting_Data\barrelfurniture\data\BRP_BarrelChair_Green_co.paa"};
	};
	class BRP_BarrelChair_Blue: BRP_BarrelChair_Avgas
	{
		scope = 2;
		color = "Blue";
		hiddenSelectionsTextures[] = {"BastionMod\BastionCrafting_Data\barrelfurniture\data\BRP_BarrelChair_Blue_co.paa"};
	};
	class BRP_BarrelChair_Red: BRP_BarrelChair_Avgas
	{
		scope = 2;
		color = "Red";
		hiddenSelectionsTextures[] = {"BastionMod\BastionCrafting_Data\barrelfurniture\data\BRP_BarrelChair_Red_co.paa"};
	};
	class BRP_BarrelChair_Yellow: BRP_BarrelChair_Avgas
	{
		scope = 2;
		color = "Yellow";
		hiddenSelectionsTextures[] = {"BastionMod\BastionCrafting_Data\barrelfurniture\data\BRP_BarrelChair_Yellow_co.paa"};
	};
	class BRP_BarrelChair_Danmak: BRP_BarrelChair_Avgas
	{
		scope = 2;
		color = "Danmak";
		hiddenSelectionsTextures[] = {"BastionMod\BastionCrafting_Data\barrelfurniture\data\BRP_BarrelChair_Danmak_co.paa"};
	};
	class BRP_BarrelTable_Danmak: Container_Base
	{
		scope = 2;
		color = "Danmak";
		displayName = "Barrel Table";
		descriptionShort = "A table crafted from an oil barrel.";
		model = "BastionMod\BastionCrafting_Data\barrelfurniture\BRP_BarrelTable.p3d";
		heavyItem = 1;
		weight = 10000;
		itemSize[] = {10,15};
		itemsCargoSize[] = {10,8};
		physLayer = "item_large";
		itemBehaviour = 2;
		hiddenSelections[] = {"OilDrumTable"};
		hiddenSelectionsTextures[] = {"BastionMod\BastionCrafting_Data\barrelfurniture\data\BRP_BarrelTable_Danmak_ca.paa"};
	};
	class BRP_BarrelTable_Green: BRP_BarrelTable_Danmak
	{
		scope = 2;
		color = "Green";
		hiddenSelectionsTextures[] = {"BastionMod\BastionCrafting_Data\barrelfurniture\data\BRP_BarrelTable_Green_ca.paa"};
	};
	class BRP_BarrelTable_Blue: BRP_BarrelTable_Danmak
	{
		scope = 2;
		color = "Blue";
		hiddenSelectionsTextures[] = {"BastionMod\BastionCrafting_Data\barrelfurniture\data\BRP_BarrelTable_Blue_ca.paa"};
	};
	class BRP_BarrelTable_Red: BRP_BarrelTable_Danmak
	{
		scope = 2;
		color = "Red";
		hiddenSelectionsTextures[] = {"BastionMod\BastionCrafting_Data\barrelfurniture\data\BRP_BarrelTable_Red_ca.paa"};
	};
	class BRP_BarrelTable_Yellow: BRP_BarrelTable_Danmak
	{
		scope = 2;
		color = "Yellow";
		hiddenSelectionsTextures[] = {"BastionMod\BastionCrafting_Data\barrelfurniture\data\BRP_BarrelTable_Yellow_ca.paa"};
	};
	class BRP_BarrelTable_Avgas: BRP_BarrelTable_Danmak
	{
		scope = 2;
		color = "Avgas";
		hiddenSelectionsTextures[] = {"BastionMod\BastionCrafting_Data\barrelfurniture\data\BRP_BarrelTable_Avgas_ca.paa"};
	};
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
};