class SellItemData
{
	private string Classname;
	private float Quantity;
	private int Price;

	void SellItemData(string classname, float quant, int price)
	{
		Classname = classname;
		Quantity = quant;
		Price = price;
	}

	string GetClassname() { return Classname; }
	float GetQuantity() { return Quantity; }
	int GetPrice() { return Price; }
}

class SellerConfig
{
	private float PercentagePriceDecreaseByHelthLevel;
	private ref array<ref SellItemData> ArrayItemsData;

	void SellerConfig()
	{
		ArrayItemsData = new array<ref SellItemData>();
	}

	void Validate()
	{
		if (ArrayItemsData.Count() == 0)
		{
			ArrayItemsData.Insert(new SellItemData("WaterBottle", 1, 10));
			ArrayItemsData.Insert(new SellItemData("Rice", 1, 20));
		}
	}

	float GetPPDBHL() { return PercentagePriceDecreaseByHelthLevel; }
	ref array<ref SellItemData> GetDataArray() { return ArrayItemsData; }
}