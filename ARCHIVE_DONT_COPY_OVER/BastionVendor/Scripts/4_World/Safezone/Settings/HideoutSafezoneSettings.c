class SafezoneRadius
{
    vector Position;
	float Radius;
	string Name;

    void SafezoneRadius( vector position, float radius, string name )
	{
        this.Position = position;
		this.Radius = radius;
		this.Name = name;
    }
}

class SafezoneSettings
{
    bool Enabled;

    ref array< ref SafezoneRadius > Locations;

    void SafezoneSettings()
    {
		Locations = new array< ref SafezoneRadius >;
    }

    void Defaults()
    {
        Enabled = true;
        
        Locations.Insert( new SafezoneRadius( Vector(11925, 140, 12595), 1000, "NEAF" ) );

        if ( !FileExist( "$profile:Bastion\\Vendors" ) )
		{
			MakeDirectory( "$profile:Bastion\\Vendors" );
		}

		JsonFileLoader<SafezoneSettings>.JsonSaveFile( "$profile:Bastion\\Vendors\\Safezone.json", this );
    }

    void Load()
	{
		if ( FileExist( "$profile:Bastion\\Vendors\\Safezone.json" ) )
		{
			JsonFileLoader<SafezoneSettings>.JsonLoadFile( "$profile:Bastion\\Vendors\\Safezone.json", this );
		} 
		else 
		{
			Defaults();
		}
	}
}