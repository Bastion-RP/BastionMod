class BST_RecipeGridSpacer {
    private GridSpacerWidget wRoot;
    private Widget wParent;
    private ref array<ref BST_RecipeTextWidget> arrayTextWidgets;

    void BST_RecipeGridSpacer(Widget wParent) {
        arrayTextWidgets = new array<ref BST_RecipeTextWidget>();
        this.wParent = wParent;

        wRoot = GridSpacerWidget.Cast(GetGame().GetWorkspace().CreateWidgets("BastionMod\\BastionCrafting\\gui\\layout\\GridSpacerWidget.layout", wParent));
    }

    void ~BST_RecipeGridSpacer() {
        if (wRoot) {
            wRoot.Unlink();
        }
        foreach (BST_RecipeTextWidget text : arrayTextWidgets) {
            if (text) {
                delete text;
            }
        }
    }

    void AddChild(BST_RecipeTextWidget child) {
        if (child) {
            arrayTextWidgets.Insert(child);
        }
    }

    BST_RecipeTextWidget FindWidget(Widget w) {
        foreach (BST_RecipeTextWidget txtWidget : arrayTextWidgets) {
            if (txtWidget && txtWidget.GetText() == w) {
                return txtWidget;
                
            }
        }
        return null;
    }

    GridSpacerWidget GetGrid() { return wRoot; }
    int GetChildCount() { return arrayTextWidgets.Count(); }
}