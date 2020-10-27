modded class MissionGameplay
{
	ref CodaFramework m_CodaFramework;

	private ref CodaFramework GetCodaFramework()
	{
		if ( !m_CodaFramework ) {
			m_CodaFramework = new ref CodaFramework;
		}

		return m_CodaFramework;
	}

	override void OnMissionStart()
	{
		super.OnMissionStart();
		GetCodaFramework();
	}


};