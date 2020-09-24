class BST_BankingMenu : UIScriptedMenu {
	private static const int KEYCODE_MIN_NUM = 48;
	private static const int KEYCODE_MAX_NUM = 57;
    private static const string STRING_WARNING_RATE_LIMITED = "CANNOT COMPLETE ACTIONS THAT FAST!";
    private static const string STRING_INVALID_AMOUNT = "INVALID AMOUNT ENTERED!";
    private static const string STRING_DEPOSIT_NOT_ENOUGH_FUNDS = "NOT ENOUGH FUNDS ON PERSON!";
    private static const string STRING_WITHDRAW_NOT_ENOUGH_FUNDS = "NOT ENOUGH FUNDS IN ACCOUNT!";
    private static const string STRING_TRANSFER_NOT_ENOUGH_FUNDS = "NOT ENOUGH FUNDS IN OVERFLOW!";
    private static const string STRING_TRANSFER_FUNDS_CAPPED = "TOO MANY FUNDS TO TRANSFER";
    private static const string STRING_TRANSFER_FUNDS_LOW = "NOT ENOUGH FUNDS TO TRANSFER";

    protected ref Widget _root, _pnlMain, _pnlDeposit, _pnlWithdraw, _pnlTransfer, _pnlWarning;
    protected ref TextWidget _txtMainName, _txtMainFunds, _txtMainOverflow, _txtTransferDisclaimer;
    protected ref MultilineTextWidget _txtWarningMessage;
    protected ref ButtonWidget _btnMainDeposit, _btnMainWithdraw, _btnMainTransfer;
    protected ref ButtonWidget _btnDepositConfirm, _btnWithdrawConfirm, _btnTransferConfirm;
    protected ref ButtonWidget _btnWarningConfirm;
    protected ref EditBoxWidget _edtDeposit, _edtWithdraw, _edtTransfer;
    protected ref BST_BankAccount _bankAccount;
    private bool _isRateLimited;

    override Widget Init() {
        _root = GetGame().GetWorkspace().CreateWidgets("BastionMod\\BastionBanking\\gui\\layouts\\BankingMenu.layout");
        _pnlMain = _root.FindAnyWidget("pnlMain");
        _pnlDeposit = _root.FindAnyWidget("pnlDeposit");
        _pnlWithdraw = _root.FindAnyWidget("pnlWithdraw");
        _pnlTransfer = _root.FindAnyWidget("pnlTransfer");
        _pnlWarning = _root.FindAnyWidget("pnlWarning");
        _txtMainName = TextWidget.Cast(_root.FindAnyWidget("txtMainName"));
        _txtMainFunds = TextWidget.Cast(_root.FindAnyWidget("txtMainCredits"));
        _txtMainOverflow = TextWidget.Cast(_root.FindAnyWidget("txtMainOverflow"));
        _txtTransferDisclaimer = TextWidget.Cast(_root.FindAnyWidget("txtTransferDisclaimer"));
        _txtWarningMessage = MultilineTextWidget.Cast(_root.FindAnyWidget("txtWarningMessage"));
        _btnMainDeposit = ButtonWidget.Cast(_root.FindAnyWidget("btnDeposit"));
        _btnMainWithdraw = ButtonWidget.Cast(_root.FindAnyWidget("btnWithdraw"));
        _btnMainTransfer = ButtonWidget.Cast(_root.FindAnyWidget("btnTransfer"));
        _btnDepositConfirm = ButtonWidget.Cast(_root.FindAnyWidget("btnDepositConfirm"));
        _btnWithdrawConfirm = ButtonWidget.Cast(_root.FindAnyWidget("btnWithdrawConfirm"));
        _btnTransferConfirm = ButtonWidget.Cast(_root.FindAnyWidget("btnTransferConfirm"));
        _btnWarningConfirm = ButtonWidget.Cast(_root.FindAnyWidget("btnWarningConfirm"));
        _edtDeposit = EditBoxWidget.Cast(_root.FindAnyWidget("edtDeposit"));
        _edtWithdraw = EditBoxWidget.Cast(_root.FindAnyWidget("edtWithdraw"));
        _edtTransfer = EditBoxWidget.Cast(_root.FindAnyWidget("edtTransfer"));

        _txtMainName.SetText(PlayerBase.Cast(GetGame().GetPlayer()).GetMultiCharactersPlayerName());
        _txtTransferDisclaimer.SetText("A " + (int)(GetBSTBankingConfigHandler().GetConfig().GetOverflowTransferFee() * 100) + "% FEE WILL BE ASSESSED");
        _txtMainFunds.SetText("500");
        _txtMainOverflow.SetText("1 IN");

        _pnlMain.Show(true);
        _pnlDeposit.Show(false);
        _pnlWithdraw.Show(false);
        _pnlTransfer.Show(false);
        _pnlWarning.Show(false);
        DeselectAll();
        ClearPanels();
        return _root;
    }

    override bool OnClick(Widget w, int x, int y, int button) {
        array<ItemBase> arrTemp;
        Param params;
        int amount;

        switch(w) {
            case _btnMainDeposit:
                {
                    DeselectAll();
                    HideAllPanels();
                    ClearPanels();
                    _btnMainDeposit.SetState(true);
                    _pnlDeposit.Show(true);
                    break;
                }
            case _btnMainWithdraw:
                { 
                    DeselectAll();
                    HideAllPanels();
                    ClearPanels();
                    _btnMainWithdraw.SetState(true);
                    _pnlWithdraw.Show(true);
                    break;
                }
            case _btnMainTransfer:
                {
                    DeselectAll();
                    HideAllPanels();
                    ClearPanels();
                    _btnMainTransfer.SetState(true);
                    _pnlTransfer.Show(true);
                    break;
                }
            case _btnDepositConfirm:
                {
                    amount = _edtDeposit.GetText().ToInt();

                    if (amount > 0) {
                        if (IsRateLimited()) {
                            _pnlWarning.Show(true);
                            _txtWarningMessage.SetText(STRING_WARNING_RATE_LIMITED);
                        } else {
                            if (GetBSTBankingManager().CanDeposit(PlayerBase.Cast(GetGame().GetPlayer()), amount, arrTemp)) {
                                params = new Param1<int>(amount);

                                SetRateLimited();
                                GetGame().RPCSingleParam(GetGame().GetPlayer(), BST_BankRPC.SERVER_DEPOSIT_FUNDS, params, true);
                            } else {
                                _pnlWarning.Show(true);
                                _txtWarningMessage.SetText(STRING_DEPOSIT_NOT_ENOUGH_FUNDS);
                            }
                        }
                    } else {
                        _pnlWarning.Show(true);
                        _txtWarningMessage.SetText(STRING_INVALID_AMOUNT);
                    }
                    break;
                }
            case _btnWithdrawConfirm:
                {
                    amount = _edtWithdraw.GetText().ToInt();

                    if (amount > 0) {
                        if (IsRateLimited()) {
                            _pnlWarning.Show(true);
                            _txtWarningMessage.SetText(STRING_WARNING_RATE_LIMITED);
                        } else {
                            if (_bankAccount.GetFunds() >= amount) {
                                params = new Param1<int>(amount);

                                SetRateLimited();
                                GetGame().RPCSingleParam(GetGame().GetPlayer(), BST_BankRPC.SERVER_WITHDRAW_FUNDS, params, true);
                            } else {
                                _pnlWarning.Show(true);
                                _txtWarningMessage.SetText(STRING_WITHDRAW_NOT_ENOUGH_FUNDS);
                            }
                        }
                    } else {
                        _pnlWarning.Show(true);
                        _txtWarningMessage.SetText(STRING_INVALID_AMOUNT);
                    }
                    break;
                }
            case _btnTransferConfirm:
                {
                    amount = _edtTransfer.GetText().ToInt();

                    if (amount > 0) {
                        if (IsRateLimited()) {
                            _pnlWarning.Show(true);
                            _txtWarningMessage.SetText(STRING_WARNING_RATE_LIMITED);
                        } else {
                            int bankFundsCap = GetBSTBankingConfigHandler().GetConfig().GetFundsCapByClass(PlayerBase.Cast(GetGame().GetPlayer()).GetMultiCharactersPlayerClass());
                            float transferBeforeFloor = amount * (1 - GetBSTBankingConfigHandler().GetConfig().GetOverflowTransferFee());
                            int transferAmount = Math.Floor(transferBeforeFloor);

                            if (amount > _bankAccount.GetOverflowFunds()) {
                                _pnlWarning.Show(true);
                                _txtWarningMessage.SetText(STRING_TRANSFER_NOT_ENOUGH_FUNDS);
                            } else if ((_bankAccount.GetFunds() + transferAmount) > bankFundsCap) {
                                _pnlWarning.Show(true);
                                _txtWarningMessage.SetText(STRING_TRANSFER_FUNDS_CAPPED + " : " + FloatTo2Decimal(transferBeforeFloor) + " Cap : " + bankFundsCap);
                            } else if (transferAmount <= 0) {
                                _pnlWarning.Show(true);
                                _txtWarningMessage.SetText(STRING_TRANSFER_FUNDS_LOW + " : " + FloatTo2Decimal(transferBeforeFloor));
                            } else {
                                params = new Param1<int>(amount);

                                SetRateLimited();
                                GetGame().RPCSingleParam(GetGame().GetPlayer(), BST_BankRPC.SERVER_TRANSFER_FUNDS, params, true);
                            }
                        }
                    } else {
                        _pnlWarning.Show(true);
                        _txtWarningMessage.SetText(STRING_INVALID_AMOUNT);
                    }
                    break;
                }
            case _btnWarningConfirm:
                {
                    _pnlWarning.Show(false);
                    break;
                }
        }
        return super.OnClick(w, x, y, button);
    }

	override bool OnKeyPress(Widget w, int x, int y, int key) {
        EditBoxWidget edtW = EditBoxWidget.Cast(w);

        if (edtW && (edtW == _edtDeposit || edtW == _edtWithdraw || edtW == _edtTransfer)) {
            if (key < KEYCODE_MIN_NUM || key > KEYCODE_MAX_NUM) {
                string boxText = edtW.GetText();

                edtW.SetText(boxText);
                return true;
            }
        }
        return super.OnKeyPress(w, x , y, key);
    }

    override void OnShow() {
        super.OnShow();
        
        // this will grab account information. If the account does not exist, it will create a new one.
        if (!IsRateLimited()) {
            GetGame().RPCSingleParam(GetGame().GetPlayer(), BST_BankRPC.SERVER_GRAB_ACCOUNT, null, true);
        }
        GetGame().GetMission().PlayerControlDisable(INPUT_EXCLUDE_ALL);
        GetGame().GetUIManager().ShowCursor(true);
        GetGame().GetMission().GetHud().Show(false);

        PPEffects.SetBlurInventory(0.3);
    }

    override void OnHide() {
        super.OnHide();

        GetGame().GetUIManager().ShowCursor(false);
        GetGame().GetMission().PlayerControlEnable(true);
        GetGame().GetMission().GetHud().Show(true);

        PPEffects.SetBlurInventory(0);
    }

    string FloatTo2Decimal(float num) {
        string strAmount = num.ToString();

        if (strAmount.IndexOf(".") != -1) {
            array<string> arrStrTransferSplit = new array<string>();
            
            strAmount.Split(".", arrStrTransferSplit);

            string strBeforeDecimal = arrStrTransferSplit[0];
            string strAfterDecimal = arrStrTransferSplit[1].Substring(0, 2);
            strAmount = strBeforeDecimal + "." + strAfterDecimal;
        }
        return strAmount;
    }

    void ClearPanels() {
        _edtDeposit.SetText("");
        _edtWithdraw.SetText("");
        _edtTransfer.SetText("");
    }

    void HideAllPanels() {
        _pnlDeposit.Show(false);
        _pnlWithdraw.Show(false);
        _pnlTransfer.Show(false);
        _pnlWarning.Show(false);
    }

    void DeselectAll() {
        _btnMainDeposit.SetState(false);
        _btnMainWithdraw.SetState(false);
        _btnMainTransfer.SetState(false);
    }

    void SetBankAccount(BST_BankAccount account) {
        _bankAccount = account;

        _txtMainFunds.SetText("" + account.GetFunds());
        _txtMainOverflow.SetText("" + account.GetOverflowFunds() + " IN");
    }

    void SetRateLimited() {
        if (_isRateLimited) { return; }
        _isRateLimited = true;
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(this.RemoveRateLimit, 2000, false);
    }

    void RemoveRateLimit() {
        _isRateLimited = false;
    }

    bool IsRateLimited() {
        return _isRateLimited;
    }
}