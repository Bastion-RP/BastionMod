modded class ItemBase 
{
    private ref BST_FurnaceHandler bst_FurnaceHandler;

    void CreateFurnaceHandler() 
    {
        bst_FurnaceHandler = new BST_FurnaceHandler(this);
    }

    override void SetActions() 
    {
        super.SetActions();

        AddAction(BST_ActionStartStopSmelting);
    }

    BST_FurnaceHandler GetBSTFurnaceHandler() { return bst_FurnaceHandler; }

    
	vector Get_ItemPlacingPos()
	{
		return "0 0 0";
	}

	vector Get_ItemPlacingOrientation()
	{
		return "180 0 0";
	}
	
	string Get_ItemName()
	{
		return "BRP_Item";
	}
	string Get_KitName()
	{
		return "BRP_Kit";
	}

	bool IsInvEmpty()
	{   
		if (GetNumberOfItems() < 1 &&  GetInventory().AttachmentCount() < 1)
		{
			return true;
		}
		return false;
	}
};