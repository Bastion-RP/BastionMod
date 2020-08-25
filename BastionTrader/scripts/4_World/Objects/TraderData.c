class TraderData
{
	private int 	Id;
	private vector	Position;
	private vector	Orientation;
	private string	Type;

	private ref array<string> Clothes = new array<string>();
	private ref array<int> AllowClasses = new array<int>();
	private ref array<ref BTraderArticleData> AllGoods = new array<ref BTraderArticleData>();

	int GetId() { return Id; }
	vector GetPos() { return Position; }
	vector GetOri() { return Orientation; }
	string GetType() {return Type; }

	array<string> GetClothes() { return Clothes; }
	array<int> GetAllowClasses() { return AllowClasses; }
	array<ref BTraderArticleData> GetGoods() { return AllGoods; }
}