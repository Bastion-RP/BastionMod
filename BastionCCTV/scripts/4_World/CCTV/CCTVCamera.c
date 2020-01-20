class CCTVCamera {
    protected vector position;
    protected int yaw, pitch, roll;
    protected bool canRotate;

    void CCTVCamera( vector _position, int _startingAngle = 0, int _pitch = 0, int _roll = 0, bool _canRotate = true ) {
        position = _position;
        yaw = Math.NormalizeAngle( _startingAngle );
        pitch = Math.NormalizeAngle( _pitch );
        roll = Math.NormalizeAngle( _roll );
        canRotate = _canRotate;
    }

    vector GetPosition() { return position; }
    int GetStartingAngle() { return yaw; }
    int GetPitch() { return pitch; }
    int GetRoll() { return roll; }
    bool GetCanRotate() { return canRotate; }
    vector GetDirection() {
        vector dir = vector.Zero;
        dir[0] = yaw;
        dir[1] = pitch;
        dir[2] = roll;
        return dir;
    }
}