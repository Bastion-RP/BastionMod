modded class PlayerBase {
    override void OnConnect() {
        Param params = new Param1<BST_BankingConfig>(GetBSTBankingConfigHandler().GetConfig());
        
        super.OnConnect();
        GetGame().RPCSingleParam(this, BST_BankRPC.CLIENT_RECEIVE_CONFIG, params, true, GetIdentity());
    }
}