modded class PlayerBase
{
	private int		UnicID;
	private ref PersonalQuestManager	m_PersonQuestManag;

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

	override void OnConnect()
    {
        super.OnConnect();

		if (GetGame().IsServer() && GetIdentity())
		{
			m_PersonQuestManag = new PersonalQuestManager(this);
		}
		
		m_PersonQuestManag.OnConnect();
    }

	PersonalQuestManager GetPersonalQuestManager()
	{
		return m_PersonQuestManag;
	}

    override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);
        if (GetGame().IsClient())
        {
            g_QM.OnRPC(sender, rpc_type, ctx);
        }
		else if (GetGame().IsServer())
		{
			m_PersonQuestManag.OnRPC(sender, rpc_type, ctx);
		}
    }

}