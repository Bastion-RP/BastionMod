class ActionRefillAIONVendingMachineCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime( 30 );
	}
};

class ActionRefillAIONVendingMachine: ActionContinuousBase
{
	void ActionRefillAIONVendingMachine()
	{
		m_CallbackClass = ActionRefillAIONVendingMachineCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
		
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNonRuined( UAMaxDistances.BASEBUILDING );
	}

	override string GetText()
	{		
		return "Refill Vending Machine";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		Object targetObject = target.GetObject();
		if ( targetObject )
		{				
			BRP_AionVendor vendor = BRP_AionVendor.Cast( targetObject );
			BRP_AIONBox_Base box = BRP_AIONBox_Base.Cast( item );
			if(vendor && box && box.GetNumberOfItems() > 0 && box.ContainsOnlyAION())
				return true;
		}
		return false;
	}
	

	override void OnStartClient(ActionData action_data)
	{
		action_data.m_Player.GetItemAccessor().HideItemInHands(true);
	}
	
	override void OnStartServer(ActionData action_data)
	{
		action_data.m_Player.GetItemAccessor().HideItemInHands(true);
	}

	override void OnEndClient(ActionData action_data)
	{
		action_data.m_Player.GetItemAccessor().HideItemInHands(false);
	}
	
	override void OnEndServer( ActionData action_data )
	{
		action_data.m_Player.GetItemAccessor().HideItemInHands(false);
	}
		
	override void OnFinishProgressServer( ActionData action_data ) 
	{
		BRP_AIONBox_Base myItem = BRP_AIONBox_Base.Cast(action_data.m_MainItem);
		if (myItem)
			myItem.Delete();
	}	
};