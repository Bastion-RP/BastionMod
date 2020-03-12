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

    // TODO: Ask if this is ok or if we should try something else
    string serverName = "BastionRP | S1";
    if (IsCLIParam("serverName"))
      GetCLIParam("serverName", serverName)
    
    auto data = new Param3<int, string, string>( balance, steam, serverName );
    GetRPCManager().SendRPC( "BastionMenu", "ReceiveStoredData", data, true, player.GetIdentity() );
  }

  override void InvokeOnConnect( PlayerBase player, PlayerIdentity identity ) {
    super.InvokeOnConnect( player, identity );
    StoredDataToClient( player );
  }

  void MissionServer() {
    m_StoredDataHook = new StoredDataHook();
  }
}