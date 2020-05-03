modded class PlayerBase extends ManBase
{
    override void Init()
    {
        if ( !GetGame().IsServer() || !GetGame().IsMultiplayer() ) 
        {
			DayzPlayerItemBehaviorCfg toolsOneHanded = new DayzPlayerItemBehaviorCfg;
			toolsOneHanded.SetToolsOneHanded();
			
			GetDayZPlayerType().AddItemInHandsProfileIK("BRP_CopperCoin", "dz/anims/workspaces/player/player_main/player_main_1h.asi", toolsOneHanded, "dz/anims/anm/player/ik/ammunition/22_LooseRounds.anm");
			GetDayZPlayerType().AddItemInHandsProfileIK("BRP_SilverCoin", "dz/anims/workspaces/player/player_main/player_main_1h.asi", toolsOneHanded, "dz/anims/anm/player/ik/ammunition/22_LooseRounds.anm");
			GetDayZPlayerType().AddItemInHandsProfileIK("BRP_GoldCoin", "dz/anims/workspaces/player/player_main/player_main_1h.asi", toolsOneHanded, "dz/anims/anm/player/ik/ammunition/22_LooseRounds.anm");
		}
        super.Init();
    }
};