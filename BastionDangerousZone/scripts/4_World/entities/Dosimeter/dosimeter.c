// Script File
class BRP_Dosimeter extends ItemBase
{
	PlayerBase					m_player;

	static const string			START_SOUND 				= "dz_Geiger_SoundSet_Switch";
	static const string			LOOP_SOUND_LOW					= "dz_Geiger_Low_SoundSet";
	static const string			LOOP_SOUND_INT 					= "dz_Geiger_Intermediate_SoundSet";
	static const string			LOOP_SOUND_HIGH 				= "dz_Geiger_High_SoundSet";
	static const string			LOOP_SOUND_VERYLOW					= "dz_Geiger_VeryLow_SoundSet";
	static const string			LOOP_SOUND_VERYINT 					= "dz_Geiger_VeryIntermediate_SoundSet";
	static const string			LOOP_SOUND_VERYHIGH 				= "dz_Geiger_VeryHigh_SoundSet";
	static const string			STOP_SOUND 					= "dz_Geiger_SoundSet_Switch";

	protected EffectSound 		m_EngineLoop;
	protected EffectSound 		m_EngineStart;
	protected EffectSound 		m_EngineStop;


	ItemBase					m_Battery; // Attached battery9v

	bool						m_Working;
	bool            m_CanWork = false;
	int						  m_Level;
	int             i=-1;

	ref Timer 					m_SoundLoopStartTimer;


	void BRP_Dosimeter()
	{
		RegisterNetSyncVariableBool("m_IsSoundSynchRemote");
		RegisterNetSyncVariableBool("m_CanWork");
		m_Level = 0;
	}

	void ~BRP_Dosimeter()
	{
		OnWorkStop();
	}


	override void OnInitEnergy()
	{
		super.OnInitEnergy();
	}

