class QuestManager
{
    ref array<ref NPC>          NPCArray;
	ref array<ref Quest>		AllQuests;
	ref set<int>				AppliedQuests;
	ref map<string,int>			m_ExItems;
	private ref NPC				m_CurrentNPC;
	private ref QuestHud		m_QuestHud;

	ref QuestManagerStg			m_QuestManagerStg;

	bool						IsInit;

	PlayerBase					m_Player;

    void QuestManager()
    {
        NPCArray		= new array<ref NPC>();
		AppliedQuests	= new set<int>();
		AllQuests		= new array<ref Quest>();
		m_ExItems		= new map<string,int>();
		IsInit			= false;
		m_Player		= PlayerBase.Cast(GetGame().GetPlayer());

		m_QuestManagerStg = new QuestManagerStg();
		GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( this.Update, 2000, true);
    }

	void ~QuestManager()
	{
		GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).Remove( this.Update );
	}

	void SetQuestNPC(NPC npc)
	{
		m_CurrentNPC = npc;
	}

	NPC GetCurNPC()
	{
		return m_CurrentNPC;
	}

	void RequestNPCTalk()
	{
		if (m_QuestHud || GetGame().GetUIManager().GetMenu()) return;
		GetGame().GetMission().GetHud().ShowQuickbarUI( false );
        m_QuestHud = new QuestHud();
        GetGame().GetUIManager().ShowScriptedMenu( m_QuestHud, NULL );
	}

	void CloseMenu()
	{
		if ( GetGame().GetUIManager().GetMenu() && m_QuestHud)
		{
			GetGame().GetUIManager().Back();
			GetGame().GetMission().GetHud().ShowQuickbarUI( true );
		}
	}

	void OnKeyPress( int key )
    {
        switch (key)
        {
            case KeyCode.KC_ESCAPE:
				CloseMenu();
            break;
        }
    }

	static void SelfChatMessage( string message )
	{ 
        GetGame().GetMission().OnEvent(ChatMessageEventTypeID, new ChatMessageEventParams(0, "", message, "")); 
    }

	void CompeteQuest(Quest qt)
	{
		int idx;
		bool needSync = false;
		for (int i = 0; i < m_QuestManagerStg.QuestStatusArr.Count(); i++)
		{
			AppliedQuestStatus qs = m_QuestManagerStg.QuestStatusArr.Get(i);
			if (qt.QuestID == qs.QuestID)
			{
				needSync = true;
				idx = m_QuestManagerStg.QuestStatusArr.Find(qs);
				m_QuestManagerStg.QuestStatusArr.Remove(idx);
				if (qt.Repeatable)
				{
					m_QuestManagerStg.CompRepeatQuests.Insert(qs.QuestID);
					StartCooldownTimer(qs.QuestID, qt.Delay);
				}
				else
				{
					m_QuestManagerStg.CompNonRepeatQuests.Insert(qs.QuestID);
				}
				break;
			}
		}
		if (needSync)
		{
			RequestSyncData();
		}
	}

	void TakeQuest(Quest qt)
	{
		switch (qt.Type)
		{
			case "Delivery":
				TakeDelivery(qt);
			break;
			case "FindAndDelivery":
				TakeFindAndDelivery(qt);
			break;
			case "KillSomething":
				TakeKillSomething(qt);
			break;
		}
		RequestSyncData();
	}

	void TakeDelivery(Quest qt)
	{
		AppliedQuestStatus qs = new AppliedQuestStatus();
		qs.QuestID = qt.QuestID;
		qs.Type = qt.Type;
		m_QuestManagerStg.QuestStatusArr.Insert(qs);
	}

	void TakeFindAndDelivery(Quest qt)
	{
		AppliedQuestStatus qs = new AppliedQuestStatus();
		qs.QuestID = qt.QuestID;
		qs.Type = qt.Type;
		for (int i = 0; i < qt.Shipments.Count(); i++)
		{
			qs.SaveCountSpawnedItems.Insert(0);
		}
		m_QuestManagerStg.QuestStatusArr.Insert(qs);
	}

	void TakeKillSomething(Quest qt)
	{
		AppliedQuestStatus qs = new AppliedQuestStatus();
		qs.QuestID = qt.QuestID;
		qs.Type = qt.Type;
		for (int i = 0; i < qt.TargetsForKilling.Count(); i++)
		{
			QKillTgt qkt = qt.TargetsForKilling.Get(i);
			qkt.KillCount = 0;
			qs.SaveCountKilledSomething.Insert(qkt);
		}
		m_QuestManagerStg.QuestStatusArr.Insert(qs);
	}

	void CooldownQuest(int qID) 
	{
		int idx;
		idx = m_QuestManagerStg.CompRepeatQuests.Find(qID);
		if (idx != -1) 
		{m_QuestManagerStg.CompRepeatQuests.Remove(idx);}
		RequestSyncData();
	}

	void StartCooldownTimer(int questID, int delay)
	{
		GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater(CooldownQuest, (delay * 1000), false, questID);
	}

	void FirstSyncCooldown()
	{
		for (int i = 0; i < m_QuestManagerStg.CompRepeatQuests.Count(); i++)
		{
			Quest qt = GetQuestByID(m_QuestManagerStg.CompRepeatQuests.Get(i));
			if (qt)
			{
				StartCooldownTimer(qt.QuestID, qt.Delay);
			}
		}
	}

	bool CanTakeQuest(int questID)
	{
		for (int i = 0; i < m_QuestManagerStg.QuestStatusArr.Count(); i++)
		{
			AppliedQuestStatus qs = m_QuestManagerStg.QuestStatusArr.Get(i);
			if (questID == qs.QuestID)
			{
				return false;
			}
		}

		Quest qt = GetQuestByID(questID);
		if (qt)
		{
			for (int j = 0; j < qt.Required.Count(); j++)
			{
				int reqID = qt.Required.Get(j);
				if ( (m_QuestManagerStg.CompNonRepeatQuests.Find(reqID) == -1) && (m_QuestManagerStg.CompRepeatQuests.Find(reqID) == -1) )
				{
					return false;
				}
			}
		}

		if ( (m_QuestManagerStg.CompNonRepeatQuests.Find(questID) != -1) || (m_QuestManagerStg.CompRepeatQuests.Find(questID) != -1) )
		{
			return false;
		}

		return true;
	}

	Quest GetQuestByID(int questID)
	{
		for (int j = 0; j < AllQuests.Count(); j++)
		{
			Quest qt = AllQuests.Get(j);
			if (questID == qt.QuestID)
			{
				return qt;
			}
		}
		return null;
	}
	

