class BST_DTACLookupMenu {
	private static const int KEYCODE_MIN_NUM = 48;
	private static const int KEYCODE_MAX_NUM = 57;

    protected ref JsonSerializer _jsSerializer;
    protected ref Widget _root, _parent, _pnlInput, _pnlCivData;
    protected ref EditBoxWidget _edtInputId;
    protected ref TextWidget _txtPnlNameFirst, _txtPnlNameLast, _txtPnlDOB, _txtPnlClass;
    protected ref ButtonWidget _btnLookupId, _btnAddGeneralRecord, _btnAddCriminalRecord, _btnShowGeneralRecords, _btnShowCriminalRecords;
    protected ref ScrollWidget _scrollerGeneralRecords, _scrollerCriminalRecords;
    protected ref GridSpacerWidget _gridGeneralRecords, _gridCriminalRecords;
    private ref BST_GUIRecords _generalRecords;
    private ref BST_GUIRecords _criminalRecords;
    private ref BST_DTAC_CURL_GeneralCivData _civGeneralData;
    private ref map<Widget, BST_GUIRecord> _mapGUIObjects;
    private bool _isRateLimited;

    void BST_DTACLookupMenu(Widget parent) {
        _parent = parent;
        _jsSerializer = new JsonSerializer();
        _mapGUIObjects = new map<Widget, BST_GUIRecord>();
        _root = GetGame().GetWorkspace().CreateWidgets("BastionMod\\BastionDTAC\\gui\\layouts\\CivLookupMenu.layout", _parent);
        _pnlInput = _root.FindAnyWidget("pnlInput");
        _pnlCivData = _root.FindAnyWidget("pnlCiv");
        _edtInputId = EditBoxWidget.Cast(_root.FindAnyWidget("edtInputID"));
        _txtPnlNameFirst = TextWidget.Cast(_root.FindAnyWidget("txtPnlNameFirst"));
        _txtPnlNameLast = TextWidget.Cast(_root.FindAnyWidget("txtPnlNameLast"));
        _txtPnlDOB = TextWidget.Cast(_root.FindAnyWidget("txtPnlDOB"));
        _txtPnlClass = TextWidget.Cast(_root.FindAnyWidget("txtPnlClass"));
        _btnLookupId = ButtonWidget.Cast(_root.FindAnyWidget("btnLookup"));
        _btnAddGeneralRecord = ButtonWidget.Cast(_root.FindAnyWidget("btnAddGeneralRecord"));
        _btnAddCriminalRecord = ButtonWidget.Cast(_root.FindAnyWidget("btnAddCriminalRecord"));
        _btnShowGeneralRecords = ButtonWidget.Cast(_root.FindAnyWidget("btnGeneralRecords"));
        _btnShowCriminalRecords = ButtonWidget.Cast(_root.FindAnyWidget("btnCriminalRecords"));
        _scrollerGeneralRecords = ScrollWidget.Cast(_root.FindAnyWidget("scrollerGeneralRecords"));
        _scrollerCriminalRecords = ScrollWidget.Cast(_root.FindAnyWidget("scrollerCriminalRecords"));
        _gridGeneralRecords = GridSpacerWidget.Cast(_root.FindAnyWidget("gridGeneralRecords"));
        _gridCriminalRecords = GridSpacerWidget.Cast(_root.FindAnyWidget("gridCriminalRecords"));
        _generalRecords = new BST_GUIRecords(_gridGeneralRecords);
        _criminalRecords = new BST_GUIRecords(_gridCriminalRecords);

        _scrollerGeneralRecords.Show(true);
        _scrollerCriminalRecords.Show(false);
        _btnShowGeneralRecords.SetState(true);
        _btnShowCriminalRecords.SetState(false);
        _pnlInput.Show(true);
        _pnlCivData.Show(false);
        BST_DTACCivGeneralDataCallback._civGeneralDataInvoker.Insert(FillGeneralData);
        BST_DTACGeneralRecordCallback._dtacGeneralRecordInvoker.Insert(BuildGeneralRecords);
        BST_DTACCriminalRecordCallBack._dtacCriminalRecordInvoker.Insert(BuildCriminalRecords);
    }

    void ~BST_DTACLookupMenu() {
        if (_root) {
            _root.Unlink();
        }
        BST_DTACCivGeneralDataCallback._civGeneralDataInvoker.Remove(FillGeneralData);
        BST_DTACGeneralRecordCallback._dtacGeneralRecordInvoker.Remove(BuildGeneralRecords);
        BST_DTACCriminalRecordCallBack._dtacCriminalRecordInvoker.Remove(BuildCriminalRecords);
    }

