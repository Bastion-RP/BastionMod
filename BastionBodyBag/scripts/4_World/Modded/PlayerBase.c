modded class PlayerBase
{
    override void Init()
    {
        DayzPlayerItemBehaviorCfg toolsOneHanded = new DayzPlayerItemBehaviorCfg;
        toolsOneHanded.SetToolsOneHanded();   
        DayzPlayerItemBehaviorCfg     twoHanded = new DayzPlayerItemBehaviorCfg;
        twoHanded.SetTwoHanded();

        DayzPlayerItemBehaviorCfg     fireArmsItemBehaviour = new DayzPlayerItemBehaviorCfg;
        fireArmsItemBehaviour.SetFirearms();

        DayzPlayerItemBehaviorCfg     heavyItemBehaviour = new DayzPlayerItemBehaviorCfg;
        heavyItemBehaviour.SetHeavyItems();            

        GetDayZPlayerType().AddItemInHandsProfileIK("BRP_BodyBag_Base", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", heavyItemBehaviour, "dz/anims/anm/player/ik/heavy/wooden_log.anm");
        GetDayZPlayerType().AddItemInHandsProfileIK("BRP_BodyBagKit", "dz/anims/workspaces/player/player_main/player_main_1h.asi", toolsOneHanded, "dz/anims/anm/player/ik/gear/book.anm");        
        super.Init();
    }
};