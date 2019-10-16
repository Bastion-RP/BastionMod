modded class DayZGame
{
	ref PlayerIdMenu m_PlayerIdMenu;
	private bool bstIsWhitelisted;
	private bool hasRequestedWhitelisting;

	void DayZGame() {
		bstIsWhitelisted = false;
	}

	override void StoreLoginData() {
		// Make RPC call to server to grab whitelist information
		if (!hasRequestedWhitelisting) {
			RPCSingleParam(null, -19815223, null, true);
			hasRequestedWhitelisting = true;
		}
		else if (bstIsWhitelisted) {
			super.StoreLoginData();
		}
	}

	void CheckDir() {
		if (!FileExist(BSTWConst.bstProfileDir)) {
			MakeDirectory(BSTWConst.bstProfileDir);
		}

        if (!FileExist(BSTWConst.bstWhitelistDir)) {
			JsonFileLoader<array<string>>.JsonSaveFile(BSTWConst.bstWhitelistDir, new array<string>());
		}
    }

	void SetWhitelisted(bool whitelisted) {
		if (whitelisted) {
			bstIsWhitelisted = whitelisted
			StoreLoginData();
		} else {
			DisconnectSessionForce();
		}
	}

	bool IsWhitelisted() {
		return bstIsWhitelisted;
	}

	override void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) {
		super.OnRPC(sender, target, rpc_type, ctx);

		if (!IsServer()) {
			switch (rpc_type) {
				case BSTWRPC.RPC_CLIENT_SETWHITELIST:
				{
					Param1<bool> whitelistData;
					ctx.Read(whitelistData);

					SetWhitelisted(whitelistData.param1);
				}
			}
		}
	}
}