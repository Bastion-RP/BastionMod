modded class MainMenu  
 { 
	 protected Widget         brp_ForumsLinkButton;

	 protected Widget 		  m_ViewPost;
	 protected Widget 		  m_SettingsGame;
	 protected Widget 		  m_SettingsAudio;
	 protected Widget 		  m_SettingsVideo;
	 protected Widget	      m_SettingsControls;

	 protected TextWidget 	  m_Player;

	 protected ImageWidget 	  m_logoWidget;
	 protected ImageWidget 	  m_newsWidget;
	 protected ImageWidget	  m_viewWidget; 
	 protected ImageWidget	  m_playWidget;
	 
	 
     override Widget Init() 

 	{ 
 		layoutRoot = GetGame().GetWorkspace().CreateWidgets( "Menu/gui/layouts/main_menu1.layout" ); 
 		 
		brp_ForumsLinkButton        = layoutRoot.FindAnyWidget( "ForumsLinkButton" );

		m_Exit						= layoutRoot.FindAnyWidget( "ExitGame" );

		m_Play						= layoutRoot.FindAnyWidget( "play" );

		m_ViewPost  				= layoutRoot.FindAnyWidget( "ViewPost" );

		m_SettingsGame				= layoutRoot.FindAnyWidget( "Game" );

		m_SettingsAudio				= layoutRoot.FindAnyWidget( "Sounds" );

		m_SettingsVideo				= layoutRoot.FindAnyWidget( "Video" );

		m_SettingsControls			= layoutRoot.FindAnyWidget( "Controls" );

		m_ChooseServer				= layoutRoot.FindAnyWidget(	"viewall" );

		m_SettingsButton 			= layoutRoot.FindAnyWidget( "Settings" );

		m_Player					= layoutRoot.FindAnyWidget( "Player" );
		
 		m_Mission					= MissionMainMenu.Cast( GetGame().GetMission() ); 
 		 
 		m_ScenePC					= m_Mission.GetIntroScenePC(); 
 		 
 		if( m_ScenePC ) 
 		{ 
 			m_ScenePC.ResetIntroCamera(); 
 		} 
 		 
 		GetGame().GetUIManager().ScreenFadeOut(0); 
		 

 		SetFocus( null ); 
 		 
 		Refresh(); 
 		 
 		LoadMods(); 
 		 
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
                GetGame().OpenURL( "https://bastionrp.com/" );
            
                return true;
            }
			else if ( w == m_SettingsButton )
			{
				OpenSettings();
				return true; 
			}
			else if ( w == m_ViewPost )
			{
				GetGame().OpenURL( "https://bastionrp.com/");

				return true;
			}

			else if ( w == m_SettingsGame )
			{
				OpenSettings();
				m_GameTab.Focus();
				return true; 
			}

			else if ( w == m_SettingsAudio )
			{
				OpenSettings();
				m_SoundsTab.Focus();
				return true; 
			}

			else if ( w == m_SettingsVideo )
			{
				OpenSettings();
				m_VideoTab.Focus();
				return true; 
			}

			else if ( w == m_SettingsControls )
			{
				OpenSettings();
				m_ControlsTab.Focus();
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
 

 	override void Refresh() 
 	{ 
 		if( m_ScenePC ) 
 		{ 
 			OnChangeCharacter(); 
 		}	

	 }	 
 
}; 
