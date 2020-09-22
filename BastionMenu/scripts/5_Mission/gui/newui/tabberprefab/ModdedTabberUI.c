modded class TabberUI extends ScriptedWidgetEventHandler
{
	override void SelectTabControl( int index )
	{
		Widget tab_control = m_TabControls.Get( index );
		if( tab_control )
		{
			/*
			Widget tab_bg = tab_control.FindAnyWidget( tab_control.GetName() + "_Background" );
			if( tab_bg )
			{
				tab_bg.Show( true );
			}
			*/
			
			Widget tab_title = TextWidget.Cast(tab_control.FindAnyWidget( tab_control.GetName() + "_Title" ));
			
			int color_title = ARGB(255, 255, 168, 0);
			int color_backg = ARGB(255, 0, 0 ,0);
			
			#ifdef PLATFORM_CONSOLE
				color_title = ARGB(255, 255, 255, 255);
				color_backg = ARGB(255, 200, 0 ,0);
			#endif
			
			tab_title.SetColor( color_title );
			tab_control.SetColor( color_backg );
		}
	}

	override bool OnMouseEnter( Widget w, int x, int y )
	{
		int index = m_TabControls.GetKeyByValue( w );
		if( m_SelectedIndex == index )
		{
			return false;
		}
		
		Widget tab_control = m_TabControls.Get( index );
		if( tab_control )
		{			
			Widget tab_title = TextWidget.Cast(tab_control.FindAnyWidget( tab_control.GetName() + "_Title" ));
			tab_title.SetColor( ARGB(255, 255, 168, 0) );
			tab_control.SetColor( ARGB(255, 0, 0 ,0) );
		}
		
		return false;
	}
}