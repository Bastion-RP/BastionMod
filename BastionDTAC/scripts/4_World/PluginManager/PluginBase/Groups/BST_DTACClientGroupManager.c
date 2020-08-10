class BST_DTACClientGroupManager : PluginBase {
    private ref array<ref BST_DTACGroup> arrayGroups;
    private ref BST_DTACGroup activeGroup;
    private ref BST_DTACHUD hud;
    private ref BST_CompassHUD compassHUD;
    static ref ScriptInvoker groupInvoker, statUpdateInvoker, playerUpdateInvoker;
    private bool isRateLimited, isUpdateRateLimited;

    void BST_DTACClientGroupManager() {
        arrayGroups = new array<ref BST_DTACGroup>();
        groupInvoker = new ScriptInvoker();
        statUpdateInvoker = new ScriptInvoker();
        playerUpdateInvoker = new ScriptInvoker();
    }

    void Init() {
        delete arrayGroups;
        delete activeGroup;
        delete hud;
        
        arrayGroups = new array<ref BST_DTACGroup>();
    }

    void InitCompassHUD() {
        DeleteCompassHUD();
        compassHUD = new BST_CompassHUD();
    }

    void DeleteCompassHUD() {
        if (compassHUD) {
            delete compassHUD;
        }
    }

    void InitActiveGroup() {
        delete activeGroup;
        delete hud;
    }

    void ReceiveActiveGroup(ref BST_DTACGroup activeGroup, ref array<ref BST_DTACGroup> arrayGroups) {
        if (this.arrayGroups || this.activeGroup || this.hud) {
            Init();
        }
        this.arrayGroups = arrayGroups;
        this.activeGroup = activeGroup;
        this.activeGroup.Init();
        groupInvoker.Invoke();

        // Create new HUD
        this.hud = new BST_DTACHUD();
    }

    void ReceiveGroupArray(ref array<ref BST_DTACGroup> arrayGroups) {
        this.arrayGroups = arrayGroups;
        groupInvoker.Invoke();
    }

    void UpdateGroupMember(ref BST_DTACPlayerData playerData) {
        if (activeGroup) {
            activeGroup.UpdateMember(playerData);
            statUpdateInvoker.Invoke(playerData.GetId());
        }
    }

    void AddGroupMember(ref BST_DTACPlayerData playerData) {
        if (activeGroup) {
            activeGroup.AddMember(playerData);
            groupInvoker.Invoke();
        }
    }

    void RemoveGroupMember(string uid) {
        if (activeGroup) {
            activeGroup.RemoveMember(uid);
            groupInvoker.Invoke();
        }
    }

    void SetRateLimited() {
        if (isRateLimited) { return; }
        isRateLimited = true;
        
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(this.RemoveRateLimit, 20000);
    }

    void SetUpdateRateLimited() {
        if (isUpdateRateLimited) { return; }
        isUpdateRateLimited = true;
        
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(this.RemoveUpdateRateLimit, 20000);
    }

    void RemoveRateLimit() { isRateLimited = false; }
    void RemoveUpdateRateLimit() { isUpdateRateLimited = false; }

    BST_DTACGroup GetGroupById(int groupId) {
        foreach (BST_DTACGroup group : arrayGroups) {
            if (group && group.GetId() == groupId) {
                return group;
            }
        }
        return null;
    }
    
    ref array<ref BST_DTACGroup> GetGroups() { return arrayGroups; }
    BST_CompassHUD GetCompassHUD() { return compassHUD; }
    BST_DTACGroup GetActiveGroup() { return activeGroup; }
    BST_DTACHUD GetHUD() { return hud; }
    bool IsRateLimited() { return isRateLimited; }
    bool IsUpdateRateLimited() { return isUpdateRateLimited; }
}

BST_DTACClientGroupManager GetDTACClientGroupManager() {
    return BST_DTACClientGroupManager.Cast(GetPlugin(BST_DTACClientGroupManager));
}