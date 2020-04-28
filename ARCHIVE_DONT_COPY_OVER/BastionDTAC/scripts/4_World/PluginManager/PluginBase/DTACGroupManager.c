class DTACGroupManager : PluginBase {
    static ref ScriptInvoker dtacRemovalInvoker;
    static ref ScriptInvoker dtacStatInvoker;

    void DTACGroupManager() {
        dtacRemovalInvoker = new ScriptInvoker();
        dtacStatInvoker = new ScriptInvoker();
    }

    void ~DTACGroupManager() {
        if (dtacRemovalInvoker) {
            delete dtacRemovalInvoker;
        }
        if (dtacStatInvoker) {
            delete dtacStatInvoker;
        }
    }
}

DTACGroupManager GetDTACGroupManager() {
    return DTACGroupManager.Cast(GetPlugin(DTACGroupManager));
}