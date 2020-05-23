class QuestNPCData
{
    const private static string m_ProfilePath		= "$profile:\\Bastion\\Quests";

    ref NPC 					NPCElem;
    ref array<ref NPC>          MainDataArray;

    void QuestNPCData()
    {
        NPCElem = new NPC();
        MainDataArray = new array<ref NPC>();
    }

    void LoadAllNPCData()
    {
        for (int i = 1; i < (g_QD.m_GeneralSettings.NPCCount + 1); i++)
        {
            QuestNPCData QData = new QuestNPCData();
            if (FileExist(m_ProfilePath + "\\" + "Npc" + i.ToString() + ".json"))
            {
                string temp = m_ProfilePath + "\\" + "Npc" + i.ToString() + ".json";
                JsonFileLoader<QuestNPCData>.JsonLoadFile(m_ProfilePath + "\\" + "Npc" + i.ToString() + ".json", QData);
            }
            MainDataArray.Insert(QData.NPCElem);
        }
    }

    void SendAllData(PlayerBase player)
    {
        if (player)
        {
            for (int i = 0; i < MainDataArray.Count(); i++)
            {
                GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(this.SendPacket, 100, false, MainDataArray.Get(i), player); //optimization
            }
        }
    }

    void SendPacket(ref NPC npc, PlayerBase player)
    {
        player.RPCSingleParam(QRPC.SEND_NPC_DATA, new Param1<ref NPC>(npc), true, player.GetIdentity());
    }

	void SpawnAllNPCs()
	{
		for (int i = 0; i < MainDataArray.Count(); i++)
		{
			NPC npc = MainDataArray.Get(i);
			if (npc)
			{
				EntityAI ent = EntityAI.Cast(GetGame().CreateObject(npc.NPCType, vector.Zero, false));
				if (ent)
				{
					vector spawnPos = npc.NPCPos;
					spawnPos[1] = GetGame().SurfaceY(spawnPos[0], spawnPos[2]);
					ent.SetPosition(spawnPos);
					ent.SetOrientation(npc.NPCOri);
					PlayerBase 	playerNPC;
					ItemBase	itemNPC;
					if (ent.IsInherited(PlayerBase) && Class.CastTo(playerNPC, ent))
					{
						playerNPC.SetQuestNPC(npc.NPCUnicID);
						playerNPC.RemoveAllItems();
						Print("Spawn quest npc [player] "+spawnPos);
						for (int j = 0; j < npc.NPCClothing.Count(); j++)
						{
							playerNPC.GetInventory().CreateInInventory(npc.NPCClothing.Get(j));
						}
					}
					else if (ent.IsInherited(ItemBase) && Class.CastTo(itemNPC, ent))
					{
						Print("Spawn quest npc [item] "+spawnPos);
						itemNPC.SetQuestNPC(npc.NPCUnicID);
					}
				}
			}
		}
	}
}
ref QuestNPCData g_QND;