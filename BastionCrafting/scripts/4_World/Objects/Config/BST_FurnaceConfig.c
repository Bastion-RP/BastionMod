class BST_FurnaceConfig {
    protected int TickRate;

    void BST_FurnaceConfig() {
        this.TickRate = 5;
    }

    void Validate() {
        if (TickRate <= 0) {
            TickRate = 5;
        }
    }
    
    int GetTickRate() { return TickRate; }
}