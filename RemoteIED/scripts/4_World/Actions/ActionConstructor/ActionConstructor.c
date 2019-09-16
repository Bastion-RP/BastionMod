modded class ActionConstructor
{
	override void RegisterActions(TTypenameArray actions)
	{
		super.RegisterActions( actions );

		actions.Insert(ActionTouchOffIED);
		actions.Insert(ActionAddIEDToDetonator);
		actions.Insert(ActionArmIED);
		actions.Insert(ActionDisarmIED);
	}
}