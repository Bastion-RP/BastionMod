class ActionHackBRPDoorCB : ActionContinuousBaseCB
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

class ActionHackBRPDoor: ActionContinuousBase
{
	void ActionHackBRPDoor()
	{
		m_CallbackClass = ActionHackBRPDoorCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
	}
	
	override void CreateConditionComponents()
	{	
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNone;
	}
		
	override string GetText()
	{
		return "Hack door";
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if( !target ) return false;
		if( !IsBuilding(target) ) return false;
		if( !IsInReach(player, target, UAMaxDistances.DEFAULT) ) return false;

		BuildingBase brpbuilding;
		if( Class.CastTo(brpbuilding, target.GetObject()) )
		{
			if (GetGame().IsClient())
			{
				int doorIdx = brpbuilding.GetDoorIndex(target.GetComponentIndex());
				if (!brpbuilding.m_HouseData)
				{return false;}
				if (!brpbuilding.m_HouseData.LeaseTime)
				{return false;}
				if (!g_HM.IsDoorOwner(player, brpbuilding, doorIdx))
				{
					return true;
				}
			}
			return true;
		}
		Building building;
		if( Class.CastTo(building, target.GetObject()) )
		{
			if (GetGame().IsClient())
			{
				int dIdx = building.GetDoorIndex(target.GetComponentIndex());
				LockDoorStorage fix;
				vector doorPos = brpbuilding.GetDoorSoundPos(dIdx);
				if (GetLockedDoorsManager().IsDoorExist(doorPos, fix) )
				{
					return true;
				}
				else
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
		TryHackDoor(action_data);
	}

    void TryHackDoor(ActionData action_data)
	{
		BuildingBase building;
        HackHouseToolBase hackTool = HackHouseToolBase.Cast(action_data.m_MainItem);
        if (!hackTool) return;
		if ( Class.CastTo(building, action_data.m_Target.GetObject()) )
		{
			int doorIndex = building.GetDoorIndex(action_data.m_Target.GetComponentIndex());
			if ( doorIndex != -1 )
			{
                if (hackTool.RollHackDoor())
                {
                    building.OpenDoor(doorIndex);
                    hackTool.Destroy();
                }
                else
                {
                    hackTool.HackFailed(building);
                }
			}
		}
	}
};