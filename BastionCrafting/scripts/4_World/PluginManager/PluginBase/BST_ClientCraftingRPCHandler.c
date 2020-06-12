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

                    Print("[DEBUG] CLIENT_RECEIVE_RECIPES | Reading recipes");
                    if (!ctx.Read(dataRecipes)) { return; }
                    Print("[DEBUG] CLIENT_RECEIVE_RECIPES | Read recipes");

                    GetBSTCraftingManager().SetCraftingRecipes(dataRecipes.param1);
                    break;
                }
            case BST_CraftingRPC.CLIENT_RECEIVE_CONFIG:
                {
                    Param2<ref BST_CraftingConfig, ref BST_CraftingBenchConfig> dataConfig;

                    Print("[DEBUG] CLIENT_RECEIVE_CONFIG | Reading config");
                    if (!ctx.Read(dataConfig)) { return; }
                    Print("[DEBUG] CLIENT_RECEIVE_CONFIG | Read config");

                    GetBSTCraftingManager().SetConfig(dataConfig.param1);
                    GetBSTCraftingManager().SetBenchConfig(dataConfig.param2);
                    break;
                }
        }
    }
}