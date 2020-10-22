//For coda_radio functionality
modded class ActionConstructor 
{
    override void RegisterActions(TTypenameArray actions)
    {
        super.RegisterActions(actions);

		actions.Insert( ActionTurnOnRadio);
        actions.Insert( ActionTurnOffRadio);
        actions.Insert( ActionRadioPlay);
        actions.Insert( ActionRadioStop);
    }
}
