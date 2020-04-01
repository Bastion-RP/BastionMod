class BastionConfigHandler : PluginBase {
    private ref BastionBankingConfig bbConfig;
    private ref array<ref BastionATM> ATMLocations;

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
        if (!FileExist(BBConst.atmLocationsDir)) {
            ATMLocations = new array<ref BastionATM>();

            ATMLocations.Insert(new BastionATM());
            ATMLocations.Insert(new BastionATM());
            JsonFileLoader<array<ref BastionATM>>.JsonSaveFile(BBConst.atmLocationsDir, ATMLocations);
        } else {
            JsonFileLoader<array<ref BastionATM>>.JsonLoadFile(BBConst.atmLocationsDir, ATMLocations);
        }
        SpawnATMs();
    }

    void SpawnATMs() {
        foreach (BastionATM atmLocation : ATMLocations) {
            if (atmLocation) {
                ItemBase newATM = GetGame().CreateObject(bbConfig.GetATMClassName(), atmLocation.GetPosition().ToVector());

                if (newATM) {
                    newATM.SetPosition(atmLocation.GetPosition().ToVector());
                    newATM.SetOrientation(atmLocation.GetOrientation().ToVector());
                }
            }
        }
    }

    void SetConfig(BastionBankingConfig bbConfig) { this.bbConfig = bbConfig; }
    ref BastionBankingConfig GetConfig() { return bbConfig; }
}

BastionConfigHandler GetBBankConfig() {
    return BastionConfigHandler.Cast(GetPlugin(BastionConfigHandler));
}