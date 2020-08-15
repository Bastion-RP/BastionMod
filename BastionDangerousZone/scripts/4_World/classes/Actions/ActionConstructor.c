modded class ActionConstructor
{
	override void RegisterActions(TTypenameArray actions)
	{
		super.RegisterActions(actions);

	  actions.Insert(ActionTestForRadiationSelf);
	  actions.Insert(ActionTestForRadiationTarget);
		actions.Insert(ActionDecontaminationObject);
		actions.Insert(ActionTurnOnBRP_DecontaminationShower);
		actions.Insert(ActionTurnOffBRP_DecontaminationShower);
		actions.Insert(ActionGetRadClotheLevel);
		//actions.Insert(ActionPackShower);
	}
};
