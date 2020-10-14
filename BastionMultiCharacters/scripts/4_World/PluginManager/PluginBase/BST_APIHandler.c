class BST_APIHandler : PluginBase {
    string GetClassNameFromInt(int classInt) {
        string className = typename.EnumToString(BastionClasses, classInt);

        if (className.IndexOf("_") != -1) {
            className.Replace("_", "-");
        }
        return className;
    }
}

BST_APIHandler GetBSTAPIHandler() {
    return BST_APIHandler.Cast(GetPlugin(BST_APIHandler));
}