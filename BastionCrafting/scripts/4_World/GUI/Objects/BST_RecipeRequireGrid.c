class BST_RecipeRequireGrid {
    private ref GridSpacerWidget wRoot;
    private ref Widget wParent;
    private ref TextWidget txtItemDisplayName;
    private ref ImageWidget imgHasItem;

    void BST_RecipeRequireGrid(Widget wParent, string itemDisplayName, bool hasItem) {
        this.wParent = wParent;

        wRoot = GridSpacerWidget.Cast(GetGame().GetWorkspace().CreateWidgets("BastionMod\\BastionCrafting\\gui\\layout\\ItemRequirementWidget.layout", wParent));
        txtItemDisplayName = TextWidget.Cast(wRoot.FindAnyWidget("txtItem"));
        imgHasItem = ImageWidget.Cast(wRoot.FindAnyWidget("imgStatus"));

        txtItemDisplayName.SetText(itemDisplayName);
        imgHasItem.LoadImageFile(0, "set:BST_Crafting_StatusImageSet image:redx");
        imgHasItem.LoadImageFile(1, "set:BST_Crafting_StatusImageSet image:greencheckmark");

        if (hasItem) {
            txtItemDisplayName.SetColor(BST_CraftingMenuWidget.CONST_COLOR_GREEN);
            imgHasItem.SetImage(1);
        } else {
            txtItemDisplayName.SetColor(BST_CraftingMenuWidget.CONST_COLOR_RED);
            imgHasItem.SetImage(0);
        }
    }

    void ~BST_RecipeRequireGrid() {
        if (wRoot) {
            wRoot.Unlink();
        }
        if (txtItemDisplayName) {
            txtItemDisplayName.Unlink();
        }
        if (imgHasItem) {
            imgHasItem.Unlink();
        }
    }
}