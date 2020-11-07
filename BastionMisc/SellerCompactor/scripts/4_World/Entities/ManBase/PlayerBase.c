modded class PlayerBase
{
	override void OnConnect()
	{
		super.OnConnect();

		this.RPCSingleParam(SellerConst.RPC_SEND_CONFIG, new Param1<ref SellerConfig>(GetSellerManager().GetConfig()), true, this.GetIdentity());
	}

	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);
		
		if (GetGame().IsClient())
		{
			if (rpc_type == SellerConst.RPC_SEND_CONFIG)
			{
				Param1<ref SellerConfig> data;
				if (!ctx.Read(data)) return;

				GetSellerManager().SetConfig(data.param1);
			}
		}
	}

	override bool CanSwapItemInCargo (EntityAI child_entity, EntityAI new_entity)
	{
		if (!super.CanSwapItemInCargo(child_entity, new_entity)) { return false; }
		ItemBase oldEnt = ItemBase.Cast(child_entity);
		ItemBase newEnt = ItemBase.Cast(new_entity);
		if (oldEnt.IsSeller() || newEnt.IsSeller())
		{ return false; }

		return true;
	}
}