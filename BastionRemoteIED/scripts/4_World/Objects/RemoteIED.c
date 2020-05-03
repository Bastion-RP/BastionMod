class BRP_RemoteIED : TrapBase
{
	bool m_Disarmed;

	void BRP_RemoteIED()
	{
		m_Disarmed = false;
		RegisterNetSyncVariableBool( "m_Disarmed" );
	}

	override void OnStoreSave( ParamsWriteContext ctx )
	{
		super.OnStoreSave( ctx );

		ctx.Write( m_Disarmed );
	}

	override bool OnStoreLoad( ParamsReadContext ctx, int version )
	{
		if ( !super.OnStoreLoad(ctx, version) )
			return false;

		if ( !ctx.Read( m_Disarmed ) )
			return false;

		return true;
	}

	bool IsDisarmed()
	{
		return m_Disarmed;
	}

	void ArmIED()
	{
		m_Disarmed = false;
		SetSynchDirty();
	}

	void DisarmIED()
	{
		m_Disarmed = true;
		SetSynchDirty();
	}

	void SnapOnObject( EntityAI victim )
	{
		return;
	}

	void OnSteppedOn( EntityAI victim )
	{
		return;
	}

	override void CreateTrigger()
	{
		return;
	}
	
	void ActivateIED()
	{
		m_WasActivatedOrDeactivated = true;
		
		m_IsInProgress = false;
		m_IsActive = true;
			
		if ( g_Game.IsServer() )
		{
			RefreshState();
			Synch(NULL);
		}
	}

	override void OnPlacementComplete( Man player ) 
	{		
		if ( GetGame().IsServer() )
		{
			ActivateIED();
		}		
	}

	override bool IsDeployable()
	{
		return true;
	}
	
	override string GetLoopDeploySoundset()
	{
		return "landmine_deploy_SoundSet";
	}

	override void SetActions()
	{
		super.SetActions();
		
		AddAction( ActionAddIEDToDetonator );
		AddAction( ActionTogglePlaceObject );
		AddAction( ActionActivateTrap );
		AddAction( ActionDeployObject );
	}
}