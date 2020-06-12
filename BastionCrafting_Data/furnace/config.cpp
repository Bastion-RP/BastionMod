////////////////////////////////////////////////////////////////////
//DeRap: Z:\BastionMod\BastionCrafting_Data\furnace\config.bin
//Produced from mikero's Dos Tools Dll version 7.69
//https://mikero.bytex.digital/Downloads
//'now' is Fri Jun 12 16:01:18 2020 : 'file' last modified on Fri Jun 12 16:01:18 2020
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgMods
{
	class BastionFurnace_Data
	{
		type = "mod";
		author = "Chopper";
		name = "BastionFurnace_Data";
		dir = "BastionFurnace_Data";
		dependencies[] = {};
	};
};
class CfgPatches
{
	class BastionFurnace_Data
	{
		units[] = {"BRP_FurnaceKit","BRP_Furnace_Hologram","BRP_Furnace","BRP_FurnaceFireplace"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Gear_Containers","DZ_Gear_Crafting","DZ_Data"};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class Container_Base;
	class FireplaceBase;
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
		openable = 0;
		lootCategory = "Crafted";
		itemSize[] = {10,20};
		itemsCargoSize[] = {10,20};
		useEntityHierarchy = "true";
		attachments[] = {"Firewood","WoodenStick","CookingEquipment","Rags","MedicalBandage","Paper","Book","OakBark","BirchBark"};
		class GUIInventoryAttachmentsProps
		{
			class CookingEquipment
			{
				name = "$STR_attachment_CookingEquipment0";
				description = "";
				attachmentSlots[] = {"CookingEquipment"};
				icon = "cat_fp_cooking";
				view_index = 1;
			};
			class Fuel
			{
				name = "$STR_attachment_Fuel0";
				description = "";
				attachmentSlots[] = {"Firewood","WoodenStick"};
				icon = "cat_fp_fuel";
				view_index = 4;
			};
			class Kindling
			{
				name = "$STR_attachment_Kindling0";
				description = "";
				attachmentSlots[] = {"Rags","MedicalBandage","Paper","Book","OakBark","BirchBark"};
				icon = "cat_fp_kindling";
				view_index = 3;
			};
		};
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
};
