class BRP_InternalDosimeter : Morphine
{
	private const int SYNC_RAD_RPC = 90109010;

	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx) 
	{
		super.OnRPC(sender, rpc_type, ctx);
		if (GetGame().IsClient())
		{
			if (rpc_type == SYNC_RAD_RPC)
				ShowRadiationLevel(ctx);
		}
	}

	void SendRadiation(PlayerIdentity recipient)
	{
		int radiationInt;
		PlayerBase owner;
		Param2<BRP_InternalDosimeter, int> params;
		if (Class.CastTo(owner, GetHierarchyRootPlayer()))
		{
			radiationInt = owner.GetRadiationLevel();
			params = new Param2<BRP_InternalDosimeter, int>(this, radiationInt);
			RPCSingleParam(SYNC_RAD_RPC, params, true, recipient);
		}
	}

	void ShowRadiationLevel(ParamsReadContext ctx)
	{
		Param2<BRP_InternalDosimeter, int> data;
		if (!ctx.Read(data))
			return;

		BRP_InternalDosimeter dosim = data.param1;
		dosim.SoundRadiation(data.param2);
	}

	void SoundRadiation(int innerRadiation)
	{
		EffectSound sound =	SEffectManager.PlaySoundOnObject( "Radiation_INIT_SoundSet", this );
		sound.SetSoundAutodestroy( true );
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(PrepareRadSound, 1000, false, innerRadiation);
		PlayerBase.Cast(GetHierarchyRootPlayer()).BSTShowNotification("Your internal exposure is "+innerRadiation.ToString());
	}

	void PrepareRadSound(int innerRadiation)
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

	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionMeasureRadiationLevel);
		RemoveAction(ActionInjectMorphineTarget);
		RemoveAction(ActionInjectMorphineSelf);
	}
}