class DTACPlayerData {
    protected vector position;
    protected string name, id;
    protected float health, blood, water, food;

    void SetName(string name) {
        this.name = name;
    }

    void SetId(string id) {
        this.id = id;
    }

    void SetPosition(vector position) {
        this.position = position;
    }

    void SetHealth(float health) {
        this.health = health;
    }

    void SetBlood(float blood) {
        this.blood = blood;
    }

    void SetWater(float water) {
        this.water = water;
    }

    void SetFood(float food) {
        this.food = food;
    }

    string GetName() { return name; }
    string GetId() { return id; }
    vector GetPosition() { return position; }
    float GetHealth() { return health; }
    float GetBlood() { return blood; }
    float GetWater() { return water; }
    float GetFood() { return food; }
}