modded class DayZGame {
	static ref ScriptInvoker BST_MCSpawnInvoker;

	void DayZGame() {
		BST_MCSpawnInvoker = new ScriptInvoker();
	}

	override void OnRespawnEvent(int time) {
		if (time > 0) {
			m_LoginTime = time;
		}
		return;
	}

	override void StoreLoginDataPrepare() {
		BST_MCSpawnInvoker.Invoke();
	}

	void ~DayZGame() {
		delete BST_MCSpawnInvoker;
	}
}