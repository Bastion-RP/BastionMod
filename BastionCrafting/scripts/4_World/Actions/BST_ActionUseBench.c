class BST_ActionUseBench : ActionInteractBase {
    override void CreateConditionComponents() {
        m_ConditionItem = new CCINone();
        m_ConditionTarget = new CCTNone();
    }

    override string GetText() {
        return "Craft";
    }

    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item) {
        BRP_CraftingBenchBase benchBase = BRP_CraftingBenchBase.Cast(target.GetObject());

        if (benchBase && Math.AbsFloat(vector.Distance(benchBase.GetPosition(), player.GetPosition())) < UAMaxDistances.DEFAULT) {
            return true;
        }
        return false;
    }

    override void OnExecuteClient(ActionData action_data) {
        BRP_CraftingBenchBase benchBase = BRP_CraftingBenchBase.Cast(action_data.m_Target.GetObject());

        if (benchBase) {
            GetGame().GetUIManager().EnterScriptedMenu(BST_CraftingConst.CONST_CRAFTING_MENU_ID, null);

            BST_CraftingMenu craftingMenu = BST_CraftingMenu.Cast(GetGame().GetUIManager().GetMenu());

            if (craftingMenu) {
                craftingMenu.SetBench(benchBase);
            }
        }
    }
}