class DTACTracker {
    private static const int MAX_HEALTH = 100;
    private static const int MAX_BLOOD = 5000;
    private static const int MAX_WATER = 5000;
    private static const int MAX_FOOD = 5000;
    private static const int BLOOD_DEATH_THRESHOLD = 2500;
    private static const int FRAME_PADDING = 4;
    private static const int GRID_PADDING = 6;

    private ref Widget wParent;
    private ref Widget wRootData;
    private ref TextWidget txtDataName, txtDataHealth, txtDataBlood, txtDataWater, txtDataFood;
    private ref Widget wRootVisual;
    private ref TextWidget txtVisualName;
    private ref GridSpacerWidget gridParent;
    private ref DTACGroupMember groupMember;
    private bool relativeScreenSide = false; // false = left | true = right

    void DTACTracker(ref DTACGroupMember groupMember, Widget wParent, Widget gridParent) {
        this.wParent = wParent;
        this.gridParent = gridParent;
        this.groupMember = groupMember;

        // Data widget
        wRootData = GetGame().GetWorkspace().CreateWidgets("BastionDTAC\\gui\\layouts\\TrackerData.layout", gridParent);
        txtDataName = TextWidget.Cast(wRootData.FindAnyWidget("txtName"));
        txtDataHealth = TextWidget.Cast(wRootData.FindAnyWidget("txtHealth"));
        txtDataBlood = TextWidget.Cast(wRootData.FindAnyWidget("txtBlood"));
        txtDataWater = TextWidget.Cast(wRootData.FindAnyWidget("txtWater"));
        txtDataFood = TextWidget.Cast(wRootData.FindAnyWidget("txtFood"));

        // Visual widget
        wRootVisual = GetGame().GetWorkspace().CreateWidgets("BastionDTAC\\gui\\layouts\\Tracker.layout", wParent);
        txtVisualName = TextWidget.Cast(wRootVisual.FindAnyWidget("txtPlayerName"));

        txtDataName.SetText(GetFormattedName(groupMember.GetPlayerData().GetName()));
        txtVisualName.SetText(GetFormattedName(groupMember.GetPlayerData().GetName()));
        wRootVisual.Show(false);
        txtVisualName.Show(false);
        UpdateDataStats();
        GetDTACClientGroupManager().playerUpdateInvoker.Insert(StartUpdateLoop);
        GetDTACClientGroupManager().statUpdateInvoker.Insert(UpdateDataStats);
        //GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(this.CheckForPlayerBase, 1000, true);
    }

    void ~DTACTracker() {
        if (wRootData) {
            wRootData.Unlink();
        }
        if (wRootVisual) {
            wRootVisual.Unlink();
        }
    }

    void StartUpdateLoop() {
        StopUpdateLoop();
        GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(this.UpdateVisualTracker, 10, true);
    }

    void StartUpdateLoop(string uid) {
        if (groupMember.GetPlayerData().GetId() == uid) {
            StartUpdateLoop();
        }
    }

    void StopUpdateLoop() {
        GetGame().GetCallQueue(CALL_CATEGORY_GUI).Remove(this.UpdateVisualTracker);
    }

    /* void CheckForPlayerBase() {
        Print("[DEBUG] DTACTracker | CheckForPlayerBase | Initializing playerbase loop check");
        if (groupMember.GetPlayer() && groupMember.GetPlayer().IsAlive()) {
            Print("[DEBUG] DTACTracker | CheckForPlayerBase | Player exists and is alive");
            if (!wRootVisual.IsVisible()) {
                Print("[DEBUG] DTACTracker | CheckForPlayerBase | Tracker hidden, starting update");
                StartUpdateLoop();
            }
        } else {
            Print("[DEBUG] DTACTracker | CheckForPlayerBase | No player found, stopping loop");
            wRootVisual.Show(false);
            StopUpdateLoop();
        }
    } */

