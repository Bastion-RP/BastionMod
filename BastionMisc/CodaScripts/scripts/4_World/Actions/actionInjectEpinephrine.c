/*modded class ActionInjectEpinephrineSelf: ActionInjectSelf
{	
		
	override void OnExecuteClient(  ActionData action_data )
	{
		//Print("ShockInjector::OnExecuteClient::InjectionEpinSelf");
		
		if(action_data.m_Player.m_ShockTickActive)
		{
			action_data.m_Player.StopShockInjectionClient();
		}
		
	}
	
	override void OnExecuteServer( ActionData action_data )
	{
		//Print("ShockInjector::OnExecuteServer::InjectionEpinSelf");
		
		if(action_data.m_Player.m_ShockTickActive)
		{
			action_data.m_Player.StopShockInjectionServer();
		}
	}
};

modded class ActionInjectEpinephrineTarget:ActionInjectTarget
{
	override void OnExecuteServer( ActionData action_data )
	{
		//Print("ShockInjector::OnExecuteServer::InjectionEpinTarget");
		
		PlayerBase pTarget = PlayerBase.Cast(action_data.m_Target.GetObject());
		
		if(pTarget != null)
		{
			pTarget.StopShockInjectionServer();
		}
	}
}*/