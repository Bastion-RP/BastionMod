class BST_CraftingConfig {
    private const float CONST_DEFAULT_DISTANCE = 3.0;

    private float VicinityDistance;
    private bool AllowVicinitySearch;

    void BST_CraftingConfig() {
        this.VicinityDistance = CONST_DEFAULT_DISTANCE;
        this.AllowVicinitySearch = true;
    }

    void Validate() {
        if (VicinityDistance <= 0.0) {
            this.VicinityDistance = CONST_DEFAULT_DISTANCE;
        }
    }

    float GetVicinityDistance() { return VicinityDistance; }
    bool CanSearchVicinity() { return AllowVicinitySearch; }
}