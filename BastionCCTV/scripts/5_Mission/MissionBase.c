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
                m_bastionCCTV.AddCamera( "Bridge", "4539.593750 15.793251 4725.109375", 130.0, -5.0, 0.0, false );
                m_bastionCCTV.AddCamera( "FireStation1", "4851.897949 28.766982 4420.295410", 70.0, 0.0, 0.0, true );
                m_bastionCCTV.AddCamera( "FireStation2", "4843.640137 20.000047 4441.417480", -50.0, 0.0, 0.0, true );
                m_bastionCCTV.AddCamera( "Office1", "4785.000000 28.152763 4448.799805", -50.0, -20.0, 0.0, false );
                m_bastionCCTV.AddCamera( "Office2", "4714.375488 17.566299 4444.317871", 70.0, -5.0, 0.0, false );
                m_bastionCCTV.AddCamera( "BigApt1", "4831.299805 32.104875 4253.982910", -120.0, -20.0, 0.0, true );
                m_bastionCCTV.AddCamera( "GuardHouse", "4711.987305 13.944799 4357.939941", 90.0, -10.0, 0.0, true );
                m_bastionCCTV.AddCamera( "SmallApt2", "4793.169922 21.105083 4234.919922", 20.0, -10.0, 0.0, true );
                m_bastionCCTV.AddCamera( "Hotel", "4823.399902 29.600000 4179.799805", -85.0, -10.0, 0.0, true );
                m_bastionCCTV.AddCamera( "Store", "4721.689902 18.530797 4251.049805", 100.0, -10.0, 0.0, true );
                m_bastionCCTV.AddCamera( "TrainStation", "4860.500000 17.700000 4103.899902", 10.0, -10.0, 0.0, true );
                m_bastionCCTV.AddCamera( "Industrial1", "4535.219727 20.459999 4392.620117", -170.0, -10.0, 0.0, false );
                m_bastionCCTV.AddCamera( "TownSquare1", "4661.000000 24.650000 4232.299805", 100.0, -10.0, 0.0, true );
                m_bastionCCTV.AddCamera( "Industrial2", "4453.959961 13.350000 4364.799805", 95.0, -10.0, 0.0, false );
                m_bastionCCTV.AddCamera( "TownSquare2", "4579.399902 18.320000 4183.270020", 95.0, -10.0, 0.0, false );

                JsonFileLoader<array<ref CCTVCamera>>.JsonSaveFile( BastionCCTVConst.config, m_bastionCCTV.m_cameras );
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
                vector position = monitor.GetPosition();
                vector orientation = monitor.GetDirection();

                auto obj = GetGame().CreateObject( "BST_CCTV", position );
                obj.SetPosition( position );
                obj.SetOrientation( orientation );
                obj.SetOrientation( obj.GetOrientation() );
                obj.Update();
                obj.SetAffectPathgraph( true, false );
                if( obj.CanAffectPathgraph() ) GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( GetGame().UpdatePathgraphRegionByObject, 100, false, obj );
            }
        }
    }
}