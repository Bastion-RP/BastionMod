
//1.08 uncomment and delete the playerbase

/*
modded class ModItemRegisterCallbacks
{
    override void RegisterOneHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
        super.RegisterOneHanded(pType, pBehavior);
        pType.AddItemInHandsProfileIK("BRP_Coal", "dz/anims/workspaces/player/player_main/props/player_main_1h_fruit.asi", pBehavior, "dz/anims/anm/player/ik/gear/orange.anm");
        pType.AddItemInHandsProfileIK("BRP_MetalScrap", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/paper.anm");
        pType.AddItemInHandsProfileIK("BRP_MetalSheet_Small2", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/paper.anm");
        pType.AddItemInHandsProfileIK("BRP_ComputerComponent", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/paper.anm"");
        pType.AddItemInHandsProfileIK("BRP_PlasticScrap", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/paper.anm");
        pType.AddItemInHandsProfileIK("BRP_WoodScrap", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/paper.anm");
        pType.AddItemInHandsProfileIK("BRP_Woodscrap2", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/paper.anm");
    };
};
*/

modded class PlayerBase
{
    override void Init()
    {
        if ( !GetGame().IsServer() || !GetGame().IsMultiplayer() ) 
        {
            DayzPlayerItemBehaviorCfg     toolsOneHanded = new DayzPlayerItemBehaviorCfg;
            toolsOneHanded.SetToolsOneHanded();

            DayzPlayerItemBehaviorCfg     twoHanded = new DayzPlayerItemBehaviorCfg;
            twoHanded.SetTwoHanded();

            DayzPlayerItemBehaviorCfg     heavyItemBehaviour = new DayzPlayerItemBehaviorCfg;
            heavyItemBehaviour.SetHeavyItems();
            GetDayZPlayerType().AddItemInHandsProfileIK("BRP_Coal", "dz/anims/workspaces/player/player_main/props/player_main_1h_fruit.asi", toolsOneHanded, "dz/anims/anm/player/ik/gear/orange.anm");	
            GetDayZPlayerType().AddItemInHandsProfileIK("BRP_MetalScrap", "dz/anims/workspaces/player/player_main/player_main_1h.asi", toolsOneHanded, "dz/anims/anm/player/ik/gear/paper.anm");
            GetDayZPlayerType().AddItemInHandsProfileIK("BRP_MetalSheet_Small2", "dz/anims/workspaces/player/player_main/player_main_1h.asi", toolsOneHanded, "dz/anims/anm/player/ik/gear/paper.anm");
            GetDayZPlayerType().AddItemInHandsProfileIK("BRP_ComputerComponent", "dz/anims/workspaces/player/player_main/player_main_1h.asi", toolsOneHanded, "dz/anims/anm/player/ik/gear/paper.anm");
            GetDayZPlayerType().AddItemInHandsProfileIK("BRP_PlasticScrap", "dz/anims/workspaces/player/player_main/player_main_1h.asi", toolsOneHanded, "dz/anims/anm/player/ik/gear/paper.anm");
            GetDayZPlayerType().AddItemInHandsProfileIK("BRP_WoodScrap", "dz/anims/workspaces/player/player_main/player_main_1h.asi", toolsOneHanded, "dz/anims/anm/player/ik/gear/paper.anm");
            GetDayZPlayerType().AddItemInHandsProfileIK("BRP_Woodscrap2", "dz/anims/workspaces/player/player_main/player_main_1h.asi", toolsOneHanded, "dz/anims/anm/player/ik/gear/paper.anm");
        }
        super.Init();
    }
};