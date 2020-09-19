modded class KeybindingElement extends ScriptedWidgetEventHandler
{
	override bool OnMouseEnter( Widget w, int x, int y )
	{
		if( w == m_PrimaryBindButton || w == m_PrimaryClear )
		{
			m_PrimaryBindButton.SetColor( ARGB(255, 255, 168, 0));
			m_PrimaryClear.Show( true );
			m_PrimaryClear.Update();
			m_AlternativeClear.Show( false );
			return true;
		}
		else if( w == m_AlternativeBindButton || w == m_AlternativeClear )
		{
			m_AlternativeBindButton.SetColor( ARGB(255, 255, 168, 0));
			m_PrimaryClear.Show( false );
			m_AlternativeClear.Show( true );
			m_AlternativeClear.Update();
			return true;
		}
		else
		{
			m_PrimaryBindButton.SetColor( ARGBF( 0, 0, 0, 0 ) );
			m_AlternativeBindButton.SetColor( ARGBF( 1, 0, 0, 0 ) );
			m_PrimaryClear.Show( false );
			m_AlternativeClear.Show( false );
		}
		return false;
	}
}