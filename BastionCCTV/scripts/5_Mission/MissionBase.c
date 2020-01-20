modded class MissionGameplay {
    private autoptr BastionCCTV m_bastionCCTV;

    void MissionGameplay() {
        m_bastionCCTV = new BastionCCTV();
    }

    override void OnKeyPress( int key ) {
        super.OnKeyPress( key );

        BastionCCTVMenu menu = BastionCCTVMenu.Cast(GetUIManager().GetMenu());
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
        foreach( auto camera : m_bastionCCTV.m_cameras ) {
            auto data = new Param5<vector, int, int, int, bool>( camera.GetPosition(), camera.GetStartingAngle(), camera.GetPitch(), camera.GetRoll(), camera.GetCanRotate() );
            GetRPCManager().SendRPC( "BastionCCTV", "ReceiveCameraData", data, true, identity );
        }
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
                m_bastionCCTV.AddCamera( "5025.65 20 2363.44", 0, 0, 0, true );
                m_bastionCCTV.AddCamera( "6025.65 250 4363.44", 270, -20, 0, false );
                m_bastionCCTV.AddCamera( "6018.26 300 10256.4", 270, -10, 0, true );

                JsonFileLoader<array<ref CCTVCamera>>.JsonSaveFile( BastionCCTVConst.config, m_bastionCCTV.m_cameras );
            }
        }
    }
}