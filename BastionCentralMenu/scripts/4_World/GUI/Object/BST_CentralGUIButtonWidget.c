class BST_CentralGUIButtonWidget {
    private ref Widget _parent;
    private ref ButtonWidget _root;
    private ref BST_ScriptedWidget _scriptedWidget;
    
    void BST_CentralGUIButtonWidget(Widget parent, BST_ScriptedWidget scriptedWidget) {
        _parent = parent;
        _scriptedWidget = scriptedWidget;
        _root = ButtonWidget.Cast(GetGame().GetWorkspace().CreateWidgets("BastionMod\\BastionCentralMenu\\gui\\layout\\ButtonWidget.layout", _parent));

        _root.SetText(scriptedWidget.GetUpperButtonText());
    }

    void Select() {
        _scriptedWidget.OnShow();
    }
    
    void Deselect() {
        _root.SetState(false);
        _scriptedWidget.OnHide();
    }

    ButtonWidget GetRoot() { return _root; }
    BST_ScriptedWidget GetWidget() { return _scriptedWidget; }

    void ~BST_CentralGUIButtonWidget() {
        if (_root) {
            _root.Unlink();
        }
        if (_scriptedWidget) {
            delete _scriptedWidget;
        }
    }
}