class BST_FurnaceRecipe {
    private const string DEFAULT_CLASS_NAME = "EXAMPLE INGREDIENT";

    private ref array<ref BST_FurnaceBiProduct> BiProducts;
    private string IngredientClassname;
    private int SmeltRate;

    void BST_FurnaceRecipe() {
        this.BiProducts = new array<ref BST_FurnaceBiProduct>();
        this.IngredientClassname = DEFAULT_CLASS_NAME;
        this.SmeltRate = 5;

        BiProducts.Insert(new BST_FurnaceBiProduct());
    }

    bool Validate() {
        if (BiProducts.Count() == 0) {
            BiProducts.Insert(new BST_FurnaceBiProduct());
            return false;
        }
        if (IngredientClassname == DEFAULT_CLASS_NAME) {
            return false;
        }
        if (SmeltRate == 0) {
            SmeltRate = 5;
        }
        return true;
    }

    string GetLoweredType() {
        string loweredType = IngredientClassname;

        loweredType.ToLower();
        return loweredType;
    }

    array<ref BST_FurnaceBiProduct> GetBiProducts() { return BiProducts; }
    string GetType() { return IngredientClassname; }
    int GetSmeltRate() { return SmeltRate; }
}