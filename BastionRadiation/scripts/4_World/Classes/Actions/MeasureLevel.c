// modded class ActionInjectMorphineSelf: ActionInjectSelf
// {
// 	override void OnEndServer( ActionData action_data )
// 	{
// 		action_data.m_Player.NeedSyncRadiation(true);
// 		action_data.m_Player.DelaySyncReset();
// 		super.OnEndServer(action_data);
// 	}
// };

class ActionMeasureRadiationLevel : ActionInjectSelf
{
	private float energyUsage = 0.2;
	
	override string GetText()
	{
		return "Measure";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item ) //condition for action
	{
		// Battery9V battery = Battery9V.Cast( item.GetCompEM().GetEnergySource() );
			
		// if (battery)
		// {
		// 	float energy = battery.GetCompEM().GetEnergy0To1();

		// }
		// return false;
		return true;
	}

	override void OnExecuteServer( ActionData action_data )
	{	
		
	}
	
	override void OnEndServer( ActionData action_data )
	{
		action_data.m_Player.NeedSyncRadiation(true);
		action_data.m_Player.DelaySyncReset();
	}
	
	override void OnEndClient( ActionData action_data )
	{
		
	}
}