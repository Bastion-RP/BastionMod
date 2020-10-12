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
	private float passedTime = 0;
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
		passedTime = GetGame().GetTime();
	}
	
	override void OnEndServer( ActionData action_data )
	{
		passedTime = GetGame().GetTime() - passedTime;
		if (MiscGameplayFunctions.IsValueInRange(passedTime, 1700, 2000))
		{
			action_data.m_Player.NeedSyncRadiation(true);
			action_data.m_Player.DelaySyncReset();
		}
	}
	
	override void OnEndClient( ActionData action_data )
	{
		
	}
}

// class ActionMeasureRadiationLevelCB : ActionContinuousBaseCB
// {
// 	override void CreateActionComponent()
// 	{
// 		m_ActionData.m_ActionComponent = new CAContinuousTime(5);
// 	}
// };

// class ActionMeasureRadiationLevel: ActionContinuousBase
// {
// 	void ActionMeasureRadiationLevel()
// 	{
// 		m_CallbackClass = ActionMeasureRadiationLevelCB;
// 		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_TAKETEMPSELF;
// 		m_CommandUIDProne = DayZPlayerConstants.CMD_ACTIONFB_TAKETEMPSELF;
// 		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;
// 	}
	
// 	override void CreateConditionComponents()  
// 	{	
// 		m_ConditionItem = new CCINonRuined;
// 		m_ConditionTarget = new CCTSelf;
// 	}

// 	override bool HasTarget()
// 	{
// 		return false;
// 	}

// 	override string GetText()
// 	{
// 		return "Measure";
// 	}

// 	override void OnEndServer( ActionData action_data )
// 	{
// 		// Param1<float> nacdata;
// 		// Class.CastTo(nacdata,  action_data.m_ActionComponent.GetACData() );
// 		// float delta = 0;
// 		// if(nacdata)
// 		// 	delta = (nacdata.param1 / UATimeSpent.COLLECT_BLOOD);
		
// 		// if(delta > 0)
// 		// {
// 		// 	ActionCollectBloodTargetLambda lambda = new ActionCollectBloodTargetLambda(action_data.m_MainItem, "BloodBagFull", action_data.m_Player, m_SpecialtyWeight, action_data.m_Player, delta);
// 		// 	action_data.m_Player.ServerReplaceItemInHandsWithNew(lambda);
// 		// }
// 	}

// 	override void OnFinishProgressServer( ActionData action_data )
// 	{
// 		Print("OnFinishProgressServer ActionMeasureRadiationLevel");
// 	}
// };