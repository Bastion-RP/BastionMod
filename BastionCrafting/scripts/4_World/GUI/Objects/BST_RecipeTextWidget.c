class BST_RecipeTextWidget {
    private TextWidget wRoot;
    private Widget wParent;
    private BST_CraftingLoadedRecipe recipe;

    void BST_RecipeTextWidget(string recipeName, Widget wParent, BST_CraftingLoadedRecipe recipe) {
        this.wParent = wParent;
        this.recipe = recipe;

        wRoot = TextWidget.Cast(GetGame().GetWorkspace().CreateWidgets("BastionMod\\BastionCrafting\\gui\\layout\\TextWidget.layout", wParent));

        wRoot.SetText(recipeName);
    }

    void ~BST_RecipeTextWidget() {
        if (wRoot) {
            wRoot.Unlink();
        }
    }

    void Select() {
        wRoot.SetColor(ARGB(255, 255, 0, 0));
    }

    void Deselect() {
        wRoot.SetColor(ARGB(255, 255, 255, 255));
    }

    TextWidget GetText() { return wRoot; }
    BST_CraftingLoadedRecipe GetRecipe() { return recipe; }
}