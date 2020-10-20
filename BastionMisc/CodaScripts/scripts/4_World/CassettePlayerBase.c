class coda_cassetteradio extends ItemBase
{

    ref protected EffectSound 						m_DeployLoopSound;
    protected bool j_IsPlaying;

    void coda_cassetteradio()
    {
        SetSongPlaying(false);
        RegisterNetSyncVariableBool("j_IsPlaying"); 
    }

	//--- COMMON
	bool CanOperate()
	{
		return GetCompEM().IsSwitchedOn();	
	}
	
	bool HasCassetteTape()
	{
		int slot_id = InventorySlots.GetSlotIdFromString("coda_cassette");
        brp_cassette_base tape = brp_cassette_base.Cast( GetInventory().FindAttachment(slot_id) );
		if(tape)
		{
			return true;
		}
		return false;	
	}
	
	//--- POWER EVENTS
	override void OnSwitchOn()
	{
		//switch device on
		SwitchOn ( true );
	}

	override void OnSwitchOff()
	{
		//switch device off
		SwitchOn ( false );
        StopMusic();
	}

	override void OnWorkStop()
	{
		//turn off device
		GetCompEM().SwitchOff();
	}
	
	//--- RADIO ACTIONS
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionTurnOnRadio);
        AddAction(ActionRadioPlay);
		AddAction(ActionRadioStop);
		AddAction(ActionTurnOffRadio);
	}

	//--- RADIO SYNC BOOL
    void SetSongPlaying(bool pState)
    {
        j_IsPlaying = pState;
        SetSynchDirty();
    }
    
    bool SongIsPlaying()
    {
        return j_IsPlaying;
    }

	//--- USAGE FUNCTIONS
    void PlayMusic()
    {
        if ( GetGame().IsMultiplayer() && GetGame().IsClient() || !GetGame().IsMultiplayer() )
		{		
			m_DeployLoopSound = SEffectManager.PlaySound( GetMusicSoundset(), GetPosition() );
		}
    }

    void StopMusic()
    {
        if ( GetGame().IsMultiplayer() && GetGame().IsClient() || !GetGame().IsMultiplayer() )
		{	
			m_DeployLoopSound.SoundStop();
			delete m_DeployLoopSound;
		}
    }

    override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
			
		if ( !SongIsPlaying() && GetCompEM().CanSwitchOff())
		{
			PlayMusic();
		}
					
		if ( SongIsPlaying() )
		{
			StopMusic();
		}
	}

    string GetMusicSoundset()
	{
        int slot_id = InventorySlots.GetSlotIdFromString("coda_cassette");
        brp_cassette_base tape = brp_cassette_base.Cast( GetInventory().FindAttachment(slot_id) );

		return tape.SongToPlay();
	}

    override bool CanReleaseAttachment(EntityAI attachment)
	{
		if ( GetCompEM().IsWorking() )
		{
			return false;
		}
		return true;
	}

    override bool CanPutInCargo( EntityAI parent )
	{	
		if ( GetCompEM().IsWorking() )
		{
			return false;
		}
		return true;
	}

	override bool CanPutIntoHands(EntityAI parent)
	{
		if ( GetCompEM().IsWorking() )
		{
			return false;
		}
		return true;
	}
	
};


