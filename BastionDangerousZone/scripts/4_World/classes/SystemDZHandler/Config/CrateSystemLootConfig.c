class DZLootConfig
{
	string LootName;
	float  ProbToSpawn;
	ref array<ref DZAttachmentConfig> AttachmentsToLoot;
	//AttachmentsToItem = NULL;


	void DZLootConfig(string lootname, float probtospawn)
	{
		LootName = lootname;
		ProbToSpawn = probtospawn;
		AttachmentsToLoot = new ref array< ref DZAttachmentConfig>;
	}

	void AddAttachmentsToItem(string name, float prob)
	{
		AttachmentsToLoot.Insert(new ref DZAttachmentConfig(name,prob));
	}
}

class DZAttachmentConfig
{
	string AttachName;
	float  ProbAttachToSpawn;

	void  DZAttachmentConfig(string attachname, float probattachtospawn)
	{
		AttachName = attachname;
		ProbAttachToSpawn = probattachtospawn;
	}
}

class DZListLootConfig{
	string Name;
	ref array<ref DZLootConfig> Loots;

	void DZListLootConfig(string name)
	{
		Loots= new ref array<ref DZLootConfig>;
		Name=name;
	}

	void AddLootConfig(string lootname, float probtospawn)
	{
		Loots.Insert(new ref DZLootConfig(lootname,probtospawn));
	}
}
