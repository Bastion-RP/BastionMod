class BRP_BarrelTableCactus extends ItemBase
{
	override void SetActions()
    {
        super.SetActions();
        
        AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
		AddAction(ActionDeployObject);
    }
}
