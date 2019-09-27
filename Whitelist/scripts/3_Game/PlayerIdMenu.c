class PlayerIdMenu
{
	Widget m_Root;
    TextWidget txtPlayerId;
    int screenW, screenH;
    float x, y, w, h;
	void PlayerIdMenu(string playerId) {
        Print(m_DebugPrefix + "Creating UI to show playerId");

        m_Root = GetGame().GetWorkspace().CreateWidgets("BSTWhitelist\\scripts\\layouts\\PlayerId.layout");
        txtPlayerId = TextWidget.Cast(m_Root.FindAnyWidget("BSTPlayerId"));
        txtPlayerId.SetText(playerId);
    }
}