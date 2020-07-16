class LockDoorConfig
{
	static const float MAX_DST_BETWEEN_PLAYER_AND_DOOR = 2;


	private int	AutoCloseDoorTime;
	private ref array<ref LockDoorStorage> AllDoorsData;

	void LockDoorConfig()
	{
		AutoCloseDoorTime 	= -1;
		AllDoorsData 	= new array<ref LockDoorStorage>();
	}

	void Validate()
	{
		if (AllDoorsData.Count() == 0)
		{
			AllDoorsData.Insert(new LockDoorStorage( "Some door", "0 0 0", false, {"Pliers"}, {-272, -273}, {-1, -2} ));
		}
	}

	int GetAutoCloseDoorTime()
	{
		return AutoCloseDoorTime;
	}

	ref array<ref LockDoorStorage> GetAllDoorsData()
	{
		return AllDoorsData;
	}

	float GetMaxDst()
	{
		return MAX_DST_BETWEEN_PLAYER_AND_DOOR;
	}
	
}

class LockDoorStorage
{
	private string 				Description;
	private vector 				Pos;
	private bool				NeedKey;
	private ref array<string> 	AllowKeys;
	private ref array<int>		BastionIdsArr;
	private ref array<int>		BastionClassesArr;



	void LockDoorStorage(string desc, vector pos, bool needkey, ref array<string> allowkeys, ref array<int> bstIds, ref array<int> bstClasses)
	{
		Description			= desc;
		Pos					= pos;
		NeedKey				= needkey;
		AllowKeys			= allowkeys;
		BastionIdsArr		= bstIds;
		BastionClassesArr	= bstClasses;
	}

	vector 				GetPos() 			{ return Pos; }
	bool				GetNeedKey()		{ return NeedKey; }
	ref array<string>	GetAllowKeys()		{ return AllowKeys; }
	ref array<int>		GetBstIds()			{ return BastionIdsArr; }
	ref array<int>		GetBastionClasses()	{ return BastionClassesArr; }
}