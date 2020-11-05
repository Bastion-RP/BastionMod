modded class MissionGameplay
{
	override void OnUpdate(float timeslice)
	{
		super.OnUpdate(timeslice);
		Input input = GetGame().GetInput();

		if (input.LocalPress("UABSTROLL",false))
		{
			TryRoll();
		}
	}

	void TryRoll()
	{
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		if (player && player.IsAlive())
			player.DoRoll();
	}
}