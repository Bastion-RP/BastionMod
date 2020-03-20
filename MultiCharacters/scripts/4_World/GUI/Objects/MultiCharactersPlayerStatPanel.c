class MultiCharactersPlayerStatPanel {
    private ref Widget wRoot, wParent, pnlStats, pnlBorder;
    private ref TextWidget txtRespawn, txtName, txtHealth, txtBlood, txtEnergy, txtWater;
    private ref SavePlayer savePlayer;
    private DayZPlayer dayzPlayer
    private bool isSelected;

    // Consts
	private const int maxHealth = 100;
	private const int maxBlood = 5000;
	private const int maxEnergy = 20000;
	private const int maxWater = 5000;

    void MultiCharactersPlayerStatPanel(Widget wParent, SavePlayer savePlayer) {
        this.wParent = wParent;
        this.savePlayer = savePlayer;
        wRoot = GetGame().GetWorkspace().CreateWidgets("MultiCharacters\\gui\\layouts\\SurvivorStatWidget.layout", wParent);
        txtRespawn = TextWidget.Cast(wRoot.FindAnyWidget("txtRespawn"));
        txtName = TextWidget.Cast(wRoot.FindAnyWidget("txtName"));
        txtHealth = TextWidget.Cast(wRoot.FindAnyWidget("txtHealth"));
        txtBlood = TextWidget.Cast(wRoot.FindAnyWidget("txtBlood"));
        txtEnergy = TextWidget.Cast(wRoot.FindAnyWidget("txtEnergy"));
        txtWater = TextWidget.Cast(wRoot.FindAnyWidget("txtWater"));
        pnlStats = wRoot.FindAnyWidget("pnlStats");
        pnlBorder = wRoot.FindAnyWidget("pnlBorder");
        dayzPlayer = GetGame().CreateObject(savePlayer.GetType(), vector.Zero, true);

        Init();
        txtName.SetText(savePlayer.GetName());
        wRoot.Show(true);
    }

    void ~MultiCharactersPlayerStatPanel() {
        Print("[DEBUG] Deleting survivor stat panel");
        if (wRoot) {
            wRoot.Unlink();
        }
        if (dayzPlayer) {
            GetGame().ObjectDelete(dayzPlayer);
            GetGame().ObjectRelease(dayzPlayer);
        }
    }

    void Init() {
        pnlStats.Show(false);
        txtRespawn.Show(false);
        if (!savePlayer.IsDead()) {
            InitStats();
            CreateSurvivorInventory();
            pnlStats.Show(true);
        } else {
            txtRespawn.Show(true);
        }
    }

    void Select() {
        isSelected = true;

        pnlBorder.SetColor(MCColors.COLOR_RED);
    }

    void Deselect() {
        isSelected = false;

        pnlBorder.SetColor(MCColors.COLOR_WHITE);
    }

	void OnMouseEnter() {
        if (!isSelected) {
            pnlBorder.SetColor(MCColors.COLOR_LIGHT_GRAY);
        }
	}

	void OnMouseLeave() {
        if (!isSelected) {
            pnlBorder.SetColor(MCColors.COLOR_WHITE);
        }
	}

    private void InitStats() {
		int percentHealth = (savePlayer.GetHealth() * 100) / maxHealth;
		int percentBlood = (savePlayer.GetBlood() * 100) / maxBlood;
		int percentEnergy = (savePlayer.GetEnergy() * 100) / maxEnergy;
		int percentWater = (savePlayer.GetWater() * 100) / maxWater;
        
		txtHealth.SetText(percentHealth.ToString() + "%");
		txtBlood.SetText(percentBlood.ToString() + "%");
		txtEnergy.SetText(percentEnergy.ToString() + "%");
		txtWater.SetText(percentWater.ToString() + "%");
    }

    private void CreateSurvivorInventory() {
		array<ref SaveObject> arrayInventory = savePlayer.GetInventory();

        foreach (SaveObject saveObject : arrayInventory) {
            EntityAI newItem;

            if (saveObject.IsInHands()) {
                Print("[DEBUG] Save object is in hands!!!");
                newItem = dayzPlayer.GetHumanInventory().CreateInHands(saveObject.GetType())
            } else {
			    newItem = dayzPlayer.GetInventory().CreateInInventory(saveObject.GetType());
            }
            Print("[DEBUG] Item created=" + newItem);
        }
    }

    Widget GetWidget() {
        return wRoot;
    }

    SavePlayer GetSavePlayer() {
        return savePlayer;
    }

    DayZPlayer GetPlayer() {
        return dayzPlayer;
    }
}