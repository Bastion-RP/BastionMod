modded class JMAnimRegister
{
    override void RegisterOneHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
    	super.RegisterOneHanded(pType, pBehavior);
    	pBehavior.SetToolsOneHanded();
		
		pType.AddItemInHandsProfileIK("BRP_LeatherWeaponBelt_ColorBase", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/battery_charger.anm");
		pType.AddItemInHandsProfileIK("BRP_riflesling_colorbase", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/camping/combinationlock.anm");
		pType.AddItemInHandsProfileIK("BRP_meleesling_colorbase", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/camping/combinationlock.anm");
		
    }	
	
    override void RegisterTwoHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
    	super.RegisterTwoHanded(pType, pBehavior);
    	pBehavior.SetTwoHanded();
		
 		pType.AddItemInHandsProfileIK("BRP_ISF_CarrierRig", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_extinguisher.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/vest_ballistic.anm"); 		
		pType.AddItemInHandsProfileIK("BRP_jaakari_Colorbase", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_extinguisher.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/mountain_g.anm");
		pType.AddItemInHandsProfileIK("BRP_bag_6B38_Colorbase", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_extinguisher.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/mountain_g.anm");
		pType.AddItemInHandsProfileIK("BRP_rifleholster_colorbase", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_extinguisher.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/mountain_g.anm");
		pType.AddItemInHandsProfileIK("BRP_carrierrig", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_extinguisher.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/mountain_g.anm");
		pType.AddItemInHandsProfileIK("BRP_Hikingbag_ColorBase", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_extinguisher.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/mountain_g.anm");
		pType.AddItemInHandsProfileIK("BRP_simplebackpack_ColorBase", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_extinguisher.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/mountain_g.anm");

    }	
};