class ActionPutCorpseInBagCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.DEFAULT_DECONSTRUCT);
	}
};

class ActionPutCorpseInBag: ActionContinuousBase
{
	void ActionPutCorpseInBag()
	{
		m_CallbackClass = ActionPutCorpseInBagCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
		
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNone;
	}

	override string GetText()
	{		
		return "Put corpse in body bag";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		Object targetObject = target.GetObject();
		if ( targetObject )
		{
			BRP_StaticGraves myItem = BRP_StaticGraves.Cast(targetObject);
			if(myItem)					
                return true;
		}
		return false;
	}
		
	override void OnFinishProgressServer( ActionData action_data ) 
	{
		vector playerPos = action_data.m_Player.GetPosition();

        BRP_StaticGraves myItem = BRP_StaticGraves.Cast(action_data.m_Target.GetObject());
        if(!myItem)
            return;

		action_data.m_MainItem.Delete();

		GetGame().CreateObject(BastionBodyBagConst.bodyBagItem, playerPos);
	}	
};