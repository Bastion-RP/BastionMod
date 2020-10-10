class ToxicAreaData
{
	private string Position;
	private int Radius;
	private ref array<ref ParticlesData> ParticlesArr;

	void ToxicAreaData(string pos = "", int rad = 0, array<ref ParticlesData> arr = null)
	{
		Position = pos;
		Radius = rad;
		ParticlesArr = arr;
	}


	vector GetPos() { return Position.ToVector(); }
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