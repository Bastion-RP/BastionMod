modded class JMAnimRegister
{
    override void RegisterHeavy(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
    	super.RegisterHeavy(pType, pBehavior);
				
		pType.AddItemInHandsProfileIK("BRP_ChessDeck", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", pBehavior, "dz/anims/anm/player/ik/heavy/wooden_crate.anm");	
    }
	override void RegisterOneHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
	{
    	super.RegisterOneHanded(pType, pBehavior);
		  
		pType.AddItemInHandsProfileIK("BRP_ChessPiece_Base", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/ammunition/357_LooseRounds.anm");

	}	
};