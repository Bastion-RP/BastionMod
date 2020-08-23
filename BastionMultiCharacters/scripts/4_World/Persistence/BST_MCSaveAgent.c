class BST_MCSaveAgent {
    int _key, _value;

    void BST_MCSaveAgent(int key, int value) {
        _key = key;
        _value = value;
    }

    int GetKey() { return _key; }
    int GetValue() { return _value; }
}