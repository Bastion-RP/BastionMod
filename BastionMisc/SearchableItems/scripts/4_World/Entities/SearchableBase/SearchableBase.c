class SearchableBase : House
{
	private int 	numberSearches;
	private int		currentSearches;
	private int		cooldown;

	void SearchableBase()
	{
		numberSearches = 0;
		currentSearches = 0;

		RegisterNetSyncVariableInt("numberSearches");
		RegisterNetSyncVariableInt("currentSearches");
	}

	void IncCurrentSearches()
	{
		if (GetGame().IsServer())
		{
			currentSearches++;
			SetSynchDirty();
			StartCooldownTimer();
		}
	}

	void DecCurrentSearches()
	{
		if (GetGame().IsServer())
		{
			currentSearches--;
			SetSynchDirty();
		}
	}

	void SetNumberSearches(int val)
	{
		numberSearches = val;
		SetSynchDirty();
	}

	void SetCooldown(int val)
	{
		cooldown = val;
	}

	int GetNumberSearches()
	{
		return numberSearches;
	}

	int GetCooldown()
	{
		return cooldown;
	}

	int GetCurrentSearches()
	{
		return currentSearches;
	}

	bool CanSearch()
	{
		return GetCurrentSearches() <= GetNumberSearches();
	}

	void DoSearch(vector position)
	{
		int numberItems;

		if (!numberSearches)
		{
			GetSearchManager().InitSearchObject(this);
		}

		numberItems = GetSearchManager().GetNumberItems(this);

		while (numberItems)
		{
			SpawnItem(position);
			numberItems--;
		}

		IncCurrentSearches();
	}

	void SpawnItem(vector position)
	{
		string itemType;

		itemType = GetSearchManager().GetRandomItem(this);

		if (!itemType) return;

		GetGame().CreateObject(itemType, position, false);
	}

	void StartCooldownTimer()
	{
		GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( this.DecCurrentSearches, (cooldown * 1000), false );
	}
}

class garbage_pile1 	: SearchableBase {}
class garbage_pile2 	: SearchableBase {}
class garbage_pile3 	: SearchableBase {}
class garbage_pile4 	: SearchableBase {}
class garbage_pile5 	: SearchableBase {}
class garbage_pile6 	: SearchableBase {}
class garbage_pile7 	: SearchableBase {}
class garbage_pile8 	: SearchableBase {}
class misc_barricade	: SearchableBase {}
class wall_barricade1_4	: SearchableBase {}
class wall_barricade1_10: SearchableBase {}