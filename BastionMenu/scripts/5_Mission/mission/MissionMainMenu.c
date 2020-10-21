modded class MissionMainMenu
{
	private ref MainMenu  menuhud;
	private ref DayZIntroSceneNew dayzintroscenenew;

	override void OnInit()
	{
		CreateScene();
	}

	override void OnMissionStart()
	{
		if (menuhud == null)
			menuhud = UIScriptedMenu.Cast(g_Game.GetUIManager().EnterScriptedMenu( mainmenu, NULL ));


		g_Game.GetUIManager().ShowUICursor(true);
		g_Game.SetMissionState( DayZGame.MISSION_STATE_MAINMENU );
		g_Game.LoadingHide(true);
		ProgressAsync.DestroyAllPendingProgresses();
	}
	
	override void OnMissionFinish()
	{
		if( menuhud ) menuhud.Cleanup();

		GetGame().GetUIManager().CloseAll();
		menuhud = NULL;
		
		dayzintroscenenew.DestroyScene();
		dayzintroscenenew = NULL;
		g_Game.GetUIManager().ShowUICursor(false);
	}

	override void Reset()
	{
		delete dayzintroscenenew;
		CreateScene();
	}

	override void OnUpdate(float timeslice)
	{
		if ( g_Game.IsLoading() ) return;
				
		if (dayzintroscenenew)
			dayzintroscenenew.Update();

		GetGame().GetUIManager().ShowUICursor(true);
	}

	DayZIntroSceneNew GetIntroScene()
	{
		return dayzintroscenenew;
	}

	void CreateScene()
	{
		if (dayzintroscenenew == null)
			dayzintroscenenew = new DayZIntroSceneNew();
	}
}