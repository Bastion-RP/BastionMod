modded class ActionConstructor
{
	override void RegisterActions(TTypenameArray actions)
	{
		super.RegisterActions(actions);
		actions.Insert(ActionShowDoorInfo);
		actions.Insert(ActionRemoteAdminManageHouses);
		actions.Insert(ActionRemoteManageHouses);
	}
}

