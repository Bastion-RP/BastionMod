modded class JMAnimRegister
{
	override void RegisterFireArms( DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior )
    {
        super.RegisterFireArms( pType, pBehavior );
              
		pType.AddItemInHandsProfileIK("BRP_R700_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_winchester70.asi", pBehavior, "dz/anims/anm/player/ik/weapons/winchester70.anm", "dz/anims/anm/player/reloads/Winchester70/w_winchester70_states.anm");
 		pType.AddItemInHandsProfileIK("BRP_CSSMG9_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_m4a1.asi", pBehavior, "dz/anims/anm/player/ik/weapons/m4a1_ik.anm", "dz/anims/anm/player/reloads/M4A1/w_M4A1_states.anm");
  		pType.AddItemInHandsProfileIK("BRP_SCARH_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_fnfal.asi", pBehavior, "dz/anims/anm/player/ik/weapons/fn_fal.anm", "dz/anims/anm/player/reloads/FNFal/w_FNFal_states.anm");
		pType.AddItemInHandsProfileIK("BRP_ACR_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_ump45.asi", pBehavior, "dz/anims/anm/player/ik/weapons/ump.anm","dz/anims/anm/player/reloads/UMP45/w_UMP45_states.anm");
		pType.AddItemInHandsProfileIK("BRP_MP5SD_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_ump45.asi", pBehavior, "dz/anims/anm/player/ik/weapons/ump.anm","dz/anims/anm/player/reloads/UMP45/w_UMP45_states.anm");
		pType.AddItemInHandsProfileIK("BRP_AR15Hunting_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_ruger1022.asi", pBehavior, "dz/anims/anm/player/ik/weapons/ruger1022.anm", "dz/anims/anm/player/reloads/ruger1022/w_Ruger1022_states.anm");
		pType.AddItemInHandsProfileIK("BRP_CS12G_Base", "BastionMod/BastionGuns/Beneillim/massautoshotty.asi", pBehavior, "dz/anims/anm/player/ik/weapons/mp133.anm", "dz/anims/anm/player/reloads/MP133/w_mp133_states.anm");
		pType.AddItemInHandsProfileIK("BRP_AK15_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_akm.asi", pBehavior, "dz/anims/anm/player/ik/weapons/akm.anm", "dz/anims/anm/player/reloads/AKM/w_akm_states.anm");
		pType.AddItemInHandsProfileIK("BRP_Vector_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_mp5.asi", pBehavior, "dz/anims/anm/player/ik/weapons/mp5k.anm","dz/anims/anm/player/reloads/mp5/w_mp5k_states.anm");

	}
   
    override void RegisterOneHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
    	super.RegisterOneHanded(pType, pBehavior);
    	pBehavior.SetToolsOneHanded();
		
		pType.AddItemInHandsProfileIK("BRP_Mag_CSSMG9_30Rnd", "dz/anims/workspaces/player/player_main/props/player_main_mp5k_mag.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_mp5_30rnd.anm");
		pType.AddItemInHandsProfileIK("BRP_Mag_M9A3_17rnd", "dz/anims/workspaces/player/player_main/props/player_main_fnp45_mag.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_fnp45.anm");
		pType.AddItemInHandsProfileIK("BRP_Mag_G18_17rnd", "dz/anims/workspaces/player/player_main/props/player_main_fnp45_mag.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_glock19_15rnd.anm");
		pType.AddItemInHandsProfileIK("BRP_Mag_PB_8Rnd", "dz/anims/workspaces/player/player_main/props/player_main_fnp45_mag.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_ij70.anm");
		pType.AddItemInHandsProfileIK("Ammo_Taser", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/ammunition/22_LooseRounds.anm");
		pType.AddItemInHandsProfileIK("BRP_Mag_CSSMG45_30Rnd", "dz/anims/workspaces/player/player_main/props/player_main_mp5k_mag.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_mp5_30rnd.anm");
		pType.AddItemInHandsProfileIK("BRP_Mag_CSP9_17Rnd", "dz/anims/workspaces/player/player_main/props/player_main_fnp45_mag.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_fnp45.anm");
		pType.AddItemInHandsProfileIK("BRP_Mag_CSP45_17Rnd", "dz/anims/workspaces/player/player_main/props/player_main_fnp45_mag.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_fnp45.anm");
		pType.AddItemInHandsProfileIK("BRP_Mag_PX4_20Rnd", "dz/anims/workspaces/player/player_main/props/player_main_fnp45_mag.asi", pBehavior,	"dz/anims/anm/player/ik/attachments/magazines/magazine_fnp45.anm");
		pType.AddItemInHandsProfileIK("BRP_Mag_BrowningHP_13rnd", "dz/anims/workspaces/player/player_main/props/player_main_fnp45_mag.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_glock19_15rnd.anm");
		pType.AddItemInHandsProfileIK("BRP_Mag_BerettaM9_15rnd", "dz/anims/workspaces/player/player_main/props/player_main_fnp45_mag.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_glock19_15rnd.anm");
		pType.AddItemInHandsProfileIK("BRP_Mag_P99_15rnd", "dz/anims/workspaces/player/player_main/props/player_main_fnp45_mag.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_glock19_15rnd.anm");
		pType.AddItemInHandsProfileIK("BRP_Mag_Vector_33rnd", "dz/anims/workspaces/player/player_main/props/player_main_mp5k_mag.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_cz61_20rnd.anm");
		pType.AddItemInHandsProfileIK("BRP_Vector_Suppressor", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/attachments/muzzle/suppressor_556.anm");		

	}
	
 	override void OnRegisterPistol( DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior )
	{
        super.OnRegisterPistol( pType, pBehavior );    
		
		pType.AddItemInHandsProfileIK("BRP_M9A3_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_fnp45.asi", pBehavior, "dz/anims/anm/player/ik/weapons/fnp45.anm", "dz/anims/anm/player/reloads/FNP45/w_fnp45_states.anm");
		pType.AddItemInHandsProfileIK("BRP_G18_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_glock.asi", pBehavior, "dz/anims/anm/player/ik/weapons/Glock19.anm", "dz/anims/anm/player/reloads/Glock/w_Glock19_states.anm");
		pType.AddItemInHandsProfileIK("BRP_PB_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_ij70.asi", pBehavior, "dz/anims/anm/player/ik/weapons/ij70.anm", "dz/anims/anm/player/reloads/IJ70/w_IJ70_states.anm");
		pType.AddItemInHandsProfileIK("BRP_Taser_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_cz75.asi", pBehavior, "dz/anims/anm/player/ik/weapons/CZ75.anm", "dz/anims/anm/player/reloads/CZ75/w_CZ75_states.anm");
		pType.AddItemInHandsProfileIK("BRP_BrowningHP_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_fnp45.asi", pBehavior, "dz/anims/anm/player/ik/weapons/fnp45.anm", "dz/anims/anm/player/reloads/FNP45/w_fnp45_states.anm");
		pType.AddItemInHandsProfileIK("CSP9_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_cz75.asi", pBehavior, "dz/anims/anm/player/ik/weapons/CZ75.anm", "dz/anims/anm/player/reloads/CZ75/w_CZ75_states.anm");
		pType.AddItemInHandsProfileIK("BRP_BerettaM9", "dz/anims/workspaces/player/player_main/weapons/player_main_cz75.asi", pBehavior, "dz/anims/anm/player/ik/weapons/CZ75.anm", "dz/anims/anm/player/reloads/CZ75/w_CZ75_states.anm");
		pType.AddItemInHandsProfileIK("BRP_P99", "dz/anims/workspaces/player/player_main/weapons/player_main_cz75.asi", pBehavior, "dz/anims/anm/player/ik/weapons/CZ75.anm", "dz/anims/anm/player/reloads/CZ75/w_CZ75_states.anm");

	}   	
};