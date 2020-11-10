class ActionOpenCasinoUI : ActionInteractBase
{
	void ActionOpenCasinoUI()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_HUDCursorIcon = CursorIcons.OpenHood;
	}

	override string GetText()
	{
		return "#hint_can_open_game";
	}

	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTObject(UAMaxDistances.DEFAULT);
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{

		if (GetGame().IsServer())
			return true;

		Object target_object = target.GetObject();

		Print("ActionCondition " + target_object.GetType());
		if ( target_object.GetType() == "BRP_CasinoGamblingMachine") 
		{
			BRP_CasinoGamblingMachine ntarget = BRP_CasinoGamblingMachine.Cast( target_object );
			if( ntarget )
			{
				
				if(!player.GetActionOpenCasinoMenu() && NeedAddGetGameMenu(player) && player.IsAlive())
					return true;
				
			}
		}
		return false;
	}

	override void OnEndClient( ActionData action_data )
	{
		Object target_object = action_data.m_Target.GetObject();
		BRP_CasinoGamblingMachine ntarget = BRP_CasinoGamblingMachine.Cast( target_object );
		
		if( ntarget && action_data.m_Player)
		{
			if(!action_data.m_Player.actionOpenCasinoMenu && NeedAddGetGameMenu(action_data.m_Player) && action_data.m_Player.IsAlive())
				action_data.m_Player.SetActionOpenCasinoMenu(true);
		}
	}

	override void OnEndServer( ActionData action_data )
	{
		Object target_object = action_data.m_Target.GetObject();
		BRP_CasinoGamblingMachine ntarget = BRP_CasinoGamblingMachine.Cast( target_object );
		ref PlayerBase player = action_data.m_Player;
		
		if( ntarget && player)
		{
			if(!action_data.m_Player.actionOpenCasinoMenu && NeedAddGetGameMenu(action_data.m_Player) && action_data.m_Player.IsAlive())
				player.SetActionOpenCasinoMenu(true);
		}
	}

	bool NeedAddGetGameMenu(DayZPlayer player) {

		vector posPlayer = player.GetPosition();
		PlayerBase playerBase = PlayerBase.Cast(player);

		CasinoConfig casinoConfig = playerBase.casinoConfig;

		if (casinoConfig.diceSettings.enabled) {
			DebugMessageCasino("diceSettings enable ");
			foreach(GamePosition position1: casinoConfig.diceSettings.gamePositions) {
				DebugMessageCasino("diceSettings confing pos =  " + position1.pos + "player pos = " + posPlayer + " DAYZ_CASINO_DISTANCE_TO_GAME = " + DAYZ_CASINO_DISTANCE_TO_GAME);
				if (vector.Distance(position1.pos, posPlayer) <= DAYZ_CASINO_DISTANCE_TO_GAME){
					DebugMessageCasino("in near of bet dice");
					
					return true;
				}
			}	
		}  
		if (casinoConfig.blackJackSettings.enabled) {
			DebugMessageCasino("blackJackSettings enable ");
			foreach(GamePosition position2: casinoConfig.blackJackSettings.gamePositions) {
				DebugMessageCasino("diceSettings confing pos =  " + position2.pos + "player pos = " + posPlayer+ " DAYZ_CASINO_DISTANCE_TO_GAME = " + DAYZ_CASINO_DISTANCE_TO_GAME);
				if (vector.Distance(position2.pos, posPlayer) <= DAYZ_CASINO_DISTANCE_TO_GAME){
					DebugMessageCasino("in near of black jack");
					
					return true;
				}
			}	
		} 
		if (casinoConfig.luckyWheelSettings.enabled) {
			DebugMessageCasino("luckyWheelSettings enable ");
			foreach(GamePosition position3: casinoConfig.luckyWheelSettings.gamePositions) {
				DebugMessageCasino("diceSettings confing pos =  " + position3.pos + "player pos = " + posPlayer + " DAYZ_CASINO_DISTANCE_TO_GAME = " + DAYZ_CASINO_DISTANCE_TO_GAME);
				if (vector.Distance(position3.pos, posPlayer) <= DAYZ_CASINO_DISTANCE_TO_GAME){
					DebugMessageCasino("in near of lucky wheel");
					
					return true;
				}
			}	
		}
		if (casinoConfig.ratRaceSettings.enabled) {
			DebugMessageCasino("ratRaceSettings enable ");
			foreach(GamePosition position4: casinoConfig.ratRaceSettings.gamePositions) {
				DebugMessageCasino("diceSettings confing pos =  " + position4.pos + "player pos = " + posPlayer + " DAYZ_CASINO_DISTANCE_TO_GAME = " + DAYZ_CASINO_DISTANCE_TO_GAME);
				if (vector.Distance(position4.pos, posPlayer) <= DAYZ_CASINO_DISTANCE_TO_GAME){
					DebugMessageCasino("in near of rat race");
					
					return true;
				}
			}	
		}
		
		return false;
	}
}