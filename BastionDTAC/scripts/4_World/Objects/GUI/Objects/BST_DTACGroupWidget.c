class BST_DTACGroupWidget {
    private ref Widget wParent, wHeader, wJoinButton;
    private ref GridSpacerWidget gridRoot;
    private ref TextWidget txtHeader;
    private ref TextWidget txtClicktoJoin;
    private ref BST_DTACGroup group;
    private ref array<ref BST_DTACUserWidget> arrayChildren;

    void BST_DTACGroupWidget(Widget wParent, BST_DTACGroup group) {
        this.wParent = wParent;
        this.group = group;
        arrayChildren = new array<ref BST_DTACUserWidget>();
        gridRoot = GridSpacerWidget.Cast(GetGame().GetWorkspace().CreateWidgets("BastionMod\\BastionDTAC\\gui\\layouts\\GroupWidget.layout", wParent));
        wHeader = gridRoot.FindAnyWidget("pnlHeader");
        txtHeader = TextWidget.Cast(gridRoot.FindAnyWidget("txtHeader"));

        txtHeader.SetText(group.GetName());
        wHeader.SetColor(group.GetColor());
    }

    void ~BST_DTACGroupWidget() {
        if (gridRoot) {
            gridRoot.Unlink();
        }
        if (wHeader) {
            wHeader.Unlink();
        }
        if (txtHeader) {
            txtHeader.Unlink();
        }
        foreach (BST_DTACUserWidget userWidget : arrayChildren) {
            if (userWidget) {
                delete userWidget;
            }
        }
    }
    
    void AddChild(string username) {
        BST_DTACUserWidget newUserWidget = new BST_DTACUserWidget(gridRoot, username);

        arrayChildren.Insert(newUserWidget);
    }

    void CreateButton(int type) {
        Widget joinBtn = GetGame().GetWorkspace().CreateWidgets("BastionMod\\BastionDTAC\\gui\\layouts\\TextWidget.layout", gridRoot);
        txtClicktoJoin = TextWidget.Cast(gridRoot.FindAnyWidget("txt"));

        switch (type) {
            case 0:
                {
                    txtClicktoJoin.SetText("+ Click to Join");
                    break;
                }
            case 1:
                {
                    txtClicktoJoin.SetText("- Click to Leave");
                    break;
                }
        }
    }

    BST_DTACGroup GetGroup() { return group; }
    TextWidget GetJoinButton() { return txtClicktoJoin; }
}