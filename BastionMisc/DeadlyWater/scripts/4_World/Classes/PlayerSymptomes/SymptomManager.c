
enum BRP_SymptomIDs : SymptomIDs 
{
    BRP_SYMPTOM_DEAD_BY_WATER,
};



modded class SymptomManager 
{

	override void Init() 
	{
        super.Init();
		RegisterSymptom(new DeadByWater);
    };


};
