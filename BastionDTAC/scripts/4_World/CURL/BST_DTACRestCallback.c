class BST_DTACCivGeneralDataCallback : RestCallback {
    static ref ScriptInvoker _civGeneralDataInvoker = new ScriptInvoker();

    override void OnError(int errorCode) {
        _civGeneralDataInvoker.Invoke("");
    };

    override void OnTimeout() {
        _civGeneralDataInvoker.Invoke("");
    };

    override void OnSuccess(string data, int dataSize) {
        if (dataSize > 0) {
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
        _dtacCriminalRecordInvoker.Invoke(data);
    }
}