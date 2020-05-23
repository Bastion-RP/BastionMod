class ActionAddIEDToDetonator : ActionContinuousBase
{
	void ActionAddIEDToDetonator()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_PICKUP_HANDS;
	}
	
	override typename GetInputType()
	{
		return ContinuousInteractActionInput;
	}
	
	override bool HasProgress()
	{
		return false;
	}

	override string GetText()
	{
		return "Add IED to Detonator";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		BRP_RemoteDetonator remote = BRP_RemoteDetonator.Cast( item );
		BRP_RemoteIED IED = BRP_RemoteIED.Cast( target.GetObject() );

		if ( !IED || !remote ) return false;
		//if ( IED.IsInactive() ) return false;
		if ( remote.HasBomb( IED ) ) return false;

		return true;
	}
	
	override bool CanContinue( ActionData action_data )
	{
		return true;
	}

	override void OnStartClient( ActionData action_data )
	{
		BRP_RemoteDetonator remote = BRP_RemoteDetonator.Cast( action_data.m_MainItem );
		BRP_RemoteIED IED = BRP_RemoteIED.Cast( action_data.m_Target.GetObject() );

		if ( !remote || !IED ) return;

		remote.AddBomb( IED );
	}

	override void OnStartServer( ActionData action_data )
	{
		BRP_RemoteDetonator remote = BRP_RemoteDetonator.Cast( action_data.m_MainItem );
		BRP_RemoteIED IED = BRP_RemoteIED.Cast( action_data.m_Target.GetObject() );

		if ( !remote || !IED ) return;

		remote.AddBomb( IED );
	}
	
	override void CreateAndSetupActionCallback( ActionData action_data )
	{
		super.CreateAndSetupActionCallback( action_data );
	}
}