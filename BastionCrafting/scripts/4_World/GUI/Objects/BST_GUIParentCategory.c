class BST_GUIParentCategory : BST_GUICategory {
    private ref BST_CraftingCategory _category;

    void BST_GUIParentCategory(Widget parent, BST_CraftingCategory category) {
        this._category = category;

        _root = GridSpacerWidget.Cast(GetGame().GetWorkspace().CreateWidgets("BastionMod\\BastionCrafting\\gui\\layout\\CategoryWidget.layout", parent));
        _txtName = TextWidget.Cast(_root.FindAnyWidget("txtName"));
        _txtCaret = TextWidget.Cast(_root.FindAnyWidget("txtCaret"));
        _txtWrap = TextWidget.Cast(_root.FindAnyWidget("txtWrap"));
        if (category) {
            _txtName.SetText(category.GetName());
        } else {
            _txtName.SetText("Uncategorized");
        }
        _txtCaret.SetText("v");
    }

    BST_GUISubCategory AddSubCategory(BST_CraftingSubCategory subCategory) {
        CheckCurrentGridSpacer();

        BST_GUISubCategory guiSubCategory = new BST_GUISubCategory(_activeGrid.GetGrid(), this, subCategory);

        _activeGrid.AddChild(guiSubCategory);
        return guiSubCategory;
    }

}