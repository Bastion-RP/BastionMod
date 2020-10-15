class BST_MCGUIPlyPreviewSmallWidget : BST_MCGUIWidget {
    private const int CONST_SIZE = 96;
    
    private ref Widget _pnlBG, _pnlBorder, _pnlPreview;
    private ref PlayerPreviewWidget _preview;
    private ref ImageWidget _imgNoChar
    private DayZPlayer _player;
    private EntityAI _itemInHands;

    void Init(bool showBorder = true) {
        _root = GetGame().GetWorkspace().CreateWidgets("BastionMod/BastionMultiCharacters/gui/layout/SmallSurvivorPreviewWidget.layout", _parent);
        _pnlBG = _root.FindAnyWidget("pnlBG");
        _pnlBorder = _root.FindAnyWidget("pnlBorder");
        _pnlPreview = _root.FindAnyWidget("pnlPreview");
        _preview = PlayerPreviewWidget.Cast(_root.FindAnyWidget("plyPreview"));
        _imgNoChar = ImageWidget.Cast(_root.FindAnyWidget("imgPortrait"));

        _pnlBG.Show(false);
        _imgNoChar.Show(false);
        _preview.Show(true);
        _pnlBorder.Show(showBorder);

        if (!showBorder) {
            _pnlPreview.SetSize(CONST_SIZE, CONST_SIZE);
            _pnlPreview.SetPos(0, 0);
        }
    }

    void Select(bool isSelected) {
        _pnlBG.Show(isSelected);

        if (isSelected) {
            _imgNoChar.SetColor(ARGB(255, 255, 255, 255));
        } else {
            _imgNoChar.SetColor(ARGB(255, 255, 168, 0))
        }
    }

    void ShowPortrait(bool showPortrait) {
        _imgNoChar.Show(showPortrait);
        _preview.Show(!showPortrait);
    }

    void SetFlags(int flag) {
        _root.SetFlags(flag);
    }

    void CreateNewPlayer(string charType) {
        _player = DayZPlayer.Cast(GetGame().CreateObjectEx(charType, "0 0 0", ECE_LOCAL));
        
        _preview.SetPlayer(_player);
    }

    void BuildExistingPlayer(BST_MCSavePlayerBasic character) {
        array<ref BST_MCSaveObject> arrInventory = character.GetInventory();
        _player = DayZPlayer.Cast(GetGame().CreateObjectEx(character.GetType(), "0 0 0", ECE_LOCAL));
        
        foreach (BST_MCSaveObject obj : arrInventory) {
            if (!obj) { continue; }
            if (obj.IsInHands()) {
                _itemInHands = _player.GetHumanInventory().CreateInHands(obj.GetType());
            } else {
                _player.GetInventory().CreateInInventory(obj.GetType());
            }
        }
        _preview.SetPlayer(_player);
        _preview.UpdateItemInHands(_itemInHands);
    }

    DayZPlayer GetPlayer() { return _player; }
    EntityAI GetItemInHands() { return _itemInHands; }

    void ~BST_MCGUIPlyPreviewSmallWidget() {
        if (_player) {
            GetGame().ObjectDelete(_player);
        }
        if (_itemInHands) {
            GetGame().ObjectDelete(_itemInHands);
        }
    }
}