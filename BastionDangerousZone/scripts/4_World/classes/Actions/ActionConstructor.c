modded class ActionConstructor
{
	override void RegisterActions(TTypenameArray actions)
	{
		super.RegisterActions(actions);

	  actions.Insert(ActionTestForRadiationSelf);
	  actions.Insert(ActionTestForRadiationTarget);
		actions.Insert(ActionDecontaminationObject);
		actions.Insert(ActionTurnOnDecontaminationShower);
		actions.Insert(ActionTurnOffDecontaminationShower);
		actions.Insert(ActionGetRadClotheLevel);
		actions.Insert(ActionUnpackShowerKit);
		actions.Insert(ActionDeployShower);
		actions.Insert(ActionPackShower);
	}
};
