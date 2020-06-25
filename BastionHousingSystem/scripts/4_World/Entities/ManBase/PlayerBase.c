modded class PlayerBase
{
	private bool			CanSyncHouseData;
	private int				HDataSyncDelay;

	void PlayerBase()
	{
		CanSyncHouseData	= true;
		HDataSyncDelay		= 3;
	}

	override void OnConnect()
	{
		super.OnConnect();
		g_HSL.SendAdmins(this);
		g_HSL.SendMainHouseData(this);
		Print("Player name: "+this.GetIdentity().GetName()+" id: "+this.GetIdentity().GetId()+"has joined.");
	}

	bool CanSyncHouseData()
	{
		return CanSyncHouseData;
	}

	void SetSyncHouseData()
	{
		CanSyncHouseData = false;
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(this.AllowSyncHouseData, HDataSyncDelay * 1000, false);
	}

	void AllowSyncHouseData()
	{
		CanSyncHouseData = true;
	}

	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionShowDoorInfo);
	}

	override void OnRPC(PlayerIdentity sender, int rpc_type,ParamsReadContext  ctx) 
	{
		super.OnRPC(sender, rpc_type,ctx);
		if (GetGame().IsClient())
		{g_HM.OnRPC(sender, rpc_type, ctx);}
		else
		{
			if (rpc_type == HRPC.REQUEST_HOUSES_DATA)
			{
				Print("Main house data request");
				g_HSL.SendMainHouseData(this);
			}
			if (rpc_type == HRPC.REQUEST_BRP_HOUSES)
			{
				g_HSL.SendAllHouses(this);
			}
		}
	}

}