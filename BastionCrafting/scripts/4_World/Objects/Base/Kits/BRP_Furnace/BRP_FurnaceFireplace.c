class BRP_Furnace_Fireplace : FireplaceBase
{
	const string ANIMATION_OPENED = "LidOff";
	const string ANIMATION_CLOSED = "LidOn";
	bool _isOpenedOnClient = false;
	bool _hasFuel = false;
	ref OpenableBehaviour _openable;
	ref BST_FurnaceHandler _furnaceHandler;

	void BRP_Furnace_Fireplace()
	{
		PARTICLE_FIRE_START = ParticleList.BARREL_FIRE_START;
		PARTICLE_SMALL_FIRE = ParticleList.BARREL_SMALL_FIRE;
		PARTICLE_NORMAL_FIRE = ParticleList.BARREL_NORMAL_FIRE;
		PARTICLE_SMALL_SMOKE = ParticleList.BARREL_SMALL_SMOKE;
		PARTICLE_NORMAL_SMOKE = ParticleList.BARREL_NORMAL_SMOKE;
		PARTICLE_FIRE_END = ParticleList.BARREL_FIRE_END;
		PARTICLE_STEAM_END = ParticleList.BARREL_FIRE_STEAM_2END;
		_openable = new OpenableBehaviour(false);
		_furnaceHandler = new BST_FurnaceHandler(this);

		//synchronized variables
		RegisterNetSyncVariableBool("_openable.m_IsOpened");
		RegisterNetSyncVariableBool("_hasFuel");
	}

	override void AfterStoreLoad()
	{
		m_IsBurning = false;
		_hasFuel = _furnaceHandler.HasFuel();

		super.AfterStoreLoad();
	}

	override string Get_KitName()
	{
		return "BRP_Furnace_Kit";
	}

	void StartSmelting()
	{
		if (!GetGame().IsMultiplayer() || !GetGame().IsServer())
		{
			return;
		}
		if (IsBurning())
		{
			return;
		}
		SetBurningState(true);
		SetObjectMaterial(0, MATERIAL_FIREPLACE_GLOW);
		SetFireState(FireplaceFireState.NORMAL_FIRE);
		_furnaceHandler.StartSmelting();
	}

	void StopSmelting()
	{
		if (!GetGame().IsMultiplayer() || !GetGame().IsServer())
		{
			return;
		}
		SetBurningState(false);
		SetObjectMaterial(0, MATERIAL_FIREPLACE_NOGLOW);
		SetFireState(FireplaceFireState.NO_FIRE);
		_furnaceHandler.StopSmelting();
	}

	void SetFuel(bool hasFuel)
	{
		_hasFuel = hasFuel;
		Synchronize();
	}

	override void EECargoIn(EntityAI item)
	{
		super.EECargoIn(item);

		if (!GetGame().IsMultiplayer() || !GetGame().IsServer())
		{
			return;
		}
		SetFuel(_furnaceHandler.HasFuel());
	}

	override void EECargoOut(EntityAI item)
	{
		super.EECargoOut(item);

		if (!GetGame().IsMultiplayer() || !GetGame().IsServer())
		{
			return;
		}
		SetFuel(_furnaceHandler.HasFuel());
	}

	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();

		if (!IsBeingPlaced())
		{
			//Refresh particles and sounds
			RefreshFireParticlesAndSounds(true);

			//sound sync
			if (IsOpen() && IsSoundSynchRemote())
			{
				SoundBarrelOpenPlay();
			}

			if (!IsOpen() && IsSoundSynchRemote())
			{
				SoundBarrelClosePlay();
			}
		}
		UpdateVisualState();
	}

	bool CanStartSmelting()
	{
		return _hasFuel;
	}

	//ATTACHMENTS
	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
	{
		return false;
	}

	override bool CanReleaseAttachment(EntityAI attachment)
	{
		return false;
	}

	//CONDITIONS
	//this into/outo parent.Cargo
	override bool CanPutInCargo(EntityAI parent)
	{
		return false;
	}

	override bool CanPutIntoHands(EntityAI parent)
	{
		return false;
	}

	override bool CanRemoveFromCargo(EntityAI parent)
	{
		return true;
	}

	override bool CanReceiveItemIntoCargo(EntityAI cargo)
	{
		if (GetHierarchyParent() || cargo.GetInventory().GetCargo())
		{
			return false;
		}

		return true;
	}

	override bool CanReleaseCargo(EntityAI cargo)
	{
		if (!IsOpen())
		{
			return false;
		}
		return true;
	}

	override bool CanDisplayCargo()
	{
		if (!super.CanDisplayCargo())
		{
			return false;
		}
		return IsOpen();
	}

	override bool CanDisplayAttachmentSlot(string slot_name)
	{
		return false;
	}

	override bool CanDisplayAttachmentCategory(string category_name)
	{
		return false;
	}
	// ---

	//ACTIONS
	override void Open()
	{
		_openable.Open();

		SoundSynchRemote();
		UpdateVisualState();
	}

	override void Close()
	{
		_openable.Close();

		SoundSynchRemote();
		UpdateVisualState();
	}

	override bool IsOpen()
	{
		return _openable.IsOpened();
	}

	void UpdateVisualState()
	{
		if (IsOpen())
		{
			SetAnimationPhase(ANIMATION_OPENED, 0);
			SetAnimationPhase(ANIMATION_CLOSED, 1);
		}
		else
		{
			SetAnimationPhase(ANIMATION_OPENED, 1);
			SetAnimationPhase(ANIMATION_CLOSED, 0);
		}
	}

	//Can extinguish fire
	override bool CanExtinguishFire()
	{
		return false;
	}

	//particles
	override bool CanShowSmoke()
	{
		return false;
	}

	// Item-to-item fire distribution
	override bool HasFlammableMaterial()
	{
		return false;
	}

	override bool CanBeIgnitedBy(EntityAI igniter = NULL)
	{
		return false;
	}

	override bool CanIgniteItem(EntityAI ignite_target = NULL)
	{
		return false;
	}

	override void OnIgnitedTarget(EntityAI ignited_item) {}
	override void OnIgnitedThis(EntityAI fire_source) {}

	void SoundBarrelOpenPlay()
	{
		EffectSound sound = SEffectManager.PlaySound("barrel_open_SoundSet", GetPosition());
		sound.SetSoundAutodestroy(true);
	}

	void SoundBarrelClosePlay()
	{
		EffectSound sound = SEffectManager.PlaySound("barrel_close_SoundSet", GetPosition());
		sound.SetSoundAutodestroy(true);
	}

	void DestroyClutterCutter(Object clutter_cutter)
	{
		GetGame().ObjectDelete(clutter_cutter);
	}

	override bool IsThisIgnitionSuccessful(EntityAI item_source = NULL)
	{
		return false;
	}

	//================================================================
	// ADVANCED PLACEMENT
	//================================================================

	override string GetPlaceSoundset()
	{
		return "placeBarrel_SoundSet";
	}

	override vector GetFireEffectPosition()
	{
		return Vector( 0, 0.4, 0 );
	}

	override void SetActions()
	{
		super.SetActions();

		AddAction(BST_ActionOpenFurnace);
		AddAction(BST_ActionCloseFurnace);
		AddAction(BST_ActionStartStopSmelting);
	}
}