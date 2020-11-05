modded class OptionsMenu extends UIScriptedMenu
{
	protected Widget m_Separator;

	override Widget Init()
	{
		m_Options			= new GameOptions();
		
		#ifdef PLATFORM_CONSOLE
			layoutRoot		= GetGame().GetWorkspace().CreateWidgets( "BastionMod/BastionMenu/gui/layouts/new_ui/options/xbox/options_menu.layout", null );
		#else
		#ifdef PLATFORM_WINDOWS
			layoutRoot		= GetGame().GetWorkspace().CreateWidgets( "BastionMod/BastionMenu/gui/layouts/new_ui/options/pc/options_menu.layout", null );
		#endif
		#endif
		
		layoutRoot.FindAnyWidget( "Tabber" ).GetScript( m_Tabber );
		
		m_Details			= layoutRoot.FindAnyWidget( "settings_details" );
		m_Version			= TextWidget.Cast( layoutRoot.FindAnyWidget( "version" ) );
		
		m_GameTab			= new OptionsMenuGame( layoutRoot.FindAnyWidget( "Tab_0" ), m_Details, m_Options, this );
		m_SoundsTab			= new OptionsMenuSounds( layoutRoot.FindAnyWidget( "Tab_1" ), m_Details, m_Options, this );
		
		#ifdef PLATFORM_CONSOLE
			m_ControlsTab	= new OptionsMenuControls( layoutRoot.FindAnyWidget( "Tab_2" ), m_Details, m_Options, this );
		#else
		#ifdef PLATFORM_WINDOWS
			m_VideoTab		= new OptionsMenuVideo( layoutRoot.FindAnyWidget( "Tab_2" ), m_Details, m_Options, this );
			m_ControlsTab	= new OptionsMenuControls( layoutRoot.FindAnyWidget( "Tab_3" ), m_Details, m_Options, this );
		#endif
		#endif
		
		m_Apply				= ButtonWidget.Cast( layoutRoot.FindAnyWidget( "apply" ) );
		m_Back				= ButtonWidget.Cast( layoutRoot.FindAnyWidget( "back" ) );
		m_Reset				= ButtonWidget.Cast( layoutRoot.FindAnyWidget( "reset" ) );

		m_Separator			= layoutRoot.FindAnyWidget( "separator_red" );
		m_Separator.SetColor( ARGB( 255, 255, 168, 0 ) );
		
		string version;
		GetGame().GetVersion( version );
		#ifdef PLATFORM_CONSOLE
			version = "#main_menu_version" + " " + version + " (" + g_Game.GetDatabaseID() + ")";
		#else
			version = "#main_menu_version" + " " + version;
		#endif
		m_Version.SetText( version );
		
		#ifdef PLATFORM_WINDOWS
			SetFocus( layoutRoot );
		#else
			ToggleFocus();
		#endif
		
		m_Tabber.m_OnTabSwitch.Insert( OnTabSwitch );
		
		#ifdef PLATFORM_PS4
			string confirm = "cross";
			string back = "circle";
			if( GetGame().GetInput().GetEnterButton() == GamepadButton.A )
			{
				confirm = "cross";
				back = "circle";
			}
			else
			{
				confirm = "circle";
				back = "cross";
			}
			ImageWidget toolbar_a = layoutRoot.FindAnyWidget( "ToggleIcon" );
			ImageWidget toolbar_b = layoutRoot.FindAnyWidget( "BackIcon" );
			ImageWidget toolbar_b2 = layoutRoot.FindAnyWidget( "BackIcon0" );
			ImageWidget toolbar_x = layoutRoot.FindAnyWidget( "ApplyIcon" );
			ImageWidget toolbar_x2 = layoutRoot.FindAnyWidget( "ApplyIcon0" );
			ImageWidget toolbar_y = layoutRoot.FindAnyWidget( "ResetIcon" );
			ImageWidget toolbar_y2 = layoutRoot.FindAnyWidget( "ResetIcon0" );
			toolbar_a.LoadImageFile( 0, "set:playstation_buttons image:" + confirm );
			toolbar_b2.LoadImageFile( 0, "set:playstation_buttons image:" + back );
			toolbar_b.LoadImageFile( 0, "set:playstation_buttons image:" + back );
			toolbar_x.LoadImageFile( 0, "set:playstation_buttons image:square" );
			toolbar_x2.LoadImageFile( 0, "set:playstation_buttons image:square" );
			toolbar_y.LoadImageFile( 0, "set:playstation_buttons image:triangle" );
			toolbar_y2.LoadImageFile( 0, "set:playstation_buttons image:triangle" );
		#endif
		
		OnChanged();
		
		return layoutRoot;
	}

	override void ColorHighlight( Widget w )
	{
		if( w.IsInherited( ButtonWidget ) )
		{
			ButtonWidget button = ButtonWidget.Cast( w );
			button.SetTextColor( ARGB( 255, 255, 168, 0 ) );
		}
		
		w.SetColor( ARGB( 255, 0, 0, 0) );
		
		TextWidget text1	= TextWidget.Cast(w.FindAnyWidget( w.GetName() + "_text" ) );
		TextWidget text2	= TextWidget.Cast(w.FindAnyWidget( w.GetName() + "_label" ) );
		TextWidget text3	= TextWidget.Cast(w.FindAnyWidget( w.GetName() + "_text_1" ) );
		ImageWidget image	= ImageWidget.Cast( w.FindAnyWidget( w.GetName() + "_image" ) );
		Widget option		= Widget.Cast( w.FindAnyWidget( w.GetName() + "_option_wrapper" ) );
		Widget option_label = w.FindAnyWidget( "option_label" );
		
		if( text1 )
		{
			text1.SetColor( ARGB( 255, 255, 168, 0 ) );
		}
		
		if( text2 )
		{
			text2.SetColor( ARGB( 255, 255, 168, 0 ) );
		}
		
		if( text3 )
		{
			text3.SetColor( ARGB( 255, 255, 168, 0 ) );
			w.SetAlpha(1);
		}
		
		if( image )
		{
			image.SetColor( ARGB( 255, 255, 168, 0 ) );
		}
		
		if ( option )
		{
			option.SetColor( ARGB( 255, 255, 168, 0 ) );
		}
		
		if ( option_label )
		{
			option_label.SetColor( ARGB( 255, 255, 168, 0 ) );
		}
	}

	void OnShow()
	{
		super.OnShow();
		PPEffects.SetBlurInventory(0.3);
	}

	void OnHide()
	{
		super.OnHide();
		PPEffects.SetBlurInventory(0);
	}
}
