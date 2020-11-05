class BST_MCGUIScriptedMenu : ScriptedWidgetEventHandler {
    protected ref Widget _root, _parent;
    protected BST_MCGUIMainMenu _rootMenu;

    void BST_MCGUIScriptedMenu(BST_MCGUIMainMenu rootMenu, Widget parent) {
        _parent = parent;
        _rootMenu = rootMenu;
    }

    void Show(bool show) {
        _root.Show(show);
    }

    void Init() { }
    void SetCharacter(BST_MCSavePlayerBasic character) { }
}