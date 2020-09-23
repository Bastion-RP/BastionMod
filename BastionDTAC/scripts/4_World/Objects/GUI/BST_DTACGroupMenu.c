class BST_DTACGroupMenu : BST_ScriptedWidget {
    private ref ScrollWidget _scroller;
    private ref GridSpacerWidget _rootGrid;
    private ref array<ref BST_DTACGroupWidget> _arrGroupWidgets;

    void BST_DTACGroupMenu() {
        _arrGroupWidgets = new array<ref BST_DTACGroupWidget>();
        _btnText = "DTAC GROUPS";

        GetDTACClientGroupManager().groupInvoker.Insert(BuildUI);
    }

    void ~BST_DTACGroupMenu() {
        DeleteMenu();
        if (_rootGrid) {
            _rootGrid.Unlink();
        }
        if (_root) {
            _root.Unlink();
        }
        if (_scroller) {
            _scroller.Unlink();
        }
    }

    override void Init(Widget parent) {
        _parent = parent;
        _root = GetGame().GetWorkspace().CreateWidgets("BastionMod\\BastionDTAC\\gui\\layouts\\GroupMenu.layout", _parent);
        _scroller = ScrollWidget.Cast(_root.FindAnyWidget("scroller"));
        _rootGrid = GridSpacerWidget.Cast(_root.FindAnyWidget("rootGrid"));

        _root.SetHandler(this);
    }

    override bool OnMouseButtonUp(Widget w, int x, int y, int button) {
        if (!w || GetDTACClientGroupManager().IsRateLimited()) { return false; }
        BST_DTACGroupWidget groupWidget;

        w.GetUserData(groupWidget);
        
        if (groupWidget) {
            if (GetDTACClientGroupManager().GetActiveGroup() && GetDTACClientGroupManager().GetActiveGroup().GetId() == groupWidget.GetGroup().GetId()) {
                GetGame().RPCSingleParam(GetGame().GetPlayer(), BST_DTACRPC.SERVER_LEAVE_GROUP, null, true);
            } else {
                Param params = new Param1<int>(groupWidget.GetGroup().GetId());

                GetGame().RPCSingleParam(GetGame().GetPlayer(), BST_DTACRPC.SERVER_JOIN_GROUP, params, true);
            }
            GetDTACClientGroupManager().SetRateLimited();
        }
        return true;
    }

    override bool OnMouseEnter(Widget w, int x, int y) {
        if (TextWidget.Cast(w)) {
            foreach (BST_DTACGroupWidget groupWidget : _arrGroupWidgets) {
                if (groupWidget && groupWidget.GetJoinButton() && groupWidget.GetJoinButton() == w) {
                    TextWidget.Cast(w).SetColor(ARGB(255, 200, 200, 200));
                }
            }
        }
        return true;
    }

    override bool OnMouseLeave(Widget w, Widget enterW, int x, int y) {
        if (TextWidget.Cast(w)) {
            foreach (BST_DTACGroupWidget groupWidget : _arrGroupWidgets) {
                if (groupWidget && groupWidget.GetJoinButton() && groupWidget.GetJoinButton() == w) {
                    TextWidget.Cast(w).SetColor(ARGB(255, 255, 255, 255));
                }
            }
        }
        return true;
    }

    void BuildUI() {
        if (!_root.IsVisible()) { return; }
        DeleteMenu();
        
        ref array<ref BST_DTACGroup> arrayGroups = GetDTACClientGroupManager().GetGroups();
        arrayGroups.Debug();

        foreach (BST_DTACGroup group : arrayGroups) {
            if (!group) { continue; }
            BST_DTACGroupWidget groupWidget = new BST_DTACGroupWidget(_rootGrid, group);
            array<ref BST_DTACGroupMember> arrayMembers;

            if (GetDTACClientGroupManager().GetActiveGroup() && GetDTACClientGroupManager().GetActiveGroup().GetId() == group.GetId()) {
                arrayMembers = GetDTACClientGroupManager().GetActiveGroup().GetMembers();
            } else {
                arrayMembers = group.GetMembers();
            }
            foreach (BST_DTACGroupMember member : arrayMembers) {
                if (member) {
                    groupWidget.AddChild(member.GetPlayerData().GetName());
                }
            }
            if (!GetDTACClientGroupManager().GetActiveGroup() || GetDTACClientGroupManager().GetActiveGroup().GetId() != group.GetId()) {
                groupWidget.CreateButton(0);
            } else {
                groupWidget.CreateButton(1);
            }
            groupWidget.GetJoinButton().SetUserData(groupWidget);
            _arrGroupWidgets.Insert(groupWidget);
        }
    }

    void DeleteMenu() {
        foreach (BST_DTACGroupWidget groupWidget : _arrGroupWidgets) {
            if (groupWidget) {
                delete groupWidget;
            }
        }
        delete _arrGroupWidgets;
        _arrGroupWidgets = new array<ref BST_DTACGroupWidget>();
    }

    override void OnShow() {
        super.OnShow();

        if (!GetDTACClientGroupManager().IsUpdateRateLimited()) {
            GetGame().RPCSingleParam(GetGame().GetPlayer(), BST_DTACRPC.SERVER_SEND_GROUP_ARRAY, null, true);
            GetDTACClientGroupManager().SetUpdateRateLimited();
        } else {
            BuildUI();
        }
    }
}