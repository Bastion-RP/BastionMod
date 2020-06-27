modded class PlayerBase {
    private ref BastionPlayerAccount bastionPlayerAccount;

    void ~PlayerBase() {
        if (bastionPlayerAccount) {
            delete bastionPlayerAccount;
        }
    }

    override void Init()
    {
        if ( !GetGame().IsServer() || !GetGame().IsMultiplayer() ) 
        {
			DayzPlayerItemBehaviorCfg toolsOneHanded = new DayzPlayerItemBehaviorCfg;
			toolsOneHanded.SetToolsOneHanded();
			
			GetDayZPlayerType().AddItemInHandsProfileIK("BRP_CopperCoin", "dz/anims/workspaces/player/player_main/player_main_1h.asi", toolsOneHanded, "dz/anims/anm/player/ik/ammunition/22_LooseRounds.anm");
			GetDayZPlayerType().AddItemInHandsProfileIK("BRP_SilverCoin", "dz/anims/workspaces/player/player_main/player_main_1h.asi", toolsOneHanded, "dz/anims/anm/player/ik/ammunition/22_LooseRounds.anm");
			GetDayZPlayerType().AddItemInHandsProfileIK("BRP_GoldCoin", "dz/anims/workspaces/player/player_main/player_main_1h.asi", toolsOneHanded, "dz/anims/anm/player/ik/ammunition/22_LooseRounds.anm");
		}
        super.Init();
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
        super.OnConnect();
        
        if (GetGame().IsServer() && GetGame().IsMultiplayer()) {
            Param params = new Param1<BastionBankingConfig>(GetBBankConfig().GetConfig());

            LoadBastionPlayerAccount();
            GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(this.DepositPassiveIncome, GetBBankConfig().GetConfig().GetPassivePayInterval() * 60000, true);
            GetGame().RPCSingleParam(this, BSTBankRPC.RPC_CLIENT_INIT, params, true, GetIdentity());
        }
    }

    override void OnDisconnect() {
        super.OnDisconnect();

        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Remove(this.DepositPassiveIncome);
    }
}