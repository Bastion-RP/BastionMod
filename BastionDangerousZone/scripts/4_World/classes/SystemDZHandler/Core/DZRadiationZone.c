class DZRadiationZone extends DZManager
{
	private int m_CheckScheduler;

	void DZRadiationZone()
	{
		if ( GetGame().IsServer() ) {
			GetDZLogger().LogInfo("DZRadiationZone - Started !");
			GetGame().GetMission().MissionScript.Call( this, "CheckScheduler", null );
		}
	}

	void CheckScheduler()
	{
		m_CheckScheduler = GetRadConfig().RadCheck;
		while(1)
		{
			array<Man> m_Players = new array<Man>;
			GetGame().GetPlayers(m_Players);
			for(int i = 0; i < m_Players.Count(); i++)
			{
				PlayerBase player;
				Class.CastTo(player, m_Players.Get(i));
				for (int k=0;k<GetRadConfig().RadiationAreaLocation.Count();k++)
				{
					private RadiationZoneLocation m_ActiveRadiationAreaLocation = GetRadConfig().RadiationAreaLocation.Get(k);
					if( m_ActiveRadiationAreaLocation.IsSquareZone == 0){
						if(m_ActiveRadiationAreaLocation.Level == 1)
						{
							HighLevelRadiationZoneRound(m_ActiveRadiationAreaLocation.X,m_ActiveRadiationAreaLocation.Y,m_ActiveRadiationAreaLocation.Radius,m_ActiveRadiationAreaLocation.RadiationZoneStatut,player);
						}
						else LowLevelRadiationZoneRound(m_ActiveRadiationAreaLocation.X,m_ActiveRadiationAreaLocation.Y,m_ActiveRadiationAreaLocation.Radius,m_ActiveRadiationAreaLocation.RadiationZoneStatut,player);
					}
					else{
						if(m_ActiveRadiationAreaLocation.Level == 1)
						{
							HighLevelRadiationZoneSquare(m_ActiveRadiationAreaLocation.X1,m_ActiveRadiationAreaLocation.Y1,m_ActiveRadiationAreaLocation.X2,m_ActiveRadiationAreaLocation.Y2,m_ActiveRadiationAreaLocation.RadiationZoneStatut,player);
						}else LowLevelRadiationZoneSquare(m_ActiveRadiationAreaLocation.X1,m_ActiveRadiationAreaLocation.Y1,m_ActiveRadiationAreaLocation.X2,m_ActiveRadiationAreaLocation.Y2,m_ActiveRadiationAreaLocation.RadiationZoneStatut,player);
					}
				}
			}
			Sleep(m_CheckScheduler);
		}
	}

	void HighLevelRadiationZoneRound(float m_X, float m_Y, float Zone_Radius,string Status,PlayerBase player)
	{
		string ZoneCheck;
		vector pos = player.GetPosition();
		float distance_squared = Math.Pow(m_X-pos[0], 2) + Math.Pow(m_Y-pos[2], 2);
		if ( distance_squared <= Math.Pow(Zone_Radius, 2) )
		{
			if (player.IsInside.DZName==Status && player.IsInside.DZStatut) //Already in zone
			{
				#ifdef DZDEBUG
				GetDZLogger().LogInfo(player.GetIdentity().GetName() + "is inside :" + player.IsInside.DZStatut.ToString());
				#endif
				player.IsRadProtected(player.IsInside.DZType);
				return;
			}
			else
			{
				//GetDZLogger().LogInfo("ELSE1:" + player.IsInside.DZName + player.IsInside.DZStatut.ToString());
				player.IsInside.DZName=Status;
				player.IsInside.DZStatut=true;
				player.IsInside.DZType=2;
				player.HighLevelRadiationCheck();
				#ifdef DZDEBUG
				GetDZLogger().LogInfo(player.GetIdentity().GetName() + "is entering :" + player.IsInside.DZStatut.ToString());
				#endif
				if(GetRadConfig().IsMsgActive==0)return;
				NotificationSystem.SendNotificationToPlayerIdentityExtended(player.GetIdentity(), 5, "Radiation Zone", GetRadConfig().MsgEnterZone, "BastionMod/BastionDangerousZone/images/radiation.paa");
			}
		}
		else if ( distance_squared > Math.Pow(Zone_Radius, 2) )
		{
			if (player.IsInside.DZName==Status && player.IsInside.DZStatut)
			{
				//GetDZLogger().LogInfo("IF2:" + player.IsInside.DZName + player.IsInside.DZStatut.ToString());
				player.IsInside.DZStatut=false;
				player.IsInside.DZName="";
				player.IsInside.DZType=0;
				#ifdef DZDEBUG
				GetDZLogger().LogInfo(player.GetIdentity().GetName() + "is leaving :" + player.IsInside.DZStatut.ToString());
				#endif
				if(GetRadConfig().IsMsgActive==0)return;
				NotificationSystem.SendNotificationToPlayerIdentityExtended(player.GetIdentity(), 5, "Radiation Zone", GetRadConfig().MsgExitZone, "BastionMod/BastionDangerousZone/images/radiation.paa");
			}
			else
			{
				//GetDZLogger().LogInfo("ELSE2:" + player.IsInside.DZName + player.IsInside.DZStatut.ToString());
				return;
			}
		}
	}

	private void SendMessageClient(PlayerBase player, string message)
	{
		Param1<string> m_MesParam = new Param1<string>(message);
		GetGame().RPCSingleParam(player, ERPCs.RPC_USER_ACTION_MESSAGE, m_MesParam, true, player.GetIdentity());
	}

	void 	HighLevelRadiationZoneSquare(float m_X1, float m_Y1, float m_X2, float m_Y2,string Status,PlayerBase player)
	{
		string ZoneCheck;
		vector pos = player.GetPosition();
		if ( (pos[0]>m_X1 && pos[0]<m_X2) && (pos[2]>m_Y1 && pos[2]<m_Y2) )
		{
			if (player.IsInside.DZName==Status && player.IsInside.DZStatut) //Already in zone
			{
				#ifdef DZDEBUG
				GetDZLogger().LogInfo(player.GetIdentity().GetName() + "is inside :" + player.IsInside.DZStatut.ToString());
				#endif
				player.IsRadProtected(player.IsInside.DZType);
				return;
			}
			else
			{
				//GetDZLogger().LogInfo("ELSE1:" + player.IsInside.DZName + player.IsInside.DZStatut.ToString());
				player.IsInside.DZName=Status;
				player.IsInside.DZStatut=true;
				player.IsInside.DZType=2;
				player.HighLevelRadiationCheck();
				#ifdef DZDEBUG
				GetDZLogger().LogInfo(player.GetIdentity().GetName() + "is entering :" + player.IsInside.DZStatut.ToString());
				#endif
				if(GetRadConfig().IsMsgActive==0)return;
				NotificationSystem.SendNotificationToPlayerIdentityExtended(player.GetIdentity(), 5, "Radiation Zone", GetRadConfig().MsgEnterZone, "BastionMod/BastionDangerousZone/images/radiation.paa");
			}
		}
		else
		{
			if (player.IsInside.DZName==Status && player.IsInside.DZStatut)
			{
				//GetDZLogger().LogInfo("IF2:" + player.IsInside.DZName + player.IsInside.DZStatut.ToString());
				player.IsInside.DZStatut=false;
				player.IsInside.DZName="";
				player.IsInside.DZType=0;
				#ifdef DZDEBUG
				GetDZLogger().LogInfo(player.GetIdentity().GetName() + "is leaving :" + player.IsInside.DZStatut.ToString());
				#endif
				if(GetRadConfig().IsMsgActive==0)return;
				NotificationSystem.SendNotificationToPlayerIdentityExtended(player.GetIdentity(), 5, "Radiation Zone", GetRadConfig().MsgExitZone, "BastionMod/BastionDangerousZone/images/radiation.paa");
			}
			else
			{
				return;
			}
		}
	}

	void LowLevelRadiationZoneRound(float m_X, float m_Y, float Zone_Radius,string Status,PlayerBase player)
	{
		string ZoneCheck;
		vector pos = player.GetPosition();
		float distance_squared = Math.Pow(m_X-pos[0], 2) + Math.Pow(m_Y-pos[2], 2);
		if ( distance_squared <= Math.Pow(Zone_Radius, 2) )
		{
			if (player.IsInside.DZName==Status && player.IsInside.DZStatut) //Already in zone
			{
				#ifdef DZDEBUG
				GetDZLogger().LogInfo(player.GetIdentity().GetName() + "is inside :" + player.IsInside.DZStatut.ToString());
				#endif
				player.LowLevelRadiationCheckLite();
				return;
			}
			else
			{
				//GetDZLogger().LogInfo("ELSE1:" + player.IsInside.DZName + player.IsInside.DZStatut.ToString());
				player.IsInside.DZName=Status;
				player.IsInside.DZStatut=true;
				player.IsInside.DZType=1;
				player.LowLevelRadiationCheck();
				#ifdef DZDEBUG
				GetDZLogger().LogInfo(player.GetIdentity().GetName() + "is entering :" + player.IsInside.DZStatut.ToString());
				#endif
				if(GetRadConfig().IsMsgActive==0)return;
				NotificationSystem.SendNotificationToPlayerIdentityExtended(player.GetIdentity(), 5, "Radiation Zone", GetRadConfig().MsgEnterZone, "BastionMod/BastionDangerousZone/images/radiation.paa");
			}
		}
		else if ( distance_squared > Math.Pow(Zone_Radius, 2) )
		{
			if (player.IsInside.DZName==Status && player.IsInside.DZStatut)
			{
				//GetDZLogger().LogInfo("IF2:" + player.IsInside.DZName + player.IsInside.DZStatut.ToString());
				player.IsInside.DZStatut=false;
				player.IsInside.DZName="";
				player.IsInside.DZType=0;
				#ifdef DZDEBUG
				GetDZLogger().LogInfo(player.GetIdentity().GetName() + "is leaving :" + player.IsInside.DZStatut.ToString());
				#endif
				if(GetRadConfig().IsMsgActive==0)return;
				NotificationSystem.SendNotificationToPlayerIdentityExtended(player.GetIdentity(), 5, "Radiation Zone", GetRadConfig().MsgExitZone, "BastionMod/BastionDangerousZone/images/radiation.paa");
			}
			else
			{
				return;
			}
		}
	}

	void LowLevelRadiationZoneSquare(float m_X1, float m_Y1, float m_X2, float m_Y2,string Status,PlayerBase player)
	{
		string ZoneCheck;
		vector pos = player.GetPosition();
		if ( (pos[0]>m_X1 && pos[0]<m_X2) && (pos[2]>m_Y1 && pos[2]<m_Y2) )
		{
			if (player.IsInside.DZName==Status && player.IsInside.DZStatut) //Already in zone
			{
				#ifdef DZDEBUG
				GetDZLogger().LogInfo(player.GetIdentity().GetName() + "is inside :" + player.IsInside.DZStatut.ToString());
				#endif
				player.LowLevelRadiationCheckLite();
				return;
			}
			else
			{
				player.IsInside.DZName=Status;
				player.IsInside.DZStatut=true;
				player.IsInside.DZType=1;
				player.LowLevelRadiationCheck();
				#ifdef DZDEBUG
				GetDZLogger().LogInfo(player.GetIdentity().GetName() + "is entering :" + player.IsInside.DZStatut.ToString());
				#endif
				if(GetRadConfig().IsMsgActive==0)return;
				NotificationSystem.SendNotificationToPlayerIdentityExtended(player.GetIdentity(), 5, "Radiation Zone", GetRadConfig().MsgEnterZone, "BastionMod/BastionDangerousZone/images/radiation.paa");
			}
		}
		else
		{
			if (player.IsInside.DZName==Status && player.IsInside.DZStatut)
			{
				player.IsInside.DZStatut=false;
				player.IsInside.DZName="";
				player.IsInside.DZType=0;
				#ifdef DZDEBUG
				GetDZLogger().LogInfo(player.GetIdentity().GetName() + "is leaving :" + player.IsInside.DZStatut.ToString());
				#endif
				if(GetRadConfig().IsMsgActive==0)return;
				NotificationSystem.SendNotificationToPlayerIdentityExtended(player.GetIdentity(), 5, "Radiation Zone", GetRadConfig().MsgExitZone, "BastionMod/BastionDangerousZone/images/radiation.paa");
			}
			else
			{
				return;
			}
		}
	}
}
