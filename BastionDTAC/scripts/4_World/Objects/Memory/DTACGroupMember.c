class DTACGroupMember {
    protected ref DTACPlayerData playerData;
    protected PlayerBase player;
    protected float maxHealth, maxBlood, maxWater, maxFood;

    void DTACGroupMember(DTACPlayerData playerData) {
        this.playerData = playerData;

        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) {
            GetDTACGroupManager().dtacStatInvoker.Insert(StartUpdateLoop);
        }
    }

    void ~DTACGroupMember() {
        if (playerData) {
            delete playerData;
        }
    }

    void StartUpdateLoop() {
        Print("[DEBUG] DTACGroupMember | StartUpdateLoop");
        int updateSens;
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) {
            updateSens = 1000;
        } else {
            updateSens = GetDTACServerGroupManager().GetConfig().GetUpdateInterval() * 1000;
        }
        StopUpdateLoop();
        GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(this.UpdatePlayer, updateSens, true);
    }

    void StartUpdateLoop(string id) {
        if (playerData.GetId() != id) {
            StartUpdateLoop();
        }
    }

    void StopUpdateLoop() {
        Print("[DEBUG] DTACGroupMember | StopUpdateLoop");
        GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).Remove(this.UpdatePlayer);
    }
    
    void Init() {
        Print("[DEBUG] DTACGroupMember | Init | Initializing playerbase loop check");
        GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).Remove(this.UpdatePlayer);

        
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) {
            if (playerData.GetId() != GetGame().GetPlayer().GetIdentity().GetId()) {
                StartUpdateLoop();
            }
        } else {
            if (player) {
                maxHealth = player.GetMaxHealth("", "Health");
                maxBlood = player.GetMaxHealth("", "Blood");
                maxWater = player.GetStatWater().GetMax();
                maxFood = player.GetStatEnergy().GetMax();
            }
            StartUpdateLoop();
        }
    }

    void SetPlayer(PlayerBase player) {
        this.player = player;
    }

    void UpdatePlayer() {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) {
            Print("[DEBUG] DTACGroupMember | UpdatePlayer | Starting update player loop!!!")
            if (!player || !player.IsAlive()) {
                Print("[DEBUG] DTACGroupMember | UpdatePlayer | player is null or dead!!!")
                array<Man> playerList = new array<Man>();
                playerList = ClientData.m_PlayerBaseList;
                
                foreach (Man man : playerList) {
                    if (man) {
                        Print("[DEBUG] DTACGroupMember | UpdatePlayer | man found!!!")
                        PlayerBase searchPlayer = PlayerBase.Cast(man);

                        if (searchPlayer && searchPlayer.IsAlive() && searchPlayer.GetIdentity() && searchPlayer.GetIdentity().GetId() == playerData.GetId()) {
                            Print("[DEBUG] DTACGroupMember | UpdatePlayer | setting player!!!")
                            player = searchPlayer;

                            GetDTACClientGroupManager().playerUpdateInvoker.Invoke();
                            StopUpdateLoop();
                            break;
                        }
                    }
                }
            }
        } else {
            if (player && player.IsAlive()) {
                int updateSens, distanceSens;
                float currHealth, currBlood, currWater, currFood, diffHealth, diffBlood, diffWater, diffFood;

                updateSens = GetDTACServerGroupManager().GetConfig().GetUpdateSensitivity();
                distanceSens = GetDTACServerGroupManager().GetConfig().GetDistanceSensitivity();

                currHealth = player.GetHealth("", "Health");
                currBlood = player.GetHealth("", "Blood");
                currWater = player.GetStatWater().Get();
                currFood = player.GetStatEnergy().Get();
                diffHealth = Math.AbsFloat((((currHealth / maxHealth) * 100) - ((playerData.GetHealth() / maxHealth) * 100)));
                diffBlood = Math.AbsFloat((((currBlood / maxBlood) * 100) - ((playerData.GetBlood() / maxBlood) * 100)));
                diffWater = Math.AbsFloat((((currWater / maxWater) * 100) - ((playerData.GetWater() / maxWater) * 100)));
                diffFood = Math.AbsFloat((((currFood / maxFood) * 100) - ((playerData.GetFood() / maxFood) * 100)));

                if (vector.Distance(player.GetPosition(), playerData.GetPosition()) > distanceSens || diffHealth > updateSens || diffBlood > updateSens || diffWater > updateSens || diffFood > updateSens) {
                    playerData.SetPosition(player.GetPosition());
                    playerData.SetHealth(currHealth);
                    playerData.SetBlood(currBlood);
                    playerData.SetWater(currWater);
                    playerData.SetFood(currFood);

                    auto rpcParams = new array<ref Param>();
                    Param params = new Param1<ref DTACPlayerData>(playerData);

                    rpcParams.Insert(params);
                    GetDTACGroupManager().dtacStatInvoker.Invoke(playerData.GetId(), DTACRPC.CLIENT_RECEIVE_PLAYER_STAT_UPDATE, rpcParams);
                }
            } else {
                GetDTACGroupManager().dtacRemovalInvoker.Invoke(playerData.GetId());
            }
        }
    }

    DTACPlayerData GetPlayerData() { return playerData; }
    PlayerBase GetPlayer() { return player; }
}