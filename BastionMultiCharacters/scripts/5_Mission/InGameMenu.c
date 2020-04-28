modded class InGameMenu {
    override void OnShow() {
        super.OnShow();

        if (GetMultiCharactersClientManager()) {
            Print(MCConst.debugPrefix + "InGameMenu | OnShow | Showing menu!");
            Print(MCConst.debugPrefix + "InGameMenu | OnShow | isInitializing=" + GetMultiCharactersClientManager().IsInitialized());
            if (!GetMultiCharactersClientManager().IsInitialized()) {
                Print(MCConst.debugPrefix + "InGameMenu | OnShow | Respawning!");
                GameRespawn();
                GetMultiCharactersClientManager().SetInitialized(true);
            }
        }
    }
}