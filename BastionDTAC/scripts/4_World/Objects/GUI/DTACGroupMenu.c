class DTACGroupMenu : UIScriptedMenu {
    private ref Widget wRoot;
    private ref ScrollWidget scroller;
    private ref GridSpacerWidget rootGrid;
    private ref array<ref DTACGroupWidget> arrayGroupWidgets;

    void DTACGroupMenu() {
        arrayGroupWidgets = new array<ref DTACGroupWidget>();

        GetDTACClientGroupManager().groupInvoker.Insert(BuildUI);
    }

    void ~DTACGroupMenu() {
        DeleteMenu();
    }

    override Widget Init() {
        wRoot = GetGame().GetWorkspace().CreateWidgets("BastionDTAC\\gui\\layouts\\GroupMenu.layout");
        scroller = ScrollWidget.Cast(wRoot.FindAnyWidget("scroller"));
        rootGrid = GridSpacerWidget.Cast(wRoot.FindAnyWidget("rootGrid"));

        return wRoot;
    }

    override bool OnMouseButtonUp(Widget w, int x, int y, int button) {
        Print("[DEBUG] DTACGroupMenu | OnMouseButtonUp | " + GetDTACClientGroupManager().IsRateLimited());
        if (TextWidget.Cast(w) && !GetDTACClientGroupManager().IsRateLimited()) {
            Print("[DEBUG] DTACGroupMenu | OnMouseButtonUp | Is text widget");
            foreach (DTACGroupWidget groupWidget : arrayGroupWidgets) {
                Print("[DEBUG] DTACGroupMenu | OnMouseButtonUp | searching for text widget..." + groupWidget.GetJoinButton() + " | w=" + w);
                if (groupWidget && groupWidget.GetJoinButton() && groupWidget.GetJoinButton() == w) {
                    Print("[DEBUG] DTACGroupMenu | OnMouseButtonUp | Is group widget and join button is w");
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
        return true;
    }

    override bool OnMouseEnter(Widget w, int x, int y) {
        if (TextWidget.Cast(w)) {
            foreach (DTACGroupWidget groupWidget : arrayGroupWidgets) {
                if (groupWidget && groupWidget.GetJoinButton() && groupWidget.GetJoinButton() == w) {
                    TextWidget.Cast(w).SetColor(ARGB(255, 200, 200, 200));
                }
            }
        }
        return true;
    }

    override bool OnMouseLeave(Widget w, Widget enterW, int x, int y) {
        if (TextWidget.Cast(w)) {
            foreach (DTACGroupWidget groupWidget : arrayGroupWidgets) {
                if (groupWidget && groupWidget.GetJoinButton() && groupWidget.GetJoinButton() == w) {
                    TextWidget.Cast(w).SetColor(ARGB(255, 255, 255, 255));
                }
            }
        }
        return true;
    }

    void BuildUI() {
        Print("[DEBUG] DTACGroupMenu | DTACGroupMenu | Call to build UI");
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

    override void OnShow() {
        super.OnShow();
        Print("[DEBUG] DTACGroupMenu | OnShow | Sending RPC");
        if (!GetDTACClientGroupManager().IsUpdateRateLimited()) {
            GetGame().RPCSingleParam(GetGame().GetPlayer(), DTACRPC.SERVER_SEND_GROUP_ARRAY, null, true);
            GetDTACClientGroupManager().SetUpdateRateLimited();
        } else {
            BuildUI();
        }
        GetGame().GetMission().PlayerControlDisable(INPUT_EXCLUDE_ALL);
        GetGame().GetUIManager().ShowCursor(true);
        GetGame().GetMission().GetHud().Show(false);
    }

    override void OnHide() {
        super.OnHide();

        GetGame().GetUIManager().ShowCursor(false);
        GetGame().GetMission().PlayerControlEnable(true);
        GetGame().GetMission().GetHud().Show(true);
    }
}