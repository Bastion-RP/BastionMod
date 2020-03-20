modded class DayZGame {
	protected ref FileSerializer m_FileSerializer = new FileSerializer();
	private int multicharactersSelectedCharacterId;
	private string multicharactersSelectedSurvivorType;
	private string multicharactersSelectedSurvivorName;

	void DayZGame() {
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
		GetUIManager().EnterScriptedMenu(MultiCharMenu.MENU_WAIT, null);
		RPCSingleParam(null, MultiCharRPC.SERVER_GRAB_LOADOUTS, null, true);
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
		m_LoginTime--
		if (m_LoginTime <= 0) {
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

	void ContinueSpawn() {
		Print(MCConst.debugPrefix + "Continuing spawn!");
		ref array<ref Param> params = new array<ref Param>;
		ref Param characterId = new Param1<int>(multicharactersSelectedCharacterId);
		ref Param characterType = new Param1<string>(multicharactersSelectedSurvivorType);
		ref Param characterName = new Param1<string>(multicharactersSelectedSurvivorName);

		params.Insert(characterId);
		params.Insert(characterType);
		params.Insert(characterName);
		StoreLoginData(params);
	}
}