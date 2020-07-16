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
    private ref BST_GUIRecipe activeRecipe, craftingRecipe;
    private ref array<ref BST_RecipeGridSpacer> arrayGridSpacers;
    private ref array<ref BST_RecipeRequireGrid> arrayGridIngredients;
    private ref map<Widget, ref BST_GUIObject> _mapGUIObjects;
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
        _mapGUIObjects = new map<Widget, ref BST_GUIObject>();

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
        if (_mapGUIObjects) {
            delete _mapGUIObjects;
            _mapGUIObjects = new map<Widget, ref BST_GUIObject>();
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
        array<ref BST_CraftingCategory> arrParentCategories = GetBSTCraftingManager().GetCategoryConfig().GetParentCategories();
        array<ref BST_CraftingSubCategory> arrSubCategories = GetBSTCraftingManager().GetCategoryConfig().GetSubCategories();
        array<ref BST_CraftingLoadedRecipe> arrRecipes = GetBSTCraftingManager().GetCraftingRecipes();
        map<int, ref BST_GUIParentCategory> mapParentCategories = new map<int, ref BST_GUIParentCategory>();
        map<int, ref BST_GUISubCategory> mapSubCategories = new map<int, ref BST_GUISubCategory>();

        // Create the parent categories. Insert the categories into a map and store them so I can grab them when creating
        // the sub categories;
        foreach (BST_CraftingCategory parentCategory : arrParentCategories) {
            if (!parentCategory) { continue; }
            CheckCurrentGridSpacer();

            BST_GUIParentCategory newParent = new BST_GUIParentCategory(activeGrid.GetGrid(), parentCategory);

            _mapGUIObjects.Insert(newParent.GetCaret(), newParent);
            mapParentCategories.Insert(parentCategory.GetId(), newParent);
            activeGrid.AddChild(newParent);
        }
        CheckCurrentGridSpacer();

        BST_GUIParentCategory uncategorizedParent = new BST_GUIParentCategory (activeGrid.GetGrid(), null);

        _mapGUIObjects.Insert(uncategorizedParent.GetCaret(), uncategorizedParent);
        activeGrid.AddChild(uncategorizedParent);

        foreach (BST_CraftingSubCategory subCategory : arrSubCategories) {
            if (!subCategory) { continue; }
            if (mapParentCategories.Contains(subCategory.GetParentId())) {
                BST_GUIParentCategory parent = mapParentCategories.Get(subCategory.GetParentId());
                BST_GUISubCategory newSub = parent.AddSubCategory(subCategory);
                
                _mapGUIObjects.Insert(newSub.GetCaret(), newSub);
                mapSubCategories.Insert(subCategory.GetId(), newSub);
            }
        }
        delete mapParentCategories;

        foreach (BST_CraftingLoadedRecipe recipe : arrRecipes) {
            if (!recipe) { continue; }
            bool isSearching = false;

            if (searchString != string.Empty) {
                searchString = searchString.Trim();
                searchString.ToLower();

                if (recipe.GetLoweredName().IndexOf(searchString) == -1) { continue; }
                isSearching = true;
            }
            BST_GUIRecipe newRecipe;

            if (mapSubCategories.Contains(recipe.GetCategoryId())) {
                BST_GUISubCategory sub = mapSubCategories.Get(recipe.GetCategoryId());
                newRecipe = sub.AddRecipeWidget(recipe, 2, isSearching);
            } else {
                newRecipe = uncategorizedParent.AddRecipeWidget(recipe, 1, isSearching);
            }
            _mapGUIObjects.Insert(newRecipe.GetText(), newRecipe);
        }
        scrollerRecipes.VScrollToPos01(0);
    }
    
    void CheckCurrentGridSpacer() {
        if (!activeGrid || activeGrid.GetChildCount() >= 100) {
            activeGrid = new BST_RecipeGridSpacer(gridRoot);

            arrayGridSpacers.Insert(activeGrid);
        }
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

        if (benchBase && arrayVicinityContainers.Count() > 0) {
            mapRequiredCount = GetBSTClientCraftingManager().GetIngredientAmountInVicinityandPlayer(activeRecipe.GetRecipe(), arrayVicinityContainers);
        } else {
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

    void OnShow() {
        arrayRecipes = GetBSTCraftingManager().GetCraftingRecipes();
        player = PlayerBase.Cast(GetGame().GetPlayer());

        super.OnShow();
        GetGame().GetMission().PlayerControlDisable(INPUT_EXCLUDE_ALL);
        GetGame().GetUIManager().ShowCursor(true);
        GetGame().GetMission().GetHud().Show(false);
        BuildMenu();
        SetFocus(null);
    }

    void OnHide() {
        super.OnHide();
        GetGame().GetUIManager().ShowCursor(false);
        GetGame().GetMission().PlayerControlEnable(true);
        GetGame().GetMission().GetHud().Show(true);
        Cleanup();
    }

    override bool OnClick(Widget w, int x, int y, int button) {
        if (w == btnCraft) {
            if (hasIngredients) {
                if ((requiresBench && hasRequiredBench) || !requiresBench) {
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
        if (_mapGUIObjects.Contains(w)) {
            BST_GUIObject guiObject = _mapGUIObjects.Get(w);

            if (BST_GUICategory.Cast(guiObject)) {
                BST_GUICategory category = BST_GUICategory.Cast(guiObject);
                
                if (category.IsCollapsed()) {
                    category.ShowChildren();
                } else {
                    category.HideChildren();
                }
            } else if (BST_GUIRecipe.Cast(guiObject)) {
                BST_GUIRecipe recipe = BST_GUIRecipe.Cast(guiObject);

                if (recipe != activeRecipe) {
                    if (activeRecipe) {
                        activeRecipe.Deselect();
                    }
                    if (entityRecipeProduct) {
                        GetGame().ObjectDelete(entityRecipeProduct);
                    }
                    activeRecipe = recipe;
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
                            txtRecipeCraftTime.SetText("" + craftMinutes + "m, " + craftSeconds + "s");
                        } else {
                            txtRecipeCraftTime.SetText("" + craftMinutes + "m");
                        }
                    } else {
                        if (craftSeconds == 0) {
                            txtRecipeCraftTime.SetText("Instant");
                        } else {
                            txtRecipeCraftTime.SetText("" + craftSeconds + "s");
                        }
                    }
                    recipe.Select();
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