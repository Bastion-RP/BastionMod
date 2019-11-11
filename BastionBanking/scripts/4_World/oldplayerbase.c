/* modded class PlayerBase {
    private int m_PlayerIndex;
    protected int bankStoredRations = 0;
    protected int bankOverflowRations = 0;

    void PlayerBase() {
        RegisterNetSyncVariableInt("bankStoredRations");
        RegisterNetSyncVariableInt("bankOverflowRations");
    }

    void ~PlayerBase() {
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Remove(PayPlayerWage);
    }

    override void OnStoreSave(ParamsWriteContext ctx) {
        super.OnStoreSave(ctx);

        ctx.Write(bankStoredRations);
        ctx.Write(bankOverflowRations);
        SavePlayerBank();
    }

    override bool OnStoreLoad(ParamsReadContext ctx, int version) {
        if (!super.OnStoreLoad(ctx, version)) {
            return false;
        }
        if (!ctx.Read(bankStoredRations)) {
            bankStoredRations = 0;
            return false;
        }
        if (!ctx.Read(bankOverflowRations)) {
            bankOverflowRations = 0;
            return false;
        }
        return true;
    }

    override void AfterStoreLoad() {
        super.AfterStoreLoad();
        Print("After store load");

        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }

        StartWageTimer();
    }

    void WithdrawRations(int amount) {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }

        bankStoredRations -= amount;
        SetSynchDirty();
    }

    void DepositRations(int amount) {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }

        if ((bankStoredRations + amount) >= 1000) {
            int gap = 1000 - bankStoredRations;
            int remaining = amount - gap;

            bankStoredRations += gap;
            bankOverflowRations += remaining;
        } else {
            bankStoredRations += amount;
        }
        SetSynchDirty();
    }

    int GetStoredRations() {
        return bankStoredRations;
    }

    int GetOverflowRations() {
        return bankOverflowRations;
    }

    void StartWageTimer() {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }
        // MAKE CONFIGURABLE LATER. For now testing with every second.
        Print("Starting income loop");
        //GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(PayPlayerWage, 1000, true);
    }

    void SavePlayerBank() {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }

        string clientId = GetIdentity().GetPlainId();
        string clientDir = BBConst.playerDir + clientId;
        string saveDir = clientDir + "\\" + m_PlayerIndex + BBConst.fileType;
        map<string, int> mapBanking = new map<string, int>();

        if (!FileExist(clientDir)) {
            MakeDirectory(clientDir);
        }
        mapBanking.Insert(BBConst.mapStored, bankStoredRations);
        mapBanking.Insert(BBConst.mapOverflow, bankOverflowRations)
        JsonFileLoader<map<string, int>>.JsonSaveFile(saveDir, mapBanking);
    }

    void PayPlayerWage() {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }

        if (bankStoredRations >= 100) {
            int stored = bankStoredRations;
            int overflow = stored - 100;

            if (overflow > 1) {
                bankStoredRations -= overflow;
                bankOverflowRations += overflow;
            }
            bankOverflowRations += 1
        } else {
            bankStoredRations += 1;
        }

        Print("bankStoredRations=" + bankStoredRations);
        Print("bankOverflowRations=" + bankOverflowRations);
        SavePlayerBank();
        SetSynchDirty();
    }

    void LoadPlayerBankAccount(map<string, int> bankMap) {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }

        int storedRations;
        int overflowRations;

        bankMap.Find(BBConst.mapStored, storedRations);
        bankMap.Find(BBConst.mapOverflow, overflowRations);

        bankStoredRations = storedRations;
        bankOverflowRations = overflowRations;
        Print("bankStoredRations=" + bankStoredRations);
        Print("bankOverflowRations=" + bankOverflowRations);
        SetSynchDirty();
    }

    override void EEKilled(Object killer) {
        super.EEKilled(killer);

        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Remove(PayPlayerWage);
    }

    override void OnDisconnect() {
        super.OnDisconnect();

        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Remove(PayPlayerWage);
    }
} */