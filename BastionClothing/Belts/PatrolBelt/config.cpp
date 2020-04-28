////////////////////////////////////////////////////////////////////
//DeRap: P:\BastionMod\BastionClothing\Belts\PatrolBelt\config.bin
//Produced from mikero's Dos Tools Dll version 7.60
//https://mikero.bytex.digital/Downloads
//'now' is Tue Apr 28 20:29:11 2020 : 'file' last modified on Tue Apr 28 20:29:11 2020
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class NCC_PatrolBelt
	{
		units[] = {"ISF_PatrolBelt"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Characters","DZ_Characters_Pants","DZ_Characters_Tops","DZ_Characters_Vests","DZ_Data"};
	};
};
class cfgVehicles
{
	class Clothing_Base;
	class Clothing: Clothing_Base{};
	class CivilianBelt;
	class ISF_PatrolBelt: CivilianBelt
	{
		scope = 2;
		model = "BastionMod\BastionClothing\Belts\PatrolBelt\nccbelt.p3d";
		displayName = "Patrol Belt";
		attachments[] = {"Baton","Pistol"};
		descriptionShort = "";
		visibilityModifier = 1;
		inventorySlot = "Hips";
		itemInfo[] = {"Clothing","Hips"};
		class ClothingTypes
		{
			male = "BastionMod\BastionClothing\Belts\PatrolBelt\nccbelt_m.p3d";
			female = "BastionMod\BastionClothing\Belts\PatrolBelt\nccbelt_f.p3d";
		};
	};
	class Powered_Base;
	class StunBaton: Powered_Base
	{
		inventorySlot[] = {"Baton"};
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class Proxyfnp45: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "Pistol";
		model = "\DZ\weapons\pistols\fnx45\fnp45.p3d";
	};
	class ProxyStun_Baton: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "Baton";
		model = "\dz\weapons\melee\powered\Stun_Baton.p3d";
	};
	class Proxyglock19: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "Pistol";
		model = "\DZ\weapons\pistols\glock\glock19.p3d";
	};
	class Proxynccbelt_holster: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "BeltHolster";
		model = "BastionMod\BastionClothing\Belts\PatrolBelt\nccbelt_holster.p3d";
	};
};
class CfgSlots
{
	class Slot_Baton
	{
		name = "Baton";
		displayName = "Baton";
		ghostIcon = "Melee";
	};
	class Slot_BeltHolster
	{
		name = "BeltHolster";
		displayName = "BeltHolster";
		ghostIcon = "Melee";
	};
};
