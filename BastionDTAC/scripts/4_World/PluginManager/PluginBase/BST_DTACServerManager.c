class BST_DTACServerManager : PluginBase {
    // DO NOT PASS THIS AS BST_DTACConfigServer TO CLIENT, pass BST_DTACConfig
    private ref BST_DTACConfigServer _config;

    void BST_DTACServerManager() {
        LoadConfig();
    }

    void LoadConfig() {
        if (FileExist(BST_DTACConst.configDir)) {
            JsonFileLoader<BST_DTACConfigServer>.JsonLoadFile(BST_DTACConst.configDir, _config);
            _config.Validate();
        } else {
            _config = new BST_DTACConfigServer();
        }
        JsonFileLoader<BST_DTACConfigServer>.JsonSaveFile(BST_DTACConst.configDir, _config);
    }

    BST_DTACConfigServer GetConfig() { return _config; }
}

BST_DTACServerManager GetDTACServerManager() {
    return BST_DTACServerManager.Cast(GetPlugin(BST_DTACServerManager));
}