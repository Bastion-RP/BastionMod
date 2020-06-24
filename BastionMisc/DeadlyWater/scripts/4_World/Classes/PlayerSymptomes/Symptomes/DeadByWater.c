class DeadByWater : SymptomBase
{
	private float m_VignetteValue;
	
	override void OnInit() 
	{
		m_SymptomType = SymptomTypes.SECONDARY;
		m_Priority = 0;
		m_ID = BRP_SymptomIDs.BRP_SYMPTOM_DEAD_BY_WATER;
		m_DestroyOnAnimFinish = true;
		m_IsPersistent = false;
		m_SyncToClient = true;
		m_VignetteValue = 0;
	}

	override void OnUpdateServer(PlayerBase player, float deltatime)
	{
		if (!player.IsInWater())
		{
			m_VignetteValue -= 0.07;
		}
		else
		{
			m_VignetteValue += 0.07;
		}
		if (m_VignetteValue > 2)
		{
			player.SetHealth("","Shock",0);
			m_VignetteValue = 2;
		}
	}

	override void OnUpdateClient(PlayerBase player, float deltatime)
	{
		if (!player.IsInWater())
		{
			m_VignetteValue -= 0.003;
		}
		else
		{
			m_VignetteValue += 0.003;	
		}
		PPEffects.SetVignette(m_VignetteValue, 0, 0, 0);
		if (m_VignetteValue > 2)
		m_VignetteValue = 2;
		if	(m_VignetteValue < 0)
		m_VignetteValue = 0;
	}
	
	override void OnGetActivatedServer(PlayerBase player)
	{
		
	}

	override void OnGetActivatedClient(PlayerBase player)
	{

	}

	override void OnGetDeactivatedServer(PlayerBase player)
	{

	}
	
	override void OnGetDeactivatedClient(PlayerBase player)
	{

	}
}