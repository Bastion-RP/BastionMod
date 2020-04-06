modded class PlayerBase
{
    bool m_IsInSafeZone;

    static ref set< PlayerBase > m_Players = new set< PlayerBase >;

    void PlayerBase()
    {
		m_Players.Insert( this );
    }

	void ~PlayerBase()
	{
        int i = m_Players.Find( this );
		if ( i >= 0 )
		{
			m_Players.Remove( i );
		}
	}
    
	static set< PlayerBase > GetAll()
	{
		return m_Players;
	}

    void EnterSafeZone()
    {
        m_IsInSafeZone = true;

        if (GetGame().IsServer())
        {
            SetAllowDamage( false );

            SetSynchDirty();
        }
    }

    void LeaveSafeZone()
    {
        m_IsInSafeZone = false;

        if (GetGame().IsServer())
        {
            SetAllowDamage( true );

            SetSynchDirty();
        }
    }

    bool IsInSafeZone()
    {
        return m_IsInSafeZone;
    }

    override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
    }
}