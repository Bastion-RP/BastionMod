class BST_CraftingBenchConfig {
    private ref array<ref BST_CraftingConfigBench> CraftingBenches;

    void BST_CraftingBenchConfig() {
        this.CraftingBenches = new array<ref BST_CraftingConfigBench>();

        CraftingBenches.Insert(new BST_CraftingConfigBench());
    }

    void Validate() {
        if (CraftingBenches.Count() == 0) {
            CraftingBenches.Insert(new BST_CraftingConfigBench());
        }
    }

    array<string> GetBenchClassnamesByType(string type) {
        BST_CraftingConfigBench bench = GetBenchByType(type);

        if (bench) {
            return bench.GetBenchClassnames();
        }
        return null;
    }

    BST_CraftingConfigBench GetBenchByType(string type) {
        foreach (BST_CraftingConfigBench bench : CraftingBenches) {
            if (bench && bench.GetLoweredType() == type) {
                return bench;
            }
        }
        return null;
    }

    BST_CraftingConfigBench GetBenchByItemType(string type) {
        foreach (BST_CraftingConfigBench bench : CraftingBenches) {
            if (bench && bench.HasBench(type)) {
                return bench;
            }
        }
        return null;
    }

    array<ref BST_CraftingConfigBench> GetCraftingBenches() { return CraftingBenches; }
}