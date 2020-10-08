modded class PlayerBase
{
	private ref RadiationHandlerClient radiationHandler;

	override void Init()
	{
		super.Init();

		if (!GetGame().IsServer() || !GetGame().IsMultiplayer())
		{
			radiationHandler = new RadiationHandlerClient(this);
		}
	}

	RadiationHandlerClient GetRadiationHandler()
	{
		return radiationHandler;
	}

	override void OnConnect()
	{
		super.OnConnect();

		GetGame().RPCSingleParam(null, RadRPCs.RESPONSE_DATA, new Param1<ref RadiationConfig>(GetRadiationManager().GetConfig()), true, GetIdentity());
	}

	void AddRadiationLevel(float rad)
	{
		float tempRad = rad;
		Print("current rad "+ GetRadiationLevel());
		if (GetModifiersManager().IsModifierActive(Rad_eModifiers.MDF_RAD_BLOCK))
			tempRad *= 0.5;
		Print("\nAddRadiationLevel rad "+ tempRad);
		InsertAgent(BST_Agents.RADIATION, ConvertRadiationAgent(tempRad));
		Print("after insert rad {"+ GetRadiationLevel()+"}");
	}

	void DecreaseAgent(int agent, float amount)
	{
		m_AgentPool.DecreaseAgent(agent, ConvertRadiationAgent(amount));
	}

	int ConvertRadiationAgent(float amount)
	{
		return (amount * 1000);
	}

	float GetRadiationLevel()
	{
		return (GetSingleAgentCount(BST_Agents.RADIATION) * 0.001);
	}
}