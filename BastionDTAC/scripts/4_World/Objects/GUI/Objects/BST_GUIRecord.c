class BST_GUIRecord {
    private Widget _root, _parent;
    private TextWidget _txtName, _txtDate;
    private ref BST_DTAC_CURL_GeneralRecord _record;

    void BST_GUIRecord(Widget parent, BST_DTAC_CURL_GeneralRecord record, bool transparent) {
        _parent = parent;
        _record = record;
        _root = GetGame().GetWorkspace().CreateWidgets("BastionMod\\BastionDTAC\\gui\\layouts\\RecordWidget.layout", parent);
        _txtName = TextWidget.Cast(_root.FindAnyWidget("txtCrime"));
        _txtDate = TextWidget.Cast(_root.FindAnyWidget("txtDateIssued"));
        
        if (transparent) {
            _root.SetAlpha(0);
        }
        if (!record) {
            _txtName.SetText("No Records Found!");
        } else {
            _txtName.SetText(_record.GetDescription());
            _txtDate.SetText(_record.GetDateAdded());
        }
    }

    void ~BST_GUIRecord() {
        if (_txtName) {
            _txtName.Unlink();
        }
        if (_txtDate) {
            _txtDate.Unlink();
        }
        if (_root) {
            _root.Unlink();
        }
    }

    Widget GetRoot() { return _root; }
    Widget GetParent() { return _parent; }
    BST_DTAC_CURL_GeneralRecord GetRecord() { return _record; }
}