class CSP9_Base : Pistol_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new Fnx45Recoil(this);
	}
};
class BRP_CSP9 : CSP9_Base {};
class BRP_CSP45 : CSP9_Base {};