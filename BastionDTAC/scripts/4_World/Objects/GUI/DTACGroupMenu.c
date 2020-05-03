class DTACGroupMenu {
    private ref Widget wRoot, wParent;
    private ref ScrollWidget scroller;
    private ref GridSpacerWidget rootGrid;
    private ref array<ref DTACGroupWidget> arrayGroupWidgets;

    void DTACGroupMenu(Widget wParent) {
        this.wParent = wParent;
        arrayGroupWidgets = new array<ref DTACGroupWidget>();
        wRoot = GetGame().GetWorkspace().CreateWidgets("BastionMod\\BastionDTAC\\gui\\layouts\\GroupMenu.layout", wParent);
        scroller = ScrollWidget.Cast(wRoot.FindAnyWidget("scroller"));
        rootGrid = GridSpacerWidget.Cast(wRoot.FindAnyWidget("rootGrid"));

        GetDTACClientGroupManager().groupInvoker.Insert(BuildUI);
    }

    void ~DTACGroupMenu() {
        DeleteMenu();
        if (rootGrid) {
            rootGrid.Unlink();
        }
        if (wRoot) {
            wRoot.Unlink();
        }
        if (scroller) {
            scroller.Unlink();
        }
    }

    void OnMouseButtonUp(Widget w, int x, int y, int button) {
        if (TextWidget.Cast(w) && !GetDTACClientGroupManager().IsRateLimited()) {
            foreach (DTACGroupWidget groupWidget : arrayGroupWidgets) {
                if (groupWidget && groupWidget.GetJoinButton() && groupWidget.GetJoinButton() == w) {
                    if (GetDTACClientGroupManager().GetActiveGroup() && GetDTACClientGroupManager().GetActiveGroup().GetId() == groupWidget.GetGroup().GetId()) {
                        GetGame().RPCSingleParam(GetGame().GetPlayer(), DTACRPC.SERVER_LEAVE_GROUP, null, true);
                    } else {
                        Param params = new Param1<int>(groupWidget.GetGroup().GetId());

                        GetGame().RPCSingleParam(GetGame().GetPlayer(), DTACRPC.SERVER_JOIN_GROUP, params, true);
                    }
                    GetDTACClientGroupManager().SetRateLimited();
                }
            }
        }
    }

    void OnMouseEnter(Widget w, int x, int y) {
        if (TextWidget.Cast(w)) {
            foreach (DTACGroupWidget groupWidget : arrayGroupWidgets) {
                if (groupWidget && groupWidget.GetJoinButton() && groupWidget.GetJoinButton() == w) {
                    TextWidget.Cast(w).SetColor(ARGB(255, 200, 200, 200));
                }
            }
        }
    }

    void OnMouseLeave(Widget w, Widget enterW, int x, int y) {
        if (TextWidget.Cast(w)) {
            foreach (DTACGroupWidget groupWidget : arrayGroupWidgets) {
                if (groupWidget && groupWidget.GetJoinButton() && groupWidget.GetJoinButton() == w) {
                    TextWidget.Cast(w).SetColor(ARGB(255, 255, 255, 255));
                }
            }
        }
    }

    void BuildUI() {
        Print("[DEBUG] DTACGroupMenu | BuildUI | Call to build UI");
        if (!wRoot.IsVisible()) { return; }
        DeleteMenu();
        
        ref array<ref DTACGroup> arrayGroups = GetDTACClientGroupManager().GetGroups();
        arrayGroups.Debug();

        foreach (DTACGroup group : arrayGroups) {
            if (group) {
                DTACGroupWidget groupWidget = new DTACGroupWidget(rootGrid, group);
                array<ref DTACGroupMember> arrayMembers;

                if (GetDTACClientGroupManager().GetActiveGroup() && GetDTACClientGroupManager().GetActiveGroup().GetId() == group.GetId()) {
                    arrayMembers = GetDTACClientGroupManager().GetActiveGroup().GetMembers();
                } else {
                    arrayMembers = group.GetMembers();
                }
                foreach (DTACGroupMember member : arrayMembers) {
                    if (member) {
                        groupWidget.AddChild(member.GetPlayerData().GetName());
                    }
                }
                if (!GetDTACClientGroupManager().GetActiveGroup() || GetDTACClientGroupManager().GetActiveGroup().GetId() != group.GetId()) {
                    groupWidget.CreateJoinButton();
                } else {
                    groupWidget.CreateLeaveButton();
                }
                arrayGroupWidgets.Insert(groupWidget);
            }
        }
    }

    void DeleteMenu() {
        foreach (DTACGroupWidget groupWidget : arrayGroupWidgets) {
            if (groupWidget) {
                delete groupWidget;
            }
        }
        delete arrayGroupWidgets;
        arrayGroupWidgets = new array<ref DTACGroupWidget>();
    }

    void OnShow() {
        Print("[DEBUG] DTACGroupMenu | OnShow | Sending RPC");
        if (!GetDTACClientGroupManager().IsUpdateRateLimited()) {
            GetGame().RPCSingleParam(GetGame().GetPlayer(), DTACRPC.SERVER_SEND_GROUP_ARRAY, null, true);
            GetDTACClientGroupManager().SetUpdateRateLimited();
        } else {
            BuildUI();
        }
    }
}