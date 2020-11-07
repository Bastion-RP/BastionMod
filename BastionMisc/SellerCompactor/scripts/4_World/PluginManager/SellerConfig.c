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

class SellerObjData
{
	private string Type;
	private ref array<ref SellItemData> ArrayItemsData;

	void SellerObjData()
	{
		ArrayItemsData = new array<ref SellItemData>();
	}

	ref array<ref SellItemData> GetDataArray() { return ArrayItemsData; }
	string GetType() { return Type; }
}

class SellerConfig
{
	private float PercentagePriceDecreaseByHelthLevel;
	private ref array<ref SellerObjData> SellersObjData;

	void SellerConfig()
	{
		SellersObjData = new array<ref SellerObjData>();
	}

	float GetPPDBHL() { return PercentagePriceDecreaseByHelthLevel; }
	ref array<ref SellerObjData> GetSellersData() { return SellersObjData; }
}