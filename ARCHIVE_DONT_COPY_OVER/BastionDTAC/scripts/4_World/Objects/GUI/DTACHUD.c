class DTACHUD {
    private ref Widget wRoot;
    private ref GridSpacerWidget gridRoot;
    private ref array<ref DTACTracker> arrayTrackers;

    void DTACHUD() {
        wRoot = GetGame().GetWorkspace().CreateWidgets("BastionDTAC\\gui\\layouts\\HUD.layout");
        gridRoot = GridSpacerWidget.Cast(wRoot.FindAnyWidget("rootGrid"));
        
        wRoot.SetSort(-9999);
        Init();
    }

    void ~DTACHUD() {
        foreach (DTACTracker tracker : arrayTrackers) {
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
        array<ref DTACGroupMember> arrayMembers = GetDTACClientGroupManager().GetActiveGroup().GetMembers();
        arrayTrackers = new array<ref DTACTracker>();

        foreach (DTACGroupMember member : arrayMembers) {
            if (i >= 6) { break; }
            if (member) {
                AddTracker(member);
                i++;
            }
        }
    }

    void AddTracker(DTACGroupMember groupMember) {
        Print("[DEBUG] DTACHUD | AddTracker | Adding new tracker! data=" + groupMember.GetPlayerData());
        if (groupMember.GetPlayerData().GetId() == GetGame().GetPlayer().GetIdentity().GetId()) { return; }
        DTACTracker newTracker = new DTACTracker(groupMember, wRoot, gridRoot);

        arrayTrackers.Insert(newTracker);
    }

    void RemoveTracker(string id) {
        Print("[DEBUG] DTACHUD | RemoveTracker | Removing tracker by id! id=" + id);
        foreach(DTACTracker tracker : arrayTrackers) {
            if (tracker && tracker.GetPlayerData() && tracker.GetPlayerData().GetId() == id) {
                Print("[DEBUG] DTACHUD | RemoveTracker | Matching tracker found!");
                arrayTrackers.RemoveItem(tracker);
            } 
        }
    }
}