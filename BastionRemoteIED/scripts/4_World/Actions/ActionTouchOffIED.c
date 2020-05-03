class ActionTouchOffIED : ActionSingleUseBase
{
	int bombCount;

	void ActionTouchOffIED()
	{
		bombCount 		= 0;
	}

	override void CreateConditionComponents()  
	{	
		m_ConditionItem		= new CCINonRuined;
		m_ConditionTarget 	= new CCTNone;
	}

	override bool HasTarget()
	{
		return false;
	}
	
	override bool IsInstant()
	{
		return true;
	}
	
	override bool RemoveForceTargetAfterUse()
	{
		return false;
	}

	override string GetText()
	{
		return "Touch off " + bombCount + " bombs";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		BRP_RemoteDetonator 			remote 			= BRP_RemoteDetonator.Cast( item );
		ref array< ref BRP_RemoteIED > 	bombsInRange 	= remote.GetBombsInRange( player );
		int							bombArraySize	= bombsInRange.Count();

		if ( !remote )
		{
			Print("[RS][DEBUG] Could not find remote!");
			return false;
		}
		if ( bombArraySize == 0 )
		{
			Print("[RS][DEBUG] Bomb count == 0!");
			return false;
		}

		bombCount = bombArraySize;
		return true;
	}

	override void OnStartClient( ActionData action_data )
	{
		BRP_RemoteDetonator 			remote 			= BRP_RemoteDetonator.Cast( action_data.m_MainItem );
		ref array< ref BRP_RemoteIED > 	bombsInRange 	= remote.GetBombsInRange( action_data.m_Player );

		remote.DetonateBombsInRange( bombsInRange );
	}

	override void OnStartServer( ActionData action_data )
	{
		BRP_RemoteDetonator 			remote 			= BRP_RemoteDetonator.Cast( action_data.m_MainItem );
		ref array< ref BRP_RemoteIED > 	bombsInRange 	= remote.GetBombsInRange( action_data.m_Player );

		if ( !remote ) return;
		if ( bombsInRange.Count() == 0 ) return;

		remote.DetonateBombsInRange( bombsInRange );
	}
}