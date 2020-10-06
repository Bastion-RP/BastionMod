modded class PlayerBase
{
	override void SetActionsRemoteTarget()
    {
        super.SetActionsRemoteTarget();
        AddAction(ActionSearchTheCorpse);
        AddAction(ActionSearchTheCorpseZombie);
    }
	
}

modded class DayZPlayerImplement extends DayZPlayer
{
	ref array<int> dea_arraySearchingId = new array<int>;
	
	void SetDeAArraySeatchingId(int id)
	{
		if(dea_arraySearchingId == null)
			dea_arraySearchingId = new array<int>;
		
		int idx = dea_arraySearchingId.Find(id);
		if(idx == -1)
		{
			dea_arraySearchingId.Insert(id);
		}
	}
	
	bool GetDeAIsSearching(int id)
	{
		int idx = dea_arraySearchingId.Find(id);
		return idx != -1;
	}
}