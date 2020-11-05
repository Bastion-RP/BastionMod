modded class OptionSelectorBase extends ScriptedWidgetEventHandler
{
	override void ColorHighlight( Widget w )
	{
		if( !w )
			return;
				
		ButtonSetColor(w, ARGB(255, 255, 168, 0) );
	}
}