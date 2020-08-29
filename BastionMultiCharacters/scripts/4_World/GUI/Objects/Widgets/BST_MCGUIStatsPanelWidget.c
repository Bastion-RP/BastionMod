class BST_MCGUIStatsPanelWidget {
    private const int MAX_ENERGY = 20000;
    private const int MAX_WATER = 5000;

    private ref Widget _root, _parent, _pnlStats, _pnlBorder;
    private ref TextWidget _txtRespawn, _txtName, _txtHealth, _txtBlood, _txtEnergy, _txtWater;
    private ref BST_MCSavePlayerBasic _character;
    private DayZPlayer _survivor;
    private bool _isSelected, _canChoose;
    //private vector characterPos;

    void BST_MCGUIStatsPanelWidget(Widget parent, BST_MCSavePlayerBasic character) {
        _root = GetGame().GetWorkspace().CreateWidgets("BastionMod\\BastionMultiCharacters\\gui\\layouts\\SurvivorStatWidget.layout", parent);
        _txtRespawn = TextWidget.Cast(_root.FindAnyWidget("txtRespawn"));
        _txtName = TextWidget.Cast(_root.FindAnyWidget("txtName"));
        _txtHealth = TextWidget.Cast(_root.FindAnyWidget("txtHealth"));
        _txtBlood = TextWidget.Cast(_root.FindAnyWidget("txtBlood"));
        _txtEnergy = TextWidget.Cast(_root.FindAnyWidget("txtEnergy"));
        _txtWater = TextWidget.Cast(_root.FindAnyWidget("txtWater"));
        _pnlStats = _root.FindAnyWidget("pnlStats");
        _pnlBorder = _root.FindAnyWidget("pnlBorder");
        _parent = parent;
        _character = character;
        //cameraPos = GetBSTMCClientManager().GetSelectMenu().GetCameraPosition()
        //characterPos = ("" + cameraPos[0] + " " + (cameraPos[1] + 3) + " " + cameraPos[2]).ToVector();
        //dayzPlayer = GetGame().CreateObject(savePlayer.GetType(), characterPos, true);
        _survivor = DayZPlayer.Cast(GetGame().CreateObject(_character.GetType(), vector.Zero, true));

        /* if (dayzPlayer) {
            dayzPlayer.SetPosition(characterPos);
        } */
        Init();
        _txtName.SetText(_character.GetName());
        _root.Show(true);
    }

    void ~BST_MCGUIStatsPanelWidget() {
        if (_root) {
            _root.Unlink();
        }
        if (_survivor) {
            GetGame().ObjectDelete(_survivor);
            GetGame().ObjectRelease(_survivor);
        }
    }

    void Init() {
        _pnlStats.Show(false);
        _txtRespawn.Show(false);
        _canChoose = true;

        if (!_character.IsDead()) {
            InitStats();
            CreateSurvivorInventory();
            _pnlStats.Show(true);
        } else {
            int currentTimestamp = GetBSTLibTimestamp().GetCurrentTimestamp();
            int timestampDifference = currentTimestamp - _character.GetDeathTimestamp();
            int respawnTimer = GetBSTMCManager().GetConfig().GetRespawnTimer();

            _txtRespawn.Show(true);

            if (timestampDifference <= respawnTimer) {
                if (timestampDifference == respawnTimer) {
                    _txtRespawn.SetText("RESPAWN IN 1");
                } else {
                    _txtRespawn.SetText("RESPAWN IN " + (respawnTimer - timestampDifference));
                }
                _canChoose = false;
            }
        }
    }

    void Select() {
        _isSelected = true;

        _pnlBorder.SetColor(BST_MCColors.COLOR_RED);
    }

    void Deselect() {
        _isSelected = false;

        _pnlBorder.SetColor(BST_MCColors.COLOR_WHITE);
    }

    void OnMouseEnter() {
        if (!_isSelected) {
            _pnlBorder.SetColor(BST_MCColors.COLOR_LIGHT_GRAY);
        }
    }

    void OnMouseLeave() {
        if (!_isSelected) {
            _pnlBorder.SetColor(BST_MCColors.COLOR_WHITE);
        }
    }

    private void InitStats() {
        int percentHealth = (_character.GetHealth() * 100) / GetGame().ConfigGetFloat("CfgVehicles SurvivorBase DamageSystem GlobalHealth Health hitpoints");
        int percentBlood = (_character.GetBlood() * 100) / GetGame().ConfigGetFloat("CfgVehicles SurvivorBase DamageSystem GlobalHealth Blood hitpoints");
        int percentEnergy = (_character.GetEnergy() * 100) / MAX_ENERGY;
        int percentWater = (_character.GetWater() * 100) / MAX_WATER;

        _txtHealth.SetText("" + percentHealth + "%");
        _txtBlood.SetText("" + percentBlood + "%");
        _txtEnergy.SetText("" + percentEnergy + "%");
        _txtWater.SetText("" + percentWater + "%");
    }

    private void CreateSurvivorInventory() {
        array<ref BST_MCSaveObject> arrInventory = _character.GetInventory();

        foreach (BST_MCSaveObject saveObject : arrInventory) {
            EntityAI newItem;

            if (saveObject.IsInHands()) {
                newItem = _survivor.GetHumanInventory().CreateInHands(saveObject.GetType());
            } else {
                newItem = _survivor.GetInventory().CreateInInventory(saveObject.GetType());
            }
        }
    }

    Widget GetWidget() { return _root; }
    BST_MCSavePlayerBasic GetSavePlayer() { return _character; }
    DayZPlayer GetPlayer() { return _survivor; }
    bool CanChoose() { return _canChoose; }
}