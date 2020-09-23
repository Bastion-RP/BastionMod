class BST_ScriptedWidget : ScriptedWidgetEventHandler {
    protected ref Widget _root, _parent;
    protected string _btnText;

    void BST_ScriptedWidget() {
        // Set the button text in here
        _btnText = "NO TEXT";
    }

    // Use to create widget, use parent as the widget parent or it will not be created 
    // in the correct location
    void Init(Widget parent) {
        // Example
        // _root = GetGame().GetWorkspace().CreateWidgets("BastionMod\\BastionDTAC\\gui\\layouts\\GroupMenu.layout", parent);
    }

    void OnShow() {
        _root.Show(true);
    }

    void OnHide() {
        _root.Show(false);
    }

    bool IsTyping() {
        return false;
    }

    string GetUpperButtonText() {
        string upperText = _btnText;

        upperText.ToUpper();

        return upperText;
    }

    Widget GetRoot() { return _root; }
    string GetButtonText() { return _btnText; }
}