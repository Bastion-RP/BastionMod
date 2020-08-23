class BRP_Taser_Base : Pistol_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new Cz75Recoil(this);
	}
};
class BRP_Taser : BRP_Taser_Base {};