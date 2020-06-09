class BRP_BarrelTable_Danmak : Container_Base
{
	override bool CanPutInCargo( EntityAI parent )
	{
		if( !super.CanPutInCargo(parent) )
		{
			return false;
		}
		if ( GetNumberOfItems() == 0 )
		{
			return true;
		}
		return false;
	}
	
	override bool CanPutIntoHands(EntityAI parent)
	{
		if( !super.CanPutIntoHands( parent ) )
		{
			return false;
		}
		if ( GetNumberOfItems() == 0 )
		{
			return true;
		}
		return false;
	}
	
	override void SetActions()
    {
        super.SetActions();
        
        AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
		AddAction(ActionDeployObject);
    }
};

class BRP_BarrelTable_Green: BRP_BarrelTable_Danmak {};
class BRP_BarrelTable_Blue: BRP_BarrelTable_Danmak {};
class BRP_BarrelTable_Red: BRP_BarrelTable_Danmak {};
class BRP_BarrelTable_Yellow: BRP_BarrelTable_Danmak {};
class BRP_BarrelTable_Avgas: BRP_BarrelTable_Danmak {};
