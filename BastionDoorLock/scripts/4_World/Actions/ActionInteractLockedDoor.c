class ActionInteractLockedDoor: ActionInteractBase
{
	PluginDoorPersistence 	m_DoorPersistence;
	string 					lockState;

	void ActionOpenDoors()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_HUDCursorIcon = CursorIcons.OpenDoors;
	}

	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNone;
	}

	override string GetText()
	{
		return lockState;
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if ( !target ) return false;
		if ( !IsBuilding( target ) ) return false;

		Building building;
		if ( Class.CastTo(building, target.GetObject()) )
		{
			int doorIndex = building.GetDoorIndex(target.GetComponentIndex());
			if ( doorIndex != -1 )
			{
				if( !IsInReach(player, target, UAMaxDistances.DEFAULT) ) return false;
				if ( !building.IsDoorOpen(doorIndex) && !building.IsDoorLocked(doorIndex) )
				{
					if ( !m_DoorPersistence )
						m_DoorPersistence 				= PluginDoorPersistence.Cast( GetPlugin( PluginDoorPersistence ) );

					CLBuilding m_CLBuilding 	= m_DoorPersistence.GetBuildingatPos( building.GetPosition() );
					if ( m_CLBuilding )
					{
						CodeLockedDoors	m_LockedDoor	= m_CLBuilding.GetLockedDoor( doorIndex );

						if ( m_LockedDoor && !m_CLBuilding.HasEasyAccess( doorIndex, player.GetIdentity().GetId() ) )
						{
							if ( m_LockedDoor.GetOwnerId() != "" )
							{
								lockState 	= "Enter Passcode";
								return true;
							}
							else
							{
								lockState = "Set Passcode";
								return true;
							}
						}
					}
				}
			}
		}
		return false;
	}
	
	override void OnStartClient( ActionData action_data )
	{
		Building building;
		if ( Class.CastTo(building, action_data.m_Target.GetObject()) )
		{
			int doorIndex = building.GetDoorIndex(action_data.m_Target.GetComponentIndex());
			if ( doorIndex != -1 )
			{
				CLBuilding m_CLBuilding = m_DoorPersistence.GetBuildingatPos( building.GetPosition() );
				if ( m_CLBuilding )
				{
					CodeLockedDoors	m_LockedDoor	= m_CLBuilding.GetLockedDoor( doorIndex );
					if ( m_LockedDoor )
					{
						string ownerId = m_LockedDoor.GetOwnerId();
						if ( ownerId != "" )
						{
							m_DoorPersistence.OpenGuestCodeUI( building.GetPosition(), doorIndex );
						}
						else
							m_DoorPersistence.OpenSetCodeUI( building.GetPosition(), doorIndex );
					}
				}
			}
		}
	}
}