class ActionGetRadClotheLevelCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousDisinfectPlant(UAQuantityConsumed.GARDEN_DISINFECT_PLANT);
	}
};

class ActionGetRadClotheLevel: ActionContinuousBase
{
	void ActionGetRadClotheLevel()
	{
		m_CallbackClass = ActionGetRadClotheLevelCB;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;

		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_SPRAYPLANT;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
		m_FullBody = true;
	}

	override void CreateConditionComponents()
	{
		m_ConditionTarget = new CCTNonRuined(UAMaxDistances.DEFAULT);
		m_ConditionItem = new CCINonRuined;
	}

	override string GetText()
	{
		return "Get Radiation Quantity";
	}

	override bool ActionCondition ( PlayerBase player, ActionTarget target, ItemBase item )
	{
		ItemBase m_item;
		if ( Class.CastTo(m_item,  target.GetObject() ) && !item.IsRuined() )
		{
				if ( item.GetCompEM().IsWorking() )
				{
					return true;
				}
		}
		return false;
	}

	override void OnEndServer( ActionData action_data )
	{
		ItemBase m_item;
		if ( Class.CastTo(m_item, action_data.m_Target.GetObject()) )
		{
      string message = "Radiation Quantity: " + m_item.GetRadAgentQuantity().ToString();
  		NotificationSystem.SendNotificationToPlayerIdentityExtended(action_data.m_Player.GetIdentity(), 3, "Radiation Zone", message, "BastionMod/BastionDangerousZone/images/radiation.paa");
		}
	}
};
