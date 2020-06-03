class StunM18SmokeGrenade_ColorBase extends StunSmoke
{
	const string SOUND_SMOKE_START = "SmokegGrenades_M18_start_loop_SoundSet";
	const string SOUND_SMOKE_LOOP = "SmokegGrenades_M18_active_loop_SoundSet";
	const string SOUND_SMOKE_END = "SmokegGrenades_M18_end_loop_SoundSet";

	void StunM18SmokeGrenade_ColorBase()
	{
		SetAmmoType("");
		SetFuseDelay(2);
		SetSoundSmokeStart(SOUND_SMOKE_START);
		SetSoundSmokeLoop(SOUND_SMOKE_LOOP);
		SetSoundSmokeEnd(SOUND_SMOKE_END);
	}
	
	void ~StunM18SmokeGrenade_ColorBase() {}
}

class BRP_Kolokol2 extends StunM18SmokeGrenade_ColorBase
{
	void BRP_Kolokol2()
	{
		SetParticleSmokeStart(ParticleList.STUN_BLUESMOKE);
		SetParticleSmokeLoop(ParticleList.STUN_BLUESMOKE);
		SetParticleSmokeEnd(ParticleList.STUN_BLUESMOKE);
	}
}


