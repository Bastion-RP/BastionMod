modded class PlayerBase {
    private float bst_BankLastPayTick = 0.0;
    private bool bst_BankIsPaying = false;

    void ~PlayerBase() {
        // Remove income loop
        if (GetGame().IsServer() && GetGame().IsMultiplayer()) {
            BSTBankingStopIncomeLoop();
        }
    }

    void BSTBankingStartIncomeLoop() {
        if (bst_BankIsPaying) { return; }
        string debugTxt = GetBSTLibTimestamp().GetHourTimestampFormatted() + "[BANK DEBUG] Starting UBI on player=" + BST_APICharName + " | id=" + BST_APICharID + " | class=" + BST_APICharClass;

        if (!GetIdentity()) {
            Print(debugTxt);
        } else {
            Print(debugTxt + " | pid=" + GetIdentity().GetPlainId());
        }
		GetGame().GetUpdateQueue(CALL_CATEGORY_SYSTEM).Insert(this.BSTBankingPayPassiveIncome);

        bst_BankIsPaying = true;
    }

    void BSTBankingStopIncomeLoop() {
        string debugTxt = GetBSTLibTimestamp().GetHourTimestampFormatted() + "[BANK DEBUG] Stopping UBI on player=" + BST_APICharName + " | id=" + BST_APICharID + " | class=" + BST_APICharClass;

        if (!GetIdentity()) {
            Print(debugTxt);
        } else {
            Print(debugTxt + " | pid=" + GetIdentity().GetPlainId());
        }
		GetGame().GetUpdateQueue(CALL_CATEGORY_SYSTEM).Remove(this.BSTBankingPayPassiveIncome);

        bst_BankIsPaying = false;
    }

    void BSTBankingPayPassiveIncome(float tDelta) {
        if (!GetIdentity() || !IsAlive()) {
            string debugPrefix = GetBSTLibTimestamp().GetHourTimestampFormatted() + "[BANK DEBUG]";
            string debugSuffix = BST_APICharName + " | id=" + BST_APICharID + " | class=" + BST_APICharClass;

            if (!IsAlive()) {
                Print(debugPrefix + " Error with payment! Player is dead! player=" + debugSuffix + " | pid=" + GetIdentity().GetPlainId());
            } else {
                Print(debugPrefix + " Error with payment! Something went wrong! player=" + debugSuffix);
            }
            BSTBankingStopIncomeLoop();
            return;
        }
        bst_BankLastPayTick += tDelta;

        if (bst_BankLastPayTick < 60.0) { return; }
        bst_BankLastPayTick = 0.0;
        
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