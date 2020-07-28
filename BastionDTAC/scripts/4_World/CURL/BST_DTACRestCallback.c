class BST_DTACCivGeneralDataCallback : RestCallback {
    static ref ScriptInvoker _civGeneralDataInvoker = new ScriptInvoker();

    override void OnError(int errorCode) {
        Print("[DTAC DEBUG] BST_DTACCivGeneralDataCallback | OnError | Error!!!");
        _civGeneralDataInvoker.Invoke("");
    };

    override void OnTimeout() {
        Print("[DTAC DEBUG] BST_DTACCivGeneralDataCallback | OnTimeout | Timeout!!!");
        _civGeneralDataInvoker.Invoke("");
    };

    override void OnSuccess(string data, int dataSize) {
        Print("[DTAC DEBUG] BST_DTACCivGeneralDataCallback | OnSuccess | Success!!!");
        if (dataSize > 0) {
            Print("[DTAC DEBUG] BST_DTACCivGeneralDataCallback | OnSuccess | Passed size check!!!");
            _civGeneralDataInvoker.Invoke(data);
        }
    };
}

class BST_DTACGeneralRecordCallback : RestCallback {
    static ref ScriptInvoker _dtacGeneralRecordInvoker = new ScriptInvoker();

    override void OnError(int errorCode) {
        _dtacGeneralRecordInvoker.Invoke("");
    }

    override void OnTimeout() {
        _dtacGeneralRecordInvoker.Invoke("");
    }
    
    override void OnSuccess(string data , int dataSize) {
        Print("[DEBUG] BST_DTACGeneralRecordCallback | OnSuccess | DTAC File created!!! file=" + data);
        _dtacGeneralRecordInvoker.Invoke(data);
    }
}

class BST_DTACCriminalRecordCallBack : RestCallback {
    static ref ScriptInvoker _dtacCriminalRecordInvoker = new ScriptInvoker();
    
    override void OnError(int errorCode) {
        _dtacCriminalRecordInvoker.Invoke("");
    }

    override void OnTimeout() {
        _dtacCriminalRecordInvoker.Invoke("");
    }

    override void OnSuccess(string data , int dataSize) {
        Print("[DEBUG] BST_DTACCriminalRecordCallBack | OnSuccess | DTAC File created!!! file=" + data);
        _dtacCriminalRecordInvoker.Invoke(data);
    }
}