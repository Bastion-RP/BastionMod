class BST_GUIRecipe : BST_GUIObject {
    private Widget _root;
    private TextWidget _txtName;
    private BST_CraftingLoadedRecipe _recipe;

    void BST_GUIRecipe(Widget parent, BST_CraftingLoadedRecipe recipe, int type) {
        this._parent = parent;
        this._recipe = recipe;

        switch (type) {
            case 0:
                {
                    _root = GetGame().GetWorkspace().CreateWidgets("BastionMod\\BastionCrafting\\gui\\layout\\TextWidget.layout", parent);
                    break;
                }
            case 1:
                {
                    _root = GetGame().GetWorkspace().CreateWidgets("BastionMod\\BastionCrafting\\gui\\layout\\TextWidgetIndent.layout", parent);
                    break;
                }
            case 2:
                {
                    _root = GetGame().GetWorkspace().CreateWidgets("BastionMod\\BastionCrafting\\gui\\layout\\TextWidgetIndent2.layout", parent);
                    break;
                }
        }
        _txtName = TextWidget.Cast(_root.FindAnyWidget("txtName"));
        _txtName.SetText(recipe.GetName());
    }

    void ~BST_GUIRecipe() {
        if (_txtName) {
            _txtName.Unlink();
        }
        if (_root) {
            _root.Unlink();
        }
    }

    void Select() {
        _txtName.SetColor(BST_CraftingMenuWidget.CONST_COLOR_BST_ORANGE);
    }

    void Deselect() {
        _txtName.SetColor(BST_CraftingMenuWidget.CONST_COLOR_WHITE);
    }

    TextWidget GetText() { return _txtName; }
    BST_CraftingLoadedRecipe GetRecipe() { return _recipe; }
}