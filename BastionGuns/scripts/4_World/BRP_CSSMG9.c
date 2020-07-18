class BRP_CSSMG9_Base : RifleBoltLock_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new Mp5kRecoil(this);
	}
};
class BRP_CSSMG9 : BRP_CSSMG9_Base{};