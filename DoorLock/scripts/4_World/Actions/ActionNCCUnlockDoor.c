class ActionNCCUnlockDoorCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.UNLOCK);
	}
};

class ActionNCCUnlockDoor: ActionContinuousBase
{
	ref PluginDoorPersistence m_DoorPersistence;

	void ActionNCCUnlockDoor()
	{
		m_CallbackClass = ActionNCCUnlockDoorCB;
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
		return "Remove CodeLock";
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if( !target ) return false;
		if( !IsBuilding(target) ) return false;
		if( !IsInReach(player, target, UAMaxDistances.DEFAULT) ) return false;

		if ( !m_DoorPersistence )
			m_DoorPersistence = PluginDoorPersistence.Cast( GetPlugin( PluginDoorPersistence ) );
		
		Building building;
		if( Class.CastTo(building, target.GetObject()) )
		{
			int doorIndex = building.GetDoorIndex(target.GetComponentIndex());
			if ( doorIndex != -1 )
			{
				if ( !building.IsDoorOpen(doorIndex) )
				{
					CLBuilding m_CLBuilding = m_DoorPersistence.GetBuildingatPos( building.GetPosition() );
					if ( m_CLBuilding )
					{
						CodeLockedDoors m_LockedDoor = m_CLBuilding.GetLockedDoor( doorIndex );
						if ( m_LockedDoor ) return true;
					}
				}
			}
		}		
		return false;
	}

	override void OnFinishProgressServer( ActionData action_data )
	{	
		ActionTarget	target			= action_data.m_Target;
		Building 		building 		= Building.Cast( target.GetObject() );

		if ( !m_DoorPersistence )
			m_DoorPersistence 				= PluginDoorPersistence.Cast( GetPlugin( PluginDoorPersistence ) );

		m_DoorPersistence.RemoveDoorFromBuilding( building.GetPosition(), building.GetDoorIndex( action_data.m_Target.GetComponentIndex() ), action_data.m_Player );
	}
};