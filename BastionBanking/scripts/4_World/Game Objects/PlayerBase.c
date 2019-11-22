modded class PlayerBase {
    private ref BastionPlayerAccount bastionPlayerAccount;
    private int m_PlayerIndex;

    ref BastionPlayerAccount GetBastionPlayerAccount() {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return null; }

        return bastionPlayerAccount;
    }

    int GetIndex() {
        return m_PlayerIndex;
    }

    void DepositPassiveIncome() {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }

        ref BastionBankAccount account = GetBankAccountManager().GetAccountByPlayerBase(this);
        int wage = GetBankAccountManager().GetWageByPlayerBase(this);

        if (account) {
            if (wage > 0) {
                GetBankAccountManager().Deposit(account, wage);
            }
        }
    }

    void SetBastionPlayerAccount(ref BastionPlayerAccount account) {
        bastionPlayerAccount = account;
    }

    void LoadBastionPlayerAccount() {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }

        string playerAccountDir = BBConst.playerDir + "\\" + this.GetIdentity().GetPlainId() + "\\" + m_PlayerIndex + BBConst.fileType;

        if (FileExist(playerAccountDir)) {
            JsonFileLoader<BastionPlayerAccount>.JsonLoadFile(playerAccountDir, bastionPlayerAccount);
            // Validate the file

            if (bastionPlayerAccount.GetJobPosition() == string.Empty) {
                bastionPlayerAccount.SetJobPosition("unemployed");
                JsonFileLoader<ref BastionPlayerAccount>.JsonSaveFile(playerAccountDir, bastionPlayerAccount);
            }
        }
    }
    override void EEKilled(Object killer) {
        super.EEKilled(killer);
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Remove(this.DepositPassiveIncome);
    }

    override void OnConnect() {
        LoadBastionPlayerAccount();
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(this.DepositPassiveIncome, GetBBankConfig().GetPassivePayInterval() * 60000, true);
        super.OnConnect();
    }

    override void OnDisconnect() {
        super.OnDisconnect();

        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Remove(this.DepositPassiveIncome);
    }
}