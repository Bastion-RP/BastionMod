modded class PluginAdminLog extends PluginBase
{
	override void OnContinouousAction(ActionData action_data)
	{
		if (m_ActionsFilter == 1)
		{
			super.OnContinouousAction(action_data);
			return;
		}

		m_Message = action_data.m_Action.GetAdminLogMessage(action_data);
		if (m_Message == "") return;
		
		m_PlayerPrefix = this.GetPlayerPrefix(action_data.m_Player , action_data.m_Player.GetIdentity());
		
		LogPrint(m_PlayerPrefix + m_Message);
	}
}