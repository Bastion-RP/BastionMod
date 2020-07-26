class ActionTestForRadiationSelfCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.TEST_BLOOD);
	}
};

class ActionTestForRadiationSelf: ActionContinuousBase
{
	void ActionTestForRadiationSelf()
	{
		m_CallbackClass = ActionTestForRadiationSelfCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_CRAFTING;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTSelf;
	}

	override bool HasTarget()
	{
		return false;
	}

	override string GetText()
	{
		return "#check_radiation";
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
		string message = "Total Radiation Exposure : " + action_data.m_Player.GetSingleAgentCount(DZAgents.RADSICK).ToString();
		NotificationSystem.SendNotificationToPlayerIdentityExtended(action_data.m_Player.GetIdentity(), 3, "Radiation Zone", message, "BastionDangerousZone/images/radiation.paa");

		//action_data.m_MainItem.SetQuantity(action_data.m_MainItem.GetQuantity() - 20);
	}
};
