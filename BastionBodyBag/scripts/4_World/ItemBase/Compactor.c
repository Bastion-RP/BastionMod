class BRP_Compactor : ItemBase 
{
    override void SetActions() {
        super.SetActions();
        AddAction(ActionCompactBodyBag);
    }
};