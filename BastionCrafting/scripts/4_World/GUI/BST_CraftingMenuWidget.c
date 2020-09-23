/*
    Class written by RoomService
*/

class BST_CraftingMenuWidget : BST_ScriptedWidget {
    static const int CONST_COLOR_RED = ARGB(255, 255, 0, 0);
    static const int CONST_COLOR_GREEN = ARGB(255, 0, 255, 0);
    static const int CONST_COLOR_WHITE = ARGB(255, 255, 255, 255);
    static const int CONST_COLOR_BST_ORANGE = ARGB(255, 255, 149, 0);
    static const int CONST_COLOR_GRAY = ARGB(255, 180, 180, 180);
    static const string CONST_STRING_SEARCH = "Search for blueprints";

    private ref Widget _rootRecipe, _pnlProgressBar;
    private ref GridSpacerWidget _gridRoot, _gridIngredients, _gridRequirements;
    private ref TextWidget _txtRecipeTitle, _txtRecipeDesc, _txtRecipeCraftTime;
    private ref ItemPreviewWidget _prvRecipeProduct;
    private ref EditBoxWidget _edtSearch;
    private ref ButtonWidget _btnCraft;
    private ref ScrollWidget _scrollRecipes;
    private ref BST_RecipeGridSpacer _activeGrid;
    private ref BST_GUIRecipe _activeRecipe, _recipe;
    private ref array<ref BST_RecipeGridSpacer> _arrGridSpacers;
    private ref array<ref BST_RecipeRequireGrid> _arrGridIngredients;
    private ref array<ref BST_CraftingLoadedRecipe> _arrRecipes;
    private ref map<Widget, ref BST_GUIObject> _mapGUIObjects;
    private PlayerBase _player;
    private EntityAI _entProduct;
    private BRP_CraftingBenchBase _benchBase;
    private bool _isCrafting, _requiresBench, _hasRequiredBench, _hasIngredients;
    private string _prevEntry;
    private float _craftTimePassed;

    void BST_CraftingMenuWidget() {
        _arrGridSpacers = new array<ref BST_RecipeGridSpacer>();
        _arrGridIngredients = new array<ref BST_RecipeRequireGrid>();
        _arrRecipes = new array<ref BST_CraftingLoadedRecipe>();
        _mapGUIObjects = new map<Widget, ref BST_GUIObject>();
        _btnText = "CRAFTING";

        GetGame().GetUpdateQueue(CALL_CATEGORY_GUI).Insert(this.Update);
    }

    override void Init(Widget parent) {
        _parent = parent;
        _root = GetGame().GetWorkspace().CreateWidgets("BastionMod\\BastionCrafting\\gui\\layout\\CraftingMenu.layout", parent);
        _pnlProgressBar = _root.FindAnyWidget("pnlProgress");
        _gridRoot = GridSpacerWidget.Cast(_root.FindAnyWidget("gridRecipesRoot"));
        _gridIngredients = GridSpacerWidget.Cast(_root.FindAnyWidget("gridRecipeRequire"));
        _gridRequirements = GridSpacerWidget.Cast(_root.FindAnyWidget("gridRecipeToolRequire"));
        _edtSearch = EditBoxWidget.Cast(_root.FindAnyWidget("edtSearch"));
        _prvRecipeProduct = ItemPreviewWidget.Cast(_root.FindAnyWidget("prvRecipeItem"));
        _rootRecipe = _root.FindAnyWidget("pnlSelectedRecipe");
        _scrollRecipes = ScrollWidget.Cast(_root.FindAnyWidget("scrollerRecipes"));
        _txtRecipeTitle = TextWidget.Cast(_root.FindAnyWidget("txtSelectedRecipeName"));
        _txtRecipeDesc = TextWidget.Cast(_root.FindAnyWidget("txtSelectedRecipeDesc"));
        _txtRecipeCraftTime = TextWidget.Cast(_root.FindAnyWidget("txtSelectedRecipeTimetoCraft"));
        _btnCraft = ButtonWidget.Cast(_root.FindAnyWidget("btnCraft"));

        _root.SetHandler(this);
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

            BST_GUIParentCategory newParent = new BST_GUIParentCategory(_activeGrid.GetGrid(), parentCategory);

            _mapGUIObjects.Insert(newParent.GetWrapper()/*.GetCaret()*/, newParent);
            mapParentCategories.Insert(parentCategory.GetId(), newParent);
            _activeGrid.AddChild(newParent);
        }
        CheckCurrentGridSpacer();

