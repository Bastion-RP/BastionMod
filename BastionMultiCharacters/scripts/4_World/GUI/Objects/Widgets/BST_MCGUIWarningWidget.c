class BST_MCGUIWarningWidget : BST_MCGUIWidget {
    private ref ButtonWidget _btnConfirm, _btnCancel;

    void Init(ScriptedWidgetEventHandler handler) {
        _root = GetGame().GetWorkspace().CreateWidgets("BastionMod/BastionMultiCharacters/gui/layout/Warning.layout", _parent);
        _btnConfirm = ButtonWidget.Cast(_root.FindAnyWidget("btnConfirm"));
        _btnCancel = ButtonWidget.Cast(_root.FindAnyWidget("btnCancel"));
        _handler = handler;

        _root.Show(false);
        _root.SetHandler(_handler);
        _root.SetSort(9999);
    }

    ButtonWidget GetConfirmButton() { return _btnConfirm; }
    ButtonWidget GetCancelButton() { return _btnCancel; }
}