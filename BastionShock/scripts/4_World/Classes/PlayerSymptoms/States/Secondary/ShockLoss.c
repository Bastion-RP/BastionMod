class ShockLoss extends SymptomBase {
	
	//this is just for the Symptom parameters set-up and is called even if the Symptom doesn't execute, don't put any gameplay code in here
	override void OnInit() {
		m_SymptomType = SymptomTypes.SECONDARY;
		m_Priority = 0;
		m_ID = BRP_Shock_SymptomIDs.BRP_SYMPTOM_SHOCKLOSS;
		m_DestroyOnAnimFinish = true;
		m_IsPersistent = false;
		m_SyncToClient = true;


		// if we are not a client and we are in multiplayer, leave now
		if (!GetGame().IsClient() && GetGame().IsMultiplayer()) {
			return;
		};
	}
	
	//!gets called every frame
	override void OnUpdateServer(PlayerBase player, float deltatime) {
	
		int shock_simplified = player.SimplifyShock();
		
		// update shock even when player is conscious
		if(player.m_ShockSimplified != shock_simplified) {
			player.m_ShockSimplified = shock_simplified;
			player.SetSynchDirty();
		};
	};


	override void OnUpdateClient(PlayerBase player, float deltatime) {
		return;

	}
	void ~ShockLoss() {
	}


	
	//!gets called once on an Symptom which is being activated
	override void OnGetActivatedServer(PlayerBase player)
	{

	}

	override void OnGetActivatedClient(PlayerBase player)
	{

	}

	override void OnGetDeactivatedServer(PlayerBase player)
	{
	}
	
	//!only gets called once on an active Symptom that is being deactivated
	override void OnGetDeactivatedClient(PlayerBase player)
	{
	}
}
