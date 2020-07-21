modded class ActionDeployObject
{
    override void OnEndServer(ActionData action_data)
    {
        if( !action_data || !action_data.m_MainItem )
			return;            
       
        super.OnEndServer(action_data);
        
		PlaceObjectActionData placeData = PlaceObjectActionData.Cast(action_data);
        if(action_data.m_MainItem.IsInherited(BRP_Kit) && placeData.m_AlreadyPlaced)
            action_data.m_MainItem.Delete();
        
    }
};