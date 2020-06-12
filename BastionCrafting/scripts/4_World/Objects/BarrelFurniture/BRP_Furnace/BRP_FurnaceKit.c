class BRP_FurnaceKit extends ItemBase
{	
	void BRP_FurnaceKit()
	{
	}
	
	string NeededHologram()
    {
        return "BRP_Furnace_Hologram"; 
    }
	
	override void OnPlacementComplete( Man player )
	{
		if ( GetGame().IsServer() )
		{
			//Create model
			PlayerBase player_base = PlayerBase.Cast( player );
			vector position = player_base.GetLocalProjectionPosition();
			vector orientation = player_base.GetLocalProjectionOrientation();
			
			BRP_Furnace brpfurnace = BRP_Furnace.Cast( GetGame().CreateObject( "BRP_Furnace", GetPosition() ) );
			brpfurnace.SetPosition( position );
			brpfurnace.SetOrientation( orientation );
			
			//make the kit invisible, so it can be destroyed from deploy UA when action ends
			HideAllSelections();
			
			SetIsDeploySound( true );
			super.OnPlacementComplete( player );
		}	
	}
	
	override bool IsDeployable()
	{
		return true;
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
	}
}
