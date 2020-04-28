modded class ActionOpenDoors: ActionInteractBase
{
	PluginDoorPersistence 	m_DoorPersistence;
	Building 				target_building;

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if( !target ) return false;
		if( !IsBuilding(target) ) return false;

		Building building;
		if( Class.CastTo(building, target.GetObject()) )
		{
			int doorIndex = building.GetDoorIndex(target.GetComponentIndex());
			if ( doorIndex != -1 )
			{
				if( !IsInReach(player, target, UAMaxDistances.DEFAULT) ) return false;
				if ( !building.IsDoorOpen(doorIndex) && !building.IsDoorLocked(doorIndex) )
				{
					m_DoorPersistence 			= PluginDoorPersistence.Cast( GetPlugin( PluginDoorPersistence ) );
					CLBuilding m_CLBuilding 	= m_DoorPersistence.GetBuildingatPos( building.GetPosition() );
					if ( m_CLBuilding )
					{
						if ( m_CLBuilding.GetLockedDoor( doorIndex ) )
							return false;
					}
					return true;
				}
			}
		}
		return false;
	}
};