class BST_MCGUIWidget {
    protected ref Widget _root, _parent;
    protected ScriptedWidgetEventHandler _handler;

    void BST_MCGUIWidget(Widget parent) {
        _parent = parent;
    }

    void Show(bool show) {
        _root.Show(show);
    }

    void SetPos(int x, int y) {
        _root.SetPos(x, y);
    }

    Widget GetRoot() { return _root; }
    Widget GetParent() { return _parent; }

    void ~BST_MCGUIWidget() {
        Print("[DEBUG] BST_MCGUIWidget | Destructor");
        _root.Unlink();
    }
}