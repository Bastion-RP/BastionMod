modded class ZombieBase
{
    bool m_IsInSafeZone;

    static ref set< ZombieBase > m_Zombies = new set< ZombieBase >;

    void ZombieBase()
    {
		m_Zombies.Insert( this );
    }

	void ~ZombieBase()
	{
        int i = m_Zombies.Find( this );
		if ( i >= 0 )
		{
			m_Zombies.Remove( i );
		}
	}
    
	static set< ZombieBase > GetAll()
	{
		return m_Zombies;
	}

    void EnterSafeZone()
    {
        m_IsInSafeZone = true;

        GetGame().ObjectDelete(this);
    }

    void LeaveSafeZone()
    {
        m_IsInSafeZone = false;
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