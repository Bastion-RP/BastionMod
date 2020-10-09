modded class ActionDeployObject
{
    override void OnEndServer(ActionData action_data)
    {
        if (action_data.m_MainItem.IsKindOf("Base_Almara_Kit") || action_data.m_MainItem.IsKindOf("Base_Almara_Large_Kit") || action_data.m_MainItem.IsKindOf("Base_GMetalCrate_Kit") || action_data.m_MainItem.IsKindOf("Base_BMetalCrate_Kit") || action_data.m_MainItem.IsKindOf("Base_Cot_Kit") || action_data.m_MainItem.IsKindOf("Base_Nightstand_Kit") || action_data.m_MainItem.IsKindOf("Base_Chernarus_Flag_Kit") || action_data.m_MainItem.IsKindOf("Base_CornerSofa_Kit") || action_data.m_MainItem.IsKindOf("Base_LeatherSofa_Kit") || action_data.m_MainItem.IsKindOf("Base_WoodStorage_Kit") || action_data.m_MainItem.IsKindOf("Base_SingleBed_Kit")  || action_data.m_MainItem.IsKindOf("Base_CoffeeTable_Kit"))
        {
            PlaceObjectActionData poActionData;
            poActionData = PlaceObjectActionData.Cast(action_data);
            if (!poActionData.m_AlreadyPlaced)
            {
                EntityAI entity_for_placing = action_data.m_MainItem;
                GetGame().ClearJuncture(action_data.m_Player, entity_for_placing);
                action_data.m_MainItem.SetIsBeingPlaced(false);
            
                if (GetGame().IsMultiplayer())
                {
                    action_data.m_Player.PlacingCancelServer();
                    action_data.m_MainItem.SoundSynchRemoteReset();
                }
                else
                {
                    action_data.m_Player.PlacingCancelLocal();
                    action_data.m_Player.LocalTakeEntityToHands(entity_for_placing);
                }
            }
            else
            {
                GetGame().ObjectDelete(action_data.m_MainItem);
                action_data.m_MainItem.SetIsDeploySound(false);
                action_data.m_MainItem.SetIsPlaceSound(false);
                action_data.m_MainItem.SoundSynchRemoteReset();
            }
        }
        else
        {
            super.OnEndServer(action_data);
        }
    }
}