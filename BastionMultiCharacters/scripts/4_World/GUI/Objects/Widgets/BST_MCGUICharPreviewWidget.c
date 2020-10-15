class BST_MCGUICharPreviewWidget : BST_MCGUIWidget {
    private ref PlayerPreviewWidget _playerPreview;
    
    void Init(ScriptedWidgetEventHandler handler, int x, int y) {
        _root = GetGame().GetWorkspace().CreateWidgets("BastionMod/BastionMultiCharacters/gui/layout/CharacterPreviewWidget.layout", _parent);
        _playerPreview = PlayerPreviewWidget.Cast(_root.FindAnyWidget("prvPlayer"));
        _handler = handler;

        _root.SetPos(x, y);
    }

    void SetPlayer(DayZPlayer player, EntityAI itemInHands) {
        _playerPreview.SetPlayer(player);
        _playerPreview.UpdateItemInHands(itemInHands);
    }
}