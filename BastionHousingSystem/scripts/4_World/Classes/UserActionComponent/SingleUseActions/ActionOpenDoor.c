modded class ActionOpenDoors
{
	int doorIdx;
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if( !target ) return false;
		if( !IsBuilding(target) ) return false;

		BRP_House building;
		if( Class.CastTo(building, target.GetObject()) )
		{
			if (super.ActionCondition(player, target, item))
			{
				if (GetGame().IsClient())
				{
					doorIdx = building.GetDoorIndex(target.GetComponentIndex());
					if (!building.m_HouseData)
					{return true;}
					if (!building.m_HouseData.LeaseTime)
					{return true;}
					if (building.m_HouseData && building.m_HouseData.MainOwner && (building.m_HouseData.MainOwner.HashID == player.GetIdentity().GetId()) && g_HM.IsDoorAllow(doorIdx, building)) // TODO change to multicharID
					{return true;}
					return g_HM.IsDoorOwner(player, building, doorIdx);
				}
			}
			else
			{
				return false;
			}
		}
		return super.ActionCondition(player, target, item);
	}

}
