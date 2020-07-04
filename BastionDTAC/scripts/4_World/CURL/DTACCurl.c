class DTACCurl extends RestCallback {
    static ref ScriptInvoker dtacData = new ScriptInvoker();

    override void OnError(int errorCode) {
        Print("Error Code:" + errorCode);
    };

    override void OnTimeout() {
        Print("Request Timeout");
    };

    override void OnSuccess(string data, int dataSize) {
        if (dataSize > 0) {
            Print(data);
            dtacData.Invoke(data);
        }
    };
}