modded class ActionConstructor 
{
    override void RegisterActions(TTypenameArray actions)
    {
        super.RegisterActions(actions);
		
		actions.Insert(BST_ActionUseBench);
		actions.Insert(BST_ActionStartStopSmelting);
		actions.Insert(BST_ActionOpenFurnace);
		actions.Insert(BST_ActionCloseFurnace);
		actions.Insert(ActionBRPSitOnChair);
		actions.Insert(ActionBRPDismantleItem);
		actions.Insert(ActionBRPCustomClose);
		actions.Insert(ActionBRPCustomOpen);
		actions.Insert(ActionDismantleBase_Almara);
		actions.Insert(ActionDismantleBase_Almara_Large);
		actions.Insert(ActionDismantleBase_BMetalCrate);
		actions.Insert(ActionDismantleBase_GMetalCrate);
		actions.Insert(ActionDismantleBase_CoffeeTable);
		actions.Insert(ActionDismantleBase_Cot);
		actions.Insert(ActionDismantleBase_CornerSofa);
		actions.Insert(ActionDismantleBase_LeatherSofa);
		actions.Insert(ActionDismantleBase_Chernarus_Flag);
		actions.Insert(ActionDismantleBase_Nightstand);
		actions.Insert(ActionDismantleBase_SingleBed);
		actions.Insert(ActionDismantleBase_WoodStorage);
    }
}
