class BBConst {
    static const string profileDir = "$profile:\\Bastion";
    static const string modDir = "$profile:\\Bastion\\Banking";
    static const string playerDir = "$profile:\\Bastion\\Banking\\Players";
    static const string accountDir = "$profile:\\Bastion\\Banking\\Accounts";
    static const string trackerDir = "$profile:\\Bastion\\Banking\\StatTracking.json";
    static const string wagesDir = "$profile:\\Bastion\\Banking\\JobWages.json";
    static const string configDir = "$profile:\\Bastion\\Banking\\Config.json";
    static const string fileType = ".json";

    static const string ACCOUNT_ID = "id";
    static const string ACCOUNT_FUNDS = "funds";
    static const string ACCOUNT_OVERFLOW = "overflow";
    static const string ACCOUNT_TO_OVERFLOW = "depositoverflow";
    static const string ACCOUNT_DEPOSITED = "deposit";
    static const string ACCOUNT_WITHDRAW = "withdraw";
    static const string ACCOUNT_TRANSFER_FEE = "transferfee";
    static const string ACCOUNT_TRANSFER_AMOUNT = "transferamount";
    static const string ACCOUNT_TRANSFER_DIFFERENCE = "transferdifference";
}

enum BBRPCTypes {
    ACCOUNT_GET_BALANCE = -93782,
    ACCOUNT_DEPOSIT,
    ACCOUNT_WITHDRAW,
    ACCOUNT_TRANSFER,
    ACCOUNT_TRANSFER_CAPPED,
    ACCOUNT_REGISTER,
    ACCOUNT_LOGIN,
    ACCOUNT_LOGOUT,

    ERROR_ACCEPT_TRANSFER,
    ERROR_ACCEPT_OVERFLOW,
    ERROR_NO_FUNDS_DEPOSIT,
    ERROR_NO_FUNDS_WITHDRAW,
    ERROR_NO_FUNDS_TRANSFER,
    ERROR_ALREADY_REGISTERED,
    ERROR_NO_LOGIN,
    ERROR_LOGGED_IN,
    ERROR_INVALID_LOGIN
}