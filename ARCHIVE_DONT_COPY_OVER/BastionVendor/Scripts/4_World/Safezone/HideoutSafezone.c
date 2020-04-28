class Safezone
{
    void Safezone()
    {
        GetGame().GameScript.Call( this, "UpdateThread", NULL );
    }

    void ~Safezone()
    {

    }   

    bool IsInside( vector position )
	{	
        array<ref SafezoneRadius> zones = GetServerSettings().GetSafezoneSettings().Locations;

		if ( !zones )
			return false;

		for ( int i = 0; i < zones.Count(); i++)
		{
			SafezoneRadius zone = zones[i];

			if ( !zone )
				continue;
									
			float x = zone.Position[0] - position[0];
			float z = zone.Position[2] - position[2];

			float distance = (x * x) + (z * z); 
				
			if ( distance < (zone.Radius * zone.Radius) ) 
			{
				return true;
			}
		}

        return false;
	}

    void UpdatePlayers()
    {
        for ( int i = 0; i < PlayerBase.GetAll().Count(); i++ )
		{
            PlayerBase player = PlayerBase.GetAll().Get( i );

			if ( !player )
				continue;

            if (IsInside(player.GetPosition()))
            {
                if ( !player.IsInSafeZone() )
				{
					player.EnterSafeZone();
				}
            }
            else
            {
                if ( player.IsInSafeZone() )
				{
					player.LeaveSafeZone();
				}
            }
        }
    }

    void UpdateVehicles()
    {
        for ( int i = 0; i < CarScript.GetAll().Count(); i++ )
		{
            CarScript car = CarScript.GetAll().Get( i );

			if ( !car )
				continue;

            if (IsInside(car.GetPosition()))
            {
                if ( !car.IsInSafeZone() )
				{
					car.EnterSafeZone();
				}
            }
            else
            {
                if ( car.IsInSafeZone() )
				{
					car.LeaveSafeZone();
				}
            }
        }
    }

    void UpdateZombies()
    {
        for ( int i = 0; i < ZombieBase.GetAll().Count(); i++ )
		{
            ZombieBase zombie = ZombieBase.GetAll().Get( i );

			if ( !zombie )
				continue;

            if (IsInside(zombie.GetPosition()))
            {
                if ( !zombie.IsInSafeZone() )
				{
					zombie.EnterSafeZone();
				}
            }
            else
            {
                if ( zombie.IsInSafeZone() )
				{
					zombie.LeaveSafeZone();
				}
            }
        }
    }

    void UpdateThread()
    {
        while ( true )
		{
            bool enabled = GetServerSettings().GetSafezoneSettings().Enabled;

			if ( !enabled )
			{
				return;
			}
   
			array<ref SafezoneRadius> zones = GetServerSettings().GetSafezoneSettings().Locations;

			if ( !zones )
			{
				return;
			}

			UpdatePlayers();
			UpdateVehicles();
			UpdateZombies();

			Sleep( 1000 );
		}
    }
}

static ref Safezone g_Safezone;
static ref Safezone GetSafezone()
{
    if ( !g_Safezone )
    {
        g_Safezone = new ref Safezone();
    }
    
    return g_Safezone;
}