class ActionAddIEDToDetonator : ActionInteractBase
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
		RemoteDetonator remote = RemoteDetonator.Cast( item );
		RemoteIED IED = RemoteIED.Cast( target.GetObject() );

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
		RemoteDetonator remote = RemoteDetonator.Cast( action_data.m_MainItem );
		RemoteIED IED = RemoteIED.Cast( action_data.m_Target.GetObject() );

		if ( !remote || !IED ) return;

		remote.AddBomb( IED );
	}

	override void OnStartServer( ActionData action_data )
	{
		RemoteDetonator remote = RemoteDetonator.Cast( action_data.m_MainItem );
		RemoteIED IED = RemoteIED.Cast( action_data.m_Target.GetObject() );

		if ( !remote || !IED ) return;

		remote.AddBomb( IED );
	}
	
	override void CreateAndSetupActionCallback( ActionData action_data )
	{
		super.CreateAndSetupActionCallback( action_data );
	}
}