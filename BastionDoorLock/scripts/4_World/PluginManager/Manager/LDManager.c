class LockedDoorsManager : PluginBase
{
	private int AutoCloseDoorTime;

	void LockedDoorsManager()
	{
		AutoCloseDoorTime = -1;
	}

	bool IsDoorNeedKey(vector doorPos)
	{
		LockDoorStorage doorData;
		if (IsDoorExist(doorPos, doorData))
		{
			return doorData.GetNeedKey();
		}
		return true;
	}

	bool IsRightKey(vector doorPos, ItemBase key)
	{
		if (!key) return false;
		if (key.IsInherited(BunchKeys_Base))
		{
			return BunchKeysHasRightKey(doorPos, key);
		}
		else
		{
			array<string> AllowKeys = GetKeysByDoorPos(doorPos);
			if (AllowKeys && (AllowKeys.Find(key.GetType()) != -1))
			{
				return true;
			}
		}
		return false;
	}

	bool IsDoorOwner(vector doorPos, PlayerBase player)
	{
		LockDoorStorage doorData;
		if (IsDoorExist(doorPos, doorData))
		{
			array<int> BstIds = doorData.GetBstIds();
			array<int> BstClassesD = doorData.GetBastionClasses();
			int bstID = player.GetMultiCharactersPlayerId();
			int bstClass = player.GetMultiCharactersPlayerClass();
			if (BstIds && ( BstIds.Find(bstID) != -1 ))
			{return true;}
			if (BstClassesD && ( BstClassesD.Find(bstClass) != -1 ))
			{return true;}
		}
		return false;
	}

	void OnDoorOpen(int doorIdx, Building building)
	{
		AutoCloseDoorTime = GetLockedDoorsConfigHandler().GetConfig().GetAutoCloseDoorTime();
		if (AutoCloseDoorTime > 0)
		{
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( building.CloseDoor, AutoCloseDoorTime * 1000, false, doorIdx );
		}
	}

	bool IsDoorExist(vector pos, out LockDoorStorage doorData)
	{
		array<ref LockDoorStorage> AllDoorsData = GetLockedDoorsConfigHandler().GetConfig().GetAllDoorsData();
		float maxDist = GetLockedDoorsConfigHandler().GetConfig().GetMaxDst();
		for (int i = 0; i < AllDoorsData.Count(); i++)
		{
			LockDoorStorage singleDoor = AllDoorsData.Get(i);
			if (vector.Distance(pos, singleDoor.GetPos()) <= maxDist)
			{
				{doorData = singleDoor;}
				return true;
			}
		}
		return false;
	}

	ref array<string> GetKeysByDoorPos(vector doorPos)
	{
		LockDoorStorage doorData;
		if (IsDoorExist(doorPos, doorData))
		{
			return doorData.GetAllowKeys();
		}
		return null;
	}

	bool BunchKeysHasRightKey(vector doorPos, ItemBase bunchKeys)
	{
		int attCount = bunchKeys.GetInventory().AttachmentCount();
		ItemBase key;
		for (int attIdx = 0; attIdx < attCount; attIdx++)
		{
			key = bunchKeys.GetInventory().GetAttachmentFromIndex(attIdx);
			if (key && (GetKeysByDoorPos(doorPos).Find(key.GetType()) != -1))
			{
				return true;
			}
		}
		return false;
	}
}
LockedDoorsManager GetLockedDoorsManager()
{
	return LockedDoorsManager.Cast(GetPlugin(LockedDoorsManager));
}
