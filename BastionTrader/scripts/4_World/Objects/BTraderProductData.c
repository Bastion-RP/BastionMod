class BTraderProductData
{
	private ref DefaultItemData Result;
	private ref array<ref DefaultItemData> RequiredItems = new array<ref DefaultItemData>();

	DefaultItemData GetResult() {return Result;}
	array<ref DefaultItemData> GetReqItems() {return RequiredItems;}
}

class DefaultItemData
{
	private string 	Classname;
	private float	Quantity;

	string 	GetType() { return Classname; }
	float 	GetQuantity() { return Quantity; }
}