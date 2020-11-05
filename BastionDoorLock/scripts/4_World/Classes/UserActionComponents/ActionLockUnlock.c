modded class ActionUnlockDoors
{
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		bool actionCondition = super.ActionCondition(player, target, item);

		if (actionCondition)
		{
			if (GetGame().IsClient())
			{
				Building bdl;
				if( Class.CastTo(bdl, target.GetObject()) )
				{
					int dIdx = bdl.GetDoorIndex(target.GetComponentIndex());
					vector doorPos = bdl.GetDoorSoundPos(dIdx);
					LockDoorStorage fix;
					if (dIdx != -1 && GetLockedDoorsManager() && GetLockedDoorsManager().IsDoorExist(doorPos, fix) )
					{
						return false;
					}
					return true;
				}
			}
			return true;
		}
		
		return false;
	}
}

modded class ActionLockDoors
{
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		bool actionCondition = super.ActionCondition(player, target, item);

		if (actionCondition)
		{
			if (GetGame().IsClient())
			{
				Building bdl;
				if( Class.CastTo(bdl, target.GetObject()) )
				{
					int dIdx = bdl.GetDoorIndex(target.GetComponentIndex());
					vector doorPos = bdl.GetDoorSoundPos(dIdx);
					LockDoorStorage fix;
					if (dIdx != -1 && GetLockedDoorsManager() && GetLockedDoorsManager().IsDoorExist(doorPos, fix) )
					{
						return false;
					}
					return true;
				}
			}
			return true;
		}
		
		return false;
	}
}