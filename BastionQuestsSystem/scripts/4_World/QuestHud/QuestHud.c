class QuestHud extends UIScriptedMenu
{
    private ScrollWidget			m_MainDialogScroll;
    private ScrollWidget			m_ChoiceScroll;
    private WrapSpacerWidget        m_DialogMessagesContainer;
    private WrapSpacerWidget        m_DialogChoicesContainer;


	private PlayerBase				m_Player;
	private NPC						m_CurNPC;

    void QuestHud()
    {
        GetGame().GetMission().PlayerControlDisable(INPUT_EXCLUDE_ALL);
		m_Player = PlayerBase.Cast(GetGame().GetPlayer());
		m_CurNPC = g_QM.GetCurNPC();
		CheckNPCData();
    }

    void ~QuestHud()
    {
		g_QM.m_ExItems.Clear();
        GetGame().GetMission().PlayerControlEnable(true);
    }

    override Widget Init()
	{
		layoutRoot 				    = 	GetGame().GetWorkspace().CreateWidgets("BastionMod/BastionQuestsSystem/layouts/MainQuestLayout.layout");
        m_MainDialogScroll          =   ScrollWidget.Cast(GetWid("MainDialogScroll"));
        m_ChoiceScroll              =   ScrollWidget.Cast(GetWid("ChoiceScroll"));
        m_DialogMessagesContainer	=	WrapSpacerWidget.Cast(GetWid("DialogMessagesContainer"));
        m_DialogChoicesContainer	=	WrapSpacerWidget.Cast(GetWid("DialogChoicesContainer"));


		ScanItems();
		SetupFinishDialogs();
		StartDialog();
		return layoutRoot;
	}

    Widget GetWid(string val)
	{
		return layoutRoot.FindAnyWidget(val);
	}

	void CheckNPCData()
	{
		if (!m_CurNPC) QuestManager.SelfChatMessage("Quest data is corrupted!");
	}

	void StartDialog()
	{
		if (m_CurNPC)
		{
			QuestDialog qd = m_CurNPC.Dialogues.Get(0);
			if (qd)
			UpdateDialogContent(qd);
		}
	}

	// type 0 - bot, 1 - player
	void AddDialogMessage(int type, string text, string name)
	{
		new SpeakerNameContainer(m_DialogMessagesContainer, name, type);
		new DialogMainContainer(m_DialogMessagesContainer, text);
	}

	void AddChoice(string text, int move, int apply, int finish = 0, string teleportTo = "")
	{
		if (!g_QM.CanTakeQuest(apply)) return;
		new ChoiceContainer(m_DialogChoicesContainer, text, move, apply, finish, teleportTo);
	}

	void UpdateDialogContent(QuestDialog qd)
	{
		AddDialogMessage(0, qd.Message, m_CurNPC.NPCName);
		for (int i = 0; i < qd.Choices.Count(); i++)
		{
			Choice ch = qd.Choices.Get(i);
			AddChoice(ch.ChoiceMsg, ch.MoveToDialog, ch.ApplyQuest, 0, ch.TeleportTo);
		}
		AddChoice("(Close the dialog)", -123, 0);
	}

	override bool OnClick(Widget w, int x, int y, int button)
	{
		super.OnClick(w, x, y, button);

		if (w.GetUserID() == 57)
		{
			SelectResponse(w.GetParent());
		}		
		return false;
	}

	void SelectResponse(Widget choiceWid)
	{
		EditBoxWidget moveBox = EditBoxWidget.Cast(choiceWid.FindAnyWidget("MoveToStg"));
		EditBoxWidget applBox = EditBoxWidget.Cast(choiceWid.FindAnyWidget("ApplyIDStg"));
		EditBoxWidget textBox = EditBoxWidget.Cast(choiceWid.FindAnyWidget("ChoiceText"));
		EditBoxWidget finishBox = EditBoxWidget.Cast(choiceWid.FindAnyWidget("FinishStg"));
		EditBoxWidget teleportBox = EditBoxWidget.Cast(choiceWid.FindAnyWidget("TeleportTo"));
		string moveIDs = moveBox.GetText();
		int applIDs = applBox.GetText().ToInt();
		int finishIDs = finishBox.GetText().ToInt();
		string textBoxs = textBox.GetText();
		string teleportPos = teleportBox.GetText();
		if (moveIDs == "-123") g_QM.CloseMenu();
		if (moveIDs)
		{
			int moveID = moveIDs.ToInt();
			if (!moveID)
			{
				AddDialogMessage(1, textBoxs, GetMulticharacterName());
				ClearChoices();
				AddChoice("(Close the dialog)", -123, 0);
			}
			else
			{
				for (int i = 0; i < m_CurNPC.Dialogues.Count(); i++)
				{
					QuestDialog qd = m_CurNPC.Dialogues.Get(i);
					if (qd.ID == moveID)
					{
						AddDialogMessage(1, textBoxs, GetMulticharacterName());
						ClearChoices();
						UpdateDialogContent(qd);
						break;
					}
				}
			}
		}
		if (finishIDs)
		{
			FinishQuest(finishIDs);
		}
		if (applIDs)
		{
			Quest qt = g_QM.GetQuestByID(applIDs);
			if (ApplyQuestCondition(qt))
			{
				g_QM.TakeQuest(qt);
			}
		}
		if ((teleportPos != string.Empty) && (teleportPos.ToVector() != vector.Zero))
		{
			m_Player.RPCSingleParam(QRPC.REQUEST_TELEPORT_PLAYER, new Param1<string>(teleportPos), true, null);
			Close();
		}
	}

	void ClearChoices()
	{
		while (m_DialogChoicesContainer.GetChildren())
		{
			m_DialogChoicesContainer.RemoveChild(m_DialogChoicesContainer.GetChildren());
		}
	}

	bool ApplyQuestCondition(Quest qt)
	{
		if (!qt) return false;
		switch (qt.Type)
		{
			case "Delivery":
				DeliveryQuest(qt);
			break;
		}
		return true;
	}

	string GetMulticharacterName()
	{
		if (m_Player)
		{
			return m_Player.GetMultiCharactersPlayerName();
		}
		return string.Empty;
	}

	void DeliveryQuest(Quest temp)
	{
		Quest qt = temp;
		m_Player.RPCSingleParam(QRPC.REQUEST_GIVE_ITEMS, new Param1<ref array<ref Shipment>>(qt.Shipments), true, null);
	}

	void FinishQuest(int questID)
	{
		Quest qt = g_QM.GetQuestByID(questID);
		m_Player.RPCSingleParam(QRPC.REQUEST_DELIVERY_ITEMS, new Param2<ref array<ref Shipment>, int>(qt.Shipments,qt.QuestID), true, null);
		g_QM.CompeteQuest(qt);
	}



	void SetupFinishDialogs()
	{
		for (int i = 0; i < m_CurNPC.QuestFinishDialogs.Count(); i++)
		{
			QueFinDiag qfd = m_CurNPC.QuestFinishDialogs.Get(i);
			int forQuest = qfd.ForQuest;
			for (int j = 0; j < g_QM.AllQuests.Count(); j++)
			{
				int questID = g_QM.AllQuests.Get(j).QuestID;
				Quest qt = g_QM.GetQuestByID(questID);
				if (qt)
				{
					if (qt.QuestID == forQuest)
					{
						if (CheckQuestCondition(qt))
						{
							if (qt.CanDoneAnyway)
							{
								AddChoice(qfd.ChoiceMsg, qfd.MoveToDialog, 0, qfd.ForQuest, qfd.TeleportTo);
							}
							else
							{
								if (PlayerHasQuest(qt.QuestID))
								{
									AddChoice(qfd.ChoiceMsg, qfd.MoveToDialog, 0, qfd.ForQuest, qfd.TeleportTo);
								}
							}
						}
					}
				}
			}
		}
		g_QM.m_ExItems.Clear();
	}

	bool NPCHasQuest(int questID) // legacy
	{
		return m_CurNPC.NPCUnicID == questID;
	}

	bool PlayerHasQuest(int questID)
	{
		for (int i = 0; i < g_QM.m_QuestManagerStg.QuestStatusArr.Count(); i++)
		{
			if (g_QM.m_QuestManagerStg.QuestStatusArr.Get(i).QuestID == questID) return true;
		}
		return false;
	}

	bool CheckQuestCondition(Quest qt)
	{
		bool flag = false;
		if (!qt) return flag;

		switch (qt.Type)
		{
			case "Delivery":
				flag = CheckDeliveryCondition(qt);
			break;
			case "FindAndDelivery":
				flag = CheckDeliveryCondition(qt);
			break;
			case "KillSomething":
				flag = CheckKillCondition(qt);
			break;
		}
		if (!qt.CanDoneAnyway)
		{
			if (!PlayerHasQuest(qt.QuestID)) return false;
		}
		return flag;
	}

	bool CheckDeliveryCondition(Quest qt)
	{
		map<string,int> ItemsNeeded = new map<string, int>();
		int shipCount = qt.Shipments.Count();
		Shipment sm;
		for (int i = 0; i < shipCount; i++ )
		{
			sm = qt.Shipments.Get(i);
			if (!ItemsNeeded.Contains(sm.Classname))
			{
				ItemsNeeded.Insert(sm.Classname, sm.Count);
			}
			else
			{
				int nowQuant = ItemsNeeded.Get(sm.Classname);
				ItemsNeeded.Set(sm.Classname, (nowQuant + sm.Count));
			}
		}

		for (int j = 0; j < shipCount; j++)
		{
			sm = qt.Shipments.Get(j);
			if (g_QM.m_ExItems.Get(sm.Classname) < ItemsNeeded.Get(sm.Classname))
			{
				return false;
			}
		}

		return true;
	}

	bool CheckKillCondition(Quest qt)
	{
		for (int i = 0; i < g_QM.m_QuestManagerStg.QuestStatusArr.Count(); i++)
		{
			AppliedQuestStatus qs = g_QM.m_QuestManagerStg.QuestStatusArr.Get(i);
			if (qt.QuestID == qs.QuestID)
			{
				for (int j = 0; j < qs.SaveCountKilledSomething.Count(); j++)
				{
					QKillTgt qkt = qs.SaveCountKilledSomething.Get(j);
					int needDead = qkt.Count;
					if (needDead > qkt.KillCount)
					{
						return false;
					}
				}
			}
		}
		return true;
	}

	void ScanItems()
    {
        if (!m_Player)
        {
            return;
        }

		array<EntityAI> itemsArray = new array<EntityAI>;
		m_Player.GetInventory().EnumerateInventory(InventoryTraversalType.PREORDER, itemsArray);
		
        int quant;
        
        for (int c = 0; c < itemsArray.Count(); c++)
        {
            ItemBase cargoItemIB;
			if ( Class.CastTo(cargoItemIB, itemsArray.Get(c)) && cargoItemIB.IsItemBase() )
            {
                if (cargoItemIB.IsRuined()) continue;
                if (cargoItemIB.HasQuantity())
                {
                    quant = cargoItemIB.GetQuantity();
                }
                else
                {
                    quant = 1;
                }

                if (!g_QM.m_ExItems.Contains(cargoItemIB.GetType()))
                {
                    g_QM.m_ExItems.Insert(cargoItemIB.GetType(), quant);
                }
                else
                {
                    int nowQuant = g_QM.m_ExItems.Get(cargoItemIB.GetType());
                    g_QM.m_ExItems.Set(cargoItemIB.GetType(), (nowQuant + quant));
                }
            }
        }
    }

}