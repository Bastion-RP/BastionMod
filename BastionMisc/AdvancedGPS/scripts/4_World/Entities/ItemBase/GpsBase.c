class GpsBase : ItemBase
{
	private ref array<int> devicesBits;

	void GpsBase()
	{
		devicesBits = new array<int>();
	}

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
			owner.SetMainGps();
			if (owner.GetMainGps() && !type)
				type = 1;
				
			owner.SetGpsState(type);
			GetADVCGps().ToogleGPS(type);
			GetADVCGps().UpdateGpsID();
		}
	}

	bool IsWorking()
	{
		if (GetCompEM() && GetCompEM().IsWorking())
			return true;
		return false;
	}

	bool CanConnect(GpsBase device)
	{
		int low = GetLowBits(device);
		return (devicesBits.Find(low) == -1);
	}

	void ConnectDevice(GpsBase device)
	{
		int low = GetLowBits(device);
		devicesBits.Insert(low);
	}

	void DisconnectDevice(GpsBase device)
	{
		int low = GetLowBits(device);
		int idx = devicesBits.Find(low);
		if (idx >= 0)
			devicesBits.Remove(idx);
	}

	int GetLowBits(GpsBase dev = null)
	{
		GpsBase device;
		int low, high;
		if (dev)
			device = dev;
		else
			device = this;

		device.GetNetworkID( low, high );
		return low;
	}

	void SetChildrenBits(array<int> arr)
	{
		devicesBits = arr;
	}

	array<int> GetChildrenBits()
	{
		return devicesBits;
	}

	array<ref Param2<vector, int>> GetWorkingChildrenPositions()
	{
		GpsBase device;
		array<ref Param2<vector, int>> results = new array<ref Param2<vector, int>>();
		foreach (int bit : devicesBits)
		{
			if (Class.CastTo(device, GetGame().GetObjectByNetworkId(bit, 0)))
			{
				if (device.IsWorking())
				{
					results.Insert(new Param2<vector, int>(device.GetPosition(), bit));
				}
			} 
		}

		return results;
	}

	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionTurnOnWhileInHands);
		AddAction(ActionTurnOffWhileInHands);
		AddAction(ActionConnectGpsDevice);
		AddAction(ActionDisconnectGpsDevice);
	}
}

class GpsGarmin : GpsBase {}
class GpsRC : GpsBase {}