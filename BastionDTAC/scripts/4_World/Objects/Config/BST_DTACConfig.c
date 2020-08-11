class BST_DTACConfig {
    private const string DEFAULT_PHONE_CLASSNAME = "BRP_DyerPhoneV2";

    private ref array<string> APIRequiredClasses;
    private string PhoneClassname;

    void BST_DTACConfig() {
        APIRequiredClasses = new array<string>();
        PhoneClassname = DEFAULT_PHONE_CLASSNAME;

        APIRequiredClasses.Insert("isf");
    }

    void Validate() {
        if (PhoneClassname == "") {
            PhoneClassname = DEFAULT_PHONE_CLASSNAME;
        }
    }
    
    array<string> GetRequiredAPIClasses() { return APIRequiredClasses; }
    string GetPhoneClassname() { return PhoneClassname; }
}