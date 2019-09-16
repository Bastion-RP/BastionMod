class ActionInteractEasyAccess : ActionInteractBase
{
	PluginDoorPersistence m_DoorPersistence;

	void ActionInteractEasyAccess()
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
	
	override bool IsInstant()
	{
		return true;
	}

	override string GetText()
	{
		return "Open Locked Door";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		Building building;
		if( Class.CastTo(building, target.GetObject()) )
		{
			int doorIndex = building.GetDoorIndex(target.GetComponentIndex());
			if( doorIndex != -1 )
			{
				if( !IsInReach(player, target, UAMaxDistances.DEFAULT) ) return false;
				if ( !building.IsDoorOpen(doorIndex) && !building.IsDoorLocked(doorIndex) )
				{
					m_DoorPersistence 			= PluginDoorPersistence.Cast( GetPlugin( PluginDoorPersistence ) );
					CLBuilding m_CLBuilding 	= m_DoorPersistence.GetBuildingatPos( building.GetPosition() );
					if ( m_CLBuilding )
					{
						return m_CLBuilding.HasEasyAccess( doorIndex, player.GetIdentity().GetId() );
					}
				}
			}
		}
		return false;
	}
	
	override void OnStartServer( ActionData action_data )
	{
		Building building;
		if( Class.CastTo(building, action_data.m_Target.GetObject()) )
		{
			int doorIndex = building.GetDoorIndex(action_data.m_Target.GetComponentIndex());
			if( doorIndex != -1 )
			{
				building.OpenDoor(doorIndex);
			}
		}
	}
}