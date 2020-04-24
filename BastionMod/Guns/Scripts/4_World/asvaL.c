class HopAsval_Base : RifleBoltFree_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new SvdRecoil(this);
	}
	
};
class MTK83_RailAtt extends Inventory_Base
{


}