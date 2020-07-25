class BST_DTAC_CURL_CriminalRecord : BST_DTAC_CURL_GeneralRecord {
    private string crime_committed, punishment, date_commited;

    string GetCrimeCommitted() { return crime_committed; }
    string GetPunishment() { return punishment; }
    string GetDateCommitted() { return date_commited; }
    string NewToString() {
        return super.NewToString() + ", crime_committed:" + crime_committed + ", punishment:" + punishment + ", date_commited:" + date_commited;
    }
}