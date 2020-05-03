class BastionPublicAnnouncement
{
    ref Timer m_AmbientTimer;

	void BastionPublicAnnouncement()
	{
		GetRPCManager().AddRPC( "BastionPA", "PlayOnServer", this, SingleplayerExecutionType.Both ); 
	}

    void OnInit()
    {
		m_AmbientTimer = new Timer();

        //TODO: Expose timer to json
        m_AmbientTimer.Run(60, this, "GetRandomAnnouncement", NULL, true);
    }

	void PlayOnServer( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target )
	{
    	Param1< string > data;
    	if ( !ctx.Read( data ) )
			return;

		Land_Power_Pole_Wood1_Lamp_Amp.m_Invoker.Invoke( data.param1 );
		Land_Power_Pole_Wood1_Amp.m_Invoker.Invoke( data.param1 );
		Land_Power_Pole_Conc4_Lamp_Amp.m_Invoker.Invoke( data.param1 );
		Land_Power_Pole_Conc1_Amp.m_Invoker.Invoke( data.param1 );
		Land_Lamp_City1_amp.m_Invoker.Invoke( data.param1 );
	}

	void GetRandomAnnouncement()
    {
        TStringArray soundArray = 
        { 
            "BastionPA1", 
            "BastionPA2", 
        };

		GetRPCManager().SendRPC( "BastionPA", "PlayOnServer", new Param1< string >( soundArray.GetRandomElement() ) );
	}
}

static ref BastionPublicAnnouncement g_Announcements;
static ref BastionPublicAnnouncement GetAnnouncements()
{
    if ( !g_Announcements )
    {
        g_Announcements = new ref BastionPublicAnnouncement();
    }
    
    return g_Announcements;
}