// Script File
class BRP_Dosimeter extends ItemBase
{
	PlayerBase					m_player;

	static const string			START_SOUND 				= "dz_Geiger_SoundSet_Switch";
	static const string			LOOP_SOUND 					= "dz_Geiger_SoundSet";
	static const string			STOP_SOUND 					= "dz_Geiger_SoundSet_Switch";

	protected EffectSound 		m_EngineLoop;
	protected EffectSound 		m_EngineStart;
	protected EffectSound 		m_EngineStop;


	ItemBase					m_Battery; // Attached battery9v

	bool						m_Working;
	bool            m_CanWork = false;
	int             i=-1;

	ref Timer 					m_SoundLoopStartTimer;


	void BRP_Dosimeter()
	{
		RegisterNetSyncVariableBool("m_IsSoundSynchRemote");
		RegisterNetSyncVariableBool("m_CanWork");
	}


	override void OnInitEnergy()
	{
		super.OnInitEnergy();
	}

	override void OnWorkStart()
	{
		//IsPlayerIrradiedNearby();
		if ( GetGame().IsClient()  ||  !GetGame().IsMultiplayer() )
		{
			IsGeigerInRadZone();
			StartSound();

			m_Working = true;
		}
	}

	void IsGeigerInRadZone()
	{
		if ( GetGame().IsClient()  ||  !GetGame().IsMultiplayer() )
		{
			for(int i = 0 ; i<= -1 + GetRadConfigClient().X1.Count() ; i++)
			{
				//Print("Nb RadZone = " + GetRadConfigClient().X1.Count().ToString());
				if( GetRadConfigClient().IsSquareZone.Get(i) == 1)
				{
					CheckSquareZone(GetRadConfigClient().X1.Get(i),GetRadConfigClient().Y1.Get(i),GetRadConfigClient().X2.Get(i),GetRadConfigClient().Y2.Get(i),i);
				}
				else
				{
					CheckRoundZone(GetRadConfigClient().X.Get(i),GetRadConfigClient().Y.Get(i),GetRadConfigClient().Radius.Get(i),i);
				}
			}
		}
}


	void CheckSquareZone(float m_X1, float m_Y1, float m_X2, float m_Y2, int zone)
	{
		vector pos = this.GetPosition();
		if ( (pos[0]>m_X1 && pos[0]<m_X2) && (pos[2]>m_Y1 && pos[2]<m_Y2) )
		{
			if(i==zone && m_CanWork == true)
			{
				return;
			}
			else{
				i = zone;
				m_CanWork = true;
			}
		}
		else
		{
			if(i==zone && m_CanWork == true)
			{
				i = -1;
				m_CanWork = false;
			}
			else
			{
				return;
			}
		}
	}

	void CheckRoundZone(float m_X, float m_Y, float Zone_Radius, int zone)
	{
		vector pos = this.GetPosition();
		float distance_squared = Math.Pow(m_X-pos[0], 2) + Math.Pow(m_Y-pos[2], 2);
		if ( distance_squared <= Math.Pow(Zone_Radius, 2) )
		{
			if(i==zone && m_CanWork == true)
			{
				return;
			}
			else{
				i = zone;
				m_CanWork = true;
			}
		}
		else if ( distance_squared > Math.Pow(Zone_Radius, 2) )
		{
			if(i==zone && m_CanWork == true)
			{
				i = -1;
				m_CanWork = false;
			}
			else{
				return;
			}
		}
	}

	void IsPlayerIrradiedNearby()
	{
		ref array<Object> proche_objects = new array<Object>;
		PlayerBase FindPlayer;
		GetGame().GetObjectsAtPosition3D(this.GetPosition(), 2.5, proche_objects, NULL);
		FindPlayer = NULL;

		//Print("NB_Obj: " + proche_objects.Count().ToString());

		for (int i = 0; i < proche_objects.Count(); ++i)
		{
			string tempObjId = proche_objects.Get(i).ToString();
			tempObjId.ToLower();
			if (tempObjId.Contains("static")) continue;
			if (proche_objects.Get(i).IsWell() || proche_objects.Get(i).IsBush()) continue;
			if (proche_objects.Get(i).IsRock() || proche_objects.Get(i).IsTree()) continue;
			if (proche_objects.Get(i).IsBuilding()) continue;
			if (proche_objects.Get(i).IsWoodBase() ) continue;
			if (proche_objects.Get(i).IsKindOf("SurvivorBase"))
			{
				FindPlayer=proche_objects.Get(i);
				int RadSickCount = FindPlayer.GetSingleAgentCount(DZAgents.RADSICK);
				if(RadSickCount > 100)
				{
					StartSound();
				}
			}
		}
		GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater(this.IsPlayerIrradiedNearby,7000 );
	}

	override void OnWork( float consumed_energy )
	{
			IsGeigerInRadZone();
	}

	override void OnWorkStop()
	{
		super.OnWorkStop();
		if ( GetGame().IsClient()  ||  !GetGame().IsMultiplayer() )
		{
			StopSound();
			m_Working = false;
		}
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Remove(this.IsPlayerIrradiedNearby);
	}

	void StartSound()
	{
		PlaySoundSet( m_EngineStart, START_SOUND, 0, 0 );

		if (!m_SoundLoopStartTimer) m_SoundLoopStartTimer = new Timer( CALL_CATEGORY_SYSTEM );
		m_SoundLoopStartTimer.Run(0.1, this, "StartLoopSound", NULL, true);
	}

	void StopSound()
	{
		if ( GetGame().IsClient()  ||  !GetGame().IsMultiplayer() )
		{
			if (m_SoundLoopStartTimer)
			{
				m_SoundLoopStartTimer.Stop();
			}

			if (m_EngineLoop){
				if (m_EngineLoop.IsSoundPlaying()) m_EngineLoop.SoundStop();
			}
			PlaySoundSet( m_EngineStop, STOP_SOUND, 0, 0 );
		}
	}

	override void EEItemAttached ( EntityAI item, string slot_name )
	{
		super.EEItemAttached ( item, slot_name );

		ItemBase item_IB = ItemBase.Cast( item );

		if ( item_IB.IsKindOf("Battery9V") )
		{
			m_Battery = item_IB;
		}
	}


	override void EEItemDetached ( EntityAI item, string slot_name )
	{
		super.EEItemDetached ( item, slot_name );

		ItemBase item_IB = ItemBase.Cast( item );

		if ( item_IB.IsKindOf("Battery9V") )
		{
			m_Battery = NULL;
		}
	}

	void StartLoopSound()
	{
		if ( (GetGame().IsClient()  ||  !GetGame().IsMultiplayer()))
		{
			if(m_CanWork)
			{
					if (m_EngineLoop)
					{
						if ( !m_EngineLoop.IsSoundPlaying()) PlaySoundSet( m_EngineLoop, LOOP_SOUND, 0, 0);
					}
					else {
							PlaySoundSet( m_EngineLoop, LOOP_SOUND, 0, 0);
					}
			}
		}
		else
			{
				if (m_EngineLoop){
					if (m_EngineLoop.IsSoundPlaying())	m_EngineLoop.SoundStop();
				}
			}
	}

	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionTurnOnWhileInHands);
		AddAction(ActionTurnOffWhileInHands);
		AddAction(ActionTestForRadiationSelf);
		AddAction(ActionTestForRadiationTarget);
	}
}
