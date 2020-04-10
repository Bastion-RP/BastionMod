modded class ActionConstructor {
    override void RegisterActions(TTypenameArray actions) { 
        super.RegisterActions(actions);
        actions.Insert(ActionBodyBag);
        actions.Insert(ActionBuryBodyBag);
        actions.Insert(ActionCompactBodyBag);
    }
}