class ActionPackShowerCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.TEST_BLOOD);
	}
};

class ActionPackShower: ActionContinuousBase
{
	void ActionPackShower()
	{
		m_CallbackClass = ActionPackShowerCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_CRAFTING;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;
	}

	override void CreateConditionComponents()
	{
    m_ConditionTarget = new CCTNonRuined(UAMaxDistances.DEFAULT);
		m_ConditionItem = new CCINonRuined;
	}

	override string GetText()
	{
		return "Pack Shower";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if ( target && target.GetObject().IsKindOf("DecontaminationShower"))
		{
      DecontaminationShower sh = DecontaminationShower.Cast(target.GetObject());
      if(sh.FindAttachmentBySlotName("ShowerTank") == NULL)
      {
        return true;
      }
			return false;
		}
		return false;
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
    if ( action_data.m_MainItem && action_data.m_MainItem.GetHierarchyRootPlayer() == action_data.m_Player )
		{
      action_data.m_Player.DropItem(action_data.m_MainItem);
      action_data.m_MainItem.Delete();

      ItemBase m_sh = ItemBase.Cast(action_data.m_Target.GetObject());
      m_sh.Delete();

      vector pos = action_data.m_Player.GetPosition() + Vector(1,0,1);
      ItemBase sh = ItemBase.Cast( GetGame().CreateObjectEx("ShowerKit", pos, ECE_PLACE_ON_SURFACE) );
		}
  }
};
