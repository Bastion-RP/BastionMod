modded class DayZGame
{
	private ref array<string> m_BSTWhitelist;
	private bool m_BSTIsWhitelisted;

	void DayZGame() {
		m_BSTIsWhitelisted = false;
	}

	void CheckDir() {
		if (!FileExist(m_BSTProfileDir)) {
			MakeDirectory(m_BSTProfileDir);
		}

        if (!FileExist(m_BSTWhitelistDir)) {
			JsonFileLoader<array<string>>.JsonSaveFile(m_BSTWhitelistDir, new array<string>());
		}
    }

	void SetWhitelisted(bool whitelisted) {
		m_BSTIsWhitelisted = whitelisted;
	}

	void LoadWhitelist() {
		if(!IsServer()) return;

		m_BSTWhitelist = new array<string>();
		JsonFileLoader<array<string>>.JsonLoadFile(m_BSTWhitelistDir, m_BSTWhitelist);
	}

	bool IsWhitelisted() {
		return m_BSTIsWhitelisted;
	}
	
	bool IsWhitelisted(string playerID) {
		int index = m_BSTWhitelist.Find(playerID);

		if (index == -1) {
			return false;
		} else {
			return true;
		}
	}
}