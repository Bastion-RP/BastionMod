class BST_GUISubCategory : BST_GUICategory {
    private ref BST_GUIParentCategory _guiParentCategory;
    private ref BST_CraftingSubCategory _subCategory;

    void BST_GUISubCategory(Widget parent, BST_GUIParentCategory guiParentCategory, BST_CraftingSubCategory subCategory) {
        this._parent = parent;
        this._guiParentCategory = guiParentCategory;
        this._subCategory = subCategory;

        _root = GridSpacerWidget.Cast(GetGame().GetWorkspace().CreateWidgets("BastionMod\\BastionCrafting\\gui\\layout\\SubCategoryWidget.layout", parent));
        _txtName = TextWidget.Cast(_root.FindAnyWidget("txtName"));
        _txtCaret = TextWidget.Cast(_root.FindAnyWidget("txtCaret"));
        _txtWrap = TextWidget.Cast(_root.FindAnyWidget("txtWrap"));

        _txtName.SetText(_subCategory.GetName());
        _txtCaret.SetText("v");
    }

    //TODO causes an error that recipes in subcategories to not be clickable
    override BST_GUIRecipe AddRecipeWidget(BST_CraftingLoadedRecipe recipe, int type, bool isSearching) {
        BST_GUIRecipe newWidget = super.AddRecipeWidget(recipe, type, isSearching);

        if (isSearching) {
            _guiParentCategory.ShowChildren();
        }
        return newWidget;
    }
}