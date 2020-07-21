class BRP_Safe_Kit : BRP_Kit 
{
    override string Get_ItemName()
	{
		return "BRP_Safe";
	}
};
class BRP_Safe : BRP_Item
{
    override string Get_KitName()
	{
		return "BRP_Safe_Kit";
	}	
};