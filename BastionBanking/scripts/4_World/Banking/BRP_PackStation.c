modded class BRP_PackStation : BuildingBase {
    override void SetActions() {
        super.SetActions();

        AddAction(BST_BankingActionInteractBanking);
    }
}