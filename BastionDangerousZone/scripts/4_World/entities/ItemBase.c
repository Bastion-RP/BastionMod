modded class ItemBase extends InventoryItem
{
  private int	m_AttachedAgents;

  private int m_RadAgent = DZAgents.RADSICK;
  private int m_RadAgentQuantity = 0;

  void InjectRadAgent(int quantity)
  {
    m_RadAgentQuantity = quantity;
  }

  int GetRadAgentQuantity()
  {
    return m_RadAgentQuantity;
  }


  override bool OnStoreLoad(ParamsReadContext ctx, int version)
  {
    super.OnStoreLoad(ctx,version);

    if ( !LoadRadAgent(ctx, version) )
			return false;

    if ( !LoadRadAgentQuantity(ctx, version) )
  			return false;

    return true;
  }

  override void OnStoreSave(ParamsWriteContext ctx)
	{
		super.OnStoreSave(ctx);

    SaveRadAgent(ctx);
    SaveRadAgentQuantity(ctx);
  }

  bool LoadRadAgent(ParamsReadContext ctx, int version)
	{
		if(!ctx.Read(m_RadAgent))
			return false;
		return true;
	}

	void SaveRadAgent(ParamsWriteContext ctx)
	{
		ctx.Write(m_RadAgent);
	}

  bool LoadRadAgentQuantity(ParamsReadContext ctx, int version)
	{
		if(!ctx.Read(m_RadAgentQuantity))
			return false;
		return true;
	}

	void SaveRadAgentQuantity(ParamsWriteContext ctx)
	{
		ctx.Write(m_RadAgentQuantity);
	}

}
