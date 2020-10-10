class ToxicHandler
{
	private PlayerBase player;
	private ref array<ref ToxicAreaData> toxicAreas;
	private ref array<string> protectableMasks;

	void ToxicHandler()
	{
		player = PlayerBase.Cast(GetGame().GetPlayer());
		toxicAreas = GetToxicManager().GetConfig().GetZones();
		protectableMasks = GetToxicManager().GetConfig().GetMasks();
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
		return (vector.Distance(player.GetPosition(), toxicArea.GetPos()) <= toxicArea.GetRadius());
	}
}