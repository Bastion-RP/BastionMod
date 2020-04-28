class DTACServerGroupManager : PluginBase {
    private static const int GROUP_ID_OFFSET = 10000;

    private ref array<ref DTACGroup> arrayGroups;
    private ref DTACGroupConfig groupConfig;

    void DTACServerGroupManager() {
        arrayGroups = new array<ref DTACGroup>();

        if (!FileExist(DTACConst.dtacDir)) {
            MakeDirectory(DTACConst.dtacDir);
        }
        if (FileExist(DTACConst.configDir)) {
            JsonFileLoader<DTACGroupConfig>.JsonLoadFile(DTACConst.configDir, groupConfig);
        } else {
            groupConfig = new DTACGroupConfig();
        }
        groupConfig.Validate();
        CreateGroups();
    }

    void CreateGroups() {
        array<ref DTACGroupConfigObject> arrayConfigGroups = groupConfig.GetGroups();

        for (int i = 0; i < arrayConfigGroups.Count(); i++) {
            DTACGroupConfigObject configGroup = arrayConfigGroups[i];

            if (configGroup) {
                DTACGroup newGroup = new DTACGroup(configGroup.GetName(), configGroup.GetCapacity(), configGroup.GetColor(), (i + GROUP_ID_OFFSET));

                newGroup.Init();
                arrayGroups.Insert(newGroup);
            }
        }
    }

    void DebugMainArray() {
        foreach (DTACGroup group : arrayGroups) {
            if (group) {
                array<ref DTACGroupMember> arrayMembers = group.GetMembers();

                Print("[DEBUG] DTACServerGroupManager | DebugMainArray | Getting group data=" + group.GetName());
                Print("[DEBUG] DTACServerGroupManager | DebugMainArray | Getting group data=" + group.GetCapacity());
                Print("[DEBUG] DTACServerGroupManager | DebugMainArray | Getting group data=" + group.GetColor());

                foreach (DTACGroupMember member : arrayMembers) {
                    if (member) {
                        Print("[DEBUG] DTACServerGroupManager | DebugMainArray | Getting player data=" + member.GetPlayerData());
                        Print("[DEBUG] DTACServerGroupManager | DebugMainArray | Getting player name=" + member.GetPlayerData().GetName());
                        Print("[DEBUG] DTACServerGroupManager | DebugMainArray | Getting player id=" + member.GetPlayerData().GetId());
                        Print("[DEBUG] DTACServerGroupManager | DebugMainArray | Getting player position=" + member.GetPlayerData().GetPosition());
                        Print("[DEBUG] DTACServerGroupManager | DebugMainArray | Getting player health=" + member.GetPlayerData().GetHealth());
                        Print("[DEBUG] DTACServerGroupManager | DebugMainArray | Getting player blood=" + member.GetPlayerData().GetBlood());
                        Print("[DEBUG] DTACServerGroupManager | DebugMainArray | Getting player water=" + member.GetPlayerData().GetWater());
                        Print("[DEBUG] DTACServerGroupManager | DebugMainArray | Getting player food=" + member.GetPlayerData().GetFood());
                    }
                }
            }
        }
    }

    void AddUserToGroup(PlayerBase player, int groupId) {
        if (!HasDTAC(player)) { return; }
        DTACGroup group = GetGroupById(groupId);

        Print("DTACServerGroupManager | AddUserToGroup | Adding user to group id=" + groupId + " | group=" + group);

        if (group && !group.IsCapped() && !group.GetMember(player.GetIdentity().GetId())) {
            Param params = new Param2<ref DTACGroup, array<ref DTACGroup>>(group, arrayGroups);

            group.AddMember(player);
            GetGame().RPCSingleParam(player, DTACRPC.CLIENT_RECEIVE_ACTIVE_GROUP, params, true, player.GetIdentity());
        }
    }

    void RemoveUserFromGroup(PlayerBase player) {
        GetDTACGroupManager().dtacRemovalInvoker.Invoke(player.GetIdentity().GetId());

        GetGame().RPCSingleParam(player, DTACRPC.CLIENT_LEAVE_GROUP, null, true, player.GetIdentity());
    }

    bool HasDTAC(Man player) {
		array<EntityAI> arrayInventory = new array<EntityAI>();

		player.GetHumanInventory().EnumerateInventory(InventoryTraversalType.PREORDER, arrayInventory);
        
        foreach (EntityAI entity : arrayInventory) {
            if (entity) {
                string entityType = entity.GetType();

                entityType.ToLower();

                if (entityType == "bastionrp_phone") {
                    return true;
                }
            }
        }
        return false;
    }

    DTACGroup GetGroupById(int groupId) {
        foreach (DTACGroup group : arrayGroups) {
            if (group && group.GetId() == groupId) {
                return group;
            }
        }
        return null;
    }

    array<ref DTACGroup> GetGroups() { return arrayGroups; }
    DTACGroupConfig GetConfig() { return groupConfig; }
}

DTACServerGroupManager GetDTACServerGroupManager() {
    return DTACServerGroupManager.Cast(GetPlugin(DTACServerGroupManager));
}