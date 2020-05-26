class CfgPatches
{
	class BastionCrafting_Data
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgVehicles
{
	class HouseNoDestruct;
	class BST_CraftingBenchBase : HouseNoDestruct {};
	class BRP_CraftingTable: BST_CraftingBenchBase
	{
		scope = 1;
		model = "\BastionMod\BastionCrafting_Data\craftingtable\craftingtable.p3d";
	};
	class BRP_Workbench1: BST_CraftingBenchBase
	{
		scope = 1;
		model = "\BastionMod\BastionCrafting_Data\workbench\workbench1.p3d";
	};
	class BRP_Workbench2: BST_CraftingBenchBase
	{
		scope = 1;
		model = "\BastionMod\BastionCrafting_Data\workbench\workbench2.p3d";
	};
	class BRP_Toolsbench_Base: BST_CraftingBenchBase
	{
		scope = 0;
		model = "\BastionMod\BastionCrafting_Data\toolsbench\toolsbench.p3d";
		hiddenSelections[]=
		{
			"",
			"metalparts",
			"woodparts"
		};
		hiddenSelectionsTextures[]=
		{
			"",
			"BastionMod\BastionCrafting_Data\toolsbench\data\toolsbench_blue_co.paa",
			"BastionMod\BastionCrafting_Data\toolsbench\data\toolsbench_wood_co.paa"
		};
	};
	class BRP_Toolsbench_Blue: BRP_Toolsbench_Base
	{
		scope = 1;
		hiddenSelectionsTextures[]=
		{
			"",
			"BastionMod\BastionCrafting_Data\toolsbench\data\toolsbench_blue_co.paa",
			"BastionMod\BastionCrafting_Data\toolsbench\data\toolsbench_wood_co.paa"
		};
	};
	class BRP_Toolsbench_Red: BRP_Toolsbench_Base
	{
		scope = 1;
		hiddenSelectionsTextures[]=
		{
			"",
			"BastionMod\BastionCrafting_Data\toolsbench\data\toolsbench_red_co.paa",
			"BastionMod\BastionCrafting_Data\toolsbench\data\toolsbench_wood_co.paa"
		};
	};
	class BRP_Toolsbench_Grey: BRP_Toolsbench_Base
	{
		scope = 1;
		hiddenSelectionsTextures[]=
		{
			"",
			"BastionMod\BastionCrafting_Data\toolsbench\data\toolsbench_grey_co.paa",
			"BastionMod\BastionCrafting_Data\toolsbench\data\toolsbench_wood_co.paa"
		};
	};
};