    void FillGeneralData(string data) {
        if (data.Length() <= 0) {
            _txtPnlNameFirst.SetText("ERROR LOADING DATA!");
            return;
        }
        string error;

        Print("[DTAC DEBUG] BST_DTACLookupMenu | FillGeneralData | Received function call");
        if (_jsSerializer.ReadFromString(_civGeneralData, data, error)) {
            string txtClass = typename.EnumToString(BastionClasses, _civGeneralData.GetCitizenClass().ToInt());

            txtClass.Replace("_", "-");
            _pnlInput.Show(false);
            _pnlCivData.Show(true);
            _txtPnlNameFirst.SetText("First: " + _civGeneralData.GetFirstName());
            _txtPnlNameLast.SetText("Last: " + _civGeneralData.GetLastName());
            _txtPnlDOB.SetText("DOB: " + _civGeneralData.GetDOB());
            _txtPnlClass.SetText("Class: " + txtClass);
        }
    }

    void BuildGeneralRecords(string data) {
        BST_GUIRecord newRecord;

        if (data.Length() <= 0) {
            newRecord = _generalRecords.AddRecord(null, 0);
            return;
        }
        array<ref BST_DTAC_CURL_GeneralRecord> arrRecords;
        string error;

        if (_jsSerializer.ReadFromString(arrRecords, data, error)) {
            for (int i = 0; i < arrRecords.Count(); i++) {
                BST_DTAC_CURL_GeneralRecord record = arrRecords[i];

                if (!record) { continue; }
                newRecord = _generalRecords.AddRecord(record, i % 2);

                _mapGUIObjects.Insert(newRecord.GetRoot(), newRecord);
            }
            _scrollerGeneralRecords.VScrollToPos01(0);
        }
    }

    void BuildCriminalRecords(string data) {
        BST_GUIRecord newRecord;
        
        if (data.Length() <= 0) {
            newRecord = _generalRecords.AddRecord(null, 0);
            return;
        }
        array<ref BST_DTAC_CURL_CriminalRecord> arrRecords;
        string error;

        if (_jsSerializer.ReadFromString(arrRecords, data, error)) {
            for (int i = 0; i < arrRecords.Count(); i++) {
                BST_DTAC_CURL_CriminalRecord record = arrRecords[i];

                if (!record) { continue; }
                newRecord = _criminalRecords.AddRecord(record, i % 2);

                _mapGUIObjects.Insert(newRecord.GetRoot(), newRecord);
            }
            _scrollerCriminalRecords.VScrollToPos01(0);
        }
    }

	bool OnKeyPress(Widget w, int x, int y, int key) {
        if (w == _edtInputId) {
            string boxText = _edtInputId.GetText();

            if (key < KEYCODE_MIN_NUM || key > KEYCODE_MAX_NUM) {
                _edtInputId.SetText(boxText);
                return true;
            }
        }
        return false;
    }

    void OnClick(Widget w, int x, int y, int button) {
        switch (w) {
            case _btnLookupId:
                {
                    
                    if (!IsRateLimited() && _pnlInput.IsVisible() && _edtInputId.GetText().Length() > 0) {
                        SetRateLimited();
                        SendApiRequests();
                    }
                    break;
                }
            case _btnShowGeneralRecords:
                {
                    _scrollerGeneralRecords.Show(true);
                    _scrollerCriminalRecords.Show(false);
                    _btnShowCriminalRecords.SetState(false);
                    _btnShowGeneralRecords.SetState(true);
                    break;
                }
            case _btnShowCriminalRecords:
                {
                    _scrollerCriminalRecords.Show(true);
                    _scrollerGeneralRecords.Show(false);
                    _btnShowGeneralRecords.SetState(false);
                    _btnShowCriminalRecords.SetState(true);
                    break;
                }
        }
    }

	void SetRateLimited() {
		if (_isRateLimited) { return; }
		_isRateLimited = true;

		GetGame().GetCallQueue(CALL_CATEGORY_GUI).RemoveByName(this, "RemoveRateLimit");
		GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLaterByName(this, "RemoveRateLimit", 1000, true);
	}

	void RemoveRateLimit() {
		_isRateLimited = false;
	}

    void SendApiRequests() {
        Print("[DEBUG] SendCivDataRequest!");
        RestApi apiCore = GetRestApi();

        if (!apiCore) {
            apiCore = CreateRestApi();
        }
        RestContext ctx = apiCore.GetRestContext("https://bastionrp.com/api/");
        BST_DTACCivGeneralDataCallback generalData = new BST_DTACCivGeneralDataCallback();
        BST_DTACGeneralRecordCallback generalRecords = new BST_DTACGeneralRecordCallback();
        BST_DTACCriminalRecordCallBack criminalRecords = new BST_DTACCriminalRecordCallBack();
        string civId = _edtInputId.GetText();

        ctx.GET(generalData, "characters.php?character_id=" + civId);
        ctx.GET(generalRecords, "generalrecords.php?generalReportCharacterId=" + civId);
        ctx.GET(criminalRecords, "criminalrecords.php?criminalCharacterId=" + civId);
    }

	bool IsRateLimited() { return _isRateLimited; }
}