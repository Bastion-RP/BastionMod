/*
	PluginDoor Persistence by RoomService
	This DayZ Standalone Mod MAY NOT BE MODIFIED, REPRODUCED or UPLOADED to ANY platform without express consent of the author.
*/

class PluginDoorPersistence : PluginBase
{
	protected static 	ref array< ref CLBuilding > 		m_PersistenceArray;
	string													m_JsonString;
	protected static	ref FileSerializer 					m_FileSerializer		= new FileSerializer();
	private const 		string 								m_ProfileDir			= "$profile:\\Bastion";
	private const 		string 								m_ModDir				= "$profile:\\Bastion\\DoorLock";
	private const 		string 								m_SaveFileDir			= "$profile:\\Bastion\\DoorLock\\DoorPersistence.json";
	protected			ref SetCodeMenu						m_SetCodeUI;
	protected			ref GuestCodeMenu					m_GuestCodeUI;

	void PluginDoorPersistence()
	{
		// If this is the client, create a new persistent array to prevent a null ref later
		if ( GetGame().IsClient() ) 
		{
			m_PersistenceArray = new array< ref CLBuilding >;
		}
		
		// If server, check for files to make sure they exist
		if ( GetGame().IsServer() && GetGame().IsMultiplayer()  )
		{
			if ( !FileExist( m_ProfileDir ) )
				MakeDirectory( m_ProfileDir );

			if ( !FileExist( m_ModDir ) )
			{
				MakeDirectory( m_ModDir );

				m_PersistenceArray = new array< ref CLBuilding >;
				SavePersistence();
			}

			LoadPersistence();
			InitializeBuildings();
		}
	}

	void ~PluginDoorPersistence()
	{
		if ( GetGame().IsServer() && GetGame().IsMultiplayer() )
			SavePersistence();
	}
	// ----------------------------------[[Client Only]]------------------------------------------------------------------

	void SynchBuilding( ref CLBuilding clBuilding )
	{
		// ONLY do this on the client
		if ( GetGame().IsServer() ) return;
		
		// Loop through every single building and check for vector positions.
		vector pos = clBuilding.GetPos();

		for( int i = 0; i < m_PersistenceArray.Count(); i++ )
		{
			CLBuilding 	localBuilding 	= m_PersistenceArray.Get(i);
			vector 		localPos 		= localBuilding.GetPos();

			if ( vector.Distance( localPos, pos ) < 0.1 )
			{
				// If the vector position is the same as the building sent, delete it.
				m_PersistenceArray.RemoveOrdered(i);
				break;
			}
		}

		// Clear all the passcodes, because we don't want clients having those.
		ref array< ref CodeLockedDoors > m_LockedDoors = clBuilding.GetLockedDoors();
		for ( int j = 0; j < m_LockedDoors.Count(); j++ )
		{
			CodeLockedDoors m_LockedDoor = m_LockedDoors.Get(j);
			m_LockedDoor.SetPasscode( ":-)" );
		}

		// Add the building to the client array.
		m_PersistenceArray.Insert( clBuilding );
	}

    void OpenSetCodeUI( vector buildingPos, int doorIndex, bool changeCode = false )
    {
		// Make sure it's the client and that the UI isn't already opened.
        if ( !GetGame().IsClient() ) return;
        if ( GetGame().GetUIManager().IsMenuOpen( SET_CODE_MENU ) ) return;

		// If the object doesn't already exist, create it and set the appropriate ID
		if ( !m_SetCodeUI )
		{
			m_SetCodeUI = new SetCodeMenu();
			m_SetCodeUI.SetID( SET_CODE_MENU );
		}

		// Show the menu
		GetGame().GetUIManager().ShowScriptedMenu( m_SetCodeUI, NULL );

		// Set required local variables.
		m_SetCodeUI.SetBuildingPos( buildingPos );
		m_SetCodeUI.SetDoorIndex( doorIndex );
		m_SetCodeUI.SetChangeCode( changeCode );
    }
    
    void OpenGuestCodeUI( vector buildingPos, int doorIndex )
    {
		// Make sure it's the client and that the UI isn't already opened.
        if ( GetGame().IsServer() ) return;
        if ( GetGame().GetUIManager().IsMenuOpen( GUEST_CODE_MENU ) ) return;

		// If the object doesn't already exist, create it and set the appropriate ID
        if ( !m_GuestCodeUI )
        {
            m_GuestCodeUI = new GuestCodeMenu();
            m_GuestCodeUI.SetID( GUEST_CODE_MENU );
        }
        
		// Show the menu
        GetGame().GetUIManager().ShowScriptedMenu( m_GuestCodeUI, NULL );

		// Set required local variables.
		m_GuestCodeUI.SetBuildingPos( buildingPos );
		m_GuestCodeUI.SetDoorIndex( doorIndex );
    }

	// -------------------------------------------------------------------------------------------------------------------
	
	// ----------------------------------[[Client/Server]]----------------------------------------------------------------

	ref array< ref CLBuilding > GetPersistenceArray()
	{
		return m_PersistenceArray;
	}

	ref CLBuilding GetBuildingatPos( vector pos )
	{
		// Return a persistent building at a given position
		for ( int i = 0; i < m_PersistenceArray.Count(); i++ )
		{
			CLBuilding m_CLBuilding = m_PersistenceArray.Get(i);
			if ( m_CLBuilding && vector.Distance( m_CLBuilding.GetPos(), pos ) < 0.1 )
				return m_CLBuilding;
		}
		return null;
	}

