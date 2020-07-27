class ActionSearchObjectCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(5);
	}
}

class ActionSearchObject : ActionContinuousBase
{
	void ActionSearchObject()
	{
		m_CallbackClass = ActionSearchObjectCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionTarget = new CCTCursor(UAMaxDistances.DEFAULT);
		m_ConditionItem = new CCINone;
	}
	
	override string GetText()
	{
		return "Search";
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if ( GetGame().IsMultiplayer() && GetGame().IsServer() )
			return true;
		
		SearchableBase schObject = SearchableBase.Cast(target.GetObject());
		if (schObject && schObject.CanSearch())
		{
			return true;
		}
		return false;
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
		vector position = action_data.m_Player.GetPosition();
		SearchableBase obj = SearchableBase.Cast(action_data.m_Target.GetObject());
		obj.DoSearch(position);
	}
}