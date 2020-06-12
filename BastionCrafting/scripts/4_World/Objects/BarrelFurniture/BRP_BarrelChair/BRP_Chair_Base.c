class BRP_Chair_Base extends Container_Base
{
	override bool CanPutInCargo( EntityAI parent )
	{
		if( !super.CanPutInCargo(parent) )
		{
			return false;
		}
		if ( GetNumberOfItems() == 0 )
		{
			return true;
		}
		return false;
	}
	
	override bool CanPutIntoHands(EntityAI parent)
	{
		if( !super.CanPutIntoHands( parent ) )
		{
			return false;
		}
		if ( GetNumberOfItems() == 0 )
		{
			return true;
		}
		return false;
	}
	
	override void SetActions()
    {
        super.SetActions();
        
        AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
		AddAction(ActionDeployObject);
		AddAction(ActionBRPSitOnChair);
    }
}
