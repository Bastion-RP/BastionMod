modded class Barrel_ColorBase
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionRemoteAdminManageHouses);
		AddAction(ActionRemoteManageHouses);
	}
}