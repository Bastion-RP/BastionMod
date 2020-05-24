class BRP_GasGrenade extends M18SmokeGrenade_Green {}; //for testing the model itself

modded class JMAnimRegister
{
	override void OnRegisterOneHanded( DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior )
    {
		super.OnRegisterOneHanded( pType, pBehavior )			
 		pType.AddItemInHandsProfileIK("BRP_GasGrenade", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/explosives/smokegrenade.anm");
    }	
};