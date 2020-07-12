class BRP_R700_Base: BoltActionRifle_InnerMagazine_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new Winchester70Recoil(this);
	}
};

class BRP_R700: BRP_R700_Base {};