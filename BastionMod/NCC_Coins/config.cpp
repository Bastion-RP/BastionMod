////////////////////////////////////////////////////////////////////
//DeRap: P:\BastionMod\NCC_Coins\config.bin
//Produced from mikero's Dos Tools Dll version 7.60
//https://mikero.bytex.digital/Downloads
//'now' is Wed Mar 25 22:21:57 2020 : 'file' last modified on Wed Mar 25 22:21:57 2020
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class BastionRPitems
	{
		units[] = {"NCC_CopperCoin","NCC_SilverCoin","NCC_GoldCoin"};
		weapons[] = {};
		requiredVersion = 1;
		requiredAddons[] = {"DZ_data"};
		author = "Swade_93";
		name = "BastionRPitems";
	};
};
class CfgMods
{
	class BastionRPitems
	{
		dir = "BastionRPitems";
		picture = "";
		action = "";
		hideName = 0;
		hidePicture = 1;
		name = "BastionRPitems";
		credits = "Bastion, Swade_93";
		author = "Swade_93";
		authorID = "76561198281669756";
		version = "1";
		extra = 0;
		type = "mod";
		dependencies[] = {"World"};
		class defs
		{
			class worldScriptModule
			{
				files[] = {"BastionMod/NCC_Coins/Scripts/4_World"};
			};
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class NCC_CopperCoin: Inventory_Base
	{
		scope = 2;
		displayName = "Copper Coin";
		descriptionShort = "NCC Currency";
		model = "\BastionMod\NCC_Coins\CopperCoin.p3d";
		isMeleeWeapon = 1;
		weight = 4;
		absorbency = 0;
		itemSize[] = {1,1};
		rotationFlags = 16;
		inventorySlot[] = {""};
	};
	class NCC_SilverCoin: NCC_CopperCoin
	{
		displayName = "Silver Coin";
		descriptionShort = "NCC Currency";
		model = "\BastionMod\NCC_Coins\SilverCoin.p3d";
	};
	class NCC_GoldCoin: NCC_CopperCoin
	{
		displayName = "Gold Coin";
		descriptionShort = "NCC Currency";
		model = "\BastionMod\NCC_Coins\GoldCoin.p3d";
	};
};
