class ToxicConfig
{
	private ref array<ref ToxicAreaData> ToxicAreaDataArr;
	private ref array<string> ProtectableMaskList;

	void ToxicConfig()
	{
		ToxicAreaDataArr = new array<ref ToxicAreaData>();
		ProtectableMaskList = new array<string>();
	}

	void SetAreas(array<ref ToxicAreaData> arr)
	{
		ToxicAreaDataArr = arr;
	}

	void SetProtectableMaskList(array<string> list)
	{
		ProtectableMaskList = list;
	}


	array<string> GetMasks() { return ProtectableMaskList; }
	array<ref ToxicAreaData> GetZones() { return ToxicAreaDataArr; }
}