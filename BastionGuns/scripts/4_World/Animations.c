modded class JMAnimRegister
{
	override void RegisterFireArms( DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior )
    {
        super.RegisterFireArms( pType, pBehavior );
              
		pType.AddItemInHandsProfileIK("BRP_R700_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_winchester70.asi", pBehavior, "dz/anims/anm/player/ik/weapons/winchester70.anm", "dz/anims/anm/player/reloads/Winchester70/w_winchester70_states.anm");
 		pType.AddItemInHandsProfileIK("BRP_CSSMG9_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_m4a1.asi", pBehavior, "dz/anims/anm/player/ik/weapons/m4a1_ik.anm", "dz/anims/anm/player/reloads/M4A1/w_M4A1_states.anm");

	}
   
     override void RegisterOneHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
    	super.RegisterOneHanded(pType, pBehavior);
    	pBehavior.SetToolsOneHanded();
		
		pType.AddItemInHandsProfileIK("BRP_Mag_CSSMG9_30Rnd", "dz/anims/workspaces/player/player_main/props/player_main_mp5k_mag.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_mp5_30rnd.anm");
	}
};