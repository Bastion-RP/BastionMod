class ConfigObject {
    vector position;
    vector direction;

    void ConfigObject( vector _position, vector _direction ) {
        position = _position;
        direction = _direction;
    }

    vector GetPosition() { return position; }
    vector GetDirection() { return direction; }
}