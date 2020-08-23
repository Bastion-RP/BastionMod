class BST_MCManager : PluginBase {
    private ref BST_MCConfig _config;

    void SetConfig(BST_MCConfig config) {
        _config = config;
    }

    BST_MCConfig GetConfig() { return _config; }
}

BST_MCManager GetBSTMCManager() {
    return BST_MCManager.Cast(GetPlugin(BST_MCManager));
}