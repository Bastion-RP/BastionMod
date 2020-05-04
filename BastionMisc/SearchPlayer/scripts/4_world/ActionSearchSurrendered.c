modded class UAMaxDistances
{
	const float SEARCHPLAYER = 1.0;
};

class ActionSearchSurrenderedCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(3);
	}
};

class ActionSearchSurrendered: ActionContinuousBase
{
	void ActionSearchSurrendered()
	{
		m_CallbackClass = ActionSearchSurrenderedCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_BANDAGETARGET;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionTarget = new CCTMan(UAMaxDistances.SEARCHPLAYER);
		m_ConditionItem = new CCINone;
	}
		
	override string GetText()
	{
		return "Search Person";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if( target)
		{
			PlayerBase target_player = PlayerBase.Cast(target.GetObject());
			if(target_player && !target_player.IsRestrained()) 
				return true; 
		}
		return false;	
	}

	override void OnFinishProgressServer( ActionData action_data )
	{	
		PlayerBase target = PlayerBase.Cast(action_data.m_Target.GetObject());
		
		if(target)
		{
			target.SetHandsUp(true);
			target.SearchDuration();
		}
	}
};