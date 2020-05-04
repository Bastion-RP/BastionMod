modded class PlayerBase
{
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

            GetDayZPlayerType().AddItemInHandsProfileIK("BRP_ISF_CarrierRig", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_extinguisher.asi", twoHanded, "dz/anims/anm/player/ik/two_handed/vest_ballistic.anm");
        }
        super.Init();
    }
};