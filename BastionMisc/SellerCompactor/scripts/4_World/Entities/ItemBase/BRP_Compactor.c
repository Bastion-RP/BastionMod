modded class BRP_Compactor
{
    void BRP_Compactor()
    {
        RegisterNetSyncVariableBool("m_IsSoundSynchRemote");
    }

    override bool IsInventoryVisible()
    {
		return true;
	}

	override bool IsSeller()
	{
		return true;
	}

    override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
				
		if ( IsSoundSynchRemote() )
		{
			//[COMPACTOR] trade sound here
		}
    }
}

class BRP_HolocomBooth : ItemBase 
{
	override bool IsSeller()
	{
		return true;
	}
}