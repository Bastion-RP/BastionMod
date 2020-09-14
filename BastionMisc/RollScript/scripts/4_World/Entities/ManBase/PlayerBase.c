modded class PlayerBase
{
	private const int ROLL_RPC_SEND = -000999;
	private const int ROLL_RPC_APPLY = -000998;

	private const int ROLL_COOLDOWN = 10;
	private const int ROLL_MAXVALUE = 6;
	private const int ROLL_MAXDISTANCE = 15;
	private bool rollAllowed = true;

	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);

		Param1<string> data;

		if (GetGame().IsClient())
		{
			if (rpc_type == ROLL_RPC_APPLY)
			{
				if (!ctx.Read(data)) return;
				BSTShowNotification(data.param1);
			}
		} else if (GetGame().IsServer())
		{
			if (rpc_type == ROLL_RPC_SEND)
			{
				if (!ctx.Read(data)) return;
				SendToNearestPlayers(data.param1);
			}
		}
	}

	bool CanRoll()
	{
		return rollAllowed;
	}

	void SetAllowRoll(bool val)
	{
		rollAllowed = val;
	}

	void DoRoll()
	{
		if (CanRoll() == false)
			return;

		SetAllowRoll(false);
		Roll();
		GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( SetAllowRoll, (ROLL_COOLDOWN * 1000), false, true );
	}

	void Roll()
	{
		int number = Math.RandomIntInclusive(1, ROLL_MAXVALUE);
		string message = string.Format("%1 rolls %2", this.GetMultiCharactersPlayerName(), number);
		this.RPCSingleParam(ROLL_RPC_SEND, new Param1<string>(message), true);
		BSTShowNotification(message);
	}

	/*==================================
	HousingManager.c -> class HouseManager (305)

		void ShowBastionNotification(string text)
		{
			new BstNot(text);
		}
	*/
	void BSTShowNotification(string text)
	{
		g_HM.ShowBastionNotification(text);
	}

	void SendToNearestPlayers(string text)
	{
		array<Man> players = new array<Man>();
		GetGame().GetPlayers(players);
		foreach (auto player : players)
		{
			if (player && player != this && player.IsAlive() && IsPlayerNear(player))
			{
				player.RPCSingleParam(ROLL_RPC_APPLY, new Param1<string>(text), true, player.GetIdentity());
			}
		}
	}

	bool IsPlayerNear(Man player)
	{
		vector sourcePos = GetPosition();
		vector distPos = player.GetPosition();
		return (vector.Distance(sourcePos, distPos) <= ROLL_MAXDISTANCE);
	}
}