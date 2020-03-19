class BastionBankingMenu : UIScriptedMenu {
    protected ref Widget wRoot;
    protected ref EditBoxWidget activeInputBox;
    protected ref ButtonWidget btnClose;
    protected ref ScrollWidget scroller;
    protected ref GridSpacerWidget outerGrid, activeGrid;
    protected ref array<ref Widget> arrayWidgets, arrayActiveGridWidgets;
    protected ref array<string> arrayPreviousEntry;
    protected ref map<string, string> mapCommands;
    protected PlayerBase player;
    protected string userDir, password, cmdUsed;
    protected bool isLoggingIn, isRegistering, isConfirming, isConfirmed;
    protected int bankId, inputAmount;

    override Widget Init() {
        arrayWidgets = new array<ref Widget>();
        arrayActiveGridWidgets = new array<ref Widget>();
        arrayPreviousEntry = new array<string>();

        wRoot = GetGame().GetWorkspace().CreateWidgets("BastionBanking\\gui\\layouts\\BastionCLI.layout");
        scroller = ScrollWidget.Cast(wRoot.FindAnyWidget("barScroll"));
        outerGrid = GridSpacerWidget.Cast(wRoot.FindAnyWidget("outerGrid"));
        activeGrid = GetGame().GetWorkspace().CreateWidgets("BastionBanking\\gui\\layouts\\GridSpacer.layout", outerGrid);
        arrayWidgets.Insert(activeGrid);

        InitializeCommands();

        return wRoot;
    }

    override bool OnKeyPress(Widget w, int x, int y, int key) {
        if (w == activeInputBox) {
            string boxText = activeInputBox.GetText();
            if (boxText.Length() >= 80) {
                activeInputBox.SetText(boxText);
                return true;
            }
        }
        return false;
    }

    override bool OnChange(Widget w, int x, int y, bool finished) {
        if (isLoggingIn || isRegistering) {
            if (EditBoxWidget.Cast(w) == activeInputBox) {
                string boxText = activeInputBox.GetText();

                if (boxText != string.Empty) {
                    password += boxText;
                    activeInputBox.SetText(string.Empty);
                }
            }
            return true;
        }
        return false;
    }

    override bool OnClick(Widget w, int x, int y, int button) {
        super.OnClick(w, x, y, button);

        if (button == MouseState.LEFT) {
            if (w.GetName() == "btnClose") {
                GetGame().GetUIManager().HideScriptedMenu(this);
            }
        }
        return false;
    }

    override void OnShow() {
        super.OnShow();

        GetGame().GetMission().PlayerControlDisable(INPUT_EXCLUDE_INVENTORY);
        GetGame().GetUIManager().ShowUICursor(true);
        GetGame().GetUIManager().ShowCursor(true);
        GetGame().GetInput().ChangeGameFocus(1);
        GetGame().GetMission().GetHud().Show(false);
        player = PlayerBase.Cast(GetGame().GetPlayer());
        userDir = "C:\Users\\" + player.GetIdentity().GetName() + ">";
        CreateTextGrid("Welcome to Bastion Banking. This is going to be changed later, but this is good enough for testing!", true);
        CreateInputGrid();
        scroller.VScrollToPos01(1);
    }

    override void OnHide() {
        super.OnHide();

        GetGame().GetUIManager().ShowCursor(false);
        GetGame().GetUIManager().ShowUICursor(false);
        GetGame().GetInput().ResetGameFocus();
        GetGame().GetMission().PlayerControlEnable(true);
        GetGame().GetMission().GetHud().Show(true);
        Cleanup();
    }

    void StartIntro() {

    }

    void CreateTextGrid(string text, bool newLine = false) {
        CheckGridSize();

        TextWidget displayText;
        GridSpacerWidget newGrid;

        if (newLine) {
            newGrid = GetGame().GetWorkspace().CreateWidgets("BastionBanking\\gui\\layouts\\GridTextNewLine.layout", activeGrid);
        } else {
            newGrid = GetGame().GetWorkspace().CreateWidgets("BastionBanking\\gui\\layouts\\GridText.layout", activeGrid);
        }
        displayText = TextWidget.Cast(newGrid.FindAnyWidget("text"));
        displayText.SetText(text);
        arrayWidgets.Insert(newGrid);
        arrayActiveGridWidgets.Insert(newGrid);
    }

    void CreateInputGrid(string inputText = "") {
        CheckGridSize();

        TextWidget txtUserDir;
        GridSpacerWidget newGrid;

        newGrid = GetGame().GetWorkspace().CreateWidgets("BastionBanking\\gui\\layouts\\GridUserInput.layout", activeGrid);
        txtUserDir = TextWidget.Cast(newGrid.FindAnyWidget("txtUserDir"));
        activeInputBox = EditBoxWidget.Cast(newGrid.FindAnyWidget("edtUserInput"));

        if (inputText == string.Empty) {
            txtUserDir.SetText(userDir);
        } else {
            txtUserDir.SetText(inputText);
        }
        arrayWidgets.Insert(newGrid);
        arrayActiveGridWidgets.Insert(newGrid);
        SetFocus(activeInputBox);
    }

    void Cleanup() {
        foreach (Widget w : arrayWidgets) {
            if (w) {
                w.Unlink();
                delete w;
            }
        }
    }

    void SetConfirmation(string error) {
        isConfirming = true;

        CreateInputGrid(error);
    }

    void SetAmount(int amount) {
        inputAmount = amount;
    }

    private void CheckGridSize() {
        if (arrayActiveGridWidgets.Count() >= 100) {
            Print("Creating new grid");
            activeGrid = GetGame().GetWorkspace().CreateWidgets("BastionBanking\\gui\\layouts\\GridSpacer.layout", outerGrid);
            arrayWidgets.Insert(activeGrid);
            arrayActiveGridWidgets = new array<ref Widget>();
        }
    }

    void HandleEnterKey() {
        string inputText = activeInputBox.GetText();
        inputText.ToLower();
        inputText.Trim();

        if (isLoggingIn || isRegistering) {
            if (password != string.Empty) {
                if (isLoggingIn) {
                    CreateTextGrid("Logging in...", true);

                    auto loginParams = new Param2<int, string>(bankId, password);
                    GetGame().RPCSingleParam(player, BSTBankRPC.RPC_SERVER_ACCOUNTLOGIN, loginParams, true);
                } else if (isRegistering) {
                    CreateTextGrid("Registering...", true);

                    auto registerParam = new Param1<string>(password);
                    GetGame().RPCSingleParam(player, BSTBankRPC.RPC_SERVER_REGISTERACCOUNT, registerParam, true);
                }
            } else {
                CreateTextGrid("No Password Entered!", true);
                CreateInputGrid();
            }
            isLoggingIn = false;
            isRegistering = false;
            password = string.Empty;
        } else if (isConfirming) {
            if (inputText == "y" || inputText == "yes") {
                //isConfirmed = true;
                //isConfirming = false;

                CommandHandler(cmdUsed + " " + inputAmount);
            } else if (inputText == "n" || inputText == "no") {
                isConfirming = false;

                CreateInputGrid();
            } else {
                CreateInputGrid("Are you sure? (Y/N):");
            }
        } else {
            if (inputText == string.Empty) {
                CreateInputGrid();
            } else {
                CommandHandler(inputText);
            }
        }
        ScrollToBottom();
    }

    void Backspace() {
        if (isLoggingIn) {
            if (password != string.Empty) {
                password = password.Substring(0, password.Length() - 1);
            }
        }
    }

    void ScrollToBottom() {
        GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(scroller.VScrollToPos01, 100, false, 1);
    }

    void InitializeCommands() {
        if (!mapCommands) {
            // Maybe make a legit command handler. Idk.
            mapCommands = new map<string, string>();
            mapCommands.Insert("Balance", "Check your account balance");
            mapCommands.Insert("Deposit", "Deposit {amount} | Deposit rations into account");
            mapCommands.Insert("Withdraw", "Withdraw {amount} | Withdraw rations from account");
        }
    }

    void CommandHandler(string input) {
        ref array<string> splitInput = new array<string>();
        Param1<int> params;
        string cmd, amountStr;

        arrayPreviousEntry.Insert(input);
        input.Split(" ", splitInput);
        cmd = splitInput[0];

        switch (cmd) {
            case "help":
                {
                    int mapCount = mapCommands.Count();
                    for (int i = 0; i < mapCount; i++) {
                        if (i == (mapCount - 1)) {
                            CreateTextGrid("" + mapCommands.GetKey(i) + ": " + mapCommands.GetElement(i), true);
                        } else {
                            CreateTextGrid("" + mapCommands.GetKey(i) + ": " + mapCommands.GetElement(i));
                        }
                    }
                    CreateInputGrid();
                    break;
                }
            case "register":
                {
                    isRegistering = true;
                    CreateInputGrid("Password:");
                    break;
                }
            case "deposit":
                {
                    amountStr = splitInput[1];
                    inputAmount = amountStr.ToInt();

                    if (amountStr == "all" || inputAmount > 0) {
                        if (amountStr == "all") {
                            inputAmount = -1
                        }
                        activeInputBox = null;
                        auto paramsDeposit = new Param2<int, bool>(inputAmount, isConfirming);

                        CreateTextGrid("Depositing Rations...", true);
                        SetFocus(null);
                        GetGame().RPCSingleParam(player, BSTBankRPC.RPC_SERVER_DEPOSIT, paramsDeposit, true);

                        if (isConfirming) {
                            isConfirming = false;
                        } else {
                            cmdUsed = cmd;
                        }
                    } else {
                        CreateTextGrid("Invalid amount entered!", true);
                        CreateInputGrid();
                    }
                    break;
                }
            case "withdraw":
                {
                    inputAmount = splitInput[1].ToInt();

                    if (inputAmount <= 0) {
                        CreateTextGrid("Invalid amount entered!", true);
                        CreateInputGrid();
                    } else {
                        CreateTextGrid("Withdrawing Rations...", true);
                        SetFocus(null);
                        activeInputBox = null;

                        params = new Param1<int>(inputAmount);
                        GetGame().RPCSingleParam(player, BSTBankRPC.RPC_SERVER_WITHDRAW, params, true);
                    }
                    break;
                }
            case "transfer":
                {
                    inputAmount = splitInput[1].ToInt();

                    if (inputAmount <= 1) {
                        CreateTextGrid("Invalid amount entered! Must be greater than 1!", true);
                        CreateInputGrid();
                    } else {
                        activeInputBox = null;
                        auto paramsTransfer = new Param2<int, bool>(inputAmount, isConfirming);

                        CreateTextGrid("Transferring...", true)
                        SetFocus(null);
                        GetGame().RPCSingleParam(player, BSTBankRPC.RPC_SERVER_TRANSFER, paramsTransfer, true);

                        if (isConfirming) {
                            isConfirming = false;
                        } else {
                            cmdUsed = cmd;
                        }
                    }
                    break;
                }
            case "balance":
                {
                    CreateTextGrid("Retrieving account balance...", true);
                    SetFocus(null);
                    activeInputBox = null;

                    GetGame().RPCSingleParam(player, BSTBankRPC.RPC_SERVER_GETBALANCE, null, true);
                    break;
                }
            case "login":
                {
                    if (splitInput.Count() > 1) {
                        bankId = splitInput[1].ToInt();
                    } else {
                        bankId = -1;
                    }
                    isLoggingIn = true;
                    CreateInputGrid("Password:");
                    break;
                }
            case "logout":
                {
                    CreateTextGrid("Logging Out...", true);
                    SetFocus(null);
                    activeInputBox = null;

                    GetGame().RPCSingleParam(player, BSTBankRPC.RPC_SERVER_ACCOUNTLOGOUT, null, true);
                    break;
                }
            default:
                {
                    CreateTextGrid("'" + cmd + "' is not recognized as an internal or external command,");
                    CreateTextGrid("operable program or batch file.", true);
                    CreateInputGrid();
                    break;
                }
        }
    }
}