class CCTVCamera {
    protected string name;
    protected vector position;
    protected float yaw, pitch, roll;
    protected bool canRotate;

    void CCTVCamera( string _name, vector _position, float _startingAngle = 0.0, float _pitch = 0.0, float _roll = 0.0, bool _canRotate = true ) {
        name = _name;
        position = _position;
        yaw = Math.NormalizeAngle( _startingAngle );
        pitch = Math.NormalizeAngle( _pitch );
        roll = Math.NormalizeAngle( _roll );
        canRotate = _canRotate;
    }

    string GetName() { return name; }
    vector GetPosition() { return position; }
    float GetStartingAngle() { return yaw; }
    float GetPitch() { return pitch; }
    float GetRoll() { return roll; }
    bool GetCanRotate() { return canRotate; }
    vector GetDirection() {
        vector dir = vector.Zero;
        dir[0] = yaw;
        dir[1] = pitch;
        dir[2] = roll;
        return dir;
    }
}