class MultiCharactersSurvivorCreator {
    private ref Widget wRoot, wParent, btnBack;
    private ref ButtonWidget btnSpawn;
    private ref PlayerPreviewWidget survivorPreview;
    private ref GridSpacerWidget gridPreviewWidgets;
    private ref MultiCharactersSurvivorPreviewWidget selectedSurvivor;
    private ref array<ref MultiCharactersSurvivorPreviewWidget> arrayPreviewWidgets;
	private ref array<string> arraySurvivorTypes;

    void MultiCharactersSurvivorCreator(Widget wParent) {
        this.wParent = wParent;
        wRoot = GetGame().GetWorkspace().CreateWidgets("MultiCharacters\\gui\\layouts\\CharacterCreateWidget.layout", wParent);
        btnBack = wRoot.FindAnyWidget("previousMenu");
        survivorPreview = PlayerPreviewWidget.Cast(wRoot.FindAnyWidget("playerPreview"));
        gridPreviewWidgets = GridSpacerWidget.Cast(wRoot.FindAnyWidget("spacer"));
        btnSpawn = ButtonWidget.Cast(wRoot.FindAnyWidget("btnCreateSpawn"));

        arrayPreviewWidgets = new array<ref MultiCharactersSurvivorPreviewWidget>();
		arraySurvivorTypes = GetGame().ListAvailableCharacters();

        Init();
        InitPreviewWidgets();
        survivorPreview.Show(false);
        btnSpawn.Show(false);
        wRoot.Show(false);
    }

    void ~MultiCharactersSurvivorCreator() {
        Print(MCConst.debugPrefix + "Deleting survivor creator widget");
        if (wRoot) {
            wRoot.Unlink();
            delete wRoot;
        }
        foreach (MultiCharactersSurvivorPreviewWidget previewWidget : arrayPreviewWidgets) {
            if (previewWidget) {
                delete previewWidget;
            }
        }
    }

    void Init() {
        selectedSurvivor = null;
        
        foreach(MultiCharactersSurvivorPreviewWidget previewWidget : arrayPreviewWidgets) {
            if (previewWidget) {
                previewWidget.Deselect();
            }
        }
        btnBack.SetColor(MCColors.COLOR_YELLOW);
        survivorPreview.Show(false);
        btnSpawn.Show(false);
    }

    void InitPreviewWidgets() {
        foreach(string type : arraySurvivorTypes) {
            MultiCharactersSurvivorPreviewWidget newPreviewWidget = new MultiCharactersSurvivorPreviewWidget(gridPreviewWidgets, type);
            arrayPreviewWidgets.Insert(newPreviewWidget);
        }
    }

    void OnClick(Widget w) {
        if (ButtonWidget.Cast(w) == btnSpawn) {
            Hide();
            SetGameVariables();
            GetDayZGame().ShowCountDown();
            return;
        }
    }

	void OnMouseButtonUp(Widget w) {
        if (w == btnBack) {
            Hide();
        } else {
            if (PlayerPreviewWidget.Cast(w)) {
                foreach(MultiCharactersSurvivorPreviewWidget previewWidget : arrayPreviewWidgets) {
                    if (previewWidget) {
                        if (previewWidget.GetPreviewWidget() == w) {
                            selectedSurvivor = previewWidget;

                            survivorPreview.SetPlayer(previewWidget.GetPlayer());
                            survivorPreview.Show(true);
                            previewWidget.Select();
                        } else {
                            previewWidget.Deselect();
                        }
                    }
                }
            }
        }
        if (selectedSurvivor) {
            btnSpawn.Show(true);
        } else {
            survivorPreview.Show(false);
            btnSpawn.Show(false);
        }
    }

	void OnMouseEnter(Widget w) {
        if (w == btnBack) {
            btnBack.SetColor(MCColors.COLOR_DARK_YELLOW);
        } else {
            if (PlayerPreviewWidget.Cast(w)) {
                foreach(MultiCharactersSurvivorPreviewWidget previewWidget : arrayPreviewWidgets) {
                    if (previewWidget && previewWidget.GetPreviewWidget() == w) {
                        previewWidget.OnMouseEnter();
                        break;
                    }
                }
            }
        }
	}

	void OnMouseLeave(Widget w) {
        if (w == btnBack) {
            btnBack.SetColor(MCColors.COLOR_YELLOW);
        } else {
            if (PlayerPreviewWidget.Cast(w)) {
                foreach(MultiCharactersSurvivorPreviewWidget previewWidget : arrayPreviewWidgets) {
                    if (previewWidget && previewWidget.GetPreviewWidget() == w) {
                        previewWidget.OnMouseLeave();
                        break;
                    }
                }
            }
        }
	}

    void Unlink() {
        wRoot.Unlink();
    }

    void Show() {
        wRoot.Show(true);
        Init();
    }

    void Hide() {
        wRoot.Show(false);
    }

    void SetGameVariables() {
        GetDayZGame().SetSelectedSurvivorType(selectedSurvivor.GetPlayer().GetType());
    }

    Widget GetBackButton() {
        return btnBack;
    }

    ButtonWidget GetSpawnButton() {
        return btnSpawn;
    }
    
    bool IsVisible() {
        return wRoot.IsVisible();
    }
}