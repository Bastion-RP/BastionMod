class CfgPatches
{
	class BRP_Tactical_Jacket_Assets
	{
		units[] = {"BRP_Tactical_Jacket_Base","BRP_Tactical_Jacket_Tan","BRP_Tactical_Jacket_Black","BRP_Tactical_Jacket_Woodland_Camo","BRP_Tactical_Jacket_Urban_Camo","BRP_Tactical_Jacket_DarkGrey_Camo","BRP_Tactical_Jacket_Arctic_Camo"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgVehicles
{
	class Clothing_Base;
	class Clothing: Clothing_Base{};
	class BRP_Tactical_Jacket_Base: Clothing
	{
		scope = 0;
		displayName = "Military Fleece";
		descriptionShort = "";
		model = "\BastionMod\Clothing\Tactical_Jacket\tactical_jacket_g.p3d";
		inventorySlot = "Body";
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Body"};
		weight = 250;
		itemSize[] = {4,3};
		itemsCargoSize[] = {6,5};
		quickBarBonus = 1;
		absorbency = 0.25;
		heatIsolation = 0.6;
		ragQuantity = 4;
		repairableWithKits[] = {5,2};
		repairCosts[] = {30,25};
		soundAttType = "WoolShirt";
		hiddenSelections[] = {"zbytek"};
		class ClothingTypes
		{
			male = "\BastionMod\Clothing\Tactical_Jacket\tactical_jacket_m.p3d";
			female = "\BastionMod\Clothing\Tactical_Jacket\tactical_jacket_f.p3d";
		};
		hiddenSelectionsTextures[] = {"\BastionMod\Clothing\Tactical_Jacket\data\bastiontacticaljacket_co.paa","\BastionMod\Clothing\Tactical_Jacket\data\bastiontacticaljacket_co.paa","\BastionMod\Clothing\Tactical_Jacket\data\bastiontacticaljacket_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"BastionMod\Clothing\Tactical_Jacket\data\bastiontacticaljacket.rvmat"}},{0.7,{"BastionMod\Clothing\Tactical_Jacket\data\bastiontacticaljacket.rvmat"}},{0.5,{"BastionMod\Clothing\Tactical_Jacket\data\bastiontacticaljacket_damaged.rvmat"}},{0.3,{"BastionMod\Clothing\Tactical_Jacket\data\bastiontacticaljacket_badlydamaged.rvmat"}},{0.0,{"BastionMod\Clothing\Tactical_Jacket\data\bastiontacticaljacket_ruined.rvmat"}}};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					Health = 0.9;
					Blood = 0.9;
					Shock = 0.9;
				};
				class Melee
				{
					Health = 0.9;
					Blood = 0.9;
					Shock = 0.9;
				};
				class Infected
				{
					Health = 0.9;
					Blood = 0.9;
					Shock = 0.9;
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "Shirt_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "Shirt_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class BRP_Tactical_Jacket_Tan: BRP_Tactical_Jacket_Base
	{
		scope = 2;
		hiddenSelections[] = {"zbytek"};
		visibilityModifier = 0.85;
		hiddenSelectionsTextures[] = {"\BastionMod\Clothing\Tactical_Jacket\data\bastiontacticaljacket_tan_co.paa","\BastionMod\Clothing\Tactical_Jacket\data\bastiontacticaljacket_tan_co.paa","\BastionMod\Clothing\Tactical_Jacket\data\bastiontacticaljacket_tan_co.paa"};
	};
	class BRP_Tactical_Jacket_Black: BRP_Tactical_Jacket_Base
	{
		scope = 2;
		hiddenSelections[] = {"zbytek"};
		visibilityModifier = 0.85;
		hiddenSelectionsTextures[] = {"\BastionMod\Clothing\Tactical_Jacket\data\bastiontacticaljacket_black_co.paa","\BastionMod\Clothing\Tactical_Jacket\data\bastiontacticaljacket_black_co.paa","\BastionMod\Clothing\Tactical_Jacket\data\bastiontacticaljacket_black_co.paa"};
	};
	class BRP_Tactical_Jacket_Woodland_Camo: BRP_Tactical_Jacket_Base
	{
		scope = 2;
		hiddenSelections[] = {"zbytek"};
		visibilityModifier = 0.85;
		hiddenSelectionsTextures[] = {"\BastionMod\Clothing\Tactical_Jacket\data\bastiontacticaljacket_woodland_camo_co.paa","\BastionMod\Clothing\Tactical_Jacket\data\bastiontacticaljacket_woodland_camo_co.paa","\BastionMod\Clothing\Tactical_Jacket\data\bastiontacticaljacket_woodland_camo_co.paa"};
	};
	class BRP_Tactical_Jacket_Urban_Camo: BRP_Tactical_Jacket_Base
	{
		scope = 2;
		hiddenSelections[] = {"zbytek"};
		visibilityModifier = 0.85;
		hiddenSelectionsTextures[] = {"\BastionMod\Clothing\Tactical_Jacket\data\bastiontacticaljacket_urban_camo_co.paa","\BastionMod\Clothing\Tactical_Jacket\data\bastiontacticaljacket_urban_camo_co.paa","\BastionMod\Clothing\Tactical_Jacket\data\bastiontacticaljacket_urban_camo_co.paa"};
	};
	class BRP_Tactical_Jacket_DarkGrey_Camo: BRP_Tactical_Jacket_Base
	{
		scope = 2;
		hiddenSelections[] = {"zbytek"};
		visibilityModifier = 0.85;
		hiddenSelectionsTextures[] = {"\BastionMod\Clothing\Tactical_Jacket\data\bastiontacticaljacket_darkgrey_camo_co.paa","\BastionMod\Clothing\Tactical_Jacket\data\bastiontacticaljacket_darkgrey_camo_co.paa","\BastionMod\Clothing\Tactical_Jacket\data\bastiontacticaljacket_darkgrey_camo_co.paa"};
	};
	class BRP_Tactical_Jacket_Arctic_Camo: BRP_Tactical_Jacket_Base
	{
		scope = 2;
		hiddenSelections[] = {"zbytek"};
		visibilityModifier = 0.85;
		hiddenSelectionsTextures[] = {"\BastionMod\Clothing\Tactical_Jacket\data\bastiontacticaljacket_arctic_camo_co.paa","\BastionMod\Clothing\Tactical_Jacket\data\bastiontacticaljacket_arctic_camo_co.paa","\BastionMod\Clothing\Tactical_Jacket\data\bastiontacticaljacket_arctic_camo_co.paa"};
	};
};
