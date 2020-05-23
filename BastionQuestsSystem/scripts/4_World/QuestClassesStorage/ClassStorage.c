class GeneralSettings
{
	int							NPCCount; // count of npc. The name of the NPC file should look like this npc+№;   Example: NPCCount: 3, Npc1.json, Npc2.json, Npc3.json 
}										  //																	   NPCCount: 5, Npc1.json, Npc2.json, Npc3.json, Npc4.json, Npc5.json

class NPC 
{
    string                      NPCType;	// classname npc object
    string                      NPCName;	// the name displayed in the dialogues
    ref array<string>           NPCClothing = new array<string>(); // clothing for a human's NPC
    vector                      NPCPos;		// position
    vector                      NPCOri;		// orientation
    int                         NPCUnicID;	// unic ID !must be greater than 0!
    ref array<ref QuestDialog>  Dialogues = new array<ref QuestDialog>(); 
    ref array <ref QueFinDiag>	QuestFinishDialogs = new array<ref QueFinDiag>();
}
class QuestDialog
{
    int                         ID;			// unique id relative to this NPC !must be greater than 0!
    string                      Message;	// text 
    ref array<ref Choice>       Choices = new array<ref Choice>();
}
class QueFinDiag
{
	int							ForQuest;	// questID
	int							MoveToDialog; // move to QuestDialog ID
	string                      ChoiceMsg;	// text
}
class Choice
{
    string                      ChoiceMsg;	// text
    int                         MoveToDialog;	//move to QuestDialog ID
    int                         ApplyQuest;		// questID accept the job
}
class Quest
{
    int                         QuestID;	// absolutely unique id relative to all other quests !must be greater than 0!
    string                      Type;		// type 'Delivery', 'FindAndDelivery'
	bool						Repeatable;	// can I take this quest again after a period of time
	int							Delay;		// in sec
	ref array<int>				Required = new array<int>();	// list of completed quests required to take this (contains QuestID)
	bool						CanDoneAnyway;	// ignore delay, repetable, required. This task can be passed without taking it if there are completed goals
    ref array<ref Shipment>     Shipments = new array<ref Shipment>();
    ref array<ref Reward>       Rewards = new array<ref Reward>();
}
class Shipment
{
    string                      Classname;
    int                         Count;		// If the item has a quantity, specify it in conventional units. For example for a water bottle specify 1000
	int							DistanceForSpawn;
	vector						PackagePos;	// need only for 'FindAndDelivery' type
	vector						PackageOri; // need only for 'FindAndDelivery' type
}
class Reward
{
    string                      Classname;
    int							Count; 		// If the item has a quantity, specify it in conventional units. For example for a water bottle specify 1000
}

//================================ need to store progress =====================================
class QuestManagerStg
{
	ref array<ref AppliedQuestStatus> QuestStatusArr = new array<ref AppliedQuestStatus>();
	ref array<int>				CompNonRepeatQuests = new array<int>();
	ref array<int>				CompRepeatQuests = new array<int>();
}

class AppliedQuestStatus
{
	int							QuestID;
	ref array<int>				SaveCountSpawnedItems = new array<int>();
	int							CompletedTasks;
}
//=============================================================================================