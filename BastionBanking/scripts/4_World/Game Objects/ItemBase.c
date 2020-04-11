modded class ItemBase {
    bool ConditionIntoInventory(EntityAI player) {
        string type = GetType();
        type.ToLower();

        if (type == GetBBankConfig().GetConfig().GetATMClassName()) {
            return false;
        }
        return super.CanPutInCargo(player);
    }

    override bool CanPutIntoHands(EntityAI parent) {
        string type = GetType();
        type.ToLower();

        if (GetBBankConfig() && GetBBankConfig().GetConfig() && GetBBankConfig().GetConfig().GetATMClassName() && type == GetBBankConfig().GetConfig().GetATMClassName()) {
            return false;
        }
        return super.CanPutInCargo(parent);
    }

    override bool CanPutInCargo(EntityAI parent) {
        string type = GetType();
        type.ToLower();

        if (GetBBankConfig() && GetBBankConfig().GetConfig() && GetBBankConfig().GetConfig().GetATMClassName() && type == GetBBankConfig().GetConfig().GetATMClassName()) {
            return false;
        }
        return super.CanPutInCargo(parent);
    }

    bool ConditionOutOfHands(EntityAI player) {
        string type = GetType();
        type.ToLower();

        if (type == GetBBankConfig().GetConfig().GetATMClassName()) {
            return false;
        }
        return super.CanPutInCargo(player);
    }

    override void SetActions() {
        super.SetActions();

        AddAction(ActionInteractBanking);
    }
}