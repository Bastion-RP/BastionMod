class BastionCCTV
{
    Camera m_camera;
	autoptr TStringVectorMap m_CCTVUsers = new TStringVectorMap;

    void BastionCCTV() {
        Print("[CCTV]: Initialized CCTV RPCs");
        GetRPCManager().AddRPC( "BastionCCTV", "EnterCCTV",              this, SingeplayerExecutionType.Client );
        GetRPCManager().AddRPC( "BastionCCTV", "LeaveCCTV",              this, SingeplayerExecutionType.Client );
        GetRPCManager().AddRPC( "BastionCCTV", "SwitchCCTV",             this, SingeplayerExecutionType.Client );
        GetRPCManager().AddRPC( "BastionCCTV", "PlayerToCameraPosition", this, SingeplayerExecutionType.Client );
    }

    void EnterCCTV( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target ) {
        Param2<vector, int> data;
        if ( !ctx.Read( data ) ) return;

        if( type == CallType.Server ) {
            Print("[CCTV]: EnterCCTV on Server");

            m_CCTVUsers.Set( sender.GetId(), target.GetPosition() );
            
            GetGame().SelectPlayer( sender, NULL );
            GetGame().SelectSpectator( sender, "BastionCCTVCam", data.param1 );

            GetRPCManager().SendRPC( "BastionCCTV", "EnterCCTV", data, true, sender, target );
        } else if ( type == CallType.Client ) {
            Print("[CCTV]: EnterCCTV on Client");

            m_camera = BastionCCTVCam.Cast( Camera.GetCurrentCamera() );
            
            auto newOrientation = m_camera.GetOrientation();
            newOrientation[0] = data.param2;
		    m_camera.SetOrientation( newOrientation );

            auto camPosition = m_camera.GetPosition();
            dBodyEnableGravity( PlayerBase.Cast( target ), false );
            GetRPCManager().SendRPC( "BastionCCTV", "PlayerToCameraPosition", new Param1<vector>( camPosition ), true, NULL, target );
            GetGame().UpdateSpectatorPosition( camPosition );
            
            if ( m_camera ) {
                m_camera.SetActive( true );
                if ( GetPlayer() ) {
                    // GetPlayer().GetInputController().SetDisabled( true );
                }
            }
        }
    }

	void LeaveCCTV( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target ) {
		if ( type == CallType.Server ) {
            Print("[CCTV]: LeaveCCTV on Server");

            target.SetPosition( m_CCTVUsers.Get( sender.GetId() ) );
            m_CCTVUsers.Remove( sender.GetId() );

			GetGame().SelectPlayer( sender, target );
		    GetRPCManager().SendRPC( "BastionCCTV", "LeaveCCTV", new Param, true, sender, target );
		} else if ( type == CallType.Client ) {
            Print("[CCTV]: LeaveCCTV on Client");
			m_camera.SetActive( false );
			m_camera = NULL;
			
			PPEffects.ResetDOFOverride();

			if ( GetPlayer() ) {
				// GetPlayer().GetInputController().SetDisabled( false );
			}
		}
	}

    void SwitchCCTV( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target ) {
        Param2<vector, int> data;
        if ( !ctx.Read( data ) ) return;

        if( type == CallType.Server ) {
            Print("[CCTV]: SwitchCCTV on Server");
            
		    // GetRPCManager().SendRPC( "BastionCCTV", "LeaveCCTV", new Param, true, sender, target );

            GetGame().SelectSpectator( sender, "BastionCCTVCam", data.param1 );
            
            // GetRPCManager().SendRPC( "BastionCCTV", "EnterCCTV", data, true, sender, target );
            GetRPCManager().SendRPC( "BastionCCTV", "SwitchCCTV", data, true, sender, target );
        } else if ( type == CallType.Client ) {
            m_camera = BastionCCTVCam.Cast( Camera.GetCurrentCamera() );

            auto newOrientation = m_camera.GetOrientation();
            newOrientation[0] = data.param2;
		    m_camera.SetOrientation( newOrientation );

            auto camPosition = m_camera.GetPosition();
            dBodyEnableGravity( PlayerBase.Cast( target ), false );
            GetRPCManager().SendRPC( "BastionCCTV", "PlayerToCameraPosition", new Param1<vector>( camPosition ), true, NULL, target );
            GetGame().UpdateSpectatorPosition( camPosition );
            
            if ( m_camera ) {
                m_camera.SetActive( true );
                if ( GetPlayer() ) {
                    // GetPlayer().GetInputController().SetDisabled( true );
                }
            }
        }
    }

    void PlayerToCameraPosition( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target ) {
        Param2<vector, int> data;
        if ( !ctx.Read( data ) ) return;
        Print("[CCTV]: PlayerToCameraPosition on Server1");

        if ( m_CCTVUsers.Contains( sender.GetId() ) ) {
        Print("[CCTV]: PlayerToCameraPosition on Server 2");
            auto position = data.param1;
            auto player = PlayerBase.Cast(target);

            position[1] = GetGame().SurfaceY(position[0], position[2]) - 3;
            
            dBodyEnableGravity(player, false);

            player.SetPosition( position );
        }
    }
};