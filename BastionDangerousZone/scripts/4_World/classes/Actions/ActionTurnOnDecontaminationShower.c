class ActionTurnOnBRP_DecontaminationShower: ActionInteractBase
{
	void ActionTurnOnBRP_DecontaminationShower()
	{
		m_CommandUID        = DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		m_StanceMask        = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
	}

	override string GetText()
	{
		return "Turn on shower";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object targetObject = target.GetObject();
		if ( targetObject )
		{
			BRP_DecontaminationShower shower = BRP_DecontaminationShower.Cast( targetObject );

			if (shower.FindAttachmentBySlotName("ShowerTank") != NULL)
			{
				EntityAI m_Tank = shower.FindAttachmentBySlotName("ShowerTank");
				ItemBase m_Tank_IB = ItemBase.Cast(m_Tank);

				if ( m_Tank_IB.GetLiquidType() != LIQUID_GASOLINE && m_Tank_IB.GetQuantity() > 0)
				{
					return true;
				}
				else false;
			}
			return false;
		}
		return false;
	}

	override void OnExecuteServer( ActionData action_data )
	{
		Object targetObject = action_data.m_Target.GetObject();
		if (targetObject)
		{
			EntityAI target_EAI = EntityAI.Cast( targetObject );
			if(target_EAI.IsKindOf("BRP_DecontaminationShower"))
			{
				BRP_DecontaminationShower sh = BRP_DecontaminationShower.Cast(target_EAI);
				sh.CanStartShower();
			}
		}
	}
};
