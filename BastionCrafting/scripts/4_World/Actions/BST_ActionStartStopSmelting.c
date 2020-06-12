class BST_ActionStartStopSmelting : ActionInteractBase {
    override void CreateConditionComponents() {
        m_ConditionItem = new CCINone();
        m_ConditionTarget = new CCTNone();
    }

    override string GetText() {
        return "Turn On/Off Furnace";
    }

    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item) {
        ItemBase targetObject = ItemBase.Cast(target.GetObject());

        if (targetObject && Math.AbsFloat(vector.Distance(targetObject.GetPosition(), player.GetPosition())) < UAMaxDistances.DEFAULT) {
            return true;
        }
        return false;
    }

    override void OnExecuteServer(ActionData action_data) {
        ItemBase targetObject = ItemBase.Cast(action_data.m_Target.GetObject());
        
        if (targetObject) {
            if (!targetObject.GetBSTFurnaceHandler()) {
                targetObject.CreateFurnaceHandler();
            }
            BST_FurnaceHandler furnaceHandler = targetObject.GetBSTFurnaceHandler();

            if (furnaceHandler.IsSmelting()) {
                furnaceHandler.StopSmelting();
            } else {
                furnaceHandler.StartSmelting();
            }
        }
    }
}