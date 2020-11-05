class GreenSpore extends House
{
	Particle m_ParticleEfx;
	Particle m_Mist;

	void GreenSpore()
	{
		if (GetGame().IsClient() || !GetGame().IsMultiplayer()){
			m_ParticleEfx = Particle.PlayOnObject(ParticleList.HAZARDZONE_GREENSPORE, this);
			m_Mist = Particle.PlayOnObject(ParticleList.HAZARDZONE_MUSTARDMIST, this);
		}
	}

	void ~GreenSpore()
	{
		if (m_ParticleEfx)
			m_ParticleEfx.Stop();

		if (m_Mist)
			m_Mist.Stop();
	}
}

class WeirdGreenSpore extends House
{
	Particle m_ParticleEfx;

	void WeirdGreenSpore()
	{
		if (GetGame().IsClient() || !GetGame().IsMultiplayer()){
			m_ParticleEfx = Particle.PlayOnObject(ParticleList.HAZARDZONE_WEIRDGREEN, this);
		}
	}

	void ~WeirdGreenSpore()
	{
		if (m_ParticleEfx)
			m_ParticleEfx.Stop();
	}
}

class WeirdGreenSpore2 extends House
{
	Particle m_ParticleEfx;
	Particle m_Mist;

	void WeirdGreenSpore2()
	{
		if (GetGame().IsClient() || !GetGame().IsMultiplayer()){
			m_ParticleEfx = Particle.PlayOnObject(ParticleList.HAZARDZONE_WEIRDGREEN2, this);
		}
	}

	void ~WeirdGreenSpore2()
	{
		if (m_ParticleEfx)
			m_ParticleEfx.Stop();
	}
}

class PurpleSpore extends House
{
	Particle m_ParticleEfx;
	Particle m_Mist;

	void PurpleSpore()
	{
		if (GetGame().IsClient() || !GetGame().IsMultiplayer()){
			m_ParticleEfx = Particle.PlayOnObject(ParticleList.HAZARDZONE_PURPLESPORE, this);
			m_Mist = Particle.PlayOnObject(ParticleList.HAZARDZONE_MUSTARDMIST, this);
		}
	}

	void ~PurpleSpore()
	{
		if (m_ParticleEfx)
			m_ParticleEfx.Stop();

			if (m_Mist)
				m_Mist.Stop();
	}
}

class BlueSpore extends House
{
	Particle m_ParticleEfx;
	Particle m_Mist;

	void BlueSpore()
	{
		if (GetGame().IsClient() || !GetGame().IsMultiplayer()){
			m_ParticleEfx = Particle.PlayOnObject(ParticleList.HAZARDZONE_BLUESPORE, this);
			m_Mist = Particle.PlayOnObject(ParticleList.HAZARDZONE_MUSTARDMIST, this);
		}
	}

	void ~BlueSpore()
	{
		if (m_ParticleEfx)
			m_ParticleEfx.Stop();

			if (m_Mist)
				m_Mist.Stop();
	}
}

class RedSpore extends House
{
	Particle m_ParticleEfx;
	Particle m_Mist;

	void RedSpore()
	{
		if (GetGame().IsClient() || !GetGame().IsMultiplayer()){
			m_ParticleEfx = Particle.PlayOnObject(ParticleList.HAZARDZONE_REDSPORE, this);
			m_Mist = Particle.PlayOnObject(ParticleList.HAZARDZONE_MUSTARDMIST, this);
		}
	}

	void ~RedSpore()
	{
		if (m_ParticleEfx)
			m_ParticleEfx.Stop();

			if (m_Mist)
				m_Mist.Stop();
	}
}

class WhiteSpore extends House
{
	Particle m_ParticleEfx;
	Particle m_Mist;

	void WhiteSpore()
	{
		if (GetGame().IsClient() || !GetGame().IsMultiplayer()){
			m_ParticleEfx = Particle.PlayOnObject(ParticleList.HAZARDZONE_WHITESPORE, this);
			m_Mist =  Particle.PlayOnObject(ParticleList.HAZARDZONE_MUSTARDMIST, this);
		}
	}

	void ~WhiteSpore()
	{
		if (m_ParticleEfx)
			m_ParticleEfx.Stop();
	}
}

class WeirdGreenSporeSmall extends House
{
	Particle m_ParticleEfx;

	void WeirdGreenSporeSmall()
	{
		if (GetGame().IsClient() || !GetGame().IsMultiplayer()){
			m_ParticleEfx = Particle.PlayOnObject(ParticleList.HAZARDZONE_WEIRDGREEN_SMALL, this);
		}
	}

	void ~WeirdGreenSporeSmall()
	{
		if (m_ParticleEfx)
			m_ParticleEfx.Stop();
	}
}

class WeirdGreenSporeExtraSmall extends House
{
	Particle m_ParticleEfx;

	void WeirdGreenSporeExtraSmall()
	{
		if (GetGame().IsClient() || !GetGame().IsMultiplayer()){
			m_ParticleEfx = Particle.PlayOnObject(ParticleList.HAZARDZONE_WEIRDGREEN_EXTRASMALL, this);
		}
	}

	void ~WeirdGreenSporeExtraSmall()
	{
		if (m_ParticleEfx)
			m_ParticleEfx.Stop();
	}
}
