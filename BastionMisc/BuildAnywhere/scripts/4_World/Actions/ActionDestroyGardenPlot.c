class ActionDestroyGardenPlotCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime( UATimeSpent.DEFAULT_DECONSTRUCT );
	}
};

class ActionDestroyGardenPlot: ActionContinuousBase
{
	void ActionDestroyGardenPlot()
	{
		m_CallbackClass = ActionDestroyGardenPlotCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DIGMANIPULATE;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_LOW;
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNone;
	}
		
	override string GetText()
	{
		return "Destroy";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		Object targetObject = target.GetObject();
		GardenPlot gardenPlot = GardenPlot.Cast( targetObject );
		if (gardenPlot)
		{
			if ( player.IsPlacingLocal() )
			{
				Hologram hologram = player.GetHologramLocal();
				if (hologram.IsColliding() )
				{
					return false;
				}
			}
			return true;
			
		}	
		return false;
	}
		
	override void OnFinishProgressServer( ActionData action_data ) 
	{
		GardenPlot gardenPlot = GardenPlot.Cast( action_data.m_Target.GetObject() );
		if ( gardenPlot ) 
		{
			gardenPlot.Delete();
			action_data.m_MainItem.DecreaseHealth( UADamageApplied.BUILD, false );
		}
	}
};