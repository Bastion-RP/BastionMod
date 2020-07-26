class DZCrateLocation
{
		string DZContainer;
		int DZMaxLoot;
    string Name;
    vector POS, ORI;

    void DZCrateLocation(int dzmaxloot,string container,string name, vector pos, vector ori)
	{
				DZMaxLoot = dzmaxloot;
				DZContainer = container;
        Name = name;
        POS = pos;
        ORI = ori;
    }
}

class DZ_CSArea
{
	string DZName;
	int DZNbCrate;
	string DZCreature;
	int DZNbCreature;
	ref array<ref DZCrateLocation>CrateLocation;


	void DZ_CSArea(string name, int nbcrate, string creature, int nbcreature)
	{
		DZName=name;
		DZNbCrate=nbcrate;
		DZCreature=creature;
		DZNbCreature=nbcreature;

		CrateLocation = new ref array<ref DZCrateLocation>;
	}

	void AddCratePosition(int dzmaxloot,string container,string name, vector pos, vector ori)
	{
		CrateLocation.Insert(new ref DZCrateLocation(dzmaxloot,container,name,pos,ori));
	}
}
