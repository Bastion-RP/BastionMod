modded class MissionGameplay {
    void MissionGameplay() {
        BST_MCClientManager._initInvoker.Insert(MCRespawnPlayer);
        GetBSTMCClientManager().Init();
    }

    void MCRespawnPlayer() {
        if (GetBSTMCClientManager() && !GetBSTMCClientManager().IsInitialized()) {
                GetBSTMCClientManager().SetInitialized(true);
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

    void ~MissionGameplay() {
        BST_MCClientManager._initInvoker.Remove(MCRespawnPlayer);
    }
}