class MagObject
{
    string m_Type;
    int m_AmmoCount;

    void MagObject(string type, int count) {
        m_Type = type;
        m_AmmoCount = count;
    }

    string GetType() {
        return m_Type;
    }

    int GetCount() {
        return m_AmmoCount;
    }
}