class ActionInteractChangePasscode: ActionInteractBase
{
	PluginDoorPersistence 	m_DoorPersistence;

	void ActionInteractChangePasscode()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_PICKUP_HANDS;
	}

	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNone;
	}
	
	override typename GetInputType()
	{
		return ContinuousInteractActionInput;
	}
	
	override bool HasProgress()
	{
		return false;
	}

	override string GetText()
	{
		return "Change Passcode";
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

					CLBuilding m_CLBuilding 			= m_DoorPersistence.GetBuildingatPos( building.GetPosition() );
					if ( m_CLBuilding )
					{
						CodeLockedDoors	m_LockedDoor	= m_CLBuilding.GetLockedDoor( doorIndex );

						if ( m_LockedDoor )
						{
							if ( m_LockedDoor.GetOwnerId() == player.GetIdentity().GetId() ) return true;
						}
					}
				}
			}
		}
		return false;
	}
	
	override bool CanContinue( ActionData action_data )
	{
		return true;
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
						if ( ownerId == action_data.m_Player.GetIdentity().GetId() )
							m_DoorPersistence.OpenSetCodeUI( building.GetPosition(), doorIndex, true );
					}
				}
			}
		}
	}
	
	override void CreateAndSetupActionCallback( ActionData action_data )
	{
		super.CreateAndSetupActionCallback( action_data );
	}
}