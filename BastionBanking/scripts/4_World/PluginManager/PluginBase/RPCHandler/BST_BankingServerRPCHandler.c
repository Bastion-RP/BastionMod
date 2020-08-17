// Fee forumla so I don't forget
// Depositing Known: amount being deposited(difference) total=amount/(1-%fee)
// Depositing Known: total, find amount deposited amount=total(1-%fee)

class BST_BankingServerRPCHandler : PluginBase {
    void BST_BankingServerRPCHandler() {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }

        GetDayZGame().Event_OnRPC.Insert(OnRPC);
    }

    void ~BST_BankingServerRPCHandler() {
        GetDayZGame().Event_OnRPC.Remove(OnRPC);
    }

    void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }
        if (!sender) { return; }

        ref array<ItemBase> outItems;
        PlayerBase player;
        Param params;
        BST_BankAccount bankAccount;
        string playerId, characterId, accountDir;
        int amount, bankFunds, bankOverflowFunds, bankFundsCap, transferAmount;

        switch (rpc_type) {
            case BST_BankRPC.SERVER_GRAB_ACCOUNT:
                {
                    player = PlayerBase.Cast(target);

                    if (!player || !player.GetIdentity()) { return; }
                    playerId = player.GetIdentity().GetPlainId();
                    characterId = "" + player.GetMultiCharactersPlayerId();

                    if (characterId.Length() <= 0) { return; }
                    bankAccount = GetBSTBankingAccountManager().FindAccount(playerId, characterId);
                    
                    SendClientBankAccount(bankAccount, player);
                    break;
                }
            case BST_BankRPC.SERVER_DEPOSIT_FUNDS:
                {
                    Param1<int> dataDeposit;

                    if (!ctx.Read(dataDeposit)) { return; }
                    player = PlayerBase.Cast(target);
                    amount = dataDeposit.param1;

                    if (!player || !player.GetIdentity() || amount <= 0) { return; }
                    playerId = player.GetIdentity().GetPlainId();
                    characterId = "" + player.GetMultiCharactersPlayerId();

                    if (GetBSTBankingManager().CanDeposit(player, amount, outItems)) {
                        bankAccount = GetBSTBankingAccountManager().Deposit(playerId, characterId, amount);

                        SendClientBankAccount(bankAccount, player);
                        GetBSTBankingManager().RemoveCurrency(outItems, amount);
                    }
                    break;
                }
            case BST_BankRPC.SERVER_WITHDRAW_FUNDS:
                {
                    Param1<int> dataWithdraw;

                    if (!ctx.Read(dataWithdraw)) { return; }
                    player = PlayerBase.Cast(target);
                    amount = dataWithdraw.param1;

                    if (!player || !player.GetIdentity() || amount <= 0) { return; }
                    playerId = player.GetIdentity().GetPlainId();
                    characterId = "" + player.GetMultiCharactersPlayerId();
                    accountDir = BST_BankingConst.playerDir + "\\" + playerId + "\\" + characterId + ".json";
                    bankAccount = GetBSTBankingAccountManager().FindAccount(playerId, characterId);

                    if (bankAccount) {
                        bankFunds = bankAccount.GetFunds();

                        if (bankFunds >= amount) {
                            bankAccount.Withdraw(amount);
                            GetBSTBankingManager().AddCurrency(player, amount);
                            SendClientBankAccount(bankAccount, player);
                            JsonFileLoader<BST_BankAccount>.JsonSaveFile(accountDir, bankAccount);
                        }
                    }
                    break;
                }
            case BST_BankRPC.SERVER_TRANSFER_FUNDS:
                {
                    Param1<int> dataTransfer;

                    if (!ctx.Read(dataTransfer)) { return; }
                    player = PlayerBase.Cast(target);
                    amount = dataTransfer.param1;

                    if (!player || !player.GetIdentity() || amount <= 0) { return; }
                    playerId = player.GetIdentity().GetPlainId();
                    characterId = "" + player.GetMultiCharactersPlayerId();
                    accountDir = BST_BankingConst.playerDir + "\\" + playerId + "\\" + characterId + ".json";
                    bankAccount = GetBSTBankingAccountManager().FindAccount(playerId, characterId);
                    bankFundsCap = GetBSTBankingConfigHandler().GetConfig().GetBankFundsCap();

                    if (bankAccount) {
                        bankFunds = bankAccount.GetFunds();
                        bankOverflowFunds = bankAccount.GetOverflowFunds();
                        transferAmount = Math.Floor(amount * (1 - GetBSTBankingConfigHandler().GetConfig().GetOverflowTransferFee()));

                        if (amount > bankOverflowFunds || (bankFunds + transferAmount) > bankFundsCap || transferAmount <= 0) { return; }
                        bankAccount.WithdrawOverflow(amount);
                        bankAccount.Deposit(transferAmount);
                        SendClientBankAccount(bankAccount, player);
                        JsonFileLoader<BST_BankAccount>.JsonSaveFile(accountDir, bankAccount);
                    }
                    break;
                }
        }
    }

    void SendClientBankAccount(BST_BankAccount account, PlayerBase player) {
        if (!player || !player.GetIdentity() || !account) { return; }
        Param params = new Param1<BST_BankAccount>(account);

        GetGame().RPCSingleParam(player, BST_BankRPC.CLIENT_RECEIVE_ACCOUNT, params, true, player.GetIdentity());
    }
}