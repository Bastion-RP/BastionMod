class ActionTurnOffRadio: ActionInteractBase
{
	void ActionTurnOffRadio()
	{
		m_CommandUID        = DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		m_StanceMask        = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
	}

	override string GetText()
	{
		return "#turn_off";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		Object target_object = target.GetObject();
		if ( player && target_object )
		{
			brp_cassetteradio radio = brp_cassetteradio.Cast( target_object );
			
			if ( radio.HasEnergyManager() && radio.GetCompEM().CanSwitchOff() )
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
				radio.GetCompEM().SwitchOff();
				radio.SetSongPlaying(false);
			}
		}
	}
};