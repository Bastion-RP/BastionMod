class RadiationZoneLocation
{
  string RadiationZoneStatut;
  int   NbSickGivenForRadiation;
  float X, Y, Radius;
	float X1,Y1,X2,Y2;
	bool IsSquareZone;

    void RadiationZoneLocation(int giveradsickness, bool isquarezone, string radiationzonestatut, float x, float y, float radius,float x1, float y1, float x2, float y2)
	  {
      NbSickGivenForRadiation = giveradsickness;
  		IsSquareZone=isquarezone;
      RadiationZoneStatut = radiationzonestatut;
      X = x;
      Y = y;
  		X1= x1;
  		Y1=y1;
  		X2=x2;
  		Y2=y2;
      Radius = radius;
    }
}
