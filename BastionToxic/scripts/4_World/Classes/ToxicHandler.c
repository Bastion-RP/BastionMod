class ToxicHandler
{
	private PlayerBase player;
	private ref array<ref ToxicAreaData> toxicAreas;
	private ref array<string> protectableMasks;
	private bool IsDebug;

	// Debug stuff
	// private Shape shapeMin;
	// private Shape shapeMax;
	private Shape playerShape;
	private array<Shape> triggerShapes;
	//============

	void ToxicHandler()
	{
		player = PlayerBase.Cast(GetGame().GetPlayer());
		toxicAreas = GetToxicManager().GetConfig().GetZones();
		protectableMasks = GetToxicManager().GetConfig().GetMasks();

		IsDebug = GetToxicManager().GetSettings().IsDebug();

		if (IsDebug)
			DebugStart();
		//Debug.DestroyAllShapes();
	}

	void ~ToxicHandler()
	{
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Remove(CheckPlayerPosition);
	}

	void Init()
	{
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(CheckPlayerPosition, 2000, true);
	}

	void CheckPlayerPosition()
	{
		vector pos = player.GetPosition();
		int packetID;
		foreach (ToxicAreaData toxicArea : toxicAreas)
		{
			if (PlayerInToxicArea(toxicArea))
			{
				if (PlayerHasProtect())
					packetID = TRPCs.HAS_PROTECT;
				else
					packetID = TRPCs.HAS_NO_PROTECT;

				GetGame().RPCSingleParam(player, packetID, null, true);
				return;
			}
		}
	}

	bool PlayerHasProtect()
	{
		ItemBase mask = player.FindAttachmentBySlotName("Mask");
		if (!mask)
			return false;
		if (mask.IsRuined())
			return false;
		
		int idx = protectableMasks.Find(mask.GetType());

		return (idx + 1);
	}

	bool PlayerInToxicArea(ToxicAreaData toxicArea)
	{
		if (toxicArea.IsCircle())
			return (vector.Distance(player.GetPosition(), toxicArea.GetPos()) <= toxicArea.GetRadius());
		else
		{
			if (CheckPos(toxicArea))
			{
				//Print("Player in box trigger");
				return true;
			}
		}
		return false;
	}

	bool CheckPos(ToxicAreaData toxicArea)
	{
		vector tmins; //trigger mins
		vector tmaxs; //trigger maxs
		vector pmins; //player mins
		vector pmaxs; //player maxs
		vector pos = toxicArea.GetPos();
		tmins = pos + toxicArea.GetMins();
		tmaxs = pos + toxicArea.GetMaxs();

		// shape1.SetColor(Colors.BLACK);
		// shape2.SetColor(Colors.BLACK);

		GetPBounds(pmins, pmaxs, player.GetPosition() );
		if (Math3D.CheckBoundBox(pmins, pmaxs, tmins, tmaxs))
		{
			// shape1.SetColor(Colors.RED);
			// shape2.SetColor(Colors.RED);
			return true;
		}
		return false;	
	}

	void GetPBounds(out vector min, out vector max, vector pos)
	{
		vector temp[2];
		player.GetCollisionBox(temp);
		min = temp[0] + pos;
		max = temp[1] + pos;
	}

	void DebugStart()
	{
		// triggerShapes = new array<Shape>();

		foreach (ToxicAreaData toxicArea : toxicAreas)
		{
			if (toxicArea.IsCircle())
				Debug.DrawSphere(toxicArea.GetPos(), toxicArea.GetRadius(), Colors.RED);
			else
			{
				Debug.DrawBox(toxicArea.GetPos() + toxicArea.GetMins(), toxicArea.GetPos() + toxicArea.GetMaxs(), Colors.RED);
			}
		}
	}
}