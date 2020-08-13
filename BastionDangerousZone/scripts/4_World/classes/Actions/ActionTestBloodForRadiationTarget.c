class ActionTestForRadiationTargetCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.SALINE);
	}
};

class ActionTestForRadiationTarget: ActionContinuousBase
{
	void ActionTestForRadiationTarget()
	{
		m_CallbackClass = ActionTestForRadiationTargetCB;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_MEDIUM;

		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_CRAFTING;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTMan(UAMaxDistances.DEFAULT);
	}

	override string GetText()
	{
		return "Get Radiation Level Target";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if ( item )
		{
			BRP_Dosimeter dos = BRP_Dosimeter.Cast(item);

			if ( dos  && dos.GetCompEM().IsWorking())
			{
					return true;
			}
			else return false;
		}
		return true;
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
		PlayerBase ntarget = PlayerBase.Cast( action_data.m_Target.GetObject() );
		string message = "Total Radiation Exposure : " + ntarget.GetSingleAgentCount(DZAgents.RADSICK).ToString();
		NotificationSystem.SendNotificationToPlayerIdentityExtended(ntarget.GetIdentity(), 3, "Radiation Zone", message, "BastionMod/BastionDangerousZone/images/radiation.paa");
		NotificationSystem.SendNotificationToPlayerIdentityExtended(action_data.m_Player.GetIdentity(), 3, "Radiation Zone", message, "BastionMod/BastionDangerousZone/images/radiation.paa");

		#ifdef DZDEBUG
		GetDZLogger().LogInfo("playerTarget:"+ntarget.GetIdentity().GetName()+"action_dosimeter:"+message);
		#endif
	}
};
