modded class MissionGameplay {
    private autoptr BastionCCTV m_bastionCCTV;

    void MissionGameplay() {
        m_bastionCCTV = new BastionCCTV();
    }

    override void OnKeyPress( int key ) {
        super.OnKeyPress( key );

        BastionCCTVMenu menu = BastionCCTVMenu.Cast( GetUIManager().GetMenu() );
        if ( menu ) {
            menu.OnKeyPress( key );
        }
    }

    override UIScriptedMenu CreateScriptedMenu( int id ) {
        UIScriptedMenu menu = super.CreateScriptedMenu( id );

        if ( !menu ) {
            switch ( id ) {
                case BastionCCTVEnum.CCTVMenu:
                    menu = new BastionCCTVMenu();
                break;
            }
            if  ( menu ) {
                menu.SetID(id);
            }
        }

        return menu;
    }
}

modded class MissionServer {
    private autoptr BastionCCTV m_bastionCCTV;

	void InvokeOnConnect( PlayerBase player, PlayerIdentity identity ) {
        super.InvokeOnConnect( player, identity );
        GetRPCManager().SendRPC( "BastionCCTV", "InitClientCameraData", NULL, true, identity );
	}
	
	void CreateSpecificObject( string type, vector pos, vector dir )
	{
		auto obj = GetGame().CreateObject( type, pos );
		obj.SetPosition( pos );
		obj.SetOrientation( dir );
		obj.SetOrientation( obj.GetOrientation() );
		obj.Update();
		obj.SetAffectPathgraph( true, false );
		if( obj.CanAffectPathgraph() ) GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( GetGame().UpdatePathgraphRegionByObject, 100, false, obj );
	}

    void MissionServer() {
        m_bastionCCTV = new BastionCCTV();

        if ( GetGame().IsServer() ) {
            if ( !FileExist( BastionCCTVConst.baseDir ) ) {
                MakeDirectory( BastionCCTVConst.baseDir );
            }
            if ( !FileExist( BastionCCTVConst.configDir ) ) {
                MakeDirectory( BastionCCTVConst.configDir );
            }

            if ( FileExist( BastionCCTVConst.config ) ) {
                JsonFileLoader<array<ref CCTVCamera>>.JsonLoadFile( BastionCCTVConst.config, m_bastionCCTV.m_cameras );
            } else {
				// To keep in mind while changing these positions:
				// 1. The camera views will be placed under these as to not show the model
				// 2. The camera models will not get the yaw and roll applied to them for now
                m_bastionCCTV.AddCamera( "Bridge", "4539.629395 15.510000 4724.262695", 130.0, -5.0, 0.0, false );
				m_bastionCCTV.AddCamera( "FireStationLow", "4843.568848 19.525745 4441.661133", -23.0, 0.0, 0.0, true );
				m_bastionCCTV.AddCamera( "FireStationHi", "4852.020020 28.375820 4420.404785", 78.0, 0.0, 0.0, true );
                m_bastionCCTV.AddCamera( "Office1", "4785.060059 28.352760 4448.580078", -50.0, -20.0, 0.0, false );
                m_bastionCCTV.AddCamera( "Office2", "4713.869141 16.800011 4444.125488", 77.0, -5.0, 0.0, false );
                m_bastionCCTV.AddCamera( "BigApt1", "4833.096191 32.104874 4252.549316", -141.0, -20.0, 0.0, true );
                m_bastionCCTV.AddCamera( "GuardHouse", "4712.000000 13.470000 4357.910156", 90.0, -10.0, 0.0, true );
                m_bastionCCTV.AddCamera( "SmallApt2", "4793.120117 21.055084 4234.770020", -42.0, -10.0, 0.0, true );
                m_bastionCCTV.AddCamera( "Hotel", "4823.660156 26.400049 4179.689941", -44.0, -10.0, 0.0, true );
                m_bastionCCTV.AddCamera( "Store", "4721.560059 18.530191 4251.169922", 91.0, -10.0, 0.0, true );
                m_bastionCCTV.AddCamera( "TrainStation", "4860.419922 16.050022 4103.109863", 22.0, -10.0, 0.0, true );
                m_bastionCCTV.AddCamera( "Industrial1", "4537.759766 19.786858 4389.817871", -131.0, -10.0, 0.0, false );
                m_bastionCCTV.AddCamera( "TownSquare1", "4660.910156 24.499821 4232.377930", 89.0, -10.0, 0.0, true );
                m_bastionCCTV.AddCamera( "Industrial2", "4453.099121 13.128106 4364.430176", 97.0, -10.0, 0.0, false );
                m_bastionCCTV.AddCamera( "TownSquare2", "4579.270020 18.050175 4183.352051", 90.0, -10.0, 0.0, false );

                JsonFileLoader<array<ref CCTVCamera>>.JsonSaveFile( BastionCCTVConst.config, m_bastionCCTV.m_cameras );
            }
            foreach( auto camera : m_bastionCCTV.m_cameras )
            {
				vector dir = vector.Zero;
				dir[0] = camera.GetStartingAngle();
				CreateSpecificObject( "BRP_DOME_CCTV", camera.GetPosition(), dir );
            }

            array<ref CCTVMonitor> monitors = new array<ref CCTVMonitor>;

            if ( FileExist( BastionCCTVConst.monitors ) ) {
                JsonFileLoader<array<ref CCTVMonitor>>.JsonLoadFile( BastionCCTVConst.monitors, monitors );
            } else {
                monitors.Insert( new CCTVMonitor( "4443.448730 14.239664 4719.937988", 29.0, 0.0, 0.0 ) );
                JsonFileLoader<array<ref CCTVMonitor>>.JsonSaveFile( BastionCCTVConst.monitors, monitors );
            }
            foreach( auto monitor : monitors )
            {
				CreateSpecificObject( "BRP_CCTV", monitor.GetPosition(), monitor.GetDirection() );
            }
        }
    }
}