class CharacterData
{
    protected string id;
    protected string member_id;
    protected string first_name;
    protected string last_name;
    protected string citizen_class;
    protected string date_of_birth;
    protected string sex;
    protected string race;

    void CharacterData(
      string _id,
      string _member_id,
      string _first_name,
      string _last_name,
      string _citizen_class,
      string _date_of_birth,
      string _sex,
      string _race )
    {
      id = _id;
      member_id = _member_id;
      first_name = _first_name;
      last_name = _last_name;
      citizen_class = _citizen_class;
      date_of_birth = _date_of_birth;
      sex = _sex;
      race = _race;
    }

    string GetId() { return id; }
    string GetMemberId() { return member_id; }
    string GetFirstName() { return first_name; }
    string GetLastName() { return last_name; }
    string GetCitizenClass() { return citizen_class; }
    string GetDOB() { return date_of_birth; }
    string GetSex() { return sex; }
    string GetRace() { return race; }
}