class ToxicRPCServer : PluginBase
{
	private float HealthDamagePlayer;
	private float BloodDamagePlayer;
	private float HealthDamageMask;

    void ToxicRPCServer() 
	{
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) 
		{ return; }

        GetDayZGame().Event_OnRPC.Insert(OnRPC);

		HealthDamagePlayer = GetToxicManager().GetSettings().GetPHealthDmg();
		BloodDamagePlayer = GetToxicManager().GetSettings().GetPBloodDmg();
		HealthDamageMask = GetToxicManager().GetSettings().GetMaskDamage();
    }

    void ~ToxicRPCServer() 
	{
        GetDayZGame().Event_OnRPC.Remove(OnRPC);
    }

    void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) 
	{
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer())
			return;

        if (!sender) 
			return;

		PlayerBase player = PlayerBase.Cast(target);

		switch (rpc_type)
		{
			case TRPCs.HAS_PROTECT: DamageMask(player); break;
			case TRPCs.HAS_NO_PROTECT: DamagePlayer(player); break;
		}
	}

	void DamageMask(PlayerBase player)
	{
		ItemBase mask = player.FindAttachmentBySlotName("Mask");
		if (!mask)
			return;
		mask.AddHealth("GlobalHealth", "Health" , (-1 * HealthDamageMask));
	}

	void DamagePlayer(PlayerBase player)
	{
		player.AddHealth("GlobalHealth", "Health" , (-1 * HealthDamagePlayer));
		player.AddHealth("GlobalHealth", "Blood" , (-1 * BloodDamagePlayer));
		player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_COUGH);
	}
}