class ActionInteractBanking : ActionInteractBase {
    void ActionInteractBanking() {
        m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
        m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
        m_HUDCursorIcon = CursorIcons.OpenDoors;
    }

    override void CreateConditionComponents() {
        m_ConditionItem = new CCINone;
        m_ConditionTarget = new CCTNone;
    }

    override string GetText() {
        return "Open Bank";
    }

    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item) {
        if (target.GetObject() && IsInReach(player, target, UAMaxDistances.DEFAULT) && BRP_ATM.Cast(target.GetObject())) { return true; }
        return false;
    }

    override void OnStartClient(ActionData action_data) {
        if (GetGame().GetUIManager().GetMenu()) { return; }
        GetGame().GetUIManager().EnterScriptedMenu(BSTBankMenu.BankingMenu, null);
    }
}