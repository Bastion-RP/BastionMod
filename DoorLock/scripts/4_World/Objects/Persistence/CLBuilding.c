/*
	Building Persistence by RoomService
	This DayZ Standalone Mod MAY NOT BE MODIFIED, REPRODUCED or UPLOADED to ANY platform without express consent of the author.
*/

class CLBuilding
{
	ref array< ref CodeLockedDoors > 		m_CodeLockedDoors;
	vector									m_BuildingPos;

	void CLBuilding( vector buildingPos, int doorIndex )
	{
		m_CodeLockedDoors 	= new array< ref CodeLockedDoors >;
		m_BuildingPos 		= buildingPos;
		AddCodeLockedDoor( doorIndex );
	}

	vector GetPos()
	{
		return m_BuildingPos;
	}

	ref array< ref CodeLockedDoors > GetLockedDoors()
	{
		return m_CodeLockedDoors;
	}

	ref CodeLockedDoors GetLockedDoor( int doorIndex )
	{
		for ( int i = 0; i < m_CodeLockedDoors.Count(); i++ )
		{
			CodeLockedDoors m_LockedDoor = m_CodeLockedDoors.Get(i);
			
			if ( m_LockedDoor.GetLocalIndex() == doorIndex )
			{
				return m_LockedDoor;
			}
		}
		return null;
	}
	
	ref Building GetBuilding()
	{
        Building building;
        array<Object> objects = new array<Object>;
        array<CargoBase> cargo = new array<CargoBase>;
        GetGame().GetObjectsAtPosition( m_BuildingPos, 1, objects, cargo );

        for ( int i = 0; i < objects.Count(); i++ )
        {
            Class.CastTo( building, objects.Get(i) );
			if ( building ) break;
        }
		return building;
	}

	void CloseAllDoors()
	{
		Building building = GetBuilding();

		if ( !building ) return;

		for ( int j = 0; j < m_CodeLockedDoors.Count(); j++ )
		{
			CodeLockedDoors 	m_LockedDoor 	= m_CodeLockedDoors.Get(j);
			int 				doorIndex 		= m_LockedDoor.GetLocalIndex();
			if ( building.IsDoorOpen( doorIndex ) ) 
			{
				building.CloseDoor( doorIndex );
			}
		}
	}

	bool HasEasyAccess( int doorIndex, string playerId )
	{
		CodeLockedDoors m_LockedDoor = GetLockedDoor( doorIndex );

		if ( m_LockedDoor )
		{
			if ( m_LockedDoor.GetOwnerId() == playerId ) return true;
			
			ref array< string > m_PersistentPlayers = m_LockedDoor.GetPersistentPlayers();
			for ( int i = 0; i < m_PersistentPlayers.Count(); i++ )
			{
				if ( m_PersistentPlayers.Get(i) == playerId ) return true;
			}
		}
		return false;
	}

	void AddCodeLockedDoor( int doorIndex )
	{
		CodeLockedDoors m_LockedDoor = new CodeLockedDoors( doorIndex );
		m_CodeLockedDoors.Insert( m_LockedDoor );
	}

	void RemoveCodeLockedDoor( int doorIndex )
	{
		CodeLockedDoors m_LockedDoor = GetLockedDoor( doorIndex );

		if ( m_LockedDoor )
			m_CodeLockedDoors.RemoveItem( m_LockedDoor );
	}

	void ClearPlayers( int doorIndex )
	{
		CodeLockedDoors m_LockedDoor = GetLockedDoor( doorIndex );

		if ( m_LockedDoor )
			m_LockedDoor.ClearPlayers();
	}

	void InsertPlayer( int doorIndex, string playerId )
	{
		CodeLockedDoors m_LockedDoor = GetLockedDoor( doorIndex );

		if ( m_LockedDoor )
			m_LockedDoor.InsertPlayer( playerId );
	}
}