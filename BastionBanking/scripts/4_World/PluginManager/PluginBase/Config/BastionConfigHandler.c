class BastionConfigHandler : PluginBase {
    private ref BastionBankingConfig bbConfig;

    void BastionConfigHandler() {
        if (!FileExist(BBConst.configDir)) {
            bbConfig = new BastionBankingConfig();
            JsonFileLoader<BastionBankingConfig>.JsonSaveFile(BBConst.configDir, bbConfig);
        } else {
            JsonFileLoader<BastionBankingConfig>.JsonLoadFile(BBConst.configDir, bbConfig);
            bbConfig.Validate();
            JsonFileLoader<BastionBankingConfig>.JsonSaveFile(BBConst.configDir, bbConfig);
        }
    }

    ref BastionBankingConfig GetConfig() {
        return bbConfig;
    }
}

BastionConfigHandler GetBBankConfig() {
    return BastionConfigHandler.Cast(GetPlugin(BastionConfigHandler));
}