class MultiCharactersCharacterId {
    private string id, member_id, active, first_name, last_name, citizen_class, date_of_birth, sex, race;
    
    string GetCharacterId() {
        return id;
    }

    string GetMemberId() {
        return member_id;
    }

    string GetFirstName() {
        return first_name;
    }

    string GetLastName() {
        return last_name;
    }

    string GetCitizenClass() {
        return citizen_class;
    }

    string GetDOB() {
        return date_of_birth;
    }

    string GetSex() {
        return sex;
    }

    string GetRace() {
        return race;
    }

    bool IsActive() {
        if (active == "1") {
            return true;
        }
        return false;
    }

    void PrintData() {
        Print(MCConst.debugPrefix + "MultiCharactersCharacterId | id=" + id + " | member_id=" + member_id + " | active=" + active + " | first_name=" + first_name + " | last_name=" + last_name + " | citizen_class=" + citizen_class + " | date_of_birth=" + date_of_birth + " | sex=" + sex + " | race=" + race);
    }
}