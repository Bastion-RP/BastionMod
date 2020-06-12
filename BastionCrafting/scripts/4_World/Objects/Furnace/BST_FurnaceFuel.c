class BST_FurnaceFuel {
    private ref array<ref BST_FurnaceBiProduct> BiProducts;
    private string fuelType;
    private float fuelMultiplier;
    private int fuelConsumptionRate;

    void BST_FurnaceFuel() {
        this.BiProducts = new array<ref BST_FurnaceBiProduct>();
        this.fuelType = "EXAMPLE CLASSNAME";
        this.fuelMultiplier = 1.0;
        this.fuelConsumptionRate = 1;

        BiProducts.Insert(new BST_FurnaceBiProduct());
    }

    void Validate() {
        if (fuelMultiplier <= 0.0) {
            fuelMultiplier = 1.0;
        }
        if (fuelConsumptionRate == 0) {
            fuelConsumptionRate = 1;
        }
    }

    string GetLoweredType() {
        string loweredType = fuelType;

        loweredType.ToLower();
        return loweredType;
    }

    array<ref BST_FurnaceBiProduct> GetBiProducts() { return BiProducts; }
    string GetType() { return fuelType; }
    float GetMultiplier() { return fuelMultiplier; }
    int GetConsumptionRate() { return fuelConsumptionRate; }
}