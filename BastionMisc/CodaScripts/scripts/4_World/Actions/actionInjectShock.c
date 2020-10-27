class ActionInjectShockSelf: ActionInjectSelf
{			
	override void OnExecuteClient(  ActionData action_data )
	{
		Print("ShockInjector::OnExecuteClient::InjectionShockSelf");
		action_data.m_Player.StartShockInjectionClient();
	}
	
	override void OnExecuteServer( ActionData action_data )
	{
		Print("ShockInjector::OnExecuteServer");
		action_data.m_Player.StartShockInjectionServer();
	}
};

class ActionInjectShockTarget: ActionInjectTarget
{	
	void ActionInjectShockTarget()
	{
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_MEDIUM;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INJECTIONTARGET;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTMan(UAMaxDistances.DEFAULT);
	}
	
	override string GetText()
	{
		return "Inject Target";
	}
		
	override void OnExecuteServer( ActionData action_data )
	{
		Print("ShockInjector::OnExecuteServer::InjectionShockTarget");
		
		PlayerBase pTarget = PlayerBase.Cast(action_data.m_Target.GetObject());
		
		if(pTarget != null)
		{
			ScriptRPC rpc = new ScriptRPC();
			rpc.Write(true);
			Print("ShockInjector::OnExecuteServer - Sending start client rpc to " + pTarget);
			rpc.Send(pTarget,Shock_RPC.M_InjectStartClient,true,pTarget.GetIdentity());
			
			pTarget.StartShockInjectionServer();
		}
		
		super.OnExecuteServer(action_data);
	}
};