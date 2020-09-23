class BST_CraftingMenu : UIScriptedMenu {
    private ref BST_CraftingMenuWidget _craftingWidget;
    
    void BST_CraftingMenu() {
        _craftingWidget = new BST_CraftingMenuWidget();

        _craftingWidget.Init(null);
    }
    void OnShow() {
        super.OnShow();
        _craftingWidget.OnShow();
        GetGame().GetMission().PlayerControlDisable(INPUT_EXCLUDE_ALL);
        GetGame().GetUIManager().ShowCursor(true);
        GetGame().GetMission().GetHud().Show(false);
    }

    void OnHide() {
        super.OnHide();
        _craftingWidget.OnHide();
        GetGame().GetUIManager().ShowCursor(false);
        GetGame().GetMission().PlayerControlEnable(true);
        GetGame().GetMission().GetHud().Show(true);
    }

    void SetBench(BRP_CraftingBenchBase benchBase) {
        _craftingWidget.SetBench(benchBase);
    }

    bool IsTyping() {
        return _craftingWidget.IsTyping();
    }

    void ~BST_CraftingMenu() {
        if (_craftingWidget) {
            delete _craftingWidget;
        }
    }
}