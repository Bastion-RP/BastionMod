class BST_DTACGroupManager : PluginBase {
    static ref ScriptInvoker dtacRemovalInvoker;
    static ref ScriptInvoker dtacStatInvoker;

    void BST_DTACGroupManager() {
        dtacRemovalInvoker = new ScriptInvoker();
        dtacStatInvoker = new ScriptInvoker();
    }

    void ~BST_DTACGroupManager() {
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
                string requiredEntityType = GetDTACClientManager().GetConfig().GetPhoneClassname();

                entityType.ToLower();
                requiredEntityType.ToLower();

                if (entityType == requiredEntityType) {
                    return true;
                }
            }
        }
        return false;
    }
}

BST_DTACGroupManager GetDTACGroupManager() {
    return BST_DTACGroupManager.Cast(GetPlugin(BST_DTACGroupManager));
}