modded class MissionGameplay {
  private autoptr StoredDataHook m_StoredDataHook;

  void MissionGameplay() {
    m_StoredDataHook = new StoredDataHook();
  }
}

modded class MissionServer {
  private autoptr StoredDataHook m_StoredDataHook;

  void StoredDataToClient( PlayerBase player )
  {
    BastionBankAccount account = GetBankAccountManager().FindAccount(player);
    
    int balance = 0;
    if (account)
      balance = account.GetFunds();
    
    Print(account);
    Print(balance);

    auto data = new Param2<string, int>( player.GetIdentity().GetPlainId(), balance );
    GetRPCManager().SendRPC( "BastionMenu", "ReceiveStoredData", data, true, identity );
  }

	override void InvokeOnDisconnect( PlayerBase player )
	{
    StoredDataToClient( player );
    super.InvokeOnDisconnect( player );    
  }
  override void InvokeOnConnect( PlayerBase player, PlayerIdentity identity ) {
    super.InvokeOnConnect( player, identity );
    StoredDataToClient( player );
  }

  void MissionServer() {
    m_StoredDataHook = new StoredDataHook();
  }
}