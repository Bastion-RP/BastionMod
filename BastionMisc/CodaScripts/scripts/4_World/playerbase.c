//Shock Injector functionality and Restraint Logout fixes

modded class PlayerBase extends ManBase
{
	//---Changeable---
	private bool useVin							= true; //Enabe Vin Effects
	private bool useInjured						= true; //Enable Injured effect
	private bool DebugOn 						= true; // Enable Print statments for client/server into script logs
	private float m_TargetTime 					= 30; // Time in seconds till player falls Uncon
	
	//---Do Not Change---
	private ref Timer m_ShockTimerBase;			//Timer used by both server and client (With diffrent Tick rates)
	private ShockInjectionStage m_currentStage 	= ShockInjectionStage.NotActive; //Injured stages
	private float m_maxPlayerShock 				= 100; //Max player shock, recaluclated in Init
	
	//Timer tick rates
	private const float m_tickRateC 			= 0.1; //Tick rate of Client Timer
	private const float m_tickRateS 			= 1; //TickRate of Server Timer
	
	//Main toggles
	bool m_ShockTickActive 						= false; // Master toggle, if injection effects are active - Synced	
	bool m_ShockActive 							= false; // If Shock is being applied to the player - Synced
	
	//Vin Settings
	float m_MaxVin								 = 1.5; //Max Vignette value 0-2
	float m_Vin 								 = 0; //Current Vin Value
	float m_VinRate 							 = 0; //Rate Vin increases per tick"
	float m_VinStart							 = 0; //Value the vin will start from
	
	//Injured Settings
	float m_MaxInjured 							 = 0.8; //Max injured value 0-1
	float m_InjuredVal 							 = 0; //Current Injured value
	float m_InjuredRate 						 = 0; //current Injured rate
	float m_InjuredStart						 = 0; //Value the injured state starts at
	
	//Item Init
    override void Init()
    {
		//Hold the item like a real person
        DayzPlayerItemBehaviorCfg toolsOneHanded = new DayzPlayerItemBehaviorCfg;
        toolsOneHanded.SetToolsOneHanded();
     	GetDayZPlayerType().AddItemInHandsProfileIK("ShockInjector", "dz/anims/workspaces/player/player_main/props/player_main_1h_morphine.asi", toolsOneHanded, "dz/anims/anm/player/ik/gear/morphine.anm");
		
		//Net Sync for the client
		RegisterNetSyncVariableBool("m_ShockTickActive");
		RegisterNetSyncVariableInt("m_currentStage");
		
		super.Init();
    }
	
	/*override void CommandHandler(float pDt, int pCurrentCommandID, bool pCurrentCommandFinished)	
	{
		super.CommandHandler(pDt,pCurrentCommandID,pCurrentCommandFinished);
		Print("REEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE");
	}*/
	
	//If another player uses an injection the target player will get an RPC to start its client function
	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender,rpc_type,ctx);
		
		if(GetGame().IsClient())
		{
			switch(rpc_type)
			{
			case Shock_RPC.M_InjectStartClient:
				log("OnRPC - Starting Client injection for " + this + " player");
				StartShockInjectionClient();
			break;
			}	
		}
	}
	
	//Stop the player Regen Shock if we're shocking them
	override void ShockRefill(float pDt)
	{
		if(m_ShockActive)
		{
			//log("ShockRefill - Shock Disabled");
			return;
		} 
		
		super.ShockRefill(pDt);
	}
	
	override void OnUnconsciousStart()
	{
		super.OnUnconsciousStart();
		
		if(GetGame().IsServer())
		{
			log("UnconServer::");
			m_currentStage = ShockInjectionStage.Unconscious;
			SetSynchDirty();
		}
	}
	
	void StartShockInjectionClient()
	{
		log("StartShockInjectionClient::");
		
		if(IsAlive())
		{
			m_ShockTimerBase = new Timer( CALL_CATEGORY_GAMEPLAY );
			m_ShockTimerBase.Run(m_tickRateC,this,"ShockTickClient",null,true);
			
			if(useInjured)
			{
				m_InjuredStart = m_InjuryHandler.GetInjuryAnimValue();
				m_InjuredVal = m_InjuredStart;
			}
			
		}
		else
		{
			log("StartShockInjectionClient:: Player is dead, aborting client timer start");
		}
	}
	
	void StartShockInjectionServer()
	{
		log("StartShockInjectionServer::");
		
		if(IsAlive())
		{
			//Calculate max shock, get the max value of shock minus the knockout threshold (25 shock default)
			m_maxPlayerShock = GetMaxHealth("","Shock") - PlayerConstants.UNCONSCIOUS_THRESHOLD;
			m_currentStage = ShockInjectionStage.ApplyingShock;
			
			//Start our base timer (will run the duration of the injection)
			m_ShockTimerBase = new Timer( CALL_CATEGORY_GAMEPLAY );
			m_ShockTimerBase.Run(m_tickRateS,this,"ShockTickServer",null,true);
			m_ShockTickActive = true;
			
			
			if(useInjured)
			{
				m_InjuredStart = m_InjuryHandler.GetInjuryAnimValue();
				m_InjuredVal = m_InjuredStart;
			}
			
			SetSynchDirty();
		}
		else
		{
			log("StartShockInjectionServer:: Player is dead, aborting server timer start");
		}

	}
	
	void StopShockInjectionClient()
	{
		if(useVin)
		{
			m_Vin = 0;
			log("StopShockClient:: Vin End " + m_Vin);
			PPEffects.SetUnconsciousnessVignette(0);
		}
		
		if(useInjured)
		{
			m_InjuredVal = m_InjuredStart;
			log("StopShockClient:: Injured End " + m_InjuredVal);
			
			HumanCommandAdditives HCA = GetCommandModifier_Additives();
		
			if( HCA != null)
			{
				HCA.SetInjured( m_InjuredVal , false );
			}
			else
			{
				log("HandleInjured:: " + this + " has null HCA");
			}
		}

		
		if(m_ShockTimerBase !=null)
		{
			m_ShockTimerBase.Stop();
		}
		
		log("StopShockInjectionClient::");
	}
	
	void StopShockInjectionServer()
	{
		m_currentStage = ShockInjectionStage.NotActive;
		
		m_ShockActive = false;
		m_ShockTickActive = false;
		
		if(useInjured)
		{
			m_InjuredVal = m_InjuredStart;
			
			HumanCommandAdditives HCA = GetCommandModifier_Additives();
		
			if( HCA != null)
			{
				HCA.SetInjured( m_InjuredVal , false );
			}
			else
			{
				log("HandleInjured:: " + this + " has null HCA");
			}
		}

		
		if(m_ShockTimerBase != null)
		{
			m_ShockTimerBase.Stop();
		}
		
		log("StopShockInjectionServer::");
		
		SetSynchDirty();
	}
	
	
	//Ticks 0.1 per second on the client
	void ShockTickClient()
	{
		log("ShockTickClient:: Tick, stage " + m_currentStage);

		
		if(!IsAlive())
		{
			log("ShockTickClient:: Player is dead, aborting tick");
			StopShockInjectionClient();
		}
		
		if(m_currentStage == ShockInjectionStage.ApplyingShock)
		{
			if(useVin)
			{
				HandleVinEffect();
			}
			
			if(useInjured)
			{
				HandleInjured(m_tickRateC);
			}
		}
		else if(m_currentStage == ShockInjectionStage.Unconscious || m_currentStage == ShockInjectionStage.Awake)
		{
			log("ShockTickClient:: Stopping ShockTickClient");
			StopShockInjectionClient();
		}
	}
	
	//Ticks 1 per second on the server
	void ShockTickServer()
	{		
		log("ShockTickServer:: Tick, stage " + m_currentStage + " for " + this);
		
		if(IsAlive())
		{
			float PShock = GetHealth( "GlobalHealth", "Shock" );
			
			switch(m_currentStage)
			{
			case ShockInjectionStage.ApplyingShock: 
				ApplyingShock(PShock);
			break;
			case ShockInjectionStage.Unconscious: 
				ApplyingUncon(PShock);
			break;
			case ShockInjectionStage.Awake: 
				ApplyingAwake(PShock);
			break;
			}
		}
		else
		{
			log("ShockTickServer:: Player is dead stopping server for "  + this);
			StopShockInjectionServer();
		}
		
		//Resync with the client every second/timer tick
		SetSynchDirty();
	}
	
	
	void ApplyingShock(float PShock)
	{
		
		log("ShockTickBase:: Applying Shock");
	
		if(PShock > 0)
		{
			float ShockDamage = GetInjectionShockDamage(m_tickRateS);		
			log("ApplyingShock:: " + ShockDamage + " shock to " + this + " with " + PShock +" current shock");	
			GiveShock(-ShockDamage);
			m_ShockActive = true;
			
			if(useInjured)
			HandleInjured(m_tickRateS);	
		}
		else
		{
			m_currentStage = ShockInjectionStage.Unconscious; //Shocking complete, next tick move to the next stage
		}
	}
	
	void ApplyingUncon(float PShock)
	{
		log("ShockTickBase:: "+ this +" is unconscious " + PShock);		
		
		m_ShockActive = false;
				
		if(PShock > PlayerConstants.CONSCIOUS_THRESHOLD)
		{
			log("ShockTickBase:: " + this + "Player is waking up!");
			
			m_currentStage = ShockInjectionStage.Awake;
		}
	}
	
	void ApplyingAwake(float PShock)
	{
		log("ApplyingAwake:: " + this + " is awake " + PShock);
		StopShockInjectionServer();
	}
	
	void HandleInjured(float _Tick)
	{
		if(m_InjuredVal < m_MaxInjured)
		{
			m_InjuredVal += GetInjuredPerTick(_Tick);
		}
		
		HumanCommandAdditives HCA = GetCommandModifier_Additives();
		
		if( HCA != null)
		{
			HCA.SetInjured( m_InjuredVal , true );
		}
		else
		{
			log("HandleInjured:: " + this + " has null HCA");
		}
		
		
		log("HandleInjured:: " + m_InjuredVal);
	}
	
	void HandleVinEffect()
	{
		if(m_Vin < m_MaxVin)
		{
			m_Vin += GetVinPerTick();
		}
		
		PPEffects.SetUnconsciousnessVignette(m_Vin);
	}
	
	//Vin Effect Change Per Tick
	float GetVinPerTick()
	{
		float val = Math.Max(0, ((m_MaxVin - m_VinStart) / (m_TargetTime / m_tickRateC)));
		return val;
	}
	
	//Shock Effect Change Per Tick
	float GetInjectionShockDamage(float _Tick)
	{
		float val = Math.Max(0, (m_maxPlayerShock / (m_TargetTime/_Tick)));
		return val;
	}
	
	//Injured Effect Change Per Tick
	float GetInjuredPerTick(float _Tick)
	{
		float val = Math.Max(0,((m_MaxInjured - m_InjuredStart) / (m_TargetTime/_Tick)));
		return val;
	}
	
	//Print with toggle
	void log(string msg)
	{
		if(DebugOn)
		{
			Print("ShockInjector::" + msg);
		}
	}
//Restraint override
	override bool Save()
	{
		// saved player must be alive but remove captive check
		if (GetPlayerState() == EPlayerStates.ALIVE )
		{
			GetHive().CharacterSave(this);
			Debug.Log("Player "+this.ToString()+ " saved as alive");
			
			return true;
		}
		return false;		
	}
}

enum ShockInjectionStage
{
	NotActive = 0, //While injection is not active
	ApplyingShock = 1, //While Shock is being applied to the player
	Unconscious = 2, //While the player is Uncon
	Awake = 3 //After the player wakes up, normally just a single tick of time
};

