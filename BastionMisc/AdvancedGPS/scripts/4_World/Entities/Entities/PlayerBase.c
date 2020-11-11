modded class PlayerBase
{
	private bool hasWorkingGps;
	private GpsBase mainGPS;

	override void OnConnect()
	{
		super.OnConnect();

		GetGame().RPCSingleParam(this, -999777722, new Param1<ref GpsConfig>(GetADVCGps().GetConfig()), true, this.GetIdentity());
	}

	bool GetGpsState()
	{
		return hasWorkingGps;
	}

	void SetGpsState(bool val)
	{
		hasWorkingGps = val;
	}

	GpsBase GetWorkingGps()
	{
		GpsBase gpsItem;
		array<EntityAI> itemsArray = new array<EntityAI>;
		GetInventory().EnumerateInventory(InventoryTraversalType.PREORDER, itemsArray);
		
		for (int i = 0; i < itemsArray.Count(); i++)
		{
			if (Class.CastTo(gpsItem, itemsArray.Get(i)) && gpsItem.IsWorking())
			{
				return gpsItem;
			}
		}
		return null;
	}

	void SetMainGps()
	{
		if (mainGPS && mainGPS.IsWorking() && mainGPS.GetHierarchyRootPlayer() == GetGame().GetPlayer())
			return;
		mainGPS = GetWorkingGps();
		GetGame().RPCSingleParam(null, -999777723, new Param1<GpsBase>(mainGPS), true, null);
	}

	GpsBase GetMainGps()
	{
		return mainGPS;
	}
}