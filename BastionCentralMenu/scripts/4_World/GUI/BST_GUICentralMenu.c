/*
    BST_GUICentralMenu written by RoomService

    This mod is basically a "framework." It is built to allow other mods to add buttons to it
    and have its menu show when clicking on the button

    How To Use: 
        Create a new class that inherits BST_ScriptedWidget
            (If you have never used ScriptedWidgetEventHandler before, here is an example)
            Note:   Do not use constructor to instansiate _root, the widget will not be created correctly.
                    There is an Init() function for this purpose

            class BST_DTACGroupMenu : BST_ScriptedWidget {
                override void Init(Widget parent) {
                    _parent = parent;
                    _root = GetGame().GetWorkspace().CreateWidgets("layout path", _parent);

                    _root.SetHandler(this); <---    Make sure this is called in the constructor, this allows the script to 
                                                    act as an independent UI
                }
            }

        Note: YOU MUST use the variable _root for the root of the widget or it will not function properly.
        
        Make sure you use SetHandler(this) on the root OF THAT CLASS
        Once that's done, you can code that class as you would a normal UI
        
        There is nothing in this class that should be nor has to be modified to get the buttons to function

        In MissionGameplay.c, override BST_CentralInsertMenus (CALL SUPER!!!!) and call menu.InsertMenu(classname)
        for each button you wish to add!! And logic you want to check before adding the button can be done there as well

        See MissionGameplay.c for more information
 */

class BST_GUICentralMenu : UIScriptedMenu {
    // ====================== Do not modify anything below ======================
    private static const int CONST_UI_PADDING = 25;
    private static const int CONST_UI_GRID_PADDING = 10;

    protected ref Widget _pnlRoot, _subMenuRoot; //  <-- This is the widget to use as a parent for new menus!!!
    protected ref GridSpacerWidget _rootGrid;
    protected ref TextWidget _txtName;
    protected ref TextWidget _txtID;
    protected ref array<typename> _arrScriptedWidgets;
    protected ref array<ref BST_CentralGUIButtonWidget> _arrButtonWidgets;
    protected ref map<ButtonWidget, BST_CentralGUIButtonWidget> _mapButtonWidgets;
    protected BST_CentralGUIButtonWidget _selectedWidget;

    void BST_GUICentralMenu() {
        _arrScriptedWidgets = new array<typename>();
        _arrButtonWidgets = new array<ref BST_CentralGUIButtonWidget>();
        _mapButtonWidgets = new map<ButtonWidget, BST_CentralGUIButtonWidget>();
    }

    override Widget Init() {
        layoutRoot = GetGame().GetWorkspace().CreateWidgets("BastionMod\\BastionCentralMenu\\gui\\layout\\CentralMenu.layout");
        _pnlRoot = layoutRoot.FindAnyWidget("pnlRootMenu");
        _subMenuRoot = layoutRoot.FindAnyWidget("menuFrame");
        _txtName = TextWidget.Cast(layoutRoot.FindAnyWidget("txtName"));
        _txtID = TextWidget.Cast(layoutRoot.FindAnyWidget("txtID"));
        _rootGrid = GridSpacerWidget.Cast(layoutRoot.FindAnyWidget("gridButtons"));

        return layoutRoot;
    }

    void SetPlayerData() {
        PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
        string classText = typename.EnumToString(BastionClasses, player.GetMultiCharactersPlayerClass());

        classText.Replace("_","-");
        _txtName.SetText(player.GetMultiCharactersPlayerName());
        _txtID.SetText("ID: " + player.GetMultiCharactersPlayerId() + " \ Class: " + classText);
    }

    void InsertMenu(typename type) {
        _arrScriptedWidgets.Insert(type);
    }

    void BuildButtons() {
        foreach (typename type : _arrScriptedWidgets) {
            AddButton(type);
        }
    }

