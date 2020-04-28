class CCTVMonitor {
    protected vector position;
    protected float yaw, pitch, roll;

    void CCTVMonitor( vector _position, float _startingAngle = 0.0, float _pitch = 0.0, float _roll = 0.0 ) {
        position = _position;
        yaw = Math.NormalizeAngle( _startingAngle );
        pitch = Math.NormalizeAngle( _pitch );
        roll = Math.NormalizeAngle( _roll );
    }

    vector GetPosition() { return position; }
    vector GetDirection() {
        vector dir = vector.Zero;
        dir[0] = yaw;
        dir[1] = pitch;
        dir[2] = roll;
        return dir;
    }
}