class BRP_PackStation : BuildingBase 
{
    override void SetActions() 
	{
        super.SetActions();

        AddAction(ActionRemoteAdminManageHouses);
		AddAction(ActionRemoteManageHouses);
    }
}