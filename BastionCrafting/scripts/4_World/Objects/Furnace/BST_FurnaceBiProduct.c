class BST_FurnaceBiProduct {
    private string ProductClassname;
    private int SpawnCount;

    void BST_FurnaceBiProduct() {
        this.ProductClassname = "EXAMPLE CLASSNAME";
        this.SpawnCount = 1;
    }
    
    string GetLoweredType() {
        string loweredType = ProductClassname;

        loweredType.ToLower()
        return loweredType;
    }

    string GetType() { return ProductClassname; }
    int GetSpawnCount() { return SpawnCount; }
}