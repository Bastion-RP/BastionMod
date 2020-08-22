class BRP_PB_Base : Pistol_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new MakarovRecoil(this);
	}
};

class BRP_PB : BRP_PB_Base {};