class RaceCollection{
    ref array<ref Race> races;
    ref array<string> playerIdent;

    void RaceCollection() {
        races = new array<ref Race>;
        playerIdent = new array<string>;
    }
	
	void AddRace(PlayerIdentity player, Race race) {
		int index = playerIdent.Find(player.GetId());
		
		if (!races.IsValidIndex(index)) {
			races.Insert(race);
			playerIdent.Insert(player.GetId());
		} else {
			races.Set(index, race);
			playerIdent.Set(index, player.GetId());
		}
	}
	
	Race FindRace(PlayerIdentity player) {
		int index = playerIdent.Find(player.GetId());

		if (!races.IsValidIndex(index)) {
		    return null;
		}
		
		return races.Get(index);
	}
	
	void RemoveRace(PlayerIdentity player) {
		int index = playerIdent.Find(player.GetId());
		
		if (!races.IsValidIndex(index)) {
			playerIdent.Remove(index);
			races.Remove(index);
		}
	}
};