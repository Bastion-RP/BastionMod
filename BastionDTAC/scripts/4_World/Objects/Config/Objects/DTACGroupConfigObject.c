class DTACGroupConfigObject {
    private static const string DEFAULT_HEADER_COLOR = "255 255 255";
    private static const string DEFAULT_GROUP_NAME = "TEMP GROUP NAME";
    private static const int DEFAULT_GROUP_CAPACITY = 5;
    
    private string GroupName;
    private int GroupCapactity;
    private string GroupHeaderColor;

    void Validate() {
        if (GroupName == string.Empty) {
            GroupName = DEFAULT_GROUP_NAME;
        }
        if (GroupCapactity < 1) {
            GroupCapactity = DEFAULT_GROUP_CAPACITY;
        }
        if (GroupHeaderColor == string.Empty || !GroupHeaderColor.ToVector()) {
            GroupHeaderColor = DEFAULT_HEADER_COLOR;
        }
    }

    string GetName() { return GroupName; }
    int GetCapacity() { return GroupCapactity; }
    int GetColor() {
        vector color = GroupHeaderColor.ToVector();

        return ARGB(255, color[0].ToString().ToInt(), color[1].ToString().ToInt(), color[2].ToString().ToInt());
    }
}