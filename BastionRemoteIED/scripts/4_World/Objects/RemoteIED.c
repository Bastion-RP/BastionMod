class BRP_RemoteIED : TrapBase
{
	bool disarmed;

	void BRP_RemoteIED()
	{
		disarmed = false;
		RegisterNetSyncVariableBool( "disarmed" );
	}

	override void OnStoreSave( ParamsWriteContext ctx )
	{
		super.OnStoreSave( ctx );

		ctx.Write( disarmed );
	}

	override bool OnStoreLoad( ParamsReadContext ctx, int version )
	{
		if ( !super.OnStoreLoad(ctx, version) )
			return false;

		if ( !ctx.Read( disarmed ) )
			return false;

		return true;
	}

	bool IsDisarmed()
	{
		return disarmed;
	}

	void ArmIED()
	{
		disarmed = false;
		SetSynchDirty();
	}

	void DisarmIED()
	{
		disarmed = true;
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

	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" ) 
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