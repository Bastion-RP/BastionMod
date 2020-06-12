modded class ItemBase {
    private ref BST_FurnaceHandler bst_FurnaceHandler;

    void CreateFurnaceHandler() {
        bst_FurnaceHandler = new BST_FurnaceHandler(this);
    }

    override void SetActions() {
        super.SetActions();

        AddAction(BST_ActionStartStopSmelting);
    }

    BST_FurnaceHandler GetBSTFurnaceHandler() { return bst_FurnaceHandler; }
}