modded class ActionConstructor 
{
    override void RegisterActions(TTypenameArray actions)
    {
        super.RegisterActions(actions);
		
		actions.Insert(ActionBRPSitOnChair);
		actions.Insert(ActionBRPUpgradeFurnace);
		actions.Insert(ActionBRPDismantleFurnace);
		//actions.Insert(ActionBRPPlaceFireplaceIntoFurnace);
		//actions.Insert(ActionBRPTakeFireplaceFromFurnace);		
    }
}
