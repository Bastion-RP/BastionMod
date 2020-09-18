modded class ActionForceFeed extends ActionForceConsume
{
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		PlayerBase target_player = PlayerBase.Cast(target.GetObject());

		return target_player && target_player.IsRestrained() && super.ActionCondition(player, target, item);
	}

	override void OnEndServer(ActionData action_data)
	{	
		if (m_AdminLog) m_AdminLog.OnContinouousAction(action_data);
	}

	override void OnFinishProgress(ActionData action_data)
	{
		PluginAdminLog admin_log;
		admin_log = m_AdminLog;
		m_AdminLog = NULL;

		super.OnFinishProgress(action_data);

		m_AdminLog = admin_log;
	}

	override string GetAdminLogMessage(ActionData action_data)
	{
		if (!m_AdminLog) return "";

		Object target_object = action_data.m_Target.GetObject();
		if (!target_object) return "";

		PlayerBase target_player = PlayerBase.Cast(target_object);
		if (!target_player) return " force fed " + target_object.GetDisplayName() + " with " + action_data.m_MainItem.GetDisplayName();

		string target_player_prefix = m_AdminLog.GetPlayerPrefix(target_player, target_player.GetIdentity());
		if (!target_player_prefix) return " force fed " + target_player.GetDisplayName() + " with " + action_data.m_MainItem.GetDisplayName();

		return " force fed " + target_player_prefix + " with " + action_data.m_MainItem.GetDisplayName();
	}
}