modded class MainMenu  
{
	protected Widget      m_ForumsLinkButton;

	protected Widget 		  m_ViewPost;
	protected Widget 		  m_SettingsGame;
	protected Widget 		  m_SettingsAudio;
	protected Widget 		  m_SettingsVideo;
	protected Widget	    m_SettingsControls;
	protected Widget      m_NewsButton;

	protected TextWidget 	m_Player;
	protected TextWidget 	m_FirstName;
	protected TextWidget 	m_LastName;
	protected TextWidget 	m_Welcome;
	protected TextWidget 	m_ForumsAccount;
	protected TextWidget 	m_TimeSurvivedValue;
	protected TextWidget  m_CitizenClass;
	protected TextWidget  m_NewsButtonText;
	protected TextWidget  m_NoUIDWarning;
	protected TextWidget  m_RationCardsValue;
	protected TextWidget  m_LastServer;
	protected TextWidget  m_LocationValue;
	protected TextWidget  m_AllServers;

	protected ImageWidget m_logoWidget;
	protected ImageWidget m_newsWidget;
	protected ImageWidget	m_viewWidget;
	protected ImageWidget	m_playWidget;

  protected ref MenuPlayerData							 m_PlayerData;
  protected autoptr array<ref CharacterData> m_Characters;
	protected ref NewsData 										 m_NewsData;
	protected bool														 m_hasStoredData;

	override Widget Init()
 	{
 		layoutRoot           			= GetGame().GetWorkspace().CreateWidgets( "BastionMenu/gui/layouts/main_menu.layout" );
		m_ForumsLinkButton 			  = layoutRoot.FindAnyWidget( "VisitForums" );
		m_Exit							 			= layoutRoot.FindAnyWidget( "ExitGame" );
		m_Play						   			= layoutRoot.FindAnyWidget( "play" );
		m_ViewPost  				 			= layoutRoot.FindAnyWidget( "ViewPost" );
		m_SettingsGame			 			= layoutRoot.FindAnyWidget( "Game" );
		m_SettingsAudio			 			= layoutRoot.FindAnyWidget( "Sounds" );
		m_SettingsVideo			 			= layoutRoot.FindAnyWidget( "Video" );
		m_SettingsControls	 			= layoutRoot.FindAnyWidget( "Controls" );
		m_ChooseServer			 			= layoutRoot.FindAnyWidget( "viewall" );
		m_SettingsButton 		 			= layoutRoot.FindAnyWidget( "Settings" );
		m_CustomizeCharacter      = layoutRoot.FindAnyWidget( "ChangeChar" );
		m_CharacterRotationFrame	= layoutRoot.FindAnyWidget( "character_rotation_frame" );
		m_Player						 			= layoutRoot.FindAnyWidget( "Player" );
		m_NewsButton							= layoutRoot.FindAnyWidget( "NewsButton" );
 		m_Mission						 			= MissionMainMenu.Cast( GetGame().GetMission());
 		m_ScenePC						 			= m_Mission.GetIntroScenePC();

		m_Stats						   			= new MainMenuStats( layoutRoot.FindAnyWidget( "StatsFrme" ) );
    m_PlayerData         			= new MenuPlayerData;

		m_FirstName					 			= layoutRoot.FindAnyWidget( "FirstName" );
		m_LastName					 			= layoutRoot.FindAnyWidget( "LastName" );
		m_Welcome			 						= layoutRoot.FindAnyWidget( "Welcome" );
		m_ForumsAccount			 			= layoutRoot.FindAnyWidget( "LinkedAccount" );
    m_TimeSurvivedValue  			= layoutRoot.FindAnyWidget( "PlaytimeTXT" );
		m_CitizenClass						= layoutRoot.FindAnyWidget( "CitizenClassValue" );
		m_NewsButtonText					= layoutRoot.FindAnyWidget( "NewsButtonText" );
		m_NoUIDWarning					  = layoutRoot.FindAnyWidget( "NoUIDWarning" );
		m_RationCardsValue				= layoutRoot.FindAnyWidget( "RationCardsValue" );
		m_LastServer							= layoutRoot.FindAnyWidget( "LastServer" );
		m_LocationValue						= layoutRoot.FindAnyWidget( "LocationValue" );
		m_AllServers							= layoutRoot.FindAnyWidget( "AllServers" );

		m_hasStoredData = LoadStoredData();
		m_NoUIDWarning.Show( !m_hasStoredData );

 		if( m_ScenePC )
 		{
 			m_ScenePC.ResetIntroCamera();
			SetCharacterDetails();
			if ( m_NewsData )
				m_NewsButtonText.SetText( m_NewsData.GetTitle() );
    }

 		GetGame().GetUIManager().ScreenFadeOut(0);
 		SetFocus( null );
 		Refresh();
 		// LoadMods();
 		GetDayZGame().GetBacklit().MainMenu_OnShow();

 		g_Game.SetLoadState( DayZLoadState.MAIN_MENU_CONTROLLER_SELECT );

		Class.CastTo(m_logoWidget, layoutRoot.FindAnyWidget("bastion_logo"));
		m_logoWidget.LoadImageFile( 0, "BastionMenu/gui/images/bastionlogo.edds" );

		Class.CastTo(m_newsWidget, layoutRoot.FindAnyWidget("NewsBox"));
		m_newsWidget.LoadImageFile( 0, "BastionMenu/gui/images/009Block.edds" );
 		return layoutRoot;
 	}

	bool LoadStoredData()
	{
		StoredDataHook storedDataHook = MissionGameplay.GetStoredDataHook();
		return storedDataHook.LoadData();
	}

  CURLCore FetchCurlCore()
	{
		CURLCore curlCore = GetCURLCore();

		if (!curlCore) {
			curlCore = CreateCURLCore();
		}

		return curlCore;
	}

	bool LoadAPIData()
	{
		string string_data, error;
		bool ok;
		string apiBase = "https://bastionrp.com/api/";
		CURLCore curlCore = FetchCurlCore();
		CURLContext api = curlCore.GetCURLContext(apiBase);
		JsonSerializer js = new JsonSerializer();

		Print( "GET " + apiBase + "forum.php?last_post=24" );
		string_data = api.GET_now( "forum.php?last_post=24" );
		ok = js.ReadFromString( m_NewsData, string_data, error );
		if (!ok) {
			Print(error);
			return false;
		}

		if (!m_hasStoredData) return false;

		StoredData storedData = MissionGameplay.GetStoredDataHook().m_storedData;

		string steamId = storedData.GetSteamId();
		Print( "GET " + apiBase + "characters.php?steam_id=" + steamId );

		string_data = api.GET_now( "characters.php?steam_id=" + steamId );
		ok = js.ReadFromString( m_PlayerData, string_data, error );
		if (!ok) {
			Print(error);
			return false;
		}

		string player_id = m_PlayerData.GetId();
		
		Print( "GET " + apiBase + "characters.php?player_id=" + player_id );
		string_data = api.GET_now( "characters.php?player_id=" + player_id );
		Print(string_data);
		ok = js.ReadFromString( m_Characters, string_data, error );
		if (!ok) {
			Print(error);
			return false;
		}

		return true;
	}

	void SetCharacterDetails()
	{
		Print("###### Loading Character Details From API ######");

		// TODO: Find all servers with BastionRP in their name and show count here
		m_AllServers.SetText( "1 BastionRP Server Online" );

		if (!LoadAPIData()) {
			m_FirstName.SetText( "" );
			m_LastName.SetText( "" );
			m_RationCardsValue.SetText( "N/A" );
			m_CitizenClass.SetText( "N/A" );
			m_LocationValue.SetText( "N/A" );
			m_LastServer.SetText( "No last server on record" );
			m_Play.Enable( false );
			return;
		}

		auto storedData = MissionGameplay.GetStoredDataHook().m_storedData;

		auto player_name = m_PlayerData.GetName();
		m_Welcome.SetText( "Welcome back, " + player_name + "!" );
		m_ForumsAccount.SetText( "Linked account - " + player_name );
		m_RationCardsValue.SetText( "" + storedData.GetRations() );
		m_LocationValue.SetText( storedData.GetLocation() );
		m_LastServer.SetText( storedData.GetLastServer() );

		if (m_Characters && m_Characters.Count() > 0) {
			auto activeChar = m_Characters.Get(0);
			foreach (auto candidate : m_Characters) {
				if (candidate.GetActive()) {
					activeChar = candidate;
					break;
				}
			}
			m_FirstName.SetText( activeChar.GetFirstName() );
			m_LastName.SetText( activeChar.GetLastName() );
			m_CitizenClass.SetText( activeChar.GetCitizenClass() );
		}

		Print("###### Loaded Character Data From API ######");
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
			else if ( w == m_ForumsLinkButton )
			{
				GetGame().OpenURL( "https://bastionrp.com/forums" );
				return true;
			}
			else if ( w == m_NewsButton )
			{
				string link = m_NewsData.GetLink();
				Print(link);
				if (!link) {
					link = "https://bastionrp.com/forums/forum/24-announcements/";
				}
				GetGame().OpenURL( link );
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
			else if( w == m_Play && m_hasStoredData )
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
			else if ( w == m_CustomizeCharacter )
			{
				OpenMenuCustomizeCharacter();
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
