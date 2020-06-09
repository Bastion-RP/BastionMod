class BRP_CraftBarrelChair extends RecipeBase
{	
	override void Init()
	{
		m_Name = "Craft Barrel Chair";
		m_IsInstaRecipe = false;//should this recipe be performed instantly without animation
		m_AnimationLength = 1;//animation length in relative time units
		m_Specialty = 0.01;// value > 0 for roughness, value < 0 for precision

		//conditions
		m_MinDamageIngredient[0] = -1;
		m_MaxDamageIngredient[0] = 3;
		m_MinQuantityIngredient[0] = -1;
		m_MaxQuantityIngredient[0] = -1;
		
		m_MinDamageIngredient[1] = -1;
		m_MaxDamageIngredient[1] = 3;
		m_MinQuantityIngredient[1] = -1;
		m_MaxQuantityIngredient[1] = -1;
		
		
		//ingredient 1
		InsertIngredient(0,"Barrel_ColorBase");//you can insert multiple ingredients this way

		m_IngredientAddHealth[0] = 0;
		m_IngredientAddQuantity[0] = 0;
		m_IngredientSetHealth[0] = -1; // -1 = do nothing
		m_IngredientDestroy[0] = 1;
		m_IngredientUseSoftSkills[1] = false;// set 'true' to allow modification of the values by softskills on this ingredient
		
		//ingredient 2
		InsertIngredient(1,"Hacksaw");
		//InsertIngredient(1,"Screwdriver");
		//InsertIngredient(1,"Crowbar");
		
		m_IngredientAddHealth[1] = -10;
		m_IngredientSetHealth[1] = -1; // -1 = do nothing
		m_IngredientAddQuantity[1] = 0;
		m_IngredientDestroy[1] = 0;
		m_IngredientUseSoftSkills[1] = true;// set 'true' to allow modification of the values by softskills on this ingredient
		
		// crafting multiple results
		//AddResult("BarrelHoles_");//additional results, must be processed individually in Do method (as "results" parameter)
		
		m_ResultSetFullQuantity[0] = 0;
		m_ResultSetQuantity[0] = -1;
		m_ResultSetHealth[0] = -1;
		m_ResultInheritsHealth[0] = 0;// (value) == -1 means do nothing; a (value) >= 0 means this result will inherit health from ingredient number (value);(value) == -2 means this result will inherit health from all ingredients averaged(result_health = combined_health_of_ingredients / number_of_ingredients)
		m_ResultInheritsColor[0] = 0;// (value) == -1 means do nothing; a (value) >= 0 means this result classname will be a composite of the name provided in AddResult method and config value "color" of ingredient (value)
		m_ResultToInventory[0] = 0;
		m_ResultUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this result
		m_ResultReplacesIngredient[0] = 0;// value == -1 means do nothing; a value >= 0 means this result will transfer item propertiesvariables, attachments etc.. from an ingredient value
	}

	override bool CanDo(ItemBase ingredients[], PlayerBase player)
	{
		//HACK: until server-> client syncing of "LocalDropEntity" gets sortet out
		ItemBase parent = ingredients[0];
		if (parent.IsEmpty())
			return true;
		return false;
		//return true;
	}

	override void Do(ItemBase ingredients[], PlayerBase player,array<ItemBase> results, float specialty_weight)
	{
		ItemBase item = ingredients[0];
		string class_name = item.GetType();
		string color = item.ConfigGetString("color");
		string new_class_name = "BRP_Barrel_Chair_" + color;
		
		MiscGameplayFunctions.TurnItemIntoItem(ingredients[0],new_class_name,player);
	}
	
	void TransferItemsToNew(PlayerBase player, ItemBase barrel_old, ItemBase barrel_new)
	{
		//TODO bugfix, only drops items now
		MiscGameplayFunctions.TransferInventory(barrel_old,barrel_new,player);
		//player.m_UpdateInventoryForced = true;
		//player.SetSynchDirty();
	}
};
