modded class MainMenuStats
{
	override void UpdateStats()
	{
		PlayerBase player;
		MissionMainMenu mission_main_menu = MissionMainMenu.Cast( GetGame().GetMission() );
		
    player = mission_main_menu.GetIntroScenePC().GetIntroCharacter().GetCharacterObj();
		
		if ( player )
		{
			m_TimeSurvivedValue.SetText( GetTimeString( player.StatGet( AnalyticsManagerServer.STAT_PLAYTIME ) ) );
			//m_PlayersKilledValue.SetText( GetValueString( player.StatGet( AnalyticsManagerServer.STAT_PLAYERS_KILLED ) ) );
			//m_InfectedKilledValue.SetText( GetValueString( player.StatGet( AnalyticsManagerServer.STAT_INFECTED_KILLED ) ) );
			//m_DistanceTraveledValue.SetText( GetDistanceString( player.StatGet( AnalyticsManagerServer.STAT_DISTANCE ) ) );
			//m_LongRangeShotValue.SetText( GetDistanceString( player.StatGet( AnalyticsManagerServer.STAT_LONGEST_SURVIVOR_HIT ), true ) );
		}
	}
}