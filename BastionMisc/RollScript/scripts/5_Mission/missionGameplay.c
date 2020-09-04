modded class MissionGameplay
{
	override void OnEvent(EventType eventTypeId, Param params)
	{	
		switch(eventTypeId)
		{
			case ChatMessageEventTypeID:
				ChatMessageEventParams chat_params = ChatMessageEventParams.Cast( params );			
				if (m_LifeState == EPlayerStates.ALIVE)
				{
					if (IsRollCommand(chat_params.param3, chat_params.param2))
					{
						chat_params.param3 = DoRoll(chat_params.param3);
					}
					
					m_Chat.Add(chat_params);
				}
			break;
			default:
				super.OnEvent(eventTypeId, params);
		}
	}

	bool IsRollCommand(string text, string senderName)
	{
		string playerName;
		GetGame().GetPlayerName( playerName );
		text.ToLower();
		if ( text.Contains("roll") && (senderName == playerName))
		{
			return true;
		}
		return false;
	}

	string DoRoll(string text)
	{
		int countRolls;
		int numberOptions;
		string rolls;
		string sourceText = text;
		array<string> rollSettings = new array<string>();
		text.ToLower();
		text.Split(" ", rollSettings);

		if (rollSettings.Count() != 3)
			return sourceText;
		if (rollSettings.Get(0) != "roll")
			return sourceText;

		countRolls = rollSettings.Get(1).ToInt();
		numberOptions = rollSettings.Get(2).ToInt();

		if (!countRolls || !numberOptions)
			return sourceText;

		rolls = FormatMessage(countRolls, numberOptions);
		return rolls;
	}

	string FormatMessage(int countRolls, int numberOptions)
	{
		string result = "rolls ";
		for (int i = 0; i < countRolls; i++)
		{
			result += "" + Math.RandomIntInclusive(1, numberOptions) + " ";
		}
		return result;
	}
}