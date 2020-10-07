class BST_MCMagObject {
    private string _type;
    private int _count;

    void BST_MCMagObject(string type, int count) {
        _type = type;
        _count = count;
    }

    string GetType() { return _type; }
    int GetCount() { return _count; }
}