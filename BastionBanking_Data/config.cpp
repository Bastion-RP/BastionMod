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
		units[] = {"BRP_ATM","BRP_CopperCoin","BRP_SilverCoin","BRP_GoldCoin"};
		weapons[] = {};
		requiredVersion = 1;
		requiredAddons[] = {"DZ_data"};
		author = "Swade_93";
		name = "BastionRPitems";
	};
};
class CfgVehicles
{
	class HouseNoDestruct;
	class Inventory_Base;
	class BRP_ATM: HouseNoDestruct
	{
		scope=1;
		model="\BastionMod\BastionBanking_Data\ATM\atm.p3d";
	};

	class BRP_Coin_Base: Inventory_Base
	{
		scope = 0;
		model = "\BastionMod\BastionBanking_Data\Coin\coin.p3d";
		canBeSplit = 1;
		varQuantityInit = 50;
		varQuantityMin = 0;
		varQuantityMax = 50;
		isMeleeWeapon = 1;
		weight = 4;
		absorbency = 0;
		itemSize[] = {1,1};
		rotationFlags = 16;		
		hiddenSelections[] = 
		{
			"all"
		};
		hiddenSelectionsTextures[] = 
		{
			"\BastionMod\BastionBanking_Data\Coin\data\coin_copper_co.paa"
		};
		hiddenSelectionsMaterials[] = 
		{
			"BastionMod\BastionBanking_Data\Coin\data\coin_copper.rvmat"
		};
	};
	
	class BRP_CopperCoin: BRP_Coin_Base
	{
		scope = 2;
		displayName = "Credit (Copper)";
		descriptionShort = "An NCC Credit. It appears to be plated in copper.";
		hiddenSelectionsTextures[] = 
		{
			"\BastionMod\BastionBanking_Data\Coin\data\coin_copper_co.paa"
		};
		hiddenSelectionsMaterials[] = 
		{
			"BastionMod\BastionBanking_Data\Coin\data\coin_copper.rvmat"
		};
	};

	class BRP_SilverCoin: BRP_Coin_Base
	{
		scope = 2;
		displayName = "Credit (Silver)";
		descriptionShort = "An NCC Credit. It appears to be plated in silver.";
		hiddenSelectionsTextures[] = 
		{
			"\BastionMod\BastionBanking_Data\Coin\data\coin_silver_co.paa"
		};
		hiddenSelectionsMaterials[] = 
		{
			"BastionMod\BastionBanking_Data\Coin\data\coin_silver.rvmat"
		};
	};
	class BRP_GoldCoin: BRP_Coin_Base
	{
		scope = 2;
		displayName = "Credit (Gold)";
		descriptionShort = "An NCC Credit. It appears to be plated in gold.";
		hiddenSelectionsTextures[] = 
		{
			"\BastionMod\BastionBanking_Data\Coin\data\coin_gold_co.paa"
		};
		hiddenSelectionsMaterials[] = 
		{
			"BastionMod\BastionBanking_Data\Coin\data\coin_gold.rvmat"
		};
	};
};
