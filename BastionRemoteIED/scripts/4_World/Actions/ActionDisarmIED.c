class ActionDisarmIEDCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime( 5 );
	}
};

class ActionDisarmIED: ActionContinuousBase
{			 
	void ActionDisarmIED()
	{
		m_CallbackClass		= ActionLockDoorsCB;
		m_CommandUID 		= DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionTarget = new CCTNonRuined( UAMaxDistances.DEFAULT );
		m_ConditionItem = new CCINonRuined;
	}
	
	override string GetText()
	{
		return "Disarm IED";
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		RemoteIED IED = RemoteIED.Cast( target.GetObject() );

		if ( !IED ) return false;
		if ( IED.IsDisarmed() ) return false;

		return true;
	}
	
	override void OnFinishProgressServer( ActionData action_data )
	{
		RemoteIED IED = RemoteIED.Cast( action_data.m_Target.GetObject() );

		if ( !IED ) return;

		IED.DisarmIED();
	}
};