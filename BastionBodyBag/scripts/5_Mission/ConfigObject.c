class ConfigObject {
    string type;
    vector position;
    vector direction;

    void ConfigObject( string _type, vector _position, vector _direction ) {
        type = _type;
        position = _position;
        direction = _direction;
    }

    string GetType() { return type; }
    vector GetPosition() { return position; }
    vector GetDirection() { return direction; }
}