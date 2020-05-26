class BST_ActionUseBench : ActionInteractBase {
    void BST_ActionUseBench () {
        m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
        m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
        m_HUDCursorIcon = CursorIcons.CloseHood;
    }

/*     override void CreateConditionComponents () {
        m_ConditionTarget = new CCTObject (UAMaxDistances.DEFAULT);
        m_ConditionItem = new CCINonRuined ();
    } */

    override string GetText() {
        return "Craft";
    }

    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item) {
        //BST_CraftingBenchBase benchBase = BST_CraftingBenchBase.Cast(target.GetObject());
        EntityAI benchBase = target.GetObject();

        if (benchBase) {
            return true;
        }
        return false;
    }

    override void OnExecuteClient(ActionData action_data) {
        //BST_CraftingBenchBase benchBase = BST_CraftingBenchBase.Cast(action_data.m_Target.GetObject());
        EntityAI benchBase = action_data.m_Target.GetObject();

        if (benchBase) {
            GetGame().GetUIManager().EnterScriptedMenu(BST_CraftingConst.CONST_CRAFTING_MENU_ID, null);

            BST_CraftingMenu craftingMenu = BST_CraftingMenu.Cast(GetGame().GetUIManager().GetMenu());

            if (craftingMenu) {
                craftingMenu.SetBench(benchBase);
            }
        }
    }
}