class BRP_BrowningHP_Base : Pistol_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new Fnx45Recoil(this);
	}
};

class BRP_BrowningHP : BRP_BrowningHP_Base {};