class ActionArmIEDCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime( 5 );
	}
};

class ActionArmIED: ActionContinuousBase
{			 
	void ActionDisarmIED()
	{
		m_CallbackClass		= ActionLockDoorsCB;
		m_CommandUID 		= DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
		m_FullBody 			= true;
		m_StanceMask 		= DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNone;
	}
	
	override string GetText()
	{
		return "Arm IED";
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		BRP_RemoteIED IED = BRP_RemoteIED.Cast( target.GetObject() );

		if ( !IED ) return false;
		if ( !IED.IsDisarmed() ) return false;

		return true;
	}
	
	override void OnFinishProgressServer( ActionData action_data )
	{
		BRP_RemoteIED IED = BRP_RemoteIED.Cast( action_data.m_Target.GetObject() );

		if ( !IED ) return;

		IED.ArmIED();
	}
};