class BST_ServerRPCHandler : PluginBase {
    void BST_ServerRPCHandler() {
        GetDayZGame().Event_OnRPC.Insert(OnRPC);
    }

    void ~BST_ServerRPCHandler() {
        GetDayZGame().Event_OnRPC.Remove(OnRPC);
    }

    void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) {
        if (!sender) { return; }

        PlayerBase player;
        ref array<EntityAI> arrayFoundItems;

        switch (rpc_type) {
            case BST_CraftingRPC.SERVER_CRAFT_ITEM:
                {
                    Param1<string> dataCraftItem;

                    Print("[DEBUG] Reading data");
                    if (!ctx.Read(dataCraftItem)) { return; }
                    Print("[DEBUG] Data read " + dataCraftItem.param1);

                    BST_CraftingLoadedRecipe foundRecipe = GetServerCraftingManager().FindRecipeByFileName(dataCraftItem.param1);
                    player = PlayerBase.Cast(target);

                    if (foundRecipe && GetServerCraftingManager().HasIngredients(foundRecipe, player, arrayFoundItems)) {
                        Print("[DEBUG] Player has enough items");
                        arrayFoundItems.Debug();
                        GetServerCraftingManager().Craft(foundRecipe, player, arrayFoundItems);
                    }
                    break;
                }
        }
    }
}