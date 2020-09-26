class BST_DTACLookupMenu : BST_ScriptedWidget {
	private static const int KEYCODE_MIN_NUM = 48;
	private static const int KEYCODE_MAX_NUM = 57;
    const static float CONST_FLOAT_ALPHA_200 = 0.7843;
    const static float CONST_FLOAT_ALPHA_100 = 0.3921;

    protected ref JsonSerializer _jsSerializer;
    protected ref Widget _pnlInput, _pnlCiv, _pnlCivData, _pnlCivExpandedData, _pnlExpandedRecord;
    protected ref Widget _pnlCreateGeneralRecord, _pnlCreateCriminalRecord;
    protected ref EditBoxWidget _edtInputId;
    protected ref EditBoxWidget _edtCriminalCrime, _edtCriminalPunishment, _edtCriminalDate;
    protected ref MultilineEditBoxWidget _edtCriminalDescription;
    protected ref MultilineEditBoxWidget _edtGeneralRecordDesc;
    protected ref TextWidget _txtPnlNameFirst, _txtPnlNameLast, _txtPnlDOB, _txtPnlClass;
    protected ref TextWidget _txtInfoNameFirst, _txtInfoNameLast, _txtInfoId, _txtInfoClass, _txtInfoZone, _txtInfoAlias;
    protected ref TextWidget _txtInfoHeight, _txtInfoWeight, _txtInfoEyes, _txtInfoHair;
    protected ref TextWidget _txtInfoDOB, _txtInfoSex, _txtInfoNationality, _txtInfoEthnicity, _txtInfoOccupation, _txtInfoAffiliation;
    protected ref TextWidget _txtRecordCrime, _txtRecordDesc, _txtRecordPunishment, _txtRecordDate;
    protected ref ButtonWidget _btnLookupId, _btnAddGeneralRecord, _btnAddCriminalRecord, _btnShowGeneralRecords, _btnShowCriminalRecords;
    protected ref ButtonWidget _btnGeneralCancel, _btnGeneralCreate;
    protected ref ButtonWidget _btnCriminalCancel, _btnCriminalCreate;
    protected ref ScrollWidget _scrollerGeneralRecords, _scrollerCriminalRecords;
    protected ref GridSpacerWidget _gridGeneralRecords, _gridCriminalRecords;
    private ref BST_GUIRecords _generalRecords;
    private ref BST_GUIRecords _criminalRecords;
    private ref BST_DTAC_CURL_GeneralCivData _civGeneralData;
    private ref BST_DTAC_CURL_CriminalRecord _activeCriminalRecord;
    private ref map<Widget, BST_GUIRecord> _mapGUIObjects;
    private bool _isRateLimited;

    void BST_DTACLookupMenu() {
        _jsSerializer = new JsonSerializer();
        _btnText = "dtac records";

        BST_DTACCivGeneralDataCallback._civGeneralDataInvoker.Insert(FillGeneralData);
        BST_DTACGeneralRecordCallback._dtacGeneralRecordInvoker.Insert(BuildGeneralRecords);
        BST_DTACCriminalRecordCallBack._dtacCriminalRecordInvoker.Insert(BuildCriminalRecords);
    }

    void Init() {
        if (_generalRecords) {
            delete _generalRecords;
        }
        if (_criminalRecords) {
            delete _criminalRecords;
        }
        _generalRecords = new BST_GUIRecords(_gridGeneralRecords);
        _criminalRecords = new BST_GUIRecords(_gridCriminalRecords);
        _mapGUIObjects = new map<Widget, BST_GUIRecord>();

        _scrollerGeneralRecords.Show(true);
        _scrollerCriminalRecords.Show(false);
        _btnShowGeneralRecords.SetState(true);
        _btnShowCriminalRecords.SetState(false);
        _pnlInput.Show(true);
        _pnlCiv.Show(false);
        _pnlCivExpandedData.Show(false);
        _pnlExpandedRecord.Show(false);
        _pnlCreateGeneralRecord.Show(false);
        _pnlCreateCriminalRecord.Show(false);
    }

    void Init(Widget parent) {
        _parent = parent;
        _root = GetGame().GetWorkspace().CreateWidgets("BastionMod\\BastionDTAC\\gui\\layouts\\CivLookupMenu.layout", _parent);
        _pnlInput = _root.FindAnyWidget("pnlInput");
        _pnlCiv = _root.FindAnyWidget("pnlCiv");
        _pnlCivData = _root.FindAnyWidget("pnlCivData");
        _pnlCivExpandedData = _root.FindAnyWidget("pnlCivInfo");
        _pnlExpandedRecord = _root.FindAnyWidget("pnlExpandedRecord");
        _pnlCreateGeneralRecord = _root.FindAnyWidget("pnlCreateGeneralRecord");
        _pnlCreateCriminalRecord = _root.FindAnyWidget("pnlCreateCriminalRecord");
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

        // Text Widgets for expanded record panel
        _txtRecordCrime = TextWidget.Cast(_root.FindAnyWidget("txtRecordCrime"));
        _txtRecordDesc = TextWidget.Cast(_root.FindAnyWidget("txtRecordDesc"));
        _txtRecordPunishment = TextWidget.Cast(_root.FindAnyWidget("txtRecordPunishment"));
        _txtRecordDate = TextWidget.Cast(_root.FindAnyWidget("txtRecordDate"));
        // Text Widgets for expanded record panel
        
        // Text Widgets for create general record panel
        _edtGeneralRecordDesc = MultilineEditBoxWidget.Cast(_root.FindAnyWidget("edtGenRecDesc"));
        _btnGeneralCreate = ButtonWidget.Cast(_root.FindAnyWidget("btnGeneralCreate"));
        _btnGeneralCancel = ButtonWidget.Cast(_root.FindAnyWidget("btnGeneralCancel"));
        // Text Widgets for create general record panel

        // Text Widgets for create criminal create record panel
        _edtCriminalCrime = EditBoxWidget.Cast(_root.FindAnyWidget("edtCrimRecCrime"));
        _edtCriminalDescription = MultilineEditBoxWidget.Cast(_root.FindAnyWidget("edtCrimRecDesc"));
        _edtCriminalPunishment = EditBoxWidget.Cast(_root.FindAnyWidget("edtCrimeRecPunishment"));
        _edtCriminalDate = EditBoxWidget.Cast(_root.FindAnyWidget("edtCrimRecDate"));
        _btnCriminalCreate = ButtonWidget.Cast(_root.FindAnyWidget("btnCriminalCreate"));
        _btnCriminalCancel = ButtonWidget.Cast(_root.FindAnyWidget("btnCriminalCancel"));
        // Text Widgets for create criminal create record panel

        _btnLookupId = ButtonWidget.Cast(_root.FindAnyWidget("btnLookup"));
        _btnAddGeneralRecord = ButtonWidget.Cast(_root.FindAnyWidget("btnAddGeneralRecord"));
        _btnAddCriminalRecord = ButtonWidget.Cast(_root.FindAnyWidget("btnAddCriminalRecord"));
        _btnShowGeneralRecords = ButtonWidget.Cast(_root.FindAnyWidget("btnGeneralRecords"));
        _btnShowCriminalRecords = ButtonWidget.Cast(_root.FindAnyWidget("btnCriminalRecords"));
        _scrollerGeneralRecords = ScrollWidget.Cast(_root.FindAnyWidget("scrollerGeneralRecords"));
        _scrollerCriminalRecords = ScrollWidget.Cast(_root.FindAnyWidget("scrollerCriminalRecords"));
        _gridGeneralRecords = GridSpacerWidget.Cast(_root.FindAnyWidget("gridGeneralRecords"));
        _gridCriminalRecords = GridSpacerWidget.Cast(_root.FindAnyWidget("gridCriminalRecords"));

        Init();
        _root.SetHandler(this);
        // Hide zone text since it's not exposed atm
        _txtInfoZone.Show(false);
        //
    }

    void FillGeneralData(string data) {
        if (data.Length() <= 0) {
            _txtPnlNameFirst.SetText("ERROR LOADING DATA!");
            return;
        }
        string error;

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
            newRecord = _criminalRecords.AddRecord(null, 0);
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

    override void OnShow() {
        super.OnShow();

        Init();
    }

	override bool OnKeyPress(Widget w, int x, int y, int key) {
        if (w == _edtInputId) {
            string boxText = _edtInputId.GetText();

            if (key < KEYCODE_MIN_NUM || key > KEYCODE_MAX_NUM) {
                _edtInputId.SetText(boxText);
                return true;
            }
        }
        return false;
    }

    override bool OnMouseEnter(Widget w, int x, int y) {
        if (w == _pnlCivData) {
            w.SetAlpha(CONST_FLOAT_ALPHA_100);
        } else if (_mapGUIObjects.Contains(w)) {
            BST_GUIRecord guiRecord = _mapGUIObjects.Get(w);

            guiRecord.MouseEnter();
        }
        return true;
    }

    override bool OnMouseLeave(Widget w, Widget enterW, int x, int y) {
        if (w == _pnlCivData) {
            w.SetAlpha(CONST_FLOAT_ALPHA_200);
        } else if (_mapGUIObjects.Contains(w)) {
            BST_GUIRecord guiRecord = _mapGUIObjects.Get(w);

            guiRecord.MouseLeave();
        }
        return true;
    }

    override bool OnMouseButtonUp(Widget w, int x, int y, int button) {
        if (w == _pnlCivData) {
            HideRecordPanels();

            if (_pnlCivExpandedData.IsVisible()) {
                _pnlCivExpandedData.Show(false);
            } else {
                _pnlCivExpandedData.Show(true);
            }
        } else if (_mapGUIObjects.Contains(w)) {
            BST_GUIRecord guiRecord = _mapGUIObjects.Get(w);

            if (guiRecord) {
                BST_DTAC_CURL_CriminalRecord criminalRecord = BST_DTAC_CURL_CriminalRecord.Cast(guiRecord.GetRecord());

                if (criminalRecord) {
                    HideCreateRecordPanels();

                    if (_pnlCivExpandedData.IsVisible()) {
                        _pnlCivExpandedData.Show(false);
                    }
                    if (_activeCriminalRecord == criminalRecord) {
                        if (_pnlExpandedRecord.IsVisible()) {
                            HideExpandedRecord();
                        }
                        _activeCriminalRecord = null;
                    } else {
                        _activeCriminalRecord = criminalRecord;

                        _pnlExpandedRecord.Show(true);
                        _txtRecordCrime.SetText(criminalRecord.GetDescription());
                        _txtRecordDesc.SetText(criminalRecord.GetCrimeCommitted());
                        _txtRecordPunishment.SetText(criminalRecord.GetPunishment());
                        _txtRecordDate.SetText(criminalRecord.GetDateCommitted());
                    }
                }
            }
        }
        return true;
    }

    override bool OnClick(Widget w, int x, int y, int button) {
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
            case _btnAddGeneralRecord:
                {
                    if (!_pnlCreateGeneralRecord.IsVisible()) {
                        HideAllPanels();
                        _edtGeneralRecordDesc.SetText("");
                        _pnlCreateGeneralRecord.Show(true);
                    }
                    _btnAddGeneralRecord.SetState(true);
                    break;
                }
            case _btnAddCriminalRecord:
                {
                    if (!_pnlCreateCriminalRecord.IsVisible()) {
                        int hr, min, sec, yr, mnth, day;

                        GetHourMinuteSecondUTC(hr, min, sec);
                        GetYearMonthDayUTC(yr, mnth, day);

                        string formattedDate = "" + mnth + "/" + day + "/" + (yr + 20) + " " + hr + ":" + min;

                        HideAllPanels();
                        _edtCriminalCrime.SetText("");
                        _edtCriminalDescription.SetText("");
                        _edtCriminalPunishment.SetText("");
                        _edtCriminalDate.SetText(formattedDate);
                        _pnlCreateCriminalRecord.Show(true);
                    }
                    _btnAddCriminalRecord.SetState(true);
                    break;
                }
            case _btnCriminalCreate:
                {
                    string txtCrime, txtCrimeDescription, txtCrimePunishment, txtCrimeDate;

                    _edtCriminalDescription.GetText(txtCrimeDescription);

                    txtCrime = _edtCriminalCrime.GetText().Trim();
                    txtCrimeDescription = txtCrimeDescription.Trim();
                    txtCrimePunishment = _edtCriminalPunishment.GetText().Trim();
                    txtCrimeDate = _edtCriminalDate.GetText().Trim();

                    if (IsRateLimited() || txtCrime.Length() <= 0 || txtCrimeDescription.Length() <= 0 || txtCrimePunishment.Length() <= 0 || txtCrimeDate.Length() <= 0) { break; }
                    Param paramsPostCriminal = new Param5<string, string, string, string, string>(txtCrime, txtCrimeDescription, txtCrimePunishment, txtCrimeDate, _civGeneralData.GetId());

                    SetRateLimited();
                    HideCreateRecordPanels();
                    GetGame().RPCSingleParam(GetGame().GetPlayer(), BST_DTACRPC.SERVER_API_POST_CRIMINAL_RECORD, paramsPostCriminal, true);
                    break;
                }
            case _btnGeneralCreate:
                {
                    // Maybe I want to add a string limit...
                    string edtBoxText;

                    _edtGeneralRecordDesc.GetText(edtBoxText);

                    if (!IsRateLimited() && edtBoxText.Length() > 0) {
                        Param paramsPOSTGeneral = new Param2<string, string>(edtBoxText.Trim(), _civGeneralData.GetId());

                        SetRateLimited();
                        HideCreateRecordPanels();
                        GetGame().RPCSingleParam(GetGame().GetPlayer(), BST_DTACRPC.SERVER_API_POST_GENERAL_RECORD, paramsPOSTGeneral, true);
                    }
                    break;
                }
            case _btnCriminalCancel:
                {
                    HideCreateRecordPanels();
                    break;
                }
            case _btnGeneralCancel:
                {
                    HideCreateRecordPanels();
                    break;
                }
        }
        return true;
    }
    
    void HideAllPanels() {
        HideExpandedRecord();
        HideCreateRecordPanels();
        _pnlCivExpandedData.Show(false);
    }

    void HideRecordPanels() {
        HideExpandedRecord();
        HideCreateRecordPanels();
    }

    void HideCreateRecordPanels() {
        _pnlCreateGeneralRecord.Show(false);
        _pnlCreateCriminalRecord.Show(false);
        _btnAddCriminalRecord.SetState(false);
        _btnAddGeneralRecord.SetState(false);
    }

    void HideExpandedRecord() {
        _pnlExpandedRecord.Show(false);
        _activeCriminalRecord = null;
    }

	void SetRateLimited() {
		if (_isRateLimited) { return; }
		_isRateLimited = true;

		GetGame().GetCallQueue(CALL_CATEGORY_GUI).Remove(this.RemoveRateLimit);
		GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(this.RemoveRateLimit, 1000);
	}

	void RemoveRateLimit() {
		_isRateLimited = false;
	}

    void SendApiRequests() {
        if (!GetDTACManager().IsRequiredClass(GetDTACClientManager().GetConfig().GetRequiredAPIClasses(), PlayerBase.Cast(GetGame().GetPlayer()).GetMultiCharactersPlayerClass())) {
            return;
        }
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

    bool IsTyping() {
        if (EditBoxWidget.Cast(GetFocus()) || MultilineEditBoxWidget.Cast(GetFocus())) {
            return true;
        }
        return false;
    }

	bool IsRateLimited() { return _isRateLimited; }

    void ~BST_DTACLookupMenu() {
        if (_root) {
            _root.Unlink();
        }
        BST_DTACCivGeneralDataCallback._civGeneralDataInvoker.Remove(FillGeneralData);
        BST_DTACGeneralRecordCallback._dtacGeneralRecordInvoker.Remove(BuildGeneralRecords);
        BST_DTACCriminalRecordCallBack._dtacCriminalRecordInvoker.Remove(BuildCriminalRecords);
    }
}