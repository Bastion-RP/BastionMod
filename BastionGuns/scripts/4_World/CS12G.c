enum JCSchottiAnimState
{
	DEFAULT 			= 0, 	//Animstates are only important for weapon that will stay open when empty - stuff like that
	OPENED				= 1, 	// Duh
	JAMMED				= 2,	// Typical pvp server owner: hOw tO dIsAbLe wEaPoN jAm
};
//States the weapon can have
enum JCSchottiStableStateID  
{
	UNKNOWN		=  0,
	Empty		=  1,
	Dry			=  2,
	Loaded		=  3,
	Jammed		=  4,
}

class JCSchottiEmpty extends WeaponStableState
{
	override void OnEntry (WeaponEventBase e) { wpnPrint("[wpnfsm] " + Object.GetDebugName(m_weapon) + " { Empty"); super.OnEntry(e); }
	override void OnExit (WeaponEventBase e) { super.OnExit(e); wpnPrint("[wpnfsm] " + Object.GetDebugName(m_weapon) + " } Empty"); }
	override int GetCurrentStateID () { return JCSchottiStableStateID.Empty; }
	override bool HasBullet () { return false; }
	override bool IsJammed () { return false; }
};
class JCSchottiDry extends WeaponStableState
{
	override void OnEntry (WeaponEventBase e) { wpnPrint("[wpnfsm] " + Object.GetDebugName(m_weapon) + " { Dry"); super.OnEntry(e); }
	override void OnExit (WeaponEventBase e) { super.OnExit(e); wpnPrint("[wpnfsm] " + Object.GetDebugName(m_weapon) + " } Dry"); }
	override int GetCurrentStateID () { return JCSchottiStableStateID.Dry; }
	override bool HasBullet () { return false; }
	override bool IsJammed () { return false; }
	override bool IsBoltOpen () { return true; }
};
class JCSchottiLoaded extends WeaponStableState
{
	override void OnEntry (WeaponEventBase e) { wpnPrint("[wpnfsm] " + Object.GetDebugName(m_weapon) + " { Loaded C"); super.OnEntry(e); }
	override void OnExit (WeaponEventBase e) { super.OnExit(e); wpnPrint("[wpnfsm] " + Object.GetDebugName(m_weapon) + " } Loaded C"); }
	override int GetCurrentStateID () { return JCSchottiStableStateID.Loaded; }
	override bool HasBullet () { return true; }
	override bool HasMagazine () { return false; }
	override bool IsJammed () { return false; }
};
class JCSchottiJammed extends WeaponStateJammed
{
	override void OnEntry (WeaponEventBase e) { wpnPrint("[wpnfsm] " + Object.GetDebugName(m_weapon) + " { Jammed"); super.OnEntry(e); }
	override void OnExit (WeaponEventBase e) { super.OnExit(e); wpnPrint("[wpnfsm] " + Object.GetDebugName(m_weapon) + " } Jammed"); }
	override int GetCurrentStateID () { return JCSchottiStableStateID.Jammed; }
	override bool HasBullet () { return true; }
	override bool IsJammed () { return true; }
	override bool IsBoltOpen () { return true; }
};

class AutoShotGunScript extends Rifle_Base
{
	ref WeaponStateBase Empty;			// you could also just use "E","D","L","J" - however i want to keep it simple and easily readable
	ref WeaponStateBase Dry;
	ref WeaponStateBase Loaded;
	ref WeaponStateBase Jammed;

