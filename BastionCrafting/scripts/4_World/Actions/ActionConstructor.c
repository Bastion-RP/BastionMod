modded class ActionConstructor 
{
    override void RegisterActions(TTypenameArray actions)
    {
        super.RegisterActions(actions);
		
		actions.Insert(ActionBRPSitOnChair);
		actions.Insert(BST_ActionUseBench);
		actions.Insert(BST_ActionStartStopSmelting);
		actions.Insert(ActionBRPUpgradeFurnace);
		actions.Insert(ActionBRPDismantleFurnace);
		//actions.Insert(ActionBRPPlaceFireplaceIntoFurnace);
		//actions.Insert(ActionBRPTakeFireplaceFromFurnace);		
    }
}
