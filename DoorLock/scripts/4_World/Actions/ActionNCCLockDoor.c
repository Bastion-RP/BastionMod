class ActionNCCLockDoorCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.LOCK);
	}
}

class ActionNCCLockDoor : ActionContinuousBase
{
	ref PluginDoorPersistence m_DoorPersistence;

	void ActionNCCLockDoor()
	{
		m_CallbackClass = ActionNCCLockDoorCB;
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
		return "CodeLock Door";
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if( !target ) return false;
		if( !IsBuilding(target) ) return false;
		if( !IsInReach(player, target, UAMaxDistances.DEFAULT) ) return false;

		if ( !m_DoorPersistence )
			m_DoorPersistence	= PluginDoorPersistence.Cast( GetPlugin( PluginDoorPersistence ) );

		Building building;
		if( Class.CastTo(building, target.GetObject()) )
		{
			int doorIndex = building.GetDoorIndex(target.GetComponentIndex());
			if ( doorIndex != -1 )
			{
				if ( !building.IsDoorOpen(doorIndex) )
				{
					CLBuilding m_CLBuilding = m_DoorPersistence.GetBuildingatPos( building.GetPosition() );
					if ( !m_CLBuilding ) return true;

					CodeLockedDoors m_LockedDoor = m_CLBuilding.GetLockedDoor( doorIndex );
					if ( !m_LockedDoor ) return true;
				}
			}
		}		
		return false;
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
		Building 	building 		= Building.Cast( action_data.m_Target.GetObject() );

		if ( !m_DoorPersistence )
			m_DoorPersistence				= PluginDoorPersistence.Cast( GetPlugin( PluginDoorPersistence ) );
					
		m_DoorPersistence.AddDoorToBuilding( building.GetPosition(), building.GetDoorIndex( action_data.m_Target.GetComponentIndex() ), action_data.m_Player );
	}
}