modded class PlayerBase
{
	bool m_IsHandsUp;

	override void Init()
	{
		super.Init();
		SetHandsUp(false);
		RegisterNetSyncVariableBool("m_IsHandsUp");  
	}

	void SetHandsUp(bool pState)
	{
		m_IsHandsUp = pState;
		SetSynchDirty();
	}
	
	bool HasHandsUp()
	{
		return m_IsHandsUp;
	}

	void SearchDuration()
	{
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater( SetHandsUp, 10000, false, false );
	}

	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionSearchSurrendered);
	}

	override bool CanManipulateInventory()
	{
		if( HasHandsUp() )
		{
			return true;
		}
		return super.CanManipulateInventory();
	}

	override bool CanReleaseAttachment (EntityAI attachment)
	{
		if( HasHandsUp() )
		{
			return false;
		}
		return super.CanReleaseAttachment(attachment);
	}
	
	override bool CanReleaseCargo (EntityAI cargo)
	{
		if( HasHandsUp() )
		{
			return false;
		}
		return super.CanReleaseCargo(cargo);
	}
};