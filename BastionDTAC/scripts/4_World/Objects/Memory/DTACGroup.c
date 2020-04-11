class DTACGroup {
    protected ref array<ref DTACGroupMember> arrayMembers;
    protected string groupName;
    protected int groupCapactity, groupColor, groupId;
    
    void DTACGroup(string groupName, int groupCapactity, int groupColor, int groupId) {
        this.arrayMembers = new array<ref DTACGroupMember>();
        this.groupName = groupName;
        this.groupCapactity = groupCapactity;
        this.groupColor = groupColor;
        this.groupId = groupId;
    }

    void ~DTACGroup() {
        foreach (DTACGroupMember memberBase : arrayMembers) {
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
            Print("[DEBUG] DTACGroup | Init | Initializing existing members");
            DebugMembers();
            foreach (DTACGroupMember member : arrayMembers) {
                Print("looping " + member);
                if (member) {
                    Print("member exists");
                    member.Init();
                }
            }
        }
    }

    void AddMember(PlayerBase player) {
        DTACGroupMember member = GetMember(player.GetIdentity().GetId());

        if (!member) {
            DTACPlayerData playerData;
            array<ref Param> rpcParams;
            Param1<ref DTACPlayerData> param;

            playerData = new DTACPlayerData();
            rpcParams = new array<ref Param>();

            playerData.SetName(player.GetIdentity().GetName());
            playerData.SetId(player.GetIdentity().GetId());
            playerData.SetPosition(player.GetPosition());
            playerData.SetHealth(player.GetHealth("", "Health"));
            playerData.SetBlood(player.GetHealth("", "Blood"));
            playerData.SetWater(player.GetStatWater().Get());
            playerData.SetFood(player.GetStatEnergy().Get());

            member = new DTACGroupMember(playerData);
            param = new Param1<ref DTACPlayerData>(playerData);
            
            member.SetPlayer(player);
            member.Init();
            rpcParams.Insert(param);
            SendRPC(DTACRPC.CLIENT_ADD_GROUP_MEMBER, rpcParams);
            arrayMembers.Insert(member);
            arrayMembers.Debug();
        }
    }

    // CLIENT ONLY
    void AddMember(DTACPlayerData playerData) {
        if (playerData && !GetMember(playerData.GetId())) {
            DTACGroupMember newMember = new DTACGroupMember(playerData);

            if (GetDTACClientGroupManager()) {
                GetDTACClientGroupManager().GetHUD().AddTracker(newMember);
            }
            newMember.Init();
            arrayMembers.Insert(newMember);
            arrayMembers.Debug();
        }
    }

    // CLIENT ONLY
    void UpdateMember(DTACPlayerData playerData) {
        DTACGroupMember member = GetMember(playerData.GetId());

        if (member) {
            member.GetPlayerData().SetHealth(playerData.GetHealth());
            member.GetPlayerData().SetBlood(playerData.GetBlood());
            member.GetPlayerData().SetWater(playerData.GetWater());
            member.GetPlayerData().SetFood(playerData.GetFood());
            member.GetPlayerData().SetPosition(playerData.GetPosition());
        }
    }

    void RemoveMember(string id) {
        Print("[DEBUG] DTACGroup | RemoveMember | Removing member by ID..." + id);
        DTACGroupMember member = GetMember(id);

        if (member) {
            if (GetGame().IsServer() && GetGame().IsMultiplayer()) {
                array<ref Param> rpcParams = new array<ref Param>();
                Param param = new Param1<string>(id);

                rpcParams.Insert(param);
                SendRPC(DTACRPC.CLIENT_REMOVE_GROUP_MEMBER, rpcParams);
            } else {
                Print("[DEBUG] DTACGroup | RemoveMember | Removing...");
                if (GetDTACClientGroupManager()) {
                    GetDTACClientGroupManager().GetHUD().RemoveTracker(id);
                }
                Print("[DEBUG] DTACGroup | RemoveMember | Removed...");
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
        Print("[DEBUG] DTACGroup | SendRPC | Sending RPC=" + typename.EnumToString(DTACRPC, rpcType) + " | data=" + rpcParams);
        foreach (DTACGroupMember member : arrayMembers) {
            if (member && member.GetPlayer() && member.GetPlayer().GetIdentity()) {
                Print("[DEBUG] DTACGroup | SendRPC | Sending RPC to " + member.GetPlayerData().GetName());
                GetGame().RPC(member.GetPlayer(), rpcType, rpcParams, true, member.GetPlayer().GetIdentity());
            }
        }
    }

    void DebugMembers() {
        Print("[DEBUG] DTACGroup | DebugMembers | Debugging member array");
        foreach (DTACGroupMember member : arrayMembers) {
            if (member) {
                Print("[DEBUG] DTACGroup | DebugMembers | Getting player data=" + member.GetPlayerData());
                Print("[DEBUG] DTACGroup | DebugMembers | Getting player name=" + member.GetPlayerData().GetName());
                Print("[DEBUG] DTACGroup | DebugMembers | Getting player id=" + member.GetPlayerData().GetId());
                Print("[DEBUG] DTACGroup | DebugMembers | Getting player position=" + member.GetPlayerData().GetPosition());
                Print("[DEBUG] DTACGroup | DebugMembers | Getting player health=" + member.GetPlayerData().GetHealth());
                Print("[DEBUG] DTACGroup | DebugMembers | Getting player blood=" + member.GetPlayerData().GetBlood());
                Print("[DEBUG] DTACGroup | DebugMembers | Getting player water=" + member.GetPlayerData().GetWater());
                Print("[DEBUG] DTACGroup | DebugMembers | Getting player food=" + member.GetPlayerData().GetFood());
            }
        }
    }

    DTACGroupMember GetMember(string uid) {
        foreach (DTACGroupMember member : arrayMembers) {
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
    array<ref DTACGroupMember> GetMembers() { return arrayMembers; }
}