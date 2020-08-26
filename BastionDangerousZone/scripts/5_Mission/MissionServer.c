modded class MissionServer extends MissionBase
{
	ref DZRadiationZone RadiationZone;
	ref DZHazardZone HazardZone;
	ref array<ref DZInfectedZone> InfectedZones;
	ref DZCrateSystem CrateSystem;

	void MissionServer() {
		m_DZManager = NULL;
		GetDZManager();
	}

	void ~MissionServer() {
	}

	override void OnInit()
	{
		super.OnInit();
		initRadiationZones();
		initHazardZones();
		initInfectedZones();
		initCrateSysteme();
	}

	void initCrateSysteme()
	{
		if(GetCrateSystemConfig().IsCrateSystemActive == 1)
		{
			CrateSystem = new DZCrateSystem;
		}
	}

	void initRadiationZones()
	{
		if(GetRadConfig().IsRadiationZoneActive == 1){
			RadiationZone = new DZRadiationZone;
		}
	}

	void initHazardZones()
	{
		if(GetHazardConfig().IsHazardZoneActive == 1){
			HazardZone = new DZHazardZone;
		}
	}

	void initInfectedZones()
	{
		if(GetInfectedConfig().IsInfectedZoneActive == 1){
			InfectedZones = new array<ref DZInfectedZone>;
			int cpt=-1+GetInfectedConfig().InfectedAreaLocation.Count();
			for (int k=0;k<=cpt;k++)
			{
				GetDZLogger().LogInfo("InfectedZone : " + GetInfectedConfig().InfectedAreaLocation.Get(k).InfectedZoneStatut + " spawned !");
				InfectedZones.Insert(new ref DZInfectedZone(GetInfectedConfig().InfectedAreaLocation.Get(k)));
			}
		}
	}

	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
	{
		super.InvokeOnConnect(player,identity);
		InitializeConfigToPlayer(player);
	}

	override void InvokeOnDisconnect( PlayerBase player )
	{
		super.InvokeOnDisconnect(player);
	}

	void InitializeConfigToPlayer(PlayerBase player)
	{
		player.RadChanceVomit = GetRadConfig().RadChanceVomit;
		player.RadChanceBleeding = GetRadConfig().RadChanceBleeding;
		player.RadBloodLossDamage = GetRadConfig().RadBloodLossDamage;
		player.RadHealthDamage = GetRadConfig().RadHealthDamage;
		player.RadHighMultiplier = GetRadConfig().RadHighMultiplier;
		player.CriticalProtection = GetRadConfig().CriticalProtection;
		player.ClothesQuantityMultiplier = GetRadConfig().ClothesQuantityMultiplier;
		player.AmountGivenAfterCriticalProtection = GetRadConfig().AmountGivenAfterCriticalProtection;
		player.SetSuitsDamageForRad(GetRadConfig().SuitsDamage);
		player.SetSuitsDamageForHazard(GetHazardConfig().GasMaskDamage);
		player.NbSickGivenForHazard = GetHazardConfig().NbSickGivenForHazard;
		player.HazardShockValue = GetHazardConfig().HazardShockValue;
		player.HazardChanceCough = GetHazardConfig().HazardChanceCough;
		player.HazardChanceShock = GetHazardConfig().HazardChanceShock;
	}


	override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
	{
		Entity playerEnt;
		playerEnt = GetGame().CreatePlayer(identity, characterName, pos, 0, "NONE");//Creates random player
		Class.CastTo(m_player, playerEnt);

		GetGame().SelectPlayer(identity, m_player);

		m_player.IsInside.DZStatut=false;
		m_player.IsInside.DZName="";
		m_player.IsInside.DZType=0;

		return m_player;

		//super.CreateCharacter(identity,pos,ctx,characterName);
	}

}
