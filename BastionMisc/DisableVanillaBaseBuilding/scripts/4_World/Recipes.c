modded class PluginRecipesManager 
{

 	override void RegisterRecipies()
	{
		super.RegisterRecipies();		
		UnregisterRecipe("CraftFenceKit");
		UnregisterRecipe("CraftWatchtowerKit");
		UnregisterRecipe("CraftTerritoryFlagKit");
	}			
};