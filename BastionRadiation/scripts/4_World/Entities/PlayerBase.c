modded class PlayerBase
{
	private ref RadiationHandlerClient radiationHandler;
	private int innerRadiation;
	private bool shouldSyncRadiation;

	override void Init()
	{
		super.Init();

		RegisterNetSyncVariableInt("innerRadiation");
		RegisterNetSyncVariableBool("shouldSyncRadiation");

		if (!GetGame().IsServer() || !GetGame().IsMultiplayer())
		{
			radiationHandler = new RadiationHandlerClient(this);
		}
	}

	RadiationHandlerClient GetRadiationHandler()
	{
		return radiationHandler;
	}

	override void OnConnect()
	{
		super.OnConnect();

		GetGame().RPCSingleParam(null, RadRPCs.RESPONSE_DATA, new Param1<ref RadiationConfig>(GetRadiationManager().GetConfig()), true, GetIdentity());
	}

	void AddRadiationLevel(float rad)
	{
		float tempRad = rad;
		//Print("current rad "+ GetRadiationLevel());
		if (GetModifiersManager().IsModifierActive(Rad_eModifiers.MDF_RAD_BLOCK))
			tempRad *= 0.5;
		//Print("\nAddRadiationLevel rad "+ tempRad);
		InsertAgent(BST_Agents.RADIATION, ConvertRadiationAgent(tempRad));
		//Print("after insert rad {"+ GetRadiationLevel()+"}");
	}

	void DecreaseAgent(int agent, float amount)
	{
		m_AgentPool.DecreaseAgent(agent, ConvertRadiationAgent(amount));
	}

	int ConvertRadiationAgent(float amount)
	{
		return (amount * 1000);
	}

	float GetRadiationLevel()
	{
		return (GetSingleAgentCount(BST_Agents.RADIATION) * 0.001);
	}

	void NeedSyncRadiation(bool need)
	{
		shouldSyncRadiation = need;
		if (shouldSyncRadiation)
			innerRadiation = GetRadiationLevel();
		SetSynchDirty();
	}

	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
		if (shouldSyncRadiation)
		{
			SoundRadiation();
		}
	}

	void SoundRadiation()
	{
		EffectSound sound =	SEffectManager.PlaySoundOnObject( "Radiation_INIT_SoundSet", this );
		sound.SetSoundAutodestroy( true );
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(PrepareRadSound, 1000, false);
		BSTShowNotification("Your internal exposure is "+innerRadiation.ToString());
	}

	void PrepareRadSound()
	{
		string exposure = innerRadiation.ToString();
		int idx;
		string digit;
		for (int i = 0; i < exposure.Length(); i++)
		{
			digit = exposure.Get(i);
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(PlayInnerRadSound, ((i + 1) * 800), false, digit);
		}
	}

	void PlayInnerRadSound(string name)
	{
		EffectSound sound =	SEffectManager.PlaySoundOnObject( "Radiation_MR_"+name+"_SoundSet", this );
		sound.SetSoundAutodestroy( true );
	}

	void DelaySyncReset()
	{
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(NeedSyncRadiation, 1000, false, false);
	}
}