modded class DayZPlayerImplement {
    override void ShowDeadScreen(bool show, float duration) {
        super.ShowDeadScreen(show, duration);

        if (GetMultiCharactersClientManager() && !GetMultiCharactersClientManager().IsInitialized()) {
            MultiCharactersClientManager.BST_testInvoker.Invoke();
        }
    }
}