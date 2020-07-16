class BRP_CraftingBenchBase : Container_Base {
    override void SetActions() {
        super.SetActions();

        AddAction(BST_ActionUseBench);
    }
}

class BRP_CraftingTable : BRP_CraftingBenchBase {}
class BRP_Workbench1 : BRP_CraftingBenchBase {}
class BRP_Workbench2 : BRP_CraftingBenchBase {}
class BRP_Toolsbench_Base : BRP_CraftingBenchBase {}
class BRP_Toolsbench_Blue : BRP_Toolsbench_Base {}
class BRP_Toolsbench_Red : BRP_Toolsbench_Base {}
class BRP_Toolsbench_Grey : BRP_Toolsbench_Base {}