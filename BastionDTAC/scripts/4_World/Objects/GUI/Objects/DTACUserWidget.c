class DTACUserWidget {
    private ref Widget wRoot, wParent;
    private ref TextWidget txtUsername;

    void DTACUserWidget(Widget wParent, string username) {
        this.wParent = wParent;
        wRoot = GetGame().GetWorkspace().CreateWidgets("BastionDTAC\\gui\\layouts\\UserWidget.layout", wParent);
        txtUsername = TextWidget.Cast(wRoot.FindAnyWidget("txtUsername"));

        txtUsername.SetText(username);
    }

    void ~DTACUserWidget() {
        if (wRoot) {
            wRoot.Unlink();
        }
        if (txtUsername) {
            txtUsername.Unlink();
        }
    }
}