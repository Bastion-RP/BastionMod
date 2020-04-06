class CfgPatches
{
	class BastionBodyBag
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {};
	};
};
class CfgMods
{
	class BastionBodyBag
	{
		dir = "BastionBodyBag";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "BastionBodyBag";
		credits = "Kerkkoh";
		author = "Kerkkoh";
		authorID = "0";
		version = "1.0";
		extra = 0;
		type = "mod";
		dependencies[] = {"Game", "World", "Mission"};
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {"BastionBodyBag/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"BastionBodyBag/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"BastionBodyBag/scripts/5_Mission"};
			};
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class DryBag_Black;
	// DryBag_Black is placeholder
	class BST_BodyBag: DryBag_Black
	{
		scope = 2;
		displayName = "Body bag";
		descriptionShort = "Bag used to store and transport human corpses. Filled with a corpse from the looks of it.";
		weight = 70000;
	};
	// WaterproofBag is placeholder
	class BST_BodyBagKit: Inventory_Base
	{
		scope = 2;
		displayName = "Body bag kit";
		descriptionShort = "Bag used to store and transport human corpses";
		model = "\dz\gear\containers\WaterproofBag.p3d";
		weight = 500;
		itemSize[] = {1,2};
		rotationFlags = 2;
		hiddenSelections[] = {"camoGround"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 300;
					healthLevels[] = {{1.0,{"DZ\gear\containers\data\WaterproofBag.rvmat"}},{0.7,{"DZ\gear\containers\data\WaterproofBag.rvmat"}},{0.5,{"DZ\gear\containers\data\WaterproofBag_damage.rvmat"}},{0.3,{"DZ\gear\containers\data\WaterproofBag_damage.rvmat"}},{0.0,{"DZ\gear\containers\data\WaterproofBag_destruct.rvmat"}}};
				};
			};
		};
		hiddenSelectionsTextures[] = {"\dz\gear\containers\Data\WaterproofBag_yellow_co.paa"};
	};
};