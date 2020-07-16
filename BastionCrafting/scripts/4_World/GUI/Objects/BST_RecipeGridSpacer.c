class BST_RecipeGridSpacer : BST_GUIObject {
    private GridSpacerWidget _root;
    private ref array<ref BST_GUIObject> _arrGUIObjects;

    void BST_RecipeGridSpacer(Widget parent) {
        _arrGUIObjects = new array<ref BST_GUIObject>();
        this._parent = parent;

        _root = GridSpacerWidget.Cast(GetGame().GetWorkspace().CreateWidgets("BastionMod\\BastionCrafting\\gui\\layout\\GridSpacerWidget.layout", parent));
    }

    void ~BST_RecipeGridSpacer() {
        if (_root) {
            _root.Unlink();
        }
        foreach (BST_GUIObject object : _arrGUIObjects) {
            if (object) {
                delete object;
            }
        }
    }

    void AddChild(BST_GUIObject child) {
        if (child) {
            _arrGUIObjects.Insert(child);
        }
    }

    GridSpacerWidget GetGrid() { return _root; }
    int GetChildCount() { return _arrGUIObjects.Count(); }
}