class BST_DTAC_CURL_GeneralRecord {
    private string id, description, input_by, date_added, input_by_member_id;

    string GetId() { return id; }
    string GetDescription() { return description; }
    string GetInputBy() { return input_by; }
    string GetDateAdded() { return date_added; }
    string GetInputMemberId() { return input_by_member_id; }
    string NewToString() { return "id:" + id + ", input_by:" + input_by + ", date_added:" + date_added + ", input_by_member_id:" + input_by_member_id; }
}