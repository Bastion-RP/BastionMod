modded class PlayerBase {
    override void SetActions() {
        super.SetActions();

        AddAction(ActionBRPSitOnChair);
    }

    override void OnConnect() {
        super.OnConnect();

        if (GetIdentity()) {
            GetGame().RPCSingleParam(this, BST_CraftingRPC.CLIENT_RECEIVE_CONFIG, new Param3<ref BST_CraftingConfig, ref BST_CraftingBenchConfig, ref BST_CraftingCategoryConfig>(GetBSTCraftingManager().GetConfig(), GetBSTCraftingManager().GetBenchConfig(), GetBSTCraftingManager().GetCategoryConfig()), true, GetIdentity());
            GetGame().RPCSingleParam(this, BST_CraftingRPC.CLIENT_RECEIVE_RECIPES, new Param1<ref array<ref BST_CraftingLoadedRecipe>>(GetBSTCraftingManager().GetCraftingRecipes()), true, GetIdentity());
        }
    }
}