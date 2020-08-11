class BST_DTACClientManager : PluginBase {
    private ref BST_DTACConfig _config;

    void SetConfig(BST_DTACConfig config) {
        _config = config;
    }
    
    BST_DTACConfig GetConfig() { return _config; }
}

BST_DTACClientManager GetDTACClientManager() {
    return BST_DTACClientManager.Cast(GetPlugin(BST_DTACClientManager));
}