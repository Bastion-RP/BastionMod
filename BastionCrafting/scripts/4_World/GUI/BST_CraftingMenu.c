class BST_CraftingMenu : UIScriptedMenu {
    static const int CONST_COLOR_RED = ARGB(255, 255, 0, 0);
    static const int CONST_COLOR_GREEN = ARGB(255, 0, 255, 0);
    static const int CONST_COLOR_WHITE = ARGB(255, 255, 255, 255);
    static const int CONST_COLOR_BST_ORANGE = ARGB(255, 255, 149, 0);
    static const int CONST_COLOR_GRAY = ARGB(255, 180, 180, 180);
    static const string CONST_STRING_SEARCH = "Search for blueprints";

    private ref array<ref BST_CraftingLoadedRecipe> arrayRecipes;
    private ref Widget wRoot, recipeRoot, pnlCraftingProgressBar;
    private ref GridSpacerWidget gridRoot, gridRecipeIngredients, gridRecipeToolRequirements;
    private ref TextWidget txtRecipeTitle, txtRecipeDesc, txtRecipeCraftTime;
    private ref ItemPreviewWidget prvRecipeProduct;
    private ref EditBoxWidget edtSearch;
    private ref ButtonWidget btnCraft;
    private ref ScrollWidget scrollerRecipes;
    private ref BST_RecipeGridSpacer activeGrid;
    private ref BST_RecipeTextWidget activeRecipe, craftingRecipe;
    private ref array<ref BST_RecipeGridSpacer> arrayGridSpacers;
    private ref array<ref BST_RecipeRequireGrid> arrayGridIngredients;
    private PlayerBase player;
    private EntityAI entityRecipeProduct;
    private BRP_CraftingBenchBase benchBase;
    private bool isCrafting, requiresBench, hasRequiredBench, hasIngredients;
    private string previousEntry;
    private float craftingTimePassed;

    void ~BST_CraftingMenu() {
        Cleanup();
    }

    override Widget Init() {
        arrayGridSpacers = new array<ref BST_RecipeGridSpacer>();
        arrayGridIngredients = new array<ref BST_RecipeRequireGrid>();
        arrayRecipes = new array<ref BST_CraftingLoadedRecipe>();

        wRoot = GetGame().GetWorkspace().CreateWidgets("BastionMod\\BastionCrafting\\gui\\layout\\CraftingMenu.layout");
        pnlCraftingProgressBar = wRoot.FindAnyWidget("pnlProgress");
        gridRoot = GridSpacerWidget.Cast(wRoot.FindAnyWidget("gridRecipesRoot"));
        gridRecipeIngredients = GridSpacerWidget.Cast(wRoot.FindAnyWidget("gridRecipeRequire"));
        gridRecipeToolRequirements = GridSpacerWidget.Cast(wRoot.FindAnyWidget("gridRecipeToolRequire"));
        edtSearch = EditBoxWidget.Cast(wRoot.FindAnyWidget("edtSearch"));
        prvRecipeProduct = ItemPreviewWidget.Cast(wRoot.FindAnyWidget("prvRecipeItem"));
        recipeRoot = wRoot.FindAnyWidget("pnlSelectedRecipe");
        scrollerRecipes = wRoot.FindAnyWidget("scrollerRecipes");
        txtRecipeTitle = TextWidget.Cast(wRoot.FindAnyWidget("txtSelectedRecipeName"));
        txtRecipeDesc = TextWidget.Cast(wRoot.FindAnyWidget("txtSelectedRecipeDesc"));
        txtRecipeCraftTime = TextWidget.Cast(wRoot.FindAnyWidget("txtSelectedRecipeTimetoCraft"));
        btnCraft = ButtonWidget.Cast(wRoot.FindAnyWidget("btnCraft"));
        
        return wRoot;
    }

    void Cleanup() {
        if (activeGrid) {
            delete activeGrid;
        }
        if (benchBase) {
            benchBase = null;
        }
        previousEntry = string.Empty;
        isCrafting = false;
        requiresBench = false;
        hasRequiredBench = false;
        hasIngredients = false;
        craftingTimePassed = 0.0;

        CleanupRecipes();
        CleanupIngredients();
    }

    void BuildMenu(string searchString = "") {
        foreach (BST_CraftingLoadedRecipe recipe : arrayRecipes) {
            if (recipe) {
                if (searchString != "") {
                    searchString = searchString.Trim();
                    searchString.ToLower();

                    if (recipe.GetLoweredName().IndexOf(searchString) == -1) { continue; }
                }
                CheckCurrentGridSpacer();

                BST_RecipeTextWidget newRecipe = new BST_RecipeTextWidget(recipe.GetName(), activeGrid.GetGrid(), recipe);

                activeGrid.AddChild(newRecipe);
            }
        }
        scrollerRecipes.VScrollToPos01(0);
    }

    void CleanupRecipes() {
        if (arrayGridSpacers) {
            foreach (BST_RecipeGridSpacer grid : arrayGridSpacers) {
                if (grid) {
                    delete grid;
                }
            }
            delete arrayGridSpacers;
            arrayGridSpacers = new array<ref BST_RecipeGridSpacer>();
        }
    }

    void CleanupIngredients() {
        if (!arrayGridIngredients) { return; }
        for (int i = (arrayGridIngredients.Count() - 1); i >= 0; i--) {
            BST_RecipeRequireGrid deleteGrid = arrayGridIngredients[i];

            if (deleteGrid) {
                delete deleteGrid;
            }
            arrayGridIngredients.Remove(i);
        }
    }
    
    void CheckCurrentGridSpacer() {
        if (!activeGrid || activeGrid.GetChildCount() >= 100) {
            activeGrid = new BST_RecipeGridSpacer(gridRoot);

            arrayGridSpacers.Insert(activeGrid);
        }
    }

    override void Update(float timeslice) {
        if (GetFocus() == edtSearch) {
            if (edtSearch.GetText() == CONST_STRING_SEARCH) {
                edtSearch.SetText(string.Empty);
            }
        } else {
            if (edtSearch.GetText() == string.Empty) {
                edtSearch.SetText(CONST_STRING_SEARCH);
            }
        }
        if (recipeRoot.IsVisible()) {
            if (isCrafting || !hasIngredients || (requiresBench && !hasRequiredBench)) {
                if (btnCraft.GetColor() != CONST_COLOR_GRAY) {
                    btnCraft.SetColor(CONST_COLOR_GRAY);
                }
            } else {
                if (btnCraft.GetColor() != CONST_COLOR_BST_ORANGE) {
                    btnCraft.SetColor(CONST_COLOR_BST_ORANGE);
                }
            }
        }
        if (craftingRecipe && isCrafting) {
            if (craftingRecipe == activeRecipe) {
                int craftTime = activeRecipe.GetRecipe().GetCraftTime();
                craftingTimePassed += timeslice;

                pnlCraftingProgressBar.SetSize((craftingTimePassed / craftTime), 1);

                if (!pnlCraftingProgressBar.IsVisible()) {
                    pnlCraftingProgressBar.Show(true);
                }
                if (craftingTimePassed >= craftTime) {
                    isCrafting = false;
                    hasIngredients = false;
                    craftingTimePassed = 0.0;
                    
                    GetGame().RPCSingleParam(player, BST_CraftingRPC.SERVER_CRAFT_ITEM, new Param2<string, EntityAI>(activeRecipe.GetRecipe().GetFileName(), benchBase), true);
                    GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(this.RefreshBuildWindow, 2000);
                }
            } else {
                craftingTimePassed = 0.0;
                isCrafting = false;

                pnlCraftingProgressBar.Show(false);
            }
        }
        super.Update(timeslice);
    }

    void RefreshBuildWindow() {
        pnlCraftingProgressBar.Show(false);
        CleanupIngredients();
        BuildRecipeWindow();
    }

    void BuildRecipeWindow() {
        BST_RecipeRequireGrid newGridIngredient;
        map<string, int> mapRequiredCount;
        array<ref BST_CraftingIngredient> arrayCraftingIngredients = activeRecipe.GetRecipe().GetIngredients();
        array<EntityAI> arrayVicinityContainers = GetBSTVicinityItemManager().RefreshVicinityItems(player);

        Print("[Menu DEBUG] array=" + arrayVicinityContainers);
        if (benchBase && arrayVicinityContainers.Count() > 0) {
            Print("[DEBUG] Grabbing ingredients in vicinity");
            mapRequiredCount = GetBSTClientCraftingManager().GetIngredientAmountInVicinityandPlayer(activeRecipe.GetRecipe(), arrayVicinityContainers);
        } else {
            Print("[DEBUG] Grabbing ingredients only on player");
            mapRequiredCount = GetBSTClientCraftingManager().GetIngredientAmountOnPlayer(activeRecipe.GetRecipe());
        }
        string requiredBench = activeRecipe.GetRecipe().GetRequiredBench();

        requiresBench = false;
        hasIngredients = true;

        // Build ingredient grid
        if (mapRequiredCount == null) {
            newGridIngredient = new BST_RecipeRequireGrid(gridRecipeIngredients, "ERROR OCCURRED WHEN TRYING TO GRAB CLIENT. REFRESH", false);
            arrayGridIngredients.Insert(newGridIngredient);
        } else {
            foreach (BST_CraftingIngredient ingredient : arrayCraftingIngredients) {
                if (!ingredient) { continue; }

                EntityAI tempObject;
                bool hasRequiredAmount;
                string ingredientClassname;

                hasRequiredAmount = true;
                ingredientClassname = ingredient.GetLoweredClassname();

                if (mapRequiredCount.Contains(ingredientClassname)) {
                    if (mapRequiredCount.Get(ingredientClassname) > 0) {
                        hasRequiredAmount = false;
                        hasIngredients = false;
                    }
                }
                tempObject = GetGame().CreateObject(ingredientClassname, vector.Zero, true);

                if (tempObject) {
                    newGridIngredient = new BST_RecipeRequireGrid(gridRecipeIngredients, "(" + ingredient.GetRequiredAmount() + ") " + tempObject.GetDisplayName(), hasRequiredAmount);
                    GetGame().ObjectDelete(tempObject);
                } else {
                    newGridIngredient = new BST_RecipeRequireGrid(gridRecipeIngredients, "(" + ingredient.GetRequiredAmount() + ") " + ingredient.GetClassname() + " (BAD CLASSNAME, NOTIFY AN ADMIN!!!)", false);
                }
                arrayGridIngredients.Insert(newGridIngredient);
            }
        }
        // Build bench requirement grid
        if (requiredBench == string.Empty) {
            newGridIngredient = new BST_RecipeRequireGrid(gridRecipeToolRequirements, "Your Hands", true);

            arrayGridIngredients.Insert(newGridIngredient);
        } else {
            BST_CraftingConfigBench configBenchRequired = GetBSTCraftingManager().GetBenchConfig().GetBenchByType(requiredBench);
            requiresBench = true;
            hasRequiredBench = false;

            if (configBenchRequired) {
                if (!benchBase || configBenchRequired != GetBSTCraftingManager().GetBenchConfig().GetBenchByItemType(benchBase.GetType())) {
                    newGridIngredient = new BST_RecipeRequireGrid(gridRecipeToolRequirements, requiredBench, false);
                } else {
                    hasRequiredBench = true;
                    newGridIngredient = new BST_RecipeRequireGrid(gridRecipeToolRequirements, requiredBench, true);
                }
            } else {
                newGridIngredient = new BST_RecipeRequireGrid(gridRecipeToolRequirements, "Invalid Bench Type! Contact a server admin!", false);
            }
            arrayGridIngredients.Insert(newGridIngredient);
        }
    }

    void SetBench(EntityAI benchBase) {
        this.benchBase = benchBase;
    }

    void GetItemsinVicinity() {
        array<EntityAI> vicinityEntities = GetBSTVicinityItemManager().RefreshVicinityItems(player);

        Print("Grabbed vicinity array=" + vicinityEntities.Count());
        
        foreach (EntityAI item : vicinityEntities) {
            if (item) {
                Print("[DEBUG] item=" + item);
            }
        }
    }

    void OnShow() {
        arrayRecipes = GetBSTCraftingManager().GetCraftingRecipes();
        player = PlayerBase.Cast(GetGame().GetPlayer());

        super.OnShow();
        GetGame().GetMission().PlayerControlDisable(INPUT_EXCLUDE_ALL);
        GetGame().GetUIManager().ShowCursor(true);
        GetGame().GetMission().GetHud().Show(false);
        BuildMenu();
        SetFocus(null);
        //GetItemsinVicinity();
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
            if (hasIngredients) {
                if ((requiresBench && hasRequiredBench) || !requiresBench) {
                    Print("[DEBUG] Can craft, starting timer");
                    craftingRecipe = activeRecipe;
                    isCrafting = true;
                }
            }
        }
        return super.OnClick(w, x, y, button);
    }
    
	override bool OnMouseLeave(Widget w, Widget enterW, int x, int y) {
        if (w == edtSearch) {
            SetFocus(null);
        }
        return super.OnMouseLeave(w, enterW, x, y);
    }

    override bool OnChange(Widget w, int x, int y, bool finished) {
        super.OnChange(w, x, y, finished);

        if (w == edtSearch) {
            CleanupRecipes();

            if (edtSearch.GetText() != previousEntry && edtSearch.GetText() != string.Empty && edtSearch.GetText() != CONST_STRING_SEARCH) {
                previousEntry = edtSearch.GetText();

                BuildMenu(previousEntry);
            } else {
                BuildMenu();
            }
        }
        return true;
    }

    override bool OnMouseButtonUp(Widget w, int x, int y, int button) {
        if (TextWidget.Cast(w)) {
            BST_RecipeTextWidget txtWidget = FindWidgetInGrid(w);

            if (txtWidget) {
                if (txtWidget != activeRecipe) {
                    if (activeRecipe) {
                        activeRecipe.Deselect();
                    }
                    if (entityRecipeProduct) {
                        GetGame().ObjectDelete(entityRecipeProduct);
                    }
                    activeRecipe = txtWidget;
                    entityRecipeProduct = GetGame().CreateObject(activeRecipe.GetRecipe().GetProduct(), "0 0 0", true);

                    if (entityRecipeProduct) {
                        prvRecipeProduct.SetItem(entityRecipeProduct);
                    }
                    txtRecipeTitle.SetText(activeRecipe.GetRecipe().GetName()); // Could make this the object's display name.
                    txtRecipeDesc.SetText(activeRecipe.GetRecipe().GetDescription());

                    int craftTime = activeRecipe.GetRecipe().GetCraftTime();
                    int craftMinutes = craftTime / 60;
                    int craftSeconds = craftTime;

                    if (craftMinutes > 0) {
                        craftSeconds -= craftMinutes * 60;

                        if (craftSeconds > 0) {
                            txtRecipeCraftTime.SetText("" + craftMinutes + " m, " + craftSeconds + "s");
                        } else {
                            txtRecipeCraftTime.SetText("" + craftMinutes + " m");
                        }
                    } else {
                        txtRecipeCraftTime.SetText("" + craftSeconds + "s");
                    }
                    txtWidget.Select();
                    recipeRoot.Show(true);
                    CleanupIngredients();
                    BuildRecipeWindow();
                } else {
                    activeRecipe.Deselect();

                    activeRecipe = null;

                    recipeRoot.Show(false);
                }
                SetFocus(null);
            }
        }
        return super.OnMouseButtonUp(w, x, y, button);
    }
}