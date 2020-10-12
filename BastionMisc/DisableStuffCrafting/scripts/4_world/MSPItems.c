modded class Msp_AppleCrate : Msp_Storage_Base 
{   
    override static Msp_ItemRecipeValues GetRecipeValues()
    {   
        Msp_ItemRecipeValues recipeVals = new Msp_ItemRecipeValues;
        recipeVals.Set_minQuantityIngredientTwo(99);
        recipeVals.Set_addHealthOne(-5);
        recipeVals.Set_addQuantTwo(-2);
        array<string> ingredientsOne =
        {"Hammer"};
        recipeVals.SetIngredientItemOne(ingredientsOne);
        array<string> ingredientsTwo =
        {"WoodenPlank"};
        recipeVals.SetIngredientItemTwo(ingredientsTwo);
        recipeVals.SetName("Craft Apple Crate");
        recipeVals.SetResult("Msp_AppleCrate");
        return recipeVals;
    } 
};
modded class Msp_AmericanAppleCrate : Msp_Storage_Base 
{   
    override static Msp_ItemRecipeValues GetRecipeValues()
    {   
        Msp_ItemRecipeValues recipeVals = new Msp_ItemRecipeValues;
        recipeVals.Set_minQuantityIngredientTwo(99);
        recipeVals.Set_addHealthOne(-5);
		recipeVals.Set_addQuantTwo(-2);
        array<string> ingredientsOne =
        {"Hammer"};
        recipeVals.SetIngredientItemOne(ingredientsOne);
        array<string> ingredientsTwo =
        {"WoodenPlank"};
        recipeVals.SetIngredientItemTwo(ingredientsTwo);
		recipeVals.SetName("Craft American Apple Crate");
		recipeVals.SetResult("Msp_AmericanAppleCrate");
        return recipeVals;
    } 
};
modded class Msp_EmptyPlanterBox : Msp_Storage_Base 
{   
    override static Msp_ItemRecipeValues GetRecipeValues()
    {   
        Msp_ItemRecipeValues recipeVals = new Msp_ItemRecipeValues;
        recipeVals.Set_minQuantityIngredientOne(99);
        recipeVals.Set_minQuantityIngredientTwo(99);
		recipeVals.Set_addQuantOne(-50);
		recipeVals.Set_addQuantTwo(-10);
        array<string> ingredientsOne =
        {"EpoxyPutty"};
        recipeVals.SetIngredientItemOne(ingredientsOne);
        array<string> ingredientsTwo =
        {"WoodenPlank"};
        recipeVals.SetIngredientItemTwo(ingredientsTwo);
		recipeVals.SetName("Craft Planter Box");
		recipeVals.SetResult("Msp_EmptyPlanterBox");
        return recipeVals;
    } 
};
modded class Msp_EmptySquarePlanterBox : Msp_Storage_Base 
{   
    override static Msp_ItemRecipeValues GetRecipeValues()
    {   
        Msp_ItemRecipeValues recipeVals = new Msp_ItemRecipeValues;
        recipeVals.Set_minQuantityIngredientOne(99);
        recipeVals.Set_minQuantityIngredientTwo(99);
		recipeVals.Set_addQuantOne(-25);
		recipeVals.Set_addQuantTwo(-5);
        array<string> ingredientsOne =
        {"EpoxyPutty"};
        recipeVals.SetIngredientItemOne(ingredientsOne);
        array<string> ingredientsTwo =
        {"WoodenPlank"};
        recipeVals.SetIngredientItemTwo(ingredientsTwo);
		recipeVals.SetName("Craft Square Planter Box");
		recipeVals.SetResult("Msp_EmptySquarePlanterBox");
        return recipeVals;
    } 
};
modded class Msp_WaterBarrel_Stand : Msp_Storage_Base 
{   
    override static Msp_ItemRecipeValues GetRecipeValues()
    {   
        Msp_ItemRecipeValues recipeVals = new Msp_ItemRecipeValues;
        recipeVals.Set_minQuantityIngredientTwo(99);
		recipeVals.Set_addHealthOne(-5);
		recipeVals.Set_addQuantTwo(-5);
        array<string> ingredientsOne =
        {"Hammer"};
        recipeVals.SetIngredientItemOne(ingredientsOne);
        array<string> ingredientsTwo =
        {"WoodenPlank"};
        recipeVals.SetIngredientItemTwo(ingredientsTwo);
		recipeVals.SetName("Craft Water Barrel Stand");
		recipeVals.SetResult("Msp_WaterBarrel_Stand");
        return recipeVals;
    } 
};
modded class Msp_WaterBarrel_Valve : ItemBase 
{   
    override static Msp_ItemRecipeValues GetRecipeValues()
    {   
        Msp_ItemRecipeValues recipeVals = new Msp_ItemRecipeValues;
        recipeVals.Set_minQuantityIngredientTwo(99);
        recipeVals.Set_addHealthOne(-5);
		recipeVals.Set_addQuantTwo(-1);
        array<string> ingredientsOne =
        {"KitchenKnife","SteakKnife",
        "StoneKnife","CombatKnife",
        "HuntingKnife","Machete",
        "AK_Bayonet","M9A1_Bayonet",
        "Mosin_Bayonet","SKS_Bayonet"};
        recipeVals.SetIngredientItemOne(ingredientsOne);
        array<string> ingredientsTwo =
        {"Firewood"};
        recipeVals.SetIngredientItemTwo(ingredientsTwo);
		recipeVals.SetName("Craft Water Barrel Valve");
		recipeVals.SetResult("Msp_WaterBarrel_Valve");
        return recipeVals;
    } 
};
modded class Msp_WaterBarrel_Stand_Darkwood : Msp_WaterBarrel_Stand 
{   
    override static Msp_ItemRecipeValues GetRecipeValues()
    {   
        Msp_ItemRecipeValues recipeVals = new Msp_ItemRecipeValues;
        recipeVals.Set_minQuantityIngredientTwo(99);
		recipeVals.Set_addHealthOne(-5);
		recipeVals.Set_addQuantTwo(-5);
        array<string> ingredientsOne =
        {"Hammer"};
        recipeVals.SetIngredientItemOne(ingredientsOne);
        array<string> ingredientsTwo =
        {"WoodenPlank"};
        recipeVals.SetIngredientItemTwo(ingredientsTwo);
		recipeVals.SetName("Craft Darkwood Water Barrel Stand");
		recipeVals.SetResult("Msp_WaterBarrel_Stand_Darkwood");
        return recipeVals;
    } 
};
modded class Msp_WaterBarrel_Valve_Darkwood : Msp_WaterBarrel_Valve 
{   
    override static Msp_ItemRecipeValues GetRecipeValues()
    {   
        Msp_ItemRecipeValues recipeVals = new Msp_ItemRecipeValues;
        recipeVals.Set_minQuantityIngredientTwo(99);
        recipeVals.Set_addHealthOne(-5);
		recipeVals.Set_addQuantTwo(-1);
        array<string> ingredientsOne =
        {"KitchenKnife","SteakKnife",
        "StoneKnife","CombatKnife",
        "HuntingKnife","Machete",
        "AK_Bayonet","M9A1_Bayonet",
        "Mosin_Bayonet","SKS_Bayonet"};
        recipeVals.SetIngredientItemOne(ingredientsOne);
        array<string> ingredientsTwo =
        {"Firewood"};
        recipeVals.SetIngredientItemTwo(ingredientsTwo);
		recipeVals.SetName("Craft Darkwood Water Barrel Valve");
		recipeVals.SetResult("Msp_WaterBarrel_Valve_Darkwood");
        return recipeVals;
    }
};
modded class Msp_FireplaceRailing : Msp_BuildingWithFireplace 
{   
    override static Msp_ItemRecipeValues GetRecipeValues()
    {
        Msp_ItemRecipeValues recipeVals = new Msp_ItemRecipeValues;
        recipeVals.Set_addHealthOne(-5);
        recipeVals.Set_minQuantityIngredientTwo(99);
		recipeVals.Set_addQuantTwo(-1);
        array<string> ingredientsOne =
        {"Pliers"};
        recipeVals.SetIngredientItemOne(ingredientsOne);
        array<string> ingredientsTwo =
        {"MetalPlate"};
        recipeVals.SetIngredientItemTwo(ingredientsTwo);
		recipeVals.SetName("Craft Fireplace Railing");
		recipeVals.SetResult("Msp_FireplaceRailing");
        return recipeVals;
    } 
};