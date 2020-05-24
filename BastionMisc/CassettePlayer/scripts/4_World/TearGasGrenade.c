class BRP_CassettePlayer extends ItemBase {};
class BRP_Cassette extends ItemBase {};
class BRP_Cassette_blue extends BRP_Cassette {};

modded class JMAnimRegister
{
	override void OnRegisterOneHanded( DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior )
    {
		super.OnRegisterOneHanded( pType, pBehavior )			
 		pType.AddItemInHandsProfileIK("BRP_CassettePlayer", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/cassette.anm");
 		pType.AddItemInHandsProfileIK("BRP_Cassette", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/cassette.anm");

    }	
};