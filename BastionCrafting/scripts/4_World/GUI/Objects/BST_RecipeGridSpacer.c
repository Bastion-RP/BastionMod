class BST_RecipeGridSpacer : BST_GUIObject {
    private GridSpacerWidget _root;
    private ref array<ref BST_GUIObject> _arrGUIOBjects;

    void BST_RecipeGridSpacer(Widget parent) {
        _arrGUIOBjects = new array<ref BST_GUIObject>();
        this._parent = parent;

        _root = GridSpacerWidget.Cast(GetGame().GetWorkspace().CreateWidgets("BastionMod\\BastionCrafting\\gui\\layout\\GridSpacerWidget.layout", parent));
    }

    void ~BST_RecipeGridSpacer() {
        if (_root) {
            _root.Unlink();
        }
        foreach (BST_GUIObject object : _arrGUIOBjects) {
            if (object) {
                delete object;
            }
        }
    }

    void AddChild(BST_GUIObject child) {
        if (child) {
            _arrGUIOBjects.Insert(child);
        }
    }

    GridSpacerWidget GetGrid() { return _root; }
    int GetChildCount() { return _arrGUIOBjects.Count(); }
}