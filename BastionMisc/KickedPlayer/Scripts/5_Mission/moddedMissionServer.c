modded class MissionServer extends MissionBase
{
	ref map<string, vector> 		analizePlayer;
	ref map<string, int> 			warningPlayer;
	ref BRP_KickedPlayerConfigData 	kickedPlayerConfigData;

	void MissionServer()
	{
		analizePlayer = new map<string, vector>;
		warningPlayer = new map<string, int>;
		BRP_KickedPlayerConfig brpKickedConfig = new BRP_KickedPlayerConfig();
		kickedPlayerConfigData = brpKickedConfig.GetConfig();

		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(this.AnalizeInactivPlayer, 60 * 1000, true);
	}

	void ~MissionServer()
	{
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).Remove(this.AnalizeInactivPlayer);
	}
	
	void AnalizeInactivPlayer()
	{
		ref array<Man> players = new array<Man>;
		GetGame().GetPlayers( players );
		for ( int i = 0; i < players.Count(); i++ )
		{
			PlayerBase player;
			Class.CastTo(player, players.Get(i));
			if( player )
			{
				if(analizePlayer.Contains(player.GetIdentity().GetPlainId()))
				{
					vector currentPos = player.GetPosition();
					vector lastPos = analizePlayer.Get(player.GetIdentity().GetPlainId());
					if(currentPos == lastPos)
					{
						if(warningPlayer.Contains(player.GetIdentity().GetPlainId()))
						{
							int countWarning = warningPlayer.Get(player.GetIdentity().GetPlainId());
							countWarning++;
							if(countWarning >= kickedPlayerConfigData.InActiveTimeToKick)
							{
								Param1<string> m_MesParam = new Param1<string>("You have not been active for "+ kickedPlayerConfigData.InActiveTimeToKick +" minutes.");
								GetGame().RPCSingleParam(player, BRP_KickPlayer_RPC.SendKickPlayer, m_MesParam, true, player.GetIdentity()); 
								warningPlayer.Remove(player.GetIdentity().GetPlainId());
							}
							else
							{
								warningPlayer.Remove(player.GetIdentity().GetPlainId());
								warningPlayer.Insert(player.GetIdentity().GetPlainId(), countWarning);
							}
						}
						else
						{
							warningPlayer.Insert(player.GetIdentity().GetPlainId(), 1);
						}
					}
					else
					{
						if(warningPlayer.Contains(player.GetIdentity().GetPlainId()))
							warningPlayer.Remove(player.GetIdentity().GetPlainId());

					}
					analizePlayer.Remove(player.GetIdentity().GetPlainId());
					analizePlayer.Insert(player.GetIdentity().GetPlainId(), player.GetPosition());
				}
				else
				{
					analizePlayer.Insert(player.GetIdentity().GetPlainId(), player.GetPosition());
				}
			}
		}
	}
}