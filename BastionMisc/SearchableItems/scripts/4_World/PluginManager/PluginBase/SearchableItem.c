class SearchableItem
{
	private string					Classname;
	private int 					Cooldown;
	private int 					MinimumNumberSearches;
	private int 					MaximumNumberSearches;
	private int						MinimumSpawnItems;
	private int						MaximumSpawnItems;
	private ref array<string>		PossibleDrop;

	void SearchableItem(string cl, int cd, int mnNs, int mxNs, int mnSI, int mxSI, ref array<string> possibleDrop)
	{
		Classname 				= cl;
		Cooldown				= cd;
		MinimumNumberSearches	= mnNs;
		MaximumNumberSearches	= mxNs;
		MinimumSpawnItems		= mnSI;
		MaximumSpawnItems		= mxSI;
		PossibleDrop			= possibleDrop;
	}

	string GetClassname() 					{ return Classname; }
	int GetCooldown()						{ return Cooldown; }
	int GetMinimumNumberSearches() 			{ return MinimumNumberSearches; }
	int GetMaximumNumberSearches() 			{ return MaximumNumberSearches; }
	int GetMinimumSpawnItems()				{ return MinimumSpawnItems; }
	int GetMaximumSpawnItems()				{ return MaximumSpawnItems; }
	ref array<string> GetPossibleDrop()		{ return PossibleDrop; }
}