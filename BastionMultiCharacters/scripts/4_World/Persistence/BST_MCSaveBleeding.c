class BST_MCSaveBleeding {
    private int _activeBits;
    private ref array<int> _arrActiveTime;

    void BST_MCSaveBleeding(int bits) {
        _arrActiveTime = new array<int>();
        _activeBits = bits;
    }

    void Insert(int time) {
        _arrActiveTime.Insert(time);
    }

    array<int> GetActiveTimes() { return _arrActiveTime; }
    int GetBits() { return _activeBits; }
}