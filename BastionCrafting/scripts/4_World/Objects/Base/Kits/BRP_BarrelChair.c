class BRP_Chair_Base : BRP_Item
{	
	override void SetActions()
    {
        super.SetActions();
		AddAction(ActionBRPSitOnChair);
    }
};

class BRP_BarrelChair_Avgas_Kit : BRP_Kit 
{
    override string Get_ItemName()
	{
		return "BRP_BarrelChair_Avgas";
	}
};
class BRP_BarrelChair_Avgas : BRP_Chair_Base
{
    override string Get_KitName()
	{
		return "BRP_BarrelChair_Avgas_Kit";
	}	
};

class BRP_BarrelChair_Green_Kit : BRP_Kit 
{
    override string Get_ItemName()
	{
		return "BRP_BarrelChair_Green";
	}
};
class BRP_BarrelChair_Green: BRP_BarrelChair_Avgas
{
    override string Get_KitName()
	{
		return "BRP_BarrelChair_Green_Kit";
	}	
};

class BRP_BarrelChair_Blue_Kit : BRP_Kit 
{
    override string Get_ItemName()
	{
		return "BRP_BarrelChair_Blue";
	}
};
class BRP_BarrelChair_Blue: BRP_BarrelChair_Avgas
{
    override string Get_KitName()
	{
		return "BRP_BarrelChair_Blue_Kit";
	}	
};
class BRP_BarrelChair_Red_Kit : BRP_Kit 
{
    override string Get_ItemName()
	{
		return "BRP_BarrelChair_Red";
	}
};
class BRP_BarrelChair_Red: BRP_BarrelChair_Avgas
{
    override string Get_KitName()
	{
		return "BRP_BarrelChair_Red_Kit";
	}	
};
class BRP_BarrelChair_Yellow_Kit : BRP_Kit 
{
    override string Get_ItemName()
	{
		return "BRP_BarrelChair_Yellow";
	}
};
class BRP_BarrelChair_Yellow: BRP_BarrelChair_Avgas
{
    override string Get_KitName()
	{
		return "BRP_BarrelChair_Yellow_Kit";
	}	
};
class BRP_BarrelChair_Danmak_Kit : BRP_Kit 
{
    override string Get_ItemName()
	{
		return "BRP_BarrelChair_Danmak";
	}
};
class BRP_BarrelChair_Danmak: BRP_BarrelChair_Avgas
{
    override string Get_KitName()
	{
		return "BRP_BarrelChair_Danmak_Kit";
	}	
};
