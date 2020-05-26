class BST_CraftingConfigBench {
    private string BenchType;
    private int BenchTier;
    private ref array<string> BenchClassnames;

    void BST_CraftingConfigBench() {
        BenchClassnames = new array<string>();
        BenchType = "EXAMPLE (Crafting Bench)";
        BenchTier = 1;

        BenchClassnames.Insert("EXAMPLE");
        BenchClassnames.Insert("BENCH CLASSNAMES GO HERE");
    }

    bool HasBench(string type) {
        foreach (string benchType : BenchClassnames) {
            if (benchType == type) {
                return true;
            }
        }
        return false;
    }

    string GetLoweredType() {
        string loweredType = BenchType;

        loweredType.ToLower();
        return loweredType;
    }

    array<string> GetBenchClassnames() { return BenchClassnames; }
    string GetType() { return BenchType; }
    int GetBenchTier() { return BenchTier; }
}