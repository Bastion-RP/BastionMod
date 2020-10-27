modded class PluginRecipesManagerBase
{
    override void RegisterRecipies()
    {
        super.RegisterRecipies();
        //UnregisterRecipe("CraftPotatoSeeds");
        //RegisterRecipe(new CombineLeatherSewingKits);
        //UnregisterRecipe("CraftGunwallMung");
        //UnregisterRecipe("CraftGunwallMetalMung");
        RegisterRecipe(new RevertBottle);
        RegisterRecipe(new DrawDiazepam);
        //RegisterRecipe(new CraftTortilla);
        //RegisterRecipe(new CraftRaggedEyepatch);
        RegisterRecipe(new CraftSoap);
        //Leather Tanning
        RegisterRecipe(new CraftTanBearPelt);
        RegisterRecipe(new CraftTanCowPelt);
        RegisterRecipe(new CraftTanDeerPelt);
        RegisterRecipe(new CraftTanGoatPelt);
        RegisterRecipe(new CraftTanPigPelt);
        RegisterRecipe(new CraftTanSheepPelt);
        RegisterRecipe(new CraftTanMouflonPelt);
        RegisterRecipe(new CraftTanWildBoarPelt);
        RegisterRecipe(new CraftTanWolfPelt);
        //Leather Crafting
        RegisterRecipe(new CraftLeatherGloves);
        RegisterRecipe(new CraftLeatherHat);
        RegisterRecipe(new CraftLeatherJacket);
        RegisterRecipe(new CraftLeatherPants);
        RegisterRecipe(new CraftLeatherShoes);
        RegisterRecipe(new CraftLeatherVest);
        RegisterRecipe(new CraftLeatherWaterPouch);
        RegisterRecipe(new CraftLeatherSack);
        //Dye Leather
        RegisterRecipe(new DyeGreenGloves);
        RegisterRecipe(new DyeGreenHat);
        RegisterRecipe(new DyeGreenJacket);
        RegisterRecipe(new DyeGreenPants);
        RegisterRecipe(new DyeGreenSack);
        RegisterRecipe(new DyeGreenShoes);
        RegisterRecipe(new DyeGreenVest);
        RegisterRecipe(new DyeBlackGloves);
        RegisterRecipe(new DyeBlackHat);
        RegisterRecipe(new DyeBlackJacket);
        RegisterRecipe(new DyeBlackPants);
        RegisterRecipe(new DyeBlackSack);
        RegisterRecipe(new DyeBlackShoes);
        RegisterRecipe(new DyeBlackVest);
        RegisterRecipe(new DyeBrownGloves);
        RegisterRecipe(new DyeBrownHat);
        RegisterRecipe(new DyeBrownJacket);
        RegisterRecipe(new DyeBrownPants);
        RegisterRecipe(new DyeBrownSack);
        RegisterRecipe(new DyeBrownShoes);
        RegisterRecipe(new DyeBrownVest);
        RegisterRecipe(new DyeCreamGloves);
        RegisterRecipe(new DyeCreamHat);
        RegisterRecipe(new DyeCreamJacket);
        RegisterRecipe(new DyeCreamPants);
        RegisterRecipe(new DyeCreamSack);
        RegisterRecipe(new DyeCreamShoes);
        RegisterRecipe(new DyeCreamVest);
        //Bandanas
        RegisterRecipe(new craftarmygreenbandana);
        RegisterRecipe(new craftbabybluebandana);
        RegisterRecipe(new craftbabypinkbandana);
        RegisterRecipe(new craftbeigebandana);
        RegisterRecipe(new craftblackbandana);
        RegisterRecipe(new craftburgundybandana);
        RegisterRecipe(new craftcandypinkbandana);
        RegisterRecipe(new craftcreambandana);
        RegisterRecipe(new craftcyanbandana);
        RegisterRecipe(new craftdarkbrownbandana);
        RegisterRecipe(new craftdarkgreybandana);
        RegisterRecipe(new craftfuchsiabandana);
        RegisterRecipe(new craftlavenderbandana);
        RegisterRecipe(new craftlightbrownbandana);
        RegisterRecipe(new craftlightgreybandana);
        RegisterRecipe(new craftnavybluebandana);
        RegisterRecipe(new craftolivegreenbandana);
        RegisterRecipe(new craftorangebandana);
        RegisterRecipe(new craftplumbandana);
        RegisterRecipe(new craftpurplebandana);
        RegisterRecipe(new craftredbandana);
        RegisterRecipe(new craftroyalbluebandana);
        RegisterRecipe(new craftwhitebandana);
        RegisterRecipe(new craftyellowbandana);
        //Armbands
        RegisterRecipe(new craftarmygreenarmband);
        RegisterRecipe(new craftbabybluearmband);
        RegisterRecipe(new craftbabypinkarmband);
        RegisterRecipe(new craftbeigearmband);
        RegisterRecipe(new craftblackarmband);
        RegisterRecipe(new craftburgundyarmband);
        RegisterRecipe(new craftcandypinkarmband);
        RegisterRecipe(new craftcreamarmband);
        RegisterRecipe(new craftcyanarmband);
        RegisterRecipe(new craftdarkbrownarmband);
        RegisterRecipe(new craftdarkgreyarmband);
        RegisterRecipe(new craftfuchsiaarmband);
        RegisterRecipe(new craftlavenderarmband);
        RegisterRecipe(new craftlightbrownarmband);
        RegisterRecipe(new craftlightgreyarmband);
        RegisterRecipe(new craftnavybluearmband);
        RegisterRecipe(new craftolivegreenarmband);
        RegisterRecipe(new craftorangearmband);
        RegisterRecipe(new craftplumarmband);
        RegisterRecipe(new craftpurplearmband);
        RegisterRecipe(new craftredarmband);
        RegisterRecipe(new craftroyalbluearmband);
        RegisterRecipe(new craftwhitearmband);
        RegisterRecipe(new craftyellowarmband);
        //Fruit Juices
        RegisterRecipe(new CreateAppleFruitJuice);
        RegisterRecipe(new CreatePlumFruitJuice);
        RegisterRecipe(new CreatePearFruitJuice);
        RegisterRecipe(new CreateOrangeFruitJuice);
        RegisterRecipe(new CreateKiwiFruitJuice);
        RegisterRecipe(new CreateRoseHipFruitJuice);
        RegisterRecipe(new CreateBananaFruitJuice);
        RegisterRecipe(new CreateElderberryFruitJuice);
        //Sweet Fruit Juices
        RegisterRecipe(new CreateSweetAppleFruitJuice);
        RegisterRecipe(new CreateSweetPlumFruitJuice);
        RegisterRecipe(new CreateSweetPearFruitJuice);
        RegisterRecipe(new CreateSweetOrangeFruitJuice);
        RegisterRecipe(new CreateSweetKiwiFruitJuice);
        RegisterRecipe(new CreateSweetRoseHipFruitJuice);
        RegisterRecipe(new CreateSweetBananaFruitJuice);
        RegisterRecipe(new CreateSweetElderberryFruitJuice);
        //Fruit Cider
        RegisterRecipe(new CreateAppleCider);
        RegisterRecipe(new CreatePlumCider);
        RegisterRecipe(new CreatePearCider);
        RegisterRecipe(new CreateOrangeCider);
        RegisterRecipe(new CreateKiwiCider);
        RegisterRecipe(new CreateRoseHipCider);
        RegisterRecipe(new CreateBananaCider);
        RegisterRecipe(new CreateElderberryCider);
        //Spraypaint Mosin
        UnregisterRecipe("PaintMosin");
        UnregisterRecipe("PaintMosinCamoBlack");
        UnregisterRecipe("PaintMosinCamoGreen");
        RegisterRecipe(new PaintBlackMosin);
        RegisterRecipe(new PaintGreenMosin);
        RegisterRecipe(new PaintCamoMosinB);
        RegisterRecipe(new PaintCamoMosinG);
        RegisterRecipe(new PaintTundraBlack);
        RegisterRecipe(new PaintTundraGreen);
        //Spraypaint Ghillie
        UnregisterRecipe("PaintGhillieAttBlack");
        UnregisterRecipe("PaintGhillieAttGreen");
        UnregisterRecipe("PaintGhillieAttGreenMossy");
        RegisterRecipe(new PaintGhillieAtt1);
        RegisterRecipe(new PaintGhillieAtt2);
        RegisterRecipe(new PaintGhillieAtt3);
    }    
};
//**Workaround for UnregisterRecipe syntax not working**
//MunghardIP
/*modded class CraftGunwallMetalMung
{
    override bool CanDo(ItemBase ingredients[], PlayerBase player)//final check for recipe's validity
    {
        return false;
    }
};
modded class CraftGunwallMung
{
    override bool CanDo(ItemBase ingredients[], PlayerBase player)//final check for recipe's validity
    {
        return false;
    }
};*/