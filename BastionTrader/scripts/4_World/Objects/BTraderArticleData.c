class BTraderArticleData
{
	private string								Category;
	private ref array<ref BTraderProductData> 	Products = new array<ref BTraderProductData>();

	string GetCategory() { return Category; }
	array<ref BTraderProductData> GetProducts() { return Products; }
}