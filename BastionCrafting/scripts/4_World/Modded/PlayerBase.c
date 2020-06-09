modded class PlayerBase {
    override void OnConnect() {
        super.OnConnect();

        if (GetIdentity()) {
            Print("[DEBUG] Sending recipes to client " + GetBSTCraftingManager().GetBenchConfig());
            GetGame().RPCSingleParam(this, BST_CraftingRPC.CLIENT_RECEIVE_CONFIG, new Param2<ref BST_CraftingConfig, ref BST_CraftingBenchConfig>(GetBSTCraftingManager().GetConfig(), GetBSTCraftingManager().GetBenchConfig()), true, GetIdentity());
            GetGame().RPCSingleParam(this, BST_CraftingRPC.CLIENT_RECEIVE_RECIPES, new Param1<ref array<ref BST_CraftingLoadedRecipe>>(GetBSTCraftingManager().GetCraftingRecipes()), true, GetIdentity());
        }
    }
}