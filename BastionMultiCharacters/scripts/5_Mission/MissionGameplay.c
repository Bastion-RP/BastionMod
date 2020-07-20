modded class MissionGameplay {
    void MissionGameplay() {
        Print("[DEBUG] InGameMenu | InGameMenu | Inserting method!");
        MultiCharactersClientManager.BST_testInvoker.Insert(MCRespawnPlayer);
        GetMultiCharactersClientManager().Init();
    }

    void MCRespawnPlayer() {
        Print("[DEBUG] InGameMenu | MCRespawnPlayer | Invoker invoked!");
        if (GetMultiCharactersClientManager() && !GetMultiCharactersClientManager().IsInitialized()) {
                GetMultiCharactersClientManager().SetInitialized(true);
                GetGame().GetCallQueue(CALL_CATEGORY_GUI).Call(GetGame().RespawnPlayer);
                //turns off dead screen, hides HUD for countdown
                //---------------------------------------------------
                PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
                if(player)
                {
                    GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(player.ShowDeadScreen, DayZPlayerImplement.DEAD_SCREEN_DELAY, false, false, 0);
                }
                DestroyAllMenus();
                SetPlayerRespawning(true);
        }
    }
}