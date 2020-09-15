modded class LoadingScreen
{
	protected TextWidget m_RandomMessages;

	ref TStringArray loadingscreens = 
	{	
		"BastionMod/BastionMenu/gui/data/loading_1.edds",
		"BastionMod/BastionMenu/gui/data/loading_1.edds"		
	};	

	void Show()
	{
		string lscreen = loadingscreens.GetRandomElement();	
		m_ImageWidgetBackground.LoadMaskTexture("");
        ImageWidget background = ImageWidget.Cast( m_WidgetRoot.FindAnyWidget("ImageBackground"));		
		m_ImageWidgetBackground.LoadImageFile(0, lscreen); 
		
		Widget lIcon = m_ImageBackground;
		Widget pText = m_ProgressLoading;
		m_ProgressText.SetText("");
		m_ProgressLoading.SetCurrent( 0.0 );
		m_ImageBackground.SetMaskProgress( 0.0 );
		
		if ( !m_WidgetRoot.IsVisible() )
		{
			if ( m_DayZGame.GetUIManager().IsDialogVisible() )
			{
				m_DayZGame.GetUIManager().HideDialog();
			}
			
			if ( m_DayZGame.GetMissionState() == DayZGame.MISSION_STATE_MAINMENU )
			{
				m_ImageLogoMid.Show(false);
				m_ImageLogoCorner.Show(false);				
				m_ImageWidgetBackground.Show( true );		
				m_TextWidgetStatus.Show(true);
			}
			else
			{
				m_ImageLogoMid.Show(false);
				m_ImageLogoCorner.Show(false);
				m_ImageWidgetBackground.Show( true );
				m_TextWidgetStatus.Show(false);
			}
			
			m_WidgetRoot.Show( true );
			m_TextWidgetTitle.SetText( "" );
			m_TextWidgetStatus.SetText( "" );
		}
		
		ProgressAsync.SetProgressData(pText);
		ProgressAsync.SetUserData(lIcon);
	}
	
	void LoadingScreen(DayZGame game)
	{
		
		m_DayZGame = game;
		
		m_WidgetRoot = game.GetLoadingWorkspace().CreateWidgets("BastionMod/BastionMenu/gui/layouts/loading.layout");

		Class.CastTo(m_ImageLogoMid, m_WidgetRoot.FindAnyWidget("ImageLogoMid"));
		Class.CastTo(m_ImageLogoCorner, m_WidgetRoot.FindAnyWidget("ImageLogoCorner"));
		Class.CastTo(m_TextWidgetTitle, m_WidgetRoot.FindAnyWidget("TextWidget"));
		Class.CastTo(m_TextWidgetStatus, m_WidgetRoot.FindAnyWidget("StatusText"));
		Class.CastTo(m_ImageWidgetBackground, m_WidgetRoot.FindAnyWidget("ImageBackground"));
		Class.CastTo(m_ImageLoadingIcon, m_WidgetRoot.FindAnyWidget("ImageLoadingIcon"));
		Class.CastTo(m_ModdedWarning, m_WidgetRoot.FindAnyWidget("ModdedWarning"));

		m_RandomMessages = TextWidget.Cast( m_WidgetRoot.FindAnyWidget("RandomMessages") );
		
		m_ImageBackground = ImageWidget.Cast( m_WidgetRoot.FindAnyWidget("ImageBackground") );
		m_ProgressLoading = ProgressBarWidget.Cast( m_WidgetRoot.FindAnyWidget("LoadingBar") );

		m_ProgressLoading.SetColor (ARGB(255, 255, 168, 0));
		
		string tmp;
		m_ProgressText = TextWidget.Cast(m_WidgetRoot.FindAnyWidget("ProgressText"));
		if (GetGame())
		{
			m_ProgressText.Show( GetGame().CommandlineGetParam("loadingTest", tmp) );
		}
		
		
		m_ModdedWarning.Show(false);
		m_ImageLogoMid.Show(true);
		m_ImageLogoCorner.Show(false);
		m_ImageWidgetBackground.Show( true );		
		m_Counter = 0;
				
		game.GetBacklit().LoadingAnim();
		
		ProgressAsync.SetProgressData(m_ProgressLoading);
		ProgressAsync.SetUserData(m_ImageBackground);
	}
};
