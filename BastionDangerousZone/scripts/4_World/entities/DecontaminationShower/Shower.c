class BRP_DecontaminationShower extends BRP_Item
{
  static const string			SHOWER_SOUND 				= "dz_Shower_SoundSet";
  ref array<string> m_SLOTS = {"Head","Shoulder","Melee","Headgear","Mask","Eyewear","Hands","LeftHand","Gloves","Armband","Vest","Body","Back","Hips","Legs","Feet"};
  static float 			m_WorkingTimePerLiter=60;

  Particle m_Particle1Efx;
  Particle m_Particle2Efx;
  Particle m_Particle3Efx;
  Particle m_Particle4Efx;
  Particle m_Particle5Efx;
  Particle m_Particle6Efx;

  vector m_ParticleLocal1Pos = Vector(-1.702,0.493,-0.05);

  vector m_ParticleLocal2Pos = Vector(-1.702,0.838,-0.05);

  vector m_ParticleLocal4Pos = Vector(-1.702,1.730,-0.05);

  vector m_ParticleLocal3Pos = Vector(-1.702,1.196,-0.05);

  vector m_ParticleLocal5Pos = Vector(-1.086,2.102,-0.05);

  vector m_ParticleLocal6Pos = Vector(-0.569,2.102,-0.05);

  ref Timer 					m_SoundLoopStartTimerShower;

  protected EffectSound 		m_EngineLoop;

  bool            m_CanWork = false;

  void BRP_DecontaminationShower()
  {
      SetAllowDamage(false);
  }

  void ~BRP_DecontaminationShower()
  {

  }

  override string Get_KitName()
	{
		return "BRP_ShowerKit";
	}

  override void OnWorkStart()
  {
    #ifdef DZDEBUG
    GetDZLogger().LogInfo("Shower_OnWork start"+"current energy: "+GetCompEM().GetEnergy().ToString());
    #endif
    if ( GetGame().IsClient()  ||  !GetGame().IsMultiplayer() )
    {
      StartSound();
      PlayParticle();
    }
  }

  void PlayParticle()
  {
    if (GetGame().IsClient() || !GetGame().IsMultiplayer()){
      m_Particle1Efx = Particle.PlayOnObject(ParticleList.SHOWER90, this,m_ParticleLocal1Pos, Vector(0,0,0), false);
      m_Particle2Efx = Particle.PlayOnObject(ParticleList.SHOWER90, this,m_ParticleLocal2Pos, Vector(0,0,0), false);
      m_Particle3Efx = Particle.PlayOnObject(ParticleList.SHOWER90, this,m_ParticleLocal3Pos, Vector(0,0,0), false);
      m_Particle4Efx = Particle.PlayOnObject(ParticleList.SHOWER135, this,m_ParticleLocal4Pos, Vector(0,0,0), false);
      m_Particle5Efx = Particle.PlayOnObject(ParticleList.SHOWER180, this,m_ParticleLocal5Pos, Vector(0,0,0), false);
      m_Particle6Efx = Particle.PlayOnObject(ParticleList.SHOWER180, this,m_ParticleLocal6Pos, Vector(0,0,0), false);
    }
  }

  void StopParticle()
  {
    if (m_Particle1Efx)
			m_Particle1Efx.Stop();
    if (m_Particle2Efx)
  		m_Particle2Efx.Stop();
    if (m_Particle3Efx)
    	m_Particle3Efx.Stop();
    if (m_Particle4Efx)
      	m_Particle4Efx.Stop();
    if (m_Particle5Efx)
    	m_Particle5Efx.Stop();
      if (m_Particle6Efx)
      	m_Particle6Efx.Stop();
  }

  override void OnWork( float consumed_energy )
	{

      if ( !GetCompEM().HasEnoughStoredEnergy())
			GetCompEM().SwitchOff();

			DecontaminatePlayerNearby();
      ConsumeTank();

      #ifdef DZDEBUG
			GetDZLogger().LogInfo("Shower_OnWork on"+"current energy: "+GetCompEM().GetEnergy().ToString());
			#endif
	}

  void ConsumeTank()
	{
		CanisterGasoline m_Tank = GetTank();

		if (m_Tank)
		{
			m_Tank.AddQuantity(-500);
			GetCompEM().AddEnergy(m_WorkingTimePerLiter);
		}
    if(m_Tank.GetQuantity()==0)
    {
      	GetCompEM().SwitchOff();
    }
	}

  CanisterGasoline GetTank()
  {
    return CanisterGasoline.Cast(GetAttachmentByType(CanisterGasoline));
  }

  void DecontaminatePlayerNearby()
  {
    ref array<Object> proche_objects = new array<Object>;
		PlayerBase FindPlayer;
		GetGame().GetObjectsAtPosition3D(this.GetPosition(), 2, proche_objects, NULL);
		FindPlayer = NULL;

		for (int i = 0; i < proche_objects.Count(); ++i)
		{
			string tempObjId = proche_objects.Get(i).ToString();
			tempObjId.ToLower();
			if (tempObjId.Contains("static")) continue;
			if (proche_objects.Get(i).IsWell() || proche_objects.Get(i).IsBush()) continue;
			if (proche_objects.Get(i).IsRock() || proche_objects.Get(i).IsTree()) continue;
			if (proche_objects.Get(i).IsBuilding()) continue;
			if (proche_objects.Get(i).IsWoodBase() ) continue;
			if(proche_objects.Get(i).IsKindOf("SurvivorBase"))
			{
				FindPlayer = PlayerBase.Cast(proche_objects.Get(i));
				CleanPlayer(FindPlayer);
			}
		}
  }

  override bool CanPutIntoHands( EntityAI parent )
	{
		if( !super.CanPutIntoHands( parent ) )
		{
			return false;
		}

		return false;
	}

	override bool CanPutInCargo( EntityAI parent )
	{
		if( !super.CanPutInCargo( parent ) )
		{
			return false;
		}

		return false;
	}

	bool ConditionOutOfHands( EntityAI player )
	{
		return false;
	}

  void CleanPlayer(PlayerBase player)
  {
    if (GetGame().IsServer())
		{
      if(player.GetSingleAgentCount(DZAgents.RADSICK) >= 150)
      {
        player.SetRadPoint(150);
      }
			for (int i = 0; i < m_SLOTS.Count();i++)
			{
				EntityAI Clothes;
				Clothes = player.FindAttachmentBySlotName(m_SLOTS.Get(i));

				if (Clothes != NULL && !Clothes.IsRuined() && ItemBase.Cast(Clothes).GetRadAgentQuantity() > 0)
				{
					ItemBase.Cast(Clothes).InjectRadAgent(0);
					continue;
				}
		  }
    }
	}

	override void OnWorkStop()
	{
		super.OnWorkStop();
    #ifdef DZDEBUG
    GetDZLogger().LogInfo("Shower_OnWork Stop"+"current energy: "+GetCompEM().GetEnergy().ToString());
    #endif
		if ( GetGame().IsClient()  ||  !GetGame().IsMultiplayer() )
		{
        StopSound();
        StopParticle();
		}
	}

  void StartSound()
	{
		if (!m_SoundLoopStartTimerShower) m_SoundLoopStartTimerShower = new Timer( CALL_CATEGORY_SYSTEM );
		m_SoundLoopStartTimerShower.Run(0.2, this, "StartLoopSound", NULL, true);
	}

  void StartLoopSound()
	{
		if ( (GetGame().IsClient()  ||  !GetGame().IsMultiplayer()))
		{
				if (m_EngineLoop)
				{
						if ( !m_EngineLoop.IsSoundPlaying()) PlaySoundSet( m_EngineLoop, SHOWER_SOUND, 0, 0);
				}
				else
        {
						PlaySoundSet( m_EngineLoop, SHOWER_SOUND, 0, 0);
				}
		}
	}

	void StopSound()
	{
		if ( GetGame().IsClient()  ||  !GetGame().IsMultiplayer() )
		{
			if (m_SoundLoopStartTimerShower)
			{
				m_SoundLoopStartTimerShower.Stop();
			}

			if (m_EngineLoop){
				if (m_EngineLoop.IsSoundPlaying()) m_EngineLoop.SoundStop();
			}
		}
	}

  override bool CanReleaseAttachment (EntityAI attachment)
	{
		if( !super.CanReleaseAttachment( attachment ) )
			return false;
		return !GetCompEM().IsWorking();
	}

  void CanStartShower()
	{
    EntityAI m_Tank;
    m_Tank = this.FindAttachmentBySlotName("ShowerTank");
    if(m_Tank == NULL)return;
    ItemBase m_Tank_IB = ItemBase.Cast(m_Tank);
		if(m_Tank_IB.GetQuantity() >= 500 && m_Tank_IB.GetLiquidType() != LIQUID_GASOLINE)
		{
			GetCompEM().SwitchOn();
		}
	}

  override void EEItemAttached ( EntityAI item, string slot_name )
	{
		super.EEItemAttached ( item, slot_name );
    //CanStartShower();
	}


	override void EEItemDetached ( EntityAI item, string slot_name )
	{
		super.EEItemDetached ( item, slot_name );
    if(GetCompEM().IsWorking())GetCompEM().SwitchOff();
	}

  override bool IsDeployable()
    {
        return true;
    }

	bool IsPlaceable()
	{
		return true;
	}

	 bool IsPlaceableAtPosition( vector position )
	{
		return true;
	}

	override void OnPlacementComplete( Man player )
	{
		super.OnPlacementComplete( player );
	}

  override void SetActions()
	{
		super.SetActions();
		AddAction(ActionTurnOnBRP_DecontaminationShower);
		AddAction(ActionTurnOffBRP_DecontaminationShower);
	}

}
