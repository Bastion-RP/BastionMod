modded class Weapon_Base {

    private bool        m_IsHacked;

    void Weapon_Base()
    {
        m_IsHacked = false;
        RegisterNetSyncVariableBool("m_IsHacked");
    }

    bool IsISFWeapon() {
        return false;
    }

    override void OnStoreSave( ParamsWriteContext ctx )
	{   
		super.OnStoreSave( ctx );
		ctx.Write( m_IsHacked );
	}
	
	override bool OnStoreLoad( ParamsReadContext ctx, int version )
	{
		if ( !super.OnStoreLoad( ctx, version ) )
			return false;
		
		if ( !ctx.Read( m_IsHacked ) )
		{
			m_IsHacked = false;		//set default
			return false;
		}
		return true;
	}
	
	override void AfterStoreLoad()
	{	
		super.AfterStoreLoad();		
		
		SetSynchDirty();
	}

    void SetHacked()
    {
        m_IsHacked = true;
        SetSynchDirty();
    }

    bool IsHacked()
    {
        return m_IsHacked;
    }
}