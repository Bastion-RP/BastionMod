class BST_MCGUIPlyPreviewSmallWidget : BST_MCGUIWidget {
    private ref Widget _pnlBG, _pnlBorder;
    private ref PlayerPreviewWidget _preview;
    private DayZPlayer _player;
    private EntityAI _itemInHands;

    void Init(bool showBG = true) {
        _root = GetGame().GetWorkspace().CreateWidgets("BastionMod/BastionMultiCharacters/gui/layout/SmallSurvivorPreviewWidget.layout", _parent);
        _pnlBG = _root.FindAnyWidget("pnlBG");
        _pnlBorder = _root.FindAnyWidget("pnlBorder");
        _preview = PlayerPreviewWidget.Cast(_root.FindAnyWidget("plyPreview"));

        _pnlBG.Show(false);
        _pnlBorder.Show(showBG);
    }

    void Select(bool isSelected) {
        _pnlBG.Show(isSelected);
    }

    void CreatePlayer(BST_MCSavePlayerBasic character) {
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