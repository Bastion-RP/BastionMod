modded class MissionServer : MissionBase
{
	PluginDoorPersistence m_DoorPersistence = PluginDoorPersistence.Cast( GetPlugin( PluginDoorPersistence ) );
	float saveInterval 	= 60;
	float timeElapsed 	= 0;

	void ~MissionServer()
	{
		m_DoorPersistence.SavePersistence();
	}
	
	override void OnUpdate( float timeslice )
	{
		super.OnUpdate( timeslice );

		timeElapsed += timeslice;
		if (timeElapsed >= saveInterval)
		{
			timeElapsed = 0;
			m_DoorPersistence.SavePersistence();
		}
	}
}