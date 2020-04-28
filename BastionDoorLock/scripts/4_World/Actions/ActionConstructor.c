modded class ActionConstructor
{
	override void RegisterActions( TTypenameArray actions )
	{
		super.RegisterActions( actions );
		actions.Insert( ActionNCCLockDoor );
		actions.Insert( ActionNCCUnlockDoor );
		actions.Insert( ActionInteractEasyAccess );
		actions.Insert( ActionInteractLockedDoor );
		actions.Insert( ActionInteractChangePasscode );
	}
};