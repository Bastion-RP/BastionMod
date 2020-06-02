modded class ActionOpenDoors
{
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
					if ((g_HM.AdminsArr.Find(player.GetIdentity().GetId()) + 1))
					{return true;}
					if (building.m_HouseData && building.m_HouseData.MainOwner && (building.m_HouseData.MainOwner.HashID == player.GetIdentity().GetId()))
					{return true;}
					int doorIndex = building.GetDoorIndex(target.GetComponentIndex());
					return g_HM.IsDoorOwner(player, building, doorIndex);
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
