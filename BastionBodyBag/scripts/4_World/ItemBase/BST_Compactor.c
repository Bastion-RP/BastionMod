class BRP_Compactor : BuildingSuper 
{
    override void SetActions() {
        super.SetActions();
        AddAction(ActionCompactBodyBag);
    }
};