        BST_GUIParentCategory uncategorizedParent = new BST_GUIParentCategory (_activeGrid.GetGrid(), null);

        _mapGUIObjects.Insert(uncategorizedParent.GetWrapper()/*GetCaret()*/, uncategorizedParent);
        _activeGrid.AddChild(uncategorizedParent);

        foreach (BST_CraftingSubCategory subCategory : arrSubCategories) {
            if (!subCategory) { continue; }
            if (mapParentCategories.Contains(subCategory.GetParentId())) {
                BST_GUIParentCategory parent = mapParentCategories.Get(subCategory.GetParentId());
                BST_GUISubCategory newSub = parent.AddSubCategory(subCategory);
                
                _mapGUIObjects.Insert(newSub.GetWrapper()/*GetCaret()*/, newSub);
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
        _scrollRecipes.VScrollToPos01(0);
    }

    void BuildRecipeWindow() {
        BST_RecipeRequireGrid newGridIngredient;
        map<string, int> mapRequiredCount;
        array<ref BST_CraftingIngredient> arrayCraftingIngredients = _activeRecipe.GetRecipe().GetIngredients();
        array<EntityAI> arrayVicinityContainers = GetBSTVicinityItemManager().RefreshVicinityItems(_player);

        if (_benchBase && arrayVicinityContainers.Count() > 0) {
            mapRequiredCount = GetBSTClientCraftingManager().GetIngredientAmountInVicinityandPlayer(_activeRecipe.GetRecipe(), arrayVicinityContainers);
        } else {
            mapRequiredCount = GetBSTClientCraftingManager().GetIngredientAmountOnPlayer(_activeRecipe.GetRecipe());
        }
        string requiredBench = _activeRecipe.GetRecipe().GetRequiredBench();

        _requiresBench = false;
        _hasIngredients = true;

        // Build ingredient grid
        if (mapRequiredCount == null) {
            newGridIngredient = new BST_RecipeRequireGrid(_gridIngredients, "ERROR OCCURRED WHEN TRYING TO GRAB CLIENT. REFRESH", false);
            _arrGridIngredients.Insert(newGridIngredient);
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
                        _hasIngredients = false;
                    }
                }
                tempObject = EntityAI.Cast(GetGame().CreateObject(ingredientClassname, vector.Zero, true));

                if (tempObject) {
                    string minDestroyPath = CFG_VEHICLESPATH + " " + ingredientClassname + " varQuantityDestroyOnMin";

                    if (GetGame().ConfigIsExisting(minDestroyPath) && GetGame().ConfigGetInt(minDestroyPath) == 0) {
                        int itemMaxQuant = QuantityConversions.GetItemQuantity(InventoryItem.Cast(tempObject));

                        if (ingredient.GetRequiredAmount() == -1) {
                            newGridIngredient = new BST_RecipeRequireGrid(_gridIngredients, "(1) " + tempObject.GetDisplayName(), hasRequiredAmount);
                        } else {
                            newGridIngredient = new BST_RecipeRequireGrid(_gridIngredients, "(" + ingredient.GetRequiredAmount() + "/" + itemMaxQuant + ") " + tempObject.GetDisplayName(), hasRequiredAmount);
                        }
                    } else {
                        newGridIngredient = new BST_RecipeRequireGrid(_gridIngredients, "(" + ingredient.GetRequiredAmount() + ") " + tempObject.GetDisplayName(), hasRequiredAmount);
                    }
                    GetGame().ObjectDelete(tempObject);
                } else {
                    newGridIngredient = new BST_RecipeRequireGrid(_gridIngredients, "(" + ingredient.GetRequiredAmount() + ") " + ingredient.GetClassname() + " (BAD CLASSNAME, NOTIFY AN ADMIN!!!)", false);
                }
                _arrGridIngredients.Insert(newGridIngredient);
            }
        }
        // Build bench requirement grid
        if (requiredBench == string.Empty) {
            newGridIngredient = new BST_RecipeRequireGrid(_gridRequirements, "Your Hands", true);

            _arrGridIngredients.Insert(newGridIngredient);
        } else {
            BST_CraftingConfigBench configBenchRequired = GetBSTCraftingManager().GetBenchConfig().GetBenchByType(requiredBench);
            _requiresBench = true;
            _hasRequiredBench = false;

            if (configBenchRequired) {
                if (!_benchBase || configBenchRequired != GetBSTCraftingManager().GetBenchConfig().GetBenchByItemType(_benchBase.GetType())) {
                    newGridIngredient = new BST_RecipeRequireGrid(_gridRequirements, requiredBench, false);
                } else {
                    _hasRequiredBench = true;
                    newGridIngredient = new BST_RecipeRequireGrid(_gridRequirements, requiredBench, true);
                }
            } else {
                newGridIngredient = new BST_RecipeRequireGrid(_gridRequirements, "Invalid Bench Type! Contact a server admin!", false);
            }
            _arrGridIngredients.Insert(newGridIngredient);
        }
    }
    
    void CheckCurrentGridSpacer() {
        if (!_activeGrid || _activeGrid.GetChildCount() >= 100) {
            _activeGrid = new BST_RecipeGridSpacer(_gridRoot);

            _arrGridSpacers.Insert(_activeGrid);
        }
    }

    void Cleanup() {
        if (_activeGrid) {
            delete _activeGrid;
        }
        if (_benchBase) {
            _benchBase = null;
        }
        if (_mapGUIObjects) {
            delete _mapGUIObjects;
            _mapGUIObjects = new map<Widget, ref BST_GUIObject>();
        }
        _prevEntry = string.Empty;
        _isCrafting = false;
        _requiresBench = false;
        _hasRequiredBench = false;
        _hasIngredients = false;
        _craftTimePassed = 0.0;

        CleanupRecipes();
        CleanupIngredients();
    }

    void CleanupRecipes() {
        if (_arrGridSpacers) {
            foreach (BST_RecipeGridSpacer grid : _arrGridSpacers) {
                if (grid) {
                    delete grid;
                }
            }
            delete _arrGridSpacers;
            _arrGridSpacers = new array<ref BST_RecipeGridSpacer>();
        }
    }

    void CleanupIngredients() {
        if (!_arrGridIngredients) { return; }
        for (int i = (_arrGridIngredients.Count() - 1); i >= 0; i--) {
            BST_RecipeRequireGrid deleteGrid = _arrGridIngredients[i];

            if (deleteGrid) {
                delete deleteGrid;
            }
            _arrGridIngredients.Remove(i);
        }
    }

    void RefreshBuildWindow() {
        _pnlProgressBar.Show(false);
        CleanupIngredients();
        BuildRecipeWindow();
    }

    void SetBench(BRP_CraftingBenchBase _benchBase) {
        this._benchBase = _benchBase;
    }

    override bool IsTyping() {
        if (EditBoxWidget.Cast(GetFocus())) {
            return true;
        }
        return false;
    }

    void Update(float timeslice) {
        if (GetFocus() == _edtSearch) {
            if (_edtSearch.GetText() == CONST_STRING_SEARCH) {
                _edtSearch.SetText(string.Empty);
            }
        } else {
            if (_edtSearch.GetText() == string.Empty) {
                _edtSearch.SetText(CONST_STRING_SEARCH);
            }
        }
        if (_rootRecipe.IsVisible()) {
            if (_isCrafting || !_hasIngredients || (_requiresBench && !_hasRequiredBench)) {
                if (_btnCraft.GetColor() != CONST_COLOR_GRAY) {
                    _btnCraft.SetColor(CONST_COLOR_GRAY);
                }
            } else {
                if (_btnCraft.GetColor() != CONST_COLOR_BST_ORANGE) {
                    _btnCraft.SetColor(CONST_COLOR_BST_ORANGE);
                }
            }
        }
        if (_recipe && _isCrafting) {
            if (_recipe == _activeRecipe) {
                int craftTime = _activeRecipe.GetRecipe().GetCraftTime();
                _craftTimePassed += timeslice;

                _pnlProgressBar.SetSize((_craftTimePassed / craftTime), 1);

                if (!_pnlProgressBar.IsVisible()) {
                    _pnlProgressBar.Show(true);
                }
                if (_craftTimePassed >= craftTime) {
                    _isCrafting = false;
                    _hasIngredients = false;
                    _craftTimePassed = 0.0;
                    
                    GetGame().RPCSingleParam(_player, BST_CraftingRPC.SERVER_CRAFT_ITEM, new Param2<string, EntityAI>(_activeRecipe.GetRecipe().GetFileName(), _benchBase), true);
                    GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(this.RefreshBuildWindow, 2000);
                }
            } else {
                _craftTimePassed = 0.0;
                _isCrafting = false;

                _pnlProgressBar.Show(false);
            }
        }
    }

    override bool OnClick(Widget w, int x, int y, int button) {
        if (w == _btnCraft) {
            if (_hasIngredients) {
                if ((_requiresBench && _hasRequiredBench) || !_requiresBench) {
                    _recipe = _activeRecipe;
                    _isCrafting = true;
                }
            }
        }
        return super.OnClick(w, x, y, button);
    }
    
	override bool OnMouseLeave(Widget w, Widget enterW, int x, int y) {
        if (w == _edtSearch) {
            SetFocus(null);
        }
        return super.OnMouseLeave(w, enterW, x, y);
    }

    override bool OnChange(Widget w, int x, int y, bool finished) {
        super.OnChange(w, x, y, finished);

        if (w == _edtSearch) {
            CleanupRecipes();

            if (_edtSearch.GetText() != _prevEntry && _edtSearch.GetText() != string.Empty && _edtSearch.GetText() != CONST_STRING_SEARCH) {
                _prevEntry = _edtSearch.GetText();

                BuildMenu(_prevEntry);
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

                if (recipe != _activeRecipe) {
                    if (_activeRecipe) {
                        _activeRecipe.Deselect();
                    }
                    if (_entProduct) {
                        GetGame().ObjectDelete(_entProduct);
                    }
                    _activeRecipe = recipe;
                    _entProduct = EntityAI.Cast(GetGame().CreateObject(_activeRecipe.GetRecipe().GetProducts()[0].GetClassname(), "0 0 0", true));

                    if (_entProduct) {
                        _prvRecipeProduct.SetItem(_entProduct);
                    }
                    _txtRecipeTitle.SetText(_activeRecipe.GetRecipe().GetName()); // Could make this the object's display name.
                    _txtRecipeDesc.SetText(_activeRecipe.GetRecipe().GetDescription());

                    int craftTime = _activeRecipe.GetRecipe().GetCraftTime();
                    int craftMinutes = craftTime / 60;
                    int craftSeconds = craftTime;

                    if (craftMinutes > 0) {
                        craftSeconds -= craftMinutes * 60;

                        if (craftSeconds > 0) {
                            _txtRecipeCraftTime.SetText("" + craftMinutes + "m, " + craftSeconds + "s");
                        } else {
                            _txtRecipeCraftTime.SetText("" + craftMinutes + "m");
                        }
                    } else {
                        if (craftSeconds == 0) {
                            _txtRecipeCraftTime.SetText("Instant");
                        } else {
                            _txtRecipeCraftTime.SetText("" + craftSeconds + "s");
                        }
                    }
                    recipe.Select();
                    _rootRecipe.Show(true);
                    CleanupIngredients();
                    BuildRecipeWindow();
                } else {
                    _activeRecipe.Deselect();

                    _activeRecipe = null;

                    _rootRecipe.Show(false);
                }
                SetFocus(null);
            }
        }
        return super.OnMouseButtonUp(w, x, y, button);
    }

    override void OnShow() {
        _arrRecipes = GetBSTCraftingManager().GetCraftingRecipes();
        _player = PlayerBase.Cast(GetGame().GetPlayer());

        super.OnShow();
        BuildMenu();
        SetFocus(null);
    }

    override void OnHide() {
        super.OnHide();
        Cleanup();
    }

    void ~BST_CraftingMenuWidget() {
        Cleanup();
    }
}