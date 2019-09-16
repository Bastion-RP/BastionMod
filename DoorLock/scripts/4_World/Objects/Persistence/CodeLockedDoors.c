/*
	Door Persistence by RoomService
	This DayZ Standalone Mod MAY NOT BE MODIFIED, REPRODUCED or UPLOADED to ANY platform without express consent of the author.
*/

class CodeLockedDoors
{
	protected ref array< string > 		m_PersistentPlayers;
	protected int						m_DoorIndex;
	protected string					m_Passcode;
	protected string					m_OwnerId;

	void CodeLockedDoors( int index )
	{
		m_PersistentPlayers 	= new array< string >;
		m_DoorIndex 			= index;
		m_Passcode 				= "temp";
		m_OwnerId 				= "";
	}

	void ClearPlayers()
	{
		m_PersistentPlayers = new array< string >;
	}

	void SetPasscode( string passcode )
	{
		m_Passcode = passcode;
	}

	void SetOwnerId( string playerId )
	{
		m_OwnerId = playerId;
	}

	void InsertPlayer( string playerId )
	{
		m_PersistentPlayers.Insert( playerId );
	}

	ref array< string > GetPersistentPlayers()
	{
		return m_PersistentPlayers;
	}

	int GetLocalIndex()
	{
		return m_DoorIndex;
	}

	string GetPasscode()
	{
		return m_Passcode;
	}

	string GetOwnerId()
	{
		return m_OwnerId;
	}
}