class BST_DTACGroup {
    protected ref array<ref BST_DTACGroupMember> arrayMembers;
    protected string groupName;
    protected int groupCapactity, groupColor, groupId;
    
    void BST_DTACGroup(string groupName, int groupCapactity, int groupColor, int groupId) {
        this.arrayMembers = new array<ref BST_DTACGroupMember>();
        this.groupName = groupName;
        this.groupCapactity = groupCapactity;
        this.groupColor = groupColor;
        this.groupId = groupId;
    }

    void ~BST_DTACGroup() {
        foreach (BST_DTACGroupMember memberBase : arrayMembers) {
            if (memberBase) {
                delete memberBase;
            }
        }
    }

    void Init() {
        if (GetGame().IsServer() && GetGame().IsMultiplayer()) {
            GetDTACGroupManager().dtacStatInvoker.Insert(CheckRPC);
            GetDTACGroupManager().dtacRemovalInvoker.Insert(RemoveMember);
        } else {
            foreach (BST_DTACGroupMember member : arrayMembers) {
                if (member) {
                    member.Init();
                }
            }
        }
    }

    void AddMember(PlayerBase player) {
        BST_DTACGroupMember member = GetMember(player.GetIdentity().GetId());

        if (!member) {
            BST_DTACPlayerData playerData;
            array<ref Param> rpcParams;
            Param1<ref BST_DTACPlayerData> param;

            playerData = new BST_DTACPlayerData();
            rpcParams = new array<ref Param>();

            playerData.SetName(player.GetMultiCharactersPlayerName());
            playerData.SetId(player.GetIdentity().GetId());
            playerData.SetPosition(player.GetPosition());
            playerData.SetHealth(player.GetHealth("", "Health"));
            playerData.SetBlood(player.GetHealth("", "Blood"));
            playerData.SetWater(player.GetStatWater().Get());
            playerData.SetFood(player.GetStatEnergy().Get());

            member = new BST_DTACGroupMember(playerData);
            param = new Param1<ref BST_DTACPlayerData>(playerData);
            
            member.SetPlayer(player);
            member.Init();
            rpcParams.Insert(param);
            SendRPC(BST_DTACRPC.CLIENT_ADD_GROUP_MEMBER, rpcParams);
            arrayMembers.Insert(member);
            arrayMembers.Debug();
        }
    }

    // CLIENT ONLY
    void AddMember(BST_DTACPlayerData playerData) {
        if (playerData && !GetMember(playerData.GetId())) {
            BST_DTACGroupMember newMember = new BST_DTACGroupMember(playerData);

            if (GetDTACClientGroupManager()) {
                GetDTACClientGroupManager().GetHUD().AddTracker(newMember);
            }
            newMember.Init();
            arrayMembers.Insert(newMember);
            arrayMembers.Debug();
        }
    }

    // CLIENT ONLY
    void UpdateMember(BST_DTACPlayerData playerData) {
        BST_DTACGroupMember member = GetMember(playerData.GetId());

        if (member) {
            member.GetPlayerData().SetHealth(playerData.GetHealth());
            member.GetPlayerData().SetBlood(playerData.GetBlood());
            member.GetPlayerData().SetWater(playerData.GetWater());
            member.GetPlayerData().SetFood(playerData.GetFood());
            member.GetPlayerData().SetPosition(playerData.GetPosition());
        }
    }

    void RemoveMember(string id) {
        BST_DTACGroupMember member = GetMember(id);

        if (member) {
            if (GetGame().IsServer() && GetGame().IsMultiplayer()) {
                array<ref Param> rpcParams = new array<ref Param>();
                Param param = new Param1<string>(id);

                rpcParams.Insert(param);
                SendRPC(BST_DTACRPC.CLIENT_REMOVE_GROUP_MEMBER, rpcParams);
            } else {
                if (GetDTACClientGroupManager()) {
                    GetDTACClientGroupManager().GetHUD().RemoveTracker(id);
                }
            }
            arrayMembers.RemoveItem(member);
        }
    }

    // SERVER ONLY
    void CheckRPC(string uid, int rpcType, array<ref Param> rpcParams) {
        if (GetMember(uid)) {
            SendRPC(rpcType, rpcParams);
        }
    }

    // SERVER ONLY
    void SendRPC(int rpcType, array<ref Param> rpcParams) {
        foreach (BST_DTACGroupMember member : arrayMembers) {
            if (member && member.GetPlayer() && member.GetPlayer().GetIdentity()) {
                GetGame().RPC(member.GetPlayer(), rpcType, rpcParams, true, member.GetPlayer().GetIdentity());
            }
        }
    }

    BST_DTACGroupMember GetMember(string uid) {
        foreach (BST_DTACGroupMember member : arrayMembers) {
            if (member.GetPlayerData().GetId() == uid) {
                return member;
            }
        }
        return null;
    }

    bool IsCapped() {
        if (arrayMembers.Count() >= groupCapactity) {
            return true;
        }
        return false;
    }
    string GetName() { return groupName; }
    int GetId() { return groupId; }
    int GetCapacity() { return groupCapactity; }
    int GetColor() { return groupColor; }
    array<ref BST_DTACGroupMember> GetMembers() { return arrayMembers; }
}