modded class ActionCPR
{
	override void OnFinishProgressServer(ActionData action_data)
	{
		super.OnFinishProgressServer(action_data);
		
		PlayerBase OP = PlayerBase.Cast(action_data.m_Target.GetObject());
		
		if(OP !=null && OP.IsAlive() && OP.m_ShockTickActive)
		{
			OP.StopShockInjectionServer();
		}
	}
}