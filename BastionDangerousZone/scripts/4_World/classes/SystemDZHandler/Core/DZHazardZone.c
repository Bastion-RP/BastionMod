class DZHazardZone extends DZManager
{
	private House m_Particle;
	private int m_CheckScheduler;

	void DZHazardZone()
	{
		if ( GetGame().IsServer() ) {
			GetDZLogger().LogInfo("DZHazardZone - Started !");
			StartParticleEffect();
			GetGame().GetMission().MissionScript.Call( this, "CheckScheduler", null );
		}
	}

	void StartParticleEffect()
	{
		for( int i=0;i<GetHazardConfig().HazardAreaLocation.Count();i++)
		{
			HazardZoneLocation HazArea = GetHazardConfig().HazardAreaLocation.Get(i);

			for (int k=0;k<HazArea.ParticlesPosition.Count();k++)
			{
				m_Particle = House.Cast(GetGame().CreateObject(HazArea.ParticlesPosition.Get(k).NName,HazArea.ParticlesPosition.Get(k).PPos));
			}
		}
	}

	void CheckScheduler()
	{
		m_CheckScheduler = GetHazardConfig().HazardCheck;
		while(1)
		{
			array<Man> m_Players = new array<Man>;
			GetGame().GetPlayers(m_Players);
			for(int i = 0; i < m_Players.Count(); i++)
			{
				PlayerBase player;
				Class.CastTo(player, m_Players.Get(i));
				for (int k=0;k<GetHazardConfig().HazardAreaLocation.Count();k++)
				{
					private HazardZoneLocation m_ActiveHazardAreaLocation = GetHazardConfig().HazardAreaLocation.Get(k);
					if( m_ActiveHazardAreaLocation.IsSquareZone == 0){
						HazardZoneRound(m_ActiveHazardAreaLocation.X,m_ActiveHazardAreaLocation.Y,m_ActiveHazardAreaLocation.Radius,m_ActiveHazardAreaLocation.HazardZoneStatut,player);
					}
					else{
						HazardZoneSquare(m_ActiveHazardAreaLocation.X1,m_ActiveHazardAreaLocation.Y1,m_ActiveHazardAreaLocation.X2,m_ActiveHazardAreaLocation.Y2,m_ActiveHazardAreaLocation.HazardZoneStatut,player);
					}
				}
			}
			Sleep(m_CheckScheduler);
		}
	}

	void HazardZoneRound(float m_X, float m_Y, float Zone_Radius,string Status,PlayerBase player)
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
				player.IsHazardProtected();
				return;
			}
			else
			{
				player.IsInside.DZName=Status;
				player.IsInside.DZStatut=true;
				player.IsInside.DZType=3;
				#ifdef DZDEBUG
				GetDZLogger().LogInfo(player.GetIdentity().GetName() + "is entering :" + player.IsInside.DZStatut.ToString());
				#endif
				if(player.IsHazarded==true)return;
				player.GasMaskHazardCheck();
				if(GetHazardConfig().IsMsgActive==0)return;
				NotificationSystem.SendNotificationToPlayerIdentityExtended(player.GetIdentity(), 5, "Hazard Zone", GetHazardConfig().MsgEnterZone, "BastionMod/BastionDangerousZone/images/HazardLogo.paa");
			}
		}
		else if ( distance_squared > Math.Pow(Zone_Radius, 2) )
		{
			if (player.IsInside.DZName==Status && player.IsInside.DZStatut)
			{
				player.IsInside.DZStatut=false;
				player.IsInside.DZName="";
				player.IsInside.DZType=0;
				#ifdef DZDEBUG
				GetDZLogger().LogInfo(player.GetIdentity().GetName() + "is leaving :" + player.IsInside.DZStatut.ToString());
				#endif
				if(GetHazardConfig().IsMsgActive==0)return;
				NotificationSystem.SendNotificationToPlayerIdentityExtended(player.GetIdentity(), 5, "Hazard Zone", GetHazardConfig().MsgExitZone, "BastionMod/BastionDangerousZone/images/HazardLogo.paa");
			}
			else
			{
				return;
			}
		}
	}

	void HazardZoneSquare(float m_X1, float m_Y1, float m_X2, float m_Y2,string Status,PlayerBase player)
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
				player.IsHazardProtected();
				return;
			}
			else
			{
				#ifdef DZDEBUG
				GetDZLogger().LogInfo(player.GetIdentity().GetName() + "is entering :" + player.IsInside.DZStatut.ToString());
				#endif
				player.IsInside.DZName=Status;
				player.IsInside.DZStatut=true;
				player.IsInside.DZType=3;
				if(player.IsHazarded==true)return;
				player.GasMaskHazardCheck();
				if(GetHazardConfig().IsMsgActive==0)return;
				NotificationSystem.SendNotificationToPlayerIdentityExtended(player.GetIdentity(), 5, "Hazard Zone", GetHazardConfig().MsgEnterZone, "BastionMod/BastionDangrousZone/images/HazardLogo.paa");
			}
		}
		else
		{
			if (player.IsInside.DZName==Status && player.IsInside.DZStatut)
			{
				#ifdef DZDEBUG
				GetDZLogger().LogInfo(player.GetIdentity().GetName() + "is leaving :" + player.IsInside.DZStatut.ToString());
				#endif
				player.IsInside.DZStatut=false;
				player.IsInside.DZName="";
				player.IsInside.DZType=0;
				if(GetHazardConfig().IsMsgActive==0)return;
				NotificationSystem.SendNotificationToPlayerIdentityExtended(player.GetIdentity(), 5, "Hazard Zone", GetHazardConfig().MsgExitZone, "BastionMod/BastionDangerousZone/images/HazardLogo.paa");
			}
			else
			{
				return;
			}
		}
	}
}
