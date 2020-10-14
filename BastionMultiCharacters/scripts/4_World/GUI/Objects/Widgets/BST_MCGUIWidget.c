class BST_MCGUIWidget {
    protected ref Widget _root, _parent;

    void BST_MCGUIWidget(Widget parent) {
        _parent = parent;
    }

    void Show(bool show) {
        _root.Show(show);
    }

    Widget GetRoot() { return _root; }
    Widget GetParent() { return _parent; }
}