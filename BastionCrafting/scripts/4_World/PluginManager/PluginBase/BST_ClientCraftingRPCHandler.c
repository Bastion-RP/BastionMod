class BST_ClientCraftingRPCHandler : PluginBase {
    void BST_ClientCraftingRPCHandler() {
        GetDayZGame().Event_OnRPC.Insert(OnRPC);
    }

    void ~BST_ClientCraftingRPCHandler() {
        GetDayZGame().Event_OnRPC.Remove(OnRPC);
    }

    void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) {
        switch (rpc_type) {
            case BST_CraftingRPC.CLIENT_RECEIVE_RECIPES:
                {
                    Param1<ref array<ref BST_CraftingLoadedRecipe>> dataRecipes;

                    if (!ctx.Read(dataRecipes)) { return; }

                    GetBSTCraftingManager().SetCraftingRecipes(dataRecipes.param1);
                    break;
                }
            case BST_CraftingRPC.CLIENT_RECEIVE_CONFIG:
                {
                    Param3<ref BST_CraftingConfig, ref BST_CraftingBenchConfig, ref BST_CraftingCategoryConfig> dataConfig;

                    if (!ctx.Read(dataConfig)) { return; }

                    GetBSTCraftingManager().SetConfig(dataConfig.param1);
                    GetBSTCraftingManager().SetBenchConfig(dataConfig.param2);
                    GetBSTCraftingManager().SetCategoryConfig(dataConfig.param3);
                    break;
                }
        }
    }
}