modded class OptionSelectorSlider  extends OptionSelectorBase
{
	void OptionSelectorSlider( Widget parent, float value, ScriptedWidgetEventHandler parent_menu, bool disabled, float min, float max )
	{
		m_Slider.SetColor( ARGB(255, 255, 168, 0) );
	}

	override void ColorHighlight( Widget w )
	{
		if( !w )
			return;
		
		//SliderWidget slider = SliderWidget.Cast( w.FindAnyWidget("option_value") );
		
		if ( m_Slider )
		{
			SetFocus( m_Slider );
			m_Slider.SetColor( ARGB(255, 255, 168, 0) );
		}
		super.ColorHighlight( w );
	}

	override void ColorNormal( Widget w )
	{
		if( !w )
			return;
		
		//SliderWidget slider = SliderWidget.Cast( w.FindAnyWidget("option_value") );
		
		if ( m_Slider )
		{
			m_Slider.SetColor( ARGB(255, 255, 168, 0) );
		}
		super.ColorNormal( w );
	}

	override bool OnMouseEnter( Widget w, int x, int y )
	{
		if( m_ParentClass )
		{
			OnFocus( w, x, y );
			m_ParentClass.OnFocus( m_Root.GetParent(), -1, m_SelectorType );
			#ifdef PLATFORM_WINDOWS
			m_ParentClass.OnMouseEnter( m_Root.GetParent().GetParent(), x, y );
			m_Slider.SetColor( ARGB(255, 255, 168, 0) );
			#endif
		}
		
		return true;
	}

	override bool OnMouseLeave( Widget w, Widget enterW, int x, int y )
	{
		if( m_ParentClass )
		{
			#ifdef PLATFORM_WINDOWS
			m_ParentClass.OnMouseLeave( m_Root.GetParent().GetParent(), enterW, x, y );
			m_Slider.SetColor( ARGB(255, 255, 168, 0) );
			#endif
			OnFocusLost( w, x, y );
			SetFocus( null );
		}
			
		return true;
	}
}