	override void InitStateMachine ()
	{
		//Ability-chan NYAAAA
		m_abilities.Insert(new AbilityRecord(WeaponActions.MECHANISM, WeaponActionMechanismTypes.MECHANISM_CLOSED));  
		m_abilities.Insert(new AbilityRecord(WeaponActions.UNJAMMING, WeaponActionUnjammingTypes.UNJAMMING_START));
		m_abilities.Insert(new AbilityRecord(WeaponActions.UNJAMMING, WeaponActionUnjammingTypes.UNJAMMING_END));
		
		m_abilities.Insert(new AbilityRecord(WeaponActions.FIRE, WeaponActionFireTypes.FIRE_NORMAL));	//DUH - do i need to explain this ?
		m_abilities.Insert(new AbilityRecord(WeaponActions.FIRE, WeaponActionFireTypes.FIRE_DRY));
		m_abilities.Insert(new AbilityRecord(WeaponActions.FIRE, WeaponActionFireTypes.FIRE_LAST));		// this one is used for keeping the weapon open
		
		m_abilities.Insert(new AbilityRecord(WeaponActions.CHAMBERING, WeaponActionChamberingTypes.CHAMBERING_STARTLOOPABLE_SHOTGUN_COCKED));
		m_abilities.Insert(new AbilityRecord(WeaponActions.CHAMBERING, WeaponActionChamberingTypes.CHAMBERING_STARTLOOPABLE_SHOTGUN_UNCOCKED));
		m_abilities.Insert(new AbilityRecord(WeaponActions.CHAMBERING, WeaponActionChamberingTypes.CHAMBERING_ENDLOOPABLE));
		
		
		Empty = 	new JCSchottiEmpty(this, NULL, JCSchottiAnimState.DEFAULT);			
		Dry = 		new JCSchottiDry(this, NULL, JCSchottiAnimState.OPENED);
		Loaded = 	new JCSchottiLoaded(this, NULL, JCSchottiAnimState.DEFAULT);
		Jammed = 	new JCSchottiJammed(this, NULL, JCSchottiAnimState.JAMMED);
		// This should be the basic weapon states and stuff it should be able to do ... now comes the real fun OwO
		
		WeaponChargingInnerMag		Mech_Empty = 	new WeaponChargingInnerMag(this, NULL, WeaponActions.MECHANISM, WeaponActionMechanismTypes.MECHANISM_CLOSED);
		WeaponChargingInnerMag		Mech_Dry = 		new WeaponChargingInnerMag(this, NULL, WeaponActions.MECHANISM, WeaponActionMechanismTypes.MECHANISM_CLOSED);
		WeaponChargingInnerMag		Mech_Loaded = 	new WeaponChargingInnerMag(this, NULL, WeaponActions.MECHANISM, WeaponActionMechanismTypes.MECHANISM_CLOSED);
		
		
		LoopedChamberingEjectLast 	Chamber_Empty 		= new LoopedChamberingEjectLast(this, NULL, WeaponActions.CHAMBERING, WeaponActionChamberingTypes.CHAMBERING_STARTLOOPABLE_SHOTGUN_UNCOCKED, WeaponActionChamberingTypes.CHAMBERING_ENDLOOPABLE);
		LoopedChamberingEjectLast 	Chamber_Dry 		= new LoopedChamberingEjectLast(this, NULL, WeaponActions.CHAMBERING, WeaponActionChamberingTypes.CHAMBERING_STARTLOOPABLE_SHOTGUN_UNCOCKED, WeaponActionChamberingTypes.CHAMBERING_ENDLOOPABLE);
		LoopedChamberingEjectLast 	Chamber_Loaded 		= new LoopedChamberingEjectLast(this, NULL, WeaponActions.CHAMBERING, WeaponActionChamberingTypes.CHAMBERING_STARTLOOPABLE_SHOTGUN_COCKED, WeaponActionChamberingTypes.CHAMBERING_ENDLOOPABLE);
		// ^ still cant really get a hold of this ... im still a noob ;-;
		
		WeaponStateBase							Unjam_J = 				new WeaponUnjamming(this, NULL, WeaponActions.UNJAMMING, WeaponActionUnjammingTypes.UNJAMMING_START);
		WeaponStateBase							Trigger_Empty = 		new WeaponDryFire(this, NULL, WeaponActions.FIRE, WeaponActionFireTypes.FIRE_DRY); // What happens when you press fire on each state
		WeaponStateBase							Trigger_Dry = 			new WeaponDryFire(this, NULL, WeaponActions.FIRE, WeaponActionFireTypes.FIRE_DRY);
		WeaponStateBase 						Trigger_Last = 			new WeaponFireLast(this, NULL, WeaponActions.FIRE, WeaponActionFireTypes.FIRE_LAST);		//handles the last bullet fired so the bolt stays open
		WeaponFireAndChamberFromInnerMagazine 	Trigger_Loaded = 		new WeaponFireAndChamberFromInnerMagazine(this, NULL, WeaponActions.FIRE, GetWeaponSpecificCommand(WeaponActions.FIRE, WeaponActionFireTypes.FIRE_NORMAL) ); // This handles if the weapon needs to be reloaded after each shot with "r" of if it auto loads the next one
		WeaponStateBase							Trigger_Jammed = 		new WeaponDryFire(this, NULL, WeaponActions.FIRE, WeaponActionFireTypes.FIRE_DRY);
		WeaponStateBase							Trigger_LoadedJammed = 	new WeaponFire(this, NULL, WeaponActions.FIRE, WeaponActionFireTypes.FIRE_JAM);  // this one is important
		WeaponStateBase 						Unjam_Weapon = 			new WeaponUnjamming(this, NULL, WeaponActions.UNJAMMING, GetWeaponSpecificCommand(WeaponActions.UNJAMMING, WeaponActionUnjammingTypes.UNJAMMING_START));
		
		// This is where it gets complicated ... however you can actually put in anything you like in there
		// for example: WeaponEventBase _dick_ = new WeaponEventHumanCommandActionFinished;
		// would still work ... lol - its just really something for you to save time when writing this ...
		// wich i effectively eliminated UwU
		WeaponEventBase _finished_ 		= new WeaponEventHumanCommandActionFinished;
		WeaponEventBase __conload_ 		= new WeaponEventContinuousLoadBulletStart;
		WeaponEventBase __L1B__ 		= new WeaponEventLoad1Bullet;
		WeaponEventBase __Trig__ 		= new WeaponEventTrigger;
		WeaponEventBase __TrigJam_ 		= new WeaponEventTriggerToJam;
		WeaponEventBase __Unjam__ 		= new WeaponEventUnjam;
		WeaponEventBase	__Mechanism__ 	= new WeaponEventMechanism;
		WeaponEventBase _abort_ 		= new WeaponEventHumanCommandActionAborted;
		WeaponEventBase _reloadaction_ 	= new WeaponEventReloadTimeout;
		WeaponEventBase _dry_ 			= new WeaponEventDryFireTimeout;
		
		m_fsm = new WeaponFSM(); //setting up a new FSM ?
		
		/////////////////////////////////////////////
		/// Lets start with the loading mechanism ///
		/////////////////////////////////////////////
		m_fsm.AddTransition(new WeaponTransition( Empty,				__L1B__,  		Chamber_Empty)); 	// Its basicly a transition what happens when you chamber
		m_fsm.AddTransition(new WeaponTransition( Chamber_Empty,		_finished_,  	Loaded));			// an empty weapon
		m_fsm.AddTransition(new WeaponTransition( Chamber_Empty,		_abort_,  		Empty, NULL, new WeaponGuardChamberEmpty(this)));
		m_fsm.AddTransition(new WeaponTransition( Chamber_Empty,		_abort_,		Loaded));	
		
		m_fsm.AddTransition(new WeaponTransition( Loaded,				__L1B__,  		Chamber_Loaded, NULL, new GuardNot(new WeaponGuardInnerMagazineFull(this))));
		m_fsm.AddTransition(new WeaponTransition( Chamber_Loaded,		_finished_,  	Loaded));
		m_fsm.AddTransition(new WeaponTransition( Chamber_Loaded,		_abort_,  		Loaded));
		
		m_fsm.AddTransition(new WeaponTransition( Dry,					__L1B__,  		Chamber_Dry, NULL, new GuardNot(new WeaponGuardInnerMagazineFull(this))));
		m_fsm.AddTransition(new WeaponTransition( Chamber_Dry,			_finished_,  	Loaded));
		m_fsm.AddTransition(new WeaponTransition( Chamber_Dry,			_abort_,  		Dry, NULL, new WeaponGuardChamberFiredOut(this)));
		m_fsm.AddTransition(new WeaponTransition( Chamber_Dry,			_abort_,  		Loaded));
		
		///////////////////////////////////////////
		/// Lets continue with the basic firing ///
		///////////////////////////////////////////
		m_fsm.AddTransition(new WeaponTransition( Loaded,				__Mechanism__,	Mech_Loaded));
		m_fsm.AddTransition(new WeaponTransition( Mech_Loaded,			_finished_,		Empty, NULL, new WeaponGuardChamberEmpty(this) )); //this is basicly a condition ... so when you fire the last bullet in the chamber it goes to empty C:
		m_fsm.AddTransition(new WeaponTransition( Mech_Loaded,			_finished_,		Loaded));
		m_fsm.AddTransition(new WeaponTransition( Mech_Loaded,			_abort_,		Empty, NULL, new WeaponGuardChamberEmpty(this) ));
		m_fsm.AddTransition(new WeaponTransition( Mech_Loaded,			_abort_,		Loaded));
		// ^ Mechanism for firing when loaded
		m_fsm.AddTransition(new WeaponTransition( Loaded,				__Trig__,		Trigger_Loaded, NULL, new WeaponGuardHasAmmoInnerMagazine(this)));
		m_fsm.AddTransition(new WeaponTransition( Trigger_Loaded,		_finished_,		Loaded));
		m_fsm.AddTransition(new WeaponTransition( Trigger_Loaded,		_reloadaction_,	Loaded));
		m_fsm.AddTransition(new WeaponTransition( Trigger_Loaded,		_abort_,		Loaded));
		// ^ trigger and reload action
		
		m_fsm.AddTransition(new WeaponTransition( Loaded,				__Trig__,		Trigger_Last));
		m_fsm.AddTransition(new WeaponTransition( Trigger_Last,			_finished_,		Dry));
		m_fsm.AddTransition(new WeaponTransition( Trigger_Last,			_reloadaction_,	Dry));
		m_fsm.AddTransition(new WeaponTransition( Trigger_Last,			_abort_,		Dry));
		// ^ trigger for the last bullet
		
		
		
		
		
		///////////////////////////////////////////
		/// Lets continue with the dry firing ///
		///////////////////////////////////////////
		m_fsm.AddTransition(new WeaponTransition( Dry, 					__Mechanism__,	Mech_Dry)); // charge from dischg nobullet nomag
		m_fsm.AddTransition(new WeaponTransition( Mech_Dry,				_finished_,		Empty));
			Mech_Dry.AddTransition(new WeaponTransition( Mech_Dry.m_start,	_abort_,	Empty));		// this code is important for the switch of the Dry state .. but dont ask me how it works
			Mech_Dry.AddTransition(new WeaponTransition( Mech_Dry.m_onCK,	_abort_,	Empty));
		
		// ^ Mechanism for firing when dry
		m_fsm.AddTransition(new WeaponTransition( Dry,					__Trig__, 		Trigger_Dry));
		m_fsm.AddTransition(new WeaponTransition( Trigger_Dry,			_finished_, 	Empty));
		m_fsm.AddTransition(new WeaponTransition( Trigger_Dry,			_abort_, 		Empty));
		m_fsm.AddTransition(new WeaponTransition( Trigger_Dry,			_reloadaction_, Empty));
		// ^ Trigger for firing dry
		
		///////////////////////////////////////////
		/// Lets continue with the empty firing ///
		///////////////////////////////////////////
		m_fsm.AddTransition(new WeaponTransition( Empty,				__Mechanism__,	Mech_Empty));
		m_fsm.AddTransition(new WeaponTransition( Mech_Empty,			_finished_, 	Empty));
		m_fsm.AddTransition(new WeaponTransition( Mech_Empty,			_abort_, 		Empty));
		m_fsm.AddTransition(new WeaponTransition( Trigger_Empty,		_reloadaction_,	Empty));
		
		m_fsm.AddTransition(new WeaponTransition( Empty,				__Trig__, 		Trigger_Empty));
		m_fsm.AddTransition(new WeaponTransition( Trigger_Empty,		_finished_, 	Empty));
		m_fsm.AddTransition(new WeaponTransition( Trigger_Empty,		_dry_,		 	Empty));
		m_fsm.AddTransition(new WeaponTransition( Trigger_Empty,		_abort_, 		Empty));
		m_fsm.AddTransition(new WeaponTransition( Trigger_Empty,		_reloadaction_, Empty));
		
		///////////////////////////////////////////
		/// Lets continue with the jamming      ///
		///////////////////////////////////////////
		m_fsm.AddTransition(new WeaponTransition(Loaded,				__TrigJam_, 	Trigger_LoadedJammed)); // remember to use the "Trigger Jam mechanism" here
		m_fsm.AddTransition(new WeaponTransition(Trigger_LoadedJammed,	_finished_, 	Jammed ));
		m_fsm.AddTransition(new WeaponTransition(Trigger_LoadedJammed,	_reloadaction_, Jammed ));
		m_fsm.AddTransition(new WeaponTransition(Trigger_LoadedJammed,	_abort_, 		Jammed ));
		
		m_fsm.AddTransition(new WeaponTransition(Jammed,				__Trig__, 		Trigger_Jammed)); //jamming thingy
		m_fsm.AddTransition(new WeaponTransition(Trigger_Jammed,		_finished_, 	Jammed));
		m_fsm.AddTransition(new WeaponTransition(Trigger_Jammed,		_dry_, 			Jammed));
		m_fsm.AddTransition(new WeaponTransition(Trigger_Jammed,		_reloadaction_, Jammed));
		m_fsm.AddTransition(new WeaponTransition(Trigger_Jammed,		_abort_, 		Jammed));
		
		
		///////////////////////////////////////////
		/// Lets continue with the unjamming    ///
		///////////////////////////////////////////
		m_fsm.AddTransition(new WeaponTransition(Jammed, 				__Unjam__, 		Unjam_Weapon));
		m_fsm.AddTransition(new WeaponTransition(Unjam_Weapon,			_finished_, 	Jammed, NULL, new WeaponGuardJammed(this)));
		m_fsm.AddTransition(new WeaponTransition(Unjam_Weapon,			_finished_, 	Loaded, NULL, new WeaponGuardChamberEmpty(this)));
		m_fsm.AddTransition(new WeaponTransition(Unjam_Weapon,			_finished_, 	Loaded));
		m_fsm.AddTransition(new WeaponTransition(Unjam_Weapon,			_abort_, 		Jammed, NULL, new WeaponGuardJammed(this)));
		m_fsm.AddTransition(new WeaponTransition(Unjam_Weapon,			_abort_, 		Loaded, NULL, new WeaponGuardChamberEmpty(this)));
		m_fsm.AddTransition(new WeaponTransition(Unjam_Weapon,			_abort_, 		Loaded));
		
		
		/*
		m_fsm.AddTransition(new WeaponTransition(Jammed, 				__Unjam__, 		Unjam_Weapon));
		m_fsm.AddTransition(new WeaponTransition(Unjam_Weapon,			_finished_, 	Jammed, NULL, new WeaponGuardJammed(this)));
		m_fsm.AddTransition(new WeaponTransition(Unjam_Weapon,			_finished_, 	Empty, NULL, new WeaponGuardChamberEmpty(this)));
		m_fsm.AddTransition(new WeaponTransition(Unjam_Weapon,			_finished_, 	Loaded));
		m_fsm.AddTransition(new WeaponTransition(Unjam_Weapon,			_abort_, 		Jammed, NULL, new WeaponGuardJammed(this)));
		m_fsm.AddTransition(new WeaponTransition(Unjam_Weapon,			_abort_, 		Empty, NULL, new WeaponGuardChamberEmpty(this)));
		m_fsm.AddTransition(new WeaponTransition(Unjam_Weapon,			_abort_, 		Loaded));*/
		
		
		
		
		m_fsm.SetInitialState(Empty);  //when the weapon spawns .. wich state it should be in

		SelectionBulletHide(); //uhm ...
		HideMagazine(); // help ....

		m_fsm.Start();
	}
	/// the part below this actually lets us chamber more than 1 round at the time c:
	override bool CanChamberBullet (int muzzleIndex, Magazine mag)
	{
		return CanChamberFromMag(muzzleIndex, mag) && !IsInternalMagazineFull(muzzleIndex) );
	}
	
	override void SetActions()
	{
		super.SetActions();
		AddAction(FirearmActionLoadMultiBullet);

		RemoveAction(FirearmActionLoadBulletQuick); // Easy reload
		AddAction(FirearmActionLoadMultiBulletQuick); // Easy reload

		
	}
};

class BRP_CS12G : AutoShotGunScript
{	
	override RecoilBase SpawnRecoilObject()
	{
		return new Mp133Recoil(this);
	}
	
	override float GetChanceToJam()
	{
		float chanceToJam = super.GetChanceToJam();
			chanceToJam = chanceToJam + ((0 - chanceToJam) * 0);
		
		return chanceToJam;
	}
};
		