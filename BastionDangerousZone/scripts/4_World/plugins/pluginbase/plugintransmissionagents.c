modded class PluginTransmissionAgents extends PluginBase
{
	//static ref map<int, ref AgentBase> m_AgentList =  new map<int, ref AgentBase>;
	//ref map<int, string> m_SimpleAgentList = new map<int, string>;
	//bool m_IsConstructed = false;

	void PluginTransmissionAgents()
	{
		//add new agents here
		RegisterAgent(new RadAgent);
		RegisterAgent(new HazardAgent);
	}
};
