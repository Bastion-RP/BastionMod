////////////////////////////////////////////////////////////////////
//DeRap: P:\BastionMod\BastionBanking_Data\config.bin
//Produced from mikero's Dos Tools Dll version 7.60
//https://mikero.bytex.digital/Downloads
//'now' is Tue Apr 28 21:16:34 2020 : 'file' last modified on Tue Apr 28 21:16:34 2020
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class BastionRPitems
	{
		units[] = {"NCC_ATM","NCC_CopperCoin","NCC_SilverCoin","NCC_GoldCoin"};
		weapons[] = {};
		requiredVersion = 1;
		requiredAddons[] = {"DZ_data"};
		author = "Swade_93";
		name = "BastionRPitems";
	};
};
class CfgVehicles
{
	class Inventory_Base;
// - NCC ATM Machine
	class NCC_ATM: Inventory_Base
	{
		scope=2;
		model="\BastionMod\BastionBanking_Data\NCC_ATM.p3d";
		physLayer="item_large";
		handheld="false"; // Didnt work :( can still take to hands
		itemSize[]={9,14};
	};
	class NCC_CopperCoin: Inventory_Base
	{
		scope = 2;
		displayName = "Credit (Copper)";
		descriptionShort = "An NCC Credit. It appears to be plated in copper.";
		model = "\BastionMod\BastionBanking_Data\CopperCoin.p3d";
		canBeSplit = 1;
		varQuantityInit = 50;
		varQuantityMin = 0;
		varQuantityMax = 50;
		isMeleeWeapon = 1;
		weight = 4;
		absorbency = 0;
		itemSize[] = {1,1};
		rotationFlags = 16;
		inventorySlot[] = {""};
	};
	class NCC_SilverCoin: NCC_CopperCoin
	{
		displayName = "Credit (Silver)";
		descriptionShort = "An NCC Credit. It appears to be plated in silver.";
		model = "\BastionMod\BastionBanking_Data\SilverCoin.p3d";
	};
	class NCC_GoldCoin: NCC_CopperCoin
	{
		displayName = "Credit (Gold)";
		descriptionShort = "An NCC Credit. It appears to be plated in gold.";
		model = "\BastionMod\BastionBanking_Data\GoldCoin.p3d";
	};
};
