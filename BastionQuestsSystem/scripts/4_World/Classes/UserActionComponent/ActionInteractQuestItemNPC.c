class ActionInteractQuestItemNPC : ActionInteractBase
{
	void ActionInteractQuestItemNPC()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_HUDCursorIcon = CursorIcons.CloseHood;
	}
	
	override void CreateConditionComponents()  
	{
		// m_ConditionTarget = new CCTMan(5);
		// m_ConditionItem = new CCINone;
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTObject(UAMaxDistances.DEFAULT);
	}

	

	override string GetText()
	{
		return "Talk";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		ItemBase ntarget = ItemBase.Cast(  target.GetObject() );
		if(ntarget && (ntarget.GetQuestID() > -1))
		{
			return true;
		}
		return false;
	}
	
	override void OnExecuteClient( ActionData action_data )
	{
		ItemBase ntarget = ItemBase.Cast( action_data.m_Target.GetObject() );
		string message;
		if ( ntarget)
		{
			int ID = ntarget.GetQuestID();
			for (int i = 0; i < g_QM.NPCArray.Count(); i++)
			{
				NPC npc = g_QM.NPCArray.Get(i);
				if (ID == npc.NPCUnicID)
				{
					g_QM.SetQuestNPC(npc);
					g_QM.RequestNPCTalk();
					break;
				}
			}
		}
	}
	
}