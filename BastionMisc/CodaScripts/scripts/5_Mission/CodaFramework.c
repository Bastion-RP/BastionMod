
class CodaFramework
{
	void CodaFramework()
    {        
        GetRPCManager().AddRPC( "CodaFramework", "UpdatePlayerHealthState",         this, SingeplayerExecutionType.Client );
        GetRPCManager().AddRPC( "CodaFramework", "Symptom",                         this, SingeplayerExecutionType.Client );
	}

	static PlayerBase GetPlayerById (int playerId) 
    {
		array<Man> players = new array<Man>;
		PlayerBase player;

		if (GetGame().IsMultiplayer()) 
        {
			GetGame().GetPlayers(players);

			for (int i = 0; i < players.Count(); i++) 
            {
				if (players.Get(i).GetIdentity().GetPlayerId() == playerId) 
                {
					player = PlayerBase.Cast(players.Get(i));
				}
			}
		} 
        else 
        {
			player = PlayerBase.Cast(GetGame().GetPlayer());
		}

		return player;
	}
    
	void UpdatePlayerHealthState( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target ) 
    {
        Param2< int, eInjuryHandlerLevels > data;
        if ( !ctx.Read( data ) ) return;

        PlayerBase player = PlayerBase.Cast( GetPlayerById(data.param1) );
        eInjuryHandlerLevels injury_level = data.param2;

        float health_current_normalized = player.GetHealth("","Health") / player.GetMaxHealth("", "Health");
        
        if ( injury_level == eInjuryHandlerLevels.PRISTINE ) 
        {  
            player.ForceUpdateInjuredState();
        } 

        else if ( player.m_InjuryHandler.GetInjuryLevel(health_current_normalized) <= injury_level ) 
        {
            player.GetCommandModifier_Additives().SetInjured( player.m_InjuryHandler.GetInjuryValue(injury_level), false );
            
            player.m_InjuryHandler.SendValue( injury_level );
            player.m_InjuryHandler.m_ChangedStateInvoker.Invoke( injury_level );
            player.m_InjuryHandler.Synchronize( injury_level );
        }
	}
	
	void Symptom( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target ) 
    {
        Param2< int, eInjuryHandlerLevels > data;
        if ( !ctx.Read( data ) ) return;

        PlayerBase player = PlayerBase.Cast( GetPlayerById(data.param1) );
        SymptomIDs symptom = data.param2;

        if (symptom == SymptomIDs.SYMPTOM_UNCONSCIOUS) 
        {
            player.SetHealth("", "Shock", 0);
            return;
        }

        if ( !player.GetCommand_Vehicle() ) 
        {
			player.GetSymptomManager().QueueUpPrimarySymptom( symptom );
		}
	}
}