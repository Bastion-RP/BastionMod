modded class MainMenu extends UIScriptedMenu
{
	protected Widget m_Forums;
	protected TextWidget m_WelcomeBack;

	override Widget Init()
	{
		layoutRoot = GetGame().GetWorkspace().CreateWidgets( "BastionMod/BastionMenu/gui/layouts/new_ui/main_menu.layout" );
		
		m_Play						= layoutRoot.FindAnyWidget( "PlayButton" );
		m_ChooseServer				= layoutRoot.FindAnyWidget( "ServerButton" );
		m_CustomizeCharacter		= layoutRoot.FindAnyWidget( "CharacterButton" );
		m_PlayVideo					= layoutRoot.FindAnyWidget( "play_video" );
		m_Tutorials					= layoutRoot.FindAnyWidget( "tutorials" );
		m_TutorialButton			= layoutRoot.FindAnyWidget( "tutorial_button" );
		m_MessageButton				= layoutRoot.FindAnyWidget( "message_button" );
		m_SettingsButton			= layoutRoot.FindAnyWidget( "SettingsButton" );
		m_Exit						= layoutRoot.FindAnyWidget( "ExitButton" );
		m_PrevCharacter				= layoutRoot.FindAnyWidget( "prev_character" );
		m_NextCharacter				= layoutRoot.FindAnyWidget( "next_character" );

		m_Forums					= layoutRoot.FindAnyWidget( "ForumsButton" );

		m_Version					= TextWidget.Cast( layoutRoot.FindAnyWidget( "version" ) );
		m_ModdedWarning				= TextWidget.Cast( layoutRoot.FindAnyWidget( "ModdedWarning" ) );
		m_CharacterRotationFrame	= layoutRoot.FindAnyWidget( "character_rotation_frame" );
		
		m_LastPlayedTooltip			= layoutRoot.FindAnyWidget( "last_server_info" );
		m_LastPlayedTooltip.Show(false);
		m_LastPlayedTooltipLabel	= m_LastPlayedTooltip.FindAnyWidget( "last_server_info_label" );
		m_LastPlayedTooltipName 	= TextWidget.Cast( m_LastPlayedTooltip.FindAnyWidget( "last_server_info_name" ) );
		m_LastPlayedTooltipIP		= TextWidget.Cast( m_LastPlayedTooltip.FindAnyWidget( "last_server_info_ip" ) );
		m_LastPlayedTooltipPort		= TextWidget.Cast( m_LastPlayedTooltip.FindAnyWidget( "last_server_info_port" ) );
		
		m_LastPlayedTooltipTimer	= new WidgetFadeTimer();
		
		m_Stats						= new MainMenuStats( layoutRoot.FindAnyWidget( "character_stats_root" ) );
		
		m_Mission					= MissionMainMenu.Cast( GetGame().GetMission() );
		
		m_LastFocusedButton = 		m_Play;

		m_ScenePC					= m_Mission.GetIntroScenePC();
		
		if( m_ScenePC )
		{
			m_ScenePC.ResetIntroCamera();
		}
		
		m_PlayVideo.Show( false );
		
		m_WelcomeBack = TextWidget.Cast(layoutRoot.FindAnyWidget("WelcomeBack"));
		m_PlayerName = TextWidget.Cast(layoutRoot.FindAnyWidget("character_name_text"));
		SetPlayerName();
		
		// Set Version
		string version;
		GetGame().GetVersion( version );
		m_Version.SetText( "#main_menu_version" + " " + version );
		
		GetGame().GetUIManager().ScreenFadeOut(0);

		SetFocus( null );
		
		Refresh();
		
		LoadMods();
		
		GetDayZGame().GetBacklit().MainMenu_OnShow();
	
		g_Game.SetLoadState( DayZLoadState.MAIN_MENU_CONTROLLER_SELECT );
		
		return layoutRoot;
	}

	void SetPlayerName()
	{
		if (m_PlayerName && m_WelcomeBack)
		{
			string name;
			GetCLIParam("name", name);
			if (!name) name = "Survivor";

			m_PlayerName.SetText(name);
		}
	}

	override void OnChangeCharacter()
	{
		super.OnChangeCharacter();
		SetPlayerName();
	}
	
	override bool OnClick(Widget w, int x, int y, int button)
	{
		if (button == MouseState.LEFT && w == m_Forums)
		{
			GetGame().OpenURL("https://bastionrp.com/forums/");
			return true;
		}

		return super.OnClick(w, x, y, button);
	}
	
	override bool IsFocusable( Widget w )
	{
		if( w )
		{
			if( w == m_Play || w == m_ChooseServer || w == m_CustomizeCharacter || w == m_TutorialButton || w == m_MessageButton || w == m_SettingsButton || w == m_Forums );
			{
				return true;
			}
			
			if( w == m_Exit || w == m_PlayVideo );
			{
				return true;
			}
			
			if( w == m_NewsMain || w == m_NewsSec1 || w == m_NewsSec2 || w == m_PrevCharacter || w == m_NextCharacter );
			{
				return true;
			}
		}
		return false;
	}
	
	override void Play()
	{
		g_Game.ConnectFromServerBrowser("51.81.48.230", 2302, "rainsofafrica");
	}
		
	//Coloring functions (Until WidgetStyles are useful)
	override void ColorHighlight( Widget w )
	{
		if( !w )
			return;
		
		//SetFocus( w );
		
		int color_pnl = ARGB(255, 0, 0, 0);
		int color_lbl = ARGB(255, 255, 168, 0);
		int color_img = ARGB(255, 255, 168, 0);
		
		#ifdef PLATFORM_CONSOLE
			color_pnl = ARGB(255, 255, 168, 0);
			color_lbl = ARGB(255, 255, 168, 0);
		#endif
		
		ButtonSetColor(w, color_pnl);
		ButtonSetTextColor(w, color_lbl);
		ImagenSetColor(w, color_img);
	}
	
	override void ButtonSetText( Widget w, string text )
	{
		if( !w )
			return;
				
		TextWidget label = TextWidget.Cast(w.FindWidget( w.GetName() + "_label" ) );
		
		if( label )
		{
			label.SetText( text );
		}
		
	}
}
