class ActionDecontaminationObjectCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousDisinfectPlant(UAQuantityConsumed.GARDEN_DISINFECT_PLANT);
	}
};

class ActionDecontaminationObject: ActionContinuousBase
{
	void ActionDecontaminationObject()
	{
		m_CallbackClass = ActionDecontaminationObjectCB;
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
		return "#apply";
	}

	override bool ActionCondition ( PlayerBase player, ActionTarget target, ItemBase item )
	{
		ItemBase m_item;
		if ( Class.CastTo(m_item,  target.GetObject() ) && !item.IsRuined() )
		{
				if ( item.GetQuantity() >= 50 )
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
      m_item.InjectRadAgent(0);
      action_data.m_MainItem.AddQuantity(-50);
		}
	}
};
