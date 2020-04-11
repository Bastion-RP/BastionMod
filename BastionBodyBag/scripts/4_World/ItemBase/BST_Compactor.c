class BST_Compactor : BuildingSuper 
{
    override void SetActions() {
        super.SetActions();
        AddAction(ActionCompactBodyBag);
    }
};