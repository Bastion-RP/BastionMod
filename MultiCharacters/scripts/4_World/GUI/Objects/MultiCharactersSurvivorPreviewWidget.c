class MultiCharactersSurvivorPreviewWidget {
    private ref Widget wRoot, wParent, pnlBG;
    private ref PlayerPreviewWidget wSurvivorPreview;
    private DayZPlayer dayzPlayer;
    private bool isSelected;

    void MultiCharactersSurvivorPreviewWidget(Widget wParent, string survivorType) {
        this.wParent = wParent;
        wRoot = GetGame().GetWorkspace().CreateWidgets("MultiCharacters\\gui\\layouts\\SurvivorPreviewWidget.layout", wParent);
        wSurvivorPreview = PlayerPreviewWidget.Cast(wRoot.FindAnyWidget("survivorPreview"));
        dayzPlayer = GetGame().CreateObject(survivorType, vector.Zero, true);
        pnlBG = wRoot.FindAnyWidget("pnlBG");

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