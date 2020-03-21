modded class MissionGameplay {
  static ref StoredDataHook m_StoredDataHook;

  static ref StoredDataHook GetStoredDataHook()
  {
    if ( !m_StoredDataHook )
      m_StoredDataHook = new StoredDataHook();

    return m_StoredDataHook;
  }

  void MissionGameplay() {
    m_StoredDataHook = new StoredDataHook();
  }
}

modded class MissionServer {
  private autoptr StoredDataHook m_StoredDataHook;

  void StoredDataToClient( PlayerBase player )
  {
    // TODO: Test with a player that actually has a bank account
    BastionAccountManager manager = GetBankAccountManager();

    int balance = 0;
    if (manager) {
      BastionBankAccount account = manager.FindAccount(player);
      if (account)
        balance = account.GetFunds();
    }

    string steam = player.GetIdentity().GetPlainId();

    string serverName = "BastionRP";
    if (IsCLIParam("serverName"))
      GetCLIParam("serverName", serverName);
    
    auto data = new Param3<int, string, string>( balance, steam, serverName );
    GetRPCManager().SendRPC( "BastionMenu", "ReceiveStoredData", data, true, player.GetIdentity() );
  }

  override void OnClientDisconnectedEvent(PlayerIdentity identity, PlayerBase player, int logoutTime, bool authFailed)
  {
    StoredDataToClient( player );
    super.OnClientDisconnectedEvent( identity, player, logoutTime, authFailed );
  }

  override void InvokeOnConnect( PlayerBase player, PlayerIdentity identity ) {
    super.InvokeOnConnect( player, identity );
    StoredDataToClient( player );
  }

  void MissionServer() {
    m_StoredDataHook = new StoredDataHook();
  }
}