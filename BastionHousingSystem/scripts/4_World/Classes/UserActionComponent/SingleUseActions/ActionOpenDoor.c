modded class ActionOpenDoors
{
	int doorIdx;
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if( !target ) return false;
		if( !IsBuilding(target) ) return false;

		BRP_House brpbuilding;
		if( Class.CastTo(brpbuilding, target.GetObject()) )
		{
			if (super.ActionCondition(player, target, item))
			{
				if (GetGame().IsClient())
				{
					doorIdx = brpbuilding.GetDoorIndex(target.GetComponentIndex());
					if (!brpbuilding.m_HouseData)
					{return true;}
					if (!brpbuilding.m_HouseData.LeaseTime)
					{return true;}
					if (brpbuilding.m_HouseData && brpbuilding.m_HouseData.MainOwner && (brpbuilding.m_HouseData.MainOwner.MilticharacterID == player.GetMultiCharactersPlayerId().ToString()) && g_HM.IsDoorAllow(doorIdx, brpbuilding)) 
					{return true;}
					return g_HM.IsDoorOwner(player, brpbuilding, doorIdx);
				}
				return true;
			}
			else
			{
				return false;
			}
		}
		return super.ActionCondition(player, target, item);
	}

	override void OnStartServer( ActionData action_data )
	{
		super.OnStartServer(action_data);
		BRP_House brpbuilding;
		if( Class.CastTo(brpbuilding, action_data.m_Target.GetObject()) )
		{
			int doorIndex = brpbuilding.GetDoorIndex(action_data.m_Target.GetComponentIndex());
			if( doorIndex != -1 )
			{
				brpbuilding.OpenDoor(doorIndex);
			}
		}
	}
}
