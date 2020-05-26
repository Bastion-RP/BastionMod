modded class ActionConstructor {
    void RegisterActions(TTypenameArray actions) {
        super.RegisterActions(actions);

        actions.Insert(BST_ActionUseBench);
    }
}