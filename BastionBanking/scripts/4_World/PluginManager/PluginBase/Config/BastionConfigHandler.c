class BastionConfigHandler : PluginBase {
    private ref BastionBankingConfig bbConfig;

    void BastionConfigHandler() {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }

        if (!FileExist(BBConst.configDir)) {
            bbConfig = new BastionBankingConfig();
            JsonFileLoader<BastionBankingConfig>.JsonSaveFile(BBConst.configDir, bbConfig);
        } else {
            JsonFileLoader<BastionBankingConfig>.JsonLoadFile(BBConst.configDir, bbConfig);
            bbConfig.Validate();
            JsonFileLoader<BastionBankingConfig>.JsonSaveFile(BBConst.configDir, bbConfig);
        }
    }

    int GetLoginTimeout() {
        return bbConfig.LoginTimeout();
    }

    int GetPassivePayInterval() {
        return bbConfig.PassivePayInterval();
    }

    int GetFundsCap() {
        return bbConfig.BankFundsCap();
    }

    float GetTransferFee() {
        return bbConfig.OverflowTransferFee();
    }
}

BastionConfigHandler GetBBankConfig() {
    return BastionConfigHandler.Cast(GetPlugin(BastionConfigHandler));
}