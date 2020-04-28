modded class CarScript
{
    bool m_IsInSafeZone;

    static ref set< CarScript > m_Vehicles = new set< CarScript >;

    void CarScript()
    {
		m_Vehicles.Insert( this );
    }

	void ~CarScript()
	{
        int i = m_Vehicles.Find( this );
		if ( i >= 0 )
		{
			m_Vehicles.Remove( i );
		}
	}
    
	static set< CarScript > GetAll()
	{
		return m_Vehicles;
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