modded class MainMenu  
{
	protected Widget      brp_ForumsLinkButton;
	protected Widget      brp_NewsBox;

	protected Widget 		  m_ViewPost;
	protected Widget 		  m_SettingsGame;
	protected Widget 		  m_SettingsAudio;
	protected Widget 		  m_SettingsVideo;
	protected Widget	    m_SettingsControls;

	protected TextWidget 	m_Player;
	protected TextWidget 	m_FirstName;
	protected TextWidget 	m_LastName;
	protected TextWidget 	m_AccountName1;
	protected TextWidget 	m_AccountName2;
	protected TextWidget 	m_TimeSurvivedValue;

	protected ImageWidget m_logoWidget;
	protected ImageWidget m_newsWidget;
	protected ImageWidget	m_viewWidget;
	protected ImageWidget	m_playWidget;

  protected ref PlayerData m_playerData;
  protected autoptr array<ref CharacterData> m_characters;

	override Widget Init()
 	{
 		layoutRoot           = GetGame().GetWorkspace().CreateWidgets( "Menu/gui/layouts/main_menu1.layout" );
		brp_ForumsLinkButton = layoutRoot.FindAnyWidget( "VisitForums" );
		brp_NewsBox          = layoutRoot.FindAnyWidget( "NewsBox" );
		m_Exit							 = layoutRoot.FindAnyWidget( "ExitGame" );
		m_Play						   = layoutRoot.FindAnyWidget( "play" );
		m_ViewPost  				 = layoutRoot.FindAnyWidget( "ViewPost" );
		m_SettingsGame			 = layoutRoot.FindAnyWidget( "Game" );
		m_SettingsAudio			 = layoutRoot.FindAnyWidget( "Sounds" );
		m_SettingsVideo			 = layoutRoot.FindAnyWidget( "Video" );
		m_SettingsControls	 = layoutRoot.FindAnyWidget( "Controls" );
		m_ChooseServer			 = layoutRoot.FindAnyWidget( "viewall" );
		m_SettingsButton 		 = layoutRoot.FindAnyWidget( "Settings" );
		m_Player						 = layoutRoot.FindAnyWidget( "Player" );
 		m_Mission						 = MissionMainMenu.Cast( GetGame().GetMission());
 		m_ScenePC						 = m_Mission.GetIntroScenePC();

		m_Stats						   = new MainMenuStats( layoutRoot.FindAnyWidget( "StatsFrme" ) );
    m_playerData         = new PlayerData;

		m_FirstName					 = layoutRoot.FindAnyWidget( "FirstName" );
		m_LastName					 = layoutRoot.FindAnyWidget( "LastName" );
		m_AccountName1			 = layoutRoot.FindAnyWidget( "AccountName1" );
		m_AccountName2			 = layoutRoot.FindAnyWidget( "AccountName2" );
    m_TimeSurvivedValue  = layoutRoot.FindAnyWidget( "PlaytimeTXT" );

 		if( m_ScenePC )
 		{
 			m_ScenePC.ResetIntroCamera();
      Print("######");
      CURLCore curlCore = GetCURLCore();
      Print(curlCore);
      if (!curlCore) {
        curlCore = CreateCURLCore();
      }
      curlCore.EnableDebug( true );
      CURLContext api = curlCore.GetCURLContext("https://bastionrp.com/api/");
      JsonSerializer js = new JsonSerializer();

      Print( "### Making a request to api..." );
      Print(m_ScenePC.GetIntroCharacter().GetCharacterObj().GetIdentity());
      Print(GetGame().GetPlayer());
      //string steamId = m_ScenePC.GetIntroCharacter().GetCharacterObj().GetIdentity().GetPlainId();
      string steamId = "76561198115443414";
      Print( "https://bastionrp.com/api/characters.php?steam_id=" + steamId );

      string string_data = api.GET_now( "characters.php?steam_id=" + steamId );
      Print( string_data );
      
      string error;
      bool ok = js.ReadFromString( m_playerData, string_data, error );
      Print(ok);
      if (!ok) {
        Print(error);
      }

      auto player_id = m_playerData.GetId();
      
      Print( "https://bastionrp.com/api/characters.php?player_id=" + player_id );
      string_data = api.GET_now( "characters.php?player_id=" + player_id );
      Print( string_data );

      ok = js.ReadFromString( m_characters, string_data, error );
      Print(ok);
      if (!ok) {
        Print(error);
      }
      
      auto player_name = m_playerData.GetName();
      m_AccountName1.SetText( player_name );
      m_AccountName2.SetText( player_name );

      if (m_characters && m_characters.Count() > 0) {
        auto firstChar = m_characters.Get(0);
        m_FirstName.SetText( firstChar.GetFirstName() );
        m_LastName.SetText( firstChar.GetLastName() );
      }
      Print("######");
    }

 		GetGame().GetUIManager().ScreenFadeOut(0);
 		SetFocus( null );
 		Refresh();
 		// LoadMods();
 		GetDayZGame().GetBacklit().MainMenu_OnShow();

 		g_Game.SetLoadState( DayZLoadState.MAIN_MENU_CONTROLLER_SELECT );

		Class.CastTo(m_logoWidget, layoutRoot.FindAnyWidget("bastion_logo"));
		m_logoWidget.LoadImageFile( 0, "Menu/gui/images/bastionlogo.edds" );

		Class.CastTo(m_newsWidget, layoutRoot.FindAnyWidget("NewsBox"));
		m_newsWidget.LoadImageFile( 0, "Menu/gui/images/NewsBlock.edds" );

		Class.CastTo(m_playWidget, layoutRoot.FindAnyWidget("PlayLastIMG"));
		m_playWidget.LoadImageFile( 0, "Menu/gui/images/PlayLastServer.edds" );

		Class.CastTo(m_viewWidget, layoutRoot.FindAnyWidget("ViewAllIMG"));
		m_viewWidget.LoadImageFile( 0, "Menu/gui/images/ViewAllServers.edds" );

 		return layoutRoot;
 	}

	OptionsMenu OpenReturnSettings()
	{
		return OptionsMenu.Cast(EnterScriptedMenu(MENU_OPTIONS));
	}

	override bool OnClick( Widget w, int x, int y, int button )
	{
		if( button == MouseState.LEFT )
		{
			if ( w == m_Exit )
			{
				Exit();
				return true;
			}
			else if ( w == brp_ForumsLinkButton )
			{
				GetGame().OpenURL( "https://bastionrp.com/forums" );
				return true;
			}
			else if ( w == brp_NewsBox )
			{
				GetGame().OpenURL( "https://bastionrp.com/forums/topic/486-sitrep-009-2142020-surveillance/");
				return true;
			}
			else if ( w == m_SettingsButton )
			{
				OpenSettings();
				return true;
			}
			else if ( w == m_SettingsGame )
			{
				OpenSettings();
				return true;
			}
			else if ( w == m_SettingsAudio )
			{
        OpenReturnSettings().SkipTabs(1);
				return true;
			}
			else if ( w == m_SettingsVideo )
			{
        OpenReturnSettings().SkipTabs(2);
				return true;
			}
			else if ( w == m_SettingsControls )
			{
        OpenReturnSettings().SkipTabs(3);
				return true;
			}
			else if( w == m_Play )
			{
				m_LastFocusedButton = m_Play;
				Play();
				return true;
			}
			else if ( w == m_ChooseServer )
			{
				m_LastFocusedButton = m_ChooseServer;
				OpenMenuServerBrowser();
				return true;
			}
		}
		return false;
	}

	override bool OnMouseEnter( Widget w, int x, int y )
	{
		if( w == m_Play )
		{
		  return false;
		}
    return super.OnMouseEnter( w, x, y );
	}

	override bool OnMouseLeave( Widget w, Widget enterW, int x, int y )
	{
		if( w == m_Play )
		{
		  return false;
		}
    return super.OnMouseLeave( w, enterW, x, y );
	}

  override void Refresh()
	{
		string name;

		if( m_ScenePC )
		{
			OnChangeCharacter();
			
			//update character stats
			m_Stats.UpdateStats();
		}
	}

	override void OnChangeCharacter() {}

	override void LoadMods() {}
}
