class MultiCharactersInitMenu {
	private ref Widget wRoot;
	private ref TextWidget txtInit;

	void MultiCharactersInitMenu() {
		wRoot = GetGame().GetWorkspace().CreateWidgets("BastionMod\\BastionMultiCharacters\\gui\\layouts\\ClientWaitMenu.layout");
		txtInit = TextWidget.Cast(wRoot.FindAnyWidget("waitText"));
		wRoot.SetSort(9999);
	}

	void ~MultiCharactersInitMenu() {
		if (wRoot) {
			wRoot.Unlink();
		}
	}

	void Hide() {
		wRoot.Show(false);
	}

	void Initializing() {
		wRoot.Show(true);
		txtInit.SetText("Initializing...");
	}
	
	void Loading() {
		txtInit.SetText("Loading player data...");
	}
	
	void DataWaiting() {
		txtInit.SetText("Waiting for Data From Server...");
	}
}