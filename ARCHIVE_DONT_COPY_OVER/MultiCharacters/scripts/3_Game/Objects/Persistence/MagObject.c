class MagObject {
    private string magType;
    private int ammoCount;

    void MagObject(string type, int count) {
        magType = type;
        ammoCount = count;
    }

    string GetType() {
        return magType;
    }

    int GetCount() {
        return ammoCount;
    }
}