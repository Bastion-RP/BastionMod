modded class ActionConstructor
{	
	override void RegisterActions(TTypenameArray actions)
	{
		
		super.RegisterActions(actions);
		
		actions.Insert(ActionInjectShockSelf);
		actions.Insert(ActionInjectShockTarget);
		//actions.Insert(ActionCombineItem);
	}
};