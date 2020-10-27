//Allows field shovels to unbury stashes
modded class FieldShovel extends ItemBase
{
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionDigOutStash);
	}	
};