//=======================================================RPC===================================================================
    void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
    {
        switch (rpc_type)
        {
            case QRPC.SEND_NPC_DATA:
                handleApplyNPCData(ctx);
            break;
			case QRPC.SEND_QUESTS_DATA:
				handleApplyQuestsData(ctx);
			break;
			case QRPC.SEND_SYNC_QUEST:
				handleSyncQuests(ctx);
			break;
        }
    }


    void handleApplyNPCData(ParamsReadContext ctx)
    {
        Param1<ref NPC> rpb;
        if (!ctx.Read(rpb)) return;
        NPC npc = rpb.param1;
        NPCArray.Insert(npc);
    }


	void handleApplyQuestsData(ParamsReadContext ctx)
	{
		Param1<ref array<ref Quest>> rpb;
        if (!ctx.Read(rpb)) return;
		AllQuests = rpb.param1;
	}

	void handleSyncQuests(ParamsReadContext ctx)
	{
		Param1<ref QuestManagerStg> rpb;
		if (!ctx.Read(rpb)) return;
		m_QuestManagerStg = rpb.param1;
		if (!IsInit) FirstSyncCooldown();
		IsInit = true;
	}

	void RequestSyncData()
	{
		m_Player = PlayerBase.Cast(GetGame().GetPlayer());
		if (m_Player)
		m_Player.RPCSingleParam(QRPC.REQUEST_SYNC_DATA, new Param1<ref QuestManagerStg>(m_QuestManagerStg), true, null);
	}

	void Update()
	{
		m_Player = PlayerBase.Cast(GetGame().GetPlayer());
		if (!IsInit) return;
		if (!m_Player) return;
		bool needSync = false;
		vector pPos = m_Player.GetPosition();
		NormalizeHeight(pPos);
		for (int i = 0; i < m_QuestManagerStg.QuestStatusArr.Count(); i++)
		{
			AppliedQuestStatus qs = m_QuestManagerStg.QuestStatusArr.Get(i);
			Quest qt = GetQuestByID(qs.QuestID);
			for (int j = 0; j < qs.SaveCountSpawnedItems.Count(); j++)
			{
				if (qs.SaveCountSpawnedItems.Get(j) == 1) continue;

				ref Shipment sh = qt.Shipments.Get(j);
				if ( vector.Distance(pPos, sh.PackagePos) <= sh.DistanceForSpawn )
				{
					RequestSpawnItems(sh);
					qs.SaveCountSpawnedItems[j] = 1;
					needSync = true;
				}
			}
		}
		if (needSync)
		RequestSyncData();
	}

	void NormalizeHeight(out vector pos)
	{
		float tempHeight = GetGame().SurfaceY(pos[0], pos[2]);
		if (pos[1] < tempHeight)
		{
			pos[1] = tempHeight;
		}
	}

	void RequestSpawnItems(ref Shipment sh)
	{
		m_Player.RPCSingleParam(QRPC.REQUEST_SPAWN_ITEM, new Param1<ref Shipment>(sh), true, null);
	}
}
ref QuestManager g_QM;