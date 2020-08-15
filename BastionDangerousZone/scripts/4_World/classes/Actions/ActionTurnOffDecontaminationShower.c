class ActionTurnOffBRP_DecontaminationShower: ActionInteractBase
{
	void ActionTurnOffBRP_DecontaminationShower()
	{
		m_CommandUID        = DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		m_StanceMask        = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
	}

	override string GetText()
	{
		return "Turn off shower";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object targetObject = target.GetObject();
		if ( targetObject )
		{
			BRP_DecontaminationShower shower = BRP_DecontaminationShower.Cast(targetObject);

			if ( shower  && shower.GetCompEM().IsWorking())
			{
					return true;
			}
			else return false;
		}
		return true;
	}

	override void OnExecuteServer( ActionData action_data )
	{
		Object targetObject = action_data.m_Target.GetObject();
		if (targetObject)
		{
			EntityAI target_EAI = EntityAI.Cast( targetObject );
			target_EAI.GetCompEM().SwitchOff();
		}
	}
};
