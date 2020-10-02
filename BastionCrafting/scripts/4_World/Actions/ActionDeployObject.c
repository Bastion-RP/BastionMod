modded class ActionDeployObject
{
    override void OnEndServer(ActionData action_data)
    {
		
        if( !action_data || !action_data.m_MainItem )
			return;    
		
		super.OnEndServer(action_data);
		
		PlaceObjectActionData placeData = PlaceObjectActionData.Cast(action_data);
		if (placeData){
			if (action_data.m_MainItem.IsKindOf("Base_Almara_Kit") || action_data.m_MainItem.IsKindOf("Base_Almara_Large_Kit") || action_data.m_MainItem.IsKindOf("Base_GMetalCrate_Kit") || action_data.m_MainItem.IsKindOf("Base_BMetalCrate_Kit") || action_data.m_MainItem.IsKindOf("Base_Cot_Kit") || action_data.m_MainItem.IsKindOf("Base_Nightstand_Kit") || action_data.m_MainItem.IsKindOf("Base_Chernarus_Flag_Kit") || action_data.m_MainItem.IsKindOf("Base_CornerSofa_Kit") || action_data.m_MainItem.IsKindOf("Base_LeatherSofa_Kit") || action_data.m_MainItem.IsKindOf("Base_WoodStorage_Kit") || action_data.m_MainItem.IsKindOf("Base_SingleBed_Kit")  || action_data.m_MainItem.IsKindOf("Base_CoffeeTable_Kit"))
			{
				 action_data.m_MainItem.Delete();
			}
		}
    }
}