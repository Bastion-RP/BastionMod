class BST_DTACCivIDMenu {
    private ref Widget wRoot, wParent;
    private ref TextWidget txtName, txtID, txtClass;

    void BST_DTACCivIDMenu(Widget wParent) {
        this.wParent = wParent;
        wRoot = GetGame().GetWorkspace().CreateWidgets("BastionMod\\BastionDTAC\\gui\\layouts\\IdMenu.layout", wParent);
        txtName = TextWidget.Cast(wRoot.FindAnyWidget("txtName"));
        txtID = TextWidget.Cast(wRoot.FindAnyWidget("txtId"));
        txtClass = TextWidget.Cast(wRoot.FindAnyWidget("txtClass"));

        txtName.SetText("Name: " + PlayerBase.Cast(GetGame().GetPlayer()).GetMultiCharactersPlayerName());
        txtID.SetText("ID: " + PlayerBase.Cast(GetGame().GetPlayer()).GetMultiCharactersPlayerId());

        // change _ to - for the class (enum can't have hypen in it's name)
        string t_ClassText = typename.EnumToString(BastionClasses, PlayerBase.Cast(GetGame().GetPlayer()).GetMultiCharactersPlayerClass());
        t_ClassText.Replace("_","-");

        txtClass.SetText("Class: " + t_ClassText);
    }

    void ~BST_DTACCivIDMenu() {
        if (wRoot) {
            wRoot.Unlink();
        }
    }
}