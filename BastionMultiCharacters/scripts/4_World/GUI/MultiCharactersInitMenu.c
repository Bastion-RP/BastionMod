class MultiCharactersInitMenu {
	private ref Widget _root;
	private ref TextWidget _txtInit;

	void MultiCharactersInitMenu() {
		_root = GetGame().GetWorkspace().CreateWidgets("BastionMod/BastionMultiCharacters/gui/layout/ClientWaitMenu.layout");
		_txtInit = TextWidget.Cast(_root.FindAnyWidget("waitText"));
		_root.SetSort(9999);
	}

	void ~MultiCharactersInitMenu() {
		if (_root) {
			_root.Unlink();
		}
	}

	void Hide() {
		_root.Show(false);
	}

	void Initializing() {
		_root.Show(true);
		_txtInit.SetText("Initializing...");
	}
	
	void Loading() {
		_txtInit.SetText("Loading player data...");
	}
	
	void DataWaiting() {
		_txtInit.SetText("Waiting for Data From Server...");
	}
}