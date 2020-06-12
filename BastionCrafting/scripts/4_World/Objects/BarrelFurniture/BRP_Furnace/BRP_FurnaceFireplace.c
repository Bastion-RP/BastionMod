class BRP_FurnaceFireplace extends BarrelHoles_ColorBase
{
	void BRP_FurnaceFireplace()
	{
		//Particles - default for FireplaceBase
		PARTICLE_FIRE_START 	= ParticleList.BARREL_FIRE_START;
		PARTICLE_SMALL_FIRE 	= ParticleList.BARREL_SMALL_FIRE;
		PARTICLE_NORMAL_FIRE	= ParticleList.BARREL_NORMAL_FIRE;
		PARTICLE_SMALL_SMOKE 	= ParticleList.BARREL_SMALL_SMOKE;
		PARTICLE_NORMAL_SMOKE	= ParticleList.BARREL_NORMAL_SMOKE;
		//PARTICLE_SMALL_SMOKE 	= ParticleList.INVALID;
		//PARTICLE_NORMAL_SMOKE	= ParticleList.INVALID;
		PARTICLE_FIRE_END 		= ParticleList.BARREL_FIRE_END;
		PARTICLE_STEAM_END		= ParticleList.BARREL_FIRE_STEAM_2END;
	}
	
	override void EEInit()
	{
		super.EEInit();
		
		//hide in inventory
		GetInventory().LockInventory(HIDE_INV_FROM_SCRIPT);
	}
	
	override bool IsBarrelWithHoles()
	{
		return true;
	}
	
	//Destroy
	override void DestroyFireplace()
	{
		//delete object
		//GetGame().ObjectDelete( this );
	}
	
	//ATTACHMENTS
	override bool CanReceiveAttachment( EntityAI attachment, int slotId )
	{
		ItemBase item = ItemBase.Cast( attachment );
		
		//kindling items
		if ( IsKindling ( item ) && IsOpen() )
		{
			return true;
		}
		
		//fuel items
		if ( IsFuel ( item ) && IsOpen() )
		{
			return true;
		}
		
		//cookware
		if ( item.Type() == ATTACHMENT_COOKING_POT && IsOpen() )
		{
			return true;
		}
		
		return false;
	}
	
	override bool CanDisplayAttachmentSlot( string slot_name )
	{
		/*//super
		if( !super.CanDisplayAttachmentSlot( slot_name ) )
		{
			return false;
		}
		//*/
		return IsOpen();
	}

	override bool CanDisplayAttachmentCategory( string category_name )
	{
		/*//super
		if( !super.CanDisplayAttachmentCategory( category_name ) )
		{
			return false;
		}
		//*/
		return IsOpen();
	}
	
	//CONDITIONS
	//this into/outo parent.Cargo
	override bool CanPutInCargo( EntityAI parent )
	{
		return false;
	}
	
	//hands
	override bool CanPutIntoHands( EntityAI parent )
	{
		return false;
	}
	
	override bool IsThisIgnitionSuccessful( EntityAI item_source = NULL )
	{
		//check kindling
		if ( !HasAnyKindling() && IsOpen() )
		{
			return false;
		}
		
		//check roof
		if ( !HasEnoughRoomForFireAbove() )
		{
			return true;
		}
		
		//check surface
		if ( IsOnWaterSurface() )
		{
			return true;
		}
		
		//check wetness/rain/wind
		if ( IsWet() || IsRainingAbove() || FireplaceBase.IsWindy() )
		{
			return true;
		}
		
		return true;	
	}
	
	//Check if there is enough room for smoke above fireplace
	override bool HasEnoughRoomForSmokeAbove( out float actual_height )
	{
		return false;
	}	
	
	//ACTIONS
	override void Open()
	{
		m_Openable.Open();
		GetInventory().UnlockInventory(HIDE_INV_FROM_SCRIPT);

		SoundSynchRemote();
		//SetSynchDirty(); //! called also in SoundSynchRemote - TODO
		UpdateVisualState();
	}
	
	override void Close()
	{
		m_Openable.Close();
		GetInventory().LockInventory(HIDE_INV_FROM_SCRIPT);
		
		SoundSynchRemote();
		//SetSynchDirty(); //! called also in SoundSynchRemote - TODO
		UpdateVisualState();
	}
	
	//particles
	override bool CanShowSmoke()
	{
		//return IsOpen();
		return false;
	}
	
	//small smoke
	protected void ParticleSmallSmokeStart()
	{
		
	}
	
	protected void ParticleSmallSmokeStop()
	{
		
	}
	
	//normal smoke
	protected void ParticleNormalSmokeStart()
	{
		
	}
	
	protected void ParticleNormalSmokeStop()
	{
		
	}
}
