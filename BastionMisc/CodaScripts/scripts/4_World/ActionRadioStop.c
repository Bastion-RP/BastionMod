class ActionRadioStop: ActionInteractBase
{
	void ActionRadioPlay()
	{
		m_CommandUID        = DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		m_StanceMask        = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
	}

	override string GetText()
	{
		return "Play/Stop";
	}
		
	override bool ActionCondition ( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object target_object = target.GetObject();

		if ( player && target_object)
		{
			brp_cassetteradio radio = brp_cassetteradio.Cast( target_object );
            EntityAI tape = EntityAI.Cast(radio.FindAttachmentBySlotName("coda_cassette"));
		
			if ( radio.HasEnergyManager() && radio.GetCompEM().CanSwitchOff() )
			{
                if( tape && radio.SongIsPlaying() )
                {
                    return true;
                }
			}
		}
		
		return false;
	}
		
	override void OnExecuteServer( ActionData action_data )
	{
		brp_cassetteradio radio = brp_cassetteradio.Cast( action_data.m_Target.GetObject() );

        radio.SetSongPlaying(false);
	}
};