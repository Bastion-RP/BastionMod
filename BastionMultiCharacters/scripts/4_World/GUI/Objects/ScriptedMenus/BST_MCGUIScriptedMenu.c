class BST_MCGUIScriptedMenu : ScriptedWidgetEventHandler {
    protected ref Widget _root, _parent;
    protected ref BST_MCGUICharPreviewWidget _pnlPlyPreview;
    protected ref BST_MCGUICharInfoWidget _pnlCharInfo;

    void BST_MCGUIScriptedMenu(Widget parent) {
        _parent = parent;
    }

    void Show(bool show) {
        _root.Show(show);
    }

    void Init() { }
    void Init(BST_MCSavePlayerBasic character) { }
}