class BRP_MP5SD_Base : RifleBoltFree_Base
{	
	override RecoilBase SpawnRecoilObject()
	{
		return new Mp5kRecoil(this);
	}
};

class BRP_MP5SD : BRP_MP5SD_Base {};