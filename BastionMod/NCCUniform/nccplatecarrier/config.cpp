////////////////////////////////////////////////////////////////////
//DeRap: P:\BastionMod\NCCUniform\nccplatecarrier\config.bin
//Produced from mikero's Dos Tools Dll version 7.60
//https://mikero.bytex.digital/Downloads
//'now' is Thu Mar 26 20:47:00 2020 : 'file' last modified on Thu Mar 26 20:47:00 2020
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class NCC_Clothing
	{
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Characters","DZ_Characters_Vests","DZ_Characters_Pants","DZ_Characters_Tops","DZ_Characters_Shoes","DZ_Characters_Headgear","DZ_Data","DZ_Weapons_Optics","DZ_Weapons_Melee"};
		units[] = {"BastionRP_ISF_CarrierRig"};
	};
};
class CfgVehicles
{
	class Clothing;
	class PlateCarrierVest;
	class BastionRP_ISF_CarrierRig: PlateCarrierVest
	{
		scope = 2;
		displayName = "Rhino II Plate Carrier 'Big Rig'";
		descriptionShort = "A carrier rig specifically made to hold extra pouches for increased capacity out in the field without compromising protection";
		model = "BastionMod\NCCUniform\nccplatecarrier\carrierrig_g.p3d";
		inventorySlot = "Vest";
		itemsCargoSize[] = {8,4};
		itemInfo[] = {"Clothing","Vest"};
		attachments[] = {"walkietalkie","grenade1","grenade2","largepouch1","largepouch2","smallpouch1","smallpouch2","VestHolster"};
		weight = 12000;
		itemSize[] = {4,4};
		absorbency = 0.1;
		heatIsolation = 0.1;
		repairableWithKits[] = {5,3};
		repairCosts[] = {30,25};
		class ClothingTypes
		{
			male = "BastionMod\NCCUniform\nccplatecarrier\carrierrig_m.p3d";
			female = "BastionMod\NCCUniform\nccplatecarrier\carrierrig_m.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1,{"DZ\characters\vests\Data\BallisticVest.rvmat"}},{0.7,{"DZ\characters\vests\Data\BallisticVest.rvmat"}},{0.5,{"DZ\characters\vests\Data\BallisticVest_damage.rvmat"}},{0.3,{"DZ\characters\vests\Data\BallisticVest_damage.rvmat"}},{0,{"DZ\characters\vests\Data\BallisticVest_destruct.rvmat"}}};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0.4;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0.26;
					};
				};
				class Melee
				{
					class Health
					{
						damage = 0.25;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0.25;
					};
				};
				class Infected
				{
					class Health
					{
						damage = 0.25;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0.25;
					};
				};
			};
		};
	};
	class Transmitter_Base;
	class PersonalRadio: Transmitter_Base
	{
		inventorySlot[] = {"walkietalkie"};
	};
	class Grenade_Base;
	class M18SmokeGrenade_ColorBase: Grenade_Base
	{
		inventorySlot[] = {"grenade1"};
	};
	class M67Grenade: Grenade_Base
	{
		inventorySlot[] = {"grenade2"};
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class Proxysmokegrenade: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "grenade1";
		model = "\DZ\weapons\explosives\smokegrenade.p3d";
	};
	class Proxygrenade: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "grenade2";
		model = "\DZ\weapons\explosives\grenade.p3d";
	};
	class ProxyWalkieTalkie: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "walkietalkie";
		model = "\DZ\gear\radio\WalkieTalkie.p3d";
	};
	class Proxyplate_carrier_holster_g: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "VestHolster";
		model = "DZ\characters\vests\plate_carrier_holster_g.p3d";
	};
};
class CfgSlots
{
	class Slot_walkietalkie
	{
		name = "walkietalkie";
		displayName = "walkietalkie";
		ghostIcon = "vest";
	};
	class Slot_grenade1
	{
		name = "grenade1";
		displayName = "grenade1";
		ghostIcon = "grenade";
	};
	class Slot_grenade2
	{
		name = "grenade2";
		displayName = "grenade2";
		ghostIcon = "grenade";
	};
	class Slot_smallpouch1
	{
		name = "smallpouch1";
		displayName = "smallpouch1";
		ghostIcon = "vest";
	};
	class Slot_smallpouch2
	{
		name = "smallpouch2";
		displayName = "smallpouch2";
		ghostIcon = "vest";
	};
	class Slot_largepouch1
	{
		name = "largepouch1";
		displayName = "largepouch1";
		ghostIcon = "vest";
	};
	class Slot_largepouch2
	{
		name = "largepouch2";
		displayName = "largepouch2";
		ghostIcon = "vest";
	};
};
