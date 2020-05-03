class BRP_BodyBag_Base : ItemBase
{
    override bool CanPutInCargo( EntityAI parent )
    {
        return false;
    }

    override void OnInventoryEnter(Man player)
    {
        super.OnInventoryEnter(player);  
        ShowSelection("Curled");
        HideSelection("Flat");
    }
    
    override void OnInventoryExit(Man player)
    {
        super.OnInventoryExit(player);     
        ShowSelection("Flat");
        HideSelection("Curled");    
    }
};

class BRP_BodyBag : BRP_BodyBag_Base {};
class BRP_BodyBag_Blood : BRP_BodyBag_Base {};
class BST_WrappedBody : BRP_BodyBag_Base {};