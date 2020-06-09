modded class PluginRecipesManager
{
	override void RegisterRecipies()
	{
		super.RegisterRecipies();
		RegisterRecipe(new BRP_CraftBarrelChair);
		RegisterRecipe(new BRP_CraftBarrelTable);
	}
}
