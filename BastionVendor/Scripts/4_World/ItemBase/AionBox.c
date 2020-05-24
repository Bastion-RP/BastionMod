class BRP_AIONBox_Base : ItemBase 
{  
	bool ContainsOnlyAION()
	{   
        if ( this.GetInventory().GetCargo() != NULL )
        {
            int item_count = this.GetInventory().GetCargo().GetItemCount();	
            
            for (int i = 0; i < item_count; i++)
            {
                CargoBase cargo = this.GetInventory().GetCargo();
                ItemBase item = ItemBase.Cast(cargo.GetItem(i));	
                if(!item.IsKindOf("BRP_AION"))
                    return false;
            }
        }
        return true;
	}

    override void SetActions()
	{
		super.SetActions();
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
		AddAction(ActionRefillAIONVendingMachine);
	}
};

class BRP_AIONBox_Empty : BRP_AIONBox_Base {};

class BRP_AIONBox_Full : BRP_AIONBox_Base 
{
    bool m_HasAION = false;

    void BRP_AIONBox_Full()
    {        
        RegisterNetSyncVariableBool("m_HasAION");
    }

    override void OnStoreSave( ParamsWriteContext ctx )
	{   
		super.OnStoreSave(ctx);        
        ctx.Write(m_HasAION);
	}
	
	override bool OnStoreLoad( ParamsReadContext ctx, int version )
	{
		if ( !super.OnStoreLoad( ctx, version ) )
			return false;
        
        if (!ctx.Read(m_HasAION))
            m_HasAION = false;

        SynchronizeValues();     
		
		return true;
	}

    void SynchronizeValues()
	{
		if (GetGame().IsServer())
			SetSynchDirty();
    }

    override void EEInit()
	{		
		super.EEInit();
        if(!GetGame().IsClient())
            GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( SpawnAION, 200, false );        
	}

    void SpawnAION()
    {   
        if(m_HasAION) return;
        if(GetNumberOfItems() < 1)
        {
            for (int i = 0; i < 19; i++)
            {
                this.GetInventory().CreateInInventory("BRP_AION");
            }
            m_HasAION = true;
        }
    }
};