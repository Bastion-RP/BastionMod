class BST_MCGUICharInfoWidget : BST_MCGUIWidget {
    private const string CONST_ALIVE_TEXT = "Alive and Well";
    private const string CONST_DEAD_TEXT = "Incapacitated";

    private ref TextWidget _txtNameFirst, _txtNameLast, _txtId, _txtClass, _txtStatus, _txtCannotPlay;
    private ref ButtonWidget _btnCanPlay;

    void Init(ScriptedWidgetEventHandler handler, int x, int y) {
        _root = GetGame().GetWorkspace().CreateWidgets("BastionMod/BastionMultiCharacters/gui/layout/CharacterSelectWidget.layout", _parent);
        _txtNameFirst = TextWidget.Cast(_root.FindAnyWidget("txtNameFirst"));
        _txtNameLast = TextWidget.Cast(_root.FindAnyWidget("txtNameLast"));
        _txtId = TextWidget.Cast(_root.FindAnyWidget("txtId"));
        _txtClass = TextWidget.Cast(_root.FindAnyWidget("txtCivClass"));
        _txtStatus = TextWidget.Cast(_root.FindAnyWidget("txtStatus"));
        _btnCanPlay = ButtonWidget.Cast(_root.FindAnyWidget("btnPlay"));
        _txtCannotPlay = TextWidget.Cast(_root.FindAnyWidget("btnCannotPlay"));

        _root.SetPos(x, y);
        _root.SetHandler(handler);
    }

    void SetCharacter(BST_MCSavePlayerBasic character) {
        array<string> charName = new array<string>();

        character.GetName().Split(" ", charName);
        _txtNameFirst.SetText(charName[0] + " ");
        _txtNameLast.SetText(charName[1]);
        _txtId.SetText("" + character.GetCharacterId());
        _txtClass.SetText(GetBSTAPIHandler().GetClassNameFromInt(character.GetCharacterClass()));
    }

    void ChangeButtons(int caseInt) {
        switch (caseInt) {
            case 0:
                {
                    _btnCanPlay.Show(true);
                    _txtCannotPlay.Show(false);
                    _txtStatus.SetText("Alive");
                    _btnCanPlay.SetText("CONFIRM & PLAY");
                    break;
                }
            case 1:
                {
                    _btnCanPlay.Show(true);
                    _txtCannotPlay.Show(false);
                    _txtStatus.SetText("Alive and Well");
                    _btnCanPlay.SetText("PLAY");
                    break;
                }
            case 2:
                {
                    _btnCanPlay.Show(false);
                    _txtCannotPlay.Show(true);
                    _txtStatus.SetText("Incapacitated");
                    break;
                }
        }
    }
}