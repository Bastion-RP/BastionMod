class BST_ActionStartStopSmelting : ActionInteractBase {
    private string _actionText;

    override void CreateConditionComponents() {
        m_ConditionItem = new CCINone();
        m_ConditionTarget = new CCTNone();
    }

    override string GetText() {
        return _actionText;
    }

    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item) {
        BRP_FurnaceFireplace furnace = BRP_FurnaceFireplace.Cast(target.GetObject());

        if (furnace && Math.AbsFloat(vector.Distance(furnace.GetPosition(), player.GetPosition())) < UAMaxDistances.DEFAULT) {
            _actionText = "Turn ";

            if (furnace.IsBurning()) {
                _actionText += "Off Furnace";
            } else if (furnace.CanStartSmelting()) {
                _actionText += "On Furnace";
            } else {
                return false;
            }
            return true;
        }
        return false;
    }

    override void OnExecuteServer(ActionData action_data) {
        BRP_FurnaceFireplace furnace = BRP_FurnaceFireplace.Cast(action_data.m_Target.GetObject());

        if (furnace) {
            if (furnace.IsBurning()) {
                furnace.StopSmelting();
            } else if (furnace.CanStartSmelting()) {
                furnace.StartSmelting();
            }
        }
    }
}