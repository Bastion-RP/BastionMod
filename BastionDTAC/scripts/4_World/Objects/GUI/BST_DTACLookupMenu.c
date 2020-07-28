class BST_DTACLookupMenu {
	private static const int KEYCODE_MIN_NUM = 48;
	private static const int KEYCODE_MAX_NUM = 57;
    const static float CONST_FLOAT_ALPHA_200 = 0.7843;
    const static float CONST_FLOAT_ALPHA_100 = 0.3921;

    protected ref JsonSerializer _jsSerializer;
    protected ref Widget _root, _parent, _pnlInput, _pnlCiv, _pnlCivData, _pnlCivExpandedData;
    protected ref EditBoxWidget _edtInputId;
    protected ref TextWidget _txtPnlNameFirst, _txtPnlNameLast, _txtPnlDOB, _txtPnlClass;
    protected ref TextWidget _txtInfoNameFirst, _txtInfoNameLast, _txtInfoId, _txtInfoClass, _txtInfoZone, _txtInfoAlias;
    protected ref TextWidget _txtInfoHeight, _txtInfoWeight, _txtInfoEyes, _txtInfoHair;
    protected ref TextWidget _txtInfoDOB, _txtInfoSex, _txtInfoNationality, _txtInfoEthnicity, _txtInfoOccupation, _txtInfoAffiliation;
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
        _pnlCiv = _root.FindAnyWidget("pnlCiv");
        _pnlCivData = _root.FindAnyWidget("pnlCivData");
        _pnlCivExpandedData = _root.FindAnyWidget("pnlCivInfo");
        _edtInputId = EditBoxWidget.Cast(_root.FindAnyWidget("edtInputID"));
        _txtPnlNameFirst = TextWidget.Cast(_root.FindAnyWidget("txtPnlNameFirst"));
        _txtPnlNameLast = TextWidget.Cast(_root.FindAnyWidget("txtPnlNameLast"));
        _txtPnlDOB = TextWidget.Cast(_root.FindAnyWidget("txtPnlDOB"));
        _txtPnlClass = TextWidget.Cast(_root.FindAnyWidget("txtPnlClass"));

        // Text Widgets for information panel
        _txtInfoNameFirst = TextWidget.Cast(_root.FindAnyWidget("txtInfoNameFirst"));
        _txtInfoNameLast = TextWidget.Cast(_root.FindAnyWidget("txtInfoNameLast"));
        _txtInfoAlias = TextWidget.Cast(_root.FindAnyWidget("txtInfoAlias"));
        _txtInfoId = TextWidget.Cast(_root.FindAnyWidget("txtInfoID"));
        _txtInfoClass = TextWidget.Cast(_root.FindAnyWidget("txtInfoClass"));
        _txtInfoZone = TextWidget.Cast(_root.FindAnyWidget("txtInfoZone"));
        _txtInfoHeight = TextWidget.Cast(_root.FindAnyWidget("txtInfoHeight"));
        _txtInfoWeight = TextWidget.Cast(_root.FindAnyWidget("txtInfoWeight"));
        _txtInfoEyes = TextWidget.Cast(_root.FindAnyWidget("txtInfoEyes"));
        _txtInfoHair = TextWidget.Cast(_root.FindAnyWidget("txtInfoHair"));
        _txtInfoDOB = TextWidget.Cast(_root.FindAnyWidget("txtInfoDOB"));
        _txtInfoSex = TextWidget.Cast(_root.FindAnyWidget("txtInfoSex"));
        _txtInfoNationality = TextWidget.Cast(_root.FindAnyWidget("txtInfoNationality"));
        _txtInfoEthnicity = TextWidget.Cast(_root.FindAnyWidget("txtInfoEthnicity"));
        _txtInfoOccupation = TextWidget.Cast(_root.FindAnyWidget("txtInfoOccupation"));
        _txtInfoAffiliation = TextWidget.Cast(_root.FindAnyWidget("txtInfoAffiliation"));
        // Text Widgets for information panel

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
        _pnlCiv.Show(false);
        _pnlCivExpandedData.Show(false);
        // Hide zone text since it's not exposed atm
        _txtInfoZone.Show(false);
        //
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
            _pnlCiv.Show(true);
            _txtPnlNameFirst.SetText("First: " + _civGeneralData.GetFirstName());
            _txtPnlNameLast.SetText("Last: " + _civGeneralData.GetLastName());
            _txtPnlDOB.SetText("DOB: " + _civGeneralData.GetDOB());
            _txtPnlClass.SetText("Class: " + txtClass);

            _txtInfoNameFirst.SetText(_civGeneralData.GetFirstName());
            _txtInfoNameLast.SetText(_civGeneralData.GetLastName());

            if (_civGeneralData.GetAlias() != "") {
                _txtInfoAlias.SetText("aka " + _civGeneralData.GetAlias());
            } else {
                _txtInfoAlias.SetText("");
            }
            _txtInfoId.SetText(_civGeneralData.GetId());
            _txtInfoClass.SetText(txtClass);
            //_txtInfoZone.SetText(_civGeneralData.Get);
            _txtInfoHeight.SetText("Height: " + _civGeneralData.GetHeight() + " cm");
            _txtInfoWeight.SetText("Weight: " + _civGeneralData.GetWeight() + " kg");
            _txtInfoEyes.SetText("Eyes: " + _civGeneralData.GetEyes());
            _txtInfoHair.SetText("Hair: " + _civGeneralData.GetHair());
            _txtInfoDOB.SetText("DOB: " + _civGeneralData.GetDOB());
            _txtInfoSex.SetText("Sex: " + _civGeneralData.GetSex());
            _txtInfoNationality.SetText("Nationality: " + _civGeneralData.GetNationality());
            _txtInfoEthnicity.SetText("Race: " + _civGeneralData.GetRace());

            if (_civGeneralData.GetOccupation() == "") {
                _txtInfoOccupation.SetText("Occupation: None");
            } else {
                _txtInfoOccupation.SetText("Occupation: " + _civGeneralData.GetOccupation());
            }
            _txtInfoAffiliation.SetText("Affiliation: " + _civGeneralData.GetAffiliation());
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

    void OnMouseEnter(Widget w, int x, int y) {
        Print("[DEBUG] BST_DTACLookupMenu | OnMouseEnter!!!");
        if (w == _pnlCivData) {
            Print("[DEBUG] BST_DTACLookupMenu | OnMouseEnter!!! alpha=" + w.GetAlpha());
            w.SetAlpha(CONST_FLOAT_ALPHA_100);
        } else if (_mapGUIObjects.Contains(w)) {
            BST_GUIRecord guiRecord = _mapGUIObjects.Get(w);
            Print("[DEBUG] BST_DTACLookupMenu | OnMouseEnter!!! alpha=" + w.GetAlpha());

            guiRecord.MouseEnter();
        }
    }

    void OnMouseLeave(Widget w, Widget enterW, int x, int y) {
        Print("[DEBUG] BST_DTACLookupMenu | OnMouseLeave!!!");
        if (w == _pnlCivData) {
            Print("[DEBUG] BST_DTACLookupMenu | OnMouseLeave!!! alpha=" + w.GetAlpha());
            w.SetAlpha(CONST_FLOAT_ALPHA_200);
        } else if (_mapGUIObjects.Contains(w)) {
            BST_GUIRecord guiRecord = _mapGUIObjects.Get(w);
            Print("[DEBUG] BST_DTACLookupMenu | OnMouseLeave!!! alpha=" + w.GetAlpha());

            guiRecord.MouseLeave();
        }
    }

    void OnMouseButtonUp(Widget w, int x, int y, int button) {
        Print("[DEBUG] BST_DTACLookupMenu | Mouse button up!!!");
        if (w == _pnlCivData) {
            if (_pnlCivExpandedData.IsVisible()) {
                _pnlCivExpandedData.Show(false);
            } else {
                _pnlCivExpandedData.Show(true);
            }
        } else if (_mapGUIObjects.Contains(w)) {
            BST_GUIRecord guiRecord = _mapGUIObjects.Get(w);

            Print("[DEBUG] BST_DTACLookupMenu | Widget found!!! guiRecord=" + guiRecord);
            if (guiRecord) {
                BST_DTAC_CURL_GeneralRecord record = guiRecord.GetRecord();

                if (record) {
                    BST_DTAC_CURL_CriminalRecord criminalRecord = BST_DTAC_CURL_CriminalRecord.Cast(record);

                    if (criminalRecord) {
                        Print("[DEBUG] BST_DTACLookupMenu | Criminal record found!!! criminalRecord=" + criminalRecord);
                    } else {
                        Print("[DEBUG] BST_DTACLookupMenu | Normal record found!!! record=" + record);
                    }
                }
            }
        }
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