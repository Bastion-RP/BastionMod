class CfgPatches
{
	class OakleyTacGlasses_Base
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Characters","DZ_Gear_Optics"};
	};
};
class CfgVehicles
{
	class AviatorGlasses;
	class BRP_OakleyTacGlasses_Base: AviatorGlasses
	{
		scope = 0;
		displayName = "Oakley Tactical Goggles";
		descriptionShort = "Oakley Tactical Goggles.";
		model = "BastionMod\BastionClothing\Glasses\Oakley\Oakley_G.p3d";
		vehicleClass = "Clothing";
		simulation = "clothing";
		inventorySlot[] = {"Eyewear"};
		itemInfo[] = {"Clothing","Eyewear"};
		rotationFlags = 17;
		weight = 36;
		itemSize[] = {2,1};
		class ClothingTypes
		{
			male = "BastionMod\BastionClothing\Glasses\Oakley\Oakley_M.p3d";
			female = "BastionMod\BastionClothing\Glasses\Oakley\Oakley_M.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "SportGlasses_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "SportGlasses_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class BRP_ISF_DTAC_Glasses: BRP_OakleyTacGlasses_Base
	{
		scope = 2;
		displayName = "Oakley Tactical Glasses";
		descriptionShort = "Oakley Tactical Goggles with a black trim and clear lenses.";
		visibilityModifier = 0.9;
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"BastionMod\BastionClothing\Glasses\Oakley\Data\Oakley_Black.paa"};
	};
};