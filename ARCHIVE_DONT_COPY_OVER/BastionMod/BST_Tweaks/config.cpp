class CfgPatches
{
	class BST_Tweaks
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data", "DZ_Weapons_Melee"};
	};
};

class CfgMods
{
	class BST_Tweaks
	{
		dir = "BST_Tweaks";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "BST_Tweaks";
		credits = "Helkhiana";
		author = "Helkhiana";
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
				files[] = {"BST_Tweaks/scripts/4_World"};
			};
		};
	};
};

class CfgVehicles
{
	class StunBaton;
	class BST_StunBaton: StunBaton
	{
		scope=2;
		inventorySlot[] = {"Baton"};
		class EnergyManager
		{
			hasIcon=1;
			plugType=1;
			energyUsagePerSecond=0.003;
			attachmentAction=1;
			wetnessExposure=0.1;
		};	
		class MeleeModes
		{
			class Default
			{
				ammo="MeleeBSTBaton";
				range=1.5;
			};
			class Heavy
			{
				ammo="MeleeBSTBaton_Heavy";
				range=1.5;
			};
			class Sprint
			{
				ammo="MeleeBSTBaton_Heavy";
				range=2;
			};
			class Default_SwitchedOn
			{
				ammo="MeleeBSTBatonShock";
				range=1.5;
			};
			class Heavy_SwitchedOn
			{
				ammo="MeleeBSTBatonShock_Heavy";
				range=1.5;
			};
			class Sprint_SwitchedOn
			{
				ammo="MeleeBSTBatonShock_Heavy";
				range=2;
			};
		};
	};
};

class CfgAmmo
{
	class MeleeLightBlunt;
	class MeleeLightBlunt_Heavy;
	class MeleeBSTBaton: MeleeLightBlunt
	{
		class DamageApplied
		{
			type="Melee";
			class Health
			{
				damage=5;
			};
			class Blood
			{
				damage=0;
			};
			class Shock
			{
				damage=10;
			};
			additionAnimalMeleeMultiplier=1;
		};
	};
	class MeleeBSTBaton_Heavy: MeleeLightBlunt_Heavy
	{
		class DamageApplied
		{
			type="Melee";
			class Health
			{
				damage=10;
			};
			class Blood
			{
				damage=0;
			};
			class Shock
			{
				damage=15;
			};
			additionAnimalMeleeMultiplier=1;
		};
	};

	class MeleeLightBluntShock;
	class MeleeLightBluntShock_Heavy;
	class MeleeBSTBatonShock: MeleeLightBluntShock
	{
		class DamageApplied
		{
			type="Melee";
			class Health
			{
				damage=5;
			};
			class Blood
			{
				damage=0;
			};
			class Shock
			{
				damage=35;
			};
			additionAnimalMeleeMultiplier=1.2;
		};
	};
	class MeleeBSTBatonShock_Heavy: MeleeLightBluntShock_Heavy
	{
		hitAnimation=1;
		class DamageApplied
		{
			type="Melee";
			class Health
			{
				damage=10;
			};
			class Blood
			{
				damage=0;
			};
			class Shock
			{
				damage=75;
			};
			additionAnimalMeleeMultiplier=1.2;
		};
	};
};