class ActionBRPSitOnChairCB : ActionSingleUseBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CASingleUse;
	}
	
	override void InitActionComponent()
	{
		m_Interrupted = false;
		m_Canceled = false;

		CreateActionComponent();
		if ( m_ActionData.m_ActionComponent )
		{ 
			m_ActionData.m_ActionComponent.Init(m_ActionData);
		}
		
		Object targetObject = m_ActionData.m_Target.GetObject();
		vector ChairDirection = targetObject.GetDirection();
		vector ChairPosition = targetObject.GetPosition();
		
		DeveloperTeleport.SetPlayerDirection( m_ActionData.m_Player, ChairDirection );
		DeveloperTeleport.SetPlayerPosition( m_ActionData.m_Player, ChairPosition );
		
		m_ActionData.m_State = UA_PROCESSING;
		RegisterAnimationEvent("ActionExec", UA_ANIM_EVENT);
		m_SoundObject = m_ActionData.m_Action.PlayActionSound(m_ActionData.m_Player);
	}
	
	override void EndActionComponent()
	{
		m_ActionData.m_State = UA_FINISHED;
	}
};

class ActionBRPSitOnChair: ActionSingleUseBase
{	
	void ActionBRPSitOnChair()
	{
		m_CallbackClass = ActionBRPSitOnChairCB;
		m_CommandUID = DayZPlayerConstants.CMD_GESTUREFB_SITA;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_LOW;
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNonRuined( UAMaxDistances.BASEBUILDING );
	}
	
	override string GetText()
	{
		return "Sit";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		Object targetObject = target.GetObject();
		BRP_Chair_Base brpchair = BRP_Chair_Base.Cast( targetObject );
		if ( player )
		{
			if ( brpchair )
			{
				return true;
			}
		}
		return false;
	}
};