    void AddButton(typename type) {
        BST_ScriptedWidget scriptedWidget;
        BST_CentralGUIButtonWidget newButton;

        scriptedWidget = BST_ScriptedWidget.Cast(type.Spawn());

        if (scriptedWidget) {
            newButton = new BST_CentralGUIButtonWidget(_rootGrid, scriptedWidget);

            scriptedWidget.Init(_subMenuRoot);
            scriptedWidget.OnHide();
            _arrButtonWidgets.Insert(newButton);
            _mapButtonWidgets.Insert(newButton.GetRoot(), newButton);
        }
    }

    // Open a menu by using its typename. This will allow keybinds to open the menu
    
    void OpenMenuByType(typename type) {
        foreach (BST_CentralGUIButtonWidget widget : _arrButtonWidgets) {
            if (widget && widget.GetWidget() && widget.GetWidget().Type() == type) {
                _selectedWidget = widget;

                widget.Select();
                break;
            }
        }
    }

    // Grab scripted menu from button and open/close it

    override bool OnClick(Widget w, int x, int y, int button) {
        ButtonWidget buttonW = ButtonWidget.Cast(w);

        if (buttonW && _mapButtonWidgets.Contains(buttonW)) {
            BST_CentralGUIButtonWidget buttonWidget = _mapButtonWidgets.Get(buttonW);

            if (buttonWidget) {
                if (buttonWidget != _selectedWidget) {
                    if (_selectedWidget) {
                        _selectedWidget.Deselect();
                    }
                    _selectedWidget = buttonWidget;

                    _selectedWidget.Select();
                } else {
                    _selectedWidget = null;

                    buttonWidget.Deselect();
                }
            }
        }
        return super.OnClick(w, x, y, button);
    }
    
    // Dynamically fixes the size of the UI based on how many buttons were created

    void FixSize() {
        if (_mapButtonWidgets.Count() <= 0) { return; }
        float totalSize = 0;
        float x = 0.0;
        float y = 0.0;
        float w = 0.0;
        float h = 0.0;

        _rootGrid.GetPos(x, y);

        for (int i = 0; i < _mapButtonWidgets.Count(); i++) {
            ButtonWidget button = _mapButtonWidgets.GetKey(i);

            if (!button) { continue; }
            w = 0;
            h = 0;

            button.GetSize(w, h);

            if (h > 0) {
                totalSize += h;
            }
        }
        totalSize += (CONST_UI_GRID_PADDING * (_mapButtonWidgets.Count() - 1));
        totalSize = totalSize + y + CONST_UI_PADDING;

        _pnlRoot.GetSize(w, h);
        _pnlRoot.SetSize(w, totalSize);
    }

    override void OnShow() {
        super.OnShow();
        GetGame().GetMission().PlayerControlDisable(INPUT_EXCLUDE_ALL);
        GetGame().GetUIManager().ShowCursor(true);
        GetGame().GetMission().GetHud().Show(false);
        PPEffects.SetBlurInventory(0.3);

        SetPlayerData();
        BuildButtons();
        FixSize();
    }

    override void OnHide() {
        super.OnHide();

        GetGame().GetUIManager().ShowCursor(false);
        GetGame().GetMission().PlayerControlEnable(true);
        GetGame().GetMission().GetHud().Show(true);
        PPEffects.SetBlurInventory(0);
    }

    bool IsTyping() {
        if (_selectedWidget && _selectedWidget.GetWidget()) {
            return _selectedWidget.GetWidget().IsTyping();
        }
        return false;
    }

    void ~BST_GUICentralMenu() {
        for (int i = 0; i < _mapButtonWidgets.Count(); i++) {
            ButtonWidget button = _mapButtonWidgets.GetKey(i);
            BST_CentralGUIButtonWidget buttonWidget = _mapButtonWidgets.GetElement(i);

            if (button) {
                button.Unlink();
            }
            if (buttonWidget) {
                delete buttonWidget;
            }
        }
    }

    BST_CentralGUIButtonWidget GetVisibleWidget() { return _selectedWidget; }
}