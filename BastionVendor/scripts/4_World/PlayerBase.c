modded class PlayerBase
{
	bool Consume(ItemBase source, float amount, EConsumeType consume_type )
	{
		if ( source )
		{
      		string type = source.GetType();
      		type.ToLower();

      		if ( type == "BRP_AION" ) 
			{
				m_PlayerStomach.AddToStomach("BRP_AION", amount, 0 , Edible_Base.Cast(source).GetAgents() );
      		}
		}

		return super.Consume(source, amount, consume_type);
	}

	
    override void Init()
    {
        if ( !GetGame().IsServer() || !GetGame().IsMultiplayer() ) 
        {
            DayzPlayerItemBehaviorCfg toolsOneHanded = new DayzPlayerItemBehaviorCfg;
            toolsOneHanded.SetToolsOneHanded();

            DayzPlayerItemBehaviorCfg     twoHanded = new DayzPlayerItemBehaviorCfg;
            twoHanded.SetTwoHanded();

            DayzPlayerItemBehaviorCfg     fireArmsItemBehaviour = new DayzPlayerItemBehaviorCfg;
            fireArmsItemBehaviour.SetFirearms();

            DayzPlayerItemBehaviorCfg     heavyItemBehaviour = new DayzPlayerItemBehaviorCfg;
            heavyItemBehaviour.SetHeavyItems();            
            
            GetDayZPlayerType().AddItemInHandsProfileIK("BRP_AIONBox", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", heavyItemBehaviour, "dz/anims/anm/player/ik/heavy/wooden_crate.anm");
        }
        super.Init();
    }
};