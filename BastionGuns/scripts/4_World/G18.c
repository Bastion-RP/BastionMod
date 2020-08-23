class BRP_G18_Base : Pistol_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new GlockRecoil(this);
	}
};
class BRP_G18 : BRP_G18_Base {};