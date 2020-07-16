class ActionOpenDoorWithKeyCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.LOCK);
	}
};

class ActionOpenDoorWithKey: ActionContinuousBase
{
	void ActionOpenDoorWithKey()
	{
		m_CallbackClass = ActionOpenDoorWithKeyCB;
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
		return "Открыть";
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if( !target ) return false;
		if( !IsBuilding(target) ) return false;
		if( !IsInReach(player, target, UAMaxDistances.DEFAULT) ) return false;

		Building building;
		if( Class.CastTo(building, target.GetObject()) )
		{
			int doorIndex = building.GetDoorIndex(target.GetComponentIndex());
			if ( doorIndex != -1 && (!building.IsDoorOpen(doorIndex) && !building.IsDoorLocked(doorIndex)))
			{
				vector doorPos = building.GetDoorSoundPos(doorIndex);
				return GetLockedDoorsManager().IsRightKey(doorPos, item);
			}
		}		
		return false;
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
		Building building;
		if( Class.CastTo(building, action_data.m_Target.GetObject()) )
		{
			int doorIndex = building.GetDoorIndex(action_data.m_Target.GetComponentIndex());
			if( doorIndex != -1 )
			{
				building.OpenDoor(doorIndex);
				GetLockedDoorsManager().OnDoorOpen(doorIndex, building);
			}
		}
	}
};