modded class MainMenu  
{
	protected Widget      m_ForumsLinkButton;

	protected Widget 		  m_ViewPost;
	protected Widget 		  m_SettingsGame;
	protected Widget 		  m_SettingsAudio;
	protected Widget 		  m_SettingsVideo;
	protected Widget	    m_SettingsControls;
	protected Widget      m_NewsButton;
	protected Widget			m_ViewCharacter;

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
 		layoutRoot           			= GetGame().GetWorkspace().CreateWidgets( "BastionMod/BastionMenu/gui/layouts/main_menu.layout" );
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
		m_ViewCharacter      			= layoutRoot.FindAnyWidget( "ViewCharacter" );
		m_CharacterRotationFrame	= layoutRoot.FindAnyWidget( "character_rotation_frame" );
		m_NewsButton							= layoutRoot.FindAnyWidget( "NewsButton" );
 		m_Mission						 			= MissionMainMenu.Cast( GetGame().GetMission());
 		m_ScenePC						 			= m_Mission.GetIntroScenePC();

		m_Stats						   			= new MainMenuStats( layoutRoot.FindAnyWidget( "StatsFrme" ) );
    m_PlayerData         			= new MenuPlayerData;

		m_Player						 			= TextWidget.Cast( layoutRoot.FindAnyWidget( "Player" ) );
		m_FirstName					 			= TextWidget.Cast( layoutRoot.FindAnyWidget( "FirstName" ) );
		m_LastName					 			= TextWidget.Cast( layoutRoot.FindAnyWidget( "LastName" ) );
		m_Welcome			 						= TextWidget.Cast( layoutRoot.FindAnyWidget( "Welcome" ) );
		m_ForumsAccount			 			= TextWidget.Cast( layoutRoot.FindAnyWidget( "LinkedAccount" ) );
    m_TimeSurvivedValue  			= TextWidget.Cast( layoutRoot.FindAnyWidget( "PlaytimeTXT" ) );
		m_CitizenClass						= TextWidget.Cast( layoutRoot.FindAnyWidget( "CitizenClassValue" ) );
		m_NewsButtonText					= TextWidget.Cast( layoutRoot.FindAnyWidget( "NewsButtonText" ) );
		m_NoUIDWarning					  = TextWidget.Cast( layoutRoot.FindAnyWidget( "NoUIDWarning" ) );
		m_RationCardsValue				= TextWidget.Cast( layoutRoot.FindAnyWidget( "RationCardsValue" ) );
		m_LastServer							= TextWidget.Cast( layoutRoot.FindAnyWidget( "LastServer" ) );
		m_LocationValue						= TextWidget.Cast( layoutRoot.FindAnyWidget( "LocationValue" ) );
		m_AllServers							= TextWidget.Cast( layoutRoot.FindAnyWidget( "AllServers" ) );

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
		m_logoWidget.LoadImageFile( 0, "BastionMod/BastionMenu/gui/images/bastionlogo.edds" );

		Class.CastTo(m_newsWidget, layoutRoot.FindAnyWidget("NewsBox"));
		m_newsWidget.LoadImageFile( 0, "BastionMod/BastionMenu/gui/images/009Block.edds" );
 		return layoutRoot;
 	}

	bool LoadStoredData()
	{
		StoredDataHook storedDataHook = MissionGameplay.GetStoredDataHook();
		return storedDataHook.LoadData();
	}

  	RestApi FetchCurlCore()
	{
		RestApi curlCore = GetRestApi();

		if (!curlCore) {
			curlCore = CreateRestApi();
		}

		return curlCore;
	}

	bool LoadAPIData()
	{
		string string_data, error;
		bool ok;
		string apiBase = BASTION_API_ENDPOINT;
		RestApi curlCore = FetchCurlCore();
		RestContext api = curlCore.GetRestContext(apiBase);
		JsonSerializer js = new JsonSerializer();

		string_data = api.GET_now( BASTION_API_ANNOUNCEMENTS );
		ok = js.ReadFromString( m_NewsData, string_data, error );
		if (!ok) {
			Print(error);
			return false;
		}

		if (!m_hasStoredData) return false;

		StoredData storedData = MissionGameplay.GetStoredDataHook().m_storedData;

		string steamId = storedData.GetSteamId();

		string_data = api.GET_now( BASTION_API_CHARACTERS_STEAM + steamId );
		ok = js.ReadFromString( m_PlayerData, string_data, error );
		if (!ok) {
			Print(error);
			return false;
		}

		string player_id = m_PlayerData.GetId();
		
		string_data = api.GET_now( BASTION_API_CHARACTERS_PID + player_id );
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

		m_AllServers.SetText( "1 BastionRP Server Online" );

		if (!LoadAPIData()) {
			m_FirstName.SetText( "" );
			m_LastName.SetText( "" );
			m_RationCardsValue.SetText( "N/A" );
			m_CitizenClass.SetText( "N/A" );
			m_LocationValue.SetText( "N/A" );
			m_LastServer.SetText( "No last server on record" );
			m_Play.Enable( false );
			m_ViewCharacter.Show( false );
			Print("###### No data for main menu to show ######");
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
		} else {
			m_ViewCharacter.Show( false );
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
				GetGame().OpenURL( BASTION_FORUMS_LINK );
				return true;
			}
			else if ( w == m_NewsButton )
			{
				string link = m_NewsData.GetLink();
				if (!link) {
					link = BASTION_ANNOUNCEMENTS_LINK;
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
			else if ( w == m_ViewCharacter )
			{
				if (m_Characters && m_Characters.Count() > 0) {
					GetGame().OpenURL( BASTION_CHARACTER_URL_PREFIX + m_Characters.Get(0).GetId() + "/" );
				}
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
