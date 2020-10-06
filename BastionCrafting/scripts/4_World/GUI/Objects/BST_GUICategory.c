class BST_GUICategory : BST_GUIObject {
    protected ref GridSpacerWidget _root;
    protected ref TextWidget _txtName, _txtCaret, _txtWrap;
    protected ref BST_RecipeGridSpacer _activeGrid;
    protected ref array<ref BST_RecipeGridSpacer> _arrGrids;
    protected bool _isCollapsed;

    void BST_GUICategory() {
        this._arrGrids = new array<ref BST_RecipeGridSpacer>();
        this._isCollapsed = true;
    }
    
    void ~BST_GUICategory() {
        if (_txtName) {
            _txtName.Unlink();
        }
        if (_txtCaret) {
            _txtCaret.Unlink();
        }
        if (_root) {
            _root.Unlink();
            delete _root;
        }
    }
    
    void CheckCurrentGridSpacer() {
        if (!_activeGrid || _activeGrid.GetChildCount() >= 100) {
            _activeGrid = new BST_RecipeGridSpacer(_root);

            _activeGrid.GetGrid().Show(false);
            _arrGrids.Insert(_activeGrid);
        }
    }

    void ShowChildren() {
        if (!_isCollapsed) { return; }
        foreach (BST_RecipeGridSpacer grid : _arrGrids) {
            if (grid && grid.GetGrid()) {
                grid.GetGrid().Show(true);
            }
        }
        _txtCaret.SetText("^");
        _txtCaret.SetColor(BST_CraftingMenuWidget.CONST_COLOR_BST_ORANGE);
        _txtName.SetColor(BST_CraftingMenuWidget.CONST_COLOR_BST_ORANGE);
        _isCollapsed = false;
    }

    void HideChildren() {
        if (_isCollapsed) { return; }
        foreach (BST_RecipeGridSpacer grid : _arrGrids) {
            if (grid && grid.GetGrid()) {
                grid.GetGrid().Show(false);
            }
        }
        _txtCaret.SetText("v");
        _txtCaret.SetColor(BST_CraftingMenuWidget.CONST_COLOR_WHITE);
        _txtName.SetColor(BST_CraftingMenuWidget.CONST_COLOR_WHITE);
        _isCollapsed = true;
    }

    BST_GUIRecipe AddRecipeWidget(BST_CraftingLoadedRecipe recipe, int type, bool isSearching) {
        CheckCurrentGridSpacer();

        BST_GUIRecipe newRecipe = new BST_GUIRecipe(_activeGrid.GetGrid(), recipe, type);
        _activeGrid.AddChild(newRecipe);

        if (isSearching) {
            ShowChildren();
        }
        return newRecipe;
    }
    
    Widget GetWrapper() { return _txtWrap; }
    BST_RecipeGridSpacer GetActiveGrid() { return _activeGrid; }
    TextWidget GetCaret() { return _txtCaret; }
    bool IsCollapsed() { return _isCollapsed; }
}