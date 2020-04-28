class NCCLockPick : Inventory_Base
{
	override void SetActions()
	{
		super.SetActions();

		AddAction( ActionNCCLockDoor );
		AddAction( ActionNCCUnlockDoor );
	}
}