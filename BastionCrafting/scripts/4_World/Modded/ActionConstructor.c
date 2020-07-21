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
    }
}
