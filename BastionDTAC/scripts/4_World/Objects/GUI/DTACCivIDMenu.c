class DTACCivIDMenu {
    private ref Widget wRoot, wParent;
    private ref TextWidget txtName, txtID, txtClass;

    void DTACCivIDMenu(Widget wParent) {
        this.wParent = wParent;
        wRoot = GetGame().GetWorkspace().CreateWidgets("BastionDTAC\\gui\\layouts\\IdMenu.layout", wParent);
        txtName = TextWidget.Cast(wRoot.FindAnyWidget("txtName"));
        txtID = TextWidget.Cast(wRoot.FindAnyWidget("txtId"));
        txtClass = TextWidget.Cast(wRoot.FindAnyWidget("txtClass"));

        Print("[DEBUG] DTACCivIDMenu | DTACCivIDMenu | Civ Class Num=" + PlayerBase.Cast(GetGame().GetPlayer()).GetMultiCharactersPlayerClass());

        txtName.SetText("Name: " + PlayerBase.Cast(GetGame().GetPlayer()).GetMultiCharactersPlayerName());
        txtID.SetText("ID: " + PlayerBase.Cast(GetGame().GetPlayer()).GetMultiCharactersPlayerId());
        txtClass.SetText("Class: " + typename.EnumToString(BastionClasses, PlayerBase.Cast(GetGame().GetPlayer()).GetMultiCharactersPlayerClass()));
    }

    void ~DTACCivIDMenu() {
        if (wRoot) {
            wRoot.Unlink();
        }
    }
}