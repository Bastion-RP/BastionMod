modded class DayZGame {
	static ref ScriptInvoker BST_MCSpawnInvoker;
	static ref ScriptInvoker BST_MCInitInvoker;

	void DayZGame() {
		BST_MCSpawnInvoker = new ScriptInvoker();
		BST_MCInitInvoker = new ScriptInvoker();
	}

	override void CancelLoginTimeCountdown() {
		super.CancelLoginTimeCountdown();
		BST_MCSpawnInvoker.Invoke();
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
			BST_MCSpawnInvoker.Invoke();
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

	override void StoreLoginData() {
		BST_MCInitInvoker.Invoke();
	}

	/* void ContinueSpawn(bool init = false) {
		array<ref Param> params = new array<ref Param>();
		Param characterId = new Param1<int>(multicharactersSelectedCharacterId);
		Param characterType = new Param1<string>(multicharactersSelectedSurvivorType);
		Param isInitializing = new Param1<bool>(false);

		params.Insert(characterId);
		params.Insert(characterType);
		params.Insert(isInitializing);
		StoreLoginData(params);
	} */
}