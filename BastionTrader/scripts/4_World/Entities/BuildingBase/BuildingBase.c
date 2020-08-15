modded class BuildingBase
{
	private int	traderId;

	void BuildingBase()
	{
		traderId = -1;
		RegisterNetSyncVariableInt("traderId");
	}

	int GetTraderId()
	{
		return traderId;
	}

	void SetTraderId(int id)
	{
		traderId = id;
		
		SetSynchDirty();
	}

	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionObjectBTraderTrade);
	}

	void SetupTrader(TraderData data)
	{
		int id;
		vector pos;
		vector ori;

		id = data.GetId();
		pos = data.GetPos();
		ori = data.GetOri();

		SetTraderId(id);
		SetPosition(pos);
		SetOrientation(ori);

		SetAllowDamage(false);
	}
}