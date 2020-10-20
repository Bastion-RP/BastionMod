class ActionTurnOnRadio: ActionInteractBase
{
	void ActionTurnOnRadio()
	{
		m_CommandUID        = DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		m_StanceMask        = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
	}

	override string GetText()
	{
		return "#turn_on";
	}
		
	override bool ActionCondition ( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object target_object = target.GetObject();

		if ( player && target_object)
		{
			brp_cassetteradio radio = brp_cassetteradio.Cast( target_object );
		
			if ( radio.HasEnergyManager() && radio.GetCompEM().CanSwitchOn() && radio.HasCassetteTape() )
			{
				return true;
			}
		}
		
		return false;
	}
		
	override void OnExecuteServer( ActionData action_data )
	{
		brp_cassetteradio radio = brp_cassetteradio.Cast( action_data.m_Target.GetObject() );

		if ( radio.HasEnergyManager() )
		{
			if ( radio.GetCompEM().CanWork() )
			{
				radio.GetCompEM().SwitchOn();
			}
		}
	}
};