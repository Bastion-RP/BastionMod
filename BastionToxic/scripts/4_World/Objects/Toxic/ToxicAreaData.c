class ToxicAreaData
{
	private string Position;
	private string Mins;
	private string Maxs;
	private int Radius;
	private bool IsCircle;
	private ref array<ref ParticlesData> ParticlesArr;

	// void ToxicAreaData(string pos = "", int rad = 0, array<ref ParticlesData> arr = null)
	// {
	// 	Position = pos;
	// 	Radius = rad;
	// 	ParticlesArr = arr;
	// }


	vector GetPos() { return Position.ToVector(); }
	vector GetMins() { return Mins.ToVector(); }
	vector GetMaxs() { return Maxs.ToVector(); }
	bool IsCircle() { return IsCircle; }
	int GetRadius() { return Radius; }
	array<ref ParticlesData> GetPTCArray() { return ParticlesArr; }
}

class ParticlesData
{
	private string Type;
	private string Pos;

	void ParticlesData(string type = "", string pos = "")
	{
		Type = type;
		Pos = pos;
	}

	string GetType() { return Type; }
	vector GetPos() { return Pos.ToVector(); }
}