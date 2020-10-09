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
		multicharactersSpawnInvoker.Invoke();
	}

	override void CancelLoginTimeCountdown() {
		super.CancelLoginTimeCountdown();
		ContinueSpawn();
	}

	void ShowCountDown() {
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
		array<ref Param> params = new array<ref Param>();
		Param characterId = new Param1<int>(multicharactersSelectedCharacterId);
		Param characterType = new Param1<string>(multicharactersSelectedSurvivorType);
		Param isInitializing = new Param1<bool>(false);

		params.Insert(characterId);
		params.Insert(characterType);
		params.Insert(isInitializing);
		StoreLoginData(params);
	}
}