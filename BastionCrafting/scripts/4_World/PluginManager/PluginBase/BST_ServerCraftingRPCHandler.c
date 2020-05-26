class BST_ServerCraftingRPCHandler : PluginBase {
    void BST_ServerCraftingRPCHandler() {
        GetDayZGame().Event_OnRPC.Insert(OnRPC);
    }

    void ~BST_ServerCraftingRPCHandler() {
        GetDayZGame().Event_OnRPC.Remove(OnRPC);
    }

    void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) {
        if (!sender) { return; }

        PlayerBase player;
        EntityAI benchBase;
        BST_CraftingConfigBench configBenchRequired, configBenchFound;
        ref array<EntityAI> arrayFoundItems;
        string requiredBench;

        switch (rpc_type) {
            case BST_CraftingRPC.SERVER_CRAFT_ITEM:
                {
                    Param2<string, EntityAI> dataCraftItem;

                    Print("[DEBUG] Reading data");
                    if (!ctx.Read(dataCraftItem)) { return; }
                    Print("[DEBUG] Data read " + dataCraftItem.param1);

                    BST_CraftingLoadedRecipe foundRecipe = GetServerCraftingManager().FindRecipeByFileName(dataCraftItem.param1);
                    benchBase = dataCraftItem.param2;
                    player = PlayerBase.Cast(target);

                    if (player && foundRecipe) {
                        requiredBench = foundRecipe.GetRequiredBench();

                        if (requiredBench != string.Empty) {
                            if (!benchBase) { return; }
                            configBenchRequired = GetServerCraftingManager().GetBenchConfig().GetBenchByType(requiredBench);
                            Print("[DEBUG] Recipe requires bench, searching!!! " + configBenchRequired);

                            if (configBenchRequired) {
                                configBenchFound = GetServerCraftingManager().GetBenchConfig().GetBenchByItemType(benchBase.GetType());
                                Print("[DEBUG] Searching for bench by item!!! " + configBenchFound);

                                if (configBenchFound && configBenchFound == configBenchRequired) {
                                    Print("[DEBUG] Bench found!!! checking for ingredients ");
                                    if (GetServerCraftingManager().HasIngredients(foundRecipe, player, arrayFoundItems)) {
                                        GetServerCraftingManager().Craft(foundRecipe, player, arrayFoundItems);
                                    }
                                }
                            }
                        } else {
                            GetServerCraftingManager().Craft(foundRecipe, player, arrayFoundItems);
                        }
                    }
                    break;
                }
        }
    }
}