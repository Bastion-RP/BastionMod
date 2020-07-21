class BST_ActionCloseFurnace : ActionInteractBase {
    void BST_ActionCloseFurnace() {
        m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
        m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
        m_HUDCursorIcon = CursorIcons.CloseHood;
    }

    override string GetText() {
        return "#close";
    }

    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item) {
        if (!target.GetObject()) { return false; }
        BRP_Furnace_Fireplace furnace = BRP_Furnace_Fireplace.Cast(target.GetObject());

        if (furnace && furnace.IsOpen()) {
            return true;
        }
        return false;
    }

    override void OnExecuteServer(ActionData action_data) {
        if (!action_data.m_Target.GetObject()) { return; }
        BRP_Furnace_Fireplace furnace = BRP_Furnace_Fireplace.Cast(action_data.m_Target.GetObject());

        if (furnace) {
            furnace.Close();
        }
    }

    override void OnEndServer(ActionData action_data) {
        if (!action_data.m_Target.GetObject()) { return; }
        BRP_Furnace_Fireplace furnace = BRP_Furnace_Fireplace.Cast(action_data.m_Target.GetObject());

        if (furnace) {
            furnace.SoundSynchRemoteReset();
        }
    }
}