class DTACClientGroupManager : PluginBase {
    private ref array<ref DTACGroup> arrayGroups;
    private ref DTACGroup activeGroup;
    private ref DTACHUD hud;
    static ref ScriptInvoker groupInvoker, statUpdateInvoker, playerUpdateInvoker;
    private bool isRateLimited, isUpdateRateLimited;

    void DTACClientGroupManager() {
        arrayGroups = new array<ref DTACGroup>();
        groupInvoker = new ScriptInvoker();
        statUpdateInvoker = new ScriptInvoker();
        playerUpdateInvoker = new ScriptInvoker();
    }

    void Init() {
        delete arrayGroups;
        delete activeGroup;
        delete hud;
        
        arrayGroups = new array<ref DTACGroup>();
    }

    void InitActiveGroup() {
        delete activeGroup;
        delete hud;
    }

    void ReceiveActiveGroup(ref DTACGroup activeGroup, ref array<ref DTACGroup> arrayGroups) {
        Print("[DEBUG] DTACClientGroupManager | ReceiveActiveGroup | Setting active group");
        if (this.arrayGroups || this.activeGroup || this.hud) {
            Init();
        }
        this.arrayGroups = arrayGroups;
        this.activeGroup = activeGroup;
        this.activeGroup.Init();
        this.activeGroup.DebugMembers();
        groupInvoker.Invoke();

        // Create new HUD
        this.hud = new DTACHUD();
    }

    void ReceiveGroupArray(ref array<ref DTACGroup> arrayGroups) {
        Print("[DEBUG] DTACClientGroupManager | ReceiveGroupArray | Setting group array");
        this.arrayGroups = arrayGroups;
        groupInvoker.Invoke();
    }

    void UpdateGroupMember(ref DTACPlayerData playerData) {
        Print("[DEBUG] DTACClientGroupManager | UpdateGroupMember | Updating group member id=" + playerData.GetId());
        if (activeGroup) {
            Print("[DEBUG] DTACClientGroupManager | UpdateGroupMember | Active group found!");
            activeGroup.UpdateMember(playerData);
            statUpdateInvoker.Invoke(playerData.GetId());
        }
    }

    void AddGroupMember(ref DTACPlayerData playerData) {
        if (activeGroup) {
            activeGroup.AddMember(playerData);
            groupInvoker.Invoke();
        }
    }

    void RemoveGroupMember(string uid) {
        Print("[DEBUG] DTACClientGroupManager | RemoveGroupMember | Removing member from active group id=" + uid);
        if (activeGroup) {
            activeGroup.RemoveMember(uid);
            groupInvoker.Invoke();
        }
    }

    void SetRateLimited() {
        isRateLimited = true;
        
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(this.RemoveRateLimit, 1);
    }

    void SetUpdateRateLimited() {
        isUpdateRateLimited = true;
        
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(this.RemoveUpdateRateLimit, 1);
    }

    void RemoveRateLimit() { isRateLimited = false; }
    void RemoveUpdateRateLimit() { isUpdateRateLimited = false; }

    DTACGroup GetGroupById(int groupId) {
        foreach (DTACGroup group : arrayGroups) {
            if (group && group.GetId() == groupId) {
                return group;
            }
        }
        return null;
    }

    ref array<ref DTACGroup> GetGroups() { return arrayGroups; }
    DTACGroup GetActiveGroup() { return activeGroup; }
    DTACHUD GetHUD() { return hud; }
    bool IsRateLimited() { return isRateLimited; }
    bool IsUpdateRateLimited() { return isUpdateRateLimited; }
}

DTACClientGroupManager GetDTACClientGroupManager() {
    return DTACClientGroupManager.Cast(GetPlugin(DTACClientGroupManager));
}