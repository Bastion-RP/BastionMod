class BST_DTAC_CURL_CriminalRecord : BST_DTAC_CURL_GeneralRecord {
    private string crime_commited, punishment, date_commited;

    string GetCrimeCommitted() { return crime_commited; }
    string GetPunishment() { return punishment; }
    string GetDateCommitted() { return date_commited; }
    string NewToString() {
        return super.NewToString() + ", crime_commited:" + crime_commited + ", punishment:" + punishment + ", date_commited:" + date_commited;
    }
}