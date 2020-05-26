class BST_CraftingBenchBase : ItemBase {
    override void SetActions() {
        super.SetActions();

        AddAction(BST_ActionUseBench);
    }
}