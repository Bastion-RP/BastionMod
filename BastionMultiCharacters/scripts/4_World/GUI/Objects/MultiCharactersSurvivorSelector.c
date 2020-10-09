class MultiCharactersSurvivorSelector {
    private ref Widget wRoot, wParent, wCharacterFrame;
    private ref GridSpacerWidget gridRoot;
    private ref PlayerPreviewWidget survivorPreview;
    private ref ButtonWidget btnSpawn;
    private ref MultiCharactersPlayerStatPanel selectedSurvivor;
    private ref array<ref MultiCharactersPlayerStatPanel> arrayStatPanels;

    void MultiCharactersSurvivorSelector(Widget wParent) {
        this.wParent = wParent;
        wRoot = GetGame().GetWorkspace().CreateWidgets("BastionMod\\BastionMultiCharacters\\gui\\layouts\\CharacterSelectWidget.layout", wParent);
        wCharacterFrame = wRoot.FindAnyWidget("charFrame");
        gridRoot = GridSpacerWidget.Cast(wRoot.FindAnyWidget("gridPnlSurvivor"));
        survivorPreview = PlayerPreviewWidget.Cast(wRoot.FindAnyWidget("plyPreview"));
        btnSpawn = ButtonWidget.Cast(wRoot.FindAnyWidget("btnSpawn"));
        arrayStatPanels = new array<ref MultiCharactersPlayerStatPanel>();

        wCharacterFrame.Show(false);
        wRoot.Show(true);
        InitStatPanels();
    }

    void ~MultiCharactersSurvivorSelector() {
        Print(MCConst.debugPrefix + "Deleting survivor selector widget");
        if (wRoot) {
            wRoot.Unlink();
        }
        foreach (MultiCharactersPlayerStatPanel statPanel : arrayStatPanels) {
            if (statPanel) {
                delete statPanel;
            }
        }
    }

    void Init() {
        selectedSurvivor = null;

        foreach (MultiCharactersPlayerStatPanel statPanel : arrayStatPanels) {
            if (statPanel) {
                statPanel.Deselect();
            }
        }
        wCharacterFrame.Show(false);
    }

    void InitStatPanels() {
        array<ref BST_MCSavePlayerBasic> arrayLoadouts = GetMultiCharactersClientManager().GetLoadouts();
        foreach (BST_MCSavePlayerBasic savePlayer : arrayLoadouts) {
            if (savePlayer) {
                MultiCharactersPlayerStatPanel newStatPanel = new MultiCharactersPlayerStatPanel(gridRoot, savePlayer);
                arrayStatPanels.Insert(newStatPanel);
            }
        }
    }

    void OnClick(Widget w) {
        if (ButtonWidget.Cast(w) == btnSpawn && selectedSurvivor.CanChoose()) {
            Hide();
            GetDayZGame().SetSelectedSurvivorId(selectedSurvivor.GetSavePlayer().GetCharacterId());
            GetDayZGame().SetSelectedSurvivorName(selectedSurvivor.GetSavePlayer().GetName());
            GetDayZGame().ShowCountDown();
            return;
        }
    }

	void OnMouseButtonUp(Widget w) {
        // First, check to see if the widget is a panel. If not, don't do anything. Then, handle the rest.
        bool widgetFound;

        // This needs to be rewritten. No need to loop to check stuff. Just use RAM and store shit in a map...

        foreach(MultiCharactersPlayerStatPanel checkStatsPanel : arrayStatPanels) {
            if (checkStatsPanel) {
                if (checkStatsPanel.GetWidget() == w) {
                    widgetFound = true;
                    break;
                }
            }
        }
        if (!widgetFound) { return; }
        foreach(MultiCharactersPlayerStatPanel statsPanel : arrayStatPanels) {
            if (statsPanel) {
                if (statsPanel.GetWidget() == w) {
                    if (!statsPanel.GetSavePlayer().IsDead()) {
                        selectedSurvivor = statsPanel;

                        survivorPreview.SetPlayer(statsPanel.GetPlayer());
                        survivorPreview.Show(true);
                        statsPanel.Select();
                    } else if (statsPanel.CanChoose()){
                        GetDayZGame().SetSelectedSurvivorId(statsPanel.GetSavePlayer().GetCharacterId());
                        GetDayZGame().SetSelectedSurvivorName(statsPanel.GetSavePlayer().GetName());
                        Hide();
                        break;
                    }
                } else {
                    statsPanel.Deselect();
                }
            }
        }
        if (selectedSurvivor) {
            wCharacterFrame.Show(true);
        } else {
            wCharacterFrame.Show(false);
        }
    }

	void OnMouseEnter(Widget w) {
        foreach(MultiCharactersPlayerStatPanel statsPanel : arrayStatPanels) {
            if (statsPanel && statsPanel.GetWidget() == w) {
                statsPanel.OnMouseEnter();
                break;
            }
        }
	}

	void OnMouseLeave(Widget w) {
        foreach(MultiCharactersPlayerStatPanel statsPanel : arrayStatPanels) {
            if (statsPanel && statsPanel.GetWidget() == w) {
                statsPanel.OnMouseLeave();
                break;
            }
        }
	}

    void Show() {
        wRoot.Show(true);
        Init();
    }

    void Hide() {
        wRoot.Show(false);
    }

    MultiCharactersPlayerStatPanel GetStatPanel(Widget w) {
        foreach (MultiCharactersPlayerStatPanel statPanel : arrayStatPanels) {
            if (statPanel && statPanel.GetWidget() == w) {
                return statPanel;
            }
        }
        return null;
    }

    bool IsVisible() {
        return wRoot.IsVisible();
    }
}