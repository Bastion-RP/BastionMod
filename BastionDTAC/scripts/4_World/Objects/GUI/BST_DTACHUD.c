class BST_DTACHUD {
    private ref Widget wRoot;
    private ref GridSpacerWidget gridRoot;
    private ref array<ref BST_DTACTracker> arrayTrackers;

    void BST_DTACHUD() {
        wRoot = GetGame().GetWorkspace().CreateWidgets("BastionMod\\BastionDTAC\\gui\\layouts\\HUD.layout");
        gridRoot = GridSpacerWidget.Cast(wRoot.FindAnyWidget("rootGrid"));
        
        wRoot.SetSort(-9999);
        Init();
    }

    void ~BST_DTACHUD() {
        foreach (BST_DTACTracker tracker : arrayTrackers) {
            if (tracker) {
                delete tracker;
            }
        }
        if (gridRoot) {
            gridRoot.Unlink();
        }
    }

    void Init() {
        if (arrayTrackers) {
            delete arrayTrackers;
        }
        int i;
        array<ref BST_DTACGroupMember> arrayMembers = GetDTACClientGroupManager().GetActiveGroup().GetMembers();
        arrayTrackers = new array<ref BST_DTACTracker>();

        foreach (BST_DTACGroupMember member : arrayMembers) {
            if (i >= 6) { break; }
            if (member) {
                AddTracker(member);
                i++;
            }
        }
    }

    void AddTracker(BST_DTACGroupMember groupMember) {
        if (groupMember.GetPlayerData().GetId() == GetGame().GetPlayer().GetIdentity().GetId()) { return; }
        BST_DTACTracker newTracker = new BST_DTACTracker(groupMember, wRoot, gridRoot);

        arrayTrackers.Insert(newTracker);
    }

    void RemoveTracker(string id) {
        foreach(BST_DTACTracker tracker : arrayTrackers) {
            if (tracker && tracker.GetPlayerData() && tracker.GetPlayerData().GetId() == id) {
                arrayTrackers.RemoveItem(tracker);
            } 
        }
    }
}