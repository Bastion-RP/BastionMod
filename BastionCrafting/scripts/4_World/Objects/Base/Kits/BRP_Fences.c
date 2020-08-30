class BRP_Fences_Base : BRP_Item
{
	bool HasInsideDistance( string selection, PlayerBase player )
	{
		if ( MemoryPointExists( selection ) )
		{
			vector selection_pos = ModelToWorld( GetMemoryPointPos( selection ) );
			float distance = vector.Distance( selection_pos, player.GetPosition() );
			if ( distance >= 1 )
			{
				return false;
			}
		}
		return true;
	}
};

class BRP_Fence01_Kit : BRP_Kit 
{
    override string Get_ItemName()
	{
		return "BRP_Fence01";
	}
};
class BRP_Fence01 : BRP_Fences_Base
{
    override string Get_KitName()
	{
		return "BRP_Fence01_Kit";
	}	
};

class BRP_Fence02_Kit : BRP_Kit 
{
    override string Get_ItemName()
	{
		return "BRP_Fence02";
	}
};
class BRP_Fence02 : BRP_Fences_Base
{
    override string Get_KitName()
	{
		return "BRP_Fence02_Kit";
	}	
};

class BRP_Fence03_Kit : BRP_Kit 
{
    override string Get_ItemName()
	{
		return "BRP_Fence03";
	}
};
class BRP_Fence03 : BRP_Fences_Base
{
    override string Get_KitName()
	{
		return "BRP_Fence03_Kit";
	}	
};

class BRP_Fence04_Kit : BRP_Kit 
{
    override string Get_ItemName()
	{
		return "BRP_Fence04";
	}
};
class BRP_Fence04 : BRP_Fences_Base
{
    override string Get_KitName()
	{
		return "BRP_Fence04_Kit";
	}	
};

class BRP_Fence05_Kit : BRP_Kit 
{
    override string Get_ItemName()
	{
		return "BRP_Fence05";
	}
};
class BRP_Fence05 : BRP_Fences_Base
{
    override string Get_KitName()
	{
		return "BRP_Fence05_Kit";
	}	
};

class BRP_Fence06_Kit : BRP_Kit 
{
    override string Get_ItemName()
	{
		return "BRP_Fence06";
	}
};
class BRP_Fence06 : BRP_Fences_Base
{
    override string Get_KitName()
	{
		return "BRP_Fence06_Kit";
	}	
};

class BRP_Fence07_Kit : BRP_Kit 
{
    override string Get_ItemName()
	{
		return "BRP_Fence07";
	}
};
class BRP_Fence07 : BRP_Fences_Base
{
    override string Get_KitName()
	{
		return "BRP_Fence07_Kit";
	}	
};
