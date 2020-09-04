modded class ChatInputMenu
{
	override bool OnChange(Widget w, int x, int y, bool finished)
	{
		//super.OnChange(w, x, y, finished);
		
		if (!finished) return false;
		
		string text = m_edit_box.GetText();

		if (text != "")
		{
			GetGame().ChatPlayer(text);
			if( !GetGame().IsMultiplayer() )
			{
				string name;
				PlayerBase player;
				player = PlayerBase.Cast(GetGame().GetPlayer());
				name = player.GetMultiCharactersPlayerName();
				ChatMessageEventParams chat_params = new ChatMessageEventParams( CCDirect, name, text, "" );
				MissionGameplay.Cast( GetGame().GetMission() ).m_Chat.Add( chat_params );
			}
		}

		m_close_timer.Run(0.1, this, "Close");
		
		GetUApi().GetInputByName("UAPersonView").Supress();	
		
		return true;
	}
}