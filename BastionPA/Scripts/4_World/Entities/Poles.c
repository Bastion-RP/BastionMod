modded class Land_Power_Pole_Wood1_Lamp_Amp
{
	static ref ScriptInvoker m_Invoker = new ScriptInvoker;

    void Land_Power_Pole_Wood1_Lamp_Amp()
    {
        m_Invoker.Insert( PublicAnnouncement );
    }

    void ~Land_Power_Pole_Wood1_Lamp_Amp()
    {
        m_Invoker.Remove( PublicAnnouncement );
    }

    private void PublicAnnouncement( string soundName )
    {
        EffectSound sound =	SEffectManager.PlaySound( soundName, GetPosition() );

        sound.SetSoundAutodestroy( true );
    }
}

modded class Land_Power_Pole_Wood1_Amp
{
	static ref ScriptInvoker m_Invoker = new ScriptInvoker;

    void Land_Power_Pole_Wood1_Amp()
    {
        m_Invoker.Insert( PublicAnnouncement );
    }

    void ~Land_Power_Pole_Wood1_Amp()
    {
        m_Invoker.Remove( PublicAnnouncement );
    }

    private void PublicAnnouncement( string soundName )
    {
        EffectSound sound =	SEffectManager.PlaySound( soundName, GetPosition() );

        sound.SetSoundAutodestroy( true );
    }
}

modded class Land_Power_Pole_Conc4_Lamp_Amp
{
	static ref ScriptInvoker m_Invoker = new ScriptInvoker;

    void Land_Power_Pole_Conc4_Lamp_Amp()
    {
        m_Invoker.Insert( PublicAnnouncement );
    }

    void ~Land_Power_Pole_Conc4_Lamp_Amp()
    {
        m_Invoker.Remove( PublicAnnouncement );
    }

    private void PublicAnnouncement( string soundName )
    {
        EffectSound sound =	SEffectManager.PlaySound( soundName, GetPosition() );

        sound.SetSoundAutodestroy( true );
    }
}

modded class Land_Power_Pole_Conc1_Amp
{
	static ref ScriptInvoker m_Invoker = new ScriptInvoker;

    void Land_Power_Pole_Conc1_Amp()
    {
        m_Invoker.Insert( PublicAnnouncement );
    }

    void ~Land_Power_Pole_Conc1_Amp()
    {
        m_Invoker.Remove( PublicAnnouncement );
    }

    private void PublicAnnouncement( string soundName )
    {
        EffectSound sound =	SEffectManager.PlaySound( soundName, GetPosition() );

        sound.SetSoundAutodestroy( true );
    }
}   

modded class Land_Lamp_City1_amp
{
	static ref ScriptInvoker m_Invoker = new ScriptInvoker;

    void Land_Lamp_City1_amp()
    {
        m_Invoker.Insert( PublicAnnouncement );
    }

    void ~Land_Lamp_City1_amp()
    {
        m_Invoker.Remove( PublicAnnouncement );
    }

    private void PublicAnnouncement( string soundName )
    {
        EffectSound sound =	SEffectManager.PlaySound( soundName, GetPosition() );

        sound.SetSoundAutodestroy( true );
    }
}