    void UpdateVisualTracker() {
        if (!groupMember.GetPlayer()) {
            Print("[DEBUG] DTACTracker | UpdateVisualTracker | No player found, stopping loop");
            StopUpdateLoop();
            wRootVisual.Show(false);
            return;
        }
        float posX, posY;
        vector playerHeadPos, relativeScreenPos, screenPos, angleVector;

        wRootVisual.Show(true);
        MiscGameplayFunctions.GetHeadBonePos(groupMember.GetPlayer(), playerHeadPos);
        // Shift actual vector numbers instead of pixels. This makes the tracker stick to the target better at range
        //playerHeadPos[0] = playerHeadPos[0] + 0.;
        playerHeadPos[1] = playerHeadPos[1] + 0.5;
        relativeScreenPos = GetGame().GetScreenPosRelative(playerHeadPos);
        screenPos = GetGame().GetScreenPos(playerHeadPos);
        posY = Math.Ceil(screenPos[1]);
        angleVector = relativeScreenPos.VectorToAngles();

        if (relativeScreenPos[0] > 0 && relativeScreenPos[0] < 1 && relativeScreenPos[1] > 0 && relativeScreenPos[1] < 1 && relativeScreenPos[2] > 0) {
            if (relativeScreenPos[0] > 0 && relativeScreenPos[0] < 0.5) {
                relativeScreenSide = false;
            } else if (relativeScreenPos[0] >= 0.5 && relativeScreenPos[0] < 1) {
                relativeScreenSide = true;
            }
            if (relativeScreenPos[0] > 0.489 && relativeScreenPos[0] < 0.51 && relativeScreenPos[1] > 0.43 && relativeScreenPos[1] < 0.48) {
                txtVisualName.Show(true);
            } else {
                txtVisualName.Show(false);
            }
            screenPos = GetGame().GetScreenPos(playerHeadPos);
            posX = Math.Ceil(screenPos[0]);
            wRootVisual.SetPos(posX, posY);
        } else {
            // This will attach the tracker to whichever side of the screen the player is closest
            // instead of hiding it. Could be useful for combat.

            int screenW, screenH;

            GetScreenSize(screenW, screenH);

            if (relativeScreenPos[0] > 0 && relativeScreenPos[0] < 0.5) {
                relativeScreenSide = true;
            } else if (relativeScreenPos[0] < 1 && relativeScreenPos[0] >= 0.5) {
                relativeScreenSide = false;
            }
            if (relativeScreenSide) {
                wRootVisual.SetPos(screenW - 30, posY);
            } else {
                wRootVisual.SetPos(5, posY);
            }
        }
    }

    void UpdateDataStats() {
        Print("[DEBUG] DTACTracker | UpdateDataStats | health=" + groupMember.GetPlayerData().GetHealth());
        Print("[DEBUG] DTACTracker | UpdateDataStats | blood=" + groupMember.GetPlayerData().GetBlood());
        Print("[DEBUG] DTACTracker | UpdateDataStats | water=" + groupMember.GetPlayerData().GetWater());
        Print("[DEBUG] DTACTracker | UpdateDataStats | food=" + groupMember.GetPlayerData().GetFood());
        Print("[DEBUG] DTACTracker | UpdateDataStats | food=" + groupMember.GetPlayerData().GetPosition());
        txtDataHealth.SetText("" + ((groupMember.GetPlayerData().GetHealth() / MAX_HEALTH) * 100).ToString().ToInt() + "%");
        txtDataBlood.SetText("" + (((groupMember.GetPlayerData().GetBlood() - BLOOD_DEATH_THRESHOLD) / (MAX_BLOOD - BLOOD_DEATH_THRESHOLD)) * 100).ToString().ToInt() + "%");
        txtDataWater.SetText("" + ((groupMember.GetPlayerData().GetWater() / MAX_WATER) * 100).ToString().ToInt() + "%");
        txtDataFood.SetText("" + ((groupMember.GetPlayerData().GetFood() / MAX_FOOD) * 100).ToString().ToInt() + "%");
        FixFrameSize();
    }

    void UpdateDataStats(string uid) {
        if (groupMember.GetPlayerData().GetId() == uid) {
            UpdateDataStats();
        }
    }

    void FixFrameSize() {
        float w0, y0;
        int w1, w2, w3, w4, w5, y, combined;

        txtDataName.GetTextSize(w1, y);
        txtDataHealth.GetTextSize(w2, y);
        txtDataBlood.GetTextSize(w3, y);
        txtDataWater.GetTextSize(w4, y);
        txtDataFood.GetTextSize(w5, y);
        wRootData.GetSize(w0, y0);

        combined = w2 + w3 + w4 + w5 /*+ GRID_PADDING*/;

        if (w1 >= w0) {
            wRootData.SetSize(w1 + FRAME_PADDING, y0);
        } else if (combined >= w0) {
            wRootData.SetSize(combined + FRAME_PADDING, y0);
        }
    }

    string GetFormattedName(string name) {
        array<string> nameSplit = new array<string>();
        
        name.Split(" ", nameSplit);

        return "" + nameSplit[0].Substring(0, 1) + ". " + nameSplit[1];
    }

    DTACPlayerData GetPlayerData() { return groupMember.GetPlayerData(); }
}