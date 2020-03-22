/* modded class DayZPlayerImplement {
    override void ShowDeadScreen(bool show, float duration) {
        Print(MCConst.debugPrefix + "DayZPlayerImplement | Showing dead screen")
        MultiCharactersMenu menu = MultiCharactersMenu.Cast(GetGame().GetUIManager().GetMenu());
        Print(MCConst.debugPrefix + "DayZPlayerImplement | menu=" + menu);

        if (!menu) {
            Print(MCConst.debugPrefix + "DayZPlayerImplement | Calling super!");
            super.ShowDeadScreen(show, duration);
        } else {
			GetGame().GetUIManager().ScreenFadeOut(0);
        }
    }
} */