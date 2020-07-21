class BST_DTACLookupMenu {
	private static const int KEYCODE_MIN_NUM = 48;
	private static const int KEYCODE_MAX_NUM = 57;

    protected ref JsonSerializer jsSerializer;
    protected ref Widget wRoot, wParent, pnlInput, pnlResults;
    protected ref TextWidget txtCivID, txtNameFirst, txtNameLast, txtDOB, txtSex, txtCivClass, txtRace;
    protected ref TextWidget txtInputHeader;
    protected ref EditBoxWidget edtInputID;
    protected ref ButtonWidget btnLookup;
    private bool rateLimited;

    void BST_DTACLookupMenu(Widget wParent) {
        this.wParent = wParent;
        jsSerializer = new JsonSerializer();
        wRoot = GetGame().GetWorkspace().CreateWidgets("BastionMod\\BastionDTAC\\gui\\layouts\\DBLookup.layout", wParent);
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

        BST_DTACRestCallback.dtacData.Insert(this.DisplayData);
    }

    void ~BST_DTACLookupMenu() {
        if (wRoot) {
            wRoot.Unlink();
        }
    }

    void DisplayData(string data) {
        map<string, string> mapData = new map<string, string>();
        string error;

        Print("[DTAC DEBUG] BST_DTACLookupMenu | DisplayData | Received function call");
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
            
            // change _ to - for the class (enum can't have hypen in it's name)
            string t_ClassText = typename.EnumToString(BastionClasses, mapData.Get("citizen_class").ToInt());
            t_ClassText.Replace("_","-");
            txtCivClass.SetText("Class: " + t_ClassText);
            txtRace.SetText("Race: " + mapData.Get("race"));
        }
    }

	bool OnKeyPress(Widget w, int x, int y, int key) {
        if (w == edtInputID) {
            string boxText = edtInputID.GetText();

            if (key < KEYCODE_MIN_NUM || key > KEYCODE_MAX_NUM) {
                edtInputID.SetText(boxText);
                return true;
            }
        }
        return false;
    }

    void OnClick(Widget w, int x, int y, int button) {
        switch (w) {
            case btnLookup:
                {
                    Lookup();
                    break;
                }
        }
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

	bool IsRateLimited() { return rateLimited; }
}