class BastionBankingMenu : UIScriptedMenu {

    // make an actual command handler
    // Create a command object and create command which have description/cmd/whatever
    // Have execution function which is called when the command is ran

    static const string CMD_HELP = "help";
    static const string CMD_REGISTER = "register";
    static const string CMD_DEPOSIT = "deposit";
    static const string CMD_WITHDRAW = "withdraw";
    static const string CMD_TRANSFER = "transfer";
    static const string CMD_BALANCE = "balance";
    static const string CMD_LOGIN = "login";
    static const string CMD_LOGOUT = "logout";

    protected ref Widget wRoot;
    protected ref EditBoxWidget activeInputBox;
    protected ref ButtonWidget btnClose;
    protected ref ScrollWidget scroller;
    protected ref GridSpacerWidget outerGrid, activeGrid;
    protected ref array<ref Widget> arrayWidgets, arrayActiveGridWidgets;
    protected ref array<string> arrayPreviousEntry;
    protected ref map<string, string> mapCommands;
    protected PlayerBase player;
    protected string userDir, initialPassword, password, cmdUsed;
    protected bool isLoggingIn, isRegistering, isConfirming, isConfirmed, isConfirmingPasscode, isResetting;
    protected int bankId, inputAmount;

    override Widget Init() {
        arrayWidgets = new array<ref Widget>();
        arrayActiveGridWidgets = new array<ref Widget>();
        arrayPreviousEntry = new array<string>();

        wRoot = GetGame().GetWorkspace().CreateWidgets("BastionMod\\BastionBanking\\gui\\layouts\\BastionCLI.layout");
        scroller = ScrollWidget.Cast(wRoot.FindAnyWidget("barScroll"));
        outerGrid = GridSpacerWidget.Cast(wRoot.FindAnyWidget("outerGrid"));
        activeGrid = GetGame().GetWorkspace().CreateWidgets("BastionMod\\BastionBanking\\gui\\layouts\\GridSpacer.layout", outerGrid);
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
        if (isLoggingIn || isRegistering || isConfirmingPasscode || isResetting) {
            if (EditBoxWidget.Cast(w) == activeInputBox) {
                string boxText = activeInputBox.GetText();

                if (boxText.Length() > initialPassword.Length()) {
                    initialPassword += boxText.Substring(initialPassword.Length(), 1);
                } else {
                    initialPassword = initialPassword.Substring(0, boxText.Length());
                }
                activeInputBox.SetText(ConsealText(boxText));
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

        player = PlayerBase.Cast(GetGame().GetPlayer());
        userDir = "C:\Users\\" + player.GetMultiCharactersPlayerName() + ">";

        GetGame().GetMission().PlayerControlDisable(INPUT_EXCLUDE_INVENTORY);
        GetGame().GetUIManager().ShowUICursor(true);
        GetGame().GetUIManager().ShowCursor(true);
        GetGame().GetInput().ChangeGameFocus(1);
        GetGame().GetMission().GetHud().Show(false);
        StartIntro();
    }

    override void OnHide() {
        super.OnHide();

        GetGame().GetUIManager().ShowCursor(false);
        GetGame().GetUIManager().ShowUICursor(false);
        GetGame().GetInput().ResetGameFocus();
        GetGame().GetMission().PlayerControlEnable(1);
        GetGame().GetMission().GetHud().Show(true);
        Cleanup();
    }

    void StartIntro() {
        CreateTextGrid("Welcome to the Depository & Dispensary (D2) Console // V0.1 // Licensed for use by BKG-023");
        CreateTextGrid("NCC RESTRICTED - DO NOT DISTRIBUTE, MODIFY, OR REPRODUCE THE CONTENTS OF SOFTWARE. DOING SO IS PUNISHABLE BY LAW.");
        CreateTextGrid("CONTENTS ARE PROPERTY OF THE NATO-CSTO COALITION, DEPARTMENT OF COMMERCE.", true);
        CreateTextGrid("New to D2? Type \"register\" into the console.");
        CreateTextGrid("Need a refresher? Type \"help\".", true);

        CreateInputGrid();
        ScrollToBottom();
    }

    void CreateTextGrid(string text, bool newLine = false) {
        CheckGridSize();

        TextWidget displayText;
        GridSpacerWidget newGrid;

        if (newLine) {
            newGrid = GetGame().GetWorkspace().CreateWidgets("BastionMod\\BastionBanking\\gui\\layouts\\GridTextNewLine.layout", activeGrid);
        } else {
            newGrid = GetGame().GetWorkspace().CreateWidgets("BastionMod\\BastionBanking\\gui\\layouts\\GridText.layout", activeGrid);
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

        newGrid = GetGame().GetWorkspace().CreateWidgets("BastionMod\\BastionBanking\\gui\\layouts\\GridUserInput.layout", activeGrid);
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
            activeGrid = GetGame().GetWorkspace().CreateWidgets("BastionMod\\BastionBanking\\gui\\layouts\\GridSpacer.layout", outerGrid);
            arrayWidgets.Insert(activeGrid);
            arrayActiveGridWidgets = new array<ref Widget>();
        }
    }

	protected string ConsealText(string input) {
		string consealedtext = string.Empty;

		for (int i = 0; i < input.Length(); i++) {
			consealedtext += "*";
		}

		return consealedtext;
	}

    void HandleEnterKey() {
        if (!activeInputBox) {
            return;
        }
        string inputText = activeInputBox.GetText();
        inputText.ToLower();
        inputText.Trim();

        if (isLoggingIn || isRegistering || isConfirmingPasscode || isResetting) {
            if (initialPassword != string.Empty) {
                if (isLoggingIn) {
                    isLoggingIn = false;
                    isRegistering = false;
                    isConfirmingPasscode = false;
                    password = string.Empty;
                    CreateTextGrid("Logging in...", true);

                    SetFocus(null);
                    auto loginParams = new Param2<int, string>(bankId, initialPassword);
                    GetGame().RPCSingleParam(player, BSTBankRPC.RPC_SERVER_ACCOUNTLOGIN, loginParams, true);
                } else if (isConfirmingPasscode) {
                    if (password == initialPassword) {
                        auto registerParam = new Param1<string>(password);

                        if (isResetting) {
                            SetFocus(null);
                            CreateTextGrid("Resetting passcode...", true);
                            GetGame().RPCSingleParam(player, BSTBankRPC.RPC_SERVER_RESETPASSCODE, registerParam, true);
                        } else {
                            SetFocus(null);
                            CreateTextGrid("Registering...", true);
                            GetGame().RPCSingleParam(player, BSTBankRPC.RPC_SERVER_REGISTERACCOUNT, registerParam, true);
                        }
                        initialPassword = string.Empty;
                        password = string.Empty;
                        isConfirmingPasscode = false;
                        isResetting = false;
                    } else {
                        isRegistering = true;
                        initialPassword = string.Empty;
                        password = string.Empty;

                        CreateTextGrid("Passwords do not match! Try again!");
                        CreateInputGrid("Enter Passcode:");
                    }
                    isConfirmingPasscode = false;
                } else if (isRegistering || isResetting) {
                    isConfirmingPasscode = true;
                    isRegistering = false;
                    password = initialPassword;
                    initialPassword = string.Empty;

                    CreateInputGrid("Confirm Passcode:");
                }
            } else {
                CreateTextGrid("No Password Entered!", true);
                CreateInputGrid("Enter password:");
                initialPassword = string.Empty;
            }
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

    void ScrollToBottom() {
        GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(scroller.VScrollToPos01, 100, false, 1);
    }

    void InitializeCommands() {
        if (!mapCommands) {
            // Maybe make a legit command handler. Idk.
            mapCommands = new map<string, string>();
            mapCommands.Insert("register", "register a new account, if one does not already exist.");
            mapCommands.Insert("login", "login to your D2 account. When prompted, use the same password you used to register.");
            mapCommands.Insert("logout", "logs you out of your D2 account, if logged in.");
            mapCommands.Insert("balance", "check the balance of both your main and overflow account.");
            mapCommands.Insert("deposit", "deposit Credits into your account. For example, \"deposit all\" will deposit ALL credits into your account.");
            mapCommands.Insert("withdraw", "withdraw Credits from your account. For example, \"withdraw 5\" will withdraw 5 credits from your account.");
            mapCommands.Insert("transfer", "transfer Credits from your overflow account to your main balance. This charges a transfer fee!");
            mapCommands.Insert("reset", "prompts to reset password on associated account.");
        }
    }

    void Help() {
        for (int i = 0; i < mapCommands.Count(); i++) {
            if (i == (mapCommands.Count() - 1)) {

                CreateTextGrid("" + mapCommands.GetKey(i) + " - " + mapCommands.GetElement(i), true);
            } else {
                CreateTextGrid("" + mapCommands.GetKey(i) + " - " + mapCommands.GetElement(i));
            }
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
                    Help();
                    CreateInputGrid();
                    break;
                }
            case "register":
                {
                    isRegistering = true;

                    CreateTextGrid("Welcome to the NCC's Depository & Dispensary Console.", true);
                    CreateTextGrid("The purpose of this machine (as well the many other D2 machines around your Bastion) is to provide you with a safe way to deposit, ");
                    CreateTextGrid("store, and withdraw NCC Credits, which can then be used to buy essentials for life inside your Bastion.", true);
                    CreateTextGrid("In order to reap the benefits of such a system, you must first register for an account. Your D2 login has been automatically set to your Citizen ID.");
                    CreateTextGrid("You must choose a secure, memorable password. Please type your password below");
                    CreateTextGrid("(rest assured it is logged, the characters do not show up for security purposes.)", true);
                    CreateInputGrid("Enter Password:");
                    ScrollToBottom();
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
            case "reset":
                {
                    isResetting = true;
                    CreateInputGrid("Enter New Password:");
                    ScrollToBottom();
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