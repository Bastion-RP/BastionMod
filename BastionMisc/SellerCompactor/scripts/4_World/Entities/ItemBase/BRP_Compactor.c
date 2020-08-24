modded class BRP_Compactor
{
    void BRP_Compactor()
    {
        RegisterNetSyncVariableBool("m_IsSoundSynchRemote");
    }

	override void SetActions() 
    {
        super.SetActions();
        AddAction(ActionSellItem);
    }

    override bool IsInventoryVisible()
    {
		return true;
	}

    override bool CanPutInCargo (EntityAI parent)
	{
		return false;
	}

    override bool CanPutIntoHands (EntityAI parent)
	{
		return false;
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