modded class PlayerBase
{
	private bool hasWorkingGps;

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

	bool HasWorkingGps()
	{
		GpsBase gpsItem;
		array<EntityAI> itemsArray = new array<EntityAI>;
		GetInventory().EnumerateInventory(InventoryTraversalType.PREORDER, itemsArray);
		
		for (int i = 0; i < itemsArray.Count(); i++)
		{
			if (Class.CastTo(gpsItem, itemsArray.Get(i)) && gpsItem.IsWorking())
			{
				return true;
			}
		}
		return false;
	}
}