class CfgPatches
{
	class BastionMisc_Data
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgVehicles
{
	class HouseNoDestruct;
	class BRP_WaterTank1: HouseNoDestruct
	{
		scope = 1;
		model = "\BastionMod\BastionMisc_Data\watertank\watertank1.p3d";
		hiddenSelections[] = 
		{
			"all"
		};
		hiddenSelectionsTextures[] = 
		{
			"\BastionMod\BastionMisc_Data\watertank\data\watertank_co.paa"
		};
	};
	class BRP_WaterTank2: HouseNoDestruct
	{
		scope = 1;
		model = "\BastionMod\BastionMisc_Data\watertank\watertank2.p3d";
		hiddenSelections[] = 
		{
			"all"
		};
		hiddenSelectionsTextures[] = 
		{
			"\BastionMod\BastionMisc_Data\watertank\data\watertank2_co.paa"
		};
	};
	class BRP_AION_Crate: HouseNoDestruct
	{
		scope = 0;
		model = "\BastionMod\BastionMisc_Data\crate\crate.p3d";
		hiddenSelections[] = 
		{
			"all"
		};
		hiddenSelectionsTextures[] = 
		{
			"\BastionMod\BastionMisc_Data\crate\data\crate_co.paa"
		};
	};
	
	class BRP_AIONPowder_Crate: BRP_AION_Crate
	{
		scope = 1;
	};
	class BRP_AIONBottle_Crate: BRP_AION_Crate
	{
		scope = 1;
		model = "\BastionMod\BastionMisc_Data\crate\crate_aionbottles.p3d";
	};
};
