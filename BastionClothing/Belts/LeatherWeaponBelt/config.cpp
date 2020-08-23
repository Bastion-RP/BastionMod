class CfgPatches
{
	class BRP_LeatherWeaponBelt
	{
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Characters"};
		units[] = {};
	};
};
class CfgVehicles
{
	class Clothing_Base;
	class Clothing: Clothing_Base{};
	class BRP_LeatherWeaponBelt_ColorBase: Clothing
	{
		scope = 0;
		displayName = "Move along";
		descriptionShort = "Nothing to see here";
		model = "BastionMod\BastionClothing\Belts\LeatherWeaponBelt\leatherbelt_g.p3d";
		inventorySlot[] = {"Shoulder"};
		attachments[] = {"Shoulder"};
		weight = 300;
		itemSize[] = {1,4};
		absorbency = 0.1;	
		heatIsolation = 0.02;
		repairableWithKits[] = {5,3};
		repairCosts[] = {30.0,25.0};
		rotationFlags = 12;		
		hiddenSelections[] = {"all"};	
		class ClothingTypes
		{
			male = "BastionMod\BastionClothing\Belts\LeatherWeaponBelt\leatherbelt.p3d";
			female = "BastionMod\BastionClothing\Belts\LeatherWeaponBelt\leatherbelt.p3d";
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
						{1.0,{"BastionMod\BastionClothing\Belts\LeatherWeaponBelt\data\leatherbelt.rvmat"}},
						{0.7,{"BastionMod\BastionClothing\Belts\LeatherWeaponBelt\data\leatherbelt.rvmat"}},
						{0.5,{"BastionMod\BastionClothing\Belts\LeatherWeaponBelt\data\leatherbelt_damage.rvmat"}},
						{0.3,{"BastionMod\BastionClothing\Belts\LeatherWeaponBelt\data\leatherbelt_damage.rvmat"}},
						{0.0,{"BastionMod\BastionClothing\Belts\LeatherWeaponBelt\data\leatherbelt_destruct.rvmat"}}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "SmershVest_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "SmershVest_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class BRP_LeatherWeaponBelt_Brown: BRP_LeatherWeaponBelt_ColorBase
	{	
		scope = 2;
		displayName = "Leather Gun Belt";
		descriptionShort = "Gun belt. Has a universal mount that fits most types of weapons.";			
		hiddenSelectionsTextures[] = {"BastionMod\BastionClothing\Belts\LeatherWeaponBelt\data\leatherbelt_brown_co.paa"};		
	};	
	class BRP_LeatherWeaponBelt_Black: BRP_LeatherWeaponBelt_ColorBase
	{
		scope = 2;
		displayName = "Leather Gun Belt";
		descriptionShort = "Gun belt. Has a universal mount that fits most types of weapons.";			
		hiddenSelectionsTextures[] = {"BastionMod\BastionClothing\Belts\LeatherWeaponBelt\data\leatherbelt_black_co.paa"};		
	};		
};