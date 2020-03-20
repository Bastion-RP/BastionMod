class MenuWaitForServer : UIScriptedMenu {
	private ref Widget wRoot;

	override Widget Init() {
		wRoot = GetGame().GetWorkspace().CreateWidgets("MultiCharacters\\gui\\layouts\\ClientWaitMenu.layout");
		wRoot.Show(false);

		return wRoot;
	}

	override void OnShow() { }

	override void OnHide() { }
}