modded class PlayerBase {
    void ~PlayerBase() {
        // Remove income loop
        if (GetGame().IsServer() && GetGame().IsMultiplayer()) {
            BSTBankingStopIncomeLoop();
        }
    }

    void BSTBankingStartIncomeLoop() {
        string debugTxt = "[BANKING DEBUG] Starting UBI on player=" + multicharactersPlayerName + " | id=" + multicharactersPlayerId + " | class=" + multicharactersPlayerClass;
        if (!GetIdentity()) {
            Print(debugTxt);
        } else {
            Print(debugTxt + " | pid=" + GetIdentity().GetPlainId());
        }
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(this.BSTBankingPayPassiveIncome, 60 * 1000, true); // Loop every minute
    }

    void BSTBankingStopIncomeLoop() {
        string debugTxt = "[BANKING DEBUG] Stopping UBI on player=" + multicharactersPlayerName + " | id=" + multicharactersPlayerId + " | class=" + multicharactersPlayerClass;
        if (!GetIdentity()) {
            Print(debugTxt);
        } else {
            Print(debugTxt + " | pid=" + GetIdentity().GetPlainId());
        }
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Remove(this.BSTBankingPayPassiveIncome);
    }

    void BSTBankingPayPassiveIncome() {
        string debugSuffix = multicharactersPlayerName + " | id=" + multicharactersPlayerId + " | class=" + multicharactersPlayerClass;
        if (!GetIdentity() || !IsAlive()) {
            if (!IsAlive()) {
                Print("[BANKING DEBUG] Error with payment! Player is dead! player=" + debugSuffix + " | pid=" + GetIdentity().GetPlainId());
            } else {
                Print("[BANKING DEBUG] Error with payment! Something went wrong! player=" + debugSuffix);
            }
            BSTBankingStopIncomeLoop();
            return;
        }
        GetBSTBankingAccountManager().PayUBI(this);
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
        if (GetGame().IsServer() && GetGame().IsMultiplayer()) {
            BSTBankingStopIncomeLoop();
        }
    }
}