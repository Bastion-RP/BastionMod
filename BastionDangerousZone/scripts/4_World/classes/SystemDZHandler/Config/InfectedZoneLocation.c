class InfectedZoneLocation
{
  string InfectedZoneStatut;
  int    MinCreature;
  float X, Y, Radius;
  ref array<ref Creature> CreatureList;

    void InfectedZoneLocation(int mincreature, string infectedzonestatut, float x, float y, float radius)
	  {
      InfectedZoneStatut = infectedzonestatut;
      MinCreature = mincreature;
      X = x;
      Y = y;
      Radius = radius;
      CreatureList = new ref array<ref Creature>;
    }

    void AddCreatureToList(string name, int max)
  	{
  		CreatureList.Insert(new ref Creature(name,max));
  	}
}

class Creature{
	string CreatureName;
	int Max;

	void Creature(string creaturename, int max)
	{
		CreatureName = creaturename;
		Max = max;
	}
}
