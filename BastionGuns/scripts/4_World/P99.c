class BRP_P99 : Pistol_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new Cz75Recoil(this);
	}
};