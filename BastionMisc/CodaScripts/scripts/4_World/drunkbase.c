modded class PlayerBase
{
    int howDrunk;
    int cap;

	void DrinkBooze(ItemBase source, float amount)
	{
        Edible_Base edible_item = Edible_Base.Cast(source);
		int agents = edible_item.GetAgents();

        
        if(edible_item && edible_item.IsLiquidContainer())
		{
			int liquid_type = edible_item.GetLiquidType();

			if(liquid_type == 4096 || liquid_type == 65536)
            {
                howDrunk = GetSingleAgentCount(DrunkAgent.DRUNK);
		        cap = PluginTransmissionAgents.GetAgentMaxCount(DrunkAgent.DRUNK);

		        if (howDrunk + amount > cap)
		        {
                    int minor = howDrunk / 2;
			        amount = cap - minor;
		        }

		        InsertAgent(DrunkAgent.DRUNK, amount);
            }

            else if (liquid_type == 780 || liquid_type == 781)
            {
                howDrunk = GetSingleAgentCount(DrunkAgent.DRUNK);
		        cap = PluginTransmissionAgents.GetAgentMaxCount(DrunkAgent.DRUNK);

		        if (howDrunk + amount > cap)
		        {
			        amount = cap - howDrunk;
		        }

		        InsertAgent(DrunkAgent.DRUNK, amount);
            }
		}
	};

	override bool Consume(ItemBase source, float amount, EConsumeType consume_type)
	{
		if (source)
		{
			DrinkBooze(source, amount);
		}
		return super.Consume(source, amount, consume_type);
	}
};
