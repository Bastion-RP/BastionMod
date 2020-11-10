class GpsBase : ItemBase
{
	override void OnWorkStart()
	{
		if ( !GetGame().IsServer()  ||  !GetGame().IsMultiplayer() ) // Client side
		{
			if (GetADVCGps())
			{
				SetGPSState(1);
			}
		}
	}

	override void OnWorkStop()
	{
		if ( !GetGame().IsServer()  ||  !GetGame().IsMultiplayer() ) // Client side
		{
			if (GetADVCGps())
			{
				SetGPSState(0);
			}
		}
	}

	override void OnInventoryExit(Man player)
	{
		super.OnInventoryExit(player);
		
		if (GetGame().IsClient())
		{
			if (GetGame().GetPlayer() == player)
			{
				SetGPSState(0, player);
			}
		}
	}

	override void OnInventoryEnter(Man player)
	{
		super.OnInventoryEnter(player);
		
		if (GetGame().IsClient())
		{
			if (GetGame().GetPlayer() == player && IsWorking())
			{
				SetGPSState(1, player);
			}
		}
	}

	void SetGPSState(int type, Man parent = null)
	{
		PlayerBase owner;
		if (parent)
			owner = PlayerBase.Cast(parent);
		else
			owner = PlayerBase.Cast(GetHierarchyRootPlayer());
	
		if (GetGame().GetPlayer() != owner)
			return;
			
		if (owner)
		{
			if (owner.HasWorkingGps() && !type)
				type = 1;
				
			owner.SetGpsState(type);
			GetADVCGps().ToogleGPS(type);
		}
	}

	bool IsWorking()
	{
		if (GetCompEM() && GetCompEM().IsWorking())
			return true;
		return false;
	}

	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionTurnOnWhileInHands);
		AddAction(ActionTurnOffWhileInHands);
	}
}

class GpsGarmin : GpsBase {}
class GpsRC : GpsBase {}