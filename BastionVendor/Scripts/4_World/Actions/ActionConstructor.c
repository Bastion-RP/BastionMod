modded class ActionConstructor
{
    override void RegisterActions( TTypenameArray actions )
	{
		super.RegisterActions( actions );	

        actions.Insert( ActionTrade );
        actions.Insert( ActionExchange );
        actions.Insert( ActionRefillAIONVendingMachine );
    }
};