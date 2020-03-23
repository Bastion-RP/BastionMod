modded class DayZGame {
	static ref ScriptInvoker multicharactersSpawnInvoker;
	private int multicharactersSelectedCharacterId;
	private string multicharactersSelectedSurvivorType;
	private string multicharactersSelectedSurvivorName;

	void DayZGame() {
		multicharactersSpawnInvoker = new ScriptInvoker();
		multicharactersSelectedCharacterId = -1;
	}

	void SetSelectedSurvivorId(int multicharactersSelectedCharacterId) {
		this.multicharactersSelectedCharacterId = multicharactersSelectedCharacterId;
	}

	void SetSelectedSurvivorType(string multicharactersSelectedSurvivorType) {
		this.multicharactersSelectedSurvivorType = multicharactersSelectedSurvivorType;
	}

	void SetSelectedSurvivorName(string multicharactersSelectedSurvivorName) {
		this.multicharactersSelectedSurvivorName = multicharactersSelectedSurvivorName;
	}

	int GetSelectedSurvivorId() {
		return multicharactersSelectedCharacterId;
	}

	string GetSelectedSurvivorType() {
		return multicharactersSelectedSurvivorType;
	}

	void StoreLoginData() {
		// Make this a script invoked method
		Print(MCConst.debugPrefix + "DayZGame | StoreLoginData | Invoking spawn!");
		multicharactersSpawnInvoker.Invoke();
	}

	override void CancelLoginTimeCountdown() {
		Print(MCConst.debugPrefix + "Cancelling login countdown!");
		super.CancelLoginTimeCountdown();
		ContinueSpawn();
	}

	void ShowCountDown() {
		Print(MCConst.debugPrefix + "Showing login timer!");
		if (m_LoginTime <= 0) {
			m_LoginTime = 5;
		}

		GetUIManager().ScreenFadeIn(0, "You are spawning in " + m_LoginTime + " second(s)", FadeColors.BLACK, FadeColors.WHITE);
		GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(SpawnCountdown, 1000, true);
	}

	void SpawnCountdown() {
		if (--m_LoginTime <= 0) {
			GetCallQueue(CALL_CATEGORY_SYSTEM).Remove(this.SpawnCountdown);
			GetGame().GetUIManager().ScreenFadeOut(0);
			ContinueSpawn();
		} else {
			GetUIManager().ScreenFadeIn(0, "You are spawning in " + m_LoginTime + " second(s)", FadeColors.BLACK, FadeColors.WHITE);
		}
	}

	override void OnRespawnEvent(int time) {
		if (time > 0) {
			m_LoginTime = time;
		}
		return;
	}

	void ContinueSpawn(bool init = false) {
		Print(MCConst.debugPrefix + "Continuing spawn! Initialize client? " + init);
		array<ref Param> params = new array<ref Param>();
		Param characterId = new Param1<int>(multicharactersSelectedCharacterId);
		Param characterType = new Param1<string>(multicharactersSelectedSurvivorType);
		Param isInitializing = new Param1<bool>(init);

		params.Insert(characterId);
		params.Insert(characterType);
		params.Insert(isInitializing);
		StoreLoginData(params);
	}
}