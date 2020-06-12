modded class ActionPlaceObject
{
    override void OnEndServer(ActionData action_data)
    {
        if (action_data.m_MainItem.IsKindOf("BRP_FurnaceKit") )
        {
			GetGame().ObjectDelete(action_data.m_MainItem);
		}
        else
        {
            super.OnEndServer(action_data);
        }
    }
}
