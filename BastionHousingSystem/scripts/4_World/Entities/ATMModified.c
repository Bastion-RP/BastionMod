modded class BRP_ATM : BuildingBase 
{
    override void SetActions() 
	{
        super.SetActions();

        AddAction(ActionRemoteAdminManageHouses);
		AddAction(ActionRemoteManageHouses);
    }
}