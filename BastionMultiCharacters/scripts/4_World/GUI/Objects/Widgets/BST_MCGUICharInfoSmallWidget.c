class BST_MCGUICharInfoSmallWidget : BST_MCGUIWidget {
    private const string CONST_ALIVE_TEXT = "Alive and Well";
    private const string CONST_DEAD_TEXT = "Incapacitated";
    private const int BST_COLOR_GREEN = ARGB(255, 30, 213, 0);
    private const int BST_COLOR_RED = ARGB(255, 255, 0, 0);

    private ref TextWidget _txtName, _txtId, _txtCDStatus, _txtCooldown;
    private ref BST_MCGUIPlyPreviewSmallWidget _plyPreview;
    private ref BST_MCSavePlayerBasic _character;
    private bool _onCooldown;

    void Init(ScriptedWidgetEventHandler handler, BST_MCSavePlayerBasic character) {
        _character = character;
        _root = GetGame().GetWorkspace().CreateWidgets("BastionMod/BastionMultiCharacters/gui/layout/CharacterSelectWidgetSmall.layout", _parent);
        _txtName = TextWidget.Cast(_root.FindAnyWidget("txtName"));
        _txtId = TextWidget.Cast(_root.FindAnyWidget("txtId"));
        _txtCDStatus = TextWidget.Cast(_root.FindAnyWidget("txtCdStatus"));
        _txtCooldown = TextWidget.Cast(_root.FindAnyWidget("txtCooldown"));
        _plyPreview = new BST_MCGUIPlyPreviewSmallWidget(_root);

        _root.SetHandler(handler);
        _plyPreview.Init(false);
        _plyPreview.CreatePlayer(_character);
        SetInfo();
    }

    void Select(bool isSelected) {
        _plyPreview.Select(isSelected);
    }

    private void SetInfo() {
        int currentTimestamp = GetBSTLibTimestamp().GetCurrentTimestamp();
        int timestampDifference = currentTimestamp - _character.GetDeathTimestamp();
        int respawnTimer = GetBSTMCManager().GetConfig().GetRespawnTimer();
        string txtClass = typename.EnumToString(BastionClasses, _character.GetCharacterClass());

        txtClass.Replace("_", "-");
        _txtName.SetText(_character.GetName());
        _txtId.SetText("ID #: " + _character.GetCharacterId() + " \ Class: " + txtClass);

        if (_character.IsDead() && _character.GetType() == "") {
            _txtCDStatus.SetText("NOT READY ");
            _txtCooldown.SetText("CREATE NEW CHARACTER");
            _txtCDStatus.SetColor(BST_COLOR_RED);
        } else if (_character.IsDead() && timestampDifference <= respawnTimer) {
            _onCooldown = true;

            _txtCDStatus.SetText("ON COOLDOWN ");

            if (timestampDifference == respawnTimer) {
                _txtCooldown.SetText("FOR 1 MINUTE");
            } else {
                _txtCooldown.SetText("FOR " + (respawnTimer - timestampDifference) + " MINUTES");
            }
            _txtCDStatus.SetColor(BST_COLOR_RED);
        } else {
            _txtCDStatus.SetText("READY ");
            _txtCooldown.SetText("TO PLAY");
            _txtCDStatus.SetColor(BST_COLOR_GREEN);
        }
    }

    bool IsOnCooldown() { return _onCooldown; }
    BST_MCSavePlayerBasic GetCharacter() { return _character; }
    BST_MCGUIPlyPreviewSmallWidget GetPlayerPreview() { return _plyPreview; }

    void ~BST_MCGUICharInfoSmallWidget() {
        if (_root) {
            _root.Unlink();
        }
        if (_plyPreview) {
            delete _plyPreview;
        }
    }
}