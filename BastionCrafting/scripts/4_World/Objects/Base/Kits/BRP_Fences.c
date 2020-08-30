class BRP_Fences_Base : BRP_Item
{
	override bool IsInvEmpty()
	{   
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		if ( IsPlayerInside( player, "zbytek" ) )
		{
			return true;
		}
		return false;
	}

	bool IsPlayerInside( PlayerBase player, string selection )
	{
		vector player_pos = player.GetPosition();
		vector fence_pos = GetPosition();
		vector ref_dir = GetDirection();
		ref_dir[1] = 0;
		ref_dir.Normalize();
		 
		vector x[2];
		vector b1,b2;
		GetCollisionBox(x);
		b1 = x[0];
		b2 = x[1];

		vector dir_to_fence = fence_pos - player_pos;
		dir_to_fence[1] = 0;
		float len = dir_to_fence.Length();

		dir_to_fence.Normalize();
		
		vector ref_dir_angle = ref_dir.VectorToAngles();
		vector dir_to_fence_angle = dir_to_fence.VectorToAngles();
		vector test_angles = dir_to_fence_angle - ref_dir_angle;
		
		vector test_position = test_angles.AnglesToVector() * len;
		
		if(test_position[0] < b1[0] || test_position[0] > b2[0] || test_position[2] < 0.2 || test_position[2] > 2.2 )
		{
			return false;
		}
		else
		{
			return true;
		}
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
