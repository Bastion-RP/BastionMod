class BRP_Item: ItemBase
{
	override bool CanPutInCargo( EntityAI parent )
    {
        return false;
    }
    
    override bool CanPutIntoHands(EntityAI parent)
    {
        return false;
    }
};

class BRP_Kit: ItemBase
{	
	void BRP_Kit()
	{
		RegisterNetSyncVariableBool("m_IsSoundSynchRemote");
	}
		
	override void OnPlacementComplete( Man player )
	{	
		if ( GetGame().IsServer() )
		{
			PlayerBase player_base = PlayerBase.Cast( player );
			vector position = player_base.GetLocalProjectionPosition();
			vector orientation = player_base.GetLocalProjectionOrientation();
				
			EntityAI kitItem = EntityAI.Cast(GetGame().CreateObjectEx(Get_ItemName(), position, ECE_PLACE_ON_SURFACE));
			kitItem.SetPosition(position);
			kitItem.SetOrientation(orientation);
		}
		
		SetIsPlaceSound( true );
	}
	
	override bool IsDeployable()
	{
		return true;
	}	
	
	override string GetPlaceSoundset()
	{
		return "putDown_FenceKit_SoundSet";
	}
	
    override void SetActions()
    {
        super.SetActions();
        
        AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
    }
};