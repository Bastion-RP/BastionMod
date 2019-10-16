modded class DayZGame {
	ref CURLCore curlCore;
	ref CURLContext curlCTX;
	private string bstAPISrc;
	private string bstAPIKey;
	private string whitelistedRole = "whitelisted";
	private string closedTestingRole = "closed testing sessions";

	void SetAPISrc(string src) {
		bstAPISrc = src;
	}

	void SetAPIKey(string key) {
		bstAPIKey = key;
	}

	void InitializeCURL() {
        curlCore = CreateCURLCore();
        curlCore.EnableDebug(true);
		curlCTX = GetCURLCore().GetCURLContext(bstAPISrc);
	}

	override void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) {
		super.OnRPC(sender, target, rpc_type, ctx);

		if (!sender) { return; }

		if (IsServer()) {
			switch (rpc_type) {
				case BSTSRPC.RPC_SERVER_GETWHITELIST:
					{
						string data;

        				data = curlCTX.GET_now("?key=" + bstAPIKey + "&name=" + sender.GetName());
						Print("URL USED=" + bstAPISrc + "?key=" + bstAPIKey + "&name=" + sender.GetName());
						Print("Data received data=" + data);
						ParseWhitelistData(sender, data);
					}
			}
		}
	}

	void ParseWhitelistData(PlayerIdentity sender, string data) {
		array<string> arrayData = new array<string>();
		data.Split("|", arrayData);

		if (arrayData) {
			string playerId = sender.GetPlainId();
			string webId = arrayData[0];
			bool isWhitelisted = false;
			bool canClosedTest = false;

			Print("webId=" + webId);

			if (playerId != webId) {
				Print("PlayerId does not equal id grabbed from website! Kicking player... playerId=" + playerId);
				DisconnectPlayer(sender);
				return;
			}
			for (int i = 1; i < arrayData.Count(); i++) {
				string group = arrayData[i];
				group.ToLower();

				if (group == whitelistedRole) {
					isWhitelisted = true;
					continue;
				} else if (group == closedTestingRole) {
					canClosedTest = true;
				}
			}
			if (!isWhitelisted || !canClosedTest) {
				Print("Player is not whitelisted! Kicking... playerId=" + playerId);
				DisconnectPlayer(sender);
			} else {
				Print("Player is whitelisted! Allowing client to continue... playerId=" + playerId);
				Param1<bool> params = new Param1<bool>(isWhitelisted);
				RPCSingleParam(null, BSTWRPC.RPC_CLIENT_SETWHITELIST, params, true, sender);
			}
		}
	}
}