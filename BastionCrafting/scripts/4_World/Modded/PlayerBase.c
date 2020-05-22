modded class PlayerBase {
    // Fuck it, storing it on the player base for rn

    ref array<ref BST_CraftingLoadedRecipe> arrayCraftingRecipes;

    void PlayerBase() {
        arrayCraftingRecipes = new array<ref BST_CraftingLoadedRecipe>();
    }

	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx) {
		super.OnRPC(sender, rpc_type, ctx);

        if (rpc_type == 9239122) {
            Param1<ref array<ref BST_CraftingLoadedRecipe>> dataRecipes;

            Print("[DEBUG] Reading recipes");
            if (!ctx.Read(dataRecipes)) { return; }
            Print("[DEBUG] Read recipes");

            arrayCraftingRecipes = dataRecipes.param1;

            arrayCraftingRecipes.Debug();
        }
    }

    override void OnConnect() {
        super.OnConnect();

        if (GetIdentity()) {
            Print("[DEBUG] Sending recipes to client");
            GetServerCraftingManager().GetCraftingRecipes().Debug();
            GetGame().RPCSingleParam(this, 9239122, new Param1<ref array<ref BST_CraftingLoadedRecipe>>(GetServerCraftingManager().GetCraftingRecipes()), true, GetIdentity());
        }
    }
}