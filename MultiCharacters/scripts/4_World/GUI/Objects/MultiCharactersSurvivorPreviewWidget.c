class MultiCharactersSurvivorPreviewWidget {
    private ref Widget wRoot, wParent, pnlBG;
    private ref PlayerPreviewWidget wSurvivorPreview;
    private DayZPlayer dayzPlayer;
    private bool isSelected;

    void MultiCharactersSurvivorPreviewWidget(Widget wParent, string survivorType) {
        vector cameraPos, characterPos;
        this.wParent = wParent;
        wRoot = GetGame().GetWorkspace().CreateWidgets("MultiCharacters\\gui\\layouts\\SurvivorPreviewWidget.layout", wParent);
        wSurvivorPreview = PlayerPreviewWidget.Cast(wRoot.FindAnyWidget("survivorPreview"));
        pnlBG = wRoot.FindAnyWidget("pnlBG");
        cameraPos = GetMultiCharactersClientManager().GetSelectMenu().GetCameraPosition()
        characterPos = ("" + cameraPos[0] + " " + (cameraPos[1] + 3) + " " + cameraPos[2]).ToVector();
        dayzPlayer = GetGame().CreateObject(survivorType, characterPos, true);

        Print(MCConst.debugPrefix + " | inactive pos=" + characterPos);
        dayzPlayer.SetPosition(characterPos);
        wSurvivorPreview.SetPlayer(dayzPlayer);
        pnlBG.Show(false);
    }

    void ~MultiCharactersSurvivorPreviewWidget() {
        Print(MCConst.debugPrefix + "Deleting survivor preview widget");
        if (wRoot) {
            wRoot.Unlink();
            delete wRoot;
        }
        if (dayzPlayer) {
            GetGame().ObjectDelete(dayzPlayer);
            GetGame().ObjectRelease(dayzPlayer);
        }
    }

    void Select() {
        isSelected = true;

        pnlBG.SetColor(MCColors.COLOR_TRANS_RED);
        pnlBG.Show(true);
    }

    void Deselect() {
        isSelected = false;

        pnlBG.Show(false);
    }

	void OnMouseEnter() {
        if (!isSelected) {
            pnlBG.SetColor(MCColors.COLOR_TRANS_DARK_GRAY);
            pnlBG.Show(true);
        }
	}

	void OnMouseLeave() {
        if (!isSelected) {
            pnlBG.Show(false);
        }
	}

    Widget GetWidget() {
        return wRoot;
    }

    PlayerPreviewWidget GetPreviewWidget() {
        return wSurvivorPreview;
    }

    DayZPlayer GetPlayer() {
        return dayzPlayer;
    }
}