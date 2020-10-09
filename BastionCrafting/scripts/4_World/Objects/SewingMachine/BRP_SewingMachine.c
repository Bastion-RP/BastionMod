class BRP_SewingMachine : ItemBase
{
	override void SetActions()
    {
        super.SetActions();
        
        AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
    }
};
