class CfgPatches
{
	class BRP_Gasmask
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Characters"};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class Clothing_Base;
	class Clothing: Clothing_Base{};
	class BRP_Gasmask: Clothing
	{
		scope = 2;
		displayName = "Civilian Gas Mask";
		descriptionShort = "A full face gas mask, filter is required for protection. Used to protect from airborne pollutants and toxic gases.";
		model = "BastionMod\BastionClothing\GasMask\gasmask_g.p3d";
		inventorySlot[] = {"Mask"};
		itemInfo[] = {"Clothing","Mask"};
		attachments[] = {"GasMaskFilter"};
		rotationFlags = 2;
		weight = 730;
		itemSize[] = {3,3};
		absorbency = 0;
		heatIsolation = 0.5;
		visibilityModifier = 0.9;
		noHelmet = 0;
		headSelectionsToHide[] = {"Clipping_Gasmask"};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		hiddenSelectionsTextures[] = {"BastionMod\BastionClothing\GasMask\data\gasmask_co.paa","BastionMod\BastionClothing\GasMask\data\gasmask_co.paa","BastionMod\BastionClothing\GasMask\data\gasmask_co.paa"};
		class EnergyManager
		{
			autoSwitchOff=0;
			energyAtSpawn=15;
			energyStorageMax=100;
			energyUsagePerSecond=1;
			updateInterval=59;
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] =
					{
						{1.0,{"BastionMod\BastionClothing\GasMask\data\gasmask.rvmat","BastionMod\BastionClothing\GasMask\data\glass.rvmat"}},
						{0.7,{"BastionMod\BastionClothing\GasMask\data\gasmask.rvmat","BastionMod\BastionClothing\GasMask\data\glass.rvmat"}},
						{0.5,{"BastionMod\BastionClothing\GasMask\data\gasmask_damage.rvmat","BastionMod\BastionClothing\GasMask\data\glass_damage.rvmat"}},
						{0.3,{"BastionMod\BastionClothing\GasMask\data\gasmask_damage.rvmat","BastionMod\BastionClothing\GasMask\data\glass_damage.rvmat"}},
						{0.0,{"BastionMod\BastionClothing\GasMask\data\gasmask_destruct.rvmat","BastionMod\BastionClothing\GasMask\data\glass_destruct.rvmat"}}
					};
				};
			};
		};
		class ClothingTypes
		{
			male = "BastionMod\BastionClothing\GasMask\gasmask_m.p3d";
			female = "BastionMod\BastionClothing\GasMask\gasmask_f.p3d";
		};
		class Protection
		{
			biological = 1;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "DarkMotoHelmet_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "DarkMotoHelmet_drop_SoundSet";
					id = 898;
				};
			};
		};
		soundVoiceType = "gasmask";
		soundVoicePriority = 5;
	};
	class BRP_Gasmask_Filter: Inventory_Base
	{
		scope = 2;
		displayName = "Gas Mask Filter";
		descriptionShort = "Filter for various Gas Masks. Don't forget to change, it's not eternal.";
		model = "BastionMod\BastionClothing\GasMask\gasmask_filter.p3d";
		inventorySlot[] = {"GasMaskFilter"};
		rotationFlags = 2;
		weight = 150;
		itemSize[] = {2,2};
		absorbency = 0;
		heatIsolation = 0.6;
		quantityBar=1;
		varQuantityInit=2700;
		varQuantityMin=0;
		varQuantityMax=2700;
		visibilityModifier = 0.95;
		hiddenSelections[] = {"camoGround"};
		hiddenSelectionsTextures[] = {"BastionMod\BastionClothing\GasMask\data\gasmask_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] =
					{
						{1.0,{"BastionMod\BastionClothing\GasMask\data\gasmask.rvmat"}},
						{0.7,{"BastionMod\BastionClothing\GasMask\data\gasmask.rvmat"}},
						{0.5,{"BastionMod\BastionClothing\GasMask\data\gasmask_damage.rvmat"}},
						{0.3,{"BastionMod\BastionClothing\GasMask\data\gasmask_damage.rvmat"}},
						{0.0,{"BastionMod\BastionClothing\GasMask\data\gasmask_destruct.rvmat"}}
					};
				};
			};
		};
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxyGP5GasMask_filter: ProxyAttachment
	{
		scope = 2;
		inventorySlot[] = {"GasMaskFilter"};
		model = "\DZ\characters\masks\GP5GasMask_filter.p3d";
	};
};
