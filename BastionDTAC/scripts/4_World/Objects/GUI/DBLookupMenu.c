class DBLookupMenu : UIScriptedMenu {
	private static const int KEYCODE_MIN_NUM = 48;
	private static const int KEYCODE_MAX_NUM = 57;

    protected ref JsonSerializer jsSerializer;
    protected ref Widget wRoot, pnlInput, pnlResults;
    protected ref TextWidget txtCivID, txtNameFirst, txtNameLast, txtDOB, txtSex, txtCivClass, txtRace;
    protected ref TextWidget txtInputHeader;
    protected ref EditBoxWidget edtInputID;
    protected ref ButtonWidget btnLookup;
    protected ref map<string, string> mapCitizenClasses;
    private bool rateLimited;

    void DBLookupMenu() {
        jsSerializer = new JsonSerializer();
        mapCitizenClasses = new map<string, string>();

        DTACCurl.dtacData.Insert(this.DisplayData);
        mapCitizenClasses.Insert("1", "A");
        mapCitizenClasses.Insert("2", "B");
        mapCitizenClasses.Insert("3", "C");
    }

    override Widget Init() {
        wRoot = GetGame().GetWorkspace().CreateWidgets("BastionDTAC\\gui\\layouts\\DBLookup.layout");
        pnlInput = wRoot.FindAnyWidget("pnlInput");
        pnlResults = wRoot.FindAnyWidget("pnlResults");
        txtInputHeader = TextWidget.Cast(wRoot.FindAnyWidget("txtInputHeader"));
        txtCivID = TextWidget.Cast(wRoot.FindAnyWidget("txtCivID"));
        txtNameFirst = TextWidget.Cast(wRoot.FindAnyWidget("txtNameFirst"));
        txtNameLast = TextWidget.Cast(wRoot.FindAnyWidget("txtNameLast"));
        txtDOB = TextWidget.Cast(wRoot.FindAnyWidget("txtDOB"));
        txtSex = TextWidget.Cast(wRoot.FindAnyWidget("txtSex"));
        txtCivClass = TextWidget.Cast(wRoot.FindAnyWidget("txtCivClass"));
        txtRace = TextWidget.Cast(wRoot.FindAnyWidget("txtRace"));
        edtInputID = EditBoxWidget.Cast(wRoot.FindAnyWidget("edtInputID"));
        btnLookup = ButtonWidget.Cast(wRoot.FindAnyWidget("btnLookup"));

        return wRoot;
    }

    void DisplayData(string data) {
        map<string, string> mapData = new map<string, string>();
        string error;

        Print("[DTAC DEBUG] DBLookupMenu | DisplayData | Received function call");
        if (!jsSerializer.ReadFromString(mapData, data, error)) {
            txtInputHeader.SetText(data);
        } else {
            pnlInput.Show(false);
            pnlResults.Show(true);

            txtCivID.SetText("ID: " + mapData.Get("id"));
            txtNameFirst.SetText("First Name: " + mapData.Get("first_name"));
            txtNameLast.SetText("Last Name: " + mapData.Get("last_name"));
            txtDOB.SetText("DOB: " + mapData.Get("date_of_birth"));
            txtSex.SetText("Sex: " + mapData.Get("sex"));
            txtCivClass.SetText("Class: " + mapCitizenClasses.Get(mapData.Get("citizen_class")));
            txtRace.SetText("Race: " + mapData.Get("race"));
        }
    }

	override bool OnKeyPress(Widget w, int x, int y, int key) {
        if (w == edtInputID) {
            string boxText = edtInputID.GetText();

            if (key < KEYCODE_MIN_NUM || key > KEYCODE_MAX_NUM) {
                edtInputID.SetText(boxText);
                return true;
            }
        }
        return super.OnKeyPress(w, x, y, key);
    }

    override bool OnClick(Widget w, int x, int y, int button) {
        switch (w) {
            case btnLookup:
                {
                    Lookup();
                    break;
                }
        }
        return true;
    }

    bool IsInputDialogVisible() {
        return pnlInput.IsVisible();
    }

	void SetRateLimited() {
		if (rateLimited) { return; }
		rateLimited = true;

		GetGame().GetCallQueue(CALL_CATEGORY_GUI).RemoveByName(this, "RemoveRateLimit");
		GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLaterByName(this, "RemoveRateLimit", 1000, true);
	}

	void RemoveRateLimit() {
		rateLimited = false;
	}

    void Lookup() {
        if (!IsRateLimited() && pnlInput.IsVisible() && edtInputID.GetText().Length() > 0) {
            SetRateLimited();
            SendCURLRequest(edtInputID.GetText());
        }
    }

	bool IsRateLimited() {
		return rateLimited;
	}

	override void OnShow() {
		super.OnShow();

		GetGame().GetMission().PlayerControlDisable(INPUT_EXCLUDE_ALL);
		GetGame().GetUIManager().ShowCursor(true);
		GetGame().GetMission().GetHud().Show(false);
	}

	override void OnHide() {
		super.OnHide();

		GetGame().GetUIManager().ShowCursor(false);
		GetGame().GetMission().PlayerControlEnable(1);
		GetGame().GetMission().GetHud().Show(true);
	}
}