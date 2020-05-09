class BST_CompassHUD {
    private static const int CONST_NUM_DEGREE = 360;

    private ref Widget wRoot;
    private ref ImageWidget compassNums;
    private int steps;

    void BST_CompassHUD() {
        float rootHeight, rootWidth, compassHeight, compassWidth, totalWidth;

		wRoot = GetGame().GetWorkspace().CreateWidgets("BastionMod\\BastionDTAC\\gui\\layouts\\HUDCompass.layout");
        compassNums = ImageWidget.Cast(wRoot.FindAnyWidget("imgCompass"));

        wRoot.GetSize(rootWidth, rootHeight);
        compassNums.GetSize(compassWidth, compassHeight);

        totalWidth = compassWidth - (rootWidth * 2);
        steps = totalWidth / CONST_NUM_DEGREE;

        StartUpdateLoop();
    }

    void ~BST_CompassHUD() {
        if (wRoot) {
            wRoot.Unlink();
        }
    }

    void StartUpdateLoop() {
        GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(this.UpdateBearing, 10, true);
    }

    void UpdateBearing() {
        if (!GetGame().GetPlayer()) { return; }

        float angX = GetGame().GetCurrentCameraDirection().VectorToAngles().GetRelAngles()[0];

        compassNums.SetPos((angX * -1) * steps, 0);
    }
}