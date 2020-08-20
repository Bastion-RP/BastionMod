class BRP_M9A3_Base : Pistol_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new Cz75Recoil(this);
	}
};

class BRP_M9A3 : BRP_M9A3_Base {};