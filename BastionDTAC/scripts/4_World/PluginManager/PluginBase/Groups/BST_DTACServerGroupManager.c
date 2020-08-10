class BST_DTACServerGroupManager : PluginBase {
    private static const int GROUP_ID_OFFSET = 10000;

    private ref array<ref BST_DTACGroup> arrayGroups;
    private ref BST_DTACGroupConfig groupConfig;

    void BST_DTACServerGroupManager() {
        arrayGroups = new array<ref BST_DTACGroup>();

        if (!FileExist(BST_DTACConst.dtacDir)) {
            MakeDirectory(BST_DTACConst.dtacDir);
        }
        if (FileExist(BST_DTACConst.groupConfigDir)) {
            JsonFileLoader<BST_DTACGroupConfig>.JsonLoadFile(BST_DTACConst.groupConfigDir, groupConfig);
        } else {
            groupConfig = new BST_DTACGroupConfig();
        }
        groupConfig.Validate();
        CreateGroups();
    }

    void CreateGroups() {
        array<ref BST_DTACGroupConfigObject> arrayConfigGroups = groupConfig.GetGroups();

        for (int i = 0; i < arrayConfigGroups.Count(); i++) {
            BST_DTACGroupConfigObject configGroup = arrayConfigGroups[i];

            if (configGroup) {
                BST_DTACGroup newGroup = new BST_DTACGroup(configGroup.GetName(), configGroup.GetCapacity(), configGroup.GetColor(), (i + GROUP_ID_OFFSET));

                newGroup.Init();
                arrayGroups.Insert(newGroup);
            }
        }
    }

    void AddUserToGroup(PlayerBase player, int groupId) {
        if (!GetDTACGroupManager().HasDTAC(player)) { return; }
        BST_DTACGroup group = GetGroupById(groupId);

        if (group && !group.IsCapped() && !group.GetMember(player.GetIdentity().GetId())) {
            Param params = new Param2<ref BST_DTACGroup, array<ref BST_DTACGroup>>(group, arrayGroups);

            group.AddMember(player);
            GetGame().RPCSingleParam(player, BST_DTACRPC.CLIENT_RECEIVE_ACTIVE_GROUP, params, true, player.GetIdentity());
        }
    }

    void RemoveUserFromGroup(PlayerBase player) {
        GetDTACGroupManager().dtacRemovalInvoker.Invoke(player.GetIdentity().GetId());

        GetGame().RPCSingleParam(player, BST_DTACRPC.CLIENT_LEAVE_GROUP, null, true, player.GetIdentity());
    }

    BST_DTACGroup GetGroupById(int groupId) {
        foreach (BST_DTACGroup group : arrayGroups) {
            if (group && group.GetId() == groupId) {
                return group;
            }
        }
        return null;
    }

    array<ref BST_DTACGroup> GetGroups() { return arrayGroups; }
    BST_DTACGroupConfig GetConfig() { return groupConfig; }
}

BST_DTACServerGroupManager GetDTACServerGroupManager() {
    return BST_DTACServerGroupManager.Cast(GetPlugin(BST_DTACServerGroupManager));
}