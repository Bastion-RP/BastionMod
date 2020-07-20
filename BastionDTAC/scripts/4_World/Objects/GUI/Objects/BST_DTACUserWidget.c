class BST_DTACUserWidget {
    private ref Widget wRoot, wParent;
    private ref TextWidget txtUsername;

    void BST_DTACUserWidget(Widget wParent, string username) {
        this.wParent = wParent;
        wRoot = GetGame().GetWorkspace().CreateWidgets("BastionMod\\BastionDTAC\\gui\\layouts\\UserWidget.layout", wParent);
        txtUsername = TextWidget.Cast(wRoot.FindAnyWidget("txtUsername"));

        txtUsername.SetText(username);
    }

    void ~BST_DTACUserWidget() {
        if (wRoot) {
            wRoot.Unlink();
        }
        if (txtUsername) {
            txtUsername.Unlink();
        }
    }
}