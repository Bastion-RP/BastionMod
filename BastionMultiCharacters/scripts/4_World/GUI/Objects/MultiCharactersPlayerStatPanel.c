class MultiCharactersPlayerStatPanel {
    private ref Widget wRoot, wParent, pnlStats, pnlBorder;
    private ref TextWidget txtRespawn, txtName, txtHealth, txtBlood, txtEnergy, txtWater;
    private ref SavePlayer savePlayer;
    private DayZPlayer dayzPlayer
    private vector characterPos;
    private bool isSelected;

    // Consts
	private const int maxHealth = 100;  // not used
	private const int maxBlood = 5000;  // not used
	private const int maxEnergy = 20000;
	private const int maxWater = 5000;

    void MultiCharactersPlayerStatPanel(Widget wParent, SavePlayer savePlayer) {
        vector cameraPos, characterPos;
        this.wParent = wParent;
        this.savePlayer = savePlayer;
        wRoot = GetGame().GetWorkspace().CreateWidgets("BastionMod\\BastionMultiCharacters\\gui\\layouts\\SurvivorStatWidget.layout", wParent);
        txtRespawn = TextWidget.Cast(wRoot.FindAnyWidget("txtRespawn"));
        txtName = TextWidget.Cast(wRoot.FindAnyWidget("txtName"));
        txtHealth = TextWidget.Cast(wRoot.FindAnyWidget("txtHealth"));
        txtBlood = TextWidget.Cast(wRoot.FindAnyWidget("txtBlood"));
        txtEnergy = TextWidget.Cast(wRoot.FindAnyWidget("txtEnergy"));
        txtWater = TextWidget.Cast(wRoot.FindAnyWidget("txtWater"));
        pnlStats = wRoot.FindAnyWidget("pnlStats");
        pnlBorder = wRoot.FindAnyWidget("pnlBorder");
        //cameraPos = GetMultiCharactersClientManager().GetSelectMenu().GetCameraPosition()
        //characterPos = ("" + cameraPos[0] + " " + (cameraPos[1] + 3) + " " + cameraPos[2]).ToVector();
        //dayzPlayer = GetGame().CreateObject(savePlayer.GetType(), characterPos, true);
        dayzPlayer = DayZPlayer.Cast(GetGame().CreateObject(savePlayer.GetType(), vector.Zero, true));

        /* if (dayzPlayer) {
            dayzPlayer.SetPosition(characterPos);
        } */
        Init();
        txtName.SetText(savePlayer.GetName());
        wRoot.Show(true);
    }

    void ~MultiCharactersPlayerStatPanel() {
        Print(MCConst.debugPrefix + "Deleting survivor stat panel");
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

        // Use config value for max HP and max blood
		int percentHealth = (savePlayer.GetHealth() * 100) / GetGame().ConfigGetFloat("CfgVehicles SurvivorBase DamageSystem GlobalHealth Health hitpoints");
		int percentBlood = (savePlayer.GetBlood() * 100) / GetGame().ConfigGetFloat("CfgVehicles SurvivorBase DamageSystem GlobalHealth Blood hitpoints");

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
                Print(MCConst.debugPrefix + "Save object is in hands!!!");
                newItem = dayzPlayer.GetHumanInventory().CreateInHands(saveObject.GetType());
            } else {
			    newItem = dayzPlayer.GetInventory().CreateInInventory(saveObject.GetType());
            }
            Print(MCConst.debugPrefix + "Item created=" + newItem);
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