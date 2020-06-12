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
        BRP_CraftingBenchBase benchBase;
        BST_CraftingConfigBench configBenchRequired, configBenchFound;
        array<EntityAI> arrCargoItems;
        string requiredBench;

        switch (rpc_type) {
            case BST_CraftingRPC.SERVER_CRAFT_ITEM:
                {
                    Param2<string, EntityAI> dataCraftItem;

                    Print("[DEBUG] Reading data");
                    if (!ctx.Read(dataCraftItem)) { return; }
                    Print("[DEBUG] Data read " + dataCraftItem.param1);

                    BST_CraftingLoadedRecipe recipe = GetBSTServerCraftingManager().FindRecipeByFileName(dataCraftItem.param1);
                    benchBase = dataCraftItem.param2;
                    player = PlayerBase.Cast(target);

                    if (player && recipe) {
                        requiredBench = recipe.GetRequiredBench();

                        if (requiredBench != string.Empty && benchBase) {
                            configBenchRequired = GetBSTCraftingManager().GetBenchConfig().GetBenchByType(requiredBench);
                            Print("[DEBUG] Recipe requires bench, searching!!! " + configBenchRequired);

                            if (configBenchRequired && configBenchRequired == GetBSTCraftingManager().GetBenchConfig().GetBenchByItemType(benchBase.GetType())) {
                                Print("[DEBUG] Bench found!!! checking for ingredients ");
                                if (GetBSTServerCraftingManager().HasIngredientsOnPerson(player, recipe, arrCargoItems) || GetBSTServerCraftingManager().HasIngredientsInVicinityAndPerson(player, recipe, arrCargoItems)) {
                                    GetBSTServerCraftingManager().Craft(player, recipe, arrCargoItems);
                                }
                            }
                        } else {
                            if (GetBSTServerCraftingManager().HasIngredientsOnPerson(player, recipe, arrCargoItems)) {
                                GetBSTServerCraftingManager().Craft(player, recipe, arrCargoItems);
                            }
                        }
                    }
                    break;
                }
        }
    }
}