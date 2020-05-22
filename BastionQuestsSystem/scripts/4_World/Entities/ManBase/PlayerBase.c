modded class PlayerBase
{
	private int		UnicID;

	void PlayerBase()
	{
		UnicID = -1;
		RegisterNetSyncVariableInt("UnicID");
	}

	void SetQuestNPC(int id)
	{
		SetAllowDamage(false);
		UnicID = id;
		SetSynchDirty();
	}

	int GetQuestID()
	{
		return UnicID;
	}

	override void SetActionsRemoteTarget()
	{
        super.SetActionsRemoteTarget();
        RemoveAction(ActionCheckPulse);
		AddAction(ActionInteractQuestHumanNPC);
        AddAction(ActionCheckPulse);
	}

    override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);
        if (GetGame().IsClient())
        {
            g_QM.OnRPC(sender, rpc_type, ctx);
        }
    }
}