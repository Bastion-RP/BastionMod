class ActionHackISFWeaponCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
        HackHouseToolBase hackTool;
        if (Class.CastTo(hackTool, m_ActionData.m_MainItem))
        {
            m_ActionData.m_ActionComponent = new CAContinuousTime(hackTool.GetTimeHacking());
        }
        else
        {
            m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.LOCK);
        }
	}
};

class ActionHackISFWeapon: ActionContinuousBase
{
	void ActionHackISFWeapon()
	{
		m_CallbackClass = ActionHackISFWeaponCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
	}
	
	override void CreateConditionComponents()
	{	
		m_ConditionTarget = new CCTNonRuined(1);
		m_ConditionItem = new CCINonRuined;
	}
		
	override string GetText()
	{
		return "Hack";
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Weapon_Base wpn;
		if( Class.CastTo(wpn, target.GetObject()) )
		{
			if (wpn.IsISFWeapon() && !wpn.IsHacked())
			{
				return true;
			}
		}
		
		return false;
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
		TryHackWeapon(action_data);
	}

    void TryHackWeapon(ActionData action_data)
	{
		Weapon_Base wpn;
        HackHouseToolBase hackTool = HackHouseToolBase.Cast(action_data.m_MainItem);
        if (!hackTool) return;
		if ( Class.CastTo(wpn, action_data.m_Target.GetObject()) )
		{
			if (hackTool.RollHack(0.8))
			{
				wpn.SetHacked();
			}
			else
			{
				wpn.SetHealth(0);
				hackTool.HackFailed(wpn);
			}
		}
	}
};