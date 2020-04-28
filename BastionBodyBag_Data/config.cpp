////////////////////////////////////////////////////////////////////
//DeRap: P:\BastionMod\BastionBodyBag_Data\config.bin
//Produced from mikero's Dos Tools Dll version 7.60
//https://mikero.bytex.digital/Downloads
//'now' is Tue Apr 28 21:21:50 2020 : 'file' last modified on Tue Apr 28 21:21:50 2020
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class BastionBodyBag_Data
	{
		units[] = {"BST_BodyBag","BST_BodyBag_Blood","BST_WrappedBody","BST_BodyBagKit"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class HouseNoDestruct;
	class BST_Compactor: HouseNoDestruct
	{
		scope = 1;
		displayName = "Compactor";
		model = "\BastionMod\BastionBodyBag_Data\biocompactor.p3d";
	};
	class BST_BodyBag_Base: Inventory_Base
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
	class BST_BodyBag: BST_BodyBag_Base
	{
		scope = 2;
		displayName = "Body bag";
		model = "\BastionMod\BastionBodyBag_Data\bodybag.p3d";
		hiddenSelections[] = {"all"};
		hiddenSelectionsTextures[] = {"BastionMod\BastionBodyBag_Data\data\bodybag_co.paa"};
	};
	class BST_BodyBag_Blood: BST_BodyBag
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"BastionMod\BastionBodyBag_Data\data\bodybag_blood_co.paa"};
	};
	class BST_WrappedBody: BST_BodyBag_Base
	{
		scope = 2;
		displayName = "Wrapped body";
		model = "\BastionMod\BastionBodyBag_Data\wrappedbody.p3d";
		hiddenSelections[] = {"all"};
		hiddenSelectionsTextures[] = {"BastionMod\BastionBodyBag_Data\data\wrappedbody_co.paa"};
	};
	class BST_BodyBagKit: Inventory_Base
	{
		scope = 2;
		displayName = "Body bag kit";
		descriptionShort = "Used to store and transport human corpses.";
		model = "\BastionMod\BastionBodyBag_Data\tarp.p3d";
		itemSize[] = {3,2};
		weight = 300;
		itemBehaviour = 1;
		rotationFlags = 17;
		canBeDigged = 0;
		hiddenSelections[] = {"all"};
		hiddenSelectionsTextures[] = {"BastionMod\BastionBodyBag_Data\data\bodybag_co.paa"};
		hiddenSelectionsMaterials[] = {"BastionMod\BastionBodyBag_Data\data\bodybag.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 300;
					healthLevels[] = {{1.0,{"BastionMod\BastionBodyBag_Data\data\bodybag.rvmat"}},{0.7,{"BastionMod\BastionBodyBag_Data\data\bodybag.rvmat"}},{0.5,{"BastionMod\BastionBodyBag_Data\data\bodybag_damage.rvmat"}},{0.3,{"BastionMod\BastionBodyBag_Data\data\bodybag_damage.rvmat"}},{0.0,{"BastionMod\BastionBodyBag_Data\data\bodybag_destruct.rvmat"}}};
				};
			};
		};
	};
};
