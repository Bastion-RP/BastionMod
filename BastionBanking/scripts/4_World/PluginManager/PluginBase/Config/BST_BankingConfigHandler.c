class BST_BankingConfigHandler : PluginBase {
    private ref BST_BankingConfig _config;
    private ref array<ref BST_BankingATM> _arrATMLocations;

    void BST_BankingConfigHandler() {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }
        if (!FileExist(BST_BankingConst.configDir)) {
        } else {
            JsonFileLoader<BST_BankingConfig>.JsonLoadFile(BST_BankingConst.configDir, _config);
            _config.Validate();
        }
        JsonFileLoader<BST_BankingConfig>.JsonSaveFile(BST_BankingConst.configDir, _config);
        
        if (!FileExist(BST_BankingConst.atmLocationsDir)) {
            _arrATMLocations = new array<ref BST_BankingATM>();

            _arrATMLocations.Insert(new BST_BankingATM());
            _arrATMLocations.Insert(new BST_BankingATM());
            JsonFileLoader<array<ref BST_BankingATM>>.JsonSaveFile(BST_BankingConst.atmLocationsDir, _arrATMLocations);
        } else {
            JsonFileLoader<array<ref BST_BankingATM>>.JsonLoadFile(BST_BankingConst.atmLocationsDir, _arrATMLocations);
        }
        SpawnATMs();
    }

    void SpawnATMs() {
        foreach (BST_BankingATM atmLocation : _arrATMLocations) {
            if (atmLocation) {
                ItemBase newATM = ItemBase.Cast(GetGame().CreateObject(_config.GetATMClassName(), atmLocation.GetPosition().ToVector()));

                if (newATM) {
                    newATM.SetPosition(atmLocation.GetPosition().ToVector());
                    newATM.SetOrientation(atmLocation.GetOrientation().ToVector());
                }
            }
        }
    }

    void SetConfig(BST_BankingConfig config) {
        _config = config;
    }

    BST_BankingConfig GetConfig() { return _config; }
}

BST_BankingConfigHandler GetBSTBankingConfigHandler() {
    return BST_BankingConfigHandler.Cast(GetPlugin(BST_BankingConfigHandler));
}