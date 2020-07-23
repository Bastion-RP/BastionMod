class BST_RecordGridSpacer {
    private Widget _parent;
    private GridSpacerWidget _root;
    private ref array<ref BST_GUIRecord> _arrGUIObjects;

    void BST_RecordGridSpacer(Widget parent) {
        _arrGUIObjects = new array<ref BST_GUIRecord>();
        _parent = parent;
        _root = GridSpacerWidget.Cast(GetGame().GetWorkspace().CreateWidgets("BastionMod\\BastionDTAC\\gui\\layouts\\GridSpacer.layout", parent));
    }

    void ~BST_RecordGridSpacer() {
        if (_root) {
            _root.Unlink();
        }
        foreach (BST_GUIRecord object : _arrGUIObjects) {
            if (object) {
                delete object;
            }
        }
    }

    void AddChild(BST_GUIRecord child) {
        if (child) {
            _arrGUIObjects.Insert(child);
        }
    }

    GridSpacerWidget GetGrid() { return _root; }
    int GetChildCount() { return _arrGUIObjects.Count(); }
}