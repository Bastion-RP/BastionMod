class BST_BodyBag_Base : ItemBase
{
    override void EEInit()
	{	
		super.EEInit();  
        ShowSelection("Flat");
        HideSelection("Curled");   
	}

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

class BST_BodyBag : BST_BodyBag_Base {};
class BST_BodyBag_Blood : BST_BodyBag_Base {};
class BST_WrappedBody : BST_BodyBag_Base {};