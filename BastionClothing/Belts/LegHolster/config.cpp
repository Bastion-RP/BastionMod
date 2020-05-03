////////////////////////////////////////////////////////////////////
//DeRap: P:\BastionMod\BastionClothing\Belts\LegHolster\config.bin
//Produced from mikero's Dos Tools Dll version 7.60
//https://mikero.bytex.digital/Downloads
//'now' is Tue Apr 28 20:31:15 2020 : 'file' last modified on Tue Apr 28 20:31:15 2020
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class NCC_MollePlatform
	{
		units[] = {"ISF_MolleBelt"};
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
	class BRP_ISF_MolleBelt: CivilianBelt
	{
		scope = 2;
		model = "BastionMod\BastionClothing\Belts\LegHolster\doublethighholstersmall_g.p3d";
		displayName = "Patrol Belt";
		attachments[] = {"Baton","Pistol"};
		descriptionShort = "";
		visibilityModifier = 1;
		inventorySlot = "Hips";
		itemInfo[] = {"Clothing","Hips"};
		class ClothingTypes
		{
			male = "BastionMod\BastionClothing\Belts\LegHolster\doublethighholstersmall_m.p3d";
			female = "BastionMod\BastionClothing\Belts\LegHolster\doublethighholstersmall_f.p3d";
		};
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
};
