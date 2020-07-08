class CfgPatches
{
	class BastionCrafting_Shif
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Weapons_Melee"};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class BRP_Shiv: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_SteakKnife0"; //replace me
		descriptionShort = "$STR_CfgVehicles_SteakKnife1"; //replace me
		model = "BastionMod\BastionCrafting_Data\shiv\shiv.p3d";
		animClass = "Knife";
		repairableWithKits[] = {5,4};
		repairCosts[] = {30.0,25.0};
		itemInfo[] = {"Knife"};
		RestrainUnlockType = 1;
		rotationFlags = 17;
		inventorySlot[] = {"Knife"};
		isMeleeWeapon = 1;
		suicideAnim = "onehanded";
		canSkinBodies = 1;
		weight = 90;
		itemSize[] = {1,2};
		openItemSpillRange[] = {10,20};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = 
					{
						{1.0,{"BastionMod\BastionCrafting_Data\shiv\data\shiv.rvmat"}},
						{0.7,{"BastionMod\BastionCrafting_Data\shiv\data\shiv.rvmat"}},
						{0.5,{"BastionMod\BastionCrafting_Data\shiv\data\shiv_damage.rvmat"}},
						{0.3,{"BastionMod\BastionCrafting_Data\shiv\data\shiv_damage.rvmat"}},
						{0.0,{"BastionMod\BastionCrafting_Data\shiv\data\shiv_destruct.rvmat"}}
					};
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeKnife";
				range = 1.1;
			};
			class Heavy
			{
				ammo = "MeleeKnife_Heavy";
				range = 1.1;
			};
			class Sprint
			{
				ammo = "MeleeKnife_Heavy";
				range = 3.3;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class ChoppingTree
				{
					soundSet = "ChoppingTree_SoundSet";
					id = 415;
				};
				class animalSkinning_in
				{
					soundSet = "animalSkinning_in_SoundSet";
					id = 516;
				};
				class animalSkinning
				{
					soundSet = "animalSkinning_SoundSet";
					id = 517;
				};
				class animalSkinning_out
				{
					soundSet = "animalSkinning_out_SoundSet";
					id = 518;
				};
			};
		};
	};
};
