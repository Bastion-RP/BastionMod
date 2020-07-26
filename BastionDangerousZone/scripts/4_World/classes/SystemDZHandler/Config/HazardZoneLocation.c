class HazardZoneLocation
{
  string HazardZoneStatut;
  float X, Y, Radius;
	float X1,Y1,X2,Y2;
	bool IsSquareZone;
  ref array<ref ParticleListe> ParticlesPosition;

    void HazardZoneLocation(bool isquarezone, string hazardzonestatut, float x, float y, float radius,float x1, float y1, float x2, float y2)
	  {
  		IsSquareZone=isquarezone;
      HazardZoneStatut = hazardzonestatut;
      X = x;
      Y = y;
  		X1=x1;
  		Y1=y1;
  		X2=x2;
  		Y2=y2;
      Radius = radius;
      ParticlesPosition = new ref array<ref ParticleListe>;
    }

    void AddParticlePosition(string name, vector pos)
  	{
  		ParticlesPosition.Insert(new ref ParticleListe(name,pos));
  	}
}

class ParticleListe
{
	string NName;
	vector PPos;

	void ParticleListe(string name, vector pos)
	{
		NName=name;
		PPos=pos;
	}
}
