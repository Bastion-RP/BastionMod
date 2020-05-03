class DTACGroupWidget {
    private ref Widget wParent, wHeader, wJoinButton;
    private ref GridSpacerWidget gridRoot;
    private ref TextWidget txtHeader;
    private ref TextWidget txtClicktoJoin;
    private ref DTACGroup group;
    private ref array<ref DTACUserWidget> arrayChildren;

    void DTACGroupWidget(Widget wParent, DTACGroup group) {
        this.wParent = wParent;
        this.group = group;
        arrayChildren = new array<ref DTACUserWidget>();
        gridRoot = GetGame().GetWorkspace().CreateWidgets("BastionMod\\BastionDTAC\\gui\\layouts\\GroupWidget.layout", wParent);;
        wHeader = gridRoot.FindAnyWidget("pnlHeader");
        txtHeader = gridRoot.FindAnyWidget("txtHeader");

        txtHeader.SetText(group.GetName());
        wHeader.SetColor(group.GetColor());
    }

    void ~DTACGroupWidget() {
        if (gridRoot) {
            gridRoot.Unlink();
        }
        if (wHeader) {
            wHeader.Unlink();
        }
        if (txtHeader) {
            txtHeader.Unlink();
        }
        foreach (DTACUserWidget userWidget : arrayChildren) {
            if (userWidget) {
                delete userWidget;
            }
        }
    }
    
    void AddChild(string username) {
        DTACUserWidget newUserWidget = new DTACUserWidget(gridRoot, username);

        arrayChildren.Insert(newUserWidget);
    }

    void CreateJoinButton() {
        gridRoot = GetGame().GetWorkspace().CreateWidgets("BastionMod\\BastionDTAC\\gui\\layouts\\TextWidget.layout", gridRoot);
        txtClicktoJoin = gridRoot.FindAnyWidget("txt");

        txtClicktoJoin.SetText("+ Click to Join");
    }

    void CreateLeaveButton() {
        gridRoot = GetGame().GetWorkspace().CreateWidgets("BastionMod\\BastionDTAC\\gui\\layouts\\TextWidget.layout", gridRoot);
        txtClicktoJoin = gridRoot.FindAnyWidget("txt");

        txtClicktoJoin.SetText("- Click to Leave");
    }

    DTACGroup GetGroup() { return group; }
    TextWidget GetJoinButton() { return txtClicktoJoin; }
}