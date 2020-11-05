modded class Lockpick
{
	override void SetActions()
	{
		super.SetActions();
		
		RemoveAction(ActionLockDoors);
		RemoveAction(ActionUnlockDoors);
	}
};