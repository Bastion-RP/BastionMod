class BRP_BodyBagKit : ItemBase {
    override void SetActions() {
        super.SetActions();
        AddAction(ActionBodyBag);
        AddAction(ActionPutCorpseInBag);
    }
};