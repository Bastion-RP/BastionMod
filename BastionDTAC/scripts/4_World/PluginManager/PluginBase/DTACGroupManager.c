class DTACGroupManager : PluginBase {
    static const string CONST_DTAC_CLASSNAME = "brp_phone";
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

    bool HasDTAC(Man player) {
        if (!player) { return false; }
        
		array<EntityAI> arrayInventory = new array<EntityAI>();

		player.GetHumanInventory().EnumerateInventory(InventoryTraversalType.PREORDER, arrayInventory);

        foreach (EntityAI entity : arrayInventory) {
            if (entity) {
                string entityType = entity.GetType();

                entityType.ToLower();

                if (entityType == CONST_DTAC_CLASSNAME) {
                    return true;
                }
            }
        }
        return false;
    }
}

DTACGroupManager GetDTACGroupManager() {
    return DTACGroupManager.Cast(GetPlugin(DTACGroupManager));
}