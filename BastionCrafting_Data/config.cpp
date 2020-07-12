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
	
	//==============================================Barrel Furniture================================================>	
	
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
	
	//==============================================Furnace================================================>	
	
	class BRP_FurnaceKit: Inventory_Base
	{
		scope = 2;
		displayName = "Furnace Kit";
		descriptionShort = "A hand made furnace kit. Place to begin construction.";
		model = "\DZ\gear\camping\wooden_case.p3d";
		rotationFlags = 0;
		isMeleeWeapon = 0;
		weight = 300;
		absorbency = 0;
		itemSize[] = {4,2};
		lootCategory = "Materials";
		reversed = 0;
		itemBehaviour = 2;
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
	class BRP_Furnace: Inventory_Base
	{
		scope = 2;
		displayName = "Furnace";
		descriptionShort = "A hand made furnace.";
		model = "\BastionMod\BastionCrafting_Data\furnace\BRP_Furnace.p3d";
		overrideDrawArea = "8.0";
		forceFarBubble = "true";
		lootCategory = "Crafted";
		carveNavmesh = 1;
		weight = 60000;
		itemSize[] = {10,15};
		physLayer = "item_large";
		createProxyPhysicsOnInit = "false";
		createdProxiesOnInit[] = {"Deployed"};
		rotationFlags = 2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
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
				class FragGrenade
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
		attachments[] = {"Material_Nails","Material_MetalSheets"};
		class GUIInventoryAttachmentsProps
		{
			class Materials
			{
				name = "Materials";
				description = "";
				attachmentSlots[] = {"Material_Nails","Material_MetalSheets"};
				icon = "cat_bb_material";
				selection = "furnace_construction";
			};
		};
		class AnimationSources
		{
			class AnimSourceShown
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class AnimSourceHidden
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class AnimRotate
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class Material_Nails: AnimSourceHidden{};
			class Material_MetalSheets: AnimSourceHidden{};
			class Deployed: AnimSourceHidden{};
			class Furnace_Base: AnimSourceHidden{};
			class Furnace_Body: AnimSourceHidden{};
			class Dummy_Gate: AnimSourceHidden{};
			class Dummy_Rotate: AnimRotate{};
		};
		class Construction
		{
			class furnace_construction
			{
				class furnace_base
				{
					name = "Furnace Base";
					is_base = 1;
					id = 1;
					required_parts[] = {};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 20;
						};
						class Material2
						{
							type = "MetalPlate";
							slot_name = "Material_MetalSheets";
							quantity = 5;
						};
					};
				};
				class furnace_body
				{
					name = "Furnace Body";
					id = 2;
					required_parts[] = {"furnace_base"};
					conflicted_parts[] = {"furnace_base"};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 20;
						};
						class Material2
						{
							type = "MetalPlate";
							slot_name = "Material_MetalSheets";
							quantity = 5;
						};
					};
				};
				class dummy_gate
				{
					name = "Dummy Gate";
					is_gate = 1;
					id = 3;
					required_parts[] = {"furnace_body"};
					conflicted_parts[] = {"furnace_base"};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 20;
						};
						class Material2
						{
							type = "MetalPlate";
							slot_name = "Material_MetalSheets";
							quantity = 20;
						};
					};
				};
			};
		};
	};
	class BRP_FurnaceFireplace: FireplaceBase
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
		hiddenSelections[] = {"ashes","camoGround","inventory"};
		hiddenSelectionsTextures[] = {"\dz\gear\cooking\data\stoneground_co.paa","\BastionMod\BastionCrafting_Data\furnace\data\BRP_Furnace_Co.paa","\BastionMod\BastionCrafting_Data\furnace\data\BRP_Furnace_Co.paa"};
		hiddenSelectionsMaterials[] = {"\dz\gear\cooking\data\stonegroundnoemit.rvmat","\dz\gear\cooking\data\fireplacekit.rvmat"};
		hologramMaterial = "Barrel";
		hologramMaterialPath = "";
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
		weight = 300;
		absorbency = 0;
		itemSize[] = {3,3};
		itemBehaviour = 1;
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
		weight = 300;
		absorbency = 0;
		itemSize[] = {2,3};
		itemBehaviour = 1;
	};
	class BRP_Woodscrap2: Inventory_Base
	{
		scope = 2;
		displayName = "Wood Scrap";
		descriptionShort = "Pieces of wooden scrap. Useful for crafting.";
		model = "BastionMod\BastionCrafting_Data\woodscrap\woodscrap2.p3d";
		isMeleeWeapon = 0;
		rotationFlags=16;
		weight = 300;
		absorbency = 0;
		itemSize[] = {2,3};
		itemBehaviour = 1;
	};
	class BRP_PlasticScrap: Inventory_Base
	{
		scope = 2;
		displayName = "Plastic Scrap";
		descriptionShort = "Pieces of melted plastic. Useful for crafting";
		model = "BastionMod\BastionCrafting_Data\plasticpieces\plastic.p3d";
		isMeleeWeapon = 0;
		rotationFlags=16;
		weight = 350;
		absorbency = 0;
		itemSize[] = {2,2};
		itemBehaviour = 1;
	};
};