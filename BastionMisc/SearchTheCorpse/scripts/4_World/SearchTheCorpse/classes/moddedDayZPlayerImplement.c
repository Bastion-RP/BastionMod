modded class DayZPlayerImplement
{
	ref STCConfig stcConfig;

	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);

		
		if (GetGame().IsServer())
			handleServerRPCsSTC(sender, rpc_type, ctx);
		else
			handleClientRPCsSTC(sender, rpc_type, ctx);
	}

	void handleServerRPCsSTC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
	}

	void handleClientRPCsSTC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		switch(rpc_type)
		{
			case STC_rpc_type.RPC_SetClientSTCConfig :
				SetClientSTCConfig(sender, rpc_type, ctx);
			break;
			
		}
	}

	void SetClientSTCConfig(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		ref Param1<ref STCConfig> params = new Param1<  ref STCConfig  >( null );
		if(!ctx.Read( params ))
			return;
		
		stcConfig = params.param1;
	}
}