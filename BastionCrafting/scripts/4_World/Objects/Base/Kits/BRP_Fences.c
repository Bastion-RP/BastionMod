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

class BRP_Fence11_Kit : BRP_Kit 
{
    override string Get_ItemName()
	{
		return "BRP_Fence11";
	}
};
class BRP_Fence11 : BRP_Fences_Base
{
    override string Get_KitName()
	{
		return "BRP_Fence11_Kit";
	}	
};

class BRP_Fence12_Kit : BRP_Kit 
{
    override string Get_ItemName()
	{
		return "BRP_Fence12";
	}
};
class BRP_Fence12 : BRP_Fences_Base
{
    override string Get_KitName()
	{
		return "BRP_Fence12_Kit";
	}	
};

class BRP_Fence13_Kit : BRP_Kit 
{
    override string Get_ItemName()
	{
		return "BRP_Fence13";
	}
};
class BRP_Fence13 : BRP_Fences_Base
{
    override string Get_KitName()
	{
		return "BRP_Fence13_Kit";
	}	
};

class BRP_Fence14_Kit : BRP_Kit 
{
    override string Get_ItemName()
	{
		return "BRP_Fence14";
	}
};
class BRP_Fence14 : BRP_Fences_Base
{
    override string Get_KitName()
	{
		return "BRP_Fence14_Kit";
	}	
};

class BRP_Fence15_Kit : BRP_Kit 
{
    override string Get_ItemName()
	{
		return "BRP_Fence15";
	}
};
class BRP_Fence15 : BRP_Fences_Base
{
    override string Get_KitName()
	{
		return "BRP_Fence15_Kit";
	}	
};

class BRP_Fence16_Kit : BRP_Kit 
{
    override string Get_ItemName()
	{
		return "BRP_Fence16";
	}
};
class BRP_Fence16 : BRP_Fences_Base
{
    override string Get_KitName()
	{
		return "BRP_Fence16_Kit";
	}	
};

class BRP_Fence17_Kit : BRP_Kit 
{
    override string Get_ItemName()
	{
		return "BRP_Fence17";
	}
};
class BRP_Fence17 : BRP_Fences_Base
{
    override string Get_KitName()
	{
		return "BRP_Fence17_Kit";
	}	
};

class BRP_Fence18_Kit : BRP_Kit 
{
    override string Get_ItemName()
	{
		return "BRP_Fence18";
	}
};
class BRP_Fence18 : BRP_Fences_Base
{
    override string Get_KitName()
	{
		return "BRP_Fence18_Kit";
	}	
};

class BRP_Fence19_Kit : BRP_Kit 
{
    override string Get_ItemName()
	{
		return "BRP_Fence19";
	}
};
class BRP_Fence19 : BRP_Fences_Base
{
    override string Get_KitName()
	{
		return "BRP_Fence19_Kit";
	}	
};

class BRP_Fence20_Kit : BRP_Kit 
{
    override string Get_ItemName()
	{
		return "BRP_Fence20";
	}
};
class BRP_Fence20 : BRP_Fences_Base
{
    override string Get_KitName()
	{
		return "BRP_Fence20_Kit";
	}	
};

class BRP_Fence21_Kit : BRP_Kit 
{
    override string Get_ItemName()
	{
		return "BRP_Fence21";
	}
};
class BRP_Fence21 : BRP_Fences_Base
{
    override string Get_KitName()
	{
		return "BRP_Fence21_Kit";
	}	
};

class BRP_Fence22_Kit : BRP_Kit 
{
    override string Get_ItemName()
	{
		return "BRP_Fence22";
	}
};
class BRP_Fence22 : BRP_Fences_Base
{
    override string Get_KitName()
	{
		return "BRP_Fence22_Kit";
	}	
};

class BRP_Fence23_Kit : BRP_Kit 
{
    override string Get_ItemName()
	{
		return "BRP_Fence23";
	}
};
class BRP_Fence23 : BRP_Fences_Base
{
    override string Get_KitName()
	{
		return "BRP_Fence23_Kit";
	}	
};

class BRP_Fence24_Kit : BRP_Kit 
{
    override string Get_ItemName()
	{
		return "BRP_Fence24";
	}
};
class BRP_Fence24 : BRP_Fences_Base
{
    override string Get_KitName()
	{
		return "BRP_Fence24_Kit";
	}	
};

class BRP_Fence25_Kit : BRP_Kit 
{
    override string Get_ItemName()
	{
		return "BRP_Fence25";
	}
};
class BRP_Fence25 : BRP_Fences_Base
{
    override string Get_KitName()
	{
		return "BRP_Fence25_Kit";
	}	
};

class BRP_Fence26_Kit : BRP_Kit 
{
    override string Get_ItemName()
	{
		return "BRP_Fence26";
	}
};
class BRP_Fence26 : BRP_Fences_Base
{
    override string Get_KitName()
	{
		return "BRP_Fence26_Kit";
	}	
};

class BRP_Fence27_Kit : BRP_Kit 
{
    override string Get_ItemName()
	{
		return "BRP_Fence27";
	}
};
class BRP_Fence27 : BRP_Fences_Base
{
    override string Get_KitName()
	{
		return "BRP_Fence27_Kit";
	}	
};

class BRP_Fence28_Kit : BRP_Kit 
{
    override string Get_ItemName()
	{
		return "BRP_Fence28";
	}
};
class BRP_Fence28 : BRP_Fences_Base
{
    override string Get_KitName()
	{
		return "BRP_Fence28_Kit";
	}	
};

class BRP_Fence29_Kit : BRP_Kit 
{
    override string Get_ItemName()
	{
		return "BRP_Fence29";
	}
};
class BRP_Fence29 : BRP_Fences_Base
{
    override string Get_KitName()
	{
		return "BRP_Fence29_Kit";
	}	
};

class BRP_Fence30_Kit : BRP_Kit 
{
    override string Get_ItemName()
	{
		return "BRP_Fence30";
	}
};
class BRP_Fence30 : BRP_Fences_Base
{
    override string Get_KitName()
	{
		return "BRP_Fence30_Kit";
	}	
};

class BRP_Fence31_Kit : BRP_Kit 
{
    override string Get_ItemName()
	{
		return "BRP_Fence31";
	}
};
class BRP_Fence31 : BRP_Fences_Base
{
    override string Get_KitName()
	{
		return "BRP_Fence31_Kit";
	}	
};

class BRP_Fence32_Kit : BRP_Kit 
{
    override string Get_ItemName()
	{
		return "BRP_Fence32";
	}
};
class BRP_Fence32 : BRP_Fences_Base
{
    override string Get_KitName()
	{
		return "BRP_Fence32_Kit";
	}	
};

class BRP_Fence33_Kit : BRP_Kit 
{
    override string Get_ItemName()
	{
		return "BRP_Fence33";
	}
};
class BRP_Fence33 : BRP_Fences_Base
{
    override string Get_KitName()
	{
		return "BRP_Fence33_Kit";
	}	
};

class BRP_Fence34_Kit : BRP_Kit 
{
    override string Get_ItemName()
	{
		return "BRP_Fence34";
	}
};
class BRP_Fence34 : BRP_Fences_Base
{
    override string Get_KitName()
	{
		return "BRP_Fence34_Kit";
	}	
};
