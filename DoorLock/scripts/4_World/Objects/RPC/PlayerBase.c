/*
	BastionRP RPCs by RoomService
	This DayZ Standalone Mod MAY NOT BE MODIFIED, REPRODUCED or UPLOADED to ANY platform without express consent of the author.
*/

modded class PlayerBase extends ManBase
{
	PluginDoorPersistence 	m_DoorPersistence;

	// Variables to reduce redundancy in rpc's
	CLBuilding				m_CLBuilding;
	CodeLockedDoors 		m_LockedDoor;
	vector					pos;
	Building				building;
	int						doorIndex;
	bool					changeCode;
	string					widget;
	string					playerId;
	string					passcode;

	override void OnRPC( PlayerIdentity sender, int rpc_type, ParamsReadContext ctx )
	{
		super.OnRPC(sender, rpc_type, ctx);

		// If this is the server
		if ( GetGame().IsServer() && GetGame().IsMultiplayer() )
		{
			switch( rpc_type )
			{
				case BASTRPC.RPC_SERVER_SETPASSCODE:
				{
					param_SetCode 	server_RPC1;
					param_Building 	client_BuildingData;
					param_Door		client_DoorData;
					// Handle setting a passcode
					ctx.Read( server_RPC1 );

					m_DoorPersistence 	= PluginDoorPersistence.Cast( GetPlugin( PluginDoorPersistence) );
					pos 				= server_RPC1.param1;
					doorIndex			= server_RPC1.param2;
					playerId 			= server_RPC1.param3;
					passcode 			= server_RPC1.param4;
					changeCode			= server_RPC1.param5;
					m_CLBuilding 		= m_DoorPersistence.GetBuildingatPos( pos );
					m_LockedDoor 		= m_CLBuilding.GetLockedDoor( doorIndex );

					// If the user is not changing the code
					if ( !changeCode )
					{
						// Check to make sure an owner isn't already set, this is for players potentially out of synch
						if ( m_LockedDoor.GetOwnerId() != "" ) return;

						// Set owner of door, this is the person who's capable of changing the passcode.
						m_LockedDoor.SetOwnerId( playerId );

						// Send the building to all clients.
						client_BuildingData = new param_Building( m_CLBuilding );
						GetGame().RPCSingleParam( this, BASTRPC.RPC_CLIENT_SYNCHBUILDING, client_BuildingData, true );

						// Set the passcode of the door, after sending the building to the client.
						m_LockedDoor.SetPasscode( passcode );
					}
					else
					{
						// Clear the persistent player array on the door
						m_LockedDoor.ClearPlayers();

						// Change the passcode on the door
						m_LockedDoor.SetPasscode( passcode );

						// Clear the persistent player array on the door for the clients
						client_DoorData = new param_Door( pos, doorIndex );
						GetGame().RPCSingleParam( this, BASTRPC.RPC_CLIENT_CLEARDOORPLAYERARRAY, client_DoorData, true );
					}
					break;
				}
				case BASTRPC.RPC_SERVER_ENTERPASSCODE:
				{
					param_EnterCode 		server_RPC2;
					param_ClientSetCode 	client_SetCode;
					// Handle entering a passcode
					ctx.Read( server_RPC2 );

					// Load this block of data
					m_DoorPersistence 	= PluginDoorPersistence.Cast( GetPlugin( PluginDoorPersistence) );
					pos					= server_RPC2.param1;
					doorIndex			= server_RPC2.param2;
					playerId			= server_RPC2.param3;
					passcode			= server_RPC2.param4;
					m_CLBuilding 		= m_DoorPersistence.GetBuildingatPos( pos );
					m_LockedDoor 		= m_CLBuilding.GetLockedDoor( doorIndex );
					building			= m_CLBuilding.GetBuilding();

					// If the passcode is correct
					if ( m_LockedDoor.GetPasscode() == passcode )
					{
						// Check for easy access
						if ( !m_CLBuilding.HasEasyAccess( doorIndex, playerId ) )
						{
							// If they don't have it, give it to them
							m_LockedDoor.InsertPlayer( playerId );
							client_DoorData = new param_Door( pos, doorIndex );
							GetGame().RPCSingleParam( this, BASTRPC.RPC_CLIENT_ADDCLIENTTODOOR, client_DoorData, true, sender );
						}

						// Open the door
						building.OpenDoor( doorIndex );
						// Close the menu client-side
						GetGame().RPCSingleParam( this, BASTRPC.RPC_CLIENT_CLOSEMENU, null, true, sender );
						break;
					}
					else
					{
						GetGame().RPCSingleParam( this, BASTRPC.RPC_CLIENT_PASSCODEERROR, null, true, sender );
					}
					break;
				}
			}
		}
		else if ( GetGame().IsClient() )
		{
			switch ( rpc_type )
			{
				case BASTRPC.RPC_CLIENT_SYNCHBUILDING:
				{
					param_Building client_RPC1;
					// Synch building from server with client
					ctx.Read( client_RPC1 );

					m_DoorPersistence = PluginDoorPersistence.Cast( GetPlugin( PluginDoorPersistence) );
					m_DoorPersistence.SynchBuilding( client_RPC1.param1 );
					break;
				}
				case BASTRPC.RPC_CLIENT_REMOVEBUILDING:
				{
					param_Position client_RPC2;
					// Remove the building on the client
					ctx.Read( client_RPC2 );

					m_DoorPersistence = PluginDoorPersistence.Cast( GetPlugin( PluginDoorPersistence) );
					m_DoorPersistence.RemoveBuilding( client_RPC2.param1 );
					break;
				}
				case BASTRPC.RPC_CLIENT_REMOVEDOOR:
				{
					param_Door client_RPC3;
					// Remove the door from the building on the client
					ctx.Read( client_RPC3 );

					m_DoorPersistence = PluginDoorPersistence.Cast( GetPlugin( PluginDoorPersistence) );
					m_DoorPersistence.RemoveDoorFromBuilding( client_RPC3.param1, client_RPC3.param2 );
					break;
				}
				case BASTRPC.RPC_CLIENT_ADDDOOR:
				{
					param_Door client_RPC4;
					// Add door to building on the client
					ctx.Read( client_RPC4 );

					m_DoorPersistence = PluginDoorPersistence.Cast( GetPlugin( PluginDoorPersistence) );
					m_DoorPersistence.AddDoorToBuilding( client_RPC4.param1, client_RPC4.param2 );
					break;
				}
				case BASTRPC.RPC_CLIENT_ADDCLIENTTODOOR:
				{
					param_Door client_RPC5;
					ctx.Read( client_RPC5 );

					pos				= client_RPC5.param1;
					doorIndex		= client_RPC5.param2;
					m_CLBuilding 	= m_DoorPersistence.GetBuildingatPos( pos );
					m_LockedDoor 	= m_CLBuilding.GetLockedDoor( doorIndex );

					// Add persistent player to door on the client
					m_LockedDoor.InsertPlayer( GetGame().GetPlayer().GetIdentity().GetId() );
					break;
				}
				case BASTRPC.RPC_CLIENT_PASSCODEERROR:
				{
					TextWidget txt_EnterPin = TextWidget.Cast( GetWidgetUnderCursor().GetParent().FindAnyWidget("txtEnterPin") );
					txt_EnterPin.SetText( "PASSCODE INVALID!" );
					break;
				}
				case BASTRPC.RPC_CLIENT_CLOSEMENU:
				{
					// Close the correct menu
					if ( GetGame().GetUIManager().IsMenuOpen( ENTER_CODE_MENU ) )
						GetGame().GetUIManager().CloseMenu( ENTER_CODE_MENU );

					else if ( GetGame().GetUIManager().IsMenuOpen( GUEST_CODE_MENU ) )
						GetGame().GetUIManager().CloseMenu( GUEST_CODE_MENU );
					break;
				}
				case BASTRPC.RPC_CLIENT_CLEARDOORPLAYERARRAY:
				{
					param_Door client_RPC6;
					ctx.Read( client_RPC6 );

					m_DoorPersistence 	= PluginDoorPersistence.Cast( GetPlugin( PluginDoorPersistence) );
					pos				= client_RPC6.param1;
					doorIndex		= client_RPC6.param2;
					m_CLBuilding 	= m_DoorPersistence.GetBuildingatPos( pos );
					m_LockedDoor 	= m_CLBuilding.GetLockedDoor( doorIndex );

					// Clear persistent player array on the client
					m_LockedDoor.ClearPlayers();
					break;
				}
			}
		}
	}

	// Start building client m_DoorPersistence array on connect.
	override void OnConnect()
	{
		m_DoorPersistence = PluginDoorPersistence.Cast( GetPlugin( PluginDoorPersistence) );
		m_DoorPersistence.BuildClientArray( this );
	}
		
	// --------------------------------------------------
	// User Actions
	//---------------------------------------------------
	void SetActions()
	{
		super.SetActions();

		AddAction( ActionInteractLockedDoor );
		AddAction( ActionInteractEasyAccess );
		AddAction( ActionInteractChangePasscode );
	}
}