class ActionDisconnectGpsDeviceCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime( 5.0 );
	}
};

class ActionDisconnectGpsDevice : ActionContinuousBase
{
	void ActionDisconnectGpsDevice()
	{
		m_CallbackClass = ActionDisconnectGpsDeviceCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNonRuined(2);
	}

	override string GetText()
	{
		return "Disconnect";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if (GetGame().IsServer())
			return true;

		GpsBase sourceDevice;
		GpsBase targetDevice;

		if (Class.CastTo(targetDevice, target.GetObject()) && Class.CastTo(sourceDevice, player.GetItemInHands()))
		{
			return !sourceDevice.CanConnect(targetDevice);
		}
		return false;
	}
		
	override void OnExecuteClient( ActionData action_data )
	{	
		GpsBase sourceDevice;
		GpsBase targetDevice;
		Class.CastTo(sourceDevice, action_data.m_MainItem);
		Class.CastTo(targetDevice, action_data.m_Target.GetObject());
		if (sourceDevice && targetDevice)
			sourceDevice.DisconnectDevice(targetDevice);
	}

	override void OnExecuteServer( ActionData action_data )
	{	
		GpsBase sourceDevice;
		GpsBase targetDevice;
		Class.CastTo(sourceDevice, action_data.m_MainItem);
		Class.CastTo(targetDevice, action_data.m_Target.GetObject());
		if (sourceDevice && targetDevice)
			sourceDevice.DisconnectDevice(targetDevice);
	}
}