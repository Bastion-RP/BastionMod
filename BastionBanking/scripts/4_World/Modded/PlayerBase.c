modded class PlayerBase {
    void ~PlayerBase() {
        // Remove income loop
        BSTBankingStopIncomeLoop();
    }

    void BSTBankingStartIncomeLoop() {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }
        int payInterval = GetBSTBankingConfigHandler().GetConfig().GetPassivePayInterval();

        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(this.BSTBankingPayPassiveIncome, payInterval * 60 * 1000, true);
    }

    void BSTBankingStopIncomeLoop() {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Remove(this.BSTBankingPayPassiveIncome);
    }

    void BSTBankingPayPassiveIncome() {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer() || !GetIdentity()) { return; }
        int payRate = GetBSTBankingConfigHandler().GetConfig().GetPayByClass(multicharactersPlayerClass);

        if (payRate > 0) {
            GetBSTBankingAccountManager().Deposit(GetIdentity().GetPlainId(), multicharactersPlayerId.ToString(), multicharactersPlayerClass, payRate);
        }
    }

    override void OnConnect() {
        Param params = new Param1<BST_BankingConfig>(GetBSTBankingConfigHandler().GetConfig());

        super.OnConnect();
        GetGame().RPCSingleParam(this, BST_BankRPC.CLIENT_RECEIVE_CONFIG, params, true, GetIdentity());

        // Start income loop.
        BSTBankingStartIncomeLoop();
    }

    override void OnDisconnect() {
        super.OnDisconnect();

        // Stop income loop.
        BSTBankingStopIncomeLoop();
    }

    override void EEKilled(Object killer) {
        super.EEKilled(killer);

        // Stop income loop
        BSTBankingStopIncomeLoop();
    }
}