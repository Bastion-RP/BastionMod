modded class PlayerBase {
    override void OnConnect() {
        super.OnConnect();

        if (GetIdentity()) {
            Print("[DEBUG] Sending recipes to client " + GetServerCraftingManager().GetBenchConfig());
            GetGame().RPCSingleParam(this, BST_CraftingRPC.CLIENT_RECEIVE_CONFIG, new Param1<ref BST_CraftingBenchConfig>(GetServerCraftingManager().GetBenchConfig()), true, GetIdentity());
            GetGame().RPCSingleParam(this, BST_CraftingRPC.CLIENT_RECEIVE_RECIPES, new Param1<ref array<ref BST_CraftingLoadedRecipe>>(GetServerCraftingManager().GetCraftingRecipes()), true, GetIdentity());
        }
    }
}