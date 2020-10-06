modded class GameConstants
{
    //0.5; // 50%
    const int 	STAMINA_DRAIN_STANDING_SPRINT_PER_SEC = 4 * 0.5; //in units (how much sprint depletes stamina)
	const int 	STAMINA_DRAIN_CROUCHED_SPRINT_PER_SEC = 1; //in units (how much sprint in crouch depletes stamina)
	const int 	STAMINA_DRAIN_PRONE_SPRINT_PER_SEC = 3 * 0.5; //in units (how much sprint in prone depletes stamina)
	const int	STAMINA_DRAIN_SWIM_FAST_PER_SEC = 5 * 0.5; //in units (how much fast swimming depletes stamina)
	const int	STAMINA_DRAIN_LADDER_FAST_PER_SEC = 8 * 0.5; //in units (how much fast ladder climb depletes stamina)
	
	const float	STAMINA_DRAIN_HOLD_BREATH_START = 0.2 * 0.5; //in units (how much holding breath depletes stamina at the start)
	const float	STAMINA_DRAIN_HOLD_BREATH_END = 1.0 * 0.5; //in units (how much holding breath depletes stamina at the end)
	const float	STAMINA_DRAIN_JUMP = 25 * 0.5;		// in units (how much jumping depletes stamina)
	const float	STAMINA_DRAIN_VAULT = 20 * 0.5;		// in units (how much jumping depletes stamina)
	const float	STAMINA_DRAIN_CLIMB = 42 * 0.5;		// in units (how much jumping depletes stamina)
	const float	STAMINA_DRAIN_MELEE_LIGHT = 5 * 0.5; //in units (how much light melee punch depletes stamina)
	const float	STAMINA_DRAIN_MELEE_HEAVY = 25 * 0.5; //in units (how much heavy melee punch depletes stamina)
	const float	STAMINA_DRAIN_MELEE_EVADE = 8 * 0.5; // in units (how much evade depletes stamina)
	
	const float STAMINA_DRAIN_HOLD_BREATH_DURATION = 5.0 * 0.5; //in seconds, time it takes to increase stamina drain from STAMINA_DRAIN_HOLD_BREATH_START to STAMINA_DRAIN_HOLD_BREATH_END
	const float	STAMINA_DRAIN_HOLD_BREATH_EXPONENT = 4.0 * 0.5; //holding breath exponent
	
	const float STAMINA_KG_TO_STAMINAPERCENT_PENALTY = 1.75; //in units (by how many  units is max stamina bar reduced for each 1 kg of load weight)
	const float STAMINA_MIN_CAP = 5; //in units (overload won't reduce max stamina bar under this value)
	const float STAMINA_HOLD_BREATH_THRESHOLD_ACTIVATE = 10; // in units
	const float STAMINA_HOLD_BREATH_THRESHOLD_DRAIN = 0; // in units
	const float STAMINA_JUMP_THRESHOLD = 25 * 0.5; // in units
	const float STAMINA_VAULT_THRESHOLD = 20 * 0.5; // in units
	const float STAMINA_CLIMB_THRESHOLD = 42 * 0.5; // in units
	
	const int 	STAMINA_GAIN_JOG_PER_SEC = 1; //default 2 //in units (how much of stamina units is gained while jogging)
	const int 	STAMINA_GAIN_WALK_PER_SEC = 2; //default 4 //in units (how much of stamina units is gained while walking)
	const int 	STAMINA_GAIN_IDLE_PER_SEC = 3; //default 5 //in units (how much of stamina units is gained while iddling)
	const int	STAMINA_GAIN_SWIM_PER_SEC = 1; //default 1 //in units (how much of stamina units is gained while slowly swim)
	const int	STAMINA_GAIN_LADDER_PER_SEC = 1;  //default 1 //in units (how much of stamina units is gained while slowly swim)
	const float STAMINA_GAIN_BONUS_CAP = 1.5;  //default 3.0 //in units (tells how much extra units can be added at best to stamina regain)
	
	const float STAMINA_MELEE_HEAVY_THRESHOLD = 25 * 0.5; // in units (how many units we need to make a heavy hit in melee)
	const float STAMINA_MELEE_EVADE_THRESHOLD = 8 * 0.5; // in units
}