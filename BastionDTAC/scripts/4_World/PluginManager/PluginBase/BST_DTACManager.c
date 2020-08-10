class BST_DTACManager : PluginBase {
    bool IsRequiredClass(array<string> arrRequiredClasses, int intClass) {
        array<string> arrPlayerClass;
        string playerClass;

        playerClass = typename.EnumToString(BastionClasses, intClass);

        if (playerClass.IndexOf("_") != -1) {
            playerClass.Replace("_", "-");
        }
        playerClass.ToLower();

        foreach (string str : arrRequiredClasses) {
            str.ToLower();

            if (playerClass == str) {
                return true;
            }
        }
        return false;
    }
}

BST_DTACManager GetDTACManager() {
    return BST_DTACManager.Cast(GetPlugin(BST_DTACManager));
}