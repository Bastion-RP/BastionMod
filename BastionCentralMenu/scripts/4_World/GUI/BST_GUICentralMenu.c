/*
    BST_GUICentralMenu written by RoomService

    This mod is basically a "framework." It is built to allow other mods to add buttons to it
    and have its menu show when clicking on the button

    How To Use: 
        Create a new class that inherits ScriptedWidgetEventHandler
            (If you have never used ScriptedWidgetEventHandler before, here is an example constructor)

            class BST_DTACGroupMenu : ScriptedWidgetEventHandler {
                void BST_DTACGroupMenu(Widget parent) {
                    _parent = parent;
                    _root = GetGame().GetWorkspace().CreateWidgets("layout path", _parent);

                    _root.SetHandler(this); <---    Make sure this is called in the constructor, this allows the script to 
                                                    act as an independent UI
                }
            }
        
        Make sure you use SetHandler(this) on the root OF THAT CLASS
        Once that's done, you can code that class as you would a normal UI
        
        Override BuildButtons() (which is called on OnShow) and use AddButton(className) to create new buttons
        BE SURE TO CALL SUPER

        Override 
 */

class BST_GUICentralMenu : UIScriptedMenu {
    private ref Widget _subMenuRoot; // This is the widget to use as a parent for new menus!!!

    /*!
        Used to add new buttons to UI. This should only be called inside of 'BuildButtons'

        param 'className': class name of ScriptedWidgetEventHandler class.
        return: ButtonWidget
     */

    ButtonWidget AddButton(string className) {
        ButtonWidget newButton = GetGame().GetWorkspace().CreateWidgets("BastionMod\\BastionCentralMenu\\gui\\layout\\ButtonWidget.layout", _rootGrid);
        
        newButton.SetUserData(className);
        _arrButtons.Insert(newButton);
        return newButton;
    }

    // Example modification of function to create new UI on button click

    override bool OnClick(Widget w, int x, int y, int button) {
        /*
            Example of how to create UI based on button clicked
            Pretend there's a variable:
            private ref BST_DTACLookupMenu lookupMenu;
            
            string className;

            w.GetUserData(className);

            switch (className) {
                case "BST_DTACLookupMenu":
                    {
                        if (lookupMenu) {
                            delete lookupMenu;
                        } else {
                            lookupMenu = new BST_DTACLookupMenu();
                        }
                        break;
                    }
            }
        */
        return super.OnClick(w, x, y, button); // ALWAYS CALL SUPER
    }

    /*
        Function called before FixSize() 
        Override to add button to script
    */

    void BuildButtons() {
        /*
            Example of how to add a button

            ButtonWidget newButton = AddButton("BST_DTACLookupMenu");
            
            newButton.SetText("DTAC GROUPS");
        */
    }

    // ====================== Do not modify anything below ======================
    private static const int CONST_UI_PADDING = 25;
    private static const int CONST_UI_GRID_PADDING = 10;

    private ref Widget _pnlRoot;
    private ref GridSpacerWidget _rootGrid;
    private ref TextWidget _txtName;
    private ref TextWidget _txtID;
    private ref array<ref ButtonWidget> _arrButtons;

    override Widget Init() {
        layoutRoot = GetGame().GetWorkspace().CreateWidgets("BastionMod\\BastionCentralMenu\\gui\\layout\\CentralMenu.layout");
        _pnlRoot = layoutRoot.FindAnyWidget("pnlRootMenu");
        _subMenuRoot = layoutRoot.FindAnyWidget("menuFrame");
        _txtName = TextWidget.Cast(layoutRoot.FindAnyWidget("txtName"));
        _txtID = TextWidget.Cast(layoutRoot.FindAnyWidget("txtID"));
        _rootGrid = GridSpacerWidget.Cast(layoutRoot.FindAnyWidget("gridButtons"));
        _arrButtons = new array<ref ButtonWidget>();

        return layoutRoot;
    }
    
    // Dynamically fixes the size of the UI based on how many buttons were created

    void FixSize() {
        if (_arrButtons.Count() <= 0) { return; }
        float totalSize = 0;
        float x = 0.0;
        float y = 0.0;
        float w = 0.0;
        float h = 0.0;

        _rootGrid.GetPos(x, y);

        foreach (ButtonWidget button : _arrButtons) {
            if (!button) { continue; }
            w = 0;
            h = 0;

            button.GetSize(w, h);

            if (h > 0) {
                totalSize += h;
            }
        }
        totalSize += (CONST_UI_GRID_PADDING * (_arrButtons.Count() - 1));
        totalSize = totalSize + y + CONST_UI_PADDING;

        _pnlRoot.GetSize(w, h);
        _pnlRoot.SetSize(w, totalSize);
    }

    override void OnShow() {
        super.OnShow();
        GetGame().GetMission().PlayerControlDisable(INPUT_EXCLUDE_ALL);
        GetGame().GetUIManager().ShowCursor(true);
        GetGame().GetMission().GetHud().Show(false);

        BuildButtons();
        FixSize();
    }

    override void OnHide() {
        super.OnHide();

        GetGame().GetUIManager().ShowCursor(false);
        GetGame().GetMission().PlayerControlEnable(true);
        GetGame().GetMission().GetHud().Show(true);
    }

    void ~BST_GUICentralMenu() {
        if (_arrButtons) {
            foreach (ButtonWidget button : _arrButtons) {
                if (!button) { continue; }
                button.Unlink();
            }
        }
    }
}