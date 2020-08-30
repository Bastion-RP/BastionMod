class BRP_CraftingBenchBase : BRP_Item 
{
    override void SetActions() 
    {
        super.SetActions();

        AddAction(BST_ActionUseBench);
    }
};

class BRP_CraftingTable_Kit : BRP_Kit 
{
    override string Get_ItemName()
	{
		return "BRP_CraftingTable";
	}
};
class BRP_CraftingTable : BRP_CraftingBenchBase 
{
    override string Get_KitName()
	{
		return "BRP_CraftingTable_Kit";
	}
};
class BRP_CraftingTable_Static : BRP_CraftingBenchBase {};
class BRP_Workbench1_Kit : BRP_Kit 
{
    override string Get_ItemName()
	{
		return "BRP_Workbench1";
	}
};
class BRP_Workbench1 : BRP_CraftingBenchBase
{
    override string Get_KitName()
	{
		return "BRP_Workbench1_Kit";
	}
};
class BRP_Workbench1_Static : BRP_CraftingBenchBase {};
class BRP_Workbench2_Kit : BRP_Kit 
{
    override string Get_ItemName()
	{
		return "BRP_Workbench2";
	}
};
class BRP_Workbench2 : BRP_CraftingBenchBase
{
    override string Get_KitName()
	{
		return "BRP_Workbench2_Kit";
	}
};
class BRP_Workbench2_Static : BRP_CraftingBenchBase {};

//Toolsbench
class BRP_Toolsbench_Base : BRP_CraftingBenchBase {};
class BRP_Toolsbench_Blue_Kit : BRP_Kit 
{
    override string Get_ItemName()
	{
		return "BRP_Toolsbench_Blue";
	}
};
class BRP_Toolsbench_Blue : BRP_Toolsbench_Base
{
    override string Get_KitName()
	{
		return "BRP_Toolsbench_Blue_Kit";
	}
};
class BRP_Toolsbench_Red_Kit : BRP_Kit 
{
    override string Get_ItemName()
	{
		return "BRP_Toolsbench_Red";
	}
};
class BRP_Toolsbench_Red : BRP_Toolsbench_Base 
{
    override string Get_KitName()
	{
		return "BRP_Toolsbench_Red_Kit";
	}
};
class BRP_Toolsbench_Grey_Kit : BRP_Kit 
{
    override string Get_ItemName()
	{
		return "BRP_Toolsbench_Grey";
	}
};
class BRP_Toolsbench_Grey : BRP_Toolsbench_Base 
{
    override string Get_KitName()
	{
		return "BRP_Toolsbench_Grey_Kit";
	}
};