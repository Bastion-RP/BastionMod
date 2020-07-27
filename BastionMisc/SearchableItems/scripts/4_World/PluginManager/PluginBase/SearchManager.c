class SearchManager : PluginBase
{
	private ref SearchConfig config;

	void SearchManager()
	{
		CheckDirectory();

		if (!FileExist(SIConst.configDir))
		{
			config = new SearchConfig();
			config.Validate();
			JsonFileLoader<SearchConfig>.JsonSaveFile(SIConst.configDir, config);
        } 
		else 
		{
            JsonFileLoader<SearchConfig>.JsonLoadFile(SIConst.configDir, config);
		}
	}

	void CheckDirectory()
	{
		if (!FileExist(SIConst.modDir))
		{
			MakeDirectory(SIConst.modDir);
		}
	}

	SearchableItem GetSearchableItemByType(string type)
	{
		array<ref SearchableItem> SearchableItems;
		string tempType;

		SearchableItems = config.GetSearchableItems();
		foreach (SearchableItem item : SearchableItems)
		{
			tempType = item.GetClassname();
			if (tempType == type)
			return item;
		}
		return null;
	}

	int GetNumberSearches(SearchableBase obj)
	{
		SearchableItem item;
		int min, max;
		int result;
		string type;

		type = obj.GetType();
		item = GetSearchableItemByType(type);

		if (!item) return 0;

		min = item.GetMinimumNumberSearches();
		max = item.GetMaximumNumberSearches();

		result = Math.RandomIntInclusive(min, max);

		return result;
	}

	int GetNumberItems(SearchableBase obj)
	{
		SearchableItem item;
		int min, max;
		int result;
		string type;

		type = obj.GetType();
		item = GetSearchableItemByType(type);

		if (!item) return 0;

		min = item.GetMinimumSpawnItems();
		max = item.GetMaximumSpawnItems();

		result = Math.RandomIntInclusive(min, max);

		return result;
	}

	void InitSearchObject(SearchableBase obj)
	{
		SearchableItem item;
		int numberSearches;
		int cooldown;
		string type;

		type = obj.GetType();
		item = GetSearchableItemByType(type);
		numberSearches = GetNumberSearches(obj);
		cooldown = item.GetCooldown();

		obj.SetNumberSearches(numberSearches);
		obj.SetCooldown(cooldown);
	}

	string GetRandomItem(SearchableBase obj)
	{
		SearchableItem item;

		item = GetSearchableItemByType(obj.GetType());

		if (!item) return "";

		return item.GetPossibleDrop().GetRandomElement();
	}

	SearchConfig GetConfig()
	{
		return config;
	}
}

SearchManager GetSearchManager()
{
	return SearchManager.Cast(GetPlugin(SearchManager));
}