	override void OnWorkStart()
	{

		if ( GetGame().IsClient()  ||  !GetGame().IsMultiplayer() )
		{
			IsPlayerIrradiedNearby();
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
				//Print("test value = " + GetRadConfigClient().Radius.Get(i).ToString());
				int level_value = GetLevelValue(GetRadConfigClient().NbRadGiven.Get(i));
				//Print("sick_value = " + GetRadConfigClient().NbRadGiven.Get(i));
				//Print("level_value = " + GetLevelValue(GetRadConfigClient().NbRadGiven.Get(i)).ToString());
				if( GetRadConfigClient().IsSquareZone.Get(i) == 1)
				{
					CheckSquareZone(GetRadConfigClient().X1.Get(i),GetRadConfigClient().Y1.Get(i),GetRadConfigClient().X2.Get(i),GetRadConfigClient().Y2.Get(i),i,level_value);
				}
				else
				{
					CheckRoundZone(GetRadConfigClient().X.Get(i),GetRadConfigClient().Y.Get(i),GetRadConfigClient().Radius.Get(i),i,level_value);
				}
			}
		}
	}

	int GetLevelValue(int nbradgiven)
	{
			if(nbradgiven == 0)return 0;
			if(nbradgiven <= 15)return 1;
			if(nbradgiven <= 30)return 2;
			if(nbradgiven <= 60)return 3;
			if(nbradgiven <= 75)return 4;

			return 0;
	}

	void CheckSquareZone(float m_X1, float m_Y1, float m_X2, float m_Y2, int zone, int level_value)
	{
		vector pos = this.GetPosition();
		if ( (pos[0]>GetSquarePercentageCoordonate(0.167,m_X1,m_X2) && pos[0]<GetSquarePercentageCoordonate(0.167,m_X2,m_X1)) && (pos[2]>GetSquarePercentageCoordonate(0.167,m_Y1,m_Y2) && pos[2]<GetSquarePercentageCoordonate(0.167,m_Y2,m_Y1)) )
		{
			if(i==zone && m_CanWork == true)
			{
				m_Level = level_value + 2;
				return;
			}
			else{
				m_Level = level_value + 2;
				i = zone;
				m_CanWork = true;
			}
		}
		else if ( (pos[0]>GetSquarePercentageCoordonate(0.33,m_X1,m_X2) && pos[0]<GetSquarePercentageCoordonate(0.33,m_X2,m_X1)) && (pos[2]>GetSquarePercentageCoordonate(0.33,m_Y1,m_Y2) && pos[2]<GetSquarePercentageCoordonate(0.33,m_Y2,m_Y1)) )
		{
			if(i==zone && m_CanWork == true)
			{
				m_Level = level_value + 1;
				return;
			}
			else{
				m_Level = level_value + 1;
				i = zone;
				m_CanWork = true;
			}
		}
		else if ( (pos[0]>m_X1&& pos[0]<m_X2) && (pos[2]>m_Y1) && pos[2]<m_Y2 )
		{
			if(i==zone && m_CanWork == true)
			{
				m_Level = level_value;
				return;
			}
			else{
				m_Level = level_value;
				i = zone;
				m_CanWork = true;
			}
		}
		else
		{
			if(i==zone && m_CanWork == true)
			{
				i = -1;
				m_Level = 0;
				m_CanWork = false;
			}
			else
			{
				return;
			}
		}
	}

	float GetSquarePercentageCoordonate(float percentage, float Coo1, float Coo2)
	{
		int temp = Coo1;
		temp = temp + percentage*(Coo2-Coo1);
		return temp;
	}

	void CheckRoundZone(float m_X, float m_Y, float Zone_Radius, int zone, int level_value)
	{
		vector pos = this.GetPosition();
		float distance_squared = Math.Pow(m_X-pos[0], 2) + Math.Pow(m_Y-pos[2], 2);
		if ( distance_squared <= Math.Pow(0.33*Zone_Radius, 2) )
		{
			if(i==zone && m_CanWork == true )
			{
				m_Level = level_value + 2;
				//Print("CENTER");
				//Print("m_Level " + m_Level.ToString());
				return;
			}
			else{
				m_Level = level_value + 2;
				i = zone;
				m_CanWork = true;
			}
		}
		else if ( distance_squared <= Math.Pow(0.66*Zone_Radius, 2) )
		{
			if(i==zone && m_CanWork == true )
			{
				m_Level = level_value + 1;
				//Print("INTER");
				//Print("m_Level " + m_Level.ToString());
				return;
			}
			else{
				m_Level = level_value + 1;
				i = zone;
				m_CanWork = true;
			}
		}
		else if ( distance_squared <= Math.Pow(Zone_Radius, 2) )
		{
			if(i==zone && m_CanWork == true )
			{
				m_Level = level_value;
				//Print("BORDER");
				//Print("m_Level " + m_Level.ToString());
				return;
			}
			else{
				m_Level = level_value;
				i = zone;
				m_CanWork = true;
			}
		}
		else if ( distance_squared > Math.Pow(Zone_Radius, 2) )
		{
			if(i==zone && m_CanWork == true)
			{
				m_Level = 0;
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
		GetGame().GetObjectsAtPosition3D(this.GetPosition(), 2, proche_objects, NULL);
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
			if(proche_objects.Get(i).IsKindOf("ItemBase"))
			{
				ItemBase item = ItemBase.Cast(proche_objects.Get(i));
				if (item.GetRadAgentQuantity() > 0)
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
		//GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Remove(this.IsPlayerIrradiedNearby);
	}

	void StartSound()
	{
		PlaySoundSet( m_EngineStart, START_SOUND, 0, 0 );

		if (!m_SoundLoopStartTimer) m_SoundLoopStartTimer = new Timer( CALL_CATEGORY_SYSTEM );
		m_SoundLoopStartTimer.Run(0.2, this, "StartLoopSound", NULL, true);
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
					switch(m_Level)
					{
						case 0: return;
						break;

						case 1:
						{
							if (m_EngineLoop)
							{
								//Print("VERYLOW");
								if ( !m_EngineLoop.IsSoundPlaying()) PlaySoundSet( m_EngineLoop, LOOP_SOUND_VERYLOW, 0, 0);
							}
							else {
									PlaySoundSet( m_EngineLoop, LOOP_SOUND_VERYLOW, 0, 0);
							}
						}break;

						case 2:
						{
							if (m_EngineLoop)
							{
								//Print("LOW");
								if ( !m_EngineLoop.IsSoundPlaying()) PlaySoundSet( m_EngineLoop, LOOP_SOUND_LOW, 0, 0);
							}
							else {
									PlaySoundSet( m_EngineLoop, LOOP_SOUND_LOW, 0, 0);
							}
						}break;

						case 3:
						{
							if (m_EngineLoop)
							{
								//Print("INTER");
								if ( !m_EngineLoop.IsSoundPlaying()) PlaySoundSet( m_EngineLoop, LOOP_SOUND_INT, 0, 0);
							}
							else {
									PlaySoundSet( m_EngineLoop, LOOP_SOUND_INT, 0, 0);
							}
						}break;

						case 4:
						{
							if (m_EngineLoop)
							{
								//Print("VERYINTER");
								if ( !m_EngineLoop.IsSoundPlaying()) PlaySoundSet( m_EngineLoop, LOOP_SOUND_VERYINT, 0, 0);
							}
							else {
									PlaySoundSet( m_EngineLoop, LOOP_SOUND_INT, 0, 0);
							}
						}break;

						case 5:
						{
							if (m_EngineLoop)
							{
								//Print("HIGH");
								if ( !m_EngineLoop.IsSoundPlaying()) PlaySoundSet( m_EngineLoop, LOOP_SOUND_HIGH, 0, 0);
							}
							else {
									PlaySoundSet( m_EngineLoop, LOOP_SOUND_HIGH, 0, 0);
							}
						}break;

						case 6:
						{
							if (m_EngineLoop)
							{
								//Print("VERYHIGH");
								if ( !m_EngineLoop.IsSoundPlaying()) PlaySoundSet( m_EngineLoop, LOOP_SOUND_VERYHIGH, 0, 0);
							}
							else {
									PlaySoundSet( m_EngineLoop, LOOP_SOUND_HIGH, 0, 0);
							}
						}break;

						default:return;
						break;
				}
			}
			else
			{
				if (m_EngineLoop)
				{
					if (m_EngineLoop.IsSoundPlaying())	m_EngineLoop.SoundStop();
				}
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
		AddAction(ActionGetRadClotheLevel);
	}
};

class BRP_Dosimeter_Opal : BRP_Dosimeter {};
class BRP_Dosimeter_Osa : BRP_Dosimeter_Opal {};
class BRP_Dosimeter_Sova : BRP_Dosimeter_Opal {};
class BRP_Dosimeter_Zov : BRP_Dosimeter_Opal {};