class DTACChoiceMenu : UIScriptedMenu {
    private ref Widget wRoot;
    private ref ButtonWidget btnGroup, btnLookup, btnShowID;
    private ref DTACLookupMenu lookupMenu;
    private ref DTACGroupMenu groupMenu;
    private ref DTACCivIDMenu civIDMenu;

    void ~DTACChoiceMenu() {
        DeleteMenus();
    }
    
    override Widget Init() {
        wRoot = GetGame().GetWorkspace().CreateWidgets("BastionMod\\BastionDTAC\\gui\\layouts\\ChoiceMenu.layout");
        btnGroup = ButtonWidget.Cast(wRoot.FindAnyWidget("btnGroup"));
        btnLookup = ButtonWidget.Cast(wRoot.FindAnyWidget("btnLookup"));
        btnShowID = ButtonWidget.Cast(wRoot.FindAnyWidget("btnShowID"));

        return wRoot;
    }

    override bool OnMouseButtonUp(Widget w, int x, int y, int button) {
        if (groupMenu) {
            groupMenu.OnMouseButtonUp(w, x, y, button);
        }
        return true;
    }

    override bool OnMouseEnter(Widget w, int x, int y) {
        if (groupMenu) {
            groupMenu.OnMouseEnter(w, x, y);
        }
        return true;
    }

    override bool OnMouseLeave(Widget w, Widget enterW, int x, int y) {
        if (groupMenu) {
            groupMenu.OnMouseLeave(w, enterW, x, y);
        }
        return true;
    }

	override bool OnKeyPress(Widget w, int x, int y, int key) {
        if (lookupMenu) {
            if (lookupMenu.OnKeyPress(w, x, y, key)) { return true; }
        }
        return super.OnKeyPress(w, x, y, key);
    }

    override bool OnClick(Widget w, int x, int y, int button) {
        switch (w) {
            case btnGroup:
                {
                    if (groupMenu) {
                        DeleteMenus();
                        return true;
                    }
                    DeleteMenus();

                    groupMenu = new DTACGroupMenu(wRoot);

                    groupMenu.OnShow();
                    break;
                }
            case btnLookup:
                {
                    if (lookupMenu) {
                        DeleteMenus();
                        return true;
                    }
                    DeleteMenus();

                    lookupMenu = new DTACLookupMenu(wRoot);
                    break;
                }
            case btnShowID:
                {
                    if (civIDMenu) {
                        DeleteMenus();
                        return true;
                    }
                    DeleteMenus();

                    civIDMenu = new DTACCivIDMenu(wRoot);
                    break;
                }
        }
        if (lookupMenu) {
            lookupMenu.OnClick(w, x, y, button);
        }
        return true;
    }

    void OnShow() {
        super.OnShow();
        GetGame().GetMission().PlayerControlDisable(INPUT_EXCLUDE_ALL);
        GetGame().GetUIManager().ShowCursor(true);
        GetGame().GetMission().GetHud().Show(false);

        if (GetDTACGroupManager().HasDTAC(GetGame().GetPlayer())) {
            btnLookup.Show(true);
            btnGroup.Show(true);
        } else {
            btnLookup.Show(false);
            btnGroup.Show(false);
        }
    }

    void OnHide() {
        super.OnHide();

        GetGame().GetUIManager().ShowCursor(false);
        GetGame().GetMission().PlayerControlEnable(true);
        GetGame().GetMission().GetHud().Show(true);
        DeleteMenus();
    }

    void DeleteMenus() {
        if (lookupMenu) {
            delete lookupMenu;
        }
        if (groupMenu) {
            delete groupMenu;
        }
        if (civIDMenu) {
            delete civIDMenu;
        }
    }
}