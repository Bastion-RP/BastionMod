class MultiCharactersClientManager : PluginBase {
	protected ref FileSerializer jsFileSerializer;
	private ref array<ref SavePlayer> arrayLoadouts;

	void MultiCharactersClientManager() {
		arrayLoadouts = new array<ref SavePlayer>();
		jsFileSerializer = new FileSerializer();
	}

    void Init() {
		delete arrayLoadouts;

        arrayLoadouts = new array<ref SavePlayer>();
    }

	ref array<ref SavePlayer> GetLoadouts() {
		return arrayLoadouts;
	}

	void SetLoadouts(ref array<ref SavePlayer> arrayLoadouts) {
		Init();
		this.arrayLoadouts = arrayLoadouts;
	}
}

MultiCharactersClientManager GetMultiCharactersClientManager() {
    return MultiCharactersClientManager.Cast(GetPlugin(MultiCharactersClientManager));
}