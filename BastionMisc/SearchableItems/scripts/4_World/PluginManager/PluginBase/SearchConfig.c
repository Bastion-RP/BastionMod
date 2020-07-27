class SearchConfig
{
	private ref array<ref SearchableItem> SearchableItems;

	void SearchConfig()
	{
		SearchableItems = new array<ref SearchableItem>();
	}

	void Validate()
	{
		if (SearchableItems.Count() == 0)
		{
			SearchableItems.Insert( new SearchableItem("vbldr_wall_barricade1_10", 20, 0, 2, 0, 2, {"Nail","WaterBottle","Rice"} ));
		}
	}

	ref array<ref SearchableItem> GetSearchableItems() { return SearchableItems; }
}