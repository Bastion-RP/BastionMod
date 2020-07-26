class RadiationLocations
{
  ref array<float> X;
  ref array<float> Y;
  ref array<float> Radius;
  ref array<float> X1;
  ref array<float> Y1;
  ref array<float> X2;
  ref array<float> Y2;
  ref array<bool> IsSquareZone;

    void RadiationLocations(ref RadiationAreaSettings radAreaSettings)
	  {
      X = new array<float>;
      Y = new array<float>;
      Radius = new array<float>;
      X1 = new array<float>;
      Y1 = new array<float>;
      X2 = new array<float>;
      Y2 = new array<float>;
      IsSquareZone = new array<bool>;

      TransferRadConfig(radAreaSettings);
    }

    void TransferRadConfig(ref RadiationAreaSettings radAreaSettings)
    {
      int cpt = -1 + radAreaSettings.RadiationAreaLocation.Count();
      for(int i = 0; i<=cpt ; i++)
      {
        X.Insert(radAreaSettings.RadiationAreaLocation.Get(i).X);
        Y.Insert(radAreaSettings.RadiationAreaLocation.Get(i).Y);
        Radius.Insert(radAreaSettings.RadiationAreaLocation.Get(i).Radius);
        X1.Insert(radAreaSettings.RadiationAreaLocation.Get(i).X1);
        Y1.Insert(radAreaSettings.RadiationAreaLocation.Get(i).Y1);
        X2.Insert(radAreaSettings.RadiationAreaLocation.Get(i).X2);
        Y2.Insert(radAreaSettings.RadiationAreaLocation.Get(i).Y2);
        IsSquareZone.Insert(radAreaSettings.RadiationAreaLocation.Get(i).IsSquareZone);
      }
    }

}
