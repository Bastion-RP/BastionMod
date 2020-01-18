class CCTVCamera {
    protected vector position;
    protected int startingAngle;
    protected bool canRotate;

    void CCTVCamera(vector _position, int _startingAngle, bool _canRotate) {
        position = _position;
        startingAngle = Math.NormalizeAngle(_startingAngle);
        canRotate = _canRotate;
    }

    vector GetPosition() { return position; }
    int GetStartingAngle() { return startingAngle; }
    bool GetCanRotate() { return canRotate; }
}