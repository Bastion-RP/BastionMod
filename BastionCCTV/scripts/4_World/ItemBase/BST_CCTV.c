class BRP_CCTV : ItemBase {
    override void SetActions() {
        super.SetActions();
        AddAction(ActionOpenCCTV);
    }
    bool ConditionIntoInventory(EntityAI player) {
        return false;
    }

    override bool CanPutIntoHands(EntityAI parent) {
        return false;
    }

    override bool CanPutInCargo(EntityAI parent) {
        return false;
    }

    bool ConditionOutOfHands(EntityAI player) {
        return false;
    }
}