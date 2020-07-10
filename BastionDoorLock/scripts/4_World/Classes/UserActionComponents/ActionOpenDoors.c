modded class ActionOpenDoors
{
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if (super.ActionCondition(player, target, item))
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
						if (GetLockedDoorsManager().IsDoorNeedKey(doorPos))
						{
							return false;
						}
						else
						{
							return GetLockedDoorsManager().IsDoorOwner(doorPos, player);
						}
					}
				}
			}
			return true;
		}
		return false
	}
}