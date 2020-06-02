class BRP_CassettePlayer extends ItemBase
{

    const string USA                                = "USA_SoundSet";
    const string ELC                                = "Electronic_SoundSet";
    const string FSE                                = "FourSeasons_SoundSet";
    const string MOZ                                = "Mozart_SoundSet";
    const string SAD                                = "SadMusic_SoundSet";
    const string SCT                                = "Scotland_SoundSet";
    const string STR                                = "StraussII_SoundSet";
    const string SUM                                = "SummerMusic_SoundSet";
    const string PIA                                = "GuitarMusic_SoundSet";
    const string ELT                                = "ElectronicTwo_SoundSet";
	const string SOUND_TURN_ON			            = "turnOnRadio_SoundSet";
	const string SOUND_TURN_OFF			            = "turnOffRadio_SoundSet";
	const string SOUND_TEST                         = "HeavyFire_SoundSet";

    EffectSound                                     m_SoundMusic;
    EffectSound                                     m_TurnOff;
    EffectSound                                     m_TurnOn;

    ref TStringArray CassettesTypes;

    void BRP_CassettePlayer()
    {

        CassettesTypes = new ref TStringArray;

    };
	
	void OnSwitchOn()
	{

		PlayerTurnOn();
		PlayMusic();
		SetSynchDirty();
		//Print("[Debug] SwitchedOn Completed.");

	};

    void OnSwitchOff()
    {

		//super.OnSwitchOff();
		PlayerTurnOff();
		StopMusic();
		SetSynchDirty();
		//Print("[Debug] SwitchedOff Completed.");

    };

	override bool CanReleaseAttachment(EntityAI attachment)
	{
		if (this.GetCompEM().IsWorking())
		{
			return false;
		}
		return true;
	}

    void PlayMusic()
    {
        
        //Print("[Debug] Entered PlayMusic Function...");

        // Array insertions for cassettes.
        CassettesTypes.Insert("BRP_USA_Cassette");
        CassettesTypes.Insert("BRP_Electronic_Cassette");
        CassettesTypes.Insert("BRP_FourSeasons_Cassette");
        CassettesTypes.Insert("BRP_Moazart_Cassette");
        CassettesTypes.Insert("BRP_SadMusic_Cassette");
        CassettesTypes.Insert("BRP_Scotland_Cassette");
        CassettesTypes.Insert("BRP_StraussII_Cassette");
        CassettesTypes.Insert("BRP_SummerMusic_Cassette");
        CassettesTypes.Insert("BRP_GuitarMusic_Cassette");
        CassettesTypes.Insert("BRP_ElectronicTwo_Cassette");

		for (int i = 0; i < CassettesTypes.Count(); i++)
		{
			Object CassetteOne = this.FindAttachmentBySlotName("Cassette");
			//Print("[Debug] Cassette is: " + CassetteOne.GetType());

			if (CassetteOne == NULL)
			{
				//Print("[Debug] There is no cassette attached to the slot.");
			}

			else
			{
				if (CassetteOne.IsKindOf(CassettesTypes.Get(i)))
				{
					string StringCasette = CassetteOne.GetType();

					switch (StringCasette)
					{

					case "BRP_FourSeasons_Cassette":
					{
						PlaySoundSetLoop(m_SoundMusic, FSE, 0.3, 0.4);
					}
					break;

					case "BRP_Electronic_Cassette":
					{
						PlaySoundSetLoop(m_SoundMusic, ELC, 0.3, 0.4);
					}
					break;

					case "BRP_USA_Cassette":
					{
						PlaySoundSetLoop(m_SoundMusic, USA, 0.3, 0.4);
					}
					break;

					case "BRP_Moazart_Cassette":
					{
						PlaySoundSetLoop(m_SoundMusic, MOZ, 0.3, 0.4);
					}
					break;

					case "BRP_SadMusic_Cassette":
					{
						PlaySoundSetLoop(m_SoundMusic, SAD, 0.3, 0.4);
					}
					break;

					case "BRP_Scotland_Cassette":
					{
						PlaySoundSetLoop(m_SoundMusic, SCT, 0.3, 0.4);
					}
					break;

					case "BRP_StraussII_Cassette":
					{
						PlaySoundSetLoop(m_SoundMusic, STR, 0.3, 0.4);
					}
					break;

					case "BRP_SummerMusic_Cassette":
					{
						PlaySoundSetLoop(m_SoundMusic, SUM, 0.3, 0.4);
					}
					break;

					case "BRP_GuitarMusic_Cassette":
					{
						PlaySoundSetLoop(m_SoundMusic, PIA, 0.3, 0.4);
					}
					break;

					case "BRP_ElectronicTwo_Cassette":
					{
						PlaySoundSetLoop(m_SoundMusic, ELT, 0.3, 0.4);
					}
					break;


					default:
						////Print("[Debug] Could not play music due to no inserted cassette.");
						break;
					}
				}
			}
		}      

    };

	void StopMusic()
	{

        ////Print("[Debug] Entered the StopMusic function...");
        StopSoundSet(m_SoundMusic);

		if (GetGame().IsMultiplayer() && GetGame().IsServer())
		{
			StopSoundSet(m_SoundMusic);
		}

		if (GetGame().IsMultiplayer() && GetGame().IsClient())
		{
			StopSoundSet(m_SoundMusic);
		}

		//Print("[Debug] Music Stopped.");
	};

	void PlayerTurnOn()
	{

		PlaySoundSet(m_TurnOn, SOUND_TURN_ON, 0.0, 0.0);
		//Print("[Debug] PlayerTurnOn played...");

	};

	void PlayerTurnOff()
	{

		PlaySoundSet(m_TurnOff, SOUND_TURN_OFF, 0.0, 0.0);
		//Print("[Debug] PlayerTurnOff played...");

	};

	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionTurnOnPlayer);
		AddAction(ActionTurnOffPlayer);

	};
};