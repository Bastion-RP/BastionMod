class ActionUnpackShowerKitCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.TEST_BLOOD);
	}
};

class ActionUnpackShowerKit: ActionContinuousBase
{
	void ActionUnpackShowerKit()
	{
		m_CallbackClass = ActionUnpackShowerKitCB;
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
		return "Deploy Shower kit";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		return true;
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
    if ( action_data.m_MainItem && action_data.m_MainItem.GetHierarchyRootPlayer() == action_data.m_Player )
		{
      action_data.m_Player.DropItem(action_data.m_MainItem);
      action_data.m_MainItem.Delete();

      vector pos = action_data.m_Player.GetPosition() + Vector(1,0,1);
      ItemBase sh = ItemBase.Cast( GetGame().CreateObjectEx("DecontaminationShower", pos, ECE_PLACE_ON_SURFACE) );
		}
  }
};
