class CfgPatches
{
	class BastionBodyBag_Data
	{
		units[] = {"BRP_BodyBag","BRP_BodyBag_Blood","BST_WrappedBody","BRP_BodyBagKit"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class HouseNoDestruct;
	class BRP_Compactor: Inventory_Base
	{
		scope = 2;
		displayName = "Compactor";
		model = "\BastionMod\BastionBodyBag_Data\biocompactor\biocompactor.p3d";
		physLayer = "item_large";
		class Cargo
		{
			itemsCargoSize[] = {9,1};
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};

	class BRP_BodyBag_Base: Inventory_Base
	{
		scope = 0;
		destroyOnEmpty = 0;
		varQuantityDestroyOnMin = 0;
		descriptionShort = "Bag used to store and transport human corpses. Filled with a corpse from the looks of it.";
		quantityBar = 1;
		carveNavmesh = 1;
		bounding = "BSphere";
		overrideDrawArea = "3.0";
		visibilityModifier = 0.95;
		canBeDigged = 0;
		alignHologramToTerain = 1;
		heavyItem = 1;
		itemSize[] = {3,7};
		weight = 70000;
		itemBehaviour = 0;
		physLayer = "item_large";
		simulation = "inventoryItem";
		class AnimationSources
		{
			class Flat
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class Curled
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
		};
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
	};
	class BRP_BodyBag: BRP_BodyBag_Base
	{
		scope = 2;
		displayName = "Body bag";
		model = "\BastionMod\BastionBodyBag_Data\bodybag\bodybag.p3d";
		hiddenSelections[] = {"all"};
		hiddenSelectionsTextures[] = {"BastionMod\BastionBodyBag_Data\bodybag\data\bodybag_co.paa"};
	};
	class BRP_BodyBag_Blood: BRP_BodyBag
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"BastionMod\BastionBodyBag_Data\bodybag\data\bodybag_blood_co.paa"};
	};
	class BRP_WrappedBody: BRP_BodyBag_Base
	{
		scope = 2;
		displayName = "Wrapped body";
		model = "\BastionMod\BastionBodyBag_Data\bodybag\wrappedbody.p3d";
		hiddenSelections[] = {"all"};
		hiddenSelectionsTextures[] = {"BastionMod\BastionBodyBag_Data\bodybag\data\wrappedbody_co.paa"};
	};
	class BRP_BodyBagKit: Inventory_Base
	{
		scope = 2;
		displayName = "Body bag kit";
		descriptionShort = "Used to store and transport human corpses.";
		model = "\BastionMod\BastionBodyBag_Data\bodybag\tarp.p3d";
		itemSize[] = {3,2};
		weight = 300;
		itemBehaviour = 1;
		rotationFlags = 17;
		canBeDigged = 0;
		hiddenSelections[] = {"all"};
		hiddenSelectionsTextures[] = {"BastionMod\BastionBodyBag_Data\bodybag\data\bodybag_co.paa"};
		hiddenSelectionsMaterials[] = {"BastionMod\BastionBodyBag_Data\bodybag\data\bodybag.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 300;
					healthLevels[] = {{1.0,{"BastionMod\BastionBodyBag_Data\bodybag\data\bodybag.rvmat"}},{0.7,{"BastionMod\BastionBodyBag_Data\bodybag\data\bodybag.rvmat"}},{0.5,{"BastionMod\BastionBodyBag_Data\bodybag\data\bodybag_damage.rvmat"}},{0.3,{"BastionMod\BastionBodyBag_Data\bodybag\data\bodybag_damage.rvmat"}},{0.0,{"BastionMod\BastionBodyBag_Data\bodybag\data\bodybag_destruct.rvmat"}}};
				};
			};
		};
	};
	class BRP_CartonBox_BodyBagKits: HouseNoDestruct
	{
		scope = 1;
		model = "\BastionMod\BastionBodyBag_Data\cartonbox\cartonbox.p3d";
	};
};
