////////////////////////////////////////////////////////////////////
//DeRap: P:\BastionMod\BastionClothing\PlateCarrier\config.bin
//Produced from mikero's Dos Tools Dll version 7.60
//https://mikero.bytex.digital/Downloads
//'now' is Tue Apr 28 20:26:44 2020 : 'file' last modified on Tue Apr 28 20:26:44 2020
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class NCC_Clothing
	{
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Characters","DZ_Characters_Vests","DZ_Characters_Pants","DZ_Characters_Tops","DZ_Characters_Shoes","DZ_Characters_Headgear","DZ_Data","DZ_Weapons_Optics","DZ_Weapons_Melee"};
		units[] = {"BRP_ISF_CarrierRig","BRP_ISF_CarrierRigPouches","BRP_ISF_CarrierRigHolster"};
	};
};
class CfgVehicles
{
	class PlateCarrierVest;
	class PlateCarrierPouches;
	class PlateCarrierHolster;
	class BRP_ISF_CarrierRig: PlateCarrierVest
	{
		scope = 2;
		displayName = "Rhino II Plate Carrier 'Big Rig'";
		descriptionShort = "A carrier rig specifically made to hold extra pouches for increased capacity out in the field without compromising protection";
		model = "\BastionMod\BastionClothing\PlateCarrier\isfplatecarrier_g.p3d";
		attachments[] = {"WalkieTalkie","VestGrenadeA","VestGrenadeB","VestPouch","VestHolster"};
		weight = 12000;
		class ClothingTypes
		{
			male = "BastionMod\BastionClothing\PlateCarrier\isfplatecarrier_m.p3d";
			female = "BastionMod\BastionClothing\PlateCarrier\isfplatecarrier_m.p3d";
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
	class BRP_ISF_CarrierRigPouches: PlateCarrierPouches
	{
		scope = 2;
		displayName = "Rhino II Pouches";
		descriptionShort = "$STR_CfgVehicles_CarrierPouches1";
		model = "\BastionMod\BastionClothing\PlateCarrier\isfplatecarrier_pouches.p3d";
		itemsCargoSize[] = {8,4};
	};
	class BRP_ISF_CarrierRigHolster: PlateCarrierHolster
	{
		scope = 2;
		displayName = "Rhino II Holster";
		visibilityModifier = 0.9;
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"BastionMod\BastionClothing\PlateCarrier\data\isfplatecarrier_holster_co.paa"};
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class Proxyisfplatecarrier_pouches: ProxyAttachment
	{
		scope = 2;
		inventorySlot[] = {"VestPouch"};
		model = "\BastionMod\BastionClothing\PlateCarrier\isfplatecarrier_pouches.p3d";
	};
};
