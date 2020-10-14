modded class DayZPlayerImplement {
    override void ShowDeadScreen(bool show, float duration) {
        super.ShowDeadScreen(show, duration);

        if (GetBSTMCClientManager() && !GetBSTMCClientManager().IsInitialized()) {
            BST_MCClientManager._initInvoker.Invoke();
        }
    }
}