modded class ItemBase
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionOpenDoorWithKey);
	}
}

class BunchKeys_Base : ItemBase {}