	void AddDoorToBuilding( vector pos, int doorIndex, PlayerBase player = null )
	{
		CLBuilding 		m_CLBuilding;
		bool			foundBuilding = false;
		
		// Loop through all buildings
		for ( int i = 0; i < m_PersistenceArray.Count(); i++ )
		{
			if( Class.CastTo( m_CLBuilding, m_PersistenceArray.Get(i) ) )
			{
				// If it exists and within proper distance
				if ( vector.Distance( pos, m_CLBuilding.GetPos() ) < 0.1 )
				{
					// If the door already exists, don't add it. This is the prevent oos players from adding doors multiple times.
					CodeLockedDoors m_LockedDoor = m_CLBuilding.GetLockedDoor( doorIndex );
					if ( m_LockedDoor ) return;

					m_CLBuilding.AddCodeLockedDoor( doorIndex );
					foundBuilding = true;
					break;
				}
			}
		}
		
		// Only do this on the server
		if ( !GetGame().IsServer() ) return;
		
		// If the building doesn't exist, create it
		if ( !foundBuilding )
		{
			AddBuilding( pos, doorIndex, player );
		}
		// If it exists, create the door on the client
		else if ( foundBuilding )
		{
			param_Door data = new param_Door( pos, doorIndex );
			GetGame().RPCSingleParam( player, BASTRPC.RPC_CLIENT_ADDDOOR, data, true );
		}
	}

	void RemoveDoorFromBuilding( vector pos, int doorIndex, PlayerBase player = null )
	{
		CLBuilding 		m_CLBuilding;
		bool			foundBuilding = false;

		// Loop through all persistent buildings
		for ( int i = 0; i < m_PersistenceArray.Count(); i++ )
		{
			if( Class.CastTo( m_CLBuilding, m_PersistenceArray.Get(i) ) )
			{
				if ( vector.Distance( m_CLBuilding.GetPos(), pos ) < 0.1 )
				{
					// If building exists and is within proper didstance
					m_CLBuilding.RemoveCodeLockedDoor( doorIndex );
					foundBuilding = true;
					break;
				}
			}
		}

		// Only execute on server
		if ( !GetGame().IsServer() ) return;
		
		// Remove the door on the client
		param_Door data = new param_Door( pos, doorIndex );
		GetGame().RPCSingleParam( player, BASTRPC.RPC_CLIENT_REMOVEDOOR, data, true );
	}

	void RemoveBuilding( vector pos, PlayerBase player = null )
	{
		bool foundBuilding = false;
		for ( int i = 0; i <= m_PersistenceArray.Count(); i++ )
		{
			CLBuilding 	m_CLBuilding 	= m_PersistenceArray.Get(i);
			vector 		buildingPos 	= m_CLBuilding.GetPos();
			
			if ( vector.Distance( buildingPos, pos ) < 0.1 )
			{
				m_PersistenceArray.Remove(i);
				foundBuilding = true;
				continue;
			}
		}

		// Send the building over to the client.
		if ( !GetGame().IsServer() ) return;
		
		if ( foundBuilding )
		{
			param_Position data = new param_Position( buildingPos );
			GetGame().RPCSingleParam( player, BASTRPC.RPC_CLIENT_REMOVEBUILDING, data, true );
		}
	}

	// ------------------------------------------------------------------------------------------------------------------

	// ----------------------------------[[Server Only]]-----------------------------------------------------------------

	void InitializeBuildings()
	{
		if ( !GetGame().IsServer() ) return;
		
		for ( int i = 0; i < m_PersistenceArray.Count(); i++ )
		{
			CLBuilding m_CLBuilding = m_PersistenceArray.Get(i);
			m_CLBuilding.CloseAllDoors();
		}
	}

	void AddBuilding( vector pos, int doorIndex, PlayerBase player )
	{
		if ( !GetGame().IsServer() ) return;
		
		CLBuilding m_CLBuilding = new CLBuilding( pos, doorIndex );
		m_PersistenceArray.Insert( m_CLBuilding );

		// Send the building over to the client.
		param_Building data = new param_Building( m_CLBuilding );
		GetGame().RPCSingleParam( player, BASTRPC.RPC_CLIENT_SYNCHBUILDING, data, true );
	}

	// Send the server array to the client on connect. This is to reduce server-calls later.
	void BuildClientArray( PlayerBase player )
	{
		if ( !GetGame().IsServer() ) return;
		// Loop through all buildings in the array.
		for ( int i = 0; i < m_PersistenceArray.Count(); i++ )
		{
			// Grab the building and from that, grab the array of locked doors.
			CLBuilding m_CLBuilding = m_PersistenceArray.Get(i);

			// Send the building over to the client.
			param_Building data = new param_Building( m_CLBuilding );
			GetGame().RPCSingleParam( player, BASTRPC.RPC_CLIENT_SYNCHBUILDING, data, true, player.GetIdentity() );
		}
	}

	void SavePersistence()
	{
		if ( !GetGame().IsServer() ) return;

		if ( m_FileSerializer.Open( m_SaveFileDir, FileMode.WRITE ) )
		{
			m_FileSerializer.Write( m_PersistenceArray );
			m_FileSerializer.Close();
		}
	}

	void LoadPersistence()
	{
		if ( !GetGame().IsServer() ) return;

		if ( m_FileSerializer.Open( m_SaveFileDir, FileMode.READ ) )
		{
			m_FileSerializer.Read( m_PersistenceArray );
			m_FileSerializer.Close();
		}
		
		m_PersistenceArray.Debug();
	}

	// -------------------------------------------------------------------------------------------------------------
}