modded class PlayerBase {
    private ref BastionPlayerAccount bastionPlayerAccount;

    void ~PlayerBase() {
        if (bastionPlayerAccount) {
            delete bastionPlayerAccount;
        }
    }

    BastionPlayerAccount GetBastionPlayerAccount() {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return null; }

        Print("[DEBUG] PlayerBase | GetBastionPlayerAccount | Getting player account | " + bastionPlayerAccount);
        return bastionPlayerAccount;
    }

    void DepositPassiveIncome() {
        BastionBankAccount account = GetBankAccountManager().GetAccountByPlayerBase(this);
        int wage = GetBankAccountManager().GetWageByPlayerBase(this);

        if (account) {
            if (wage > 0) {
                GetBankAccountManager().Deposit(account, wage);
            }
        }
    }

    void SetBastionPlayerAccount(BastionPlayerAccount account) {
        bastionPlayerAccount = account;
    }

    void LoadBastionPlayerAccount() {
        string playerAccountDir = BBConst.playerDir + "\\" + GetIdentity().GetPlainId() + "\\" + multicharactersPlayerId + BBConst.fileType;

        Print("[DEBUG] PlayerBase | LoadBastionPlayerAccount | Loading account | dir=" + playerAccountDir);

        if (FileExist(playerAccountDir)) {
            JsonFileLoader<BastionPlayerAccount>.JsonLoadFile(playerAccountDir, bastionPlayerAccount);
            bastionPlayerAccount.Validate();
            JsonFileLoader<BastionPlayerAccount>.JsonSaveFile(playerAccountDir, bastionPlayerAccount);
            Print("[DEBUG] PlayerBase | LoadBastionPlayerAccount | File exists! Loading account | " + bastionPlayerAccount);
        }
    }
    override void EEKilled(Object killer) {
        super.EEKilled(killer);
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Remove(this.DepositPassiveIncome);
        
        if (bastionPlayerAccount) {
            delete bastionPlayerAccount;
        }
    }

    override void OnConnect() {
        if (GetGame().IsServer() && GetGame().IsMultiplayer()) {
            LoadBastionPlayerAccount();
            GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(this.DepositPassiveIncome, GetBBankConfig().GetConfig().GetPassivePayInterval() * 60000, true);
        }
        super.OnConnect();
    }

    override void OnDisconnect() {
        super.OnDisconnect();

        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Remove(this.DepositPassiveIncome);
    }
}