class BST_CraftingMenu : UIScriptedMenu {
    private ref Widget wRoot, recipeRoot;
    private ref GridSpacerWidget gridRoot;
    private ref TextWidget recipeTitle;
    private ref ButtonWidget btnCraft;
    private ref BST_RecipeGridSpacer activeGrid;
    private ref BST_RecipeTextWidget activeRecipe;
    private ref array<ref BST_RecipeGridSpacer> arrayGridSpacers;

    void ~BST_CraftingMenu() {
        Cleanup();
    }

    override Widget Init() {
        arrayGridSpacers = new array<ref BST_RecipeGridSpacer>();

        wRoot = GetGame().GetWorkspace().CreateWidgets("BastionMod\\BastionCrafting\\gui\\layout\\CraftingMenu.layout");
        gridRoot = GridSpacerWidget.Cast(wRoot.FindAnyWidget("gridRecipesRoot"));
        recipeRoot = wRoot.FindAnyWidget("pnlSelectedRecipe");
        recipeTitle = TextWidget.Cast(wRoot.FindAnyWidget("txtSelectedRecipeName"));
        btnCraft = ButtonWidget.Cast(wRoot.FindAnyWidget("btnCraft"));

        return wRoot;
    }

    void Cleanup() {
        if (activeGrid) {
            delete activeGrid;
        }
        foreach (BST_RecipeGridSpacer grid : arrayGridSpacers) {
            if (grid) {
                delete grid;
            }
        }
    }

    void BuildMenu() {
        array<ref BST_CraftingLoadedRecipe> arrayRecipes = PlayerBase.Cast(GetGame().GetPlayer()).arrayCraftingRecipes;

        foreach (BST_CraftingLoadedRecipe recipe : arrayRecipes) {
            if (recipe) {
                CheckCurrentGridSpacer();

                BST_RecipeTextWidget newRecipe = new BST_RecipeTextWidget(recipe.GetName() + " | " + recipe.GetDescription() + " | " + recipe.GetCraftTime(), activeGrid.GetGrid(), recipe);

                activeGrid.AddChild(newRecipe);
            }
        }
    }
    
    void CheckCurrentGridSpacer() {
        if (!activeGrid || activeGrid.GetChildCount() >= 100) {
            activeGrid = new BST_RecipeGridSpacer(gridRoot);

            arrayGridSpacers.Insert(activeGrid);
        }
    }

    void OnShow() {
        super.OnShow();
        GetGame().GetMission().PlayerControlDisable(INPUT_EXCLUDE_ALL);
        GetGame().GetUIManager().ShowCursor(true);
        GetGame().GetMission().GetHud().Show(false);
        BuildMenu();
    }

    void OnHide() {
        super.OnHide();
        GetGame().GetUIManager().ShowCursor(false);
        GetGame().GetMission().PlayerControlEnable(true);
        GetGame().GetMission().GetHud().Show(true);
        Cleanup();
    }

    BST_RecipeTextWidget FindWidgetInGrid(Widget w) {
        foreach (BST_RecipeGridSpacer grid : arrayGridSpacers) {
            if (grid) {
                BST_RecipeTextWidget foundWidget = grid.FindWidget(w);

                if (foundWidget) {
                    return foundWidget;
                }
            }
        }
        return null;
    }

    override bool OnClick(Widget w, int x, int y, int button) {
        if (w == btnCraft) {
            Print("[DEBUG] Sending RPC to server");
            GetGame().RPCSingleParam(GetGame().GetPlayer(), BST_CraftingRPC.SERVER_CRAFT_ITEM, new Param1<string>(activeRecipe.GetRecipe().GetFileName()), true);
        }
        return super.OnClick(w, x, y, button);
    }

    override bool OnMouseButtonUp(Widget w, int x, int y, int button) {
        if (TextWidget.Cast(w)) {
            BST_RecipeTextWidget txtWidget = FindWidgetInGrid(w);

            if (txtWidget) {
                if (txtWidget != activeRecipe) {
                    if (activeRecipe) {
                        activeRecipe.Deselect();
                    }
                    activeRecipe = txtWidget;

                    txtWidget.Select();
                    recipeRoot.Show(true);
                    recipeTitle.SetText(txtWidget.GetRecipe().GetName());
                } else {
                    activeRecipe.Deselect();

                    activeRecipe = null;

                    recipeRoot.Show(false);
                }
            }
        }
        return super.OnMouseButtonUp(w, x, y, button);
    }
}