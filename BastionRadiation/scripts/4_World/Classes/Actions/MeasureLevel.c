modded class ActionInjectMorphineSelf: ActionInjectSelf
{
	override void OnEndServer( ActionData action_data )
	{
		action_data.m_Player.NeedSyncRadiation(true);
		action_data.m_Player.DelaySyncReset();
		super.OnEndServer(action_data);
	}
};