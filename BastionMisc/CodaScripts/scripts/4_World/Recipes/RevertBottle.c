class RevertBottle extends RecipeBase
{
	override void Init()
	{
		m_Name = "Clean Out Water Bottle";
		m_IsInstaRecipe = false;//should this recipe be performed instantly without animation
		m_AnimationLength = 1;//animation length in relative time units
		m_Specialty = 0.01;// value > 0 for roughness, value < 0 for precision
		
		
		//conditions
		m_MinDamageIngredient[0] = -1;//-1 = disable check
		m_MaxDamageIngredient[0] = -1;//-1 = disable check
		
		m_MinQuantityIngredient[0] = -1;//-1 = disable check
		m_MaxQuantityIngredient[0] = -1;//-1 = disable check
		
		m_MinDamageIngredient[1] = -1;//-1 = disable check
		m_MaxDamageIngredient[1] = -1;//-1 = disable check
		
		m_MinQuantityIngredient[1] = -1;//-1 = disable check
		m_MaxQuantityIngredient[1] = -1;//-1 = disable check
		//----------------------------------------------------------------------------------------------------------------------
		
		//INGREDIENTS
		InsertIngredient(0,"coda_waterbottle_apple");//you can insert multiple ingredients this way
		InsertIngredient(0,"coda_waterbottle_banana");
		InsertIngredient(0,"coda_waterbottle_elderberry");
		InsertIngredient(0,"coda_waterbottle_kiwi");
		InsertIngredient(0,"coda_waterbottle_orange");
		InsertIngredient(0,"coda_waterbottle_pear");
		InsertIngredient(0,"coda_waterbottle_plum");
		InsertIngredient(0,"coda_waterbottle_rosehip");
		InsertIngredient(0,"coda_waterbottle_sweetapple");
		InsertIngredient(0,"coda_waterbottle_sweetbanana");
		InsertIngredient(0,"coda_waterbottle_sweetelderberry");
		InsertIngredient(0,"coda_waterbottle_sweetkiwi");
		InsertIngredient(0,"coda_waterbottle_sweetorange");
		InsertIngredient(0,"coda_waterbottle_sweetpear");
		InsertIngredient(0,"coda_waterbottle_sweetplum");
		InsertIngredient(0,"coda_waterbottle_sweetrosehip");
		InsertIngredient(0,"coda_waterbottle_applecider");
		InsertIngredient(0,"coda_waterbottle_bananacider");
		InsertIngredient(0,"coda_waterbottle_elderberrycider");
		InsertIngredient(0,"coda_waterbottle_kiwicider");
		InsertIngredient(0,"coda_waterbottle_orangecider");
		InsertIngredient(0,"coda_waterbottle_pearcider");
		InsertIngredient(0,"coda_waterbottle_plumcider");
		InsertIngredient(0,"coda_waterbottle_rosehipcider");
		//ExtraFarmingItems Integration
		InsertIngredient(0,"coda_waterbottle_pineapple")
		InsertIngredient(0,"coda_waterbottle_sweetpineapple")
		InsertIngredient(0,"coda_waterbottle_pineapplecider")
		InsertIngredient(0,"coda_waterbottle_mango")
		InsertIngredient(0,"coda_waterbottle_sweetmango")
		InsertIngredient(0,"coda_waterbottle_mangocider")
		InsertIngredient(0,"coda_waterbottle_melon")
		InsertIngredient(0,"coda_waterbottle_sweetmelon")
		InsertIngredient(0,"coda_waterbottle_meloncider")

		m_IngredientAddHealth[0] = 0;// 0 = do nothing
		m_IngredientSetHealth[0] = -1; // -1 = do nothing
		m_IngredientAddQuantity[0] = 0;// 0 = do nothing
		m_IngredientDestroy[0] = true;//true = destroy, false = do nothing
		m_IngredientUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this ingredient
		
		//ingredient 2
		InsertIngredient(1,"Rag");//you can insert multiple ingredients this way
		
		m_IngredientAddHealth[1] = 0;// 0 = do nothing
		m_IngredientSetHealth[1] = -1; // -1 = do nothing
		m_IngredientAddQuantity[1] = 0;// 0 = do nothing
		m_IngredientDestroy[1] = false;// false = do nothing
		m_IngredientUseSoftSkills[1] = false;// set 'true' to allow modification of the values by softskills on this ingredient
		//----------------------------------------------------------------------------------------------------------------------
		
		//result1
		AddResult("WaterBottle");//add results here

		m_ResultSetFullQuantity[0] = false;//true = set full quantity, false = do nothing
		m_ResultSetQuantity[0] = 0;//-1 = do nothing
		m_ResultSetHealth[0] = -1;//-1 = do nothing
		m_ResultInheritsHealth[0] = 0;// (value) == -1 means do nothing; a (value) >= 0 means this result will inherit health from ingredient number (value);(value) == -2 means this result will inherit health from all ingredients averaged(result_health = combined_health_of_ingredients / number_of_ingredients)
		m_ResultInheritsColor[0] = -1;// (value) == -1 means do nothing; a (value) >= 0 means this result classname will be a composite of the name provided in AddResult method and config value "color" of ingredient (value)
		m_ResultToInventory[0] = -2;//(value) == -2 spawn result on the ground;(value) == -1 place anywhere in the players inventory, (value) >= 0 means switch position with ingredient number(value)
		m_ResultUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this result
		m_ResultReplacesIngredient[0] = -1;// value == -1 means do nothing; a value >= 0 means this result will transfer item propertiesvariables, attachments etc.. from an ingredient value
		
		//----------------------------------------------------------------------------------------------------------------------
	}

	override bool CanDo(ItemBase ingredients[], PlayerBase player)//final check for recipe's validity
	{
		return true;
	}

	override void Do(ItemBase ingredients[], PlayerBase player,array<ItemBase> results, float specialty_weight)//gets called upon recipe's completion
	{
		Debug.Log("Recipe Do method called","recipes");
	}
};