class BastionCCTV
{
    Camera m_camera;
	static autoptr TStringVectorMap m_CCTVUsers = new TStringVectorMap;
    static autoptr array<ref CCTVCamera> m_cameras;

    void BastionCCTV() {
        m_cameras = new array<ref CCTVCamera>();

        GetRPCManager().AddRPC( "BastionCCTV", "EnterCCTV",              this, SingeplayerExecutionType.Client );
        GetRPCManager().AddRPC( "BastionCCTV", "LeaveCCTV",              this, SingeplayerExecutionType.Client );
        GetRPCManager().AddRPC( "BastionCCTV", "SwitchCCTV",             this, SingeplayerExecutionType.Client );
        GetRPCManager().AddRPC( "BastionCCTV", "PlayerToCameraPosition", this, SingeplayerExecutionType.Client );
        GetRPCManager().AddRPC( "BastionCCTV", "ReceiveCameraData",      this, SingeplayerExecutionType.Client );
        GetRPCManager().AddRPC( "BastionCCTV", "InitClientCameraData",   this, SingeplayerExecutionType.Client );
    }

    static void AddCamera( string name, vector position, float yaw, float pitch, float roll, bool canRotate ) {
        Print("##### AddCamera " + name);
        m_cameras.Insert( new CCTVCamera( name, position, yaw, pitch, roll, canRotate ) );
    }

    void InitClientCameraData( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target ) {
        Print("##### InitClientCameraData");
        if ( type == CallType.Client ) {
            if ( m_cameras.Count() == 0 ) {
                GetRPCManager().SendRPC( "BastionCCTV", "InitClientCameraData", NULL, true, NULL, target );
            }
        } else {
            foreach( auto camera : m_cameras ) {
                auto data = new Param6<string, vector, float, float, float, bool>( camera.GetName(), camera.GetPosition(), camera.GetStartingAngle(), camera.GetPitch(), camera.GetRoll(), camera.GetCanRotate() );
                GetRPCManager().SendRPC( "BastionCCTV", "ReceiveCameraData", data, true, sender );
            }
        }
    }

    void ReceiveCameraData( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target ) {
        Param6<string, vector, float, float, float, bool> data;
        if ( !ctx.Read( data ) ) return;

        Print("##### ReceiveCameraData " + data.param1);

        if ( type == CallType.Client ) {
            string name = data.param1;
            vector position = data.param2;
            float yaw = data.param3;
            float pitch = data.param4;
            float roll = data.param5;
            bool canRotate = data.param6;

            AddCamera( name, position, yaw, pitch, roll, canRotate );
        }
    }

	void LeaveCCTV( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target ) {
		if ( type == CallType.Server ) {
            target.SetPosition( m_CCTVUsers.Get( sender.GetId() ) );
            m_CCTVUsers.Remove( sender.GetId() );

			GetGame().SelectPlayer( sender, target );
            dBodyEnableGravity( PlayerBase.Cast( target ), true );
		    GetRPCManager().SendRPC( "BastionCCTV", "LeaveCCTV", new Param, true, sender, target );
		} else if ( type == CallType.Client ) {
			m_camera.SetActive( false );
			m_camera = NULL;
            dBodyEnableGravity( PlayerBase.Cast( target ), true );
		}
	}

    void SwitchCCTV( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target ) {
        Param2<vector, vector> data;
        if ( !ctx.Read( data ) ) return;

        if( type == CallType.Server ) {
            if ( !m_CCTVUsers.Contains( sender.GetId() ) ) {
                m_CCTVUsers.Set( sender.GetId(), target.GetPosition() );
                GetGame().SelectPlayer( sender, NULL );
            }

            GetGame().SelectSpectator( sender, "BastionCCTVCam", data.param1 );
            GetRPCManager().SendRPC( "BastionCCTV", "SwitchCCTV", data, true, sender, target );
        } else if ( type == CallType.Client ) {
            m_camera = BastionCCTVCam.Cast( Camera.GetCurrentCamera() );
		    m_camera.SetOrientation( data.param2 );

            auto camPosition = m_camera.GetPosition();
            dBodyEnableGravity( PlayerBase.Cast( target ), false );
            GetRPCManager().SendRPC( "BastionCCTV", "PlayerToCameraPosition", new Param1<vector>( camPosition ), true, NULL, target );
            GetGame().UpdateSpectatorPosition( camPosition );

            m_camera.SetActive( true );
        }
    }

    void PlayerToCameraPosition( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target ) {
        Param1<vector> data;
        if ( ctx.Read( data ) && m_CCTVUsers.Contains( sender.GetId() ) ) {
            auto position = data.param1;
            auto player = PlayerBase.Cast(target);

            position[1] = GetGame().SurfaceY(position[0], position[2]) - 3;
            
            dBodyEnableGravity(player, false);

            player.SetPosition( position );
        }
    }
};