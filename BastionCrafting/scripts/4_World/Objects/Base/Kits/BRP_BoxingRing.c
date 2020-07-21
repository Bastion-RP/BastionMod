class BRP_BoxingRing_Kit : BRP_Kit 
{
    override string Get_ItemName()
	{
		return "BRP_BoxingRing";
	}
};
class BRP_BoxingRing : BuildingSuper
{
    string Get_KitName()
	{
		return "BRP_BoxingRing_Kit